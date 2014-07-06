
/*
 * corl8_utils.c
 */

#include "corl8_utils.h"
#include "crc_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memset


uchar* makeFrame(uchar *data, uchar dataLength)
{
  if (!data) {
    fprintf(stderr, "No data passed into makeFrame function!\n");
    return NULL;
  }
  if (!dataLength) {
    fprintf(stderr, "No dataLength passed into makeFrame function!\n");
    return NULL;
  }

  uchar i;
  uchar *frame, *chksum;

  uchar *payload = (uchar *) data;
  int frameLength = dataLength
                  + LENGTH_SLCP_HEADER
                  + LENGTH_SLCP_LENGTH
                  + LENGTH_SLCP_CHKSUM;

  chksum = crc8_frame(data, dataLength);
  if (chksum == NULL) {
    fprintf(stderr, "CRC8 function returned NULL!\n");
    return NULL;
  }

  frame = (uchar *) malloc(sizeof(uchar) * frameLength);

  frame[0] = SLCP_HEADER_BEGIN;
  frame[1] = SLCP_HEADER_END;
  frame[2] = dataLength;

  for (i = 0; i < dataLength; i++)
    frame[i+3] = payload[i];


  frame[frameLength - 1] = *chksum;

  return (uchar *) frame;
}

uchar* getBGR(uchar red, uchar green, uchar blue, uint16_t* bgr)
{
  if (red >= 16)
    fprintf(stderr, "setBGR is clipping extraneous bits from red!\n");

  if (green >= 16)
    fprintf(stderr, "setBGR is clipping extraneous bits from green!\n");

  if (blue >= 16)
    fprintf(stderr, "setBGR is clipping extraneous bits from blue!\n");

  // Zero out data
  memset(&bgr, 0, sizeof(uint16_t));

  // Set blue
  bgr |= (0xFF0000 & (blue << 4));
  
  // Set green
  bgr |= (0xFF00 & (green << 2));

  // Set red
  bgr |= (0x00FF & (red << 0));

  return (uchar *) 0;
}

