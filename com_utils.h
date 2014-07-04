
#ifndef _CORL8_COM_UTILS_H_
#define _CORL8_COM_UTILS_H_

/*
 * com_utils.h
 */


#include "corl8_defs.h"

/*!
 * \fn makeFrame()
 */
extern uchar* makeFrame(uchar *data, uchar dataLength);

/*!
 * \fn makeQueryFrame()
 */
extern uchar* makeQueryFrame(uchar cmd);

/*!
 * \fn sendFrame()
 */
extern uchar* sendFrame(uchar *payload);

/*!
 * \fn readFrame()
 */
extern uchar* readFrame(uchar *frame);

/*!
 * \fn handleReceivedPayload()
 */
extern uchar* handleReceivedPayload(uchar *payload, uchar dataLength);


// cmd_ping ?
// cmd_pong ?

#endif // _CORL8_COM_UTILS_H_
