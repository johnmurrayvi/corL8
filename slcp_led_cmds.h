
#ifndef _CORL8_SLCP_LED_CMDS_H_
#define _CORL8_SLCP_LED_CMDS_H_

/* 
 * slcp_led_cmds.h
 */

#include "corl8_defs.h"
#include "slcp_defs.h"


// CMD_L8_LED_SET 0x43
extern uchar* setLED(uchar x, uchar y, uchar red, uchar green, uchar blue);

// CMD_L8_SUPERLED_SET 0x4B
extern uchar* setSuperLED(uchar red, uchar green, uchar blue);


// CMD_L8_MATRIX_SET 0x44
extern void matrixSetSolid(uchar red, uchar green, uchar blue);
// extern void matrixSet(uchar *matrix);

// CMD_L8_MATRIX_OFF 0x45
extern void matrixOff();


// CMD_L8_STATUSLEDS_ENABLE 0x9E
extern uchar* setStatusLEDs(uchar enable);


#endif // _CORL8_SLCP_LED_CMDS_H_
