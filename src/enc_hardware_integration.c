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

__attribute__((weak)) bool spi_send_data(__attribute__((unused)) const uint16_t address,
                                         __attribute__((unused)) const uint8_t* data, 
                                         __attribute__((unused)) int data_length)
{

}

__attribute__((weak)) bool spi_receive_data(__attribute__((unused)) const uint16_t address, 
                                            __attribute__((unused)) int data_length, 
                                            __attribute__((unused)) uint8_t* buffer,
                                            __attribute__((unused)) int buffer_size)
{

}
