/**
 * @file enc_init.c
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains functions to initialise
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#include "enc_init.h"
#include "enc_command_builder.h"
#include "enc_const.h"
#include "enc_utils.h"

#include "stdint.h"
#include "stdbool.h"

extern bool spi_send_data(enc_buffer_t* enc_buffer);
extern bool spi_receive_data(enc_buffer_t* enc_buffer, uint16_t data_length);

bool enc_init_receive_buffer(enc_data_t* enc_data, uint16_t receive_buffer_offset, uint16_t receive_buffer_size)
{
    if(enc_is_data_valid(enc_data))
    {
        //Program buffers size
        enc_select_bank(enc_data, ENC_0_BANK);
        enc_write_control_register(enc_data->out_buffer, ENC_ERXSTH_REG_ADDR, (receive_buffer_offset & 0xFF00) >> 8);
        spi_send_data(enc_data->out_buffer);
        enc_write_control_register(enc_data->out_buffer, ENC_ERXSTL_REG_ADDR, (receive_buffer_offset & 0x00FF));
        spi_send_data(enc_data->out_buffer);
        enc_write_control_register(enc_data->out_buffer, ENC_ERXNDH_REG_ADDR, ((receive_buffer_offset + receive_buffer_size) & 0xFF00) >> 8);
        spi_send_data(enc_data->out_buffer);
        enc_write_control_register(enc_data->out_buffer, ENC_ERXNDL_REG_ADDR, ((receive_buffer_offset + receive_buffer_size) & 0x00FF));
        spi_send_data(enc_data->out_buffer);

        //Program readout pointer (lower byte first)
        enc_write_control_register(enc_data->out_buffer, ENC_ERXRDPTL_REG_ADDR, ((receive_buffer_offset & 0xFF00) >> 8));
        spi_send_data(enc_data->out_buffer);
        enc_write_control_register(enc_data->out_buffer, ENC_ERXRDPTH_REG_ADDR, (receive_buffer_offset & 0x00FF));
        spi_send_data(enc_data->out_buffer);
        return true;
    }
    return false;
}

bool enc_init_receive_filter(enc_data_t* enc_data, uint8_t filters_value)
{
	if(enc_is_data_valid(enc_data))
	{
		enc_select_bank(enc_data, ENC_1_BANK);
		enc_write_control_register(enc_data->out_buffer, ENC_ERXFCON_REG_ADDR, filters_value);
		spi_send_data(enc_data->out_buffer);
		return true;
	}
	return false;
}
