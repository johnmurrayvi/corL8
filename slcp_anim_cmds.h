
#ifndef _CORL8_SLCP_ANIM_CMDS_H_
#define _CORL8_SLCP_ANIM_CMDS_H_

/* 
 * slcp_anim_cmds.h
 */

#include "corl8_defs.h"
#include "slcp_defs.h"


// CMD_L8_DISP_CHAR 0x7F
// XXX: SLCP Description is wrong
extern uchar* displayChar(char c);
// XXX: Shift Amount should be 0-7, not 0-8 (for 4 bits)
extern uchar* displayCharShift(char c, uchar shiftDir, uchar shiftAmt);


// CMD_L8_SET_TEXT 0x83
// WTF, does this really take RGB and not BGR?


// CMD_L8_STORE_L8Y
// CMD_L8_STORE_L8Y_RESPONSE
// CMD_L8_READ_L8Y
// CMD_L8_READ_L8Y_RESPONSE

// CMD_L8_SET_STORED_L8Y
// CMD_L8_DELETE_L8Y


// CMD_L8_STORE_FRAME
// CMD_L8_STORE_FRAME_RESPONSE
// CMD_L8_READ_FRAME
// CMD_L8_READ_FRAME_RESPONSE

// CMD_L8_DELETE_FRAME

// CMD_L8_STORE_ANIM
// CMD_L8_STORE_ANIM_RESPONSE
// CMD_L8_DELETE_ANIM
// CMD_L8_PLAY_ANIM
// CMD_L8_STOP_ANIM

#endif // _CORL8_SLCP_ANIM_CMDS_H_
