
/* 
 * slcp_sensor_cmds.c
 */

#include "com_utils.h"
#include "crc_utils.h"
#include "slcp_sensor_cmds.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void queryVoltage()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_VOLTAGE_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseVoltage(uchar *data)
{
  uint16_t mVRaw = 0;
  uint8_t batPerc = 0;
  uchar *ret = 0;

  // mVRaw |= (0xFF00 & (data[0] << 8));
  // mVRaw |= (0x00FF & data[1]);

  mVRaw = ((0xFF00 & (data[0] << 8)) | (0x00FF & data[1]));

  batPerc = (0xFF & data[2]);

  if (batPerc > 100) {
    fprintf(stderr, "Received an invalid battery percentage (%3d) in responseVoltage!\n", batPerc);
    *ret = 1;
  }

  printf("Battery voltage: %4d mV, Percent charge remaining: %3d%%\n", mVRaw, batPerc);

  return ret;
}


void queryTemp()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_TEMP_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseTemp(uchar *data)
{
  uint16_t degRaw;
  double degC;

  // degRaw |= (0xFF00 & (data[0] << 8));
  // degRaw |= (0x00FF & data[1]);

  degRaw = ((0xFF00 & (data[0] << 8)) | (0x00FF & data[1]));

  degC = ((degRaw / 100.0) + (degRaw % 100));

  printf("Temperature: %2.2f\n", degC);

  return (uchar *) 0;
}


void queryAccel()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_ACC_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseAccel(uchar *data)
{
  uchar *Xaxis, *Yaxis, *Zaxis, *lying, *orientation, *tap, *shake;
  char *lyingPos = NULL, *orientPos = NULL;
  uchar *ret = 0;

  Xaxis = &data[0];
  Yaxis = &data[1];
  Zaxis = &data[2];
  lying = &data[3];
  orientation = &data[4];
  tap = &data[5];
  shake = &data[6];

  switch (*lying) {
    case 2:
      lyingPos = strdup("Rightside-Up");
      break;

    case 1:
      lyingPos = strdup("Upside-Down");
      break;

    default:
      fprintf(stderr, "Received an unknown value for 'lying' (%.2x) in responseAccel!\n", *lying);
      *ret = 1;
      break;
  }

  switch (*orientation) {
    case CMD_L8_ORIENTATION_STATUS_UP:
      orientPos = strdup("Up");
      break;

    case CMD_L8_ORIENTATION_STATUS_DOWN:
      orientPos = strdup("Down");
      break;

    case CMD_L8_ORIENTATION_STATUS_RIGHT:
      orientPos = strdup("Right");
      break;

    case CMD_L8_ORIENTATION_STATUS_LEFT:
      orientPos = strdup("Left");
      break;

    default:
      fprintf(stderr, "Received an unknown value for 'orientation' (%.2x) in responseAccel!\n", *orientation);
      *ret = 1;
      break;
  }

  switch (*tap) {
    case 1:
    case 0:
      break;

    default:
      fprintf(stderr, "Received an unknown value for 'tap' (%.2x) in responseAccel!\n", *tap);
      *ret = 1;
      break;
  }

  switch (*shake) {
    case 1:
    case 0:
      break;

    default:
      fprintf(stderr, "Received an unknown value for 'shake' (%.2x) in responseAccel!\n", *shake);
      *ret = 1;
      break;
  }

  printf("Accel Data:\n");
  printf("  X Axis: %d\n", *Xaxis);
  printf("  Y Axis: %d\n", *Yaxis);
  printf("  Z Axis: %d\n", *Zaxis);
  if (lyingPos) {
    printf("  Lying: %s\n", lyingPos);
    free(lyingPos);
  }
  if (orientPos) {
    printf("  Orientation: %s\n",orientPos );
    free(orientPos);
  }
  printf("  Tap: %d\n", *tap);
  printf("  Shake: %d\n", *shake);

  return ret;
}


void queryUID()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_UID_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseUID(uchar *data)
{
  uchar i;

  printf("L8 UID: ");
  for (i = 0; i < CMD_L8_UID_RESPONSE_LENGTH; i++) {
    printf("0x%.2x", data[i]);
    if (i != CMD_L8_UID_RESPONSE_LENGTH - 1) printf(" ");
    else if (i == CMD_L8_UID_RESPONSE_LENGTH - 1) printf("\n");
  }

  return (uchar *) 0;
}


