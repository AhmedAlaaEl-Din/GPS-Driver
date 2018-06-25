#include "UART.h"
#include "Callback.h"


void TxDone_Func (void)
{
  Y1++;
  //UART_Rx_Init(UART_Rx_IntBuff,2,2);
  UART_Tx_Init(Seconds, 2 , 0);
}

void RxDone_Func (void)
{
  Y2++;
  //GPS_Get_Data();
  //UART_Rx_Init(Frame,500,1);
}
