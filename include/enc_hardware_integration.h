/**
 * @file enc_hardware_integration.h
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
#include "enc_buffer.h"

#include "stm32g4xx_hal.h"


#define NSS_PORT GPIOA
#define NSS_PIN GPIO_PIN_4

bool spi_send_data(enc_buffer_t* enc_buffer);
bool spi_send_data2(uint8_t* data, uint16_t data_size);
bool spi_receive_data(enc_buffer_t* enc_buffer, uint16_t data_length);
bool spi_receive_data2(uint8_t* buffer, uint16_t data_length);

void spi_set_enc_nss();
void spi_reset_enc_nss();

#endif //ENC_HARDWARE_INTEGRATION_H
