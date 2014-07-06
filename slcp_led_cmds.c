
/*
 * slcp_led_cmds.c
 */

#include "com_utils.h"
#include "slcp_led_cmds.h"

#include <stdio.h>
#include <stdlib.h>


uchar* setLED(uchar x, uchar y, uchar red, uchar green, uchar blue)
{
  uchar r = 0, g = 0, b = 0;
  uchar data[6];
  uchar *frame;

  if (x > 7 || y > 7) {
    fprintf(stderr, "Bad coordinates, must be 0-7! setLED: (%d, %d)\n", x, y);
    return NULL;
  }

  if (red >= 16)
    fprintf(stderr, "setLED is clipping extraneous bits from red!\n");

  if (green >= 16)
    fprintf(stderr, "setLED is clipping extraneous bits from green!\n");

  if (blue >= 16)
    fprintf(stderr, "setLED is clipping extraneous bits from blue!\n");

  r |= (0xF & red);
  g |= (0xF & green);
  b |= (0xF & blue);

  data[0] = CMD_L8_LED_SET;
  data[1] = x;
  data[2] = y;
  data[3] = b;
  data[4] = g;
  data[5] = r;

  frame = makeSLCPFrame((uchar *) &data, 6);

  if (!frame) return NULL;

  sendSLCPFrame(frame);

  free(frame);

  return (uchar *) 0;
}



uchar* setSuperLED(uchar red, uchar green, uchar blue)
{
  uchar r = 0, g = 0, b = 0;
  uchar data[6];
  uchar *frame;

  if (red >= 16)
    fprintf(stderr, "setLED is clipping extraneous bits from red!\n");

  if (green >= 16)
    fprintf(stderr, "setLED is clipping extraneous bits from green!\n");

  if (blue >= 16)
    fprintf(stderr, "setLED is clipping extraneous bits from blue!\n");

  r |= (0xF & red);
  g |= (0xF & green);
  b |= (0xF & blue);

  data[0] = CMD_L8_SUPERLED_SET;
  data[1] = b;
  data[2] = g;
  data[3] = r;

  frame = makeSLCPFrame((uchar *) &data, 4);

  if (!frame) return NULL;

  sendSLCPFrame(frame);

  free(frame);

  return (uchar *) 0;
}



void matrixOff()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_MATRIX_OFF);

  if (!frame) return;

  sendSLCPFrame(frame);

  free(frame);
}



uchar* setStatusLEDs(uchar enable)
{
  if (enable > 1) {
    fprintf(stderr, "setStatusLEDs recevied invalid 'enable' bool param\n");
    return NULL;
  }

  uchar data[2];
  uchar *frame;

  data[0] = CMD_L8_STATUSLEDS_ENABLE;
  data[1] = enable;

  frame = makeSLCPFrame((uchar *) &data, 2);

  if (!frame) return NULL;

  sendSLCPFrame(frame);

  free(frame);

  return (uchar *) 0;
}

