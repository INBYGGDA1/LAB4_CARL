/**
 * ----------------------------------------------------------------------------
 * main.c
 * Author: Carl Larsson
 * Description: main file for demonstrating UART driver routines
 * Date: 2023-09-15
 * ----------------------------------------------------------------------------
 */

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "inc/UART_driver.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//=============================================================================
// The error routine that is called if the driver library
// encounters an error.
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
    while(1);
}
#endif
//=============================================================================
// Main Function
int main(void)
{
    char buffer[BUFF_LEN];
    // Reset UART, necessary before initializing it
    //UART_reset();
    // Initialize UART
    UART_init(UART_base_0);

    while(1)
    {
        UART_putString("Input: \n\r");
        UART_getString(buffer);
        UART_putString("Echo: \n\r");
        UART_putString(buffer);
        if((buffer[0] == 'e') && (buffer[1] == 'n') && (buffer[2] == 'd'))
        {
            //UART_reset();
            break;
        }
        UART_putString("\n\r");
    }
}
//=============================================================================
