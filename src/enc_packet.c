/**
 * @file enc_packet.h
 * @author Marcin Dzieciątkowski (marcin.dzieciatkowski@mipso.pl)
 * @brief This file contains all functions concerning receiving & sending data packets over internet
 * @date 2021-08-30
 *
 * @copyright Copyright (c) MIPSO Marcin Dzieciątkowski 2021
 *            Please refer to LICENSE file for more informations
 */

#include "enc_packet.h"
#include "enc_utils.h"
#include "enc_const.h"
#include "enc_hardware_integration.h"
#include "enc_io.h"

bool enc_send_packet(uint8_t* data, uint16_t data_size)
{
	uint8_t per_packet_control_byte = 0xE;
	write_buffer_register(TX_BUFFER_START, &per_packet_control_byte, 1);
	write_continous_buffer_register(data, data_size);
	_set_buffer_tx_pointer_end(TX_BUFFER_START + data_size);

	write_control_register(ENC_G_ECON1_REG_ADDR, 128);

	write_control_register(ENC_G_ECON1_REG_ADDR, 8);

	while(read_control_register(ENC_G_ECON1_REG_ADDR) & 8){}

	uint8_t status_vector[7];
	read_buffer_register(TX_BUFFER_START + data_size + 1, status_vector, 7);

	return !(read_control_register(ENC_G_ESTAT_REG_ADDR) & 2);
}

pbuf* enc_receive_packet(enc_data_t* t)
{
	uint8_t header_size = 6;
	uint8_t header[header_size];
	read_buffer_register(t->loc, header, header_size);
	uint16_t length = (header[2] | ((header[3] & 0x7F) << 8)) - 4; // drop the crc 4 bytes;
	uint16_t new_loc = header[0] + (header[1] << 8);
	uint8_t rxstat = ((header[5] << 8) | header[4]);
	/// buffer allocation

	pbuf* buf = pbuf_alloc(PBUF_RAW, length, PBUF_RAM);

	if(buf != NULL){
		read_buffer_register(t->loc + 6, buf->payload, length);
	}

	enc_select_bank(ENC_0_BANK);
	write_control_register(ENC_ERXRDPTL_REG_ADDR, t->loc & 0xFF);
	write_control_register(ENC_ERXRDPTH_REG_ADDR, t->loc >> 8);
	set_bit(ENC_G_ECON2_REG_ADDR, 64);
	t->loc = new_loc;

	return buf;
}
