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
#include "enc_hardware_integration.h"

#include "stdint.h"
#include "stdbool.h"

bool enc_init_receive_buffer(enc_data_t* enc_data, uint16_t receive_buffer_offset, uint16_t receive_buffer_size)
{
    if(enc_is_data_valid(enc_data))
    {
        //Program buffers size
        enc_select_bank(enc_data, ENC_0_BANK);
        enc_write_control_register(enc_data->out_buffer, ENC_ERXSTH_REG_ADDR, (receive_buffer_offset & 0xFF00) >> 8);
        spi_send_data_nss(enc_data->out_buffer);
        enc_write_control_register(enc_data->out_buffer, ENC_ERXSTL_REG_ADDR, (receive_buffer_offset & 0x00FF));
        spi_send_data_nss(enc_data->out_buffer);
        enc_write_control_register(enc_data->out_buffer, ENC_ERXNDH_REG_ADDR, ((receive_buffer_offset + receive_buffer_size) & 0xFF00) >> 8);
        spi_send_data_nss(enc_data->out_buffer);
        enc_write_control_register(enc_data->out_buffer, ENC_ERXNDL_REG_ADDR, ((receive_buffer_offset + receive_buffer_size) & 0x00FF));
        spi_send_data_nss(enc_data->out_buffer);

        //Program readout pointer (lower byte first)
        enc_write_control_register(enc_data->out_buffer, ENC_ERXRDPTL_REG_ADDR, ((receive_buffer_offset & 0xFF)));
        spi_send_data_nss(enc_data->out_buffer);
        enc_write_control_register(enc_data->out_buffer, ENC_ERXRDPTH_REG_ADDR, (receive_buffer_offset & 0xFF00) >> 8);
        spi_send_data_nss(enc_data->out_buffer);
        return true;
    }
    return false;
}

bool enc_init_receive_filters(enc_data_t* enc_data, uint8_t filters_value)
{
	if(enc_is_data_valid(enc_data))
	{
		enc_select_bank(enc_data, ENC_1_BANK);
		enc_write_control_register(enc_data->out_buffer, ENC_ERXFCON_REG_ADDR, filters_value);
		spi_send_data_nss(enc_data->out_buffer);
		return true;
	}
	return false;
}

bool enc_init_settings(enc_data_t* enc_data, enc_settings* settings)
{
    if(!enc_is_data_valid(enc_data)){
    	return false;
    }
	enc_select_bank(enc_data, ENC_2_BANK);

	enc_write_control_register(enc_data->out_buffer, ENC_MACON1_REG_ADDR, 13);
	spi_send_data_nss(enc_data->out_buffer);

	enc_write_control_register(enc_data->out_buffer, ENC_MACON3_REG_ADDR, 241);
	spi_send_data_nss(enc_data->out_buffer);

	enc_write_control_register(enc_data->out_buffer, ENC_MACON4_REG_ADDR, 64);
	spi_send_data_nss(enc_data->out_buffer);

	enc_write_control_register(enc_data->out_buffer, ENC_MAMXFLH_REG_ADDR, settings->max_frame_length >> 8);
	spi_send_data_nss(enc_data->out_buffer);

	enc_write_control_register(enc_data->out_buffer, ENC_MAMXFLL_REG_ADDR, settings->max_frame_length & 0xFF);
	spi_send_data_nss(enc_data->out_buffer);

	enc_write_control_register(enc_data->out_buffer, ENC_MABBIPG_REG_ADDR, 21);
	spi_send_data_nss(enc_data->out_buffer);

	enc_write_control_register(enc_data->out_buffer, ENC_MAIPGL_REG_ADDR, 18);
	spi_send_data_nss(enc_data->out_buffer);

	_enc_write_mac(enc_data, settings->MAC);

	return true;
}

bool enc_init_phy(enc_data_t* enc_data)
{
    if(!enc_is_data_valid(enc_data)){
    	return false;
    }
    enc_write_phy_register(enc_data, ENC_PHCON1_REG_ADDR, 256);
    return true;
}

void enc_init_wait_for_ost(enc_data_t* enc_data)
{
	while((enc_get_estat(enc_data) & 1) == 0);
}

void _enc_write_mac(enc_data_t* enc_data, uint8_t* mac)
{
	enc_select_bank(enc_data, ENC_3_BANK);

	enc_write_control_register(enc_data->out_buffer, ENC_MAADR1_REG_ADDR, mac[0]);
	spi_send_data_nss(enc_data->out_buffer);
	enc_write_control_register(enc_data->out_buffer, ENC_MAADR2_REG_ADDR, mac[1]);
	spi_send_data_nss(enc_data->out_buffer);
	enc_write_control_register(enc_data->out_buffer, ENC_MAADR3_REG_ADDR, mac[2]);
	spi_send_data_nss(enc_data->out_buffer);
	enc_write_control_register(enc_data->out_buffer, ENC_MAADR4_REG_ADDR, mac[3]);
	spi_send_data_nss(enc_data->out_buffer);
	enc_write_control_register(enc_data->out_buffer, ENC_MAADR5_REG_ADDR, mac[4]);
	spi_send_data_nss(enc_data->out_buffer);
	enc_write_control_register(enc_data->out_buffer, ENC_MAADR6_REG_ADDR, mac[5]);
	spi_send_data_nss(enc_data->out_buffer);
}
