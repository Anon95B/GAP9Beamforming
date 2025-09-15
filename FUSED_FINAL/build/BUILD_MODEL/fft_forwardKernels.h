#ifndef __FFT_FORWARDKERNEL_H__
#define __FFT_FORWARDKERNEL_H__



#define _fft_forward_L1_Memory_SIZE 9228
#define _fft_forward_L2_Memory_SIZE 5124
extern char *fft_forward_L1_Memory; /* Size given for generation: 115712 bytes, used: 9228 bytes */
extern char *fft_forward_L2_Memory; /* Size used for generation: 5124 bytes */
extern void S5_RfftNode(
		float * __restrict__ In,
		float * __restrict__ Out,
		float * __restrict__ Twiddles_fft_int,
		float * __restrict__ Twiddles_rfft,
		short int * SwapTable_fft,
		float * __restrict__ WinTable);
extern int fft_forwardCNN_Construct();
extern void fft_forwardCNN_ConstructCluster();
extern int fft_forwardCNN_Destruct();
extern int fft_forwardCNN_Memory(AT_MEM_TYPE Which);
extern int fft_forwardCNN(
		float * __restrict__ Input_1,
		float * __restrict__ Output_1);
#endif
