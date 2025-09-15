#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "main_2Kernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER main_2_L1_Memory;
L2_MEM AT_L2_POINTER main_2_L2_Memory;
L2_MEM AT_L2_POINTER main_2_L2_Memory_Dyn;
AT_DEFAULTRAM_POINTER main_2_L3_Memory_Dyn;
void  G2S3_input_3_copy(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 6168 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 12336, Tiled: 4]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 4 logical tiles, 4 physical tiles
			@ 0 (Total Size: 12336 )[D0, [3 x 3084, 3084]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [3 x 3084, 3084]]
		Tile0: [0, 3084, 3084], Tile1: [3084, 3084, 3084], Tile2; [6168, 3084, 3084]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 4 logical tiles, 4 physical tiles
			@ 0 (Total Size: 12336 )[D0, [3 x 3084, 3084]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [3 x 3084, 3084]]
		Tile0: [0, 3084, 3084], Tile1: [3084, 3084, 3084], Tile2; [6168, 3084, 3084]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+0), 3084, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=3084;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<4; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==3), D0Ind_NextLast = ((D0Ind+1)==3);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(D0Ind_Last)) {
			_N_In = _N_In + (3084); _SN_In = (3084); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+3084*((D0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+3084*((D0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(D0Ind_Last)) {
			_C_Out = _C_Out + (3084); _SC_Out = (3084); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G2S6__MatMul(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out)

{
	/* Shared L1: 3504 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	KerMatMul_fp32_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T1Ind, T1Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _NN_In1;
	unsigned int _SN_In1, _SNN_In1;
	unsigned int _NN_In2;
	unsigned int _SN_In2, _SNN_In2;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 257][Tile1 Dim: 1][Tile0 Dim: 1]
	Ker Arg: In1, Tiled Space: Tile1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 0 (Total Size: 148032 )[D0, [256 x 576, 576]][Tile1, 1:[12x12], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 576, 576]][Tile1, 1:[12x12], 4]
		Tile0: [0, 576, 576], Tile1: [576, 576, 576], Tile2; [1152, 576, 576]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 2304 (Total Size: 148032 )[D0, [256 x 576, 576]][Tile0, 1:[12x12], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 576, 576]][Tile0, 1:[12x12], 4]
		Tile0: [0, 576, 576], Tile1: [576, 576, 576], Tile2; [1152, 576, 576]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 3456 (Total Size: 48 )[Tile0, 1:[1x12], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x12], 4]
		Tile0: [0, 48, 48], Tile1: [0, 48, 48], Tile2; [0, 48, 48]
	Ker Arg: Out, Tiled Space: Tile1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 1152 (Total Size: 148032 )[D0, [256 x 576, 576]][Tile1, 1:[12x12], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 576, 576]][Tile1, 1:[12x12], 4]
		Tile0: [0, 576, 576], Tile1: [576, 576, 576], Tile2; [1152, 576, 576]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W_In1 = (unsigned short int) (12);
	KerArg0->H_In1 = (unsigned short int) (12);
	KerArg0->W_In2 = (unsigned short int) (12);
	KerArg0->Bias = (float *__restrict__) (main_2_L1_Memory+3456);
	KerArg0->W_Out = (unsigned short int) (12);
	KerArg0->ColFirst = (unsigned char) (0);
	KerArg0->UB = (float) (6.000000e+00);
	KerArg0->LB = (float) (0.000000e+00);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_2_L2_Memory_Dyn+148032+0), 576, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+576), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_2_L2_Memory_Dyn+148032+576), 576, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_2_L2_Memory_Dyn+148032+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+0), 576, 0, DmaR_Evt1);
	_NN_In1=576; _SN_In1=576;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_2_L2_Memory_Dyn+149184+0), 576, 0, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read In2 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+576), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_2_L2_Memory_Dyn+149184+576), 576, 0, UchanHR2);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_2_L2_Memory_Dyn+149184+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+2304+0), 576, 0, DmaR_Evt2);
	_NN_In2=576; _SN_In2=576;
	_C_Out=0; _SC_Out=576;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+3456), 48, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Bias */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<257; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==256), D0Ind_NextLast = ((D0Ind+1)==256), D0Ind_NextNextLast = ((D0Ind+2)==256);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In1 = _NN_In1 + (576); _SNN_In1 = (576); 
			}
		}
		_SNN_In2 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In2 = _NN_In2 + (576); _SNN_In2 = (576); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+_NN_In1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_2_L2_Memory_Dyn+148032+576*((D0Ind_Total)%2)),
					1*(_SNN_In1), 0, UchanHR1);
		}
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_2_L2_Memory_Dyn+148032+576*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+576*((D0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read In2 */
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In2) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+_NN_In2), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_2_L2_Memory_Dyn+149184+576*((D0Ind_Total)%2)),
					1*(_SNN_In2), 0, UchanHR2);
		}
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_2_L2_Memory_Dyn+149184+576*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+2304+576*((D0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile1 */
			int T1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
				/*====================== Call Kernel LOC_LOOP =========================*/
				KerArg0->In1 = (float *__restrict__) (main_2_L1_Memory+0+576*((D0Ind_Total)%2));
				KerArg0->In2 = (float *__restrict__) (main_2_L1_Memory+2304+576*((D0Ind_Total)%2));
				KerArg0->Out = (float *__restrict__) (main_2_L1_Memory+1152+576*((D0Ind_Total)%2));
				KerArg0->OutFirstCol = (unsigned int) ((0)*12);
				AT_FORK(gap_ncore(), (void *) KerParMatMulTransposed_fp32, (void *) KerArg0);
				__CALL(KerParMatMulTransposed_fp32, KerArg0);
			} /* End iteration on Tile0 */
		} /* End iteration on Tile1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+1152+576*((D0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In1 = _SNN_In1;
		_SN_In2 = _SNN_In2;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(D0Ind_Last)) {
			_C_Out = _C_Out + (576); _SC_Out = (576); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G2S8_expr_0(
		float * __restrict__ expr_0_in_0,
		float * __restrict__ expr_0_in_1,
		float * __restrict__ expr_0_out_0)

{
	/* Shared L1: 111168 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	G2s8_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast;
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_0_out_0;
	unsigned int _SP_expr_0_out_0, _SC_expr_0_out_0;
	unsigned int _N_expr_0_in_1;
	unsigned int _SN_expr_0_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 257, Tiled: 6][D1 Dim: Init: 144, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_0_out_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 0 (Total Size: 148032 )[D0, [5 x 27648, 9792]][D1, [0 x 27648, 27648]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [5 x 27648, 9792]][D1, [0 x 27648, 27648]]
		Tile0: [0, 27648, 27648], Tile1: [27648, 27648, 27648], Tile2; [55296, 27648, 27648]
	Ker Arg: expr_0_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 55296 (Total Size: 576 )[D1, [0 x 576, 576]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 576, 576]]
		Tile0: [0, 576, 576], Tile1: [0, 576, 576], Tile2; [0, 576, 576]
	Ker Arg: expr_0_in_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 55872 (Total Size: 148032 )[D0, [5 x 27648, 9792]][D1, [0 x 27648, 27648]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [5 x 27648, 9792]][D1, [0 x 27648, 27648]]
		Tile0: [0, 27648, 27648], Tile1: [27648, 27648, 27648], Tile2; [55296, 27648, 27648]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I1 = (unsigned int) (144);
	KerArg0->expr_0_in_0 = (float *__restrict__ ) (main_2_L1_Memory+55296);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_0_out_0=0; _SC_expr_0_out_0=27648;
	_SP_expr_0_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+55872+0), 27648, 0, DmaR_Evt1);
	_N_expr_0_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+55296), 576, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_0_in_0 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<6; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==5), D0Ind_NextLast = ((D0Ind+1)==5);
		/*================================= Prepare Tiles ===================================*/
		_SN_expr_0_in_1 = 0;
		if (!(D0Ind_Last)) {
			_N_expr_0_in_1 = _N_expr_0_in_1 + (27648); _SN_expr_0_in_1 = (((D0Ind_NextLast)?17:48)*(576)); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_0_in_1 */
		if (_SN_expr_0_in_1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_1+_N_expr_0_in_1), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+55872+27648*((D0Ind_Total+1)%2)),
					1*(_SN_expr_0_in_1), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on D1 */
			int D1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I0 = (unsigned int) ((D0Ind_Last)?17:48);
			KerArg0->expr_0_in_1 = (float *__restrict__ ) (main_2_L1_Memory+55872+27648*((D0Ind_Total)%2));
			KerArg0->expr_0_out_0 = (float *__restrict__ ) (main_2_L1_Memory+0+27648*((D0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) G2s8_kernel, (void *) KerArg0);
			__CALL(G2s8_kernel, KerArg0);
		} /* End iteration on D1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_expr_0_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_0_out_0 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_out_0+_C_expr_0_out_0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+27648*((D0Ind_Total)%2)),
				_SC_expr_0_out_0, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_expr_0_out_0 = _SC_expr_0_out_0;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_expr_0_out_0 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_0_out_0 = _C_expr_0_out_0 + (27648); _SC_expr_0_out_0 = (((D0Ind_NextLast)?17:48)*(576)); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_0_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G2S9__ReduceSum(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 99332 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerGlobalPool_fp32_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _LN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 257, Tiled: 2][Tile0 Dim: 3]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 0 (Total Size: 148032 )[D0, [1 x 147456, 576]][Tile0, 3:[12x4, 1:12x4, 12x4], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 147456, 576]][Tile0, 3:[12x4, 1:12x4, 12x4], 4]
		Tile0: [0, 49152, 192], Tile1: [192, 49152, 192], Tile2; [384, 49152, 192]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 98304 (Total Size: 1028 )[D0, [1 x 1024, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 1024, 4]]
		Tile0: [0, 1028, 1028], Tile1: [0, 1028, 1028], Tile2; [0, 1028, 1028]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (12);
	KerArg0->H = (unsigned short int) (4);
	KerArg0->FullHW = (unsigned int) (144);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+0), 49152, 576, 192, 0, DmaR_Evt1);
	_N_In=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<2; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==1), D0Ind_NextLast = ((D0Ind+1)==1);
		for (T0Ind=0; T0Ind<3; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==2), T0Ind_NextLast = ((T0Ind+1)==2);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (192); _LN_In = (192); _SN_In = (((D0Ind_Last)?1:256)*_LN_In); 
			} else if (!(D0Ind_Last)) {
				_N_In = _N_In + (147456)+(-384); _LN_In = (192); _SN_In = (((1)?1:256)*_LN_In); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+49152*((T0Ind_Total+1)%2)),
						1*(_SN_In), 576, _LN_In, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (float * __restrict__) (main_2_L1_Memory+0+49152*((T0Ind_Total)%2));
			KerArg0->OutFeatures = (unsigned short int) ((D0Ind_Last)?1:256);
			KerArg0->Out = (float * __restrict__) (main_2_L1_Memory+98304+((D0Ind)*1024));
			KerArg0->LastTile = (unsigned int) ((T0Ind_Last));
			KerArg0->TileIndex = (unsigned int) ((T0Ind));
			AT_FORK(gap_ncore(), (void *) KerParGlobalSum_fp32, (void *) KerArg0);
			__CALL(KerParGlobalSum_fp32, KerArg0);
			/*================================= Update Arg Pipeline =============================*/
			/*============================= End Update Arg Pipeline =============================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+98304), 1028, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G2S10_expr_1(
		float * __restrict__ expr_1_in_0,
		float * __restrict__ expr_1_in_1,
		float * __restrict__ expr_1_out_0)

{
	/* Shared L1: 111620 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	G2s10_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_1_out_0;
	unsigned int _SP_expr_1_out_0, _SC_expr_1_out_0;
	unsigned int _LP_expr_1_out_0, _LC_expr_1_out_0;
	unsigned int _N_expr_1_in_0;
	unsigned int _SN_expr_1_in_0;
	unsigned int _LN_expr_1_in_0;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 257, Tiled: 2][D1 Dim: Init: 144, Tiled: 6][Tile0 Dim: 1]
	Ker Arg: expr_1_out_0, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 12 logical tiles, 12 physical tiles
			@ 0 (Total Size: 148032 )[D0, [1 x 147456, 576]][D1, [5 x 27648, 9216]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 147456, 576]][D1, [5 x 27648, 9216]]
		Tile0: [0, 27648, 108], Tile1: [108, 27648, 108], Tile2; [216, 27648, 108]
	Ker Arg: expr_1_in_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 12 logical tiles, 12 physical tiles
			@ 55296 (Total Size: 148032 )[D0, [1 x 147456, 576]][D1, [5 x 27648, 9216]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 147456, 576]][D1, [5 x 27648, 9216]]
		Tile0: [0, 27648, 108], Tile1: [108, 27648, 108], Tile2; [216, 27648, 108]
	Ker Arg: expr_1_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 110592 (Total Size: 1028 )[D0, [1 x 1024, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 1024, 4]]
		Tile0: [0, 1028, 1028], Tile1: [0, 1028, 1028], Tile2; [0, 1028, 1028]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_1_out_0=0; _SC_expr_1_out_0=27648; _LC_expr_1_out_0=108;
	_SP_expr_1_out_0=0;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+55296+0), 27648, 576, 108, 0, DmaR_Evt1);
	_N_expr_1_in_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+110592), 1028, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_1_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<2; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==1), D0Ind_NextLast = ((D0Ind+1)==1);
		for (D1Ind=0; D1Ind<6; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==5), D1Ind_NextLast = ((D1Ind+1)==5);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_1_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_1_in_0 = _N_expr_1_in_0 + (108); _LN_expr_1_in_0 = ((D1Ind_NextLast)?36:108); _SN_expr_1_in_0 = (((D0Ind_Last)?1:256)*_LN_expr_1_in_0); 
			} else if (!(D0Ind_Last)) {
				_N_expr_1_in_0 = _N_expr_1_in_0 + (147456)+(-540); _LN_expr_1_in_0 = (108); _SN_expr_1_in_0 = (((1)?1:256)*_LN_expr_1_in_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_1_in_0 */
			if (_SN_expr_1_in_0) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_0+_N_expr_1_in_0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+55296+27648*((D1Ind_Total+1)%2)),
						1*(_SN_expr_1_in_0), 576, _LN_expr_1_in_0, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I0 = (unsigned int) ((D0Ind_Last)?1:256);
			KerArg0->I1 = (unsigned int) ((D1Ind_Last)?9:27);
			KerArg0->expr_1_in_0 = (float *__restrict__ ) (main_2_L1_Memory+55296+27648*((D1Ind_Total)%2));
			KerArg0->expr_1_in_1 = (float *__restrict__ ) (main_2_L1_Memory+110592+((D0Ind)*1024));
			KerArg0->expr_1_out_0 = (float *__restrict__ ) (main_2_L1_Memory+0+27648*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) G2s10_kernel, (void *) KerArg0);
			__CALL(G2s10_kernel, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_1_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_1_out_0 */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_out_0+_C_expr_1_out_0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+27648*((D1Ind_Total)%2)),
					_SC_expr_1_out_0, 576, _LC_expr_1_out_0, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_expr_1_out_0 = _SC_expr_1_out_0;_LP_expr_1_out_0 = _LC_expr_1_out_0;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_1_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_1_out_0 = _C_expr_1_out_0 + (108); _LC_expr_1_out_0 = ((D1Ind_NextLast)?36:108); _SC_expr_1_out_0 = (((D0Ind_Last)?1:256)*_LC_expr_1_out_0); 
			} else if (!(D0Ind_Last)) {
				_C_expr_1_out_0 = _C_expr_1_out_0 + (147456)+(-540); _LC_expr_1_out_0 = (108); _SC_expr_1_out_0 = (((1)?1:256)*_LC_expr_1_out_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_1_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G2S11__Slice_tin(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 98688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _LN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 6]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 0 (Total Size: 148032 )[Tile0, 6:[3084x2, 4:3084x2, 3084x2], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 6:[3084x2, 4:3084x2, 3084x2], 4]
		Tile0: [0, 24672, 8], Tile1: [8, 24672, 8], Tile2; [16, 24672, 8]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 49344 (Total Size: 148032 )[Tile0, 6:[3084x2, 4:3084x2, 3084x2], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 6:[3084x2, 4:3084x2, 3084x2], 4]
		Tile0: [0, 24672, 8], Tile1: [8, 24672, 8], Tile2; [16, 24672, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (257);
	KerArg0->W = (unsigned short int) (2);
	KerArg0->H = (unsigned short int) (12);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+0), 24672, 48, 8, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=24672; _LC_Out=8;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<6; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==5), T0Ind_NextLast = ((T0Ind+1)==5);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (8); _LN_In = (8); _SN_In = (3084*_LN_In); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+24672*((T0Ind_Total+1)%2)),
					1*(_SN_In), 48, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_2_L1_Memory+0+24672*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_2_L1_Memory+49344+24672*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2HCW_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2HCW_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+49344+24672*((T0Ind_Total)%2)),
				_SC_Out, 48, _LC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;_LP_Out = _LC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (8); _LC_Out = (8); _SC_Out = (3084*_LC_Out); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G2S13__Slice_tout0(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 98688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _LN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 3]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 74016 )[Tile0, 3:[1542x4, 1:1542x4, 1542x4], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[1542x4, 1:1542x4, 1542x4], 4]
		Tile0: [0, 24672, 16], Tile1: [16, 24672, 16], Tile2; [32, 24672, 16]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 49344 (Total Size: 74016 )[Tile0, 3:[1542x4, 1:1542x4, 1542x4], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[1542x4, 1:1542x4, 1542x4], 4]
		Tile0: [0, 24672, 24672], Tile1: [24672, 24672, 24672], Tile2; [49344, 24672, 24672]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (6);
	KerArg0->W = (unsigned short int) (4);
	KerArg0->H = (unsigned short int) (257);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+0), 24672, 48, 16, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=24672;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<3; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==2), T0Ind_NextLast = ((T0Ind+1)==2);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (16); _LN_In = (16); _SN_In = (1542*_LN_In); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+24672*((T0Ind_Total+1)%2)),
					1*(_SN_In), 48, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_2_L1_Memory+0+24672*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_2_L1_Memory+49344+24672*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2WHC_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2WHC_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+49344+24672*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (24672); _SC_Out = (24672); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G2S16__Slice_tout1(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 98688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _LN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 3]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 74016 )[Tile0, 3:[1542x4, 1:1542x4, 1542x4], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[1542x4, 1:1542x4, 1542x4], 4]
		Tile0: [0, 24672, 16], Tile1: [16, 24672, 16], Tile2; [32, 24672, 16]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 49344 (Total Size: 74016 )[Tile0, 3:[1542x4, 1:1542x4, 1542x4], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[1542x4, 1:1542x4, 1542x4], 4]
		Tile0: [0, 24672, 24672], Tile1: [24672, 24672, 24672], Tile2; [49344, 24672, 24672]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (6);
	KerArg0->W = (unsigned short int) (4);
	KerArg0->H = (unsigned short int) (257);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+0), 24672, 48, 16, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=24672;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<3; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==2), T0Ind_NextLast = ((T0Ind+1)==2);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (16); _LN_In = (16); _SN_In = (1542*_LN_In); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0+24672*((T0Ind_Total+1)%2)),
					1*(_SN_In), 48, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_2_L1_Memory+0+24672*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_2_L1_Memory+49344+24672*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2WHC_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2WHC_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+49344+24672*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (24672); _SC_Out = (24672); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G2S18_expr_2(
		float * __restrict__ expr_2_in_0,
		float * __restrict__ expr_2_in_1,
		float * __restrict__ expr_2_in_2,
		float * __restrict__ expr_2_in_3,
		float * __restrict__ expr_2_out_0,
		float * __restrict__ expr_2_out_1)

