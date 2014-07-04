
#ifndef _CORL8_CRC_UTILS_H_
#define _CORL8_CRC_UTILS_H_

/*
 * crc_utils.h
 */

#include "corl8_defs.h"

/*!
 * \fn crc8_frame()
 */
extern uchar* crc8_frame(uchar *data, uchar length);

/*!
 * \fn crc8()
 */
extern uchar* crc8(uchar data);


#endif // _CORL8_CRC_UTILS_H_
