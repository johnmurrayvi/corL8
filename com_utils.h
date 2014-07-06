
#ifndef _CORL8_COM_UTILS_H_
#define _CORL8_COM_UTILS_H_

/*
 * com_utils.h
 */


#include "corl8_defs.h"

/*!
 * \fn uchar* makeSLCPFrame(uchar *data, uchar dataLength);
 * \brief Allocate and create a compatible SLCP frame with the header
 *        bytes, payload length byte, payload bytes, and checksum byte.
 * \param data The frame payload
 * \param dataLength the length (number of bytes) of the data param
 * \return On success, a newly allocated frame that can be sent.
           On failure, NULL.
 */
extern uchar* makeSLCPFrame(uchar *data, uchar dataLength);

/*!
 * \fn uchar* makeQueryFrame(uchar cmd);
 * \brief Allocate and create a compatible SLCP frame with the header
 *        bytes, payload length byte, payload byte, and checksum byte.
 *        It is a convienence function for creating frames with 1 byte 
 *          payloads, namely CMD_*_QUERY. 
 *        This is a wrapper around \fn makeSLCPFrame.
 * \param cmd The query command to create a SLCP frame for
 * \return On success, a newly allocated frame that can be sent.
           On failure, NULL.
 */
extern uchar* makeQueryFrame(uchar cmd);

/*!
 * \fn sendSLCPFrame()
 */
extern uchar* sendSLCPFrame(uchar *payload);

/*!
 * \fn readSLCPFrame()
 */
extern uchar* readSLCPFrame(uchar *frame);

/*!
 * \fn handleReceivedPayload()
 */
extern uchar* handleReceivedPayload(uchar *payload, uchar dataLength);


#endif // _CORL8_COM_UTILS_H_
