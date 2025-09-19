#ifndef __main_1_H__
#define __main_1_H__

#define __PREFIX(x) main_1 ## x
// Include basic GAP builtins defined in the Autotiler
#include "at_api.h"

extern AT_DEFAULTFLASH_EXT_ADDR_TYPE main_1_L3_Flash;
extern AT_DEFAULTFLASH_EXT_ADDR_TYPE main_1_b_L3_Flash;
extern AT_DEFAULTFLASH_EXT_ADDR_TYPE main_2_L3_Flash;
extern AT_DEFAULTFLASH_EXT_ADDR_TYPE DecisionNet_L3_Flash;
extern AT_DEFAULTFLASH_EXT_ADDR_TYPE Big_fft_forward_L3_Flash;
extern AT_DEFAULTFLASH_EXT_ADDR_TYPE fft_forward_L3_Flash;
extern AT_DEFAULTFLASH_EXT_ADDR_TYPE irfft_forward_L3_Flash;

extern float G2_Input [6144];
extern float G2_out [512];
extern float* output_imaginary;
extern float* output_real;
extern uint8_t first_execution; 
extern pi_gpio_e gpio_test_0, gpio_test_1, gpio_test_2;
#endif