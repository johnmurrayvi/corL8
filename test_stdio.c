
/* 
 * test_stdio.c
 */

#include "test_stdio.h"

#include <stdio.h>

uchar* readSTDIOFrame()
{

  return NULL;
}

uchar* writeSTDIOFrame(uchar *frame)
{

  return NULL;
}

void printSTDIOFrame(uchar *frame)
{
  uint16_t i, frameLength;

  frameLength = frame[2] 
              + LENGTH_SLCP_HEADER
              + LENGTH_SLCP_LENGTH
              + LENGTH_SLCP_CHKSUM;

  printf("Frame contains:\n");
  for (i = 0; i < frameLength; i++) {
    printf("0x%.2x", frame[i]);
    if (i != frameLength - 1) printf(" ");
    else if (i == frameLength - 1) printf("\n");
  }

}