void queryAmbient()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_AMBIENT_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseAmbient(uchar *data)
{
  uint16_t ambRaw;
  uchar ambPerc, notifFlag;
  uchar *ret = 0;

  ambRaw = ((0xFF00 & (data[0] << 8)) | (0x00FF & data[1]));

  ambPerc = (0xFF & data[2]);
  notifFlag = (0xFF & data[3]);

  if (ambPerc > 100) {
    fprintf(stderr, "Received an invalid proximity percentage (%3d) in responseProximity!\n", ambPerc);
    *ret = 1;
  }

  printf("Proximity sensor: %d (of %d)\n", ambRaw, 0xFFFF);
  printf("Proximity percentage: %d\n", ambPerc);

  if (notifFlag == 1) {
    printf("  Command initiated as a notification from the L8.\n");
  } else if (notifFlag == 0) {
    printf("  Command initiated as response to host request.\n");
  } else {
    fprintf(stderr, "Received an invalid notfication flag (%3d) in responseProximity!\n", notifFlag);
    *ret = 1;
  }

  return ret;
}


void queryProximity()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_PROX_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseProximity(uchar *data)
{
  uint16_t proxRaw;
  uchar proxPerc, notifFlag;
  uchar *ret = 0;

  proxRaw = ((0xFF00 & (data[0] << 8)) | (0x00FF & data[1]));

  proxPerc = (0xFF & data[2]);
  notifFlag = (0xFF & data[3]);

  if (proxPerc > 100) {
    fprintf(stderr, "Received an invalid proximity percentage (%3d) in responseProximity!\n", proxPerc);
    *ret = 1;
  }

  printf("Proximity sensor: %d (of %d)\n", proxRaw, 0xFFFF);
  printf("Proximity percentage: %d\n", proxPerc);

  if (notifFlag == 1) {
    printf("  Command initiated as a notification from the L8.\n");
  } else if (notifFlag == 0) {
    printf("  Command initiated as response to host request.\n");
  } else {
    fprintf(stderr, "Received an invalid notfication flag (%3d) in responseProximity!\n", notifFlag);
    *ret = 1;
  }

  return ret;
}


void queryVersions()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_VERSIONS_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseVersions(uchar *data)
{
  // uint32_t fwVer = 0;
  // uint16_t hwVer = 0, bldrVer = 0, umemVer = 0;

  // fwVer = ((0x00FF0000 & (data[0] << 16)) |
  //          (0x0000FF00 & (data[1] << 8)) |
  //          (0x000000FF & (data[2] << 0)));

  // hwVer = ((0xFF00 & (data[3] << 8)) | (0x00FF & data[4]));
  
  // bldrVer = ((0xFF00 & (data[5] << 8)) | (0x00FF & data[6]));

  // umemVer = ((0xFF00 & (data[7] << 8)) | (0x00FF & data[8]));

  printf("L8 Version Info:\n");

  printf("  Firmware Version: %d.%d.%d\n", (0x00FF0000 & (data[0] << 16)),
                                           (0x0000FF00 & (data[1] << 8)),
                                           (0x000000FF & (data[2] << 0)));

  printf("  Hardware Version: %d.%d\n", (0xFF00 & (data[3] << 8)),
                                        (0x00FF & (data[4] << 0)));

  printf("  Bootloader Version: %d.%d\n", (0xFF00 & (data[5] << 8)),
                                          (0x00FF & (data[6] << 0)));

  printf("  User Memory Version: %d.%d\n", (0xFF00 & (data[7] << 8)),
                                           (0x00FF & (data[8] << 0)));

  return (uchar *) 0;
}


void queryButton()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_MIC_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseButton(uchar *data)
{
  uchar button = data[0];
  uchar *ret = 0;

  switch (button) {
    case 1:
    case 0:
      break;

    default:
      fprintf(stderr, "Received an unknown value for 'button' (%.2x) in responseButton!\n", button);
      *ret = 1;
      break;
  }

  printf("Button: %d\n", button);

  return ret;
}


void queryMic()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_MIC_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseMic(uchar *data)
{
  uint16_t noiseRaw;

  noiseRaw = ((0xFF00 & (data[0] << 8)) | (0x00FF & data[1]));

  printf("Noise sensor: %d (of %d)\n", noiseRaw, 0xFFFF);

  return (uchar *) 0;
}


void queryVBUS()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_VBUS_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseVBUS(uchar *data)
{
  uint16_t mVRaw = 0;

  // mVRaw |= (0xFF00 & (data[0] << 8));
  // mVRaw |= (0x00FF & data[1]);

  mVRaw = ((0xFF00 & data[0]) | (0x00FF & data[1]));

  printf("VBUS voltage: %4d mV\n", mVRaw);

  return (uchar *) 0;
}


void queryMCUTemp()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_MCUTEMP_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseMCUTemp(uchar *data)
{
  uint16_t degC;

  degC = ((0xFF00 & (data[0] << 8)) | (0x00FF & data[1]));

  printf("MCU Temperature: %d\n", degC);

  return (uchar *) 0;
}


