/**
 * CAN BUS
 *
 * Copyright (c) 2010 Sukkin Pang All rights reserved.
 */

#ifndef canbus__h
#define canbus__h

#define CANSPEED_125 	7		// CAN speed at 125 kbps
#define CANSPEED_250  	3		// CAN speed at 250 kbps
#define CANSPEED_500	1		// CAN speed at 500 kbps


#define CALC_ENGINE_LOAD        0x04
#define ENGINE_COOLANT_TEMP     0x05
#define ENGINE_RPM              0x0C
#define VEHICLE_SPEED           0x0D
#define MAF_SENSOR              0x10
#define THROTTLE                0x11
#define RELATIVE_THROTTLE       0x45
#define O2_S1_WR_LAMBDA         0x34

#define PID_SUPPORT_01_20 0x00
#define PID_SUPPORT_21_40 0x20
#define PID_SUPPORT_41_60 0x40
#define PID_SUPPORT_61_80 0x60
#define PID_SUPPORT_81_A0 0x80
#define PID_SUPPORT_A1_C0 0xA0
#define PID_SUPPORT_C1_E0 0xC0

#define PID_REQUEST         0x7DF
#define PID_REPLY			0x7E8

static void byte2hex(unsigned char b, char* buf) {
    char lut[] = "0123456789ABCDEF";
    buf[0] = lut[b >> 4];
    buf[1] = lut[b & 0xF];
    return;
}

typedef struct _tOBD2
{
    unsigned char pid;
    unsigned char A;
    unsigned char B;
    unsigned char C;
    unsigned char D;
} tOBD2;

class CanbusClass
{
  public:

	CanbusClass();
    char init(unsigned char);
	char message_tx(void);
	char message_rx(unsigned char *buffer);
	char ecu_req(unsigned char pid,  char *buffer);
    char obd2_data(unsigned char pid, tOBD2 *data);
    char obd2_lowlevel(unsigned char mode, unsigned char* inbytes,
                       unsigned char inlen, tOBD2 *data);
private:
	
};
extern CanbusClass Canbus;
//extern tCAN message;

#endif
