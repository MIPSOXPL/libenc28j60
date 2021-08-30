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

bool enc_send_packet(enc_data_t* t, uint8_t* data, uint16_t data_size)
{
	write_buffer_register(START_BUFFER_TX, t->out_buffer, data, data_size);

	start_transmission(t);

	while(read_control_register(ENC_G_ECON1_REG_ADDR) & 8){}

	uint8_t status_vector[56];
	read_status_vector(t->in_buffer, status_vector, START_BUFFER_TX + data_size + 1);

	return !(read_control_register(ENC_G_ESTAT_REG_ADDR) & 2);
}

bool enc_receive_packet(enc_data_t* t)
{

}


static void start_transmission()
{
	write_control_register(ENC_G_ECON1_REG_ADDR, 8);
}

static void read_status_vector(enc_buffer_t* buffer, uint8_t* save_here, uint16_t start_reading_from_here)
{
	read_buffer_register(start_reading_from_here, buffer, 56);
}
