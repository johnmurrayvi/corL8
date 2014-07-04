
#ifndef _CORL8_SLCP_DEFS_H_
#define _CORL8_SLCP_DEFS_H_

/*
 * slcp_defs.h
 */


/*
 * SLCP Frame:
 *
 * ------------------------------------------------------
 * |  0xAA  |  0x55  |  Length |    Payload    |  CRC8  |
 * ------------------------------------------------------
 * \________________/     |            |           |
 *          |             |            |           |
 *     SLCP Header     1 Byte    1 - 255 Bytes  1 Byte
 */


#define SLCP_HEADER                               0xAA55
#define SLCP_HEADER_BEGIN                         0xAA
#define SLCP_HEADER_END                           0x55

#define LENGTH_SLCP_HEADER                        2
#define LENGTH_SLCP_LENGTH                        1
#define LENGTH_SLCP_CHKSUM                        1


#define CMD_ERR                                   0xFF
#define CMD_OK                                    0x00
#define CMD_PING                                  0x01
#define CMD_PONG                                  0x02
#define CMD_ACK_LENGTH                            1


#define CMD_L8_LED_SET                            0x43
#define CMD_L8_MATRIX_SET                         0x44
#define CMD_L8_MATRIX_OFF                         0x45

#define CMD_L8_VOLTAGE_QUERY                      0x46
#define CMD_L8_VOLTAGE_RESPONSE                   0x47
#define CMD_L8_VOLTAGE_RESPONSE_LENGTH            3

#define CMD_L8_TEMP_QUERY                         0x48
#define CMD_L8_TEMP_RESPONSE                      0x49
#define CMD_L8_TEMP_RESPONSE_LENGTH               2

#define CMD_L8_BOOTLOADER                         0x4A
#define CMD_L8_SUPERLED_SET                       0x4B

#define CMD_L8_ACC_QUERY                          0x4C
#define CMD_L8_ACC_RESPONSE                       0x4D
#define CMD_L8_ACC_RESPONSE_LENGTH                7

#define CMD_L8_UID_QUERY                          0x4E
#define CMD_L8_UID_RESPONSE                       0x4F
#define CMD_L8_UID_RESPONSE_LENGTH                12

#define CMD_L8_AMBIENT_QUERY                      0x50
#define CMD_L8_AMBIENT_RESPONSE                   0x51
#define CMD_L8_AMBIENT_RESPONSE_LENGTH            4

#define CMD_L8_PROX_QUERY                         0x52
#define CMD_L8_PROX_RESPONSE                      0x53
#define CMD_L8_PROX_RESPONSE_LENGTH               4

#define CMD_L8_VERSIONS_QUERY                     0x60
#define CMD_L8_VERSIONS_RESPONSE                  0x61
#define CMD_L8_VERSIONS_RESPONSE_LENGTH           12

#define CMD_L8_BUTTON_QUERY                       0x62
#define CMD_L8_BUTTON_RESPONSE                    0x63
#define CMD_L8_BUTTON_RESPONSE_LENGTH             1

#define CMD_L8_MIC_QUERY                          0x64
#define CMD_L8_MIC_RESPONSE                       0x65
#define CMD_L8_MIC_RESPONSE_LENGTH                2

#define CMD_L8_VBUS_QUERY                         0x66
#define CMD_L8_VBUS_RESPONSE                      0x67
#define CMD_L8_VBUS_RESPONSE_LENGTH               2

#define CMD_L8_MCUTEMP_QUERY                      0x68
#define CMD_L8_MCUTEMP_RESPONSE                   0x69
#define CMD_L8_MCUTEMP_RESPONSE_LENGTH            2

#define CMD_L8_STORE_L8Y                          0x6A
#define CMD_L8_STORE_L8Y_RESPONSE                 0x6B
#define CMD_L8_STORE_L8Y_RESPONSE_LENGTH          1

#define CMD_L8_READ_L8Y                           0x6C
#define CMD_L8_READ_L8Y_RESPONSE                  0x6D
#define CMD_L8_READ_L8Y_RESPONSE_LENGTH           128

#define CMD_L8_SET_STORED_L8Y                     0x6E
#define CMD_L8_DELETE_L8Y                         0x6F

#define CMD_L8_STORE_FRAME                        0x70
#define CMD_L8_STORE_FRAME_RESPONSE               0x71
#define CMD_L8_STORE_FRAME_RESPONSE_LENGTH        1

#define CMD_L8_READ_FRAME                         0x72
#define CMD_L8_READ_FRAME_RESPONSE                0x73
#define CMD_L8_READ_FRAME_RESPONSE_LENGTH         128

#define CMD_L8_DELETE_FRAME                       0x74

#define CMD_L8_BATCHG_QUERY                       0x75
#define CMD_L8_BATCHG_RESPONSE                    0x76
#define CMD_L8_BATCHG_RESPONSE_LENGTH             1
/* BATCHG STATUS */
#define CMD_L8_BATCHG_STATUS_STANDBY              0x06
#define CMD_L8_BATCHG_STATUS_CHARGING             0x0A
#define CMD_L8_BATCHG_STATUS_CHRGCOMP             0x0C
#define CMD_L8_BATCHG_STATUS_FAULT                0x0E

#define CMD_L8_STORE_ANIM                         0x77
#define CMD_L8_STORE_ANIM_RESPONSE                0x78
#define CMD_L8_STORE_ANIM_RESPONSE_LENGTH         1

