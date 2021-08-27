/**
 * @file enc_struct.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains main structure for ENC28J60 integrated circuit
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#ifndef ENC_STRUCT_H
#define ENC_STRUCT_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "enc_buffer.h"

typedef struct {
    enc_buffer_t* in_buffer;
    enc_buffer_t* out_buffer;
} enc_struct_t;

bool enc_init_enc_struct(enc_struct_t* enc_struct, enc_buffer_t* in_buffer, enc_buffer_t* out_buffer);
void enc_clear_input_buffer(enc_struct_t* enc_struct);
void enc_clear_output_buffer(enc_struct_t* enc_struct);

#endif //ENC_STRUCT_H
