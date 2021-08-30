/**
 * @file enc_io.h
 * @author Marcin Dzieciątkowski (marcin.dzieciatkowski@mipso.pl)
 * @brief This file contains all functions concerning readint & writing to enc28j60
 * @date 2021-08-30
 *
 * @copyright Copyright (c) MIPSO Marcin Dzieciątkowski 2021
 *            Please refer to LICENSE file for more informations
 */

#ifndef ENC_IO_H
#define ENC_IO_H

#include "enc_data.h"

uint8_t read_control_register(uint8_t address);
uint8_t read_control_register2(uint8_t address);
bool write_control_register(uint8_t address, uint8_t value);

bool read_buffer_register(uint16_t start_address, enc_buffer_t* buffer, uint16_t data_length);
bool write_buffer_register(uint16_t start_address, enc_buffer_t* buffer, uint8_t* input_data, uint16_t data_size);

bool set_bit(uint8_t address, uint8_t mask);
bool clear_bit(uint8_t address, uint8_t mask);

uint16_t read_phy_register(uint8_t address);
bool write_phy_register(uint8_t address, uint16_t value);


void software_reset();


// HELPERS

void _set_buffer_rx_pointer_start(uint16_t loc);
void _set_buffer_tx_pointer_start(uint16_t loc);
void _set_buffer_tx_pointer_end(uint16_t loc);

#endif
