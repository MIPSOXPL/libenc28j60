/**
 * @file enc_const.h
 * @author Sławomir Kozok (slawomir.kozok@mipso.pl)
 * @brief This file constants used for driver
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) MIPSO Sławomir Kozok 2021
 *            Please refer to LICENSE file for more informations
 * 
 */

#ifndef ENC_CONST_H
#define ENC_CONST_H

#define ENC_0_BANK              0x00
#define ENC_ERDPTL_REG_ADDR     0x00
#define ENC_ERDPTH_REG_ADDR     0x01
#define ENC_EWRPTL_REG_ADDR     0x02
#define ENC_EWRPTH_REG_ADDR     0x03
#define ENC_ETXSTL_REG_ADDR     0x04
#define ENC_ETXSTH_REG_ADDR     0x05
#define ENC_ETXNDL_REG_ADDR     0x06
#define ENC_ETXNDH_REG_ADDR     0x07
#define ENC_ERXSTL_REG_ADDR     0x08
#define ENC_ERXSTH_REG_ADDR     0x09
#define ENC_ERXNDL_REG_ADDR     0x0A
#define ENC_ERXNDH_REG_ADDR     0x0B
#define ENC_ERXRDPTL_REG_ADDR   0x0C
#define ENC_ERXRDPTH_REG_ADDR   0x0D
#define ENC_ERXWRPTL_REG_ADDR   0x0E
#define ENC_ERXWRPTH_REG_ADDR   0x0F
#define ENC_EDMASTL_REG_ADDR    0x10
#define ENC_EDMASTH_REG_ADDR    0x11
#define ENC_EDMANDL_REG_ADDR    0x12
#define ENC_EDMANDH_REG_ADDR    0x13
#define ENC_EDMADSTL_REG_ADDR   0x14
#define ENC_EDMADSTH_REG_ADDR   0x15
#define ENC_EDMACSL_REG_ADDR    0x16
#define ENC_EDMACSH_REG_ADDR    0x17

#define ENC_1_BANK              0x01
#define ENC_EHT0_REG_ADDR       0x00
#define ENC_EHT1_REG_ADDR       0x01
#define ENC_EHT2_REG_ADDR       0x02
#define ENC_EHT3_REG_ADDR       0x03
#define ENC_EHT4_REG_ADDR       0x04
#define ENC_EHT5_REG_ADDR       0x05
#define ENC_EHT6_REG_ADDR       0x06
#define ENC_EHT7_REG_ADDR       0x07
#define ENC_EPMM0_REG_ADDR      0x08
#define ENC_EPMM1_REG_ADDR      0x09
#define ENC_EPMM2_REG_ADDR      0x0A
#define ENC_EPMM3_REG_ADDR      0x0B
#define ENC_EPMM4_REG_ADDR      0x0C
#define ENC_EPMM5_REG_ADDR      0x0D
#define ENC_EPMM6_REG_ADDR      0x0E
#define ENC_EPMM7_REG_ADDR      0x0F
#define ENC_EPMCSL_REG_ADDR     0x10
#define ENC_EPMCSH_REG_ADDR     0x11
#define ENC_EPMOL_REG_ADDR      0x14
#define ENC_EPMOH_REG_ADDR      0x15
#define ENC_ERXFCON_REG_ADDR    0x18
#define ENC_EKPTCNT_REG_ADDR    0x19

#define ENC_2_BANK              0x02
#define ENC_MACON1_REG_ADDR     0x00
#define ENC_MACON3_REG_ADDR     0x02
#define ENC_MACON4_REG_ADDR     0x03
#define ENC_MABBIPG_REG_ADDR    0x04
#define ENC_MAIPGL_REG_ADDR     0x06
#define ENC_MAIPGH_REG_ADDR     0x07
#define ENC_MACLCON1_REG_ADDR   0x08
#define ENC_MACLCON2_REG_ADDR   0x09
#define ENC_MAMXFLL_REG_ADDR    0x0A
#define ENC_MAMXFLH_REG_ADDR    0x0B
#define ENC_MICMD_REG_ADDR      0x12
#define ENC_MIREGADR_REG_ADDR   0x14
#define ENC_MIWRL_REG_ADDR      0x16
#define ENC_MIWRH_REG_ADDR      0x17
#define ENC_MIRDL_REG_ADDR      0x18
#define ENC_MIRDH_REG_ADDR      0x19

#define ENC_3_BANK              0x03
#define ENC_MAADR5_REG_ADDR     0x00
#define ENC_MAADR6_REG_ADDR     0x01
#define ENC_MAADR3_REG_ADDR     0x02
#define ENC_MAADR4_REG_ADDR     0x03
#define ENC_MAADR1_REG_ADDR     0x04
#define ENC_MAADR2_REG_ADDR     0x05
#define ENC_EBSTSD_REG_ADDR     0x06
#define ENC_EBSTCON_REG_ADDR    0x07
#define ENC_EBSTCSL_REG_ADDR    0x08
#define ENC_EBSTCSH_REG_ADDR    0x09
#define ENC_MISTAT_REG_ADDR     0x0A
#define ENC_EREVID_REG_ADDR     0x12
#define ENC_ECOCON_REG_ADDR     0x15
#define ENC_EFLOCON_REG_ADDR    0x17
#define ENC_EPAUSL_REG_ADDR     0x18
#define ENC_EPAUSH_REG_ADDR     0x19

#define ENC_G_EIE_REG_ADDR      0x1B
#define ENC_G_EIR_REG_ADDR      0x1C
#define ENC_G_ESTAT_REG_ADDR    0x1D
#define ENC_G_ECON2_REG_ADDR    0x1E
#define ENC_G_ECON1_REG_ADDR    0x1F

#endif //ENC_CONST_H
