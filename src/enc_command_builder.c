/**
 * @file enc_command_builder.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains implementations of functions that generate data for SPI requests
 * @date 2021-08-26
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#include "enc_command_builder.h"
#include "string.h"

bool enc_read_control_register(enc_buffer_t* buffer_struct, uint8_t address)
{
    if(enc_is_buffer_valid(buffer_struct) && buffer_struct->buffer_size >= 1)
    {
        //Set first byte
        buffer_struct->buffer[0] = (read_control_opcode << 5) | address;
        enc_set_buffer_data_count(buffer_struct, 1);
        return true;
    }
    return false; 
}

bool enc_read_buffer_register(enc_buffer_t* buffer_struct)
{
    if(enc_is_buffer_valid(buffer_struct) && buffer_struct->buffer_size >= 1)
    {
        //Set first byte
        buffer_struct->buffer[0] = (read_buffer_opcode << 5) | buffer_argument;
        enc_set_buffer_data_count(buffer_struct, 1);
        return true;
    }
    return false; 
}

bool enc_write_control_register(enc_buffer_t* buffer_struct, uint8_t address, uint8_t data)
{
    if(enc_is_buffer_valid(buffer_struct) && buffer_struct->buffer_size >= 2)
    {
        //Set first byte
        buffer_struct->buffer[0] = (write_control_opcode << 5) | address;
        //Set data byte
        buffer_struct->buffer[1] = data;
        enc_set_buffer_data_count(buffer_struct, 2);
        return true;
    }
    return false;
}

bool enc_write_buffer_register(enc_buffer_t* buffer_struct, uint16_t data_size, uint8_t* input_buffer)
{
    if(enc_is_buffer_valid(buffer_struct) && buffer_struct->buffer_size >= 1 + data_size && input_buffer != NULL)
    {
        //Set first byte
        buffer_struct->buffer[0] = (write_buffer_opcode << 5) | buffer_argument;
        //Copy data bytes
        memcpy(buffer_struct->buffer + 1, input_buffer, data_size);
        enc_set_buffer_data_count(buffer_struct, 1 + data_size);
        return true;
    }
    return false;
}

bool enc_set_bit(enc_buffer_t* buffer_struct, uint8_t address, uint8_t mask)
{
    if(enc_is_buffer_valid(buffer_struct) && buffer_struct->buffer_size >= 2)
    {
        //Set first byte
        buffer_struct->buffer[0] = (set_bit_opcode << 5) | address;
        //Set mask byte
        buffer_struct->buffer[1] = mask;
        enc_set_buffer_data_count(buffer_struct, 2);
        return true;
    }
    return false;
}

bool enc_clear_bit(enc_buffer_t* buffer_struct, uint8_t address, uint8_t mask)
{
    if(enc_is_buffer_valid(buffer_struct) && buffer_struct->buffer_size >= 2)
    {
        //Set first byte
        buffer_struct->buffer[0] = (clear_bit_opcode << 5) | address;
        //Set mask byte
        buffer_struct->buffer[1] = mask;
        enc_set_buffer_data_count(buffer_struct, 2);
        return true;
    }
    return false;
}

bool enc_reset(enc_buffer_t* buffer_struct)
{
    if(enc_is_buffer_valid(buffer_struct) && buffer_struct->buffer_size >= 1)
    {
        //Set first byte
        buffer_struct->buffer[0] = (reset_opcode << 5) | reset_argument;
        enc_set_buffer_data_count(buffer_struct, 1);
        return true;
    }
    return false;
}
