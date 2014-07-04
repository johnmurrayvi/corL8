
/* 
 * slcp_ack_cmds.c
 */

#include "com_utils.h"
#include "slcp_ack_cmds.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


uchar* sendCMDPING()
{
  uchar *frame;
  uchar *ret = 0;

  frame = makeQueryFrame(CMD_PING);

  ret = sendFrame(frame);

  free(frame);

  return ret;
}

uchar* handleCMDPONG()
{
  printf("Recieved PONG!\n");

  return (uchar *) 0;
}


uchar* handleCMDERR(uchar *data)
{
  uchar failedCMD = data[0];
  uchar *ret = 0;

  // XXX later translate hexvalue to command name  
  printf("L8 replied with CMD_ERR to %.2x\n", failedCMD);

  return ret;
}

uchar* handleCMDOK(uchar *data)
{
  uchar okCMD = data[0];
  uchar *ret = 0;

  // XXX later translate hexvalue to command name  
  printf("L8 replied with CMD_OK to %.2x\n", okCMD);

  return ret;
}
