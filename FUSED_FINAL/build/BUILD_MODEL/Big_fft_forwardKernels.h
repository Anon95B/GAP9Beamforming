#ifndef BIG__FFT_FORWARDKERNEL_H__
#define BIG__FFT_FORWARDKERNEL_H__


extern char *fft_forward_L1_Memory; /* Size given for generation: 115712 bytes, used: 13340 bytes */
extern char *fft_forward_L2_Memory; /* Size used for generation (static): 5124 bytes */
extern char *fft_forward_L2_Memory_Dyn; /* Size used for generation (dynamic): 6168 bytes */
extern void BiG_S5_RfftNode(
		float * __restrict__ In,
		float * __restrict__ Out,
		float * __restrict__ Twiddles_fft_int,
		float * __restrict__ Twiddles_rfft,
		short int * SwapTable_fft,
		float * __restrict__ WinTable);
extern int BiG_fft_forwardCNN_Construct();

extern int BiG_fft_forwardCNN_Destruct();
extern int BiG_fft_forwardCNN_Memory(AT_MEM_TYPE Which);
extern float * __restrict__ BiG_STFT_Input_1;
extern float * __restrict__ BiG_STFT_Output_1;
extern int BiG_fft_forwardCNN();

#endif