{
	/* Shared L1: 37008 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	G2s18_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 1542, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_2_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 6168 )[D0, [0 x 6168, 6168]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 6168, 6168]]
		Tile0: [0, 6168, 6168], Tile1: [0, 6168, 6168], Tile2; [0, 6168, 6168]
	Ker Arg: expr_2_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6168 (Total Size: 6168 )[D0, [0 x 6168, 6168]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 6168, 6168]]
		Tile0: [0, 6168, 6168], Tile1: [0, 6168, 6168], Tile2; [0, 6168, 6168]
	Ker Arg: expr_2_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 12336 (Total Size: 6168 )[D0, [0 x 6168, 6168]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 6168, 6168]]
		Tile0: [0, 6168, 6168], Tile1: [0, 6168, 6168], Tile2; [0, 6168, 6168]
	Ker Arg: expr_2_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 18504 (Total Size: 6168 )[D0, [0 x 6168, 6168]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 6168, 6168]]
		Tile0: [0, 6168, 6168], Tile1: [0, 6168, 6168], Tile2; [0, 6168, 6168]
	Ker Arg: expr_2_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 24672 (Total Size: 6168 )[D0, [0 x 6168, 6168]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 6168, 6168]]
		Tile0: [0, 6168, 6168], Tile1: [0, 6168, 6168], Tile2; [0, 6168, 6168]
	Ker Arg: expr_2_out_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 30840 (Total Size: 6168 )[D0, [0 x 6168, 6168]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 6168, 6168]]
		Tile0: [0, 6168, 6168], Tile1: [0, 6168, 6168], Tile2; [0, 6168, 6168]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1542);
	KerArg0->expr_2_in_0 = (float *__restrict__ ) (main_2_L1_Memory+6168);
	KerArg0->expr_2_in_1 = (float *__restrict__ ) (main_2_L1_Memory+12336);
	KerArg0->expr_2_in_2 = (float *__restrict__ ) (main_2_L1_Memory+24672);
	KerArg0->expr_2_in_3 = (float *__restrict__ ) (main_2_L1_Memory+18504);
	KerArg0->expr_2_out_0 = (float *__restrict__ ) (main_2_L1_Memory+0);
	KerArg0->expr_2_out_1 = (float *__restrict__ ) (main_2_L1_Memory+30840);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+6168), 6168, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+12336), 6168, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+18504), 6168, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+24672), 6168, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_2_in_2 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) G2s18_kernel, (void *) KerArg0);
		__CALL(G2s18_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_out_0+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0), 6168, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_2_out_0 */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_out_1+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+30840), 6168, 1, DmaW_Evt2);
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait DMA write expr_2_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G2S20__ReduceSum_1(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 7196 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerGlobalPool_fp32_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 257, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 6168 )[D0, [0 x 6168, 6168]][Tile0, 1:[3x2], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 6168, 6168]][Tile0, 1:[3x2], 4]
		Tile0: [0, 6168, 6168], Tile1: [0, 6168, 6168], Tile2; [0, 6168, 6168]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6168 (Total Size: 1028 )[D0, [0 x 1028, 1028]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1028, 1028]]
		Tile0: [0, 1028, 1028], Tile1: [0, 1028, 1028], Tile2; [0, 1028, 1028]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (float * __restrict__) (main_2_L1_Memory+0);
	KerArg0->W = (unsigned short int) (3);
	KerArg0->H = (unsigned short int) (2);
	KerArg0->FullHW = (unsigned int) (6);
	KerArg0->OutFeatures = (unsigned short int) (257);
	KerArg0->Out = (float * __restrict__) (main_2_L1_Memory+6168);
	KerArg0->LastTile = (unsigned int) ((1));
	KerArg0->TileIndex = (unsigned int) ((0));
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0), 6168, 0, DmaR_Evt1);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_LOOP =========================*/
			AT_FORK(gap_ncore(), (void *) KerParGlobalSum_fp32, (void *) KerArg0);
			__CALL(KerParGlobalSum_fp32, KerArg0);
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+6168), 1028, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G2S24__ReduceSum_2(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 7196 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerGlobalPool_fp32_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 257, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 6168 )[D0, [0 x 6168, 6168]][Tile0, 1:[3x2], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 6168, 6168]][Tile0, 1:[3x2], 4]
		Tile0: [0, 6168, 6168], Tile1: [0, 6168, 6168], Tile2; [0, 6168, 6168]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6168 (Total Size: 1028 )[D0, [0 x 1028, 1028]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1028, 1028]]
		Tile0: [0, 1028, 1028], Tile1: [0, 1028, 1028], Tile2; [0, 1028, 1028]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (float * __restrict__) (main_2_L1_Memory+0);
	KerArg0->W = (unsigned short int) (3);
	KerArg0->H = (unsigned short int) (2);
	KerArg0->FullHW = (unsigned int) (6);
	KerArg0->OutFeatures = (unsigned short int) (257);
	KerArg0->Out = (float * __restrict__) (main_2_L1_Memory+6168);
	KerArg0->LastTile = (unsigned int) ((1));
	KerArg0->TileIndex = (unsigned int) ((0));
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+0), 6168, 0, DmaR_Evt1);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_LOOP =========================*/
			AT_FORK(gap_ncore(), (void *) KerParGlobalSum_fp32, (void *) KerArg0);
			__CALL(KerParGlobalSum_fp32, KerArg0);
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_2_L1_Memory+6168), 1028, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
#pragma GCC diagnostic pop
int  main_2CNN_Construct()

