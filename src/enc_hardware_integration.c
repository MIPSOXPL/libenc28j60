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
extern TIM_HandleTypeDef htim1;

__attribute__((weak)) bool spi_send_data(__attribute__((unused)) enc_buffer_t* enc_buffer)
{
	spi_reset_enc_nss();
	return HAL_SPI_Transmit(&hspi2, enc_buffer->buffer, enc_buffer->buffer_data_counter, 0xFFFFFFFF) == HAL_OK;
}

__attribute__((weak)) bool spi_send_data_nss(__attribute__((unused)) enc_buffer_t* enc_buffer)
{
	bool val = spi_send_data(enc_buffer);
	spi_set_enc_nss();
	return val;
}

__attribute__((weak)) bool spi_receive_data(__attribute__((unused)) enc_buffer_t* enc_buffer,
                                            __attribute__((unused)) uint16_t data_length)
{
	enc_buffer->buffer_data_counter = data_length;
	HAL_StatusTypeDef val = HAL_SPI_Receive(&hspi2, enc_buffer->buffer, data_length, 0xFFFFFFFF);
	spi_set_enc_nss();
	return val == HAL_OK;
}

void spi_set_enc_nss()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
}

void spi_reset_enc_nss()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
}

void delay_us(uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1, 0);  // set the counter value a 0
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);  // wait for the counter to reach the us input in the parameter
}
