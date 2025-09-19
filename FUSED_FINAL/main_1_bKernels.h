#ifndef __MAIN_1_BKERNEL_H__
#define __MAIN_1_BKERNEL_H__
#include "main_1Kernels.h"
#include "Graph1_2_Expression_Kernels.h"
#define _main_1_b_L1_Memory_SIZE 115344
#define _main_1_b_L2_Memory_SIZE 942676
extern char *main_1_b_L1_Memory; /* Size given for generation: 115712 bytes, used: 115344 bytes */
extern char *main_1_b_L2_Memory; /* Size used for generation: 942676 bytes */
extern void G1_2S2__ReduceSum(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G1_2S10_expr_0(
		float * __restrict__ expr_0_in_0,
		float * __restrict__ expr_0_in_1,
		float * __restrict__ expr_0_in_2,
		float * __restrict__ expr_0_out_0,
		float * __restrict__ expr_0_out_1);
extern void G1_2S18__MatMul(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out);
extern void G1_2S21__MatMul_1(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out);
extern void G1_2S23_expr_1(
		float * __restrict__ expr_1_in_0,
		float * __restrict__ expr_1_in_1,
		float * __restrict__ expr_1_out_0);
extern void G1_2S25__MatMul_2(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out);
extern void G1_2S28__MatMul_3(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out);
extern void G1_2S30_expr_2(
		float * __restrict__ expr_2_in_0,
		float * __restrict__ expr_2_in_1,
		float * __restrict__ expr_2_out_0);
extern void G1_2S32__Concat_trans(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G1_2S34__MatMul_4(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out);
extern void G1_2S37__MatMul_5(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out);
extern void G1_2S39_expr_3(
		float * __restrict__ expr_3_in_0,
		float * __restrict__ expr_3_in_1,
		float * __restrict__ expr_3_out_0);
extern void G1_2S41__MatMul_6(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out);
extern void G1_2S44__MatMul_7(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out);
extern void G1_2S46_expr_4(
		float * __restrict__ expr_4_in_0,
		float * __restrict__ expr_4_in_1,
		float * __restrict__ expr_4_out_0);
extern void G1_2S48_expr_5(
		float * __restrict__ expr_5_in_0,
		float * __restrict__ expr_5_in_1,
		float * __restrict__ expr_5_out_0);
extern void G1_2S52__Concat_3(
		float * __restrict__ In1,
		float * __restrict__ In2,
		float * __restrict__ Out);
extern void G1_2S53__Concat_4_trans_in1(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G1_2S54_expr_9(
		float * __restrict__ expr_9_in_0,
		float * __restrict__ expr_9_out_0);
extern void G1_2S55__Concat_2(
		float * __restrict__ In1,
		float * __restrict__ In2,
		float * __restrict__ Out);
extern void G1_2S56__Concat_4_trans_in0(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G1_2S58__Concat_4_trans_out0(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G1_2S61_expr_6(
		float * __restrict__ expr_6_in_0,
		float * __restrict__ expr_6_in_1,
		float * __restrict__ expr_6_out_0);
extern void G1_2S62__ReduceSum_1(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G1_2S65_expr_7(
		float * __restrict__ expr_7_in_0,
		float * __restrict__ expr_7_in_1,
		float * __restrict__ expr_7_in_2,
		float * __restrict__ expr_7_in_3,
		float * __restrict__ expr_7_out_0,
		float * __restrict__ expr_7_out_1);
extern void G1_2S66__ReduceSum_2(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G1_2S67__Gather_6(
		float * __restrict__ In,
		float * __restrict__ Out1);
extern void G1_2S68_expr_8(
		float * __restrict__ expr_8_in_0,
		float * __restrict__ expr_8_in_1,
		float * __restrict__ expr_8_out_0);
extern void G1_2S69__Gather_9_split_trans(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G1_2S73__Concat_6(
		float * __restrict__ In1,
		float * __restrict__ In2,
		float * __restrict__ Out);
extern void G1_2S74__Concat_7_trans_in1(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G1_2S75_expr_10(
		float * __restrict__ expr_10_in_0,
		float * __restrict__ expr_10_out_0);
extern void G1_2S76__Concat_5(
		float * __restrict__ In1,
		float * __restrict__ In2,
		float * __restrict__ Out);
extern void G1_2S77__Concat_7_trans_in0(
		float * __restrict__ In,
		float * __restrict__ Out);
extern void G1_2S79__Concat_7_trans_out0(
		float * __restrict__ In,
		float * __restrict__ Out);
extern int main_1_bCNN_Construct();
extern void main_1_bCNN_ConstructCluster();
extern int main_1_bCNN_Destruct();
extern int main_1_bCNN_Memory(AT_MEM_TYPE Which);
extern float * __restrict__ G1_2Input_1;
extern float * __restrict__ G1_2Input_2;
extern float * __restrict__ G1_2Input_3;
extern float * __restrict__ G1_2Output_1;
extern float * __restrict__ G1_2Output_2;
extern int main_1_bCNN(
);
extern unsigned int Inversion;
extern unsigned int G1_2_AT_GraphPerf[36];
extern unsigned int G1_2_AT_GraphPerf_CNN_Total;
extern char * G1_2_AT_GraphNodeNames[36];
extern unsigned int G1_2_AT_GraphOperInfosNames[36];
#endif
