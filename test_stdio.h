
#ifndef _CORL8_TEST_STDIO_H_
#define _CORL8_TEST_STDIO_H_

/* 
 * test_stdio.h
 */

#include "corl8_defs.h"
#include "slcp_defs.h"


extern uchar* readSTDIOFrame();
extern uchar* writeSTDIOFrame(uchar *frame);

extern void printSTDIOFrame(uchar *frame);

#endif // _CORL8_TEST_STDIO_H_
