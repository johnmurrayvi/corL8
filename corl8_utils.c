
/*
 * corl8_utils.c
 */

#include "corl8_utils.h"
#include "crc_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memset


uchar* getBGR_2B(uchar red, uchar green, uchar blue, uint16_t* bgr)
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
  bgr |= (0x0F00 & (blue << 8));
  
  // Set green
  bgr |= (0x00F0 & (green << 4));

  // Set red
  bgr |= (0x000F & (red << 0));

  return (uchar *) 0;
}

