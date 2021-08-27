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

bool enc_init_enc_struct(enc_struct_t* enc_struct, enc_buffer_t* in_buffer, enc_buffer_t* out_buffer)
{
    if(enc_struct != NULL)
    {
        if(enc_is_buffer_valid(in_buffer) && enc_is_buffer_valid(out_buffer))
        {
            enc_struct->in_buffer = in_buffer;
            enc_struct->out_buffer = out_buffer;
            return true;
        }
    }
    return false;
}

void enc_clear_input_buffer(enc_struct_t* enc_struct)
{
    if(enc_struct != NULL)
    {
        enc_buffer_clear(enc_struct->in_buffer);
    }
}

void enc_clear_output_buffer(enc_struct_t* enc_struct)
{
    if(enc_struct != NULL)
    {
        enc_buffer_clear(enc_struct->out_buffer);
    }
}
