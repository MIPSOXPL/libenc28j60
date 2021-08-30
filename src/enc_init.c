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
#include "enc_io.h"
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
        enc_select_bank(ENC_0_BANK);
        write_control_register(ENC_ERXSTH_REG_ADDR, (receive_buffer_offset & 0xFF00) >> 8);
        write_control_register(ENC_ERXSTL_REG_ADDR, (receive_buffer_offset & 0x00FF));
        write_control_register(ENC_ERXNDH_REG_ADDR, ((receive_buffer_offset + receive_buffer_size) & 0xFF00) >> 8);
        write_control_register(ENC_ERXNDL_REG_ADDR, ((receive_buffer_offset + receive_buffer_size) & 0x00FF));

        //Program readout pointer (lower byte first)
        write_control_register(ENC_ERXRDPTL_REG_ADDR, ((receive_buffer_offset & 0xFF)));
        write_control_register(ENC_ERXRDPTH_REG_ADDR, (receive_buffer_offset & 0xFF00) >> 8);

        return true;
    }
    return false;
}

bool enc_init_receive_filters(enc_data_t* enc_data, uint8_t filters_value)
{
	if(enc_is_data_valid(enc_data))
	{
		enc_select_bank(ENC_1_BANK);
		write_control_register(ENC_ERXFCON_REG_ADDR, filters_value);
		return true;
	}
	return false;
}

bool enc_init_settings(enc_data_t* enc_data, enc_settings* settings)
{
    if(!enc_is_data_valid(enc_data)){
    	return false;
    }
	enc_select_bank(ENC_2_BANK);

	write_control_register(ENC_MACON1_REG_ADDR, 13);
	write_control_register(ENC_MACON3_REG_ADDR, 241);
	write_control_register(ENC_MACON4_REG_ADDR, 64);
	write_control_register(ENC_MAMXFLH_REG_ADDR, settings->max_frame_length >> 8);
	write_control_register(ENC_MAMXFLL_REG_ADDR, settings->max_frame_length & 0xFF);
	write_control_register(ENC_MABBIPG_REG_ADDR, 21);
	write_control_register(ENC_MAIPGL_REG_ADDR, 18);

	_enc_write_mac(enc_data, settings->MAC);

	return true;
}

bool enc_init_phy(enc_data_t* enc_data)
{
    if(!enc_is_data_valid(enc_data)){
    	return false;
    }
    write_phy_register(ENC_PHCON1_REG_ADDR, 256);
    return true;
}

void enc_init_wait_for_ost(enc_data_t* enc_data)
{
	while((read_control_register(ENC_G_ESTAT_REG_ADDR) & 1) == 0);
}

void _enc_write_mac(enc_data_t* enc_data, uint8_t* mac)
{
	enc_select_bank(ENC_3_BANK);

	write_control_register(ENC_MAADR1_REG_ADDR, mac[0]);
	write_control_register(ENC_MAADR2_REG_ADDR, mac[1]);
	write_control_register(ENC_MAADR3_REG_ADDR, mac[2]);
	write_control_register(ENC_MAADR4_REG_ADDR, mac[3]);
	write_control_register(ENC_MAADR5_REG_ADDR, mac[4]);
	write_control_register(ENC_MAADR6_REG_ADDR, mac[5]);
}
