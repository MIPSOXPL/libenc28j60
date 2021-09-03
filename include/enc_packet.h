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
#include "my_ethernet.h"

bool enc_send_packet(uint8_t* data, uint16_t data_size);

pbuf* enc_receive_packet(enc_data_t* t);
#endif
