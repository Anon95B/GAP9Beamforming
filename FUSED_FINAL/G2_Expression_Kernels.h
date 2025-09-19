#ifndef MAIN_2_BASIC_KERNELS_H
#define MAIN_2_BASIC_KERNELS_H
#include "at_api.h"
#include "DspLib.h"



typedef struct {
    unsigned int I0;
    unsigned int I1;
    float *__restrict__  expr_0_in_0;
    float *__restrict__  expr_0_in_1;
    float *__restrict__  expr_0_out_0;
} G2s8_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    float *__restrict__  expr_1_in_0;
    float *__restrict__  expr_1_in_1;
    float *__restrict__  expr_1_out_0;
} G2s10_kernel_args_t;

typedef struct {
    unsigned int I0;
    float *__restrict__  expr_2_in_0;
    float *__restrict__  expr_2_in_1;
    float *__restrict__  expr_2_in_2;
    float *__restrict__  expr_2_in_3;
    float *__restrict__  expr_2_out_0;
    float *__restrict__  expr_2_out_1;
} G2s18_kernel_args_t;


void G2s8_kernel(G2s8_kernel_args_t *Args);

void G2s10_kernel(G2s10_kernel_args_t *Args);

void G2s18_kernel(G2s18_kernel_args_t *Args);


#endif // MAIN_2_BASIC_KERNELS_H