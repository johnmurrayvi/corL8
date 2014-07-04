/*
 * usb_serial.c
 */

#include "usb_serial.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>

#include <errno.h>
#include <termios.h>

struct termios ttyUSB;
int ttyFD;


uchar *readUSBFrame(uchar *frame)
{

  return NULL;
}


uchar *writeUSBFrame(uchar *frame)
{

  return NULL;
}


uchar *initTTY(char *ttyPath)
{
  if (ttyPath == NULL) {
    fprintf(stderr, "Didn't pass path to initTTY!\n");
    return NULL;
  }

  ttyFD = open(ttyPath, O_RDWR | O_NOCTTY | O_NDELAY);
  if (ttyFD < 0) {
    fprintf(stderr, "Couldn't open file at %s!\n", ttyPath);
    return NULL;
  }

  if (!isatty(ttyFD)) {
    fprintf(stderr, "The file specified isn't a tty!\n");
    return NULL;
  }

  memset(&ttyUSB, 0, sizeof(struct termios));

  if (tcgetattr(ttyFD, &ttyUSB) < 0) {
    fprintf(stderr, "Failed to get attributes from ttyFD!\n");
    return NULL;
  }

  ttyUSB.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR | 
                      PARMRK | INPCK | ISTRIP | IXON);
  ttyUSB.c_oflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);  
  ttyUSB.c_lflag &= 0;
  ttyUSB.c_cflag &= ~(CSIZE | PARENB);
  ttyUSB.c_cflag |= CS8;

  ttyUSB.c_cc[VMIN] = 1;
  ttyUSB.c_cc[VTIME] = 0;

  if ((cfsetispeed(&ttyUSB, B9600) < 0) || (cfsetospeed(&ttyUSB, B9600) < 0)) {
    fprintf(stderr, "Failed to set baud rate!\n");
    return NULL;
  }

  if (tcsetattr(ttyFD, TCSAFLUSH, &ttyUSB) < 0) {
    fprintf(stderr, "Failed to set tty configuration!\n");
    return NULL;
  }

  return (uchar *) 1;
};


uchar *closeTTY()
{
  close(ttyFD);

  return (uchar *) 1;
};

int getTTYFD()
{
  return ttyFD;
}
