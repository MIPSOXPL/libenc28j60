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

void enc_init_receive_buffer(int receive_buffer_size);
void enc_init_transmit_buffer(int receive_buffer_size);

#endif //ENC_INIT_H
