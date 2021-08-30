/**
 * @file enc_utils.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file contains all initialisation procedures and functions prototypes for ENC28J60 integrated circuit
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#ifndef ENC_UTILS_H
#define ENC_UTILS_H

#include "enc_data.h"
#include "stddef.h"
#include "stdint.h"
#include "stdbool.h"

bool enc_select_bank(uint8_t bank);

#endif //ENC_UTILS_H
