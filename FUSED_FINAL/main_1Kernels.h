#ifndef __MAIN_1KERNEL_H__
#define __MAIN_1KERNEL_H__

#include "AutoTilerLibTypes.h"
#include "at_api.h"
#include "main_1.h"
#include "CNN_BasicKernels_SQ8.h"
#include "CNN_BasicKernels.h"
#include "CNN_BasicKernels_fp32.h"
#include "CNN_BasicKernels_f16.h"
#include "CNN_BasicKernels_f16a.h"
#include "CNN_BasicKernels_NE16.h"
#include "Expression_Kernels.h"
#define _main_1_L1_Memory_SIZE 115688
#define _main_1_L2_Memory_SIZE 20924
#define _main_1_L2_Memory_Dyn_SIZE 919312
extern char *main_1_L1_Memory; /* Size given for generation: 115712 bytes, used: 115688 bytes */
extern char *main_1_L2_Memory; /* Size used for generation (static): 20924 bytes */
extern char *main_1_L2_Memory_Dyn; /* Size used for generation (dynamic): 919312 bytes */
extern AT_DEFAULTRAM_POINTER main_1_L3_Memory_Dyn;
extern AT_DEFAULTRAM_T DefaultRam;
extern void S1_input_1_qout0(
		float * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S3__Transpose(
		signed char * __restrict__ In,
		signed char * __restrict__ Out);
extern void S4__enc_LN_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S5_expr_0(
		signed char * __restrict__ expr_0_in_0,
		signed char * __restrict__ expr_0_in_1,
		signed char * __restrict__ expr_0_out_0,
		signed char * __restrict__ expr_0_out_1);
extern void S6__enc_LN_ReduceMean_1(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S9_expr_1(
		signed char * __restrict__ expr_1_in_0,
		signed char * __restrict__ expr_1_in_1,
		signed char * __restrict__ expr_1_in_2,
		signed char * __restrict__ expr_1_in_3,
		unsigned char * __restrict__ expr_1_out_0,
		unsigned int * __restrict__ RsqrtLUT);
extern void S11__BN_Conv_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S14__BN_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S15__BN_Conv_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S18__conv_0_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S21__conv_0_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S22__conv_0_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S24__conv_0_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S25__conv_0_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S26_expr_3(
		unsigned char * __restrict__ expr_3_in_0,
		signed char * __restrict__ expr_3_in_1,
		unsigned char * __restrict__ expr_3_out_0,
		signed char * __restrict__ expr_3_out_1);
extern void S27__conv_0_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT);
extern void S30_expr_6(
		unsigned char * __restrict__ expr_6_in_0,
		signed char * __restrict__ expr_6_in_1,
		signed char * __restrict__ expr_6_in_2,
		signed char * __restrict__ expr_6_in_3,
		unsigned char * __restrict__ expr_6_in_4,
		unsigned char * __restrict__ expr_6_out_0,
		unsigned char * __restrict__ expr_6_out_1);
extern void S32__conv_1_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S35__conv_1_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S36__conv_1_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S38__conv_1_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S39__conv_1_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S40_expr_7(
		unsigned char * __restrict__ expr_7_in_0,
		signed char * __restrict__ expr_7_in_1,
		unsigned char * __restrict__ expr_7_out_0,
		signed char * __restrict__ expr_7_out_1);
extern void S41__conv_1_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT);
extern void S44_expr_8(
		unsigned char * __restrict__ expr_8_in_0,
		signed char * __restrict__ expr_8_in_1,
		signed char * __restrict__ expr_8_in_2,
		signed char * __restrict__ expr_8_in_3,
		unsigned char * __restrict__ expr_8_out_0);
extern void S45_expr_9(
		unsigned char * __restrict__ expr_9_in_0,
		unsigned char * __restrict__ expr_9_in_1,
		unsigned char * __restrict__ expr_9_out_0);
extern void S47__conv_2_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S50__conv_2_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S51__conv_2_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S53__conv_2_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S54__conv_2_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S55_expr_12(
		unsigned char * __restrict__ expr_12_in_0,
		signed char * __restrict__ expr_12_in_1,
		unsigned char * __restrict__ expr_12_out_0,
		signed char * __restrict__ expr_12_out_1);
extern void S56__conv_2_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT);
extern void S59_expr_13(
		unsigned char * __restrict__ expr_13_in_0,
		signed char * __restrict__ expr_13_in_1,
		signed char * __restrict__ expr_13_in_2,
		signed char * __restrict__ expr_13_in_3,
		unsigned char * __restrict__ expr_13_out_0);
extern void S60_expr_11(
		unsigned char * __restrict__ expr_11_in_0,
		unsigned char * __restrict__ expr_11_in_1,
		unsigned char * __restrict__ expr_11_out_0);
extern void S62__conv_3_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S65__conv_3_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S66__conv_3_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S68__conv_3_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S69__conv_3_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S70_expr_17(
		unsigned char * __restrict__ expr_17_in_0,
		signed char * __restrict__ expr_17_in_1,
		unsigned char * __restrict__ expr_17_out_0,
		signed char * __restrict__ expr_17_out_1);
extern void S71__conv_3_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT);
extern void S74_expr_18(
		unsigned char * __restrict__ expr_18_in_0,
		signed char * __restrict__ expr_18_in_1,
		signed char * __restrict__ expr_18_in_2,
		signed char * __restrict__ expr_18_in_3,
		unsigned char * __restrict__ expr_18_out_0);
