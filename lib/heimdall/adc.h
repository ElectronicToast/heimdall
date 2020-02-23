/**
 * adc.h
 * Bifrost ADC
 *
 * Description:
 *      This file contains hardware definitions for the Bifrost ADCs
 *
 * Author:          Ray Sun
 * Last Updated:    02/22/2020
 */


#ifndef HMD_ADC_H
#define HMD_ADC_H


#include "pinmap.h"


// ########################### DEFINITIONS ####################################


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


#define ADCSRA_INIT 0xE5    // 0110 0101 - Set ADC to free running mode
                            // 0--- ----    Disable ADC 
                            // -1-- ----    Start the 1st conversion in FR mode
                            // --1- ----    Enable auto trigger
                            // ---0 ----    ADC conversion complete flag (ADIF)
                            // ---- 0---    Disable ADIF 
                            // ---- -101    Prescale divide by 32  
                            
#define ADCSRA_RUN          (ADCSRA_INIT | 0xF0)
                            // 0--- ----    Enable ADC 
                            
#define ADCSRA_ADIF_BIT     4
#define ADCSRA_ADIF_MSK     (1 << ADCSRA_ADIF_BIT)

                            
#define ADCSRB_INIT 0x00    // 0000 0000 - Default
                            // 0-00 0---    Reserved
                            // -0-- ----    Comparator multiplexer disabled
                            // ---- -000    Free running mode
                            

// ############################ DATA TYPES #####################################


// Bifrost ADC peripherals
typedef enum {
    AUD_L = AUD_L_N;
    AUD_R = AUD_R_N;
    MIC = MIC_N;
} hmd_adc_perph;


// ############################# FUNCTIONS #####################################


void hmd_adc_init();                    // Set up ADC
void hmd_adc_source(hmd_adc_perph p);   // Configure ADC to read a peripheral

// Reads `n` samples of ADC into array at `readings`
void hmd_adc_read(int *readings, uint16_t n);
                            
#endif // HMD_ADC_H
