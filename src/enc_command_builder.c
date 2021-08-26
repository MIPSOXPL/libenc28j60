/**
 * @file enc_command_builder.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains implementations of functions that generate data for SPI requests
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#include "enc_command_builder.h"

void enc_read_control_register(uint8_t* command_buffer, uint8_t address, uint8_t* output)
{
    uint8_t first_byte = (read_control_opcode << 5) | address;
}

void enc_read_buffer_register(uint8_t* command_buffer, uint16_t data_size, uint8_t* output_buffer)
{
    uint8_t first_byte = (read_buffer_opcode << 5) | buffer_argument;
}

void enc_write_control_register(uint8_t* command_buffer, uint8_t address, uint8_t data)
{
    uint8_t first_byte = (write_control_opcode << 5) | address;
}

void enc_write_buffer_register(uint8_t* command_buffer, uint16_t data_size, uint8_t* input_buffer)
{
    uint8_t first_byte = (write_buffer_opcode << 5) | buffer_argument;
}

void enc_set_bit(uint8_t* command_buffer, uint8_t address, uint8_t mask)
{
    uint8_t first_byte = (set_bit_opcode << 5) | address;
}

void enc_clear_bit(uint8_t* command_buffer, uint8_t address, uint8_t mask)
{
    uint8_t first_byte = (clear_bit_opcode << 5) | address;
}

void enc_reset(uint8_t* command_buffer)
{
    uint8_t first_byte = (reset_opcode << 5) | reset_argument;
}