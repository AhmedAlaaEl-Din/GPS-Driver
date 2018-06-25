#include <stdint.h>

#ifndef GPS_H_
#define GPS_H_

typedef enum {GPS_OK =0, GPS_NOK} GPS_CheckType;
typedef enum {GPS_Idle =0, GPS_Ready, GPS_Wait, GPS_Error} GPS_State;
typedef void(*GPS_PtrToCallbackType)(void);

typedef struct
{
    uint8_t UART_ChannelID;
    GPS_PtrToCallbackType CallBack;
}GPS_CfgParameters;


extern const GPS_CfgParameters GPS_Parameters;

/* The following two variables Request and State are used to say if the user requested data of not
and to say if GPS is ready to send data or not */
uint8_t Request;
GPS_State State;
//
uint8_t LED;

/* Functions declaration */
void GPS_Init(void);
void GPS_Request(void);
void GPS_GetCoordinates(uint8_t* Longitude, uint8_t* Latitude);
void GPS_GetTime(uint8_t* Hours, uint8_t* Minutes, uint8_t* Seconds);
void GPS_GetDate(uint8_t* Day, uint8_t* Month, uint8_t* Year);
void GPS_FrameRcvd(void);
//
void LED_ON(void);

#endif /* GPS_H_ */
