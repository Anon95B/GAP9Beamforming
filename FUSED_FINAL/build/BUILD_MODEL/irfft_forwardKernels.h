#ifndef __IRFFT_FORWARDKERNEL_H__
#define __IRFFT_FORWARDKERNEL_H__

#define _irfft_forward_L1_Memory_SIZE 8200
#define _irfft_forward_L2_Memory_SIZE 4096
extern char *irfft_forward_L1_Memory; /* Size given for generation: 115712 bytes, used: 8200 bytes */
extern char *irfft_forward_L2_Memory; /* Size used for generation: 4096 bytes */
extern void S4_IRfftNode(
		float * __restrict__ In,
		float * __restrict__ Out,
		float * __restrict__ Twiddles_fft_int,
		float * __restrict__ Twiddles_rfft,
		short int * SwapTable_fft);
extern int irfft_forwardCNN_Construct();
extern void irfft_forwardCNN_ConstructCluster();
extern int irfft_forwardCNN_Destruct();
extern int irfft_forwardCNN_Memory(AT_MEM_TYPE Which);
extern int irfft_forwardCNN(
		float * __restrict__ Input_1,
		float * __restrict__ Output_1);
#endif
