/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver Pins Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *
 * @skipline @version   Firmware Driver Version 1.0.2
 *
 * @skipline @version   PLIB Version 1.3.0
 *
 * @skipline  Device : dsPIC33CK32MC102
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB1 GPIO Pin which has a custom name of IO_RB1 to High
 * @pre      The RB1 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB1_SetHigh()          (_LATB1 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB1 GPIO Pin which has a custom name of IO_RB1 to Low
 * @pre      The RB1 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB1_SetLow()           (_LATB1 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB1 GPIO Pin which has a custom name of IO_RB1
 * @pre      The RB1 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB1_Toggle()           (_LATB1 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB1 GPIO Pin which has a custom name of IO_RB1
 * @param    none
 * @return   none  
 */
#define IO_RB1_GetValue()         _RB1

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB1 GPIO Pin which has a custom name of IO_RB1 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB1_SetDigitalInput()  (_TRISB1 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB1 GPIO Pin which has a custom name of IO_RB1 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB1_SetDigitalOutput() (_TRISB1 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB2 GPIO Pin which has a custom name of IO_RB2 to High
 * @pre      The RB2 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB2_SetHigh()          (_LATB2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB2 GPIO Pin which has a custom name of IO_RB2 to Low
 * @pre      The RB2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB2_SetLow()           (_LATB2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB2 GPIO Pin which has a custom name of IO_RB2
 * @pre      The RB2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB2_Toggle()           (_LATB2 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB2 GPIO Pin which has a custom name of IO_RB2
 * @param    none
 * @return   none  
 */
#define IO_RB2_GetValue()         _RB2

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB2 GPIO Pin which has a custom name of IO_RB2 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB2_SetDigitalInput()  (_TRISB2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB2 GPIO Pin which has a custom name of IO_RB2 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB2_SetDigitalOutput() (_TRISB2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB3 GPIO Pin which has a custom name of IO_RB3 to High
 * @pre      The RB3 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB3_SetHigh()          (_LATB3 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB3 GPIO Pin which has a custom name of IO_RB3 to Low
 * @pre      The RB3 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB3_SetLow()           (_LATB3 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB3 GPIO Pin which has a custom name of IO_RB3
 * @pre      The RB3 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB3_Toggle()           (_LATB3 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB3 GPIO Pin which has a custom name of IO_RB3
 * @param    none
 * @return   none  
 */
#define IO_RB3_GetValue()         _RB3

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB3 GPIO Pin which has a custom name of IO_RB3 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB3_SetDigitalInput()  (_TRISB3 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB3 GPIO Pin which has a custom name of IO_RB3 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB3_SetDigitalOutput() (_TRISB3 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB4 GPIO Pin which has a custom name of IO_RB4 to High
 * @pre      The RB4 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetHigh()          (_LATB4 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB4 GPIO Pin which has a custom name of IO_RB4 to Low
 * @pre      The RB4 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetLow()           (_LATB4 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB4 GPIO Pin which has a custom name of IO_RB4
 * @pre      The RB4 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB4_Toggle()           (_LATB4 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB4 GPIO Pin which has a custom name of IO_RB4
 * @param    none
 * @return   none  
 */
#define IO_RB4_GetValue()         _RB4

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB4 GPIO Pin which has a custom name of IO_RB4 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetDigitalInput()  (_TRISB4 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB4 GPIO Pin which has a custom name of IO_RB4 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB4_SetDigitalOutput() (_TRISB4 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB10 GPIO Pin which has a custom name of IO_RB10 to High
 * @pre      The RB10 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB10_SetHigh()          (_LATB10 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB10 GPIO Pin which has a custom name of IO_RB10 to Low
 * @pre      The RB10 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB10_SetLow()           (_LATB10 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB10 GPIO Pin which has a custom name of IO_RB10
 * @pre      The RB10 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB10_Toggle()           (_LATB10 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB10 GPIO Pin which has a custom name of IO_RB10
 * @param    none
 * @return   none  
 */
#define IO_RB10_GetValue()         _RB10

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB10 GPIO Pin which has a custom name of IO_RB10 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB10_SetDigitalInput()  (_TRISB10 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB10 GPIO Pin which has a custom name of IO_RB10 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB10_SetDigitalOutput() (_TRISB10 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB11 GPIO Pin which has a custom name of IO_RB11 to High
 * @pre      The RB11 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define IO_RB11_SetHigh()          (_LATB11 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB11 GPIO Pin which has a custom name of IO_RB11 to Low
 * @pre      The RB11 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB11_SetLow()           (_LATB11 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB11 GPIO Pin which has a custom name of IO_RB11
 * @pre      The RB11 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define IO_RB11_Toggle()           (_LATB11 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB11 GPIO Pin which has a custom name of IO_RB11
 * @param    none
 * @return   none  
 */
#define IO_RB11_GetValue()         _RB11

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB11 GPIO Pin which has a custom name of IO_RB11 as Input
 * @param    none
 * @return   none  
 */
#define IO_RB11_SetDigitalInput()  (_TRISB11 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB11 GPIO Pin which has a custom name of IO_RB11 as Output
 * @param    none
 * @return   none  
 */
#define IO_RB11_SetDigitalOutput() (_TRISB11 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
