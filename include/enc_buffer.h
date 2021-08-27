/**
 * @file enc_buffer.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains definitions of buffers used in project
 * @date 2021-08-26
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#ifndef ENC_BUFFER_H
#define ENC_BUFFER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    uint8_t* buffer;
    uint16_t buffer_size;
    uint16_t buffer_data_counter;
} enc_buffer_t;

bool enc_buffer_init(enc_buffer_t *buffer_struct, uint8_t* buffer, uint8_t buffer_size);
bool enc_is_buffer_valid(enc_buffer_t* buffer_struct);
void enc_buffer_clear(enc_buffer_t* buffer_struct);
void enc_set_buffer_data_count(enc_buffer_t* buffer_struct, int data_count);

#endif //ENC_BUFFER_H