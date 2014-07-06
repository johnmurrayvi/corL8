

#include "com_utils.h"
#include "corl8_utils.h"
#include "crc_utils.h"
#include "slcp_ack_cmds.h"
#include "slcp_sensor_cmds.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


uchar* makeSLCPFrame(uchar *data, uchar dataLength)
{
  if (!data) {
    fprintf(stderr, "No data passed into makeFrame function!\n");
    return NULL;
  }
  if (!dataLength) {
    fprintf(stderr, "No dataLength passed into makeFrame function!\n");
    return NULL;
  }

  uchar *frame, *chksum, *payload;

  payload = data;
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

  memcpy(&(frame[3]), payload, dataLength);

  frame[frameLength - 1] = *chksum;

  return (uchar *) frame;
}

uchar* makeQueryFrame(uchar cmd)
{
  // TODO: should check to make sure that cmd is a QUERY cmd
  return makeSLCPFrame(&cmd, 1);
}

uchar* sendSLCPFrame(uchar *payload)
{
  uchar *ret = 0;
  uchar cmd;

  if (!payload) {
    fprintf(stderr, "sendFrame was passed a NULL payload!\n");
    return NULL;
  }

  cmd = payload[0];

  switch (cmd) {
    // Don't send commands that we should only be receiving
    case CMD_PONG:
    case CMD_L8_VOLTAGE_RESPONSE:
    case CMD_L8_TEMP_RESPONSE:
    case CMD_L8_ACC_RESPONSE:
    case CMD_L8_UID_RESPONSE:
    case CMD_L8_AMBIENT_RESPONSE:
    case CMD_L8_PROX_RESPONSE:
    case CMD_L8_VERSIONS_RESPONSE:
    case CMD_L8_BUTTON_RESPONSE:
    case CMD_L8_MIC_RESPONSE:
    case CMD_L8_VBUS_RESPONSE:
    case CMD_L8_MCUTEMP_RESPONSE:
    case CMD_L8_STORE_L8Y_RESPONSE:
    case CMD_L8_READ_L8Y_RESPONSE:
    case CMD_L8_STORE_FRAME_RESPONSE:
    case CMD_L8_READ_FRAME_RESPONSE:
    case CMD_L8_BATCHG_RESPONSE:
    case CMD_L8_STORE_ANIM_RESPONSE:
    case CMD_L8_READ_ANIM_RESPONSE:
    case CMD_L8_ORIENTATION_RESPONSE:
    case CMD_L8_NUML8IES_RESPONSE:
    case CMD_L8_NUMANIMS_RESPONSE:
    case CMD_L8_NUMFRAMES_RESPONSE:
    case CMD_L8_NOTIFAPP_RESPONSE:
    case CMD_L8_NOTIFAPPS_NUM_RESPONSE:
    case CMD_L8_FRAMEGRAB_RESPONSE:
    case CMD_L8_SENSORS_THRESHOLDS_RESPONSE:
    case CMD_L8_NOTIFAPPS_SILENCE_RESPONSE:
      fprintf(stderr, "sendFrame shouldn't be sending a RESPONSE command!\n");
      *ret = 1;
      break;

    default:
      *ret = 0;
      break;
  }


  return ret;
}

uchar* readSLCPFrame(uchar *frame)
{
  uchar payloadLength;
  uchar *chksum, *payload;

  if ((frame[0] != SLCP_HEADER_BEGIN) || (frame[1] != SLCP_HEADER_END)) {
    fprintf(stderr, "readFrame received a frame with an invalid header!\n");
    return NULL;
  }

  payloadLength = frame[2];

  if (payloadLength == 0) {
    fprintf(stderr, "readFrame received a frame with an 0 length payload!\n");
    return NULL;
  }

  chksum = crc8_frame(&(frame[3]), payloadLength);
  if (chksum == NULL) {
    fprintf(stderr, "CRC8 function returned NULL!\n");
    return NULL;
  } else if (*chksum != frame[2 + payloadLength]) {
    fprintf(stderr, "CRC8 of received frame doesn't match calculated CRC8 in readFrame!\n");
    return NULL;
  }

  payload = (uchar *) malloc(sizeof(uchar) * payloadLength);

  memcpy(payload, &(frame[3]), payloadLength);

  handleReceivedPayload(payload, payloadLength);

  return (uchar *) 0;
}

