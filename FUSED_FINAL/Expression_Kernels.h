#ifndef MAIN_1_BASIC_KERNELS_H
#define MAIN_1_BASIC_KERNELS_H
#include "at_api.h"
#include "DspLib.h"
#include "DspLib.h"
#include "at_api.h"

typedef struct {
    unsigned int I0;
    unsigned int I1;
    signed char *__restrict__  expr_0_in_0;
    signed char *__restrict__  expr_0_in_1;
    signed char *__restrict__  expr_0_out_0;
    signed char *__restrict__  expr_0_out_1;
} s5_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    unsigned int *__restrict__  RsqrtLUT;
    signed char *__restrict__  expr_1_in_0;
    signed char *__restrict__  expr_1_in_1;
    signed char *__restrict__  expr_1_in_2;
    signed char *__restrict__  expr_1_in_3;
    unsigned char *__restrict__  expr_1_out_0;
} s9_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned char *__restrict__  expr_3_in_0;
    signed char *__restrict__  expr_3_in_1;
    unsigned char *__restrict__  expr_3_out_0;
    signed char *__restrict__  expr_3_out_1;
} s26_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_4_in_0;
    unsigned char *__restrict__  expr_4_in_1;
    unsigned char *__restrict__  expr_4_in_2;
    unsigned char *__restrict__  expr_4_in_3;
    unsigned char *__restrict__  expr_4_in_4;
    unsigned char *__restrict__  expr_4_in_5;
    unsigned char *__restrict__  expr_4_in_6;
    unsigned char *__restrict__  expr_4_in_7;
    unsigned char *__restrict__  expr_4_out_0;
} s135_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    unsigned char *__restrict__  expr_6_in_0;
    signed char *__restrict__  expr_6_in_1;
    signed char *__restrict__  expr_6_in_2;
    signed char *__restrict__  expr_6_in_3;
    unsigned char *__restrict__  expr_6_in_4;
    unsigned char *__restrict__  expr_6_out_0;
    unsigned char *__restrict__  expr_6_out_1;
} s30_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned char *__restrict__  expr_7_in_0;
    signed char *__restrict__  expr_7_in_1;
    unsigned char *__restrict__  expr_7_out_0;
    signed char *__restrict__  expr_7_out_1;
} s40_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    unsigned char *__restrict__  expr_8_in_0;
    signed char *__restrict__  expr_8_in_1;
    signed char *__restrict__  expr_8_in_2;
    signed char *__restrict__  expr_8_in_3;
    unsigned char *__restrict__  expr_8_out_0;
} s44_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_9_in_0;
    unsigned char *__restrict__  expr_9_in_1;
    unsigned char *__restrict__  expr_9_out_0;
} s45_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_11_in_0;
    unsigned char *__restrict__  expr_11_in_1;
    unsigned char *__restrict__  expr_11_out_0;
} s60_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned char *__restrict__  expr_12_in_0;
    signed char *__restrict__  expr_12_in_1;
    unsigned char *__restrict__  expr_12_out_0;
    signed char *__restrict__  expr_12_out_1;
} s55_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    unsigned char *__restrict__  expr_13_in_0;
    signed char *__restrict__  expr_13_in_1;
    signed char *__restrict__  expr_13_in_2;
    signed char *__restrict__  expr_13_in_3;
    unsigned char *__restrict__  expr_13_out_0;
} s59_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_14_in_0;
    unsigned char *__restrict__  expr_14_in_1;
    unsigned char *__restrict__  expr_14_out_0;
} s75_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_16_in_0;
    unsigned char *__restrict__  expr_16_in_1;
    unsigned char *__restrict__  expr_16_out_0;
} s90_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned char *__restrict__  expr_17_in_0;
    signed char *__restrict__  expr_17_in_1;
    unsigned char *__restrict__  expr_17_out_0;
    signed char *__restrict__  expr_17_out_1;
} s70_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    unsigned char *__restrict__  expr_18_in_0;
    signed char *__restrict__  expr_18_in_1;
    signed char *__restrict__  expr_18_in_2;
    signed char *__restrict__  expr_18_in_3;
    unsigned char *__restrict__  expr_18_out_0;
} s74_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_19_in_0;
    unsigned char *__restrict__  expr_19_in_1;
    unsigned char *__restrict__  expr_19_out_0;
} s105_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_20_in_0;
    unsigned char *__restrict__  expr_20_in_1;
    unsigned char *__restrict__  expr_20_out_0;
} s120_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned char *__restrict__  expr_22_in_0;
    signed char *__restrict__  expr_22_in_1;
    unsigned char *__restrict__  expr_22_out_0;
    signed char *__restrict__  expr_22_out_1;
} s85_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    unsigned char *__restrict__  expr_23_in_0;
    signed char *__restrict__  expr_23_in_1;
    signed char *__restrict__  expr_23_in_2;
    signed char *__restrict__  expr_23_in_3;
    unsigned char *__restrict__  expr_23_out_0;
} s89_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned char *__restrict__  expr_25_in_0;
    signed char *__restrict__  expr_25_in_1;
    unsigned char *__restrict__  expr_25_out_0;
    signed char *__restrict__  expr_25_out_1;
} s100_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    unsigned char *__restrict__  expr_26_in_0;
    signed char *__restrict__  expr_26_in_1;
    signed char *__restrict__  expr_26_in_2;
    signed char *__restrict__  expr_26_in_3;
    unsigned char *__restrict__  expr_26_out_0;
} s104_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned char *__restrict__  expr_28_in_0;
    signed char *__restrict__  expr_28_in_1;
    unsigned char *__restrict__  expr_28_out_0;
    signed char *__restrict__  expr_28_out_1;
} s115_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    unsigned char *__restrict__  expr_29_in_0;
    signed char *__restrict__  expr_29_in_1;
    signed char *__restrict__  expr_29_in_2;
    signed char *__restrict__  expr_29_in_3;
    unsigned char *__restrict__  expr_29_out_0;
} s119_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned char *__restrict__  expr_31_in_0;
    signed char *__restrict__  expr_31_in_1;
    unsigned char *__restrict__  expr_31_out_0;
    signed char *__restrict__  expr_31_out_1;
} s130_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned int I1;
    unsigned int I2;
    unsigned char *__restrict__  expr_32_in_0;
    signed char *__restrict__  expr_32_in_1;
    signed char *__restrict__  expr_32_in_2;
    signed char *__restrict__  expr_32_in_3;
    unsigned char *__restrict__  expr_32_out_0;
} s134_kernel_args_t;

