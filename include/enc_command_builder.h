/**
 * @file enc_command_builder.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains definitions of functions that generate data for SPI requests
 * @date 2021-08-26
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#ifndef ENC_COMMAND_BUILDER_H
#define ENC_COMMAND_BUILDER_H

#include "enc_struct.h"
#include "enc_buffer.h"

typedef enum {
    read_control_opcode = 0x00,
    read_buffer_opcode = 0x01,
    write_control_opcode = 0x02,
    write_buffer_opcode = 0x03,
    set_bit_opcode = 0x04,
    clear_bit_opcode = 0x05,
    reset_opcode = 0x07,
} enc_opcodes;

typedef enum {
    buffer_argument = 0x1A,
    reset_argument = 0x1F
} enc_arguments;

bool enc_read_control_register(enc_buffer_t* buffer_struct, uint8_t address);
bool enc_read_buffer_register(enc_buffer_t* buffer_struct);
bool enc_write_control_register(enc_buffer_t* buffer_struct, uint8_t address, uint8_t data);
bool enc_write_buffer_register(enc_buffer_t* buffer_struct, uint16_t data_size, uint8_t* input_buffer);
bool enc_set_bit(enc_buffer_t* buffer_struct, uint8_t address, uint8_t mask);
bool enc_clear_bit(enc_buffer_t* buffer_struct, uint8_t address, uint8_t mask);
bool enc_reset(enc_buffer_t* buffer_struct);

#endif //ENC_COMMAND_BUILDER_H