extern void S75_expr_14(
		unsigned char * __restrict__ expr_14_in_0,
		unsigned char * __restrict__ expr_14_in_1,
		unsigned char * __restrict__ expr_14_out_0);
extern void S77__conv_4_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S80__conv_4_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S81__conv_4_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S83__conv_4_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S84__conv_4_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S85_expr_22(
		unsigned char * __restrict__ expr_22_in_0,
		signed char * __restrict__ expr_22_in_1,
		unsigned char * __restrict__ expr_22_out_0,
		signed char * __restrict__ expr_22_out_1);
extern void S86__conv_4_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT);
extern void S89_expr_23(
		unsigned char * __restrict__ expr_23_in_0,
		signed char * __restrict__ expr_23_in_1,
		signed char * __restrict__ expr_23_in_2,
		signed char * __restrict__ expr_23_in_3,
		unsigned char * __restrict__ expr_23_out_0);
extern void S90_expr_16(
		unsigned char * __restrict__ expr_16_in_0,
		unsigned char * __restrict__ expr_16_in_1,
		unsigned char * __restrict__ expr_16_out_0);
extern void S92__conv_5_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S95__conv_5_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S96__conv_5_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S98__conv_5_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S99__conv_5_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S100_expr_25(
		unsigned char * __restrict__ expr_25_in_0,
		signed char * __restrict__ expr_25_in_1,
		unsigned char * __restrict__ expr_25_out_0,
		signed char * __restrict__ expr_25_out_1);
extern void S101__conv_5_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT);
extern void S104_expr_26(
		unsigned char * __restrict__ expr_26_in_0,
		signed char * __restrict__ expr_26_in_1,
		signed char * __restrict__ expr_26_in_2,
		signed char * __restrict__ expr_26_in_3,
		unsigned char * __restrict__ expr_26_out_0);
extern void S105_expr_19(
		unsigned char * __restrict__ expr_19_in_0,
		unsigned char * __restrict__ expr_19_in_1,
		unsigned char * __restrict__ expr_19_out_0);
extern void S107__conv_6_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S110__conv_6_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S111__conv_6_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S113__conv_6_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S114__conv_6_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S115_expr_28(
		unsigned char * __restrict__ expr_28_in_0,
		signed char * __restrict__ expr_28_in_1,
		unsigned char * __restrict__ expr_28_out_0,
		signed char * __restrict__ expr_28_out_1);
extern void S116__conv_6_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT);
extern void S119_expr_29(
		unsigned char * __restrict__ expr_29_in_0,
		signed char * __restrict__ expr_29_in_1,
		signed char * __restrict__ expr_29_in_2,
		signed char * __restrict__ expr_29_in_3,
		unsigned char * __restrict__ expr_29_out_0);
extern void S120_expr_20(
		unsigned char * __restrict__ expr_20_in_0,
		unsigned char * __restrict__ expr_20_in_1,
		unsigned char * __restrict__ expr_20_out_0);
extern void S122__conv_7_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S125__conv_7_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void S126__conv_7_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S128__conv_7_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S129__conv_7_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void S130_expr_31(
		unsigned char * __restrict__ expr_31_in_0,
		signed char * __restrict__ expr_31_in_1,
		unsigned char * __restrict__ expr_31_out_0,
		signed char * __restrict__ expr_31_out_1);
extern void S131__conv_7_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT);
extern void S134_expr_32(
		unsigned char * __restrict__ expr_32_in_0,
		signed char * __restrict__ expr_32_in_1,
		signed char * __restrict__ expr_32_in_2,
		signed char * __restrict__ expr_32_in_3,
		unsigned char * __restrict__ expr_32_out_0);
extern void S135_expr_4(
		unsigned char * __restrict__ expr_4_in_0,
		unsigned char * __restrict__ expr_4_in_1,
		unsigned char * __restrict__ expr_4_in_2,
		unsigned char * __restrict__ expr_4_in_3,
		unsigned char * __restrict__ expr_4_in_4,
		unsigned char * __restrict__ expr_4_in_5,
		unsigned char * __restrict__ expr_4_in_6,
		unsigned char * __restrict__ expr_4_in_7,
		unsigned char * __restrict__ expr_4_out_0);
extern void S137__reshape_speech_reshape_speech_0_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out);
extern void S140__reshape_speech_reshape_speech_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8);
extern void S142_expr_33(
		unsigned char * __restrict__ expr_33_in_0,
		float * __restrict__ expr_33_out_0);
extern void S144__reshape_speech_reshape_speech_0_Conv_reshape_qout0(
		unsigned char * __restrict__ In,
		float * __restrict__ Out,
		signed char * __restrict__ Infos);
extern int main_1CNN_Construct();
extern void main_1CNN_ConstructCluster();
extern int main_1CNN_Destruct();
extern int main_1CNN_Memory(AT_MEM_TYPE Which);
extern float * __restrict__ Input_1;
extern float * __restrict__ Output_1;
extern float * __restrict__ Output_2;
extern int main_1CNN(
);
extern unsigned int G1_AT_GraphPerf[85];
extern unsigned int G1_AT_GraphPerf_CNN_Total;
extern char * G1_AT_GraphNodeNames[85];
extern unsigned int G1_AT_GraphOperInfosNames[85];
#endif
