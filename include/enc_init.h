/**
 * @file enc_init.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains all initialisation procedures and functions for ENC28J60 integrated circuit
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#ifndef ENC_INIT_H
#define ENC_INIT_H

#include "enc_data.h"

typedef enum {
    broadcast_filter 		= 0x01,
    multicast_filter 		= 0x02,
    hash_table_filter 		= 0x04,
    magic_packet_filter 	= 0x08,
    pattern_match_filter 	= 0x10,
    post_crc_check_filter 	= 0x20,
    and_or_filter 			= 0x40,
	unicast_filter 			= 0x80
} enc_filters;

bool enc_init_receive_buffer(enc_data_t* enc_data, uint16_t receive_buffer_offset, uint16_t receive_buffer_size);

/**
 * @brief Default filters are: broadcast_filter, post_crc_check_filter, unicast_filter
 */
bool enc_init_receive_filters(enc_data_t*, uint8_t filters_value);

#endif //ENC_INIT_H
