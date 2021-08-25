/**
 * @file enc_init.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains prototype signatures for hardware integration functions
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#ifndef ENC_HARDWARE_INTEGRATION_H
#define ENC_HARDWARE_INTEGRATION_H

#include "stdint.h"
#include "stdbool.h"

bool spi_send_data(const uint16_t address, const uint8_t* data, int data_length);
bool spi_receive_data(const uint16_t address, int data_length, uint8_t* buffer, int buffer_size);

#endif //ENC_HARDWARE_INTEGRATION_H
