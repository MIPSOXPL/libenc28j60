/**
 * @file enc_init.c
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains functions to initialise
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#include "enc_init.h"
#include "enc_command_builder.h"

#include "stdint.h"
#include "stdbool.h"

extern bool spi_send_data(const uint16_t address, const uint8_t* data, int data_length);
extern bool spi_receive_data(const uint16_t address, int data_length, uint8_t* buffer, int buffer_size);