{
	int Error;

	// AT_DEFAULTRAM_CONF_T DefaultRamConf;
	// AT_DEFAULTRAM_CONF_INIT(&DefaultRamConf, AT_MEM_L3_DEFAULTRAM, 0);
	// AT_DEFAULTRAM_OPEN(&DefaultRam, &DefaultRamConf, &Error);
	// if (Error) return AT_RAM_OPEN_ERROR;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "main_2_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;

	main_2_L3_Memory_Dyn = main_1_L3_Memory_Dyn + 2138240+1677696;
	if (main_2_L3_Memory_Dyn == 0) return AT_RAM_OPEN_ERROR;
	main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn;
	if (main_2_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	main_2_L1_Memory = main_1_L1_Memory;
	if (main_2_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	G2Input_1 = (float * __restrict__) (main_2_L3_Memory_Dyn + 0);
	G2Input_2 = (float * __restrict__) (main_2_L3_Memory_Dyn + 148032);
	return AT_NO_ERROR;
}
void main_2CNN_ConstructCluster()

{
}
int  main_2CNN_Destruct()

{
	AT_DEFAULTRAM_FREE(&DefaultRam, main_2_L3_Memory_Dyn, 296064);
	AT_L2_FREE(0, main_2_L2_Memory_Dyn, 309428);
	AT_L1_FREE(0, main_2_L1_Memory, 111620);
	AT_DEFAULTRAM_CLOSE(&DefaultRam);
	AT_DEFAULTFLASH_FS_CLOSE(&DefaultFlash);
	G2Input_1 = 0;
	G2Input_2 = 0;
	return 0;
}
int main_2CNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 111620; /* L1 Memory */
		case AT_L2_MEM:     return 0; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 309428; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 296064; /* L3 Memory, dynamic */
		default:            return 0;
	}
}
unsigned int G2_AT_GraphPerf[12];
unsigned int G2_AT_GraphPerf_CNN_Total = 0;
unsigned int G2_AT_GraphOperInfosNames[12] = {
	3084,
	444096,
	37008,
	37008,
	37008,
	37008,
	18504,
	18504,
	18504,
	1542,
	1542,
	0,
};
char *G2_AT_GraphNodeNames[12] = {
	"G2S3_input_3_copy",
	"G2S6__MatMul",
	"G2S8_expr_0",
	"G2S9__ReduceSum",
	"G2S10_expr_1",
	"G2S11__Slice_tin",
	"G2S13__Slice_tout0",
	"G2S16__Slice_tout1",
	"G2S18_expr_2",
	"G2S20__ReduceSum_1",
	"G2S24__ReduceSum_2",
	"IO_Wait",
};
float * __restrict__ G2Input_1;
float * __restrict__ G2Input_2;
int  main_2CNN(
		float * __restrict__ Input_3,
		float * __restrict__ Output_1,
		float * __restrict__ Output_2)