#define CMD_L8_READ_ANIM                          0x79
#define CMD_L8_READ_ANIM_RESPONSE                 0x7A
// #define CMD_L8_READ_ANIM_RESPONSE_LENGTH       VARIABLE, READ FIRST BYTE

#define CMD_L8_DELETE_ANIM                        0x7B
#define CMD_L8_PLAY_ANIM                          0x7C
#define CMD_L8_STOP_ANIM                          0x7D
#define CMD_L8_DELETE_USER_MEMORY                 0x7E
#define CMD_L8_DISP_CHAR                          0x7F

#define CMD_L8_SET_ORIENTATION                    0x80
#define CMD_L8_APP_RUN                            0x81
#define CMD_L8_APP_STOP                           0x82
#define CMD_L8_SET_TEXT                           0x83
#define CMD_L8_TRACE_MSG                          0x84
#define CMD_L8_TRACE_MSG_LENGTH                   2

#define CMD_L8_INIT_STATUS_QUERY                  0x85
#define CMD_L8_SET_AUTOROTATE                     0x86

#define CMD_L8_ORIENTATION_QUERY                  0x8A
#define CMD_L8_ORIENTATION_RESPONSE               0x8B
#define CMD_L8_ORIENTATION_RESPONSE_LENGTH        1
/* Orientation Values */
#define CMD_L8_ORIENTATION_STATUS_UP              1
#define CMD_L8_ORIENTATION_STATUS_DOWN            2
#define CMD_L8_ORIENTATION_STATUS_RIGHT           5
#define CMD_L8_ORIENTATION_STATUS_LEFT            6


#define CMD_L8_NUML8IES_QUERY                     0x8C
#define CMD_L8_NUML8IES_RESPONSE                  0x8D
#define CMD_L8_NUML8IES_RESPONSE_LENGTH           1

#define CMD_L8_NUMANIMS_QUERY                     0x8E
#define CMD_L8_NUMANIMS_RESPONSE                  0x8F
#define CMD_L8_NUMANIMS_RESPONSE_LENGTH           1

#define CMD_L8_NUMFRAMES_QUERY                    0x90
#define CMD_L8_NUMFRAMES_RESPONSE                 0x91
#define CMD_L8_NUMFRAMES_RESPONSE_LENGTH          1

#define CMD_L8_NOTIFAPP_STORE                     0x92
#define CMD_L8_NOTIFAPP_QUERY                     0x93
#define CMD_L8_NOTIFAPP_RESPONSE                  0x94
// ERROR in SLCP v1: Response is from L8 to host
// #define CMD_L8_NOTIFAPP_RESPONSE_LENGTH  VARIABLE

#define CMD_L8_NOTIFAPPS_NUM_QUERY                0x95
#define CMD_L8_NOTIFAPPS_NUM_RESPONSE             0x96
#define CMD_L8_NOTIFAPPS_NUM_RESPONSE_LENGTH      1

#define CMD_L8_NOTIFAPP_ENABLE                    0x97
#define CMD_L8_NOTIFAPP_DELETE                    0x98
#define CMD_L8_SET_NOTIFICATION                   0x99
#define CMD_L8_SET_LOW_BRIGHTNESS                 0x9A

#define CMD_L8_FRAMEGRAB_QUERY                    0x9B
#define CMD_L8_FRAMEGRAB_RESPONSE                 0x9C
#define CMD_L8_FRAMEGRAB_RESPONSE_LENGTH          128

#define CMD_L8_POWEROFF                           0x9D
#define CMD_L8_STATUSLEDS_ENABLE                  0x9E
#define CMD_L8_NOISE_THRESHOLDS_SET               0x9F

#define CMD_L8_PROX_THRESHOLDS_SET                0xA0
#define CMD_L8_AMB_THRESHOLDS_SET                 0xA1

#define CMD_L8_SENSORS_THRESHOLDS_QUERY           0xA2
#define CMD_L8_SENSORS_THRESHOLDS_RESPONSE        0xA3
#define CMD_L8_SENSORS_THRESHOLDS_RESPONSE_LENGTH 12

#define CMD_L8_NOTIFAPPS_ENABLE_ALL               0xA4
#define CMD_L8_NOTIFAPPS_SILENCE                  0xA5

#define CMD_L8_NOTIFAPPS_SILENCE_QUERY            0xA6
#define CMD_L8_NOTIFAPPS_SILENCE_RESPONSE         0xA7
#define CMD_L8_NOTIFAPPS_SILENCE_RESPONSE_LENGTH  1


/* TRACE DEBUGGING */
#define L8_DBG_GLOBAL_ERROR                       0xFF
#define L8_DBG_FLASH_WRITE_ERROR                  0x01
#define L8_DBG_FLASH_READ_ERROR                   0x02
#define L8_DBG_TEMP_SENSOR_ERROR                  0x03
#define L8_DBG_MCU_TEMP_SENSOR_ERROR              0x04
#define L8_DBG_BATTERY_ERROR                      0x05
#define L8_DBG_CHARGING_ERROR                     0x06
#define L8_DBG_BT_INIT_ERROR                      0x07
#define L8_DBG_ACC_SENSOR_ERROR                   0x08
#define L8_DBG_AMB_SENSOR_ERROR                   0x09
#define L8_DBG_NOISE_SENSOR_ERROR                 0x0A
#define L8_DBG_UUID_READ_ERROR                    0x0B



#endif // _CORL8_SLCP_DEFS_H_
