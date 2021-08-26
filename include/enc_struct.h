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

typedef struct {
    uint8_t* output_buffer;
    uint16_t output_buffer_size;
    uint8_t* input_buffer;
    uint16_t input_buffer_size;

    uint16_t output_buffer_data_counter;
    uint16_t input_buffer_data_counter;    
} enc_struct_t;

bool enc_init_enc_struct(enc_struct_t* enc_struct, uint8_t* output_buffer, uint8_t output_buffer_size, uint8_t* input_buffer, uint8_t input_buffer_size);
void enc_clear_input_buffer(enc_struct_t* enc_struct);
void enc_clear_output_buffer(enc_struct_t* enc_struct);

#endif //ENC_STRUCT_H