void queryBatCharge()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_BATCHG_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseBatCharge(uchar *data)
{
  uchar status = data[0];
  char *statusStr = NULL;
  uchar *ret = 0;

  switch (status) {
    case CMD_L8_BATCHG_STATUS_STANDBY:
      statusStr = strdup("Stand-By (Not charging).");
      break;
    
    case CMD_L8_BATCHG_STATUS_CHARGING:
      statusStr = strdup("Charging.");
      break;

    case CMD_L8_BATCHG_STATUS_CHRGCOMP:
      statusStr = strdup("Charge Complete.");
      break;

    case CMD_L8_BATCHG_STATUS_FAULT:
      statusStr = strdup("Fault!");
      break;

    default:
      fprintf(stderr, "Received an unknown value for 'status' (%.2x) in responseBatCharge!\n", status);
      *ret = 1;
      break;
  }

  if (statusStr) {
    printf("Battry Charge Status: %s\n", statusStr);
    free(statusStr);
  }

  return ret;
}


void queryOrientation()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_ORIENTATION_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseOrientation(uchar *data)
{
  uchar orientation = data[0];
  char *orientPos = NULL;
  uchar *ret = 0;

  switch (orientation) {
    case CMD_L8_ORIENTATION_STATUS_UP:
      orientPos = strdup("Up");
      break;

    case CMD_L8_ORIENTATION_STATUS_DOWN:
      orientPos = strdup("Down");
      break;

    case CMD_L8_ORIENTATION_STATUS_RIGHT:
      orientPos = strdup("Right");
      break;

    case CMD_L8_ORIENTATION_STATUS_LEFT:
      orientPos = strdup("Left");
      break;

    default:
      fprintf(stderr, "Received an unknown value for 'orientation' (%.2x) in responseOrientation!\n", orientation);
      *ret = 1;
      break;
  }

  if (orientPos) {
    printf("  Orientation: %s\n",orientPos );
    free(orientPos);
  }

  return ret;
}


uchar* setNoiseThresholds(uint16_t min, uint16_t max)
{
  uchar data[5];
  uchar *frame;

  data[0] = CMD_L8_NOISE_THRESHOLDS_SET;
  data[1] = ((0xFF00 & min) >> 8);
  data[2] = (0xFF & min);
  data[3] = ((0xFF00 & max) >> 8);
  data[4] = (0xFF & max);

  frame = makeSLCPFrame((uchar *) &data, 5);
  if (!frame) return NULL;

  sendSLCPFrame(frame);

  free(frame);

  return (uchar *) 0;
}

uchar* setProximityThresholds(uint16_t min, uint16_t max)
{
  uchar data[5];
  uchar *frame;

  data[0] = CMD_L8_PROX_THRESHOLDS_SET;
  data[1] = ((0xFF00 & min) >> 8);
  data[2] = (0xFF & min);
  data[3] = ((0xFF00 & max) >> 8);
  data[4] = (0xFF & max);

  frame = makeSLCPFrame((uchar *) &data, 5);
  if (!frame) return NULL;

  sendSLCPFrame(frame);

  free(frame);

  return (uchar *) 0;
}

uchar* setAmbientThresholds(uint16_t min, uint16_t max)
{
  uchar data[5];
  uchar *frame;

  data[0] = CMD_L8_AMB_THRESHOLDS_SET;
  data[1] = ((0xFF00 & min) >> 8);
  data[2] = (0xFF & min);
  data[3] = ((0xFF00 & max) >> 8);
  data[4] = (0xFF & max);

  frame = makeSLCPFrame((uchar *) &data, 5);
  if (!frame) return NULL;

  sendSLCPFrame(frame);

  free(frame);

  return (uchar *) 0;
}


void querySensorThresholds()
{
  uchar *frame;

  frame = makeQueryFrame(CMD_L8_SENSORS_THRESHOLDS_QUERY);

  sendSLCPFrame(frame);

  free(frame);
}

uchar* responseSensorThresholds(uchar *data)
{
  uint16_t min = 0, max = 0;
  uchar i;

  printf("Sensor Thresholds:\n");

  for (i = 0; i < 3; i++) {
    min = 0;
    max = 0;
    min |= (0xFF00 & (data[0+(i*4)] << 8)) | (0x00FF & (data[1+(i*4)] << 0));
    max |= (0xFF00 & (data[2+(i*4)] << 8)) | (0x00FF & (data[3+(i*4)] << 0));

    if (i == 0) printf("  Noise Sensor\n");
    else if (i == 1) printf("  Proximity Sensor\n");
    else if (i == 2) printf("  Ambient Sensor\n");

    printf("    Minimum Threshold: %d (of %d)\n", min, 0xFFFF);
    printf("    Maximum Threshold: %d (of %d)\n", min, 0xFFFF);
  }

  return (uchar *) 0;
}

