

/*
 * corl8_app_tty.c
 */

#include "com_utils.h"
#include "crc_utils.h"
#include "slcp_cmds.h"
#include "usb_serial.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>

int main(int argc, char **argv)
{
  uchar *ret;
  char *path = "/dev/ttyACM0";
  int ttyfd;
  uchar c = 0;

  ret = initTTY(path);
  if (ret == NULL) {
    fprintf(stderr, "Failed to init the USB TTY!\n");
  } else if (ret == (uchar *) 1) {
    printf("Successfully init'd the USB TTY!\n");
  }

  ttyfd = getTTYFD();

  uchar *chk;
  // chk = crc8(CMD_PING);
  chk = crc8(CMD_L8_VERSIONS_QUERY);

  uchar pingFrame[6];
  pingFrame[0] = SLCP_HEADER_BEGIN;
  pingFrame[1] = SLCP_HEADER_END;
  pingFrame[2] = 0x01;
  // pingFrame[3] = CMD_PING;
  pingFrame[3] = CMD_L8_VERSIONS_QUERY;
  pingFrame[4] = *chk;
  pingFrame[5] = 0x00;

  int i;
  printf("writing:\n");
  write(ttyfd, pingFrame, 6);
  for (i = 0; i < 6; i++) {
    printf("png[%d] = 0x%x\n", i, pingFrame[i]);
  }


  uchar buf[250];
  memset(&buf, 0, 250);

  // if (read(ttyfd, &buf, 250) > 0) {
  //   printf("reading:\n");
  //   for (i = 0; i < 250; i++) {
  //     printf("buf[%d] = 0x%x\n", i, buf[i]);
  //   }
  // }

  // printf("reading:\n");
  // for (i = 0; i < 250; i++) {
  //   printf("buf[%d] = 0x%x\n", i, buf[i]);
  // }

  while (c != 'q') {
    if (read(STDIN_FILENO, &c, 1) > 0) {
      write(ttyfd, &c, 1); // if new data is available on the console, send it to the serial port
    }

    if (read(ttyfd, &buf, 6) > 0) {
      printf("reading:\n");
      for (i = 0; i < 20; i++) {
        printf("buf[%d] = 0x%x\n", i, buf[i]);
      }
    }
  }
  //   if (read(ttyfd, &c, 1) > 0) {
  //     write(STDOUT_FILENO, &c, 1); // if new data is available on the serial port, print it out
  //   }

  //   if (read(STDIN_FILENO, &c, 1) > 0) {
  //     write(ttyfd, &c, 1); // if new data is available on the console, send it to the serial port
  //   }
  // }

  closeTTY();

  return 0;
}
