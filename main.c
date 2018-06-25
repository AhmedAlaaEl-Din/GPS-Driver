#include <stdint.h>
#include "M4MemMap.h"
#include "GPIO.h"
#include "GPIO_Cfg.h"
#include "UART.h"
#include "UART_Cfg.h"
#include "GPS.h"
/**
 * main.c
 */

#define Number_of_Bytes     500
uint8_t UART_Tx_IntBuff[5]="Hello";
//extern uint8_t Frame[Number_of_Bytes];
uint8_t XXX,Y1,Y2 = 0;
//uint8_t x = 0;
//uint8_t Data[500];
uint8_t Longitude[10];
uint8_t Latitude[11];
uint8_t Hours[2];
uint8_t Minutes[2];
uint8_t Seconds[2];
uint8_t Day[2];
uint8_t Month[2];
uint8_t Year[2];
int main(void)
{

    GPIO_Init();
    UART_Init();
    GPS_Init();
    GPS_Request();
    //UART_Tx_Init(Seconds, 2 , 0);
    while(1)
    {
        UART_Rx(1);
        GPS_GetCoordinates(Longitude,Latitude);
        GPS_GetTime(Hours,Minutes,Seconds);
        GPS_GetDate(Day,Month,Year);
        //UART_Tx(0);
    }
    return 0;
}
