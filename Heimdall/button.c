/**
 * button.c
 * Bifrost button subroutines file
 *
 * Description:
 *      This file contains functions for reading the pushbuttons on Bifrost.
 *
 * Author:          Ray Sun
 * Last Updated:    02/22/2020
 */
 
  
#include "button.h"


// ############################# FUNCTIONS #####################################


// Initializes the button pins
void hmd_init_button() {
    // Turn off button input pins in DDR
    BTN_ULD_DDR = BTN_ULD_DDR   & (!BTN_ULD_MSK);
    BTN_R_DDR   = BTN_R_DDR     & (!BTN_R_MSK);
    
    // Turn off pullups
    BTN_ULD_PORT = BTN_ULD_PORT & (!BTN_ULD_MSK);
    BTN_R_PORT   = BTN_R_PORT   & (!BTN_R_MSK);
}

// Returns 4-bit button code, active high 
uint8_t hmd_read_button() {
    // Get not of buttons [3..1] in low 3 bits
    uint8_t btnULD = (!BTN_ULD_PINR) >> BTN_ULD_RS_N;
    
    // Get not of button 4 in high bit of word
    uint8_t btnR = (!BTN_R_PINR) >> BTN_R_RS_N;
    
    return (btnULD | btnR) & BTN_CODE_MSK;
}

// Returns true if U button pressed
bool hmd_read_U() {
    return (BTN_ULD_PINR & BTN_U_MSK) ? false : true;
}

// Returns true if D button pressed
bool hmd_read_D() {
    return (BTN_ULD_PINR & BTN_D_MSK) ? false : true;
}

// Returns true if L button pressed
bool hmd_read_L() {
    return (BTN_ULD_PINR & BTN_L_MSK) ? false : true;
}

// Returns true if R button pressed
bool hmd_read_R() {
    return (BTN_ULD_PINR & BTN_R_MSK) ? false : true;
}
