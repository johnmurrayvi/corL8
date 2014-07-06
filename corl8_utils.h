
#ifndef _CORL8_UTILS_H_
#define _CORL8_UTILS_H_

/*
 * corl8_utils.h
 */

#include "corl8_defs.h"
#include "slcp_defs.h"


/*!
 * \fn uchar* getBGR_2B(uchar red, uchar green, uchar blue, uint16_t *bgr);
 * \brief 
 * \param red The red value to be used (0x0 to 0xF)
 * \param green The green value to be used (0x0 to 0xF)
 * \param blue The blue value to be used (0x0 to 0xF)
 * \param bgr An alreday-allocated 2 byte space to put the BGR
 * \return On success, returns 0.
 */
extern uchar* getBGR_2B(uchar red, uchar green, uchar blue, uint16_t *bgr);

#endif // _CORL8_UTILS_H_
