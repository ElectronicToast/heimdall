/**
 * pinmap.h
 * Bifrost Pin Map and Port Definitions
 *
 * Description:
 *      This file contains hardware definitions for the Bifrost pin mapping 
 *      and associated registers.
 *
 * Author:          Ray Sun
 * Last Updated:    02/20/2020
 */


#ifndef PINMAP_H
#define PINMAP_H


// ###################### ARDUINO PIN DEFINITIONS ##############################


// LED output
#define     OUT1_PIN            5
#define     OUT2_PIN            6
#define     OUT3_PIN            7
#define     OUT4_PIN            8

// Indicator LEDs
#define     LED_BUILTIN_PIN     13
#define     LED1_PIN            A3
#define     LED2_PIN            A6
#define     LED3_PIN            A7

// Pushbuttons
#define     BTN1_PIN            2
#define     BTN2_PIN            3
#define     BTN3_PIN            4
#define     BTN4_PIN            9

// Analog
#define     AUD_L_PIN           A0
#define     AUD_R_PIN           A1
#define     MIC_PIN             A2

// UART
#define     UART_RX_PIN         0
#define     UART_TX_PIN         1

// I2C
#define     I2C_SDA_PIN         A4
#define     I2C_SCL_PIN         A5

// SPI 
#define     SPI_SCK_PIN         13
#define     SPI_MOSI_PIN        11
#define     SPI_MISO_PIN        12
#define     SPI_nCS_PIN         10


// ######################### PORT DEFINITIONS ##################################


// Buttons
#define     BTN_123_PORT        PORTD
#define     BTN_123_DDR         DDRD
#define     BTN_123_PINR        PIND
#define     BTN_1_PIN_N         2                       // PD2
#define     BTN_2_PIN_N         3                       // PD3
#define     BTN_3_PIN_N         4                       // PD4
#define     BTN_1_MSK           (1 << BTN_1_PIN_N)
#define     BTN_2_MSK           (1 << BTN_2_PIN_N)
#define     BTN_3_MSK           (1 << BTN_3_PIN_N)
#define     BTN_123_MSK         (BTN_1_MSK | BTN_2_MSK | BTN_3_MSK)

#define     BTN_4_PORT          PORTB
#define     BTN_4_DDR           DDRB
#define     BTN_4_PINR          PINB
#define     BTN_4_PIN_N         7                       // PD7
#define     BTN_4_MSK           (1 << BTN_4_PIN_N)

#define     BTN_123_RS_N        2       // Right shift to get 1 in low bit
#define     BTN_4_RS_N          4       // Right shift to get 4 in bit 3

// U = 1
// L = 2
// D = 3
// R = 4
#define     BTN_ULD_PORT        BTN_123_PORT
#define     BTN_ULD_DDR         BTN_123_DDR
#define     BTN_ULD_PINR        BTN_123_PINR
#define     BTN_U_PIN_N         BTN_1_PIN_N
#define     BTN_L_PIN_N         BTN_2_PIN_N
#define     BTN_D_PIN_N         BTN_3_PIN_N
#define     BTN_U_MSK           (1 << BTN_U_PIN_N)
#define     BTN_L_MSK           (1 << BTN_L_PIN_N)
#define     BTN_D_MSK           (1 << BTN_D_PIN_N)
#define     BTN_ULD_MSK         (BTN_U_MSK | BTN_L_MSK | BTN_D_MSK)

#define     BTN_R_PORT          BTN_4_PORT
#define     BTN_R_DDR           BTN_4_DDR
#define     BTN_R_PINR          BTN_4_PINR
#define     BTN_R_PIN_N         BTN_4_PIN_N
#define     BTN_R_MSK           (1 << BTN_R_PIN_N)

#define     BTN_ULD_RS_N        2       // Right shift to get 1 in low bit
#define     BTN_R_RS_N          4       // Right shift to get 4 in bit 3

#define     BTN_CODE_MSK        0x0F    // Mask off high byte


// ########################## ADC DEFINITIONS ##################################


#define AUD_L_N         0       // ADC0
#define AUD_R_N         1       // ADC1 
#define MIC_N           2       // ADC2


#define AUD_L_ADMUX     0x40    // 0100 0000 - Use ADC0
                                // 01-- ----    Voltage reference is AVcc
                                // --0- ----    Right adjust ADC result 
                                // ---- 0000    Select ADC0  
#define AUD_R_ADMUX     0x41    // 0100 0001 - Use ADC1
                                // 01-- ----    Voltage reference is AVcc
                                // --0- ----    Right adjust ADC result 
                                // ---- 0001    Select ADC1   
#define MIC_ADMUX       0x42    // 0100 0010 - Use ADC2
                                // 01-- ----    Voltage reference is AVcc
                                // --0- ----    Right adjust ADC result 
                                // ---- 0010    Select ADC2     
                           
                           
#define AUD_L_DIDR      (1 << AUD_L_N)
#define AUD_R_DIDR      (1 << AUD_R_N)
#define MIC_DIDR        (1 << MIC_N)
#define AUD_MIC_DDR     (AUD_L_DIDR | AUD_R_DIDR | MIC_DIDR)


#endif // PINMAP_H
