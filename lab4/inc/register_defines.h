/**
 * ----------------------------------------------------------------------------
 * register_defines.h
 * Author: Carl Larsson
 * Description: h file for register defines
 * Date: 2023-09-18
 * ----------------------------------------------------------------------------
 */

#ifndef REGISTER_DEFINES_H
#define REGISTER_DEFINES_H

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Includes
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Defines of various registers etc
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//-----------------------------------------------------------------------------
// Base + offset
//-----------------------------------------------------------------------------
// Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control
#define RCGCUART 0x400FE618
// General-Purpose Input/Output Run Mode Clock Gating Control
#define RCGCGPIO 0x400FE608
// Micro Direct Memory Access Run Mode Clock Gating Control
#define RCGCDMA  0x400FE60C
// DMA Configuration
#define DMACFG 0x400FF004
//-----------------------------------------------------------------------------
// Base
//-----------------------------------------------------------------------------
// UART bases
// UART 0 base
#define UART_base_0 0x4000C000
// UART 1 base
#define UART_base_1 0x4000D000
// UART 2 base
#define UART_base_2 0x4000E000
// UART 3 base
#define UART_base_3 0x4000F000
// UART 4 base
#define UART_base_4 0x40010000
// UART 5 base
#define UART_base_5 0x40011000
// UART 6 base
#define UART_base_6 0x40012000
// UART 7 base
#define UART_base_7 0x40013000
//-----------------------------------------------------------------------------
// Port bases
// Port A base
#define GPIO_Port_A_base 0x40058000
// Port B base
#define GPIO_Port_B_base 0x40059000
// Port C base
#define GPIO_Port_C_base 0x4005A000
// Port D base
#define GPIO_Port_D_base 0x4005B000
// Port E base
#define GPIO_Port_E_base 0x4005C000
// Port F base
#define GPIO_Port_F_base 0x4005D000
// Port G base
#define GPIO_Port_G_base 0x4005E000
// Port H base
#define GPIO_Port_H_base 0x4005F000
// Port J base
#define GPIO_Port_J_base 0x40060000
// Port K base
#define GPIO_Port_K_base 0x40061000
// Port L base
#define GPIO_Port_L_base 0x40062000
// Port M base
#define GPIO_Port_M_base 0x40063000
// Port N base
#define GPIO_Port_N_base 0x40064000
// Port P base
#define GPIO_Port_P_base 0x40065000
// Port Q base
#define GPIO_Port_Q_base 0x40066000
//-----------------------------------------------------------------------------
// Offsets
//-----------------------------------------------------------------------------
// GPIO Alternate Function Select
#define GPIOAFSEL 0x420
// GPIO 2-mA Drive Select
#define GPIODR2R 0x500
// GPIO Slew Rate Control Select
#define GPIOSLR 0x518
// GPIO Port Control
#define GPIOPCTL 0x52C
// UART Control (UART 0)
#define UARTCTL 0x030
// UART Integer Baud-Rate Divisor (UART0)
#define UARTIBRD  0x024
// UART Fractional Baud-Rate Divisor (UART0)
#define UARTFBRD 0x028
// UART Line Control (UART0)
#define UARTLCRH 0x02C
// UART Clock Configuration (UART0)
#define UARTCC 0xFC8
// UART Data
#define UARTDR 0x000
// UART Receive Status/Error Clear
#define UARTRSR_ECR 0x004
// UART Flag
#define UARTFR 0x018
// UART IrDA Low-Power Register
#define UARTILPR 0x020
// UART Interrupt FIFO Level Select
#define UARTIFLS 0x034
// UART Interrupt Mask
#define UARTIM 0x038
// UART Raw Interrupt Status
#define UARTRIS 0x03C
// UART Masked Interrupt Status
#define UARTMIS 0x040
// UART Interrupt Clear
#define UARTICR 0x044
// UART DMA Control
#define UARTDMACTL 0x048
// UART 9-Bit Self Address
#define UART9BITADDR 0x0A4
// UART 9-Bit Self Address Mask
#define UART9BITAMASK 0x0A8
// UART Peripheral Properties
#define UARTPP 0xFC0
// UART Clock Configuration
#define UARTCC 0xFC8
// UART Peripheral Identification 4
#define UARTPeriphID4 0xFD0
// UART Peripheral Identification 5
#define UARTPeriphID5 0xFD4
// UART Peripheral Identification 6
#define UARTPeriphID6 0xFD8
// UART Peripheral Identification 7
#define UARTPeriphID7 0xFDC
// UART Peripheral Identification 0
#define UARTPeriphID0 0xFE0
// UART Peripheral Identification 1
#define UARTPeriphID1 0xFE4
// UART Peripheral Identification 2
#define UARTPeriphID2 0xFE8
// UART Peripheral Identification 3
#define UARTPeriphID3 0xFEC
// UART PrimeCell Identification 0
#define UARTPCellID0 0xFF0
// UART PrimeCell Identification 1
#define UARTPCellID1 0xFF4
// UART PrimeCell Identification 2
#define UARTPCellID2 0xFF8
// UART PrimeCell Identification 3
#define UARTPCellID3 0xFFC
// GPIO Digital Enable
#define GPIODEN 0x51C
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif // REGISTER_DEFINES_H
