/*
 * uart_app.c
 *
 *  Created on: 29 Jul 2021
 *      Author: Markel-Admin
 */


/******************************************************************************
 Includes
 *****************************************************************************/
#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/UART.h>

/* Driver configuration */
#include "ti_drivers_config.h"
/******************************************************************************
 Global variables
 *****************************************************************************/

/******************************************************************************
 Local variables
 *****************************************************************************/
UART_Handle uartHandle = NULL;
UART_Params uartParams;
/******************************************************************************
 Local function prototypes
 *****************************************************************************/

/*!
 Inititalize the UART

 -
 */
void UartApp_Init(void)
{

  /* Call driver init functions */
  UART_init();

  /* Create a UART with data processing off. */
  UART_Params_init(&uartParams);
  uartParams.writeDataMode = UART_DATA_BINARY;
  uartParams.readDataMode = UART_DATA_BINARY;
  uartParams.readReturnMode = UART_RETURN_FULL;
  uartParams.baudRate = 115200;

  uartHandle = UART_open(CONFIG_DISPLAY_UART, &uartParams);

  if (uartHandle == NULL) {
      /* UART_open() failed */
      while (1);
  }
}


/*!
 Write to UART

 -
 */
void UartApp_Write(uint8_t *data, uint8_t len)
{
    UART_write(uartHandle, data, len);
}
