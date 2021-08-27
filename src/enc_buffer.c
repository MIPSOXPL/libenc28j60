/**
 * @file enc_buffer.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains functions for buffers used in project
 * @date 2021-08-26
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#include "enc_buffer.h"

bool enc_buffer_init(enc_buffer_t *buffer_struct, uint8_t* buffer, uint8_t buffer_size)
{
    if(buffer_struct != NULL && buffer != NULL && buffer_size > 0)
    {
        buffer_struct->buffer = buffer;
        buffer_struct->buffer_size = buffer_size;
        buffer_struct->buffer_data_counter = 0;
        return true;
    }
    return false;
}

bool enc_is_buffer_valid(enc_buffer_t* buffer_struct)
{
    if(buffer_struct != NULL)
    {
        return buffer_struct->buffer != NULL && buffer_struct->buffer_size > 0;
    }
    return false;
}

void enc_buffer_clear(enc_buffer_t* buffer_struct)
{
    if(buffer_struct != NULL)
    {
        buffer_struct->buffer_data_counter = 0;
    }
}

void enc_set_buffer_data_count(enc_buffer_t* buffer_struct, int data_count)
{
    if(buffer_struct != NULL)
    {
        buffer_struct->buffer_data_counter = data_count;
    }
}