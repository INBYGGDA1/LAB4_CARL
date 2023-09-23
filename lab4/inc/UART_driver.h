/**
 * ----------------------------------------------------------------------------
 * UART_driver.h
 * Author: Carl Larsson
 * Description: UART driver routines h file
 * Date: 2023-09-17
 * ----------------------------------------------------------------------------
 */

#ifndef UART_DRIVER_H
#define UART_DRIVER_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Includes
#include <stdint.h>

#include "register_defines.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define BUFF_LEN 128

//=============================================================================
// This Function initializes the UART driver, here we set up the hardware module.
extern void UART_init(uint32_t ui32Base);
// This Function is used to receive one character.
extern char UART_getChar();
// This function is used to transmit one character.
extern void UART_putChar(char c);
// This function resets the driver to a save state (reset all registers that could lead to unpredictable behavior). Initialization after r
extern void UART_reset();
// This function uses the putChar function to write a string.
extern void UART_putString(char *string);
// This function uses the getChar function to read a string.
extern void UART_getString(char *buffer);
//=============================================================================

#endif // UART_DRIVER_H
