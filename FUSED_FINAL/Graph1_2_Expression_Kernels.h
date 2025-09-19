#ifndef MAIN_1_B_BASIC_KERNELS_H
#define MAIN_1_B_BASIC_KERNELS_H
#include "at_api.h"
#include "DspLib.h"


typedef struct SplitWidthIn2Arg_S {
    void * In;
    unsigned char DataSize;
    unsigned short int H;
    unsigned short int InWidth;
    unsigned short int S1;
    unsigned short int W1;
    void * Out1;
    unsigned short int S2;
    unsigned short int W2;
    void * Out2;
} SplitWidthIn2Arg_T;


void CNN_Split_Width_In2_Unused_1(SplitWidthIn2Arg_T *Arg);
void CNN_ParSplit_Width_In2_Unused_1(SplitWidthIn2Arg_T *Arg);

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    unsigned int I3;
    float *__restrict__  expr_0_in_0;
    float *__restrict__  expr_0_in_1;
    float *__restrict__  expr_0_in_2;
    float *__restrict__  expr_0_out_0;
    float *__restrict__  expr_0_out_1;
} G1_2s10_kernel_args_t;

typedef struct {
    unsigned int I0;
    float *__restrict__  expr_1_in_0;
    float *__restrict__  expr_1_in_1;
    float *__restrict__  expr_1_out_0;
} G1_2s23_kernel_args_t;

typedef struct {
    unsigned int I0;
    float *__restrict__  expr_2_in_0;
    float *__restrict__  expr_2_in_1;
    float *__restrict__  expr_2_out_0;
} G1_2s30_kernel_args_t;

typedef struct {
    unsigned int I0;
    float *__restrict__  expr_3_in_0;
    float *__restrict__  expr_3_in_1;
    float *__restrict__  expr_3_out_0;
} G1_2s39_kernel_args_t;

typedef struct {
    unsigned int I0;
    float *__restrict__  expr_4_in_0;
    float *__restrict__  expr_4_in_1;
    float *__restrict__  expr_4_out_0;
} G1_2s46_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    float *__restrict__  expr_5_in_0;
    float *__restrict__  expr_5_in_1;
    float *__restrict__  expr_5_out_0;
} G1_2s48_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    float *__restrict__  expr_6_in_0;
    float *__restrict__  expr_6_in_1;
    float *__restrict__  expr_6_out_0;
} G1_2s61_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    float *__restrict__  expr_7_in_0;
    float *__restrict__  expr_7_in_1;
    float *__restrict__  expr_7_in_2;
    float *__restrict__  expr_7_in_3;
    float *__restrict__  expr_7_out_0;
    float *__restrict__  expr_7_out_1;
} G1_2s65_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    float *__restrict__  expr_8_in_0;
    float *__restrict__  expr_8_in_1;
    float *__restrict__  expr_8_out_0;
} G1_2s68_kernel_args_t;

typedef struct {
    unsigned int I0;
    float *__restrict__  expr_9_in_0;
    float *__restrict__  expr_9_out_0;
} G1_2s54_kernel_args_t;

typedef struct {
    unsigned int I0;
    float *__restrict__  expr_10_in_0;
    float *__restrict__  expr_10_out_0;
} G1_2s75_kernel_args_t;


void G1_2s10_kernel(G1_2s10_kernel_args_t *Args);

void G1_2s23_kernel(G1_2s23_kernel_args_t *Args);

void G1_2s30_kernel(G1_2s30_kernel_args_t *Args);

void G1_2s39_kernel(G1_2s39_kernel_args_t *Args);

void G1_2s46_kernel(G1_2s46_kernel_args_t *Args);

void G1_2s48_kernel(G1_2s48_kernel_args_t *Args);

void G1_2s61_kernel(G1_2s61_kernel_args_t *Args);

void G1_2s65_kernel(G1_2s65_kernel_args_t *Args);

void G1_2s68_kernel(G1_2s68_kernel_args_t *Args);

void G1_2s54_kernel(G1_2s54_kernel_args_t *Args);

void G1_2s75_kernel(G1_2s75_kernel_args_t *Args);


#endif // MAIN_1_B_BASIC_KERNELS_H