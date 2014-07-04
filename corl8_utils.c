
/*
 * corl8_utils.c
 */

#include "corl8_utils.h"
#include "crc_utils.h"

#include <stdio.h>
#include <stdlib.h>


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

