#ifndef __MAIN_2KERNEL_H__
#define __MAIN_2KERNEL_H__

#include "main_1_bKernels.h"
#include "irfft_forwardKernels.h"
#include "fft_forwardKernels.h"
#include "Big_fft_forwardKernels.h"
#include "DecisionNetKernels.h"
#include "G2_Expression_Kernels.h"
#define _main_2_L1_Memory_SIZE 111620
#define _main_2_L2_Memory_SIZE 309428
extern char *main_2_L1_Memory; /* Size given for generation: 115712 bytes, used: 111620 bytes */
extern char *main_2_L2_Memory; /* Size used for generation: 309428 bytes */
extern L2_MEM AT_L2_POINTER main_2_L2_Memory_Dyn;

static AT_DEFAULTFLASH_FS_T DefaultFlash;
extern void G2S3_input_3_copy(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G2S6__MatMul(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out);
extern void G2S8_expr_0(
		float * __restrict__ expr_0_in_0,
		float * __restrict__ expr_0_in_1,
		float * __restrict__ expr_0_out_0);
extern void G2S9__ReduceSum(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G2S10_expr_1(
		float * __restrict__ expr_1_in_0,
		float * __restrict__ expr_1_in_1,
		float * __restrict__ expr_1_out_0);
extern void G2S11__Slice_tin(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G2S13__Slice_tout0(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G2S16__Slice_tout1(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G2S18_expr_2(
		float * __restrict__ expr_2_in_0,
		float * __restrict__ expr_2_in_1,
		float * __restrict__ expr_2_in_2,
		float * __restrict__ expr_2_in_3,
		float * __restrict__ expr_2_out_0,
		float * __restrict__ expr_2_out_1);
extern void G2S20__ReduceSum_1(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G2S24__ReduceSum_2(
		float * __restrict__ In,
		float * __restrict__ Out);
extern int main_2CNN_Construct();
extern void main_2CNN_ConstructCluster();
extern int main_2CNN_Destruct();
extern int main_2CNN_Memory(AT_MEM_TYPE Which);
extern float * __restrict__ G2Input_1;
extern float * __restrict__ G2Input_2;
extern int main_2CNN(
		float * __restrict__ Input_3,
		float * __restrict__ Output_1,
		float * __restrict__ Output_2);
extern unsigned int G2_AT_GraphPerf[12];
extern unsigned int G2_AT_GraphPerf_CNN_Total;
extern char * G2_AT_GraphNodeNames[12];
extern unsigned int G2_AT_GraphOperInfosNames[12];
#endif
