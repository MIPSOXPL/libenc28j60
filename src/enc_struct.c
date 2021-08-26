/**
 * @file enc_struct.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains main functions for structure for ENC28J60
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#include "enc_struct.h"

bool enc_init_enc_struct(enc_struct_t* enc_struct, uint8_t* output_buffer, uint8_t output_buffer_size, uint8_t* input_buffer, uint8_t input_buffer_size)
{
    if(enc_struct != NULL && output_buffer != NULL && output_buffer_size > 0 && input_buffer != NULL && input_buffer_size > 0)
    {
        enc_struct->input_buffer = input_buffer;
        enc_struct->input_buffer_size = input_buffer_size;
        enc_struct->output_buffer = output_buffer;
        enc_struct->output_buffer_size = output_buffer_size;
        enc_struct->output_buffer_data_counter = 0;
        enc_struct->input_buffer_data_counter = 0;
        return true;
    }
    return false;
}

void enc_clear_input_buffer(enc_struct_t* enc_struct)
{
    if(enc_struct != NULL)
    {
        enc_struct->output_buffer_data_counter = 0;
    }
}

void enc_clear_output_buffer(enc_struct_t* enc_struct)
{
    if(enc_struct != NULL)
    {
        enc_struct->input_buffer_data_counter = 0;
    }
}
