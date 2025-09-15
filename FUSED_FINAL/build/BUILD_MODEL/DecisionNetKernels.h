#ifndef __DECISIONNETKERNEL_H__
#define __DECISIONNETKERNEL_H__


#include "Expression_Kernels.h"
#define _DecisionNet_L1_Memory_SIZE 115696
#define _DecisionNet_L2_Memory_SIZE 403240
extern char *DecisionNet_L1_Memory; /* Size given for generation: 115712 bytes, used: 115696 bytes */
extern char *DecisionNet_L2_Memory; /* Size used for generation: 403240 bytes */
extern AT_DEFAULTRAM_POINTER DecisionNet_L3_Memory;
extern void Decision_S3__conv1_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void Decision_S6__layer1_layer1_0_conv1_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void Decision_S9__layer1_layer1_0_conv2_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void Decision_S10__layer1_layer1_0_Add_fusion(
		unsigned char * __restrict__ In1,
		unsigned char * __restrict__ In2,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void Decision_S13__layer2_layer2_0_conv1_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void Decision_S16__layer2_layer2_0_conv2_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void Decision_S19__layer2_layer2_0_shortcut_shortcut_0_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void Decision_S20__layer2_layer2_0_Add_fusion(
		unsigned char * __restrict__ In1,
		unsigned char * __restrict__ In2,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void Decision_S23__layer3_layer3_0_conv1_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void Decision_S26__layer3_layer3_0_conv2_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void Decision_S29__layer3_layer3_0_shortcut_shortcut_0_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos);
extern void Decision_S30__layer3_layer3_0_Add_fusion(
		unsigned char * __restrict__ In1,
		unsigned char * __restrict__ In2,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void Decision_S31__gap_MaxPool(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos);
extern void Decision_S35__fc_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8);
extern int DecisionNetCNN_Construct();
extern void DecisionNetCNN_ConstructCluster();
extern int DecisionNetCNN_Destruct();
extern int DecisionNetCNN_Memory(AT_MEM_TYPE Which);
extern int DecisionNetCNN(
		unsigned char * __restrict__ Input_1,
		unsigned char * __restrict__ Output_1);
extern unsigned int Decision_AT_GraphPerf[15];
extern unsigned int Decision_AT_GraphPerf_CNN_Total;
extern char * Decision_AT_GraphNodeNames[15];
extern unsigned int Decision_AT_GraphOperInfosNames[15];
#endif
