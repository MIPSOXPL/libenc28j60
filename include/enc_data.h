/**
 * @file enc_data.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains main structure for ENC28J60 integrated circuit
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#ifndef ENC_DATA_H
#define ENC_DATA_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "enc_buffer.h"

typedef struct {
    enc_buffer_t* in_buffer;
    enc_buffer_t* out_buffer;
    uint16_t loc;
    bool link_status;
} enc_data_t;

bool enc_data_init(enc_data_t* enc_data, enc_buffer_t* in_buffer, enc_buffer_t* out_buffer);
void enc_data_clear_input_buffer(enc_data_t* enc_data);
void enc_data_clear_output_buffer(enc_data_t* enc_data);
bool enc_is_data_valid(enc_data_t* enc_data);

#endif //ENC_DATA_H
