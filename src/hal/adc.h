/**
 * adc.h
 * Bifrost ADC
 *
 * Description:
 *      This file contains hardware definitions for the Bifrost ADCs
 *
 * Author:          Ray Sun
 * Last Updated:    02/20/2020
 */


#ifndef ADC_H
#define ADC_H


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
                            
                            
#endif // ADC_H
