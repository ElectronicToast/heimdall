/**
 * button.h
 * Bifrost button header file
 *
 * Description:
 *      This file contains definitions and function prototypes for reading the
 *      pushbuttons on Bifrost.
 *
 * Author:          Ray Sun
 * Last Updated:    02/22/2020
 */


#ifndef HMD_BTN_H
#define HMD_BTN_H


#include <stdint.h>


void hmd_init_button();

uint8_t hmd_read_button();      // Returns 4-bit button code, active high 
bool hmd_read_U();
bool hmd_read_D();
bool hmd_read_L();
bool hmd_read_R();


#endif // HMD_BTN_H
