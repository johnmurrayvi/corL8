
#ifndef _CORL8_SLCP_ACK_CMDS_H_
#define _CORL8_SLCP_ACK_CMDS_H_

/* 
 * slcp_ack_cmds.h
 */

#include "corl8_defs.h"
#include "slcp_defs.h"


extern uchar* sendCMDPING();

extern uchar* handleCMDPONG();

extern uchar* handleCMDERR(uchar *data);

extern uchar* handleCMDOK(uchar *data);


#endif // _CORL8_SLCP_ACK_CMDS_H_
