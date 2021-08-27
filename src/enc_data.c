/**
 * @file enc_data.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains main functions for structure for ENC28J60
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#include "enc_data.h"

bool enc_data_init(enc_data_t* enc_data, enc_buffer_t* in_buffer, enc_buffer_t* out_buffer)
{
    if(enc_data != NULL)
    {
        if(enc_is_buffer_valid(in_buffer) && enc_is_buffer_valid(out_buffer))
        {
            enc_data->in_buffer = in_buffer;
            enc_data->out_buffer = out_buffer;
            return true;
        }
    }
    return false;
}

void enc_data_clear_input_buffer(enc_data_t* enc_data)
{
    if(enc_data != NULL)
    {
        enc_buffer_clear(enc_data->in_buffer);
    }
}

void enc_data_clear_output_buffer(enc_data_t* enc_data)
{
    if(enc_data != NULL)
    {
        enc_buffer_clear(enc_data->out_buffer);
    }
}

bool enc_is_data_valid(enc_data_t* enc_data)
{
    return enc_data != NULL && enc_is_buffer_valid(enc_data->in_buffer) && enc_is_buffer_valid(enc_data->out_buffer);
}
