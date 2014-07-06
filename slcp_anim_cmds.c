
/*
 * slcp_anim_cmds.c
 */

#include "com_utils.h"
#include "slcp_anim_cmds.h"

#include <stdio.h>
#include <stdlib.h>


uchar* displayCharShift(char c, uchar shiftDir, uchar shiftAmt)
{
  uchar data[2], shiftByte = 0;
  uchar *frame;

  if (shiftDir >= 4) {
    fprintf(stderr, "displayCharShift got invalid shiftDir: %d\n", shiftDir);
    return NULL;
  }

  if (shiftAmt >= 8) {
    fprintf(stderr, "displayCharShift got invalid shiftAmt: %d\n", shiftAmt);
    return NULL;
  }

  shiftByte |= (0xC0 & (shiftDir << 6));
  shiftByte |= (0x0F & (shiftAmt << 0));

  data[0] = CMD_L8_DISP_CHAR;
  data[1] = shiftByte;

  frame = makeSLCPFrame((uchar *) &data, 2);

  if (!frame) return NULL;

  sendSLCPFrame(frame);

  free(frame);

  return (uchar *) 0;

}

uchar* displayChar(char c)
{
  return displayCharShift(c, 0, 0);
}