typedef struct {
    unsigned int I0;
    unsigned char *__restrict__  expr_33_in_0;
    float *__restrict__  expr_33_out_0;
} s142_kernel_args_t;

typedef struct {
    signed char *__restrict__  expr_2_in_0;
    signed char *__restrict__  expr_2_out_0;
    unsigned short int W;
    unsigned short int H;
    unsigned short int Feat;
    unsigned int * __restrict__ RsqrtLUT;
} expr_2_args_t;

typedef struct {
    signed char *__restrict__  expr_5_in_0;
    signed char *__restrict__  expr_5_out_0;
    unsigned short int W;
    unsigned short int H;
    unsigned short int Feat;
    unsigned int * __restrict__ RsqrtLUT;
} expr_5_args_t;

typedef struct {
    signed char *__restrict__  expr_10_in_0;
    signed char *__restrict__  expr_10_out_0;
    unsigned short int W;
    unsigned short int H;
    unsigned short int Feat;
    unsigned int * __restrict__ RsqrtLUT;
} expr_10_args_t;

typedef struct {
    signed char *__restrict__  expr_15_in_0;
    signed char *__restrict__  expr_15_out_0;
    unsigned short int W;
    unsigned short int H;
    unsigned short int Feat;
    unsigned int * __restrict__ RsqrtLUT;
} expr_15_args_t;

typedef struct {
    signed char *__restrict__  expr_21_in_0;
    signed char *__restrict__  expr_21_out_0;
    unsigned short int W;
    unsigned short int H;
    unsigned short int Feat;
    unsigned int * __restrict__ RsqrtLUT;
} expr_21_args_t;

typedef struct {
    signed char *__restrict__  expr_24_in_0;
    signed char *__restrict__  expr_24_out_0;
    unsigned short int W;
    unsigned short int H;
    unsigned short int Feat;
    unsigned int * __restrict__ RsqrtLUT;
} expr_24_args_t;

typedef struct {
    signed char *__restrict__  expr_27_in_0;
    signed char *__restrict__  expr_27_out_0;
    unsigned short int W;
    unsigned short int H;
    unsigned short int Feat;
    unsigned int * __restrict__ RsqrtLUT;
} expr_27_args_t;

typedef struct {
    signed char *__restrict__  expr_30_in_0;
    signed char *__restrict__  expr_30_out_0;
    unsigned short int W;
    unsigned short int H;
    unsigned short int Feat;
    unsigned int * __restrict__ RsqrtLUT;
} expr_30_args_t;


void s5_kernel(s5_kernel_args_t *Args);

void s9_kernel(s9_kernel_args_t *Args);

void s26_kernel(s26_kernel_args_t *Args);

void s135_kernel(s135_kernel_args_t *Args);

void s30_kernel(s30_kernel_args_t *Args);

void s40_kernel(s40_kernel_args_t *Args);

void s44_kernel(s44_kernel_args_t *Args);

void s45_kernel(s45_kernel_args_t *Args);

void s60_kernel(s60_kernel_args_t *Args);

void s55_kernel(s55_kernel_args_t *Args);

void s59_kernel(s59_kernel_args_t *Args);

void s75_kernel(s75_kernel_args_t *Args);

void s90_kernel(s90_kernel_args_t *Args);

void s70_kernel(s70_kernel_args_t *Args);

void s74_kernel(s74_kernel_args_t *Args);

void s105_kernel(s105_kernel_args_t *Args);

void s120_kernel(s120_kernel_args_t *Args);

void s85_kernel(s85_kernel_args_t *Args);

void s89_kernel(s89_kernel_args_t *Args);

void s100_kernel(s100_kernel_args_t *Args);

void s104_kernel(s104_kernel_args_t *Args);

void s115_kernel(s115_kernel_args_t *Args);

void s119_kernel(s119_kernel_args_t *Args);

void s130_kernel(s130_kernel_args_t *Args);

void s134_kernel(s134_kernel_args_t *Args);

void s142_kernel(s142_kernel_args_t *Args);

void expr_2(expr_2_args_t *Args);

void expr_5(expr_5_args_t *Args);

void expr_10(expr_10_args_t *Args);

void expr_15(expr_15_args_t *Args);

void expr_21(expr_21_args_t *Args);

void expr_24(expr_24_args_t *Args);

void expr_27(expr_27_args_t *Args);

void expr_30(expr_30_args_t *Args);


#endif // MAIN_1_BASIC_KERNELS_H