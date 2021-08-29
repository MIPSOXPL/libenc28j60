/**
 * @file enc_hardware_integration.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains placeholder implementation for hardware integration functions
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#include "enc_hardware_integration.h"
#include "stm32g4xx_hal.h"

extern SPI_HandleTypeDef hspi2;

__attribute__((weak)) bool spi_send_data(__attribute__((unused)) enc_buffer_t* enc_buffer)
{
	return HAL_SPI_Transmit(&hspi2, enc_buffer->buffer, enc_buffer->buffer_data_counter, 0xFFFFFFFF) == HAL_OK;
}

__attribute__((weak)) bool spi_receive_data(__attribute__((unused)) enc_buffer_t* enc_buffer,
                                            __attribute__((unused)) uint16_t data_length)
{
	enc_buffer->buffer_data_counter = data_length;
	return HAL_SPI_Receive(&hspi2, enc_buffer->buffer, data_length, 0xFFFFFFFF) == HAL_OK;
}
