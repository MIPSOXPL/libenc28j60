/**
 * @file enc_io.h
 * @author Marcin Dzieciątkowski (marcin.dzieciatkowski@mipso.pl)
 * @brief This file contains all functions concerning readint & writing to enc28j60
 * @date 2021-08-30
 *
 * @copyright Copyright (c) MIPSO Marcin Dzieciątkowski 2021
 *            Please refer to LICENSE file for more informations
 */

#include "enc_io.h"
#include "enc_hardware_integration.h"
#include "enc_utils.h"
#include "enc_command_builder.h"
#include "enc_const.h"

uint8_t buf[2];
enc_buffer_t buffer = {.buffer=buf, .buffer_size=2};

uint8_t read_control_register(uint8_t address)
{
	enc_read_control_register(&buffer, address);
	spi_reset_enc_nss();
	bool temp = spi_send_data(&buffer);
	temp = spi_receive_data(&buffer, 1);
	spi_set_enc_nss();
	return buffer.buffer[0];
}

uint8_t read_control_register2(uint8_t address)
{
	enc_read_control_register(&buffer, address);
	spi_reset_enc_nss();
	spi_send_data(&buffer);
	spi_receive_data(&buffer, 2);
	spi_set_enc_nss();
	return buffer.buffer[1];
}

bool write_control_register(uint8_t address, uint8_t value)
{
	enc_write_control_register(&buffer, address, value);
	spi_reset_enc_nss();
	spi_send_data(&buffer);
	spi_set_enc_nss();
	return true;
}

bool read_buffer_register(uint16_t start_address, enc_buffer_t* buffer, uint16_t data_length)
{
	_set_buffer_rx_pointer_start(start_address);
	enc_read_buffer_register(buffer);
	spi_reset_enc_nss();
	spi_receive_data(buffer, data_length);
	spi_set_enc_nss();
	return true;
}

bool write_buffer_register(uint16_t start_address, enc_buffer_t* buffer, uint8_t* input_data, uint16_t data_size)
{
	_set_buffer_tx_pointer_start(start_address);
	enc_write_buffer_register(buffer, data_size, input_data);
	_set_buffer_tx_pointer_end(start_address + data_size);
	spi_reset_enc_nss();
	spi_send_data(buffer);
	spi_set_enc_nss();
	return true;
}

bool set_bit(uint8_t address, uint8_t mask)
{
	enc_set_bit(&buffer, address, mask);
	spi_reset_enc_nss();
	spi_send_data(&buffer);
	spi_set_enc_nss();
	return true;
}

bool clear_bit(uint8_t address, uint8_t mask)
{
	enc_clear_bit(&buffer, address, mask);
	spi_reset_enc_nss();
	spi_send_data(&buffer);
	spi_set_enc_nss();
	return true;
}

uint16_t read_phy_register(uint8_t address)
{
	enc_select_bank(ENC_2_BANK);

	write_control_register(ENC_MIREGADR_REG_ADDR, address);
	write_control_register(ENC_MICMD_REG_ADDR, 1);

	enc_select_bank(ENC_3_BANK);
	while((read_control_register(ENC_MISTAT_REG_ADDR) & 1));

	enc_select_bank(ENC_2_BANK);

	write_control_register(ENC_MICMD_REG_ADDR, 0);

	uint16_t data = read_control_register2(ENC_MIRDL_REG_ADDR);
			 data += read_control_register2(ENC_MIRDH_REG_ADDR) << 8;

	return data;
}

bool write_phy_register(uint8_t address, uint16_t value)
{
	enc_select_bank(ENC_2_BANK);

	write_control_register(ENC_MIREGADR_REG_ADDR, address);

	write_control_register(ENC_MIWRL_REG_ADDR, value & 0xFF);

	write_control_register(ENC_MIWRH_REG_ADDR, value >> 8);

	enc_select_bank(ENC_3_BANK);
	while((read_control_register2(ENC_MISTAT_REG_ADDR) & 1));

	return true;
}

void software_reset()
{
	enc_reset(&buffer);
	spi_reset_enc_nss();
	spi_send_data(&buffer);
	spi_set_enc_nss();
}


// HELPER METHODS


void _set_buffer_rx_pointer_start(uint16_t loc)
{
	enc_select_bank(ENC_0_BANK);
	write_control_register(ENC_ERDPTL_REG_ADDR, loc & 0xFF);
	write_control_register(ENC_ERDPTH_REG_ADDR, loc >> 8);
}

void _set_buffer_tx_pointer_start(uint16_t loc)
{
	enc_select_bank(ENC_0_BANK);
	write_control_register(ENC_ETXSTL_REG_ADDR, loc & 0xFF);
	write_control_register(ENC_ETXSTH_REG_ADDR, loc >> 8);
}

void _set_buffer_tx_pointer_end(uint16_t loc)
{
	enc_select_bank(ENC_0_BANK);
	write_control_register(ENC_ETXNDL_REG_ADDR, loc & 0xFF);
	write_control_register(ENC_ETXNDH_REG_ADDR, loc >> 8);
}