{
	unsigned int Start_IO;
	G2_AT_GraphPerf_CNN_Total = gap_cl_readhwtimer();
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF0, *UchanHF0 = &_UchanHF0;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	/* Moving _matmul_biases (1/1), size 48 from DefaultFlash at 576 to (size 48) L2 at 150336 using event 0 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_2_L3_Flash + 576), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_2_L2_Memory_Dyn + 150336), 48, 0, UchanHF0);
	/* Moving Constant__constant_output_0 (1/1), size 576 from DefaultFlash at 0 to (size 576) L2 at 296064 using event 1 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_2_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_2_L2_Memory_Dyn + 296064), 576, 0, UchanHF1);
	G2_AT_GraphPerf[0] = gap_cl_readhwtimer();
	G2_AT_GraphPerf[11] = 0;

	for (int i=0;i<6;++i)
	fft_forwardCNN(Input_3,(float * __restrict__) (main_2_L2_Memory_Dyn+0));


	G2S3_input_3_copy(
		((float * __restrict__) (main_2_L2_Memory_Dyn+0)), /* In */
		((float * __restrict__) (main_2_L2_Memory_Dyn+297092)) /* Out */
	);
	G2_AT_GraphPerf[0] = gap_cl_readhwtimer() - G2_AT_GraphPerf[0];
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _matmul_biases using event 0 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF0);
	G2_AT_GraphPerf[1] = gap_cl_readhwtimer();
	G2_AT_GraphPerf[11] += G2_AT_GraphPerf[1] - Start_IO;
	G2S6__MatMul(
		((float * __restrict__) (main_2_L3_Memory_Dyn+148032)), /* In2 */
		((float * __restrict__) (main_2_L3_Memory_Dyn+0)), /* In1 */
		((float * __restrict__) (main_2_L2_Memory_Dyn+150336)), /* Bias */
		((float * __restrict__) (main_2_L2_Memory_Dyn+0)) /* Out */
	);
	G2_AT_GraphPerf[1] = gap_cl_readhwtimer() - G2_AT_GraphPerf[1];
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of Constant__constant_output_0 using event 1 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF1);
	G2_AT_GraphPerf[2] = gap_cl_readhwtimer();
	G2_AT_GraphPerf[11] += G2_AT_GraphPerf[2] - Start_IO;
	G2S8_expr_0(
		((float * __restrict__) (main_2_L2_Memory_Dyn+296064)), /* expr_0_in_0 */
		((float * __restrict__) (main_2_L2_Memory_Dyn+0)), /* expr_0_in_1 */
		((float * __restrict__) (main_2_L2_Memory_Dyn+148032)) /* expr_0_out_0 */
	);
	G2_AT_GraphPerf[2] = gap_cl_readhwtimer() - G2_AT_GraphPerf[2];
	G2_AT_GraphPerf[3] = gap_cl_readhwtimer();
	G2S9__ReduceSum(
		((float * __restrict__) (main_2_L2_Memory_Dyn+148032)), /* In */
		((float * __restrict__) (main_2_L2_Memory_Dyn+296064)) /* Out */
	);
	G2_AT_GraphPerf[3] = gap_cl_readhwtimer() - G2_AT_GraphPerf[3];
	G2_AT_GraphPerf[4] = gap_cl_readhwtimer();
	G2S10_expr_1(
		((float * __restrict__) (main_2_L2_Memory_Dyn+0)), /* expr_1_in_0 */
		((float * __restrict__) (main_2_L2_Memory_Dyn+296064)), /* expr_1_in_1 */
		((float * __restrict__) (main_2_L2_Memory_Dyn+148032)) /* expr_1_out_0 */
	);
	G2_AT_GraphPerf[4] = gap_cl_readhwtimer() - G2_AT_GraphPerf[4];
	G2_AT_GraphPerf[5] = gap_cl_readhwtimer();
	G2S11__Slice_tin(
		((float * __restrict__) (main_2_L2_Memory_Dyn+148032)), /* In */
		((float * __restrict__) (main_2_L2_Memory_Dyn+0)) /* Out */
	);
	G2_AT_GraphPerf[5] = gap_cl_readhwtimer() - G2_AT_GraphPerf[5];
	G2_AT_GraphPerf[6] = gap_cl_readhwtimer();
	G2S13__Slice_tout0(
		((float * __restrict__) (main_2_L2_Memory_Dyn+0)), /* In */
		((float * __restrict__) (main_2_L2_Memory_Dyn+222048)) /* Out */
	);
	G2_AT_GraphPerf[6] = gap_cl_readhwtimer() - G2_AT_GraphPerf[6];
	G2_AT_GraphPerf[7] = gap_cl_readhwtimer();
	G2S16__Slice_tout1(
		((float * __restrict__) ((main_2_L2_Memory_Dyn+0) + 74016)), /* In */
		((float * __restrict__) (main_2_L2_Memory_Dyn+148032)) /* Out */
	);
	G2_AT_GraphPerf[7] = gap_cl_readhwtimer() - G2_AT_GraphPerf[7];
	G2_AT_GraphPerf[8] = gap_cl_readhwtimer();
	G2S18_expr_2(
		((float * __restrict__) (main_2_L2_Memory_Dyn+222048)), /* expr_2_in_0 */
		((float * __restrict__) (main_2_L2_Memory_Dyn+297092)), /* expr_2_in_1 */
		((float * __restrict__) ((main_2_L2_Memory_Dyn+297092) + 6168)), /* expr_2_in_2 */
		((float * __restrict__) (main_2_L2_Memory_Dyn+148032)), /* expr_2_in_3 */
		((float * __restrict__) (main_2_L2_Memory_Dyn+6168)), /* expr_2_out_0 */
		((float * __restrict__) (main_2_L2_Memory_Dyn+0)) /* expr_2_out_1 */
	);
	G2_AT_GraphPerf[8] = gap_cl_readhwtimer() - G2_AT_GraphPerf[8];
	G2_AT_GraphPerf[9] = gap_cl_readhwtimer();
	G2S20__ReduceSum_1(
		((float * __restrict__) (main_2_L2_Memory_Dyn+6168)), /* In */
		((float * __restrict__) Output_1) /* Out */
	);
	G2_AT_GraphPerf[9] = gap_cl_readhwtimer() - G2_AT_GraphPerf[9];
	G2_AT_GraphPerf[10] = gap_cl_readhwtimer();
	G2S24__ReduceSum_2(
		((float * __restrict__) (main_2_L2_Memory_Dyn+0)), /* In */
		((float * __restrict__) Output_2) /* Out */
	);
	irfft_forwardCNN(Output_1,G2_out);
	

	G2_AT_GraphPerf[10] = gap_cl_readhwtimer() - G2_AT_GraphPerf[10];
	G2_AT_GraphPerf_CNN_Total = gap_cl_readhwtimer() - G2_AT_GraphPerf_CNN_Total;
	return 0;
}