uchar* handleReceivedPayload(uchar *payload, uchar payloadLength)
{
  uchar cmd, dataLength;
  uchar *data;
  uchar *ret = 0;

  cmd = payload[0];
  data = &(payload[1]);
  dataLength = payloadLength - 1;

  switch (cmd) {
    case CMD_L8_VOLTAGE_RESPONSE:
      if (dataLength != CMD_L8_TEMP_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseVoltage(data);
      }
      break;

    case CMD_L8_TEMP_RESPONSE:
      if (dataLength != CMD_L8_TEMP_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
      ret = responseTemp(data);
    }
      break;

    case CMD_L8_ACC_RESPONSE:
      if (dataLength != CMD_L8_ACC_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseAccel(data);
      }
      break;

    case CMD_L8_UID_RESPONSE:
      if (dataLength != CMD_L8_UID_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseUID(data);
      }
      break;

    case CMD_L8_AMBIENT_RESPONSE:
      if (dataLength != CMD_L8_AMBIENT_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseAmbient(data);
      }
      break;

    case CMD_L8_PROX_RESPONSE:
      if (dataLength != CMD_L8_PROX_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseProximity(data);
      }
      break;

    case CMD_L8_VERSIONS_RESPONSE:
      if (dataLength != CMD_L8_VERSIONS_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseVersions(data);
      }
      break;

    case CMD_L8_BUTTON_RESPONSE:
      if (dataLength != CMD_L8_BUTTON_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseButton(data);
      }
      break;

    case CMD_L8_MIC_RESPONSE:
      if (dataLength != CMD_L8_MIC_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseMic(data);
      }
      break;

    case CMD_L8_VBUS_RESPONSE:
      if (dataLength != CMD_L8_VBUS_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseVBUS(data);
      }
      break;

    case CMD_L8_MCUTEMP_RESPONSE:
      if (dataLength != CMD_L8_MCUTEMP_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseMCUTemp(data);
      }
      break;

    case CMD_L8_STORE_L8Y_RESPONSE:

    case CMD_L8_READ_L8Y_RESPONSE:

    case CMD_L8_STORE_FRAME_RESPONSE:

    case CMD_L8_READ_FRAME_RESPONSE:

    case CMD_L8_BATCHG_RESPONSE:
      if (dataLength != CMD_L8_BATCHG_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseBatCharge(data);
      }
      break;

    case CMD_L8_STORE_ANIM_RESPONSE:

    case CMD_L8_READ_ANIM_RESPONSE:

    case CMD_L8_ORIENTATION_RESPONSE:
      if (dataLength != CMD_L8_ORIENTATION_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseOrientation(data);
      }
      break;

    case CMD_L8_NUML8IES_RESPONSE:

    case CMD_L8_NUMANIMS_RESPONSE:

    case CMD_L8_NUMFRAMES_RESPONSE:

    case CMD_L8_NOTIFAPP_RESPONSE:

    case CMD_L8_NOTIFAPPS_NUM_RESPONSE:

    case CMD_L8_FRAMEGRAB_RESPONSE:

    case CMD_L8_SENSORS_THRESHOLDS_RESPONSE:
      if (dataLength != CMD_L8_SENSORS_THRESHOLDS_RESPONSE_LENGTH) {
        *ret = 1;
      } else {
        ret = responseSensorThresholds(data);
      }
      break;    

    case CMD_L8_NOTIFAPPS_SILENCE_RESPONSE:

      break;

    case CMD_ERR:
      if (dataLength != CMD_ACK_LENGTH) {
        *ret = 1;
      } else {
        ret = handleCMDERR(data);
      }
      break;

    case CMD_OK:
      if (dataLength != CMD_ACK_LENGTH) {
        *ret = 1;
      } else {
        ret = handleCMDOK(data);
      }
      break;

    case CMD_PONG:
      if (dataLength != 0) {
        *ret = 1;
      } else {
        ret = handleCMDPONG();
      }
      break;

    default:
      break;
  }

  return ret;
}
