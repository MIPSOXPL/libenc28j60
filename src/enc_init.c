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
#include "my_ethernet.h"

#include "stdint.h"
#include "stdbool.h"

bool enc_init(enc_settings* settings)
{
	write_control_register(ENC_G_ECON2_REG_ADDR, 128);
	enc_init_receive_buffer();
	enc_init_receive_filters(settings->enc_filters);
	enc_init_wait_for_ost();
	enc_init_settings(settings);
	enc_init_phy();
	enc_init_reception();
	return true;
}

bool enc_init_reception()
{
	write_control_register(ENC_G_ECON1_REG_ADDR, read_control_register(ENC_G_ECON1_REG_ADDR) | 4);
}

bool enc_init_receive_buffer()
{
        //Program buffers size
	enc_select_bank(ENC_0_BANK);
    write_control_register(ENC_ERXSTL_REG_ADDR, RX_BUFFER_START & 0xFF);
    write_control_register(ENC_ERXSTH_REG_ADDR, RX_BUFFER_START >> 8);


    write_control_register(ENC_ERXNDL_REG_ADDR, RX_BUFFER_END & 0xFF);
    write_control_register(ENC_ERXNDH_REG_ADDR, RX_BUFFER_END >> 8);

    //Program readout pointer (lower byte first)
    write_control_register(ENC_ERXRDPTL_REG_ADDR, RX_BUFFER_END & 0xFF);
    write_control_register(ENC_ERXRDPTH_REG_ADDR, RX_BUFFER_END >> 8);

    write_control_register(ENC_ETXSTL_REG_ADDR, TX_BUFFER_START & 0xFF);
    write_control_register(ENC_ETXSTH_REG_ADDR, TX_BUFFER_START >> 8);
    return true;
}

bool enc_init_receive_filters(uint8_t filters_value)
{
	enc_select_bank(ENC_1_BANK);
	write_control_register(ENC_ERXFCON_REG_ADDR, filters_value);
	return true;
}

bool enc_init_settings(enc_settings* settings)
{
	enc_select_bank(ENC_2_BANK);

	write_control_register(ENC_MACON1_REG_ADDR, 13);
	//write_control_register(ENC_MACON3_REG_ADDR, 241); //padding and crc
	write_control_register(ENC_MACON3_REG_ADDR, 51); // noo padding and no crc
	write_control_register(ENC_MAMXFLL_REG_ADDR, settings->max_frame_length & 0xFF);
	write_control_register(ENC_MAMXFLH_REG_ADDR, settings->max_frame_length >> 8);
	write_control_register(ENC_MABBIPG_REG_ADDR, 21);
	write_control_register(ENC_MAIPGL_REG_ADDR, 18);

	_enc_write_mac();

	return true;
}

bool enc_init_phy()
{
    write_phy_register(ENC_PHCON1_REG_ADDR, 256);
    return true;
}

void enc_init_wait_for_ost()
{
	while((read_control_register(ENC_G_ESTAT_REG_ADDR) & 1) == 0);
}

void _enc_write_mac()
{
	enc_select_bank(ENC_3_BANK);
	write_control_register(ENC_MAADR1_REG_ADDR, MAC_ADDR0);
	write_control_register(ENC_MAADR2_REG_ADDR, MAC_ADDR1);
	write_control_register(ENC_MAADR3_REG_ADDR, MAC_ADDR2);
	write_control_register(ENC_MAADR4_REG_ADDR, MAC_ADDR3);
	write_control_register(ENC_MAADR5_REG_ADDR, MAC_ADDR4);
	write_control_register(ENC_MAADR6_REG_ADDR, MAC_ADDR5);
}
