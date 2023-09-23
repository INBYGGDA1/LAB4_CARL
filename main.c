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
    char character_to_send = 'c';
    char character_sent;
    char buffer[100];

    // Reset UART, necessary before initializing it
    UART_reset();
    // Initialize UART
    UART_init(UART_base_0);

    while(1)
    {
        UART_putChar(character_to_send);
        character_sent = UART_getChar();

        UART_putString("hello\r\n");
        UART_getString(buffer);
    }
}
//=============================================================================
