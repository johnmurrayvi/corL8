

/*
 * corl8_app.c
 */

#include "com_utils.h"
#include "crc_utils.h"
#include "slcp_ack_cmds.h"
#include "slcp_sensor_cmds.h"
#include "test_stdio.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>

int main(int argc, char **argv)
{
  uchar *chk;

  // chk = crc8(CMD_PING);
  chk = crc8(CMD_L8_VERSIONS_QUERY);

  uchar pingFrame[5];
  pingFrame[0] = SLCP_HEADER_BEGIN;
  pingFrame[1] = SLCP_HEADER_END;
  pingFrame[2] = 0x01;
  // pingFrame[3] = CMD_PING;
  pingFrame[3] = CMD_L8_VERSIONS_QUERY;
  pingFrame[4] = *chk;

  printSTDIOFrame(&pingFrame[0]);

  return 0;
}
