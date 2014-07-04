
#ifndef _CORL8_USB_SERIAL_H_
#define _CORL8_USB_SERIAL_H_

/* 
 * usb_serial.h
 */

#include "corl8_defs.h"
#include "slcp_defs.h"


extern uchar* readUSBFrame();
extern uchar* writeUSBFrame(uchar *frame);

extern uchar* initTTY(char *ttyPath);
extern uchar* closeTTY();
extern int getTTYFD();


#endif // _CORL8_USB_SERIAL_H_
