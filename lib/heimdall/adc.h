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


// ########################### DEFINITIONS ####################################


#define ADCSRA_INIT 0xE5    // 0110 0101 - Set ADC to free running mode
                            // 0--- ----    Disable ADC 
                            // -1-- ----    Start the 1st conversion in FR mode
                            // --1- ----    Enable auto trigger
                            // ---0 ----    ADC conversion complete flag (ADIF)
                            // ---- 0---    Disable ADIF 
                            // ---- -101    Prescale divide by 32  
                            
#define ADCSRA_RUN          (ADCSRA_INIT | 0xF0)
                            // 0--- ----    Enable ADC 
                            
#define ADCSRA_ADIF_BIT     5
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
} HMD_ADC_PERPH;


// ############################# FUNCTIONS #####################################


void hmd_adc_init()             // Set up ADC
void hmd_adc_source()           // Configure ADC to read one of the peripherals

// Reads `n` samples of ADC into array at `readings`
void hmd_adc_read(int *readings, uint16_t n);
                            
#endif // HMD_ADC_H
