/**
 * @file enc_packet.h
 * @author Marcin Dzieciątkowski (marcin.dzieciatkowski@mipso.pl)
 * @brief This file contains all functions concerning receiving & sending data packets over internet
 * @date 2021-08-30
 *
 * @copyright Copyright (c) MIPSO Marcin Dzieciątkowski 2021
 *            Please refer to LICENSE file for more informations
 */

#ifndef ENC_PACKET_H
#define ENC_PACKET_H

#include "enc_data.h"

#define START_BUFFER_TX 0x120

bool enc_send_packet(enc_data_t* t, uint8_t* data, uint16_t data_size);

bool enc_receive_packet(enc_data_t* t);


// PRIVATE HELPER METHODS

static void start_transmission();
static void read_status_vector(enc_buffer_t* buffer, uint8_t* save_here, uint16_t start_reading_from_here);



#endif
