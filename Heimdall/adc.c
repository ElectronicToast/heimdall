/**
 * adc.h
 * Bifrost ADC
 *
 * Description:
 *      This file contains functions for the Bifrost ADCs
 *
 * Author:          Ray Sun
 * Last Updated:    02/23/2020
 */


#include "adc.h"

 
 // ############################# FUNCTIONS #####################################


// Set up ADC
void hmd_adc_init() {
    ADCSRA = ADCSRA_INIT;       // Set up ADC, auto trigger
    DIDR = AUD_MIC_DDR;         // Disable input on audio and mic
}

// Configure ADC to read a peripheral
void hmd_adc_source(hmd_adc_perph p) {
    switch (p) {
        case AUD_L:
            ADMUX = AUD_L_ADMUX;
            break;
        case AUD_R:
            ADMUX = AUD_R_ADMUX;
            break;
        case MIC:
            ADMUX = MIC_ADMUX;
            break;
        default:
            break;
    }
}

// Reads `n` samples of ADC into array at `readings`
void hmd_adc_read(int *readings, uint16_t n) {
    for (uint16_t i = 0 ; i < n ; i++) { 
        // Wait for ADC to be ready - ADIF bit is set
        while (!(ADCSRA & ADIF_MSK)); 
        
        ADCSRA = ADCSRA_RUN;    // Restart the ADC (start another conversion)
        
        byte m = ADCL;          // Get the ADC data word
        byte j = ADCH;
        int k = (j << 8) | m;   // Convert to an int
        k -= 0x0200;            // then a signed int
        k <<= 6;                // and finally a 16-bit signed int
        
        readings[i] = k;       // Insert into array
    }
}
