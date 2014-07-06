
#ifndef _CORL8_SLCP_SENSOR_CMDS_H_
#define _CORL8_SLCP_SENSOR_CMDS_H_

/* 
 * slcp_sensor_cmds.h
 */

#include "corl8_defs.h"
#include "slcp_defs.h"


/*
 * #define CMD_L8_VOLTAGE_QUERY                0x46
 * #define CMD_L8_VOLTAGE_RESPONSE             0x47
 */

/*!
 * \fn queryVoltage()
 */
extern void queryVoltage();

/*!
 * \fn uchar* responseVoltage(uchar *data)
 */
extern uchar* responseVoltage(uchar *data);


/*
 * #define CMD_L8_TEMP_QUERY                   0x48
 * #define CMD_L8_TEMP_RESPONSE                0x49
 */

/*!
 * \fn queryTemp()
 */
extern void queryTemp();

/*!
 * \fn uchar* responseTemp(uchar *data)
 */
extern uchar* responseTemp(uchar *data);


/*
 * #define CMD_L8_ACC_QUERY                    0x4C
 * #define CMD_L8_ACC_RESPONSE                 0x4D
 */

/*!
 * \fn queryAccel()
 */
extern void queryAccel();

/*!
 * \fn uchar* responseAccel(uchar *data)
 */
extern uchar* responseAccel(uchar *data);


/*
 * #define CMD_L8_UID_QUERY                    0x4E
 * #define CMD_L8_UID_RESPONSE                 0x4F
 */

/*!
 * \fn queryUID()
 */
extern void queryUID();

/*!
 * \fn uchar* responseUID(uchar *data)
 */
extern uchar* responseUID(uchar *data);


/*
 * #define CMD_L8_AMBIENT_QUERY                0x50
 * #define CMD_L8_AMBIENT_RESPONSE             0x51
 */

/*!
 * \fn queryAmbient()
 */
extern void queryAmbient();

/*!
 * \fn uchar* responseAmbient(uchar *data)
 */
extern uchar* responseAmbient(uchar *data);


/*
 * #define CMD_L8_PROX_QUERY                   0x52
 * #define CMD_L8_PROX_RESPONSE                0x53
 */

/*!
 * \fn queryProximity()
 */
extern void queryProximity();

/*!
 * \fn uchar* responseProximity(uchar *data)
 */
extern uchar* responseProximity(uchar *data);


/*
 * #define CMD_L8_VERSIONS_QUERY               0x60
 * #define CMD_L8_VERSIONS_RESPONSE            0x61
 */

/*!
 * \fn queryVersions()
 */
extern void queryVersions();

/*!
 * \fn uchar* responseVersions(uchar *data)
 */
extern uchar* responseVersions(uchar *data);


/*
 * #define CMD_L8_BUTTON_QUERY                 0x62
 * #define CMD_L8_BUTTON_RESPONSE              0x63
 */

/*!
 * \fn queryButton()
 */
extern void queryButton();

/*!
 * \fn uchar* responseButton(uchar *data)
 */
extern uchar* responseButton(uchar *data);


/*
 * #define CMD_L8_MIC_QUERY                    0x64
 * #define CMD_L8_MIC_RESPONSE                 0x65
 */

/*!
 * \fn queryMic()
 */
extern void queryMic();

/*!
 * \fn uchar* responseMic(uchar *data)
 */
extern uchar* responseMic(uchar *data);


/*
 * #define CMD_L8_VBUS_QUERY                   0x66
 * #define CMD_L8_VBUS_RESPONSE                0x67
 */

/*!
 * \fn queryVBUS()
 */
extern void queryVBUS();

/*!
 * \fn uchar* responseVBUS(uchar *data)
 */
extern uchar* responseVBUS(uchar *data);


/*
 * #define CMD_L8_MCUTEMP_QUERY                0x68
 * #define CMD_L8_MCUTEMP_RESPONSE             0x69
 */

/*!
 * \fn queryMCUTemp()
 */
extern void queryMCUTemp();

/*!
 * \fn uchar* responseMCUTemp(uchar *data)
 */
extern uchar* responseMCUTemp(uchar *data);


/*
 * #define CMD_L8_BATCHG_QUERY                 0x75
 * #define CMD_L8_BATCHG_RESPONSE              0x76
 */

/*!
 * \fn queryBatCharge()
 */
extern void queryBatCharge();

/*!
 * \fn uchar* responseBatCharge(uchar *data)
 */
extern uchar* responseBatCharge(uchar *data);


/*
 * #define CMD_L8_ORIENTATION_QUERY            0x8A
 * #define CMD_L8_ORIENTATION_RESPONSE         0x8B
 */

/*!
 * \fn queryOrientation()
 */
extern void queryOrientation();

/*!
 * \fn uchar* responseOrientation(uchar *data)
 */
extern uchar* responseOrientation(uchar *data);


/*
 * #define CMD_L8_NOISE_THRESHOLDS_SET         0x9F
 * #define CMD_L8_PROX_THRESHOLDS_SET          0xA0
 * #define CMD_L8_AMB_THRESHOLDS_SET           0xA1
 */

/*!
 * \fn setNoiseThresholds(uint16_t min, uint16_t max);
 */
extern uchar* setNoiseThresholds(uint16_t min, uint16_t max);

/*!
 * \fn setProximityThresholds(uint16_t min, uint16_t max);
 */
extern uchar* setProximityThresholds(uint16_t min, uint16_t max);

/*!
 * \fn setAmbienThresholds(uint16_t min, uint16_t max);
 */
extern uchar* setAmbientThresholds(uint16_t min, uint16_t max);


/*
 * #define CMD_L8_SENSORS_THRESHOLDS_QUERY     0xA2
 * #define CMD_L8_SENSORS_THRESHOLDS_RESPONSE  0xA3
 */

/*!
 * \fn querySensorThresholds()
 */
extern void querySensorThresholds();

/*!
 * \fn uchar* responseSensorThresholds(uchar *data)
 */
extern uchar* responseSensorThresholds(uchar *data);



#endif // _CORL8_SLCP_SENSOR_CMDS_H_
