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
#include "enc_hardware_integration.h"
#include "enc_io.h"

bool enc_select_bank(uint8_t bank)
{
    if(bank >= 0 && bank <= 3)
    {
        /*uint8_t clear_bank_selection_mask = 0b11111100;
        enc_clear_bit(enc_data->out_buffer, ENC_G_ECON1_REG_ADDR, clear_bank_selection_mask);
        spi_send_data_nss(enc_data->out_buffer);

        enc_set_bit(enc_data->out_buffer, ENC_G_ECON1_REG_ADDR, bank);
        spi_send_data_nss(enc_data->out_buffer);*/

    	write_control_register(ENC_G_ECON1_REG_ADDR, bank);
        return true;
    }
    return false;
}
