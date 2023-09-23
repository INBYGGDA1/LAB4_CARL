/**
 * ----------------------------------------------------------------------------
 * UART_driver.c
 * Author: Carl Larsson
 * Description: UART driver routines c file. The UART driver operates
 * at 9600 baud, package length of 8 bits, no parity bit, one stop bit and
 * operates in normal channel mode.
 * Date: 2023-09-17
 * ----------------------------------------------------------------------------
 */

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Includes
#include <stdint.h>

#include "../inc/UART_driver.h"
#include "../inc/register_defines.h"

#include "inc/tm4c129encpdt.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Global variables
uint32_t g_UART_base_used;
uint32_t g_uart_init = 0;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//=============================================================================
// This Function initializes the UART driver, here we set up the hardware module.
// Baud rate is fixed at 9600 baud, according to lab specification.
// Word length is set to 8 bits, according to lab specification.
void UART_init(uint32_t ui32Base)
{
    //-----------------------------------------------------------------------------
    volatile uint32_t UART_module_bit = 0;
    volatile uint32_t UART_port_bit = 0;
    volatile uint32_t UART_pin_bits = 0;
    volatile uint32_t UART_pin = 0;
    volatile uint32_t temp_port_base;

    volatile uint32_t *RCGCUART_pointer = (volatile uint32_t*)RCGCUART;
    volatile uint32_t *RCGCGPIO_pointer = (volatile uint32_t*)RCGCGPIO;

    volatile uint32_t *GPIOAFSEL_pointer;
    volatile uint32_t *GPIODR2R_pointer;
    volatile uint32_t *GPIOSLR_pointer;
    volatile uint32_t *GPIOPCTL_pointer;
    volatile uint32_t *GPIODEN_pointer;

    volatile uint32_t *UARTCTL_pointer = (volatile uint32_t*)(ui32Base + UARTCTL);
    volatile uint32_t *UARTIBRD_pointer = (volatile uint32_t*)(ui32Base + UARTIBRD);
    volatile uint32_t *UARTFBRD_pointer = (volatile uint32_t*)(ui32Base + UARTFBRD);
    volatile uint32_t *UARTLCRH_pointer = (volatile uint32_t*)(ui32Base + UARTLCRH);
    volatile uint32_t *UARTCC_pointer = (volatile uint32_t*)(ui32Base + UARTCC);
    //-----------------------------------------------------------------------------

    //-----------------------------------------------------------------------------
    // Setting the Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control to the correct UART module
    // And
    // Which port to enable for different UARTs
    switch(ui32Base)
    {
        // UART base 0
        case UART_base_0 :
            // UART module 0
            UART_module_bit = 0;
            // UART port A (Receive (Rx) and transmit (Tx))
            UART_port_bit = 0;
            // Set which GPIO Port base is to be used
            temp_port_base = GPIO_Port_A_base;
            // UART Receive (Rx) and transmit (Tx) for UART module 0 is on pin 0 and 1 (set bits 4 and 0)
            UART_pin_bits = ((1 << 0) | (1 << 4));
            UART_pin = ((1 << 0) | (1 << 1));
            break;
        // UART base 1
        case UART_base_1 :
            // UART module 1
            UART_module_bit = 1;
            // UART port B (Receive (Rx) and transmit (Tx))
            UART_port_bit = 1;
            // Set which GPIO Port base is to be used
            temp_port_base = GPIO_Port_B_base;
            // UART Receive (Rx) and transmit (Tx) for UART module 1 is on pin 0 and 1 (set bits 4 and 0)
            UART_pin_bits = ((1 << 0) | (1 << 4));
            UART_pin = ((1 << 0) | (1 << 1));
            break;
        // UART base 2
        case UART_base_2 :
            // UART module 2
            UART_module_bit = 2;
            // UART port A (Receive (Rx) and transmit (Tx))
            UART_port_bit = 0;
            // Set which GPIO Port base is to be used
            temp_port_base = GPIO_Port_A_base;
            // UART Receive (Rx) and transmit (Tx) for UART module 0 is on pin 6 and 7 (set bits 28 and 24)
            UART_pin_bits = ((1 << 24) | (1 << 28));
            UART_pin = ((1 << 6) | (1 << 7));
            break;
        // UART base 3
        case UART_base_3 :
            // UART module 3
            UART_module_bit = 3;
            // UART port A (Receive (Rx) and transmit (Tx))
            UART_port_bit = 0;
            // Set which GPIO Port base is to be used
            temp_port_base = GPIO_Port_A_base;
            // UART Receive (Rx) and transmit (Tx) for UART module 0 is on pin 4 and 5 (set bits 20 and 16)
            UART_pin_bits = ((1 << 16) | (1 << 20));
            UART_pin = ((1 << 4) | (1 << 5));
            break;
        // UART base 4
        case UART_base_4 :
            // UART module 4
            UART_module_bit = 4;
            // UART port A (Receive (Rx) and transmit (Tx))
            UART_port_bit = 0;
            // Set which GPIO Port base is to be used
            temp_port_base = GPIO_Port_A_base;
            // UART Receive (Rx) and transmit (Tx) for UART module 0 is on pin 2 and 3 (set bits 12 and 8)
            UART_pin_bits = ((1 << 8) | (1 << 12));
            UART_pin = ((1 << 2) | (1 << 3));
            break;
        // UART base 5
        case UART_base_5 :
            // UART module 5
            UART_module_bit = 5;
            // UART port C (Receive (Rx) and transmit (Tx))
            UART_port_bit = 2;
            // Set which GPIO Port base is to be used
            temp_port_base = GPIO_Port_C_base;
            // UART Receive (Rx) and transmit (Tx) for UART module 0 is on pin 6 and 7 (set bits 28 and 24)
            UART_pin_bits = ((1 << 24) | (1 << 28));
            UART_pin = ((1 << 6) | (1 << 7));
            break;
        // UART base 6
        case UART_base_6 :
            // UART module 6
            UART_module_bit = 6;
            // UART port P (Receive (Rx) and transmit (Tx))
            UART_port_bit = 13;
            // Set which GPIO Port base is to be used
            temp_port_base = GPIO_Port_P_base;
            // UART Receive (Rx) and transmit (Tx) for UART module 0 is on pin 0 and 1 (set bits 4 and 0)
            UART_pin_bits = ((1 << 0) | (1 << 4));
            UART_pin = ((1 << 0) | (1 << 1));
            break;
        // UART base 7
        case UART_base_7 :
            // UART module 7
            UART_module_bit = 7;
            // UART port C (Receive (Rx) and transmit (Tx))
            UART_port_bit = 2;
            // Set which GPIO Port base is to be used
            temp_port_base = GPIO_Port_C_base;
            // UART Receive (Rx) and transmit (Tx) for UART module 0 is on pin 4 and 5 (set bits 20 and 16)
            UART_pin_bits = ((1 << 16) | (1 << 20));
            UART_pin = ((1 << 4) | (1 << 5));
            break;
        // Default is assuming UART base 0
        default :
            // UART module 0
            UART_module_bit = 0;
            // UART port A (Receive (Rx) and transmit (Tx))
            UART_port_bit = 0;
            // Set which GPIO Port base is to be used
            temp_port_base = GPIO_Port_A_base;
            // UART Receive (Rx) and transmit (Tx) for UART module 0 is on pin 0 and 1 (set bit 0 and 4)
            UART_pin_bits = ((1 << 0) | (1 << 4));
            UART_pin = ((1 << 0) | (1 << 1));
            break;
    }

    // Set various register pointers to the correct address given the UART module and port
    GPIOAFSEL_pointer = (volatile uint32_t*) (temp_port_base + GPIOAFSEL);
    GPIODR2R_pointer = (volatile uint32_t*) (temp_port_base + GPIODR2R);
    GPIOSLR_pointer = (volatile uint32_t*) (temp_port_base + GPIOSLR);
    GPIOPCTL_pointer = (volatile uint32_t*) (temp_port_base + GPIOPCTL);
    GPIODEN_pointer = (volatile uint32_t*) (temp_port_base + GPIODEN);
    //-----------------------------------------------------------------------------

    //-----------------------------------------------------------------------------
    // Setting the UART_module_bit bit to 1 and thus enabling and providing a clock to UART module UART_module_bit in Run mode.
    *RCGCUART_pointer |= (1 << UART_module_bit);
    // Enable port
    *RCGCGPIO_pointer |= (1 << UART_port_bit);

    // Clear UARTEN bit (bit 0). Disabling UART for configuration
    *UARTCTL_pointer &= ~(1 << 0);

    // The transmit section of the UART is enabled (bit 8). The receive section of the UART is enabled (bit 9)
    *UARTCTL_pointer |= ((1 << 8) | (1 << 9));

    // Mode control select register
    *GPIOAFSEL_pointer = UART_pin;
    // Enable the digital functions for the corresponding port. (According to lab instruction hints)
    *GPIODEN_pointer = UART_pin;
    // Assign the UART signals to the appropriate pins
    *GPIOPCTL_pointer |= UART_pin_bits;

    // Set the integer part to 9600 baud rate
    // Default system clock runs at 16Mhz, page 1966
    // BRD = 16,000,000 / (16 * 9,600) = 104.166667
    *UARTIBRD_pointer = 104;
    // Set the fractional part (104.166667 - 104 = 0.166667) to 9600 baud rate
    // UARTFBRD[DIVFRAC] = integer(0.166667 * 64 + 0.5) = 11
    *UARTFBRD_pointer = 11;

    // Disable FIFO
    *UARTLCRH_pointer &= ~(1 << 4);
    // One stop bit (clearing bit 3)
    *UARTLCRH_pointer &= ~(1 << 3);
    // No parity (clearing bit 1)
    *UARTLCRH_pointer &= ~(1 << 1);
    // Set word length to 8 (by setting bits 5 and 6 to 1) (also necessary to write to this register for the baud rate changes to take effect)
    *UARTLCRH_pointer |= ((1 << 5) | (1 << 6));

    // Configure the UART clock source, clear the first 4 bits (3 to 0) to set it to normal system clock
    // Use default system clock which runs at 16Mhz, page 1966
    *UARTCC_pointer &= ~(0xF);

    // Do not need to enable 2-mA mode since this is default
    //*GPIODR2R_pointer |= (1 << 0);
    // Slew Rate Limit Enable (control), need not be enabled since it is not available for 2-mA mode.
    //*GPIOSLR_pointer |= (1 << 0);

    // Run in normal (channel?) mode
    *UARTCTL_pointer &= ~(1 << 1);
    *UARTCTL_pointer &= ~(1 << 3);
    *UARTCTL_pointer &= ~(1 << 7);


    // Enable UARTEN bit (bit 0).
    *UARTCTL_pointer |= ((1 << 0));

    // Set a global variable to the base that is to be used, since getChar etc needs to know which base to operate from (We cannot pass it as an argument since we must follow the API given)
    g_UART_base_used = ui32Base;
    // UART has been initialized
    g_uart_init = 1;
    //-----------------------------------------------------------------------------
}
//=============================================================================
// This Function is used to receive one character.
// Will not try to access the hardware if the driver hasn't been initialized first, according to lab specification.
char UART_getChar()
{
    //-----------------------------------------------------------------------------
    volatile uint32_t *UARTDR_pointer = (volatile uint32_t*) (g_UART_base_used + UARTDR);
    volatile uint32_t *UARTRSR_ECR_pointer = (volatile uint32_t*) (g_UART_base_used + UARTRSR_ECR);
    volatile uint32_t *UARTFR_pointer = (volatile uint32_t*) (g_UART_base_used + UARTFR);

    volatile char character_received;
    //-----------------------------------------------------------------------------

    // If UART hasn't been initialized then UART_getChar() should do nothing (will not try access the hardware) according to specification.
    if(g_uart_init == 0)
    {
        // Return value if UART hasn't been initialized
        // 128 is not a defined ASCII symbol
        return (char) 128;
    }

    // Clear receive errors, we haven't received anything yet
    *UARTRSR_ECR_pointer = 0x00000000;

    // Wait while the UART is busy. (This bit is set to 0 when the UART is not busy).
    while ((*UARTFR_pointer) & (1 << 3))
    {
        ;
    }

    // This bit (4) is cleared when the receiver isn't empty
    while((*UARTFR_pointer) & (1 << 4))
    {
        ;
    }

    // Read the bits received, binary form
    character_received = (char) (*UARTDR_pointer & 0xFF);

    //-----------------------------------------------------------------------------
    // Check if there was any errors with the data received.
    // (Note that we read this from UARTRSR/UARTECR rather than UARTDR since UARTDR is read-sensitive, so once UARTDR is read, the content in UARTDR is expected to be altered!)
    // UART Framing Error
    if ((*UARTRSR_ECR_pointer) & (1 << 0))
    {
        // Clear the error register once it's been noticed
        *UARTRSR_ECR_pointer = 0x00000000;
        // Return value if there was an error with the data received
        // 129 is not a defined ASCII symbol
        return (char) 129;
    }
    // UART Parity Error
    if ((*UARTRSR_ECR_pointer) & (1 << 1))
    {
        // Clear the error register once it's been noticed
        *UARTRSR_ECR_pointer = 0x00000000;
        // Return value if there was an error with the data received
        // 130 is not a defined ASCII symbol
        return (char) 130;
    }
    // UART Break Error
    if ((*UARTRSR_ECR_pointer) & (1 << 2))
    {
        // Clear the error register once it's been noticed
        *UARTRSR_ECR_pointer = 0x00000000;
        // Return value if there was an error with the data received
        // 131 is not a defined ASCII symbol
        return (char) 131;
    }
    // UART Overrun Error
    if ((*UARTRSR_ECR_pointer) & (1 << 3))
    {
        // Clear the error register once it's been noticed
        *UARTRSR_ECR_pointer = 0x00000000;
        // Return value if there was an error with the data received
        // 132 is not a defined ASCII symbol
        return (char) 132;
    }
    //-----------------------------------------------------------------------------

    // Return the character received
    return character_received;
}
//=============================================================================
// This function is used to transmit one character.
// Will not try to access the hardware if the driver hasn't been initialized first, according to lab specification.
void UART_putChar(char c)
{
    //-----------------------------------------------------------------------------
    volatile uint32_t *UARTDR_pointer = (volatile uint32_t*) (g_UART_base_used + UARTDR);
    volatile uint32_t *UARTRSR_ECR_pointer = (volatile uint32_t*) (g_UART_base_used + UARTRSR_ECR);
    volatile uint32_t *UARTFR_pointer = (volatile uint32_t*) (g_UART_base_used + UARTFR);
    //-----------------------------------------------------------------------------

    // UART_putChar() will only do something if UART has been initialized, otherwise should do nothing (will not try access the hardware) according to specification.
    if (g_uart_init == 1)
    {
        // Clear receive errors
        *UARTRSR_ECR_pointer = 0x00000000;

        // Wait while the UART is busy. (This bit is set to 0 when the UART is not busy).
        while ((*UARTFR_pointer) & (1 << 3))
        {
            ;
        }

        // Wait until the UART transmitter no longer is full. (This bit is set to 0 when the transmitter isn't full).
        while ((*UARTFR_pointer) & (1 << 5))
        {
            ;
        }

        // Convert the ASCII character into it's decimal representation
        // Write the data that is to be transmitted into the data field
        *UARTDR_pointer = c;

        // Wait until the transmit holding register is empty and all data has been sent. (This bit is set once the transmitter is empty)
        while (!((*UARTFR_pointer) & (1 << 7)))
        {
            ;
        }
    }
}
//=============================================================================
// This function resets the driver to a save state (reset all registers that could lead to unpredictable behavior). Initialization after r
void UART_reset()
{
    //-----------------------------------------------------------------------------
    volatile uint32_t i = 0;
    volatile uint32_t j = 0;
    // Pointer for accessing registers
    volatile uint32_t *temp_pointer;

    // These need to be set and enabled to reset UART registers
    volatile uint32_t *RCGCUART_pointer = (volatile uint32_t*) RCGCUART;
    volatile uint32_t *RCGCGPIO_pointer = (volatile uint32_t*) RCGCGPIO;

    // Array containing every UART base
    volatile uint32_t base_arr[8] = {UART_base_0, UART_base_1, UART_base_2, UART_base_3, UART_base_4, UART_base_5, UART_base_6, UART_base_7};
    // Array containing the offset for all 30 UART registers
    volatile uint32_t register_arr[30] = {UARTDR, UARTRSR_ECR, UARTFR, UARTILPR, UARTIBRD, UARTFBRD, UARTLCRH, UARTCTL, UARTIFLS, UARTIM,
                               UARTRIS, UARTMIS, UARTICR, UARTDMACTL, UART9BITADDR, UART9BITAMASK, UARTPP, UARTCC, UARTPeriphID4, UARTPeriphID5,
                               UARTPeriphID6, UARTPeriphID7, UARTPeriphID0, UARTPeriphID1, UARTPeriphID2, UARTPeriphID3, UARTPCellID0, UARTPCellID1, UARTPCellID2, UARTPCellID3};
    // Array containing the reset vector for all 30 UART registers
    volatile uint32_t reset_arr[30] = {0x00000000, 0x00000000, 0x00000090, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000300, 0x00000012, 0x00000000,
                            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000000FF, 0x0000000F, 0x00000000, 0x00000060, 0x00000000,
                            0x00000000, 0x00000000, 0x00000011, 0x00000000, 0x00000018, 0x00000001, 0x0000000D, 0x000000F0, 0x00000005, 0x000000B1};
    //-----------------------------------------------------------------------------

    //-----------------------------------------------------------------------------
    // Enabling all UART bases, this is vital, otherwise trying to reset any UART register will result in a fault interrupt and the program will get stuck in a while loop in the faultISR forever
    // Enabling and providing a clock to all UART modules and enabling them in Run mode.
    *RCGCUART_pointer = 0xFF;
    // Enable all ports
    *RCGCGPIO_pointer = 0x7FFF;
    //-----------------------------------------------------------------------------
    // Using the respective reset vector to reset every UART register (for all UARTs)
    // Loop over every UART base since we need to reset all of them

    for(i = 0; i < 8; i++)
    {
        // Loop over every UART register to reset all of them
        for(j = 0; j < 30; j++)
        {
            // Set pointer to the base + register
            temp_pointer = (uint32_t*)(base_arr[i] + register_arr[j]);
            // Reset that base + register
            *temp_pointer = reset_arr[j];
        }
    }

    //-----------------------------------------------------------------------------
    // Disable all the UART bases again
    // Clearing the UART_module_bit bit and thus disabling the UART module.
    *RCGCUART_pointer = 0x00000000;
    // Disable the port
    *RCGCGPIO_pointer = 0x00000000;
    //-----------------------------------------------------------------------------

    // UART is not initialized
    g_uart_init = 0;
}
//=============================================================================
// This function uses the putChar function to write a string.
void UART_putString(char *string)
{
    //-----------------------------------------------------------------------------
    volatile int idx = 0;
    //-----------------------------------------------------------------------------

    // Write until all characters have been sent (check for end of string \0, while loop will end once 0 is found)
    while(string[idx])
    {
        UART_putChar(string[idx]);
        idx++;
    }
}
//=============================================================================
// This function uses the getChar function to read a string.
void UART_getString(char *buffer)
{
    //-----------------------------------------------------------------------------
    int idx = 0;
    //-----------------------------------------------------------------------------

    // Continue to read as long as there is data that can be received.
    while(idx < (BUFF_LEN-1))
    {
        // Get one character at a time
        buffer[idx] = UART_getChar();
        // Break early if we find end of string
        if ((buffer[idx] == '\n') || (buffer[idx] == '\r'))
        {
            break;
        }
        idx++;
    }

    // Null-terminate the string
    buffer[idx] = '\0';
}
//=============================================================================
