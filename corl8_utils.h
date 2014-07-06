
#ifndef _CORL8_UTILS_H_
#define _CORL8_UTILS_H_

/*
 * corl8_utils.h
 */

#include "corl8_defs.h"
#include "slcp_defs.h"

/*!
 * \fn makeFrame()
 */
extern uchar* makeFrame(uchar *data, uchar dataLength);

extern uchar* getBGR(uchar red, uchar green, uchar blue, uint16_t *bgr); 

#endif // _CORL8_UTILS_H_
