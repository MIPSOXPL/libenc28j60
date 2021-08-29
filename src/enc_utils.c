/**
 * @file enc_utils.c
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains all initialisation procedures and functions implementations for ENC28J60 integrated circuit
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#include "enc_utils.h"
#include "enc_command_builder.h"
#include "enc_const.h"

extern bool spi_send_data(enc_buffer_t* enc_buffer);
extern bool spi_receive_data(enc_buffer_t* enc_buffer, uint16_t data_length);

bool enc_select_bank(enc_data_t* enc_data, uint8_t bank)
{
    if(enc_is_data_valid(enc_data))
    {
        uint8_t clear_bank_selection_mask = 0b11111100;
        enc_clear_bit(enc_data->out_buffer, ENC_G_ECON1_REG_ADDR, clear_bank_selection_mask);
        spi_send_data(enc_data->out_buffer);
        enc_set_bit(enc_data->out_buffer, ENC_G_ECON1_REG_ADDR, bank);
        spi_send_data(enc_data->out_buffer);
        return true;
    }
    return false;
}

uint8_t enc_get_estat(enc_data_t* enc_data)
{
	enc_read_control_register(enc_data->out_buffer, ENC_G_ESTAT_REG_ADDR);
	spi_send_data(enc_data->out_buffer);
	spi_receive_data(enc_data->in_buffer, 1);
	return enc_data->in_buffer->buffer[0];
}

uint8_t enc_get_mistat(enc_data_t* enc_data)
{
	enc_select_bank(enc_data, ENC_3_BANK);
	enc_read_control_register(enc_data->out_buffer, ENC_MISTAT_REG_ADDR);
	spi_send_data(enc_data->out_buffer);
	spi_receive_data(enc_data->in_buffer, 1);
	return enc_data->in_buffer->buffer[0];
}
