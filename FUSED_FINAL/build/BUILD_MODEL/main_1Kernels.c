#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "main_2Kernels.h"

#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER main_1_L1_Memory;
L2_MEM AT_L2_POINTER main_1_L2_Memory;
L2_MEM AT_L2_POINTER main_1_L2_Memory_Dyn;
AT_DEFAULTRAM_POINTER main_1_L3_Memory_Dyn;
AT_DEFAULTRAM_T DefaultRam;
static AT_DEFAULTFLASH_FS_T DefaultFlash;


void move_in_L2(int* movement_args){

	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) main_1_L2_Memory_Dyn+movement_args[0]), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0), movement_args[2], 0, DmaR_Evt1);
	AT_L2_WAIT(0,DmaR_Evt1);

	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) main_1_L2_Memory_Dyn+movement_args[1]), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0), movement_args[2], 1, DmaR_Evt1);
	AT_L2_WAIT(0,DmaR_Evt1);
}


void  S1_input_1_qout0(
		float * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	CNN_Float32Fps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 33410, Tiled: 3]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 133640 )[D0, [2 x 46272, 41096]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [2 x 46272, 41096]]
		Tile0: [0, 46272, 46272], Tile1: [46272, 46272, 46272], Tile2; [92544, 41096, 41096]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 92544 (Total Size: 33410 )[D0, [2 x 11568, 10274]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [2 x 11568, 10274]]
		Tile0: [0, 11568, 11568], Tile1: [11568, 11568, 11568], Tile2; [23136, 10274, 10274]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (main_1_L1_Memory+115680);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33412+0), 46272, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+46272), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33412+46272), 46272, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33412+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 46272, 0, DmaR_Evt1);
	_NN_In=46272; _SN_In=46272;
	_C_Out=0; _SC_Out=11568;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115680), 8, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D0Ind=0; D0Ind<3; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
			int D0Ind_Last = (D0Ind==2), D0Ind_NextLast = ((D0Ind+1)==2), D0Ind_NextNextLast = ((D0Ind+2)==2);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(D0Ind_Last)) {
				if (!(D0Ind_NextLast)) {
					_NN_In = _NN_In + (46272); _SNN_In = ((1)?41096:46272); 
				} else if (!(1)) {
					_NN_In = _NN_In + (-92544); _SNN_In = (46272); 
				}
			} else if (!((1))) {
				_NN_In = _NN_In + (46272); _SNN_In = (46272); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33412+46272*((D0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33412+46272*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+46272*((D0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_D0 =========================*/
			KerArg0->In = (float *__restrict__) (main_1_L1_Memory+0+46272*((D0Ind_Total)%2));
			KerArg0->Out = (signed char *__restrict__) (main_1_L1_Memory+92544+11568*((D0Ind_Total)%2));
			KerArg0->W = (unsigned short int) ((D0Ind_Last)?10274:11568);
			AT_FORK(gap_ncore(), (void *) CNN_Float32Fps, (void *) KerArg0);
			__CALL(CNN_Float32Fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+92544+11568*((D0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(D0Ind_Last)) {
				_C_Out = _C_Out + (11568); _SC_Out = ((D0Ind_NextLast)?10274:11568); 
			} else if (!(1)) {
				_C_Out = _C_Out + (-23136); _SC_Out = (11568); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S3__Transpose(
		signed char * __restrict__ In,
		signed char * __restrict__ Out)

{
	/* Shared L1: 66824 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 33410 )[D0, [0 x 33410, 33410]][Tile0, 1:[2x16705], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 33410, 33410]][Tile0, 1:[2x16705], 1]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33412 (Total Size: 33410 )[D0, [0 x 33410, 33410]][Tile0, 1:[2x16705], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 33410, 33410]][Tile0, 1:[2x16705], 1]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0);
	KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33412);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (2);
	KerArg0->H = (unsigned short int) (16705);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0), 33410, 0, DmaR_Evt1);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_LOOP =========================*/
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33412), 33410, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S4__enc_LN_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 33944 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 33410 )[Tile0, 1:[65x514], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[65x514], 1]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33412 (Total Size: 514 )[Tile0, 1:[1x514], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x514], 1]
		Tile0: [0, 514, 514], Tile1: [0, 514, 514], Tile2; [0, 514, 514]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33928 (Total Size: 13 )[Tile0, 1:[13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0);
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->Feat = (unsigned short int) (514);
	KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+33412);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+33928);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0), 33410, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33928), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33412), 514, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S5_expr_0(
		signed char * __restrict__ expr_0_in_0,
		signed char * __restrict__ expr_0_in_1,
		signed char * __restrict__ expr_0_out_0,
		signed char * __restrict__ expr_0_out_1)

{
	/* Shared L1: 100752 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	s5_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 514, Tiled: 1][D1 Dim: Init: 65, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_0_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 33410 )[D0, [0 x 33410, 33410]][D1, [0 x 33410, 33410]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 33410, 33410]][D1, [0 x 33410, 33410]]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	Ker Arg: expr_0_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33412 (Total Size: 514 )[D0, [0 x 514, 514]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 514, 514]]
		Tile0: [0, 514, 514], Tile1: [0, 514, 514], Tile2; [0, 514, 514]
	Ker Arg: expr_0_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33928 (Total Size: 33410 )[D0, [0 x 33410, 33410]][D1, [0 x 33410, 33410]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 33410, 33410]][D1, [0 x 33410, 33410]]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	Ker Arg: expr_0_out_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 67340 (Total Size: 33410 )[D0, [0 x 33410, 33410]][D1, [0 x 33410, 33410]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 33410, 33410]][D1, [0 x 33410, 33410]]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (514);
	KerArg0->I1 = (unsigned int) (65);
	KerArg0->expr_0_in_0 = (signed char *__restrict__ ) (main_1_L1_Memory+0);
	KerArg0->expr_0_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+33412);
	KerArg0->expr_0_out_0 = (signed char *__restrict__ ) (main_1_L1_Memory+33928);
	KerArg0->expr_0_out_1 = (signed char *__restrict__ ) (main_1_L1_Memory+67340);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0), 33410, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33412), 514, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_0_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on D1 */
			int D1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			AT_FORK(gap_ncore(), (void *) s5_kernel, (void *) KerArg0);
			__CALL(s5_kernel, KerArg0);
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_out_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33928), 33410, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_0_out_0 */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_out_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67340), 33410, 1, DmaW_Evt2);
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait DMA write expr_0_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S6__enc_LN_ReduceMean_1(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 33944 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 33410 )[Tile0, 1:[65x514], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[65x514], 1]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33412 (Total Size: 514 )[Tile0, 1:[1x514], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x514], 1]
		Tile0: [0, 514, 514], Tile1: [0, 514, 514], Tile2; [0, 514, 514]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33928 (Total Size: 13 )[Tile0, 1:[13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0);
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->Feat = (unsigned short int) (514);
	KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+33412);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+33928);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0), 33410, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33928), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33412), 514, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S9_expr_1(
		signed char * __restrict__ expr_1_in_0,
		signed char * __restrict__ expr_1_in_1,
		signed char * __restrict__ expr_1_in_2,
		signed char * __restrict__ expr_1_in_3,
		unsigned char * __restrict__ expr_1_out_0,
		unsigned int * __restrict__ RsqrtLUT)

{
	/* Shared L1: 67732 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s9_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int D1Ind, D1Ind_Last;
	int D2Ind, D2Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 2][D1 Dim: Init: 257, Tiled: 1][D2 Dim: Init: 65, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_1_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 0 (Total Size: 33410 )[D0, [1 x 16705, 16705]][D1, [0 x 16705, 16705]][D2, [0 x 16705, 16705]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 16705, 16705]][D1, [0 x 16705, 16705]][D2, [0 x 16705, 16705]]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	Ker Arg: expr_1_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 33412 (Total Size: 33410 )[D0, [1 x 16705, 16705]][D1, [0 x 16705, 16705]][D2, [0 x 16705, 16705]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 16705, 16705]][D1, [0 x 16705, 16705]][D2, [0 x 16705, 16705]]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	Ker Arg: expr_1_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 66824 (Total Size: 514 )[D0, [1 x 257, 257]][D1, [0 x 257, 257]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 257, 257]][D1, [0 x 257, 257]]
		Tile0: [0, 514, 514], Tile1: [0, 514, 514], Tile2; [0, 514, 514]
	Ker Arg: expr_1_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 67340 (Total Size: 2 )[D0, [1 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 1, 1]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: expr_1_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 67344 (Total Size: 2 )[D0, [1 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 1, 1]]
		Tile0: [0, 2, 2], Tile1: [0, 2, 2], Tile2; [0, 2, 2]
	Ker Arg: RsqrtLUT, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 67348 (Total Size: 384 )[Tile0, 1:[1x1], 384]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 384]
		Tile0: [0, 384, 384], Tile1: [0, 384, 384], Tile2; [0, 384, 384]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (2);
	KerArg0->I1 = (unsigned int) (257);
	KerArg0->I2 = (unsigned int) (65);
	KerArg0->RsqrtLUT = (unsigned int *__restrict__ ) (main_1_L1_Memory+67348);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33412), 33410, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66824), 514, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) RsqrtLUT+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67348), 384, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67340), 2, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67344), 2, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_1_in_3 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<2; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==1);
		{ /* Single iteration on D1 */
			int D1Ind_Last = 1;
			{ /* Single iteration on D2 */
				int D2Ind_Last = 1;
				{ /* Single iteration on Tile0 */
					int T0Ind_Last = 1;
				} /* End iteration on Tile0 */
				/*====================== Call Kernel LOC_D2 =========================*/
				KerArg0->expr_1_in_0 = (signed char *__restrict__ ) (main_1_L1_Memory+66824+((D0Ind)*257));
				KerArg0->expr_1_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+33412+((D0Ind)*16705));
				KerArg0->expr_1_in_2 = (signed char *__restrict__ ) (main_1_L1_Memory+67340+((D0Ind)*1));
				KerArg0->expr_1_in_3 = (signed char *__restrict__ ) (main_1_L1_Memory+67344+((D0Ind)*1));
				KerArg0->expr_1_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+((D0Ind)*16705));
				AT_FORK(gap_ncore(), (void *) s9_kernel, (void *) KerArg0);
				__CALL(s9_kernel, KerArg0);
			} /* End iteration on D2 */
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_out_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0), 33410, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_1_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S11__BN_Conv_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 66824 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 33410 )[D0, [0 x 33410, 33410]][Tile0, 1:[16705x2], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 33410, 33410]][Tile0, 1:[16705x2], 1]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33412 (Total Size: 33410 )[D0, [0 x 33410, 33410]][Tile0, 1:[16705x2], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 33410, 33410]][Tile0, 1:[16705x2], 1]
		Tile0: [0, 33410, 33410], Tile1: [0, 33410, 33410], Tile2; [0, 33410, 33410]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0);
	KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33412);
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (2);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0), 33410, 0, DmaR_Evt1);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_LOOP =========================*/
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33412), 33410, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S14__BN_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 112692 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 6][D0 Dim: Init: 2, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 0 (Total Size: 33410 )[Tile0, 6:[65x48, 4:65x48, 65x17], 2][D0, [0 x 2, 2]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 6:[65x48, 4:65x48, 65x17], 2][D0, [0 x 2, 2]]
		Tile0: [0, 6240, 6240], Tile1: [6240, 6240, 6240], Tile2; [12480, 6240, 6240]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 12480 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 12544 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 12560 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 12576 (Total Size: 256 )[D1, [0 x 256, 256]][D0, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]][D0, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 12832 (Total Size: 267280 )[Tile0, 6:[65x48, 4:65x48, 65x17], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 6:[65x48], 16]
		Tile0: [0, 49920, 49920], Tile1: [49920, 49920, 49920], Tile2; [99840, 49920, 49920]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 6 logical tiles, 1 physical tiles
			@ 112672 (Total Size: 20 )[Tile0, 6:[20x1, 4:20x1, 20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 6:[20x1, 4:20x1, 20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=49920;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 6240, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+12576), 256, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+12480), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+112672), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+12544), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+12560), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<6; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==5), T0Ind_NextLast = ((T0Ind+1)==5);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (6240); _SN_In = (((T0Ind_NextLast)?1105:3120)*(2)); 
			} else if (!(1)) {
				_N_In = _N_In + (-31200); _SN_In = (3120*(2)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+6240*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerConv1x1_SmallHW_Stride1_NE16Seq(
					(unsigned char * __restrict__) (main_1_L1_Memory+0+6240*((T0Ind_Total)%2)),  // In
					(unsigned char * __restrict__) (main_1_L1_Memory+12832+49920*((T0Ind_Total)%2)),  // Out
					(int * __restrict__) (main_1_L1_Memory+12480),  // Bias
					(unsigned char * __restrict__) (main_1_L1_Memory+12576),  // Filter
					(unsigned char * __restrict__) (main_1_L1_Memory+12544),  // Scale
					(unsigned char * __restrict__) (main_1_L1_Memory+12560),  // ScaleN
					(unsigned int) (((2) % (16))?(((2) / (16)) + (1)):((2) / (16))),  // Nb_KI
					(unsigned int) (((2) % (16))?((2) % (16)):(16)),  // Rem_KI
					(unsigned int) (((16) % (32))?(((16) / (32)) + (1)):((16) / (32))),  // Nb_KO
					(unsigned int) (((16) % (32))?((16) % (32)):(32)),  // Rem_KO
					(unsigned int) (((T0Ind_Last?17:48) * (65)) / (3)),  // Nb_HO
					(unsigned int) (((T0Ind_Last?17:48) * (65)) % (3)),  // Rem_HO
					(unsigned int) (0),  // Nb_WO
					(unsigned int) (0),  // Rem_WO
					(unsigned int) (0),  // Rem_HI
					(unsigned int) (0),  // Rem_WI
					(unsigned int) ((2) * (1)),  // InD0
					(unsigned int) (((2) * (65)) * (1)),  // InD1
					(unsigned int) (0),  // InD2
					(unsigned int) (16),  // WD0
					(unsigned int) (0),  // WD1
					(unsigned int) (0),  // WD2
					(unsigned int) (0),  // OutD0
					(unsigned int) ((16) * (1)),  // OutD1
					(unsigned int) (0),  // OutD2
					(v4s) 0,  // Pad
					(unsigned int) (130),  // PadVal
					(unsigned int) (((int *)(main_1_L1_Memory+112672))[4]),  // WOffset
					(unsigned char) ((1)),  // LastD0
					(unsigned char) ((1)),  // FirstD0
					(unsigned int) (50364503)  // NE16JobCfg
				);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+12832+49920*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (49920); _SC_Out = (((T0Ind_NextLast)?1105:3120)*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S15__BN_Conv_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 115648 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	unsigned int _LPP_Out, _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 10]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 28912], Tile1: [28912, 28912, 28912], Tile2; [57824, 28912, 28912]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57824 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 1807], Tile1: [1807, 28912, 1807], Tile2; [3614, 28912, 1807]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28912; _LC_Out=1807;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28912, 0, DmaR_Evt1);
	_N_In=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<10; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==9), T0Ind_NextLast = ((T0Ind+1)==9), T0Ind_NextNextLast = ((T0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (28912); _SN_In = ((T0Ind_NextLast)?7072:28912); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28912*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+28912*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+57824+28912*((T0Ind_Total)%2));
			KerArg0->H = (unsigned short int) (T0Ind_Last?442:1807);
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+267280+28912*((T0Ind_Total+-1)%2)),
						_SP_Out, 16705, _LP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+267280+28912*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57824+28912*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;_LPP_Out = _LP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1807); _LC_Out = ((T0Ind_NextLast)?442:1807); _SC_Out = (16*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+267280+28912*((T0Ind_Total+-1)%2)), _SP_Out, 16705, _LP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S18__conv_0_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 66832 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 16]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 16705], Tile1: [16705, 16705, 16705], Tile2; [33410, 16705, 16705]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 33416 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 1], Tile1: [1, 16705, 1], Tile2; [2, 16705, 1]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+0), 16705, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+16705), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16708), 16705, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16705, 0, DmaR_Evt1);
	_NN_In=16705; _SN_In=16705;
	_C_Out=0; _SC_Out=16705; _LC_Out=1;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<16; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==15), T0Ind_NextLast = ((T0Ind+1)==15), T0Ind_NextNextLast = ((T0Ind+2)==15);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_In = _NN_In + (16705); _SNN_In = (16705); 
				}
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16708*((T0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16708*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16708*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+16708*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33416+16708*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33416+16708*((T0Ind_Total)%2)),
					_SC_Out, 16, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1); _LC_Out = (1); _SC_Out = (16705*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S21__conv_0_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 107572 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 11][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 11 logical tiles, 11 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 11:[65x25, 9:65x26, 65x18], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 11:[65x25, 9:65x26, 65x18], 16][D0, [0 x 16, 16]]
		Tile0: [0, 26000, 26000], Tile1: [23920, 27040, 27040], Tile2; [48880, 27040, 27040]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 54080 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 54144 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 54160 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 54176 (Total Size: 2304 )[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 11 logical tiles, 11 physical tiles
			@ 56480 (Total Size: 267280 )[Tile0, 11:[65x24, 9:65x24, 65x17], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 11:[65x24], 16]
		Tile0: [0, 24960, 24960], Tile1: [24960, 24960, 24960], Tile2; [49920, 24960, 24960]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 11 logical tiles, 1 physical tiles
			@ 106400 (Total Size: 20 )[Tile0, 11:[20x1, 9:20x1, 20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 11:[20x1, 9:20x1, 20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 106420 (Total Size: 1152 )[D1, [0 x 1152, 1152]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1152, 1152]]
		Tile0: [0, 1152, 1152], Tile1: [0, 1152, 1152], Tile2; [0, 1152, 1152]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->Filter = (unsigned short * __restrict__) (main_1_L1_Memory+54176);
	KerArg2->Bias = (int * __restrict__) (main_1_L1_Memory+54080);
	KerArg2->Scale = (unsigned char * __restrict__) (main_1_L1_Memory+54144);
	KerArg2->ScaleN = (unsigned char * __restrict__) (main_1_L1_Memory+54160);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InW = (unsigned short int) (65);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutW = (unsigned short int) (65);
	KerArg2->Pad_Val = (unsigned short int) (128);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947351);
	KerArg2->BuffOut = (int * __restrict__) (main_1_L1_Memory+106420);
	KerArg2->Infos = (unsigned char * __restrict__) (main_1_L1_Memory+106400);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 26000, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=24960;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+54176), 2304, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+54080), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+106400), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+54144), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+54160), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<11; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==10), T0Ind_NextLast = ((T0Ind+1)==10);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (24960-(1040*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?1170:1690)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-248560); _SN_In = (1625*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+27040*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (main_1_L1_Memory+0+27040*((T0Ind_Total)%2));
				KerArg2->Out = (unsigned char * __restrict__) (main_1_L1_Memory+56480+24960*((T0Ind_Total)%2));
				KerArg2->Tile_InH = (unsigned short int) (((T0Ind_Last)?18:26)-1*(T0Ind==0));
				KerArg2->Tile_OutH = (unsigned short int) (T0Ind_Last?17:24);
				KerArg2->Pad = (v4s) ((v4s){1,1,1*(T0Ind==0),1*(T0Ind_Last)});
				KerArg2->W_Offset = (int) (((int *)(main_1_L1_Memory+106400))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerConv3x3Stride1Leaky_NE16, (void *) KerArg2);
				__CALL(KerConv3x3Stride1Leaky_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+56480+24960*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (24960); _SC_Out = (((T0Ind_NextLast)?1105:1560)*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S22__conv_0_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 115648 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 10]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 28912], Tile1: [28912, 28912, 28912], Tile2; [57824, 28912, 28912]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57824 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 1807], Tile1: [1807, 28912, 1807], Tile2; [3614, 28912, 1807]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28912, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=28912; _LC_Out=1807;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<10; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==9), T0Ind_NextLast = ((T0Ind+1)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (28912); _SN_In = ((T0Ind_NextLast)?7072:28912); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28912*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+28912*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+57824+28912*((T0Ind_Total)%2));
			KerArg0->H = (unsigned short int) (T0Ind_Last?442:1807);
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57824+28912*((T0Ind_Total)%2)),
					_SC_Out, 16705, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1807); _LC_Out = ((T0Ind_NextLast)?442:1807); _SC_Out = (16*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S24__conv_0_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	CNN_UFpsFps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 267280, Tiled: 10]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57840 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (main_1_L1_Memory+115680);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28920, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=28920;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115680), 8, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D0Ind=0; D0Ind<10; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
			int D0Ind_Last = (D0Ind==9), D0Ind_NextLast = ((D0Ind+1)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(D0Ind_Last)) {
				_N_In = _N_In + (28920); _SN_In = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_N_In = _N_In + (-260280); _SN_In = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28920*((D0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_D0 =========================*/
			KerArg0->In = (unsigned char *__restrict__) (main_1_L1_Memory+0+28920*((D0Ind_Total)%2));
			KerArg0->Out = (signed char *__restrict__) (main_1_L1_Memory+57840+28920*((D0Ind_Total)%2));
			KerArg0->W = (unsigned short int) ((D0Ind_Last)?7000:28920);
			AT_FORK(gap_ncore(), (void *) CNN_UFpsFpsScaled, (void *) KerArg0);
			__CALL(CNN_UFpsFpsScaled, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57840+28920*((D0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(D0Ind_Last)) {
				_C_Out = _C_Out + (28920); _SC_Out = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_C_Out = _C_Out + (-260280); _SC_Out = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S25__conv_0_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115120 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (56680); _SN_In = ((T0Ind_NextLast)?40560:56680); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S26_expr_3(
		unsigned char * __restrict__ expr_3_in_0,
		signed char * __restrict__ expr_3_in_1,
		unsigned char * __restrict__ expr_3_out_0,
		signed char * __restrict__ expr_3_out_1)

{
	/* Shared L1: 102800 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	s26_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_expr_3_in_0;
	unsigned int _SN_expr_3_in_0;
	unsigned int _LN_expr_3_in_0;
	unsigned int _C_expr_3_out_0;
	unsigned int _SP_expr_3_out_0, _SC_expr_3_out_0;
	unsigned int _LP_expr_3_out_0, _LC_expr_3_out_0;
	unsigned int _C_expr_3_out_1;
	unsigned int _SP_expr_3_out_1, _SC_expr_3_out_1;
	unsigned int _LP_expr_3_out_1, _LC_expr_3_out_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 4112, Tiled: 1][D1 Dim: Init: 65, Tiled: 17][Tile0 Dim: 1]
	Ker Arg: expr_3_in_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_3_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32896 (Total Size: 4112 )[D0, [0 x 4112, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4112, 4112]]
		Tile0: [0, 4112, 4112], Tile1: [0, 4112, 4112], Tile2; [0, 4112, 4112]
	Ker Arg: expr_3_out_0, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 37008 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_3_out_1, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 69904 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (4112);
	KerArg0->expr_3_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+32896);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_3_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16448, 65, 4, 0, DmaR_Evt1);
	_N_expr_3_in_0=0;
	_C_expr_3_out_0=0; _SC_expr_3_out_0=16448; _LC_expr_3_out_0=4;
	_SP_expr_3_out_0=0;
	_C_expr_3_out_1=0; _SC_expr_3_out_1=16448; _LC_expr_3_out_1=4;
	_SP_expr_3_out_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_3_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+32896), 4112, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_3_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1;
		for (D1Ind=0; D1Ind<17; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==16), D1Ind_NextLast = ((D1Ind+1)==16);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_3_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_3_in_0 = _N_expr_3_in_0 + (4); _LN_expr_3_in_0 = ((D1Ind_NextLast)?1:4); _SN_expr_3_in_0 = (4112*_LN_expr_3_in_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_3_in_0 */
			if (_SN_expr_3_in_0) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_3_in_0+_N_expr_3_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16448*((D1Ind_Total+1)%2)),
						1*(_SN_expr_3_in_0), 65, _LN_expr_3_in_0, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:4);
			KerArg0->expr_3_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16448*((D1Ind_Total)%2));
			KerArg0->expr_3_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+37008+16448*((D1Ind_Total)%2));
			KerArg0->expr_3_out_1 = (signed char *__restrict__ ) (main_1_L1_Memory+69904+16448*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) s26_kernel, (void *) KerArg0);
			__CALL(s26_kernel, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_3_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_3_out_0 */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_3_out_0+_C_expr_3_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+37008+16448*((D1Ind_Total)%2)),
					_SC_expr_3_out_0, 65, _LC_expr_3_out_0, 1, DmaW_Evt1);
			if (_SP_expr_3_out_1) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_3_out_1 */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_3_out_1+_C_expr_3_out_1), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+69904+16448*((D1Ind_Total)%2)),
					_SC_expr_3_out_1, 65, _LC_expr_3_out_1, 1, DmaW_Evt2);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_expr_3_out_0 = _SC_expr_3_out_0;_LP_expr_3_out_0 = _LC_expr_3_out_0;
			_SP_expr_3_out_1 = _SC_expr_3_out_1;_LP_expr_3_out_1 = _LC_expr_3_out_1;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_3_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_3_out_0 = _C_expr_3_out_0 + (4); _LC_expr_3_out_0 = ((D1Ind_NextLast)?1:4); _SC_expr_3_out_0 = (4112*_LC_expr_3_out_0); 
			}
			_SC_expr_3_out_1 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_3_out_1 = _C_expr_3_out_1 + (4); _LC_expr_3_out_1 = ((D1Ind_NextLast)?1:4); _SC_expr_3_out_1 = (4112*_LC_expr_3_out_1); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_3_out_0 */
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_3_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S27__conv_0_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT)

{
	/* Shared L1: 115504 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	expr_2_args_t S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	Ker Arg: RsqrtLUT, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115120 (Total Size: 384 )[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		Tile0: [0, 384, 384], Tile1: [0, 384, 384], Tile2; [0, 384, 384]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->Feat = (unsigned short int) (1);
	KerArg1->RsqrtLUT = (unsigned int * __restrict__) (main_1_L1_Memory+115120);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) RsqrtLUT+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115120), 384, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (56680); _SN_In = ((T0Ind_NextLast)?40560:56680); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		KerArg1->expr_2_in_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->expr_2_out_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->W = (unsigned short int) (T0Ind_Last?624:872);
		AT_FORK(gap_ncore(), (void *) expr_2, (void *) KerArg1);
		__CALL(expr_2, KerArg1);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S30_expr_6(
		unsigned char * __restrict__ expr_6_in_0,
		signed char * __restrict__ expr_6_in_1,
		signed char * __restrict__ expr_6_in_2,
		signed char * __restrict__ expr_6_in_3,
		unsigned char * __restrict__ expr_6_in_4,
		unsigned char * __restrict__ expr_6_out_0,
		unsigned char * __restrict__ expr_6_out_1)

{
	/* Shared L1: 115232 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_L2_EVENT _DmaR_Evt4, *DmaR_Evt4 = &_DmaR_Evt4;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s30_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int D2Ind, D2Ind_Total=0, D2Ind_Last, D2Ind_NextLast, D2Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_expr_6_in_0;
	unsigned int _SN_expr_6_in_0;
	unsigned int _LN_expr_6_in_0;
	unsigned int _N_expr_6_in_1;
	unsigned int _SN_expr_6_in_1;
	unsigned int _C_expr_6_out_0;
	unsigned int _SP_expr_6_out_0, _SC_expr_6_out_0;
	unsigned int _LP_expr_6_out_0, _LC_expr_6_out_0;
	unsigned int _C_expr_6_out_1;
	unsigned int _SP_expr_6_out_1, _SC_expr_6_out_1;
	unsigned int _LP_expr_6_out_1, _LC_expr_6_out_1;
	unsigned int _NN_expr_6_in_4;
	unsigned int _SN_expr_6_in_4, _SNN_expr_6_in_4;
	unsigned int _LN_expr_6_in_4, _LNN_expr_6_in_4;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 16][D1 Dim: Init: 257, Tiled: 2][D2 Dim: Init: 65, Tiled: 2][Tile0 Dim: 1]
	Ker Arg: expr_6_in_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 64 logical tiles, 64 physical tiles
			@ 0 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [1 x 14336, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [1 x 14336, 2304]]
		Tile0: [0, 14336, 56], Tile1: [56, 2304, 9], Tile2; [16640, 56, 56]
	Ker Arg: expr_6_in_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 28672 (Total Size: 4112 )[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		Tile0: [0, 256, 256], Tile1: [256, 1, 1], Tile2; [257, 256, 256]
	Ker Arg: expr_6_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 29184 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: expr_6_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 29200 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: expr_6_out_0, Tiled Space: D2
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 64 logical tiles, 64 physical tiles
			@ 29216 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [1 x 14336, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [1 x 14336, 2304]]
		Tile0: [0, 14336, 56], Tile1: [56, 2304, 9], Tile2; [16640, 56, 56]
	Ker Arg: expr_6_out_1, Tiled Space: D2
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 64 logical tiles, 64 physical tiles
			@ 57888 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [1 x 14336, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [1 x 14336, 2304]]
		Tile0: [0, 14336, 56], Tile1: [56, 2304, 9], Tile2; [16640, 56, 56]
	Ker Arg: expr_6_in_4, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 64 logical tiles, 64 physical tiles
			@ 86560 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [1 x 14336, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [1 x 14336, 2304]]
		Tile0: [0, 14336, 56], Tile1: [56, 2304, 9], Tile2; [16640, 56, 56]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_6_in_4+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+805952+0), 14336, 65, 56, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_6_in_4 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_6_in_4+56), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+805952+14336), 2304, 65, 9, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+805952+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+86560+0), 14336, 0, DmaR_Evt1);
	_NN_expr_6_in_4=56; _SN_expr_6_in_4=2304;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 14336, 65, 56, 0, DmaR_Evt2);
	_N_expr_6_in_0=0;
	_C_expr_6_out_0=0; _SC_expr_6_out_0=14336; _LC_expr_6_out_0=56;
	_SP_expr_6_out_0=0;
	_C_expr_6_out_1=0; _SC_expr_6_out_1=14336; _LC_expr_6_out_1=56;
	_SP_expr_6_out_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+28672+0), 256, 0, DmaR_Evt3);
	_N_expr_6_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+29184), 16, 0, DmaR_Evt4);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+29200), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt4); /* Wait previous DMA read expr_6_in_3 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<16; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==15), D0Ind_NextLast = ((D0Ind+1)==15), D0Ind_NextNextLast = ((D0Ind+2)==15);
		for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1), D1Ind_NextNextLast = ((D1Ind+2)==1);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_6_in_1 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_6_in_1 = _N_expr_6_in_1 + (256); _SN_expr_6_in_1 = ((1)?1:256); 
			} else if (!(D0Ind_Last)) {
				_N_expr_6_in_1 = _N_expr_6_in_1 + (257)+(-256); _SN_expr_6_in_1 = (256); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read expr_6_in_1 */
			if (_SN_expr_6_in_1) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_1+_N_expr_6_in_1), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+28672+256*((D1Ind_Total+1)%2)),
						1*(_SN_expr_6_in_1), 0, DmaR_Evt3);
			}
			/*============================= End Read Tiles ======================================*/
			for (D2Ind=0; D2Ind<2; D2Ind++, D2Ind_Total++) { /* Iteration on D2 */
				int D2Ind_Last = (D2Ind==1), D2Ind_NextLast = ((D2Ind+1)==1), D2Ind_NextNextLast = ((D2Ind+2)==1);
				/*================================= Prepare Tiles ===================================*/
				_SN_expr_6_in_0 = 0;
				if (!(D2Ind_Last)) {
					_N_expr_6_in_0 = _N_expr_6_in_0 + (56); _LN_expr_6_in_0 = ((1)?9:56); _SN_expr_6_in_0 = (((D1Ind_Last)?1:256)*_LN_expr_6_in_0); 
				} else if (!(D1Ind_Last)) {
					_N_expr_6_in_0 = _N_expr_6_in_0 + (16640)+(-56); _LN_expr_6_in_0 = (56); _SN_expr_6_in_0 = (((1)?1:256)*_LN_expr_6_in_0); 
				} else if (!(D0Ind_Last)) {
					_N_expr_6_in_0 = _N_expr_6_in_0 + (16705)+(-16640)+(-56); _LN_expr_6_in_0 = (56); _SN_expr_6_in_0 = (256*_LN_expr_6_in_0); 
				}
				_SNN_expr_6_in_4 = 0;
				if (!(D2Ind_Last)) {
					if (!(1)) {
						_NN_expr_6_in_4 = _NN_expr_6_in_4 + (56); _LNN_expr_6_in_4 = ((1)?9:56); _SNN_expr_6_in_4 = (((D1Ind_Last)?1:256)*_LNN_expr_6_in_4); 
					} else if (!(D1Ind_Last)) {
						_NN_expr_6_in_4 = _NN_expr_6_in_4 + (16640)+(-56); _LNN_expr_6_in_4 = (56); _SNN_expr_6_in_4 = (((1)?1:256)*_LNN_expr_6_in_4); 
					} else if (!(D0Ind_Last)) {
						_NN_expr_6_in_4 = _NN_expr_6_in_4 + (16705)+(-16640)+(-56); _LNN_expr_6_in_4 = (56); _SNN_expr_6_in_4 = (256*_LNN_expr_6_in_4); 
					}
				} else if (!(D1Ind_Last)) {
					_NN_expr_6_in_4 = _NN_expr_6_in_4 + (56); _LNN_expr_6_in_4 = (9); _SNN_expr_6_in_4 = (((1)?1:256)*_LNN_expr_6_in_4); 
				} else if (!(D0Ind_Last)) {
					_NN_expr_6_in_4 = _NN_expr_6_in_4 + (56); _LNN_expr_6_in_4 = (9); _SNN_expr_6_in_4 = (((D1Ind_Last)?1:256)*_LNN_expr_6_in_4); 
				}
				/*============================= End Prepare Tiles ===================================*/
				/*================================= Read Tiles ======================================*/
				AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_6_in_0 */
				if (_SN_expr_6_in_0) {
					AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_0+_N_expr_6_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+14336*((D2Ind_Total+1)%2)),
							1*(_SN_expr_6_in_0), 65, _LN_expr_6_in_0, 0, DmaR_Evt2);
				}
				AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_6_in_4 */
				AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_6_in_4 before starting the next buffer load from L3 which will overwrite this */
				if (_SNN_expr_6_in_4) {
					AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_6_in_4+_NN_expr_6_in_4), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+805952+14336*((D2Ind_Total)%2)),
							1*(_SNN_expr_6_in_4), 65, _LNN_expr_6_in_4, 0, UchanHR1);
				}
				if (_SN_expr_6_in_4) {
					AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+805952+14336*((D2Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+86560+14336*((D2Ind_Total+1)%2)),
							1*(_SN_expr_6_in_4), 0, DmaR_Evt1);
				}
				/*============================= End Read Tiles ======================================*/
				{ /* Single iteration on Tile0 */
					int T0Ind_Last = 1;
				} /* End iteration on Tile0 */
				/*====================== Call Kernel LOC_D2 =========================*/
				KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:256);
				KerArg0->I2 = (unsigned int) ((D2Ind_Last)?9:56);
				KerArg0->expr_6_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+14336*((D2Ind_Total)%2));
				KerArg0->expr_6_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+28672+256*((D1Ind_Total)%2));
				KerArg0->expr_6_in_2 = (signed char *__restrict__ ) (main_1_L1_Memory+29184+((D0Ind)*1));
				KerArg0->expr_6_in_3 = (signed char *__restrict__ ) (main_1_L1_Memory+29200+((D0Ind)*1));
				KerArg0->expr_6_in_4 = (unsigned char *__restrict__ ) (main_1_L1_Memory+86560+14336*((D2Ind_Total)%2));
				KerArg0->expr_6_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+29216+14336*((D2Ind_Total)%2));
				KerArg0->expr_6_out_1 = (unsigned char *__restrict__ ) (main_1_L1_Memory+57888+14336*((D2Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) s30_kernel, (void *) KerArg0);
				__CALL(s30_kernel, KerArg0);
				/*================================= Write Tiles =====================================*/
				if (_SP_expr_6_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_6_out_0 */
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_out_0+_C_expr_6_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+29216+14336*((D2Ind_Total)%2)),
						_SC_expr_6_out_0, 65, _LC_expr_6_out_0, 1, DmaW_Evt1);
				if (_SP_expr_6_out_1) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_6_out_1 */
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_out_1+_C_expr_6_out_1), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57888+14336*((D2Ind_Total)%2)),
						_SC_expr_6_out_1, 65, _LC_expr_6_out_1, 1, DmaW_Evt2);
				/*============================= End Write Tiles =====================================*/
				/*================================= Update Arg Pipeline =============================*/
				_SP_expr_6_out_0 = _SC_expr_6_out_0;_LP_expr_6_out_0 = _LC_expr_6_out_0;
				_SP_expr_6_out_1 = _SC_expr_6_out_1;_LP_expr_6_out_1 = _LC_expr_6_out_1;
				_SN_expr_6_in_4 = _SNN_expr_6_in_4;_LN_expr_6_in_4 = _LNN_expr_6_in_4;
				/*============================= End Update Arg Pipeline =============================*/
				/*================================= Prepare Tiles ===================================*/
				_SC_expr_6_out_0 = 0;
				if (!(D2Ind_Last)) {
					_C_expr_6_out_0 = _C_expr_6_out_0 + (56); _LC_expr_6_out_0 = ((1)?9:56); _SC_expr_6_out_0 = (((D1Ind_Last)?1:256)*_LC_expr_6_out_0); 
				} else if (!(D1Ind_Last)) {
					_C_expr_6_out_0 = _C_expr_6_out_0 + (16640)+(-56); _LC_expr_6_out_0 = (56); _SC_expr_6_out_0 = (((1)?1:256)*_LC_expr_6_out_0); 
				} else if (!(D0Ind_Last)) {
					_C_expr_6_out_0 = _C_expr_6_out_0 + (16705)+(-16640)+(-56); _LC_expr_6_out_0 = (56); _SC_expr_6_out_0 = (256*_LC_expr_6_out_0); 
				}
				_SC_expr_6_out_1 = 0;
				if (!(D2Ind_Last)) {
					_C_expr_6_out_1 = _C_expr_6_out_1 + (56); _LC_expr_6_out_1 = ((1)?9:56); _SC_expr_6_out_1 = (((D1Ind_Last)?1:256)*_LC_expr_6_out_1); 
				} else if (!(D1Ind_Last)) {
					_C_expr_6_out_1 = _C_expr_6_out_1 + (16640)+(-56); _LC_expr_6_out_1 = (56); _SC_expr_6_out_1 = (((1)?1:256)*_LC_expr_6_out_1); 
				} else if (!(D0Ind_Last)) {
					_C_expr_6_out_1 = _C_expr_6_out_1 + (16705)+(-16640)+(-56); _LC_expr_6_out_1 = (56); _SC_expr_6_out_1 = (256*_LC_expr_6_out_1); 
				}
				/*============================= End Prepare Tiles ===================================*/
			} /* End iteration on D2 */
			/*================================= Update Arg Pipeline =============================*/
			/*============================= End Update Arg Pipeline =============================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_6_out_0 */
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_6_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S32__conv_1_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 66832 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 16]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 16705], Tile1: [16705, 16705, 16705], Tile2; [33410, 16705, 16705]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 33416 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 1], Tile1: [1, 16705, 1], Tile2; [2, 16705, 1]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16705, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=16705; _LC_Out=1;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<16; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==15), T0Ind_NextLast = ((T0Ind+1)==15);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (16705); _SN_In = (16705); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16708*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+16708*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33416+16708*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33416+16708*((T0Ind_Total)%2)),
					_SC_Out, 16, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1); _LC_Out = (1); _SC_Out = (16705*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S35__conv_1_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 110580 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerConv_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerConvLinReduct_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 22][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 22 logical tiles, 22 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 22:[65x14, 20:65x16, 65x7], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 22:[65x14, 20:65x16, 65x7], 16][D0, [0 x 16, 16]]
		Tile0: [0, 14560, 14560], Tile1: [10400, 16640, 16640], Tile2; [22880, 16640, 16640]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33280 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33344 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33360 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33376 (Total Size: 2304 )[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 22 logical tiles, 1 physical tiles
			@ 35680 (Total Size: 1069120 )[Tile0, 22:[65x12, 20:65x12, 65x5], 64][D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][Tile0, 22:[65x12], 64]
		Tile0: [0, 49920, 49920], Tile1: [0, 49920, 49920], Tile2; [0, 49920, 49920]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 22 logical tiles, 22 physical tiles
			@ 85600 (Total Size: 267280 )[Tile0, 22:[65x12, 20:65x12, 65x5], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 22:[65x12], 16]
		Tile0: [0, 12480, 12480], Tile1: [12480, 12480, 12480], Tile2; [24960, 12480, 12480]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 22 logical tiles, 1 physical tiles
			@ 110560 (Total Size: 20 )[Tile0, 22:[20x1, 20:20x1, 20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 22:[20x1, 20:20x1, 20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->Filter = (unsigned short * __restrict__) (main_1_L1_Memory+33376);
	KerArg2->Bias = (int * __restrict__) (main_1_L1_Memory+33280);
	KerArg2->Out = (unsigned char * __restrict__) (main_1_L1_Memory+35680);
	KerArg2->Scale = (unsigned char * __restrict__) (main_1_L1_Memory+33344);
	KerArg2->ScaleN = (unsigned char * __restrict__) (main_1_L1_Memory+33360);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InW = (unsigned short int) (65);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutW = (unsigned short int) (65);
	KerArg2->Pad_Val = (unsigned short int) (122);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947351);
	KerArg2->Dx = (unsigned char) (2);
	KerArg2->Dy = (unsigned char) (2);
	KerArg3->In = (int *__restrict__) (main_1_L1_Memory+35680);
	KerArg3->Feat = (unsigned short int) (16);
	KerArg3->W = (unsigned short int) (65);
	KerArg3->Scale = (unsigned char *__restrict__) (main_1_L1_Memory+33344);
	KerArg3->ScaleN = (unsigned char *__restrict__) (main_1_L1_Memory+33360);
	KerArg3->Infos = (signed char *__restrict__) (main_1_L1_Memory+110560);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=12480;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 14560, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33376), 2304, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+110560), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33344), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33360), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1, D1Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<22; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==21), T0Ind_NextLast = ((T0Ind+1)==21), T0Ind_NextNextLast = ((T0Ind+2)==21);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (12480-(2080*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?455:1040)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-260000); _SN_In = (910*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16640*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (main_1_L1_Memory+0+16640*((T0Ind_Total)%2));
				KerArg2->Tile_InH = (unsigned short int) (((T0Ind_Last)?7:16)-2*(T0Ind==0));
				KerArg2->Tile_OutH = (unsigned short int) (T0Ind_Last?5:12);
				KerArg2->Pad = (v4s) ((v4s){2,2,2*(T0Ind==0),2*(T0Ind_Last)});
				KerArg2->W_Offset = (int) (((int *)(main_1_L1_Memory+110560))[4]);
				KerConv3x3Stride1_DxDy_NE16(KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg3->Out = (void *__restrict__) (main_1_L1_Memory+85600+12480*((T0Ind_Total)%2));
			KerArg3->H = (unsigned short int) (T0Ind_Last?5:12);
			AT_FORK(gap_ncore(), (void *) KerReduct_CC_NoScale_LeakyReLU_USQ8, (void *) KerArg3);
			__CALL(KerReduct_CC_NoScale_LeakyReLU_USQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+12480*((T0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+12480*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+85600+12480*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (12480); _SC_Out = (((T0Ind_NextLast)?325:780)*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+12480*((T0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S36__conv_1_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 115648 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 10]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 28912], Tile1: [28912, 28912, 28912], Tile2; [57824, 28912, 28912]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57824 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 1807], Tile1: [1807, 28912, 1807], Tile2; [3614, 28912, 1807]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 28912, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+28912), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912), 28912, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28912, 0, DmaR_Evt1);
	_NN_In=28912; _SN_In=28912;
	_C_Out=0; _SC_Out=28912; _LC_Out=1807;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<10; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==9), T0Ind_NextLast = ((T0Ind+1)==9), T0Ind_NextNextLast = ((T0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_In = _NN_In + (28912); _SNN_In = ((T0Ind_NextNextLast)?7072:28912); 
				}
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912*((T0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28912*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+28912*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+57824+28912*((T0Ind_Total)%2));
			KerArg0->H = (unsigned short int) (T0Ind_Last?442:1807);
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57824+28912*((T0Ind_Total)%2)),
					_SC_Out, 16705, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1807); _LC_Out = ((T0Ind_NextLast)?442:1807); _SC_Out = (16*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S38__conv_1_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	CNN_UFpsFps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 267280, Tiled: 10]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57840 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (main_1_L1_Memory+115680);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28920;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28920, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115680), 8, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D0Ind=0; D0Ind<10; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
			int D0Ind_Last = (D0Ind==9), D0Ind_NextLast = ((D0Ind+1)==9), D0Ind_NextNextLast = ((D0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(D0Ind_Last)) {
				_N_In = _N_In + (28920); _SN_In = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_N_In = _N_In + (-260280); _SN_In = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28920*((D0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_D0 =========================*/
			KerArg0->In = (unsigned char *__restrict__) (main_1_L1_Memory+0+28920*((D0Ind_Total)%2));
			KerArg0->Out = (signed char *__restrict__) (main_1_L1_Memory+57840+28920*((D0Ind_Total)%2));
			KerArg0->W = (unsigned short int) ((D0Ind_Last)?7000:28920);
			AT_FORK(gap_ncore(), (void *) CNN_UFpsFpsScaled, (void *) KerArg0);
			__CALL(CNN_UFpsFpsScaled, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57840+28920*((D0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(D0Ind_Last)) {
				_C_Out = _C_Out + (28920); _SC_Out = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_C_Out = _C_Out + (-260280); _SC_Out = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S39__conv_1_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115120 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S40_expr_7(
		unsigned char * __restrict__ expr_7_in_0,
		signed char * __restrict__ expr_7_in_1,
		unsigned char * __restrict__ expr_7_out_0,
		signed char * __restrict__ expr_7_out_1)

{
	/* Shared L1: 102800 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	s40_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_expr_7_in_0;
	unsigned int _SN_expr_7_in_0;
	unsigned int _LN_expr_7_in_0;
	unsigned int _P_expr_7_out_0, _C_expr_7_out_0;
	unsigned int _SPP_expr_7_out_0, _SP_expr_7_out_0, _SC_expr_7_out_0;
	unsigned int _LPP_expr_7_out_0, _LP_expr_7_out_0, _LC_expr_7_out_0;
	unsigned int _P_expr_7_out_1, _C_expr_7_out_1;
	unsigned int _SPP_expr_7_out_1, _SP_expr_7_out_1, _SC_expr_7_out_1;
	unsigned int _LPP_expr_7_out_1, _LP_expr_7_out_1, _LC_expr_7_out_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 4112, Tiled: 1][D1 Dim: Init: 65, Tiled: 17][Tile0 Dim: 1]
	Ker Arg: expr_7_in_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_7_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32896 (Total Size: 4112 )[D0, [0 x 4112, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4112, 4112]]
		Tile0: [0, 4112, 4112], Tile1: [0, 4112, 4112], Tile2; [0, 4112, 4112]
	Ker Arg: expr_7_out_0, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 37008 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_7_out_1, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 69904 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (4112);
	KerArg0->expr_7_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+32896);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_7_out_0=0; _SC_expr_7_out_0=16448; _LC_expr_7_out_0=4;
	_SPP_expr_7_out_0=0; _SP_expr_7_out_0=0;
	_C_expr_7_out_1=0; _SC_expr_7_out_1=16448; _LC_expr_7_out_1=4;
	_SPP_expr_7_out_1=0; _SP_expr_7_out_1=0;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16448, 65, 4, 0, DmaR_Evt1);
	_N_expr_7_in_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+32896), 4112, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_7_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (D1Ind=0; D1Ind<17; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==16), D1Ind_NextLast = ((D1Ind+1)==16), D1Ind_NextNextLast = ((D1Ind+2)==16);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_7_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_7_in_0 = _N_expr_7_in_0 + (4); _LN_expr_7_in_0 = ((D1Ind_NextLast)?1:4); _SN_expr_7_in_0 = (4112*_LN_expr_7_in_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_7_in_0 */
			if (_SN_expr_7_in_0) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_in_0+_N_expr_7_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16448*((D1Ind_Total+1)%2)),
						1*(_SN_expr_7_in_0), 65, _LN_expr_7_in_0, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:4);
			KerArg0->expr_7_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16448*((D1Ind_Total)%2));
			KerArg0->expr_7_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+37008+16448*((D1Ind_Total)%2));
			KerArg0->expr_7_out_1 = (signed char *__restrict__ ) (main_1_L1_Memory+69904+16448*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) s40_kernel, (void *) KerArg0);
			__CALL(s40_kernel, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_7_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_7_out_0 */
			if (_SPP_expr_7_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_7_out_0 */
			if (_SP_expr_7_out_0) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_7_out_0+_P_expr_7_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_7_out_0, 65, _LP_expr_7_out_0, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+37008+16448*((D1Ind_Total)%2)),
					_SC_expr_7_out_0, 1, DmaW_Evt1);
			if (_SP_expr_7_out_1) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_7_out_1 */
			if (_SPP_expr_7_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_7_out_1 */
			if (_SP_expr_7_out_1) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_7_out_1+_P_expr_7_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_7_out_1, 65, _LP_expr_7_out_1, 1, UchanHR2);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+69904+16448*((D1Ind_Total)%2)),
					_SC_expr_7_out_1, 1, DmaW_Evt2);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_7_out_0 = _SP_expr_7_out_0;_LPP_expr_7_out_0 = _LP_expr_7_out_0;
			_P_expr_7_out_0 = _C_expr_7_out_0;_SP_expr_7_out_0 = _SC_expr_7_out_0;_LP_expr_7_out_0 = _LC_expr_7_out_0;
			_SPP_expr_7_out_1 = _SP_expr_7_out_1;_LPP_expr_7_out_1 = _LP_expr_7_out_1;
			_P_expr_7_out_1 = _C_expr_7_out_1;_SP_expr_7_out_1 = _SC_expr_7_out_1;_LP_expr_7_out_1 = _LC_expr_7_out_1;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_7_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_7_out_0 = _C_expr_7_out_0 + (4); _LC_expr_7_out_0 = ((D1Ind_NextLast)?1:4); _SC_expr_7_out_0 = (4112*_LC_expr_7_out_0); 
			}
			_SC_expr_7_out_1 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_7_out_1 = _C_expr_7_out_1 + (4); _LC_expr_7_out_1 = ((D1Ind_NextLast)?1:4); _SC_expr_7_out_1 = (4112*_LC_expr_7_out_1); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_7_out_0 */
	if (_SPP_expr_7_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_7_out_0 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_7_out_0+_P_expr_7_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total+-1)%2)), _SP_expr_7_out_0, 65, _LP_expr_7_out_0, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write expr_7_out_0 */
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_7_out_1 */
	if (_SPP_expr_7_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_7_out_1 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_7_out_1+_P_expr_7_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)), _SP_expr_7_out_1, 65, _LP_expr_7_out_1, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_7_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S41__conv_1_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT)

{
	/* Shared L1: 115504 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	expr_5_args_t S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	Ker Arg: RsqrtLUT, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115120 (Total Size: 384 )[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		Tile0: [0, 384, 384], Tile1: [0, 384, 384], Tile2; [0, 384, 384]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->Feat = (unsigned short int) (1);
	KerArg1->RsqrtLUT = (unsigned int * __restrict__) (main_1_L1_Memory+115120);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) RsqrtLUT+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115120), 384, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		KerArg1->expr_5_in_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->expr_5_out_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->W = (unsigned short int) (T0Ind_Last?624:872);
		AT_FORK(gap_ncore(), (void *) expr_5, (void *) KerArg1);
		__CALL(expr_5, KerArg1);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S44_expr_8(
		unsigned char * __restrict__ expr_8_in_0,
		signed char * __restrict__ expr_8_in_1,
		signed char * __restrict__ expr_8_in_2,
		signed char * __restrict__ expr_8_in_3,
		unsigned char * __restrict__ expr_8_out_0)

{
	/* Shared L1: 67104 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s44_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int D2Ind, D2Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _P_expr_8_out_0, _C_expr_8_out_0;
	unsigned int _SPP_expr_8_out_0, _SP_expr_8_out_0, _SC_expr_8_out_0;
	unsigned int _NN_expr_8_in_0;
	unsigned int _SN_expr_8_in_0, _SNN_expr_8_in_0;
	unsigned int _N_expr_8_in_1;
	unsigned int _SN_expr_8_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 16][D1 Dim: Init: 257, Tiled: 2][D2 Dim: Init: 65, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_8_out_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 0 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_8_in_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 33280 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_8_in_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 66560 (Total Size: 4112 )[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		Tile0: [0, 256, 256], Tile1: [256, 1, 1], Tile2; [257, 256, 256]
	Ker Arg: expr_8_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67072 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: expr_8_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67088 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1);
	KerArg0->I2 = (unsigned int) (65);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_8_out_0=0; _SC_expr_8_out_0=16640;
	_SPP_expr_8_out_0=0; _SP_expr_8_out_0=0;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_8_in_0+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+0), 16640, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_8_in_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_8_in_0+16640), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+16640), 65, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+0), 16640, 0, DmaR_Evt1);
	_NN_expr_8_in_0=16640; _SN_expr_8_in_0=65;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_8_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+0), 256, 0, DmaR_Evt2);
	_N_expr_8_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_8_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67072), 16, 0, DmaR_Evt3);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_8_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67088), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read expr_8_in_3 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<16; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==15), D0Ind_NextLast = ((D0Ind+1)==15), D0Ind_NextNextLast = ((D0Ind+2)==15);
		for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1), D1Ind_NextNextLast = ((D1Ind+2)==1);
			/*================================= Prepare Tiles ===================================*/
			_SNN_expr_8_in_0 = 0;
			if (!(D1Ind_Last)) {
				if (!(1)) {
					_NN_expr_8_in_0 = _NN_expr_8_in_0 + (16640); _SNN_expr_8_in_0 = (((1)?1:256)*(65)); 
				} else if (!(D0Ind_Last)) {
					_NN_expr_8_in_0 = _NN_expr_8_in_0 + (16705)+(-16640); _SNN_expr_8_in_0 = (256*(65)); 
				}
			} else if (!(D0Ind_Last)) {
				_NN_expr_8_in_0 = _NN_expr_8_in_0 + 0; _SNN_expr_8_in_0 = (((D1Ind_Last)?1:256)*(65)); 
			}
			_SN_expr_8_in_1 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_8_in_1 = _N_expr_8_in_1 + (256); _SN_expr_8_in_1 = ((1)?1:256); 
			} else if (!(D0Ind_Last)) {
				_N_expr_8_in_1 = _N_expr_8_in_1 + (257)+(-256); _SN_expr_8_in_1 = (256); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_8_in_0 */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_8_in_0 before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_expr_8_in_0) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_8_in_0+_NN_expr_8_in_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+16640*((D1Ind_Total)%2)),
						1*(_SNN_expr_8_in_0), 0, UchanHR1);
			}
			if (_SN_expr_8_in_0) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+16640*((D1Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+16640*((D1Ind_Total+1)%2)),
						1*(_SN_expr_8_in_0), 0, DmaR_Evt1);
			}
			AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_8_in_1 */
			if (_SN_expr_8_in_1) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_8_in_1+_N_expr_8_in_1), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+256*((D1Ind_Total+1)%2)),
						1*(_SN_expr_8_in_1), 0, DmaR_Evt2);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D2 */
				int D2Ind_Last = 1;
				{ /* Single iteration on Tile0 */
					int T0Ind_Last = 1;
				} /* End iteration on Tile0 */
				/*====================== Call Kernel LOC_D2 =========================*/
				KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:256);
				KerArg0->expr_8_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+33280+16640*((D1Ind_Total)%2));
				KerArg0->expr_8_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+66560+256*((D1Ind_Total)%2));
				KerArg0->expr_8_in_2 = (signed char *__restrict__ ) (main_1_L1_Memory+67072+((D0Ind)*1));
				KerArg0->expr_8_in_3 = (signed char *__restrict__ ) (main_1_L1_Memory+67088+((D0Ind)*1));
				KerArg0->expr_8_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16640*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) s44_kernel, (void *) KerArg0);
				__CALL(s44_kernel, KerArg0);
			} /* End iteration on D2 */
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_8_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_8_out_0 */
			if (_SPP_expr_8_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_8_out_0 */
			if (_SP_expr_8_out_0) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_8_out_0+_P_expr_8_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+16640*((D1Ind_Total+-1)%2)),
						_SP_expr_8_out_0, 1, UchanHR2);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+16640*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16640*((D1Ind_Total)%2)),
					_SC_expr_8_out_0, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_8_out_0 = _SP_expr_8_out_0;
			_P_expr_8_out_0 = _C_expr_8_out_0;_SP_expr_8_out_0 = _SC_expr_8_out_0;
			_SN_expr_8_in_0 = _SNN_expr_8_in_0;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_8_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_8_out_0 = _C_expr_8_out_0 + (16640); _SC_expr_8_out_0 = (((1)?1:256)*(65)); 
			} else if (!(D0Ind_Last)) {
				_C_expr_8_out_0 = _C_expr_8_out_0 + (16705)+(-16640); _SC_expr_8_out_0 = (256*(65)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_8_out_0 */
	if (_SPP_expr_8_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_8_out_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_8_out_0+_P_expr_8_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+16640*((D1Ind_Total+-1)%2)), _SP_expr_8_out_0, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_8_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S45_expr_9(
		unsigned char * __restrict__ expr_9_in_0,
		unsigned char * __restrict__ expr_9_in_1,
		unsigned char * __restrict__ expr_9_out_0)

{
	/* Shared L1: 115680 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s45_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_9_out_0;
	unsigned int _SP_expr_9_out_0, _SC_expr_9_out_0;
	unsigned int _N_expr_9_in_0;
	unsigned int _SN_expr_9_in_0;
	unsigned int _NN_expr_9_in_1;
	unsigned int _SN_expr_9_in_1, _SNN_expr_9_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 267280, Tiled: 14][Tile0 Dim: 1]
	Ker Arg: expr_9_out_0, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 0 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_9_in_0, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 38560 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_9_in_1, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 77120 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_9_in_1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 19280, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_9_in_1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_9_in_1+19280), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280), 19280, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+0), 19280, 0, DmaR_Evt1);
	_NN_expr_9_in_1=19280; _SN_expr_9_in_1=19280;
	_C_expr_9_out_0=0; _SC_expr_9_out_0=19280;
	_SP_expr_9_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_9_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+0), 19280, 0, DmaR_Evt2);
	_N_expr_9_in_0=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<14; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==13), D0Ind_NextLast = ((D0Ind+1)==13), D0Ind_NextNextLast = ((D0Ind+2)==13);
		/*================================= Prepare Tiles ===================================*/
		_SN_expr_9_in_0 = 0;
		if (!(D0Ind_Last)) {
			_N_expr_9_in_0 = _N_expr_9_in_0 + (19280); _SN_expr_9_in_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		_SNN_expr_9_in_1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_9_in_1 = _NN_expr_9_in_1 + (19280); _SNN_expr_9_in_1 = ((D0Ind_NextNextLast)?16640:19280); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_9_in_0 */
		if (_SN_expr_9_in_0) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_9_in_0+_N_expr_9_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_9_in_0), 0, DmaR_Evt2);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_9_in_1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_9_in_1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_9_in_1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_9_in_1+_NN_expr_9_in_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280*((D0Ind_Total)%2)),
					1*(_SNN_expr_9_in_1), 0, UchanHR1);
		}
		if (_SN_expr_9_in_1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_9_in_1), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		KerArg0->I0 = (unsigned int) ((D0Ind_Last)?16640:19280);
		KerArg0->expr_9_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+38560+19280*((D0Ind_Total)%2));
		KerArg0->expr_9_in_1 = (unsigned char *__restrict__ ) (main_1_L1_Memory+77120+19280*((D0Ind_Total)%2));
		KerArg0->expr_9_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+19280*((D0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) s45_kernel, (void *) KerArg0);
		__CALL(s45_kernel, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_expr_9_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_9_out_0 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_9_out_0+_C_expr_9_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+19280*((D0Ind_Total)%2)),
				_SC_expr_9_out_0, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_expr_9_out_0 = _SC_expr_9_out_0;
		_SN_expr_9_in_1 = _SNN_expr_9_in_1;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_expr_9_out_0 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_9_out_0 = _C_expr_9_out_0 + (19280); _SC_expr_9_out_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_9_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S47__conv_2_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 66832 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 16]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 16705], Tile1: [16705, 16705, 16705], Tile2; [33410, 16705, 16705]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 33416 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 1], Tile1: [1, 16705, 1], Tile2; [2, 16705, 1]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16705, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=16705; _LC_Out=1;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<16; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==15), T0Ind_NextLast = ((T0Ind+1)==15);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (16705); _SN_In = (16705); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16708*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+16708*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33416+16708*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33416+16708*((T0Ind_Total)%2)),
					_SC_Out, 16, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1); _LC_Out = (1); _SC_Out = (16705*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S50__conv_2_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 93940 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerConv_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerConvLinReduct_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 29][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 29 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 29:[65x13, 27:65x17, 65x9], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 29:[65x13, 27:65x17, 65x9], 16][D0, [0 x 16, 16]]
		Tile0: [0, 13520, 13520], Tile1: [5200, 17680, 17680], Tile2; [14560, 17680, 17680]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 35360 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 35424 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 35440 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 35456 (Total Size: 2304 )[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 1 physical tiles
			@ 37760 (Total Size: 1069120 )[Tile0, 29:[65x9, 27:65x9, 65x5], 64][D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][Tile0, 29:[65x9], 64]
		Tile0: [0, 37440, 37440], Tile1: [0, 37440, 37440], Tile2; [0, 37440, 37440]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 29 logical tiles, 29 physical tiles
			@ 75200 (Total Size: 267280 )[Tile0, 29:[65x9, 27:65x9, 65x5], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 29:[65x9], 16]
		Tile0: [0, 9360, 9360], Tile1: [9360, 9360, 9360], Tile2; [18720, 9360, 9360]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 1 physical tiles
			@ 93920 (Total Size: 20 )[Tile0, 29:[20x1, 27:20x1, 20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 29:[20x1, 27:20x1, 20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->Filter = (unsigned short * __restrict__) (main_1_L1_Memory+35456);
	KerArg2->Bias = (int * __restrict__) (main_1_L1_Memory+35360);
	KerArg2->Out = (unsigned char * __restrict__) (main_1_L1_Memory+37760);
	KerArg2->Scale = (unsigned char * __restrict__) (main_1_L1_Memory+35424);
	KerArg2->ScaleN = (unsigned char * __restrict__) (main_1_L1_Memory+35440);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InW = (unsigned short int) (65);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutW = (unsigned short int) (65);
	KerArg2->Pad_Val = (unsigned short int) (111);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947351);
	KerArg2->Dx = (unsigned char) (4);
	KerArg2->Dy = (unsigned char) (4);
	KerArg3->In = (int *__restrict__) (main_1_L1_Memory+37760);
	KerArg3->Feat = (unsigned short int) (16);
	KerArg3->W = (unsigned short int) (65);
	KerArg3->Scale = (unsigned char *__restrict__) (main_1_L1_Memory+35424);
	KerArg3->ScaleN = (unsigned char *__restrict__) (main_1_L1_Memory+35440);
	KerArg3->Infos = (signed char *__restrict__) (main_1_L1_Memory+93920);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=9360;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 13520, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+35456), 2304, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+35360), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+93920), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+35424), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+35440), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1, D1Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<29; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==28), T0Ind_NextLast = ((T0Ind+1)==28), T0Ind_NextNextLast = ((T0Ind+2)==28);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (9360-(4160*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?585:1105)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-257920); _SN_In = (845*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+17680*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (main_1_L1_Memory+0+17680*((T0Ind_Total)%2));
				KerArg2->Tile_InH = (unsigned short int) (((T0Ind_Last)?9:17)-4*(T0Ind==0));
				KerArg2->Tile_OutH = (unsigned short int) (T0Ind_Last?5:9);
				KerArg2->Pad = (v4s) ((v4s){4,4,4*(T0Ind==0),4*(T0Ind_Last)});
				KerArg2->W_Offset = (int) (((int *)(main_1_L1_Memory+93920))[4]);
				KerConv3x3Stride1_DxDy_NE16(KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg3->Out = (void *__restrict__) (main_1_L1_Memory+75200+9360*((T0Ind_Total)%2));
			KerArg3->H = (unsigned short int) (T0Ind_Last?5:9);
			AT_FORK(gap_ncore(), (void *) KerReduct_CC_NoScale_LeakyReLU_USQ8, (void *) KerArg3);
			__CALL(KerReduct_CC_NoScale_LeakyReLU_USQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+9360*((T0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+9360*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+75200+9360*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (9360); _SC_Out = (((T0Ind_NextLast)?325:585)*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+9360*((T0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S51__conv_2_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 115648 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 10]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 28912], Tile1: [28912, 28912, 28912], Tile2; [57824, 28912, 28912]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57824 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 1807], Tile1: [1807, 28912, 1807], Tile2; [3614, 28912, 1807]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 28912, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+28912), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912), 28912, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28912, 0, DmaR_Evt1);
	_NN_In=28912; _SN_In=28912;
	_C_Out=0; _SC_Out=28912; _LC_Out=1807;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<10; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==9), T0Ind_NextLast = ((T0Ind+1)==9), T0Ind_NextNextLast = ((T0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_In = _NN_In + (28912); _SNN_In = ((T0Ind_NextNextLast)?7072:28912); 
				}
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912*((T0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28912*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+28912*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+57824+28912*((T0Ind_Total)%2));
			KerArg0->H = (unsigned short int) (T0Ind_Last?442:1807);
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57824+28912*((T0Ind_Total)%2)),
					_SC_Out, 16705, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1807); _LC_Out = ((T0Ind_NextLast)?442:1807); _SC_Out = (16*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S53__conv_2_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	CNN_UFpsFps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 267280, Tiled: 10]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57840 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (main_1_L1_Memory+115680);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28920;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28920, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115680), 8, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D0Ind=0; D0Ind<10; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
			int D0Ind_Last = (D0Ind==9), D0Ind_NextLast = ((D0Ind+1)==9), D0Ind_NextNextLast = ((D0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(D0Ind_Last)) {
				_N_In = _N_In + (28920); _SN_In = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_N_In = _N_In + (-260280); _SN_In = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28920*((D0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_D0 =========================*/
			KerArg0->In = (unsigned char *__restrict__) (main_1_L1_Memory+0+28920*((D0Ind_Total)%2));
			KerArg0->Out = (signed char *__restrict__) (main_1_L1_Memory+57840+28920*((D0Ind_Total)%2));
			KerArg0->W = (unsigned short int) ((D0Ind_Last)?7000:28920);
			AT_FORK(gap_ncore(), (void *) CNN_UFpsFpsScaled, (void *) KerArg0);
			__CALL(CNN_UFpsFpsScaled, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57840+28920*((D0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(D0Ind_Last)) {
				_C_Out = _C_Out + (28920); _SC_Out = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_C_Out = _C_Out + (-260280); _SC_Out = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S54__conv_2_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115120 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S55_expr_12(
		unsigned char * __restrict__ expr_12_in_0,
		signed char * __restrict__ expr_12_in_1,
		unsigned char * __restrict__ expr_12_out_0,
		signed char * __restrict__ expr_12_out_1)

{
	/* Shared L1: 102800 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	s55_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_expr_12_in_0;
	unsigned int _SN_expr_12_in_0;
	unsigned int _LN_expr_12_in_0;
	unsigned int _P_expr_12_out_0, _C_expr_12_out_0;
	unsigned int _SPP_expr_12_out_0, _SP_expr_12_out_0, _SC_expr_12_out_0;
	unsigned int _LPP_expr_12_out_0, _LP_expr_12_out_0, _LC_expr_12_out_0;
	unsigned int _P_expr_12_out_1, _C_expr_12_out_1;
	unsigned int _SPP_expr_12_out_1, _SP_expr_12_out_1, _SC_expr_12_out_1;
	unsigned int _LPP_expr_12_out_1, _LP_expr_12_out_1, _LC_expr_12_out_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 4112, Tiled: 1][D1 Dim: Init: 65, Tiled: 17][Tile0 Dim: 1]
	Ker Arg: expr_12_in_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_12_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32896 (Total Size: 4112 )[D0, [0 x 4112, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4112, 4112]]
		Tile0: [0, 4112, 4112], Tile1: [0, 4112, 4112], Tile2; [0, 4112, 4112]
	Ker Arg: expr_12_out_0, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 37008 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_12_out_1, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 69904 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (4112);
	KerArg0->expr_12_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+32896);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_12_out_0=0; _SC_expr_12_out_0=16448; _LC_expr_12_out_0=4;
	_SPP_expr_12_out_0=0; _SP_expr_12_out_0=0;
	_C_expr_12_out_1=0; _SC_expr_12_out_1=16448; _LC_expr_12_out_1=4;
	_SPP_expr_12_out_1=0; _SP_expr_12_out_1=0;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_12_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16448, 65, 4, 0, DmaR_Evt1);
	_N_expr_12_in_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_12_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+32896), 4112, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_12_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (D1Ind=0; D1Ind<17; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==16), D1Ind_NextLast = ((D1Ind+1)==16), D1Ind_NextNextLast = ((D1Ind+2)==16);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_12_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_12_in_0 = _N_expr_12_in_0 + (4); _LN_expr_12_in_0 = ((D1Ind_NextLast)?1:4); _SN_expr_12_in_0 = (4112*_LN_expr_12_in_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_12_in_0 */
			if (_SN_expr_12_in_0) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_12_in_0+_N_expr_12_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16448*((D1Ind_Total+1)%2)),
						1*(_SN_expr_12_in_0), 65, _LN_expr_12_in_0, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:4);
			KerArg0->expr_12_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16448*((D1Ind_Total)%2));
			KerArg0->expr_12_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+37008+16448*((D1Ind_Total)%2));
			KerArg0->expr_12_out_1 = (signed char *__restrict__ ) (main_1_L1_Memory+69904+16448*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) s55_kernel, (void *) KerArg0);
			__CALL(s55_kernel, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_12_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_12_out_0 */
			if (_SPP_expr_12_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_12_out_0 */
			if (_SP_expr_12_out_0) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_12_out_0+_P_expr_12_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_12_out_0, 65, _LP_expr_12_out_0, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+37008+16448*((D1Ind_Total)%2)),
					_SC_expr_12_out_0, 1, DmaW_Evt1);
			if (_SP_expr_12_out_1) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_12_out_1 */
			if (_SPP_expr_12_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_12_out_1 */
			if (_SP_expr_12_out_1) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_12_out_1+_P_expr_12_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_12_out_1, 65, _LP_expr_12_out_1, 1, UchanHR2);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+69904+16448*((D1Ind_Total)%2)),
					_SC_expr_12_out_1, 1, DmaW_Evt2);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_12_out_0 = _SP_expr_12_out_0;_LPP_expr_12_out_0 = _LP_expr_12_out_0;
			_P_expr_12_out_0 = _C_expr_12_out_0;_SP_expr_12_out_0 = _SC_expr_12_out_0;_LP_expr_12_out_0 = _LC_expr_12_out_0;
			_SPP_expr_12_out_1 = _SP_expr_12_out_1;_LPP_expr_12_out_1 = _LP_expr_12_out_1;
			_P_expr_12_out_1 = _C_expr_12_out_1;_SP_expr_12_out_1 = _SC_expr_12_out_1;_LP_expr_12_out_1 = _LC_expr_12_out_1;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_12_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_12_out_0 = _C_expr_12_out_0 + (4); _LC_expr_12_out_0 = ((D1Ind_NextLast)?1:4); _SC_expr_12_out_0 = (4112*_LC_expr_12_out_0); 
			}
			_SC_expr_12_out_1 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_12_out_1 = _C_expr_12_out_1 + (4); _LC_expr_12_out_1 = ((D1Ind_NextLast)?1:4); _SC_expr_12_out_1 = (4112*_LC_expr_12_out_1); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_12_out_0 */
	if (_SPP_expr_12_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_12_out_0 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_12_out_0+_P_expr_12_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)), _SP_expr_12_out_0, 65, _LP_expr_12_out_0, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write expr_12_out_0 */
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_12_out_1 */
	if (_SPP_expr_12_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_12_out_1 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_12_out_1+_P_expr_12_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total+-1)%2)), _SP_expr_12_out_1, 65, _LP_expr_12_out_1, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_12_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S56__conv_2_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT)

{
	/* Shared L1: 115504 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	expr_10_args_t S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	Ker Arg: RsqrtLUT, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115120 (Total Size: 384 )[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		Tile0: [0, 384, 384], Tile1: [0, 384, 384], Tile2; [0, 384, 384]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->Feat = (unsigned short int) (1);
	KerArg1->RsqrtLUT = (unsigned int * __restrict__) (main_1_L1_Memory+115120);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) RsqrtLUT+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115120), 384, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		KerArg1->expr_10_in_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->expr_10_out_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->W = (unsigned short int) (T0Ind_Last?624:872);
		AT_FORK(gap_ncore(), (void *) expr_10, (void *) KerArg1);
		__CALL(expr_10, KerArg1);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S59_expr_13(
		unsigned char * __restrict__ expr_13_in_0,
		signed char * __restrict__ expr_13_in_1,
		signed char * __restrict__ expr_13_in_2,
		signed char * __restrict__ expr_13_in_3,
		unsigned char * __restrict__ expr_13_out_0)

{
	/* Shared L1: 67104 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s59_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int D2Ind, D2Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _P_expr_13_out_0, _C_expr_13_out_0;
	unsigned int _SPP_expr_13_out_0, _SP_expr_13_out_0, _SC_expr_13_out_0;
	unsigned int _NN_expr_13_in_0;
	unsigned int _SN_expr_13_in_0, _SNN_expr_13_in_0;
	unsigned int _N_expr_13_in_1;
	unsigned int _SN_expr_13_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 16][D1 Dim: Init: 257, Tiled: 2][D2 Dim: Init: 65, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_13_out_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 0 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_13_in_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 33280 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_13_in_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 66560 (Total Size: 4112 )[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		Tile0: [0, 256, 256], Tile1: [256, 1, 1], Tile2; [257, 256, 256]
	Ker Arg: expr_13_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67072 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: expr_13_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67088 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1);
	KerArg0->I2 = (unsigned int) (65);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_13_out_0=0; _SC_expr_13_out_0=16640;
	_SPP_expr_13_out_0=0; _SP_expr_13_out_0=0;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_13_in_0+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33280+0), 16640, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_13_in_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_13_in_0+16640), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33280+16640), 65, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33280+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+0), 16640, 0, DmaR_Evt1);
	_NN_expr_13_in_0=16640; _SN_expr_13_in_0=65;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_13_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+0), 256, 0, DmaR_Evt2);
	_N_expr_13_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_13_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67072), 16, 0, DmaR_Evt3);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_13_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67088), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read expr_13_in_3 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<16; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==15), D0Ind_NextLast = ((D0Ind+1)==15), D0Ind_NextNextLast = ((D0Ind+2)==15);
		for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1), D1Ind_NextNextLast = ((D1Ind+2)==1);
			/*================================= Prepare Tiles ===================================*/
			_SNN_expr_13_in_0 = 0;
			if (!(D1Ind_Last)) {
				if (!(1)) {
					_NN_expr_13_in_0 = _NN_expr_13_in_0 + (16640); _SNN_expr_13_in_0 = (((1)?1:256)*(65)); 
				} else if (!(D0Ind_Last)) {
					_NN_expr_13_in_0 = _NN_expr_13_in_0 + (16705)+(-16640); _SNN_expr_13_in_0 = (256*(65)); 
				}
			} else if (!(D0Ind_Last)) {
				_NN_expr_13_in_0 = _NN_expr_13_in_0 + 0; _SNN_expr_13_in_0 = (((D1Ind_Last)?1:256)*(65)); 
			}
			_SN_expr_13_in_1 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_13_in_1 = _N_expr_13_in_1 + (256); _SN_expr_13_in_1 = ((1)?1:256); 
			} else if (!(D0Ind_Last)) {
				_N_expr_13_in_1 = _N_expr_13_in_1 + (257)+(-256); _SN_expr_13_in_1 = (256); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_13_in_0 */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_13_in_0 before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_expr_13_in_0) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_13_in_0+_NN_expr_13_in_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33280+16640*((D1Ind_Total)%2)),
						1*(_SNN_expr_13_in_0), 0, UchanHR1);
			}
			if (_SN_expr_13_in_0) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33280+16640*((D1Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+16640*((D1Ind_Total+1)%2)),
						1*(_SN_expr_13_in_0), 0, DmaR_Evt1);
			}
			AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_13_in_1 */
			if (_SN_expr_13_in_1) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_13_in_1+_N_expr_13_in_1), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+256*((D1Ind_Total+1)%2)),
						1*(_SN_expr_13_in_1), 0, DmaR_Evt2);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D2 */
				int D2Ind_Last = 1;
				{ /* Single iteration on Tile0 */
					int T0Ind_Last = 1;
				} /* End iteration on Tile0 */
				/*====================== Call Kernel LOC_D2 =========================*/
				KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:256);
				KerArg0->expr_13_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+33280+16640*((D1Ind_Total)%2));
				KerArg0->expr_13_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+66560+256*((D1Ind_Total)%2));
				KerArg0->expr_13_in_2 = (signed char *__restrict__ ) (main_1_L1_Memory+67072+((D0Ind)*1));
				KerArg0->expr_13_in_3 = (signed char *__restrict__ ) (main_1_L1_Memory+67088+((D0Ind)*1));
				KerArg0->expr_13_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16640*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) s59_kernel, (void *) KerArg0);
				__CALL(s59_kernel, KerArg0);
			} /* End iteration on D2 */
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_13_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_13_out_0 */
			if (_SPP_expr_13_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_13_out_0 */
			if (_SP_expr_13_out_0) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_13_out_0+_P_expr_13_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16640*((D1Ind_Total+-1)%2)),
						_SP_expr_13_out_0, 1, UchanHR2);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16640*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16640*((D1Ind_Total)%2)),
					_SC_expr_13_out_0, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_13_out_0 = _SP_expr_13_out_0;
			_P_expr_13_out_0 = _C_expr_13_out_0;_SP_expr_13_out_0 = _SC_expr_13_out_0;
			_SN_expr_13_in_0 = _SNN_expr_13_in_0;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_13_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_13_out_0 = _C_expr_13_out_0 + (16640); _SC_expr_13_out_0 = (((1)?1:256)*(65)); 
			} else if (!(D0Ind_Last)) {
				_C_expr_13_out_0 = _C_expr_13_out_0 + (16705)+(-16640); _SC_expr_13_out_0 = (256*(65)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_13_out_0 */
	if (_SPP_expr_13_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_13_out_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_13_out_0+_P_expr_13_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16640*((D1Ind_Total+-1)%2)), _SP_expr_13_out_0, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_13_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S60_expr_11(
		unsigned char * __restrict__ expr_11_in_0,
		unsigned char * __restrict__ expr_11_in_1,
		unsigned char * __restrict__ expr_11_out_0)

{
	/* Shared L1: 115680 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s60_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _P_expr_11_out_0, _C_expr_11_out_0;
	unsigned int _SPP_expr_11_out_0, _SP_expr_11_out_0, _SC_expr_11_out_0;
	unsigned int _N_expr_11_in_0;
	unsigned int _SN_expr_11_in_0;
	unsigned int _NN_expr_11_in_1;
	unsigned int _SN_expr_11_in_1, _SNN_expr_11_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 267280, Tiled: 14][Tile0 Dim: 1]
	Ker Arg: expr_11_out_0, Tiled Space: D0
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 0 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_11_in_0, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 38560 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_11_in_1, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 77120 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_11_out_0=0; _SC_expr_11_out_0=19280;
	_SPP_expr_11_out_0=0; _SP_expr_11_out_0=0;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_11_in_1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+38560+0), 19280, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_11_in_1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_11_in_1+19280), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+38560+19280), 19280, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+38560+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+0), 19280, 0, DmaR_Evt1);
	_NN_expr_11_in_1=19280; _SN_expr_11_in_1=19280;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_11_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+0), 19280, 0, DmaR_Evt2);
	_N_expr_11_in_0=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<14; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==13), D0Ind_NextLast = ((D0Ind+1)==13), D0Ind_NextNextLast = ((D0Ind+2)==13);
		/*================================= Prepare Tiles ===================================*/
		_SN_expr_11_in_0 = 0;
		if (!(D0Ind_Last)) {
			_N_expr_11_in_0 = _N_expr_11_in_0 + (19280); _SN_expr_11_in_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		_SNN_expr_11_in_1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_11_in_1 = _NN_expr_11_in_1 + (19280); _SNN_expr_11_in_1 = ((D0Ind_NextNextLast)?16640:19280); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_11_in_0 */
		if (_SN_expr_11_in_0) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_11_in_0+_N_expr_11_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_11_in_0), 0, DmaR_Evt2);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_11_in_1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_11_in_1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_11_in_1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_11_in_1+_NN_expr_11_in_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+38560+19280*((D0Ind_Total)%2)),
					1*(_SNN_expr_11_in_1), 0, UchanHR1);
		}
		if (_SN_expr_11_in_1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+38560+19280*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_11_in_1), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		KerArg0->I0 = (unsigned int) ((D0Ind_Last)?16640:19280);
		KerArg0->expr_11_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+38560+19280*((D0Ind_Total)%2));
		KerArg0->expr_11_in_1 = (unsigned char *__restrict__ ) (main_1_L1_Memory+77120+19280*((D0Ind_Total)%2));
		KerArg0->expr_11_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+19280*((D0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) s60_kernel, (void *) KerArg0);
		__CALL(s60_kernel, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_expr_11_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_11_out_0 */
		if (_SPP_expr_11_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_11_out_0 */
		if (_SP_expr_11_out_0) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_11_out_0+_P_expr_11_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+19280*((D0Ind_Total+-1)%2)),
					_SP_expr_11_out_0, 1, UchanHR2);
		AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+19280*((D0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+19280*((D0Ind_Total)%2)),
				_SC_expr_11_out_0, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SPP_expr_11_out_0 = _SP_expr_11_out_0;
		_P_expr_11_out_0 = _C_expr_11_out_0;_SP_expr_11_out_0 = _SC_expr_11_out_0;
		_SN_expr_11_in_1 = _SNN_expr_11_in_1;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_expr_11_out_0 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_11_out_0 = _C_expr_11_out_0 + (19280); _SC_expr_11_out_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_11_out_0 */
	if (_SPP_expr_11_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_11_out_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_11_out_0+_P_expr_11_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+19280*((D0Ind_Total+-1)%2)), _SP_expr_11_out_0, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_11_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S62__conv_3_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 66832 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 16]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 16705], Tile1: [16705, 16705, 16705], Tile2; [33410, 16705, 16705]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 33416 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 1], Tile1: [1, 16705, 1], Tile2; [2, 16705, 1]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+0), 16705, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+16705), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16708), 16705, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16705, 0, DmaR_Evt1);
	_NN_In=16705; _SN_In=16705;
	_C_Out=0; _SC_Out=16705; _LC_Out=1;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<16; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==15), T0Ind_NextLast = ((T0Ind+1)==15), T0Ind_NextNextLast = ((T0Ind+2)==15);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_In = _NN_In + (16705); _SNN_In = (16705); 
				}
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16708*((T0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16708*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16708*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+16708*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33416+16708*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33416+16708*((T0Ind_Total)%2)),
					_SC_Out, 16, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1); _LC_Out = (1); _SC_Out = (16705*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S65__conv_3_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 110580 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerConv_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerConvLinReduct_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 29][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 29 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 29:[65x17, 27:65x25, 65x13], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 29:[65x17, 27:65x25, 65x13], 16][D0, [0 x 16, 16]]
		Tile0: [0, 17680, 17680], Tile1: [1040, 26000, 26000], Tile2; [10400, 26000, 26000]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 52000 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 52064 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 52080 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 52096 (Total Size: 2304 )[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 1 physical tiles
			@ 54400 (Total Size: 1069120 )[Tile0, 29:[65x9, 27:65x9, 65x5], 64][D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][Tile0, 29:[65x9], 64]
		Tile0: [0, 37440, 37440], Tile1: [0, 37440, 37440], Tile2; [0, 37440, 37440]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 29 logical tiles, 29 physical tiles
			@ 91840 (Total Size: 267280 )[Tile0, 29:[65x9, 27:65x9, 65x5], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 29:[65x9], 16]
		Tile0: [0, 9360, 9360], Tile1: [9360, 9360, 9360], Tile2; [18720, 9360, 9360]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 1 physical tiles
			@ 110560 (Total Size: 20 )[Tile0, 29:[20x1, 27:20x1, 20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 29:[20x1, 27:20x1, 20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->Filter = (unsigned short * __restrict__) (main_1_L1_Memory+52096);
	KerArg2->Bias = (int * __restrict__) (main_1_L1_Memory+52000);
	KerArg2->Out = (unsigned char * __restrict__) (main_1_L1_Memory+54400);
	KerArg2->Scale = (unsigned char * __restrict__) (main_1_L1_Memory+52064);
	KerArg2->ScaleN = (unsigned char * __restrict__) (main_1_L1_Memory+52080);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InW = (unsigned short int) (65);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutW = (unsigned short int) (65);
	KerArg2->Pad_Val = (unsigned short int) (104);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947351);
	KerArg2->Dx = (unsigned char) (8);
	KerArg2->Dy = (unsigned char) (8);
	KerArg3->In = (int *__restrict__) (main_1_L1_Memory+54400);
	KerArg3->Feat = (unsigned short int) (16);
	KerArg3->W = (unsigned short int) (65);
	KerArg3->Scale = (unsigned char *__restrict__) (main_1_L1_Memory+52064);
	KerArg3->ScaleN = (unsigned char *__restrict__) (main_1_L1_Memory+52080);
	KerArg3->Infos = (signed char *__restrict__) (main_1_L1_Memory+110560);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=9360;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 17680, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+52096), 2304, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+52000), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+110560), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+52064), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+52080), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1, D1Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<29; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==28), T0Ind_NextLast = ((T0Ind+1)==28), T0Ind_NextNextLast = ((T0Ind+2)==28);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (9360-(8320*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?845:1625)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-253760); _SN_In = (1105*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if ((T0Ind)==27) {
				AT_TileClear((main_1_L1_Memory+0+26000*((T0Ind_Total)%2)), 65, 25, (16), 1, 3, 104, 0, 1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+26000*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (main_1_L1_Memory+0+26000*((T0Ind_Total)%2));
				KerArg2->Tile_InH = (unsigned short int) (((T0Ind_Last)?13:25)-8*(T0Ind==0));
				KerArg2->Tile_OutH = (unsigned short int) (T0Ind_Last?5:9);
				KerArg2->Pad = (v4s) ((v4s){8,8,8*(T0Ind==0),8*(T0Ind_Last)});
				KerArg2->W_Offset = (int) (((int *)(main_1_L1_Memory+110560))[4]);
				KerConv3x3Stride1_DxDy_NE16(KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg3->Out = (void *__restrict__) (main_1_L1_Memory+91840+9360*((T0Ind_Total)%2));
			KerArg3->H = (unsigned short int) (T0Ind_Last?5:9);
			AT_FORK(gap_ncore(), (void *) KerReduct_CC_NoScale_LeakyReLU_USQ8, (void *) KerArg3);
			__CALL(KerReduct_CC_NoScale_LeakyReLU_USQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+9360*((T0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+9360*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+91840+9360*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (9360); _SC_Out = (((T0Ind_NextLast)?325:585)*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+9360*((T0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S66__conv_3_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 115648 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 10]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 28912], Tile1: [28912, 28912, 28912], Tile2; [57824, 28912, 28912]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57824 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 1807], Tile1: [1807, 28912, 1807], Tile2; [3614, 28912, 1807]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), 28912, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+28912), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+28912), 28912, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28912, 0, DmaR_Evt1);
	_NN_In=28912; _SN_In=28912;
	_C_Out=0; _SC_Out=28912; _LC_Out=1807;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<10; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==9), T0Ind_NextLast = ((T0Ind+1)==9), T0Ind_NextNextLast = ((T0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_In = _NN_In + (28912); _SNN_In = ((T0Ind_NextNextLast)?7072:28912); 
				}
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+28912*((T0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+28912*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28912*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+28912*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+57824+28912*((T0Ind_Total)%2));
			KerArg0->H = (unsigned short int) (T0Ind_Last?442:1807);
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57824+28912*((T0Ind_Total)%2)),
					_SC_Out, 16705, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1807); _LC_Out = ((T0Ind_NextLast)?442:1807); _SC_Out = (16*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S68__conv_3_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	CNN_UFpsFps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 267280, Tiled: 10]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57840 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (main_1_L1_Memory+115680);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28920, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=28920;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115680), 8, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D0Ind=0; D0Ind<10; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
			int D0Ind_Last = (D0Ind==9), D0Ind_NextLast = ((D0Ind+1)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(D0Ind_Last)) {
				_N_In = _N_In + (28920); _SN_In = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_N_In = _N_In + (-260280); _SN_In = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28920*((D0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_D0 =========================*/
			KerArg0->In = (unsigned char *__restrict__) (main_1_L1_Memory+0+28920*((D0Ind_Total)%2));
			KerArg0->Out = (signed char *__restrict__) (main_1_L1_Memory+57840+28920*((D0Ind_Total)%2));
			KerArg0->W = (unsigned short int) ((D0Ind_Last)?7000:28920);
			AT_FORK(gap_ncore(), (void *) CNN_UFpsFpsScaled, (void *) KerArg0);
			__CALL(CNN_UFpsFpsScaled, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57840+28920*((D0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(D0Ind_Last)) {
				_C_Out = _C_Out + (28920); _SC_Out = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_C_Out = _C_Out + (-260280); _SC_Out = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S69__conv_3_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115120 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (56680); _SN_In = ((T0Ind_NextLast)?40560:56680); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S70_expr_17(
		unsigned char * __restrict__ expr_17_in_0,
		signed char * __restrict__ expr_17_in_1,
		unsigned char * __restrict__ expr_17_out_0,
		signed char * __restrict__ expr_17_out_1)

{
	/* Shared L1: 102800 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s70_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_expr_17_in_0;
	unsigned int _SN_expr_17_in_0;
	unsigned int _LN_expr_17_in_0;
	unsigned int _C_expr_17_out_0;
	unsigned int _SP_expr_17_out_0, _SC_expr_17_out_0;
	unsigned int _LP_expr_17_out_0, _LC_expr_17_out_0;
	unsigned int _P_expr_17_out_1, _C_expr_17_out_1;
	unsigned int _SPP_expr_17_out_1, _SP_expr_17_out_1, _SC_expr_17_out_1;
	unsigned int _LPP_expr_17_out_1, _LP_expr_17_out_1, _LC_expr_17_out_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 4112, Tiled: 1][D1 Dim: Init: 65, Tiled: 17][Tile0 Dim: 1]
	Ker Arg: expr_17_in_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_17_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32896 (Total Size: 4112 )[D0, [0 x 4112, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4112, 4112]]
		Tile0: [0, 4112, 4112], Tile1: [0, 4112, 4112], Tile2; [0, 4112, 4112]
	Ker Arg: expr_17_out_0, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 37008 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_17_out_1, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 69904 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (4112);
	KerArg0->expr_17_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+32896);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_17_out_1=0; _SC_expr_17_out_1=16448; _LC_expr_17_out_1=4;
	_SPP_expr_17_out_1=0; _SP_expr_17_out_1=0;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_17_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16448, 65, 4, 0, DmaR_Evt1);
	_N_expr_17_in_0=0;
	_C_expr_17_out_0=0; _SC_expr_17_out_0=16448; _LC_expr_17_out_0=4;
	_SP_expr_17_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_17_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+32896), 4112, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_17_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (D1Ind=0; D1Ind<17; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==16), D1Ind_NextLast = ((D1Ind+1)==16), D1Ind_NextNextLast = ((D1Ind+2)==16);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_17_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_17_in_0 = _N_expr_17_in_0 + (4); _LN_expr_17_in_0 = ((D1Ind_NextLast)?1:4); _SN_expr_17_in_0 = (4112*_LN_expr_17_in_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_17_in_0 */
			if (_SN_expr_17_in_0) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_17_in_0+_N_expr_17_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16448*((D1Ind_Total+1)%2)),
						1*(_SN_expr_17_in_0), 65, _LN_expr_17_in_0, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:4);
			KerArg0->expr_17_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16448*((D1Ind_Total)%2));
			KerArg0->expr_17_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+37008+16448*((D1Ind_Total)%2));
			KerArg0->expr_17_out_1 = (signed char *__restrict__ ) (main_1_L1_Memory+69904+16448*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) s70_kernel, (void *) KerArg0);
			__CALL(s70_kernel, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_17_out_0) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_17_out_0 */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_17_out_0+_C_expr_17_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+37008+16448*((D1Ind_Total)%2)),
					_SC_expr_17_out_0, 65, _LC_expr_17_out_0, 1, DmaW_Evt2);
			if (_SP_expr_17_out_1) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_17_out_1 */
			if (_SPP_expr_17_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_17_out_1 */
			if (_SP_expr_17_out_1) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_17_out_1+_P_expr_17_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_17_out_1, 65, _LP_expr_17_out_1, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+69904+16448*((D1Ind_Total)%2)),
					_SC_expr_17_out_1, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_expr_17_out_0 = _SC_expr_17_out_0;_LP_expr_17_out_0 = _LC_expr_17_out_0;
			_SPP_expr_17_out_1 = _SP_expr_17_out_1;_LPP_expr_17_out_1 = _LP_expr_17_out_1;
			_P_expr_17_out_1 = _C_expr_17_out_1;_SP_expr_17_out_1 = _SC_expr_17_out_1;_LP_expr_17_out_1 = _LC_expr_17_out_1;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_17_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_17_out_0 = _C_expr_17_out_0 + (4); _LC_expr_17_out_0 = ((D1Ind_NextLast)?1:4); _SC_expr_17_out_0 = (4112*_LC_expr_17_out_0); 
			}
			_SC_expr_17_out_1 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_17_out_1 = _C_expr_17_out_1 + (4); _LC_expr_17_out_1 = ((D1Ind_NextLast)?1:4); _SC_expr_17_out_1 = (4112*_LC_expr_17_out_1); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_17_out_0 */
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_17_out_1 */
	if (_SPP_expr_17_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_17_out_1 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_17_out_1+_P_expr_17_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)), _SP_expr_17_out_1, 65, _LP_expr_17_out_1, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write expr_17_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S71__conv_3_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT)

{
	/* Shared L1: 115504 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	expr_15_args_t S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	Ker Arg: RsqrtLUT, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115120 (Total Size: 384 )[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		Tile0: [0, 384, 384], Tile1: [0, 384, 384], Tile2; [0, 384, 384]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->Feat = (unsigned short int) (1);
	KerArg1->RsqrtLUT = (unsigned int * __restrict__) (main_1_L1_Memory+115120);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) RsqrtLUT+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115120), 384, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		KerArg1->expr_15_in_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->expr_15_out_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->W = (unsigned short int) (T0Ind_Last?624:872);
		AT_FORK(gap_ncore(), (void *) expr_15, (void *) KerArg1);
		__CALL(expr_15, KerArg1);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S74_expr_18(
		unsigned char * __restrict__ expr_18_in_0,
		signed char * __restrict__ expr_18_in_1,
		signed char * __restrict__ expr_18_in_2,
		signed char * __restrict__ expr_18_in_3,
		unsigned char * __restrict__ expr_18_out_0)

{
	/* Shared L1: 67104 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s74_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int D2Ind, D2Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _P_expr_18_out_0, _C_expr_18_out_0;
	unsigned int _SPP_expr_18_out_0, _SP_expr_18_out_0, _SC_expr_18_out_0;
	unsigned int _N_expr_18_in_0;
	unsigned int _SN_expr_18_in_0;
	unsigned int _N_expr_18_in_1;
	unsigned int _SN_expr_18_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 16][D1 Dim: Init: 257, Tiled: 2][D2 Dim: Init: 65, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_18_out_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 0 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_18_in_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 33280 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_18_in_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 66560 (Total Size: 4112 )[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		Tile0: [0, 256, 256], Tile1: [256, 1, 1], Tile2; [257, 256, 256]
	Ker Arg: expr_18_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67072 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: expr_18_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67088 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1);
	KerArg0->I2 = (unsigned int) (65);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_18_out_0=0; _SC_expr_18_out_0=16640;
	_SPP_expr_18_out_0=0; _SP_expr_18_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_18_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+0), 16640, 0, DmaR_Evt1);
	_N_expr_18_in_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_18_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+0), 256, 0, DmaR_Evt2);
	_N_expr_18_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_18_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67072), 16, 0, DmaR_Evt3);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_18_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67088), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read expr_18_in_3 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<16; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==15), D0Ind_NextLast = ((D0Ind+1)==15), D0Ind_NextNextLast = ((D0Ind+2)==15);
		for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1), D1Ind_NextNextLast = ((D1Ind+2)==1);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_18_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_18_in_0 = _N_expr_18_in_0 + (16640); _SN_expr_18_in_0 = (((1)?1:256)*(65)); 
			} else if (!(D0Ind_Last)) {
				_N_expr_18_in_0 = _N_expr_18_in_0 + (16705)+(-16640); _SN_expr_18_in_0 = (256*(65)); 
			}
			_SN_expr_18_in_1 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_18_in_1 = _N_expr_18_in_1 + (256); _SN_expr_18_in_1 = ((1)?1:256); 
			} else if (!(D0Ind_Last)) {
				_N_expr_18_in_1 = _N_expr_18_in_1 + (257)+(-256); _SN_expr_18_in_1 = (256); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_18_in_0 */
			if (_SN_expr_18_in_0) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_18_in_0+_N_expr_18_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+16640*((D1Ind_Total+1)%2)),
						1*(_SN_expr_18_in_0), 0, DmaR_Evt1);
			}
			AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_18_in_1 */
			if (_SN_expr_18_in_1) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_18_in_1+_N_expr_18_in_1), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+256*((D1Ind_Total+1)%2)),
						1*(_SN_expr_18_in_1), 0, DmaR_Evt2);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D2 */
				int D2Ind_Last = 1;
				{ /* Single iteration on Tile0 */
					int T0Ind_Last = 1;
				} /* End iteration on Tile0 */
				/*====================== Call Kernel LOC_D2 =========================*/
				KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:256);
				KerArg0->expr_18_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+33280+16640*((D1Ind_Total)%2));
				KerArg0->expr_18_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+66560+256*((D1Ind_Total)%2));
				KerArg0->expr_18_in_2 = (signed char *__restrict__ ) (main_1_L1_Memory+67072+((D0Ind)*1));
				KerArg0->expr_18_in_3 = (signed char *__restrict__ ) (main_1_L1_Memory+67088+((D0Ind)*1));
				KerArg0->expr_18_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16640*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) s74_kernel, (void *) KerArg0);
				__CALL(s74_kernel, KerArg0);
			} /* End iteration on D2 */
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_18_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_18_out_0 */
			if (_SPP_expr_18_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_18_out_0 */
			if (_SP_expr_18_out_0) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_18_out_0+_P_expr_18_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16640*((D1Ind_Total+-1)%2)),
						_SP_expr_18_out_0, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16640*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16640*((D1Ind_Total)%2)),
					_SC_expr_18_out_0, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_18_out_0 = _SP_expr_18_out_0;
			_P_expr_18_out_0 = _C_expr_18_out_0;_SP_expr_18_out_0 = _SC_expr_18_out_0;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_18_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_18_out_0 = _C_expr_18_out_0 + (16640); _SC_expr_18_out_0 = (((1)?1:256)*(65)); 
			} else if (!(D0Ind_Last)) {
				_C_expr_18_out_0 = _C_expr_18_out_0 + (16705)+(-16640); _SC_expr_18_out_0 = (256*(65)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_18_out_0 */
	if (_SPP_expr_18_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_18_out_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_18_out_0+_P_expr_18_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16640*((D1Ind_Total+-1)%2)), _SP_expr_18_out_0, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write expr_18_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S75_expr_14(
		unsigned char * __restrict__ expr_14_in_0,
		unsigned char * __restrict__ expr_14_in_1,
		unsigned char * __restrict__ expr_14_out_0)

{
	/* Shared L1: 115680 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	s75_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_14_out_0;
	unsigned int _SP_expr_14_out_0, _SC_expr_14_out_0;
	unsigned int _NN_expr_14_in_0;
	unsigned int _SN_expr_14_in_0, _SNN_expr_14_in_0;
	unsigned int _NN_expr_14_in_1;
	unsigned int _SN_expr_14_in_1, _SNN_expr_14_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 267280, Tiled: 14][Tile0 Dim: 1]
	Ker Arg: expr_14_out_0, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 0 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_14_in_0, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 38560 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_14_in_1, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 77120 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_14_in_0+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), 19280, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_14_in_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_14_in_0+19280), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+19280), 19280, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+0), 19280, 0, DmaR_Evt1);
	_NN_expr_14_in_0=19280; _SN_expr_14_in_0=19280;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_14_in_1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+573120+0), 19280, 0, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read expr_14_in_1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_14_in_1+19280), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+573120+19280), 19280, 0, UchanHR2);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+573120+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+0), 19280, 0, DmaR_Evt2);
	_NN_expr_14_in_1=19280; _SN_expr_14_in_1=19280;
	_C_expr_14_out_0=0; _SC_expr_14_out_0=19280;
	_SP_expr_14_out_0=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<14; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==13), D0Ind_NextLast = ((D0Ind+1)==13), D0Ind_NextNextLast = ((D0Ind+2)==13);
		/*================================= Prepare Tiles ===================================*/
		_SNN_expr_14_in_0 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_14_in_0 = _NN_expr_14_in_0 + (19280); _SNN_expr_14_in_0 = ((D0Ind_NextNextLast)?16640:19280); 
			}
		}
		_SNN_expr_14_in_1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_14_in_1 = _NN_expr_14_in_1 + (19280); _SNN_expr_14_in_1 = ((D0Ind_NextNextLast)?16640:19280); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_14_in_0 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_14_in_0 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_14_in_0) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_14_in_0+_NN_expr_14_in_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+19280*((D0Ind_Total)%2)),
					1*(_SNN_expr_14_in_0), 0, UchanHR1);
		}
		if (_SN_expr_14_in_0) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+19280*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_14_in_0), 0, DmaR_Evt1);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read expr_14_in_1 */
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_14_in_1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_14_in_1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_14_in_1+_NN_expr_14_in_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+573120+19280*((D0Ind_Total)%2)),
					1*(_SNN_expr_14_in_1), 0, UchanHR2);
		}
		if (_SN_expr_14_in_1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+573120+19280*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_14_in_1), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		KerArg0->I0 = (unsigned int) ((D0Ind_Last)?16640:19280);
		KerArg0->expr_14_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+38560+19280*((D0Ind_Total)%2));
		KerArg0->expr_14_in_1 = (unsigned char *__restrict__ ) (main_1_L1_Memory+77120+19280*((D0Ind_Total)%2));
		KerArg0->expr_14_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+19280*((D0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) s75_kernel, (void *) KerArg0);
		__CALL(s75_kernel, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_expr_14_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_14_out_0 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_14_out_0+_C_expr_14_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+19280*((D0Ind_Total)%2)),
				_SC_expr_14_out_0, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_expr_14_out_0 = _SC_expr_14_out_0;
		_SN_expr_14_in_0 = _SNN_expr_14_in_0;
		_SN_expr_14_in_1 = _SNN_expr_14_in_1;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_expr_14_out_0 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_14_out_0 = _C_expr_14_out_0 + (19280); _SC_expr_14_out_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_14_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S77__conv_4_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 66832 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 16]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 16705], Tile1: [16705, 16705, 16705], Tile2; [33410, 16705, 16705]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 33416 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 1], Tile1: [1, 16705, 1], Tile2; [2, 16705, 1]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16705, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=16705; _LC_Out=1;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<16; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==15), T0Ind_NextLast = ((T0Ind+1)==15);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (16705); _SN_In = (16705); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16708*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+16708*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33416+16708*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33416+16708*((T0Ind_Total)%2)),
					_SC_Out, 16, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1); _LC_Out = (1); _SC_Out = (16705*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S80__conv_4_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 107572 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerConv_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 11][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 11 logical tiles, 11 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 11:[65x25, 9:65x26, 65x18], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 11:[65x25, 9:65x26, 65x18], 16][D0, [0 x 16, 16]]
		Tile0: [0, 26000, 26000], Tile1: [23920, 27040, 27040], Tile2; [48880, 27040, 27040]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 54080 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 54144 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 54160 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 54176 (Total Size: 2304 )[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 11 logical tiles, 11 physical tiles
			@ 56480 (Total Size: 267280 )[Tile0, 11:[65x24, 9:65x24, 65x17], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 11:[65x24], 16]
		Tile0: [0, 24960, 24960], Tile1: [24960, 24960, 24960], Tile2; [49920, 24960, 24960]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 11 logical tiles, 1 physical tiles
			@ 106400 (Total Size: 20 )[Tile0, 11:[20x1, 9:20x1, 20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 11:[20x1, 9:20x1, 20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 106420 (Total Size: 1152 )[D1, [0 x 1152, 1152]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1152, 1152]]
		Tile0: [0, 1152, 1152], Tile1: [0, 1152, 1152], Tile2; [0, 1152, 1152]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->Filter = (unsigned short * __restrict__) (main_1_L1_Memory+54176);
	KerArg2->Bias = (int * __restrict__) (main_1_L1_Memory+54080);
	KerArg2->Scale = (unsigned char * __restrict__) (main_1_L1_Memory+54144);
	KerArg2->ScaleN = (unsigned char * __restrict__) (main_1_L1_Memory+54160);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InW = (unsigned short int) (65);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutW = (unsigned short int) (65);
	KerArg2->Pad_Val = (unsigned short int) (99);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947351);
	KerArg2->BuffOut = (int * __restrict__) (main_1_L1_Memory+106420);
	KerArg2->Infos = (unsigned char * __restrict__) (main_1_L1_Memory+106400);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=24960;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 26000, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+54176), 2304, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+54080), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+106400), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+54144), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+54160), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1, D1Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<11; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==10), T0Ind_NextLast = ((T0Ind+1)==10), T0Ind_NextNextLast = ((T0Ind+2)==10);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (24960-(1040*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?1170:1690)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-248560); _SN_In = (1625*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+27040*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (main_1_L1_Memory+0+27040*((T0Ind_Total)%2));
				KerArg2->Out = (unsigned char * __restrict__) (main_1_L1_Memory+56480+24960*((T0Ind_Total)%2));
				KerArg2->Tile_InH = (unsigned short int) (((T0Ind_Last)?18:26)-1*(T0Ind==0));
				KerArg2->Tile_OutH = (unsigned short int) (T0Ind_Last?17:24);
				KerArg2->Pad = (v4s) ((v4s){1,1,1*(T0Ind==0),1*(T0Ind_Last)});
				KerArg2->W_Offset = (int) (((int *)(main_1_L1_Memory+106400))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerConv3x3Stride1Leaky_NE16, (void *) KerArg2);
				__CALL(KerConv3x3Stride1Leaky_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+24960*((T0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+24960*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+56480+24960*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (24960); _SC_Out = (((T0Ind_NextLast)?1105:1560)*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+24960*((T0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S81__conv_4_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 115648 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 10]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 28912], Tile1: [28912, 28912, 28912], Tile2; [57824, 28912, 28912]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57824 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 1807], Tile1: [1807, 28912, 1807], Tile2; [3614, 28912, 1807]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 28912, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+28912), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912), 28912, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28912, 0, DmaR_Evt1);
	_NN_In=28912; _SN_In=28912;
	_C_Out=0; _SC_Out=28912; _LC_Out=1807;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<10; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==9), T0Ind_NextLast = ((T0Ind+1)==9), T0Ind_NextNextLast = ((T0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_In = _NN_In + (28912); _SNN_In = ((T0Ind_NextNextLast)?7072:28912); 
				}
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912*((T0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28912*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+28912*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+57824+28912*((T0Ind_Total)%2));
			KerArg0->H = (unsigned short int) (T0Ind_Last?442:1807);
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57824+28912*((T0Ind_Total)%2)),
					_SC_Out, 16705, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1807); _LC_Out = ((T0Ind_NextLast)?442:1807); _SC_Out = (16*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S83__conv_4_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	CNN_UFpsFps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 267280, Tiled: 10]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57840 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (main_1_L1_Memory+115680);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28920;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28920, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115680), 8, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D0Ind=0; D0Ind<10; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
			int D0Ind_Last = (D0Ind==9), D0Ind_NextLast = ((D0Ind+1)==9), D0Ind_NextNextLast = ((D0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(D0Ind_Last)) {
				_N_In = _N_In + (28920); _SN_In = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_N_In = _N_In + (-260280); _SN_In = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28920*((D0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_D0 =========================*/
			KerArg0->In = (unsigned char *__restrict__) (main_1_L1_Memory+0+28920*((D0Ind_Total)%2));
			KerArg0->Out = (signed char *__restrict__) (main_1_L1_Memory+57840+28920*((D0Ind_Total)%2));
			KerArg0->W = (unsigned short int) ((D0Ind_Last)?7000:28920);
			AT_FORK(gap_ncore(), (void *) CNN_UFpsFpsScaled, (void *) KerArg0);
			__CALL(CNN_UFpsFpsScaled, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57840+28920*((D0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(D0Ind_Last)) {
				_C_Out = _C_Out + (28920); _SC_Out = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_C_Out = _C_Out + (-260280); _SC_Out = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S84__conv_4_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115120 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S85_expr_22(
		unsigned char * __restrict__ expr_22_in_0,
		signed char * __restrict__ expr_22_in_1,
		unsigned char * __restrict__ expr_22_out_0,
		signed char * __restrict__ expr_22_out_1)

{
	/* Shared L1: 102800 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	s85_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_expr_22_in_0;
	unsigned int _SN_expr_22_in_0;
	unsigned int _LN_expr_22_in_0;
	unsigned int _P_expr_22_out_0, _C_expr_22_out_0;
	unsigned int _SPP_expr_22_out_0, _SP_expr_22_out_0, _SC_expr_22_out_0;
	unsigned int _LPP_expr_22_out_0, _LP_expr_22_out_0, _LC_expr_22_out_0;
	unsigned int _P_expr_22_out_1, _C_expr_22_out_1;
	unsigned int _SPP_expr_22_out_1, _SP_expr_22_out_1, _SC_expr_22_out_1;
	unsigned int _LPP_expr_22_out_1, _LP_expr_22_out_1, _LC_expr_22_out_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 4112, Tiled: 1][D1 Dim: Init: 65, Tiled: 17][Tile0 Dim: 1]
	Ker Arg: expr_22_in_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_22_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32896 (Total Size: 4112 )[D0, [0 x 4112, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4112, 4112]]
		Tile0: [0, 4112, 4112], Tile1: [0, 4112, 4112], Tile2; [0, 4112, 4112]
	Ker Arg: expr_22_out_0, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 37008 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_22_out_1, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 69904 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (4112);
	KerArg0->expr_22_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+32896);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_22_out_0=0; _SC_expr_22_out_0=16448; _LC_expr_22_out_0=4;
	_SPP_expr_22_out_0=0; _SP_expr_22_out_0=0;
	_C_expr_22_out_1=0; _SC_expr_22_out_1=16448; _LC_expr_22_out_1=4;
	_SPP_expr_22_out_1=0; _SP_expr_22_out_1=0;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_22_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16448, 65, 4, 0, DmaR_Evt1);
	_N_expr_22_in_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_22_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+32896), 4112, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_22_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (D1Ind=0; D1Ind<17; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==16), D1Ind_NextLast = ((D1Ind+1)==16), D1Ind_NextNextLast = ((D1Ind+2)==16);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_22_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_22_in_0 = _N_expr_22_in_0 + (4); _LN_expr_22_in_0 = ((D1Ind_NextLast)?1:4); _SN_expr_22_in_0 = (4112*_LN_expr_22_in_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_22_in_0 */
			if (_SN_expr_22_in_0) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_22_in_0+_N_expr_22_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16448*((D1Ind_Total+1)%2)),
						1*(_SN_expr_22_in_0), 65, _LN_expr_22_in_0, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:4);
			KerArg0->expr_22_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16448*((D1Ind_Total)%2));
			KerArg0->expr_22_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+37008+16448*((D1Ind_Total)%2));
			KerArg0->expr_22_out_1 = (signed char *__restrict__ ) (main_1_L1_Memory+69904+16448*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) s85_kernel, (void *) KerArg0);
			__CALL(s85_kernel, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_22_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_22_out_0 */
			if (_SPP_expr_22_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_22_out_0 */
			if (_SP_expr_22_out_0) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_22_out_0+_P_expr_22_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_22_out_0, 65, _LP_expr_22_out_0, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+37008+16448*((D1Ind_Total)%2)),
					_SC_expr_22_out_0, 1, DmaW_Evt1);
			if (_SP_expr_22_out_1) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_22_out_1 */
			if (_SPP_expr_22_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_22_out_1 */
			if (_SP_expr_22_out_1) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_22_out_1+_P_expr_22_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_22_out_1, 65, _LP_expr_22_out_1, 1, UchanHR2);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+69904+16448*((D1Ind_Total)%2)),
					_SC_expr_22_out_1, 1, DmaW_Evt2);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_22_out_0 = _SP_expr_22_out_0;_LPP_expr_22_out_0 = _LP_expr_22_out_0;
			_P_expr_22_out_0 = _C_expr_22_out_0;_SP_expr_22_out_0 = _SC_expr_22_out_0;_LP_expr_22_out_0 = _LC_expr_22_out_0;
			_SPP_expr_22_out_1 = _SP_expr_22_out_1;_LPP_expr_22_out_1 = _LP_expr_22_out_1;
			_P_expr_22_out_1 = _C_expr_22_out_1;_SP_expr_22_out_1 = _SC_expr_22_out_1;_LP_expr_22_out_1 = _LC_expr_22_out_1;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_22_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_22_out_0 = _C_expr_22_out_0 + (4); _LC_expr_22_out_0 = ((D1Ind_NextLast)?1:4); _SC_expr_22_out_0 = (4112*_LC_expr_22_out_0); 
			}
			_SC_expr_22_out_1 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_22_out_1 = _C_expr_22_out_1 + (4); _LC_expr_22_out_1 = ((D1Ind_NextLast)?1:4); _SC_expr_22_out_1 = (4112*_LC_expr_22_out_1); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_22_out_0 */
	if (_SPP_expr_22_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_22_out_0 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_22_out_0+_P_expr_22_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)), _SP_expr_22_out_0, 65, _LP_expr_22_out_0, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write expr_22_out_0 */
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_22_out_1 */
	if (_SPP_expr_22_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_22_out_1 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_22_out_1+_P_expr_22_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total+-1)%2)), _SP_expr_22_out_1, 65, _LP_expr_22_out_1, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_22_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S86__conv_4_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT)

{
	/* Shared L1: 115504 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	expr_21_args_t S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	Ker Arg: RsqrtLUT, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115120 (Total Size: 384 )[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		Tile0: [0, 384, 384], Tile1: [0, 384, 384], Tile2; [0, 384, 384]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->Feat = (unsigned short int) (1);
	KerArg1->RsqrtLUT = (unsigned int * __restrict__) (main_1_L1_Memory+115120);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) RsqrtLUT+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115120), 384, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		KerArg1->expr_21_in_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->expr_21_out_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->W = (unsigned short int) (T0Ind_Last?624:872);
		AT_FORK(gap_ncore(), (void *) expr_21, (void *) KerArg1);
		__CALL(expr_21, KerArg1);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S89_expr_23(
		unsigned char * __restrict__ expr_23_in_0,
		signed char * __restrict__ expr_23_in_1,
		signed char * __restrict__ expr_23_in_2,
		signed char * __restrict__ expr_23_in_3,
		unsigned char * __restrict__ expr_23_out_0)

{
	/* Shared L1: 67104 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s89_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int D2Ind, D2Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _P_expr_23_out_0, _C_expr_23_out_0;
	unsigned int _SPP_expr_23_out_0, _SP_expr_23_out_0, _SC_expr_23_out_0;
	unsigned int _NN_expr_23_in_0;
	unsigned int _SN_expr_23_in_0, _SNN_expr_23_in_0;
	unsigned int _N_expr_23_in_1;
	unsigned int _SN_expr_23_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 16][D1 Dim: Init: 257, Tiled: 2][D2 Dim: Init: 65, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_23_out_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 0 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_23_in_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 33280 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_23_in_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 66560 (Total Size: 4112 )[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		Tile0: [0, 256, 256], Tile1: [256, 1, 1], Tile2; [257, 256, 256]
	Ker Arg: expr_23_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67072 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: expr_23_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67088 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1);
	KerArg0->I2 = (unsigned int) (65);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_23_out_0=0; _SC_expr_23_out_0=16640;
	_SPP_expr_23_out_0=0; _SP_expr_23_out_0=0;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_23_in_0+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+0), 16640, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_23_in_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_23_in_0+16640), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+16640), 65, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+0), 16640, 0, DmaR_Evt1);
	_NN_expr_23_in_0=16640; _SN_expr_23_in_0=65;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_23_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+0), 256, 0, DmaR_Evt2);
	_N_expr_23_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_23_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67072), 16, 0, DmaR_Evt3);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_23_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67088), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read expr_23_in_3 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<16; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==15), D0Ind_NextLast = ((D0Ind+1)==15), D0Ind_NextNextLast = ((D0Ind+2)==15);
		for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1), D1Ind_NextNextLast = ((D1Ind+2)==1);
			/*================================= Prepare Tiles ===================================*/
			_SNN_expr_23_in_0 = 0;
			if (!(D1Ind_Last)) {
				if (!(1)) {
					_NN_expr_23_in_0 = _NN_expr_23_in_0 + (16640); _SNN_expr_23_in_0 = (((1)?1:256)*(65)); 
				} else if (!(D0Ind_Last)) {
					_NN_expr_23_in_0 = _NN_expr_23_in_0 + (16705)+(-16640); _SNN_expr_23_in_0 = (256*(65)); 
				}
			} else if (!(D0Ind_Last)) {
				_NN_expr_23_in_0 = _NN_expr_23_in_0 + 0; _SNN_expr_23_in_0 = (((D1Ind_Last)?1:256)*(65)); 
			}
			_SN_expr_23_in_1 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_23_in_1 = _N_expr_23_in_1 + (256); _SN_expr_23_in_1 = ((1)?1:256); 
			} else if (!(D0Ind_Last)) {
				_N_expr_23_in_1 = _N_expr_23_in_1 + (257)+(-256); _SN_expr_23_in_1 = (256); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_23_in_0 */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_23_in_0 before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_expr_23_in_0) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_23_in_0+_NN_expr_23_in_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+16640*((D1Ind_Total)%2)),
						1*(_SNN_expr_23_in_0), 0, UchanHR1);
			}
			if (_SN_expr_23_in_0) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+16640*((D1Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+16640*((D1Ind_Total+1)%2)),
						1*(_SN_expr_23_in_0), 0, DmaR_Evt1);
			}
			AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_23_in_1 */
			if (_SN_expr_23_in_1) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_23_in_1+_N_expr_23_in_1), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+256*((D1Ind_Total+1)%2)),
						1*(_SN_expr_23_in_1), 0, DmaR_Evt2);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D2 */
				int D2Ind_Last = 1;
				{ /* Single iteration on Tile0 */
					int T0Ind_Last = 1;
				} /* End iteration on Tile0 */
				/*====================== Call Kernel LOC_D2 =========================*/
				KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:256);
				KerArg0->expr_23_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+33280+16640*((D1Ind_Total)%2));
				KerArg0->expr_23_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+66560+256*((D1Ind_Total)%2));
				KerArg0->expr_23_in_2 = (signed char *__restrict__ ) (main_1_L1_Memory+67072+((D0Ind)*1));
				KerArg0->expr_23_in_3 = (signed char *__restrict__ ) (main_1_L1_Memory+67088+((D0Ind)*1));
				KerArg0->expr_23_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16640*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) s89_kernel, (void *) KerArg0);
				__CALL(s89_kernel, KerArg0);
			} /* End iteration on D2 */
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_23_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_23_out_0 */
			if (_SPP_expr_23_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_23_out_0 */
			if (_SP_expr_23_out_0) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_23_out_0+_P_expr_23_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+16640*((D1Ind_Total+-1)%2)),
						_SP_expr_23_out_0, 1, UchanHR2);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+16640*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16640*((D1Ind_Total)%2)),
					_SC_expr_23_out_0, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_23_out_0 = _SP_expr_23_out_0;
			_P_expr_23_out_0 = _C_expr_23_out_0;_SP_expr_23_out_0 = _SC_expr_23_out_0;
			_SN_expr_23_in_0 = _SNN_expr_23_in_0;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_23_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_23_out_0 = _C_expr_23_out_0 + (16640); _SC_expr_23_out_0 = (((1)?1:256)*(65)); 
			} else if (!(D0Ind_Last)) {
				_C_expr_23_out_0 = _C_expr_23_out_0 + (16705)+(-16640); _SC_expr_23_out_0 = (256*(65)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_23_out_0 */
	if (_SPP_expr_23_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_23_out_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_23_out_0+_P_expr_23_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+16640*((D1Ind_Total+-1)%2)), _SP_expr_23_out_0, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_23_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S90_expr_16(
		unsigned char * __restrict__ expr_16_in_0,
		unsigned char * __restrict__ expr_16_in_1,
		unsigned char * __restrict__ expr_16_out_0)

{
	/* Shared L1: 115680 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s90_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_16_out_0;
	unsigned int _SP_expr_16_out_0, _SC_expr_16_out_0;
	unsigned int _N_expr_16_in_0;
	unsigned int _SN_expr_16_in_0;
	unsigned int _NN_expr_16_in_1;
	unsigned int _SN_expr_16_in_1, _SNN_expr_16_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 267280, Tiled: 14][Tile0 Dim: 1]
	Ker Arg: expr_16_out_0, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 0 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_16_in_0, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 38560 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_16_in_1, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 77120 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_16_in_1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 19280, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_16_in_1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_16_in_1+19280), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280), 19280, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+0), 19280, 0, DmaR_Evt1);
	_NN_expr_16_in_1=19280; _SN_expr_16_in_1=19280;
	_C_expr_16_out_0=0; _SC_expr_16_out_0=19280;
	_SP_expr_16_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_16_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+0), 19280, 0, DmaR_Evt2);
	_N_expr_16_in_0=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<14; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==13), D0Ind_NextLast = ((D0Ind+1)==13), D0Ind_NextNextLast = ((D0Ind+2)==13);
		/*================================= Prepare Tiles ===================================*/
		_SN_expr_16_in_0 = 0;
		if (!(D0Ind_Last)) {
			_N_expr_16_in_0 = _N_expr_16_in_0 + (19280); _SN_expr_16_in_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		_SNN_expr_16_in_1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_16_in_1 = _NN_expr_16_in_1 + (19280); _SNN_expr_16_in_1 = ((D0Ind_NextNextLast)?16640:19280); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_16_in_0 */
		if (_SN_expr_16_in_0) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_16_in_0+_N_expr_16_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_16_in_0), 0, DmaR_Evt2);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_16_in_1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_16_in_1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_16_in_1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_16_in_1+_NN_expr_16_in_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280*((D0Ind_Total)%2)),
					1*(_SNN_expr_16_in_1), 0, UchanHR1);
		}
		if (_SN_expr_16_in_1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_16_in_1), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		KerArg0->I0 = (unsigned int) ((D0Ind_Last)?16640:19280);
		KerArg0->expr_16_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+38560+19280*((D0Ind_Total)%2));
		KerArg0->expr_16_in_1 = (unsigned char *__restrict__ ) (main_1_L1_Memory+77120+19280*((D0Ind_Total)%2));
		KerArg0->expr_16_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+19280*((D0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) s90_kernel, (void *) KerArg0);
		__CALL(s90_kernel, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_expr_16_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_16_out_0 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_16_out_0+_C_expr_16_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+19280*((D0Ind_Total)%2)),
				_SC_expr_16_out_0, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_expr_16_out_0 = _SC_expr_16_out_0;
		_SN_expr_16_in_1 = _SNN_expr_16_in_1;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_expr_16_out_0 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_16_out_0 = _C_expr_16_out_0 + (19280); _SC_expr_16_out_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_16_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S92__conv_5_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 66832 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 16]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 16705], Tile1: [16705, 16705, 16705], Tile2; [33410, 16705, 16705]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 33416 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 1], Tile1: [1, 16705, 1], Tile2; [2, 16705, 1]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16705, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=16705; _LC_Out=1;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<16; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==15), T0Ind_NextLast = ((T0Ind+1)==15);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (16705); _SN_In = (16705); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16708*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+16708*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33416+16708*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33416+16708*((T0Ind_Total)%2)),
					_SC_Out, 16, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1); _LC_Out = (1); _SC_Out = (16705*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S95__conv_5_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 110580 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerConv_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerConvLinReduct_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 22][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 22 logical tiles, 22 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 22:[65x14, 20:65x16, 65x7], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 22:[65x14, 20:65x16, 65x7], 16][D0, [0 x 16, 16]]
		Tile0: [0, 14560, 14560], Tile1: [10400, 16640, 16640], Tile2; [22880, 16640, 16640]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33280 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33344 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33360 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 33376 (Total Size: 2304 )[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 22 logical tiles, 1 physical tiles
			@ 35680 (Total Size: 1069120 )[Tile0, 22:[65x12, 20:65x12, 65x5], 64][D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][Tile0, 22:[65x12], 64]
		Tile0: [0, 49920, 49920], Tile1: [0, 49920, 49920], Tile2; [0, 49920, 49920]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 22 logical tiles, 22 physical tiles
			@ 85600 (Total Size: 267280 )[Tile0, 22:[65x12, 20:65x12, 65x5], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 22:[65x12], 16]
		Tile0: [0, 12480, 12480], Tile1: [12480, 12480, 12480], Tile2; [24960, 12480, 12480]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 22 logical tiles, 1 physical tiles
			@ 110560 (Total Size: 20 )[Tile0, 22:[20x1, 20:20x1, 20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 22:[20x1, 20:20x1, 20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->Filter = (unsigned short * __restrict__) (main_1_L1_Memory+33376);
	KerArg2->Bias = (int * __restrict__) (main_1_L1_Memory+33280);
	KerArg2->Out = (unsigned char * __restrict__) (main_1_L1_Memory+35680);
	KerArg2->Scale = (unsigned char * __restrict__) (main_1_L1_Memory+33344);
	KerArg2->ScaleN = (unsigned char * __restrict__) (main_1_L1_Memory+33360);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InW = (unsigned short int) (65);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutW = (unsigned short int) (65);
	KerArg2->Pad_Val = (unsigned short int) (101);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947351);
	KerArg2->Dx = (unsigned char) (2);
	KerArg2->Dy = (unsigned char) (2);
	KerArg3->In = (int *__restrict__) (main_1_L1_Memory+35680);
	KerArg3->Feat = (unsigned short int) (16);
	KerArg3->W = (unsigned short int) (65);
	KerArg3->Scale = (unsigned char *__restrict__) (main_1_L1_Memory+33344);
	KerArg3->ScaleN = (unsigned char *__restrict__) (main_1_L1_Memory+33360);
	KerArg3->Infos = (signed char *__restrict__) (main_1_L1_Memory+110560);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=12480;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 14560, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33376), 2304, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+110560), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33344), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33360), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1, D1Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<22; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==21), T0Ind_NextLast = ((T0Ind+1)==21), T0Ind_NextNextLast = ((T0Ind+2)==21);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (12480-(2080*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?455:1040)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-260000); _SN_In = (910*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16640*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (main_1_L1_Memory+0+16640*((T0Ind_Total)%2));
				KerArg2->Tile_InH = (unsigned short int) (((T0Ind_Last)?7:16)-2*(T0Ind==0));
				KerArg2->Tile_OutH = (unsigned short int) (T0Ind_Last?5:12);
				KerArg2->Pad = (v4s) ((v4s){2,2,2*(T0Ind==0),2*(T0Ind_Last)});
				KerArg2->W_Offset = (int) (((int *)(main_1_L1_Memory+110560))[4]);
				KerConv3x3Stride1_DxDy_NE16(KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg3->Out = (void *__restrict__) (main_1_L1_Memory+85600+12480*((T0Ind_Total)%2));
			KerArg3->H = (unsigned short int) (T0Ind_Last?5:12);
			AT_FORK(gap_ncore(), (void *) KerReduct_CC_NoScale_LeakyReLU_USQ8, (void *) KerArg3);
			__CALL(KerReduct_CC_NoScale_LeakyReLU_USQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+12480*((T0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+12480*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+85600+12480*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (12480); _SC_Out = (((T0Ind_NextLast)?325:780)*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+12480*((T0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S96__conv_5_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 115648 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 10]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 28912], Tile1: [28912, 28912, 28912], Tile2; [57824, 28912, 28912]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57824 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 1807], Tile1: [1807, 28912, 1807], Tile2; [3614, 28912, 1807]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 28912, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+28912), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912), 28912, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28912, 0, DmaR_Evt1);
	_NN_In=28912; _SN_In=28912;
	_C_Out=0; _SC_Out=28912; _LC_Out=1807;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<10; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==9), T0Ind_NextLast = ((T0Ind+1)==9), T0Ind_NextNextLast = ((T0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_In = _NN_In + (28912); _SNN_In = ((T0Ind_NextNextLast)?7072:28912); 
				}
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912*((T0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28912*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+28912*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+57824+28912*((T0Ind_Total)%2));
			KerArg0->H = (unsigned short int) (T0Ind_Last?442:1807);
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57824+28912*((T0Ind_Total)%2)),
					_SC_Out, 16705, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1807); _LC_Out = ((T0Ind_NextLast)?442:1807); _SC_Out = (16*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S98__conv_5_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	CNN_UFpsFps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 267280, Tiled: 10]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57840 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (main_1_L1_Memory+115680);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28920;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28920, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115680), 8, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D0Ind=0; D0Ind<10; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
			int D0Ind_Last = (D0Ind==9), D0Ind_NextLast = ((D0Ind+1)==9), D0Ind_NextNextLast = ((D0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(D0Ind_Last)) {
				_N_In = _N_In + (28920); _SN_In = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_N_In = _N_In + (-260280); _SN_In = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28920*((D0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_D0 =========================*/
			KerArg0->In = (unsigned char *__restrict__) (main_1_L1_Memory+0+28920*((D0Ind_Total)%2));
			KerArg0->Out = (signed char *__restrict__) (main_1_L1_Memory+57840+28920*((D0Ind_Total)%2));
			KerArg0->W = (unsigned short int) ((D0Ind_Last)?7000:28920);
			AT_FORK(gap_ncore(), (void *) CNN_UFpsFpsScaled, (void *) KerArg0);
			__CALL(CNN_UFpsFpsScaled, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57840+28920*((D0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(D0Ind_Last)) {
				_C_Out = _C_Out + (28920); _SC_Out = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_C_Out = _C_Out + (-260280); _SC_Out = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S99__conv_5_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115120 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S100_expr_25(
		unsigned char * __restrict__ expr_25_in_0,
		signed char * __restrict__ expr_25_in_1,
		unsigned char * __restrict__ expr_25_out_0,
		signed char * __restrict__ expr_25_out_1)

{
	/* Shared L1: 102800 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	s100_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_expr_25_in_0;
	unsigned int _SN_expr_25_in_0;
	unsigned int _LN_expr_25_in_0;
	unsigned int _P_expr_25_out_0, _C_expr_25_out_0;
	unsigned int _SPP_expr_25_out_0, _SP_expr_25_out_0, _SC_expr_25_out_0;
	unsigned int _LPP_expr_25_out_0, _LP_expr_25_out_0, _LC_expr_25_out_0;
	unsigned int _P_expr_25_out_1, _C_expr_25_out_1;
	unsigned int _SPP_expr_25_out_1, _SP_expr_25_out_1, _SC_expr_25_out_1;
	unsigned int _LPP_expr_25_out_1, _LP_expr_25_out_1, _LC_expr_25_out_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 4112, Tiled: 1][D1 Dim: Init: 65, Tiled: 17][Tile0 Dim: 1]
	Ker Arg: expr_25_in_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_25_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32896 (Total Size: 4112 )[D0, [0 x 4112, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4112, 4112]]
		Tile0: [0, 4112, 4112], Tile1: [0, 4112, 4112], Tile2; [0, 4112, 4112]
	Ker Arg: expr_25_out_0, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 37008 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_25_out_1, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 69904 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (4112);
	KerArg0->expr_25_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+32896);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_25_out_0=0; _SC_expr_25_out_0=16448; _LC_expr_25_out_0=4;
	_SPP_expr_25_out_0=0; _SP_expr_25_out_0=0;
	_C_expr_25_out_1=0; _SC_expr_25_out_1=16448; _LC_expr_25_out_1=4;
	_SPP_expr_25_out_1=0; _SP_expr_25_out_1=0;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_25_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16448, 65, 4, 0, DmaR_Evt1);
	_N_expr_25_in_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_25_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+32896), 4112, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_25_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (D1Ind=0; D1Ind<17; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==16), D1Ind_NextLast = ((D1Ind+1)==16), D1Ind_NextNextLast = ((D1Ind+2)==16);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_25_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_25_in_0 = _N_expr_25_in_0 + (4); _LN_expr_25_in_0 = ((D1Ind_NextLast)?1:4); _SN_expr_25_in_0 = (4112*_LN_expr_25_in_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_25_in_0 */
			if (_SN_expr_25_in_0) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_25_in_0+_N_expr_25_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16448*((D1Ind_Total+1)%2)),
						1*(_SN_expr_25_in_0), 65, _LN_expr_25_in_0, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:4);
			KerArg0->expr_25_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16448*((D1Ind_Total)%2));
			KerArg0->expr_25_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+37008+16448*((D1Ind_Total)%2));
			KerArg0->expr_25_out_1 = (signed char *__restrict__ ) (main_1_L1_Memory+69904+16448*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) s100_kernel, (void *) KerArg0);
			__CALL(s100_kernel, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_25_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_25_out_0 */
			if (_SPP_expr_25_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_25_out_0 */
			if (_SP_expr_25_out_0) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_25_out_0+_P_expr_25_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_25_out_0, 65, _LP_expr_25_out_0, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+37008+16448*((D1Ind_Total)%2)),
					_SC_expr_25_out_0, 1, DmaW_Evt1);
			if (_SP_expr_25_out_1) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_25_out_1 */
			if (_SPP_expr_25_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_25_out_1 */
			if (_SP_expr_25_out_1) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_25_out_1+_P_expr_25_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_25_out_1, 65, _LP_expr_25_out_1, 1, UchanHR2);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+69904+16448*((D1Ind_Total)%2)),
					_SC_expr_25_out_1, 1, DmaW_Evt2);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_25_out_0 = _SP_expr_25_out_0;_LPP_expr_25_out_0 = _LP_expr_25_out_0;
			_P_expr_25_out_0 = _C_expr_25_out_0;_SP_expr_25_out_0 = _SC_expr_25_out_0;_LP_expr_25_out_0 = _LC_expr_25_out_0;
			_SPP_expr_25_out_1 = _SP_expr_25_out_1;_LPP_expr_25_out_1 = _LP_expr_25_out_1;
			_P_expr_25_out_1 = _C_expr_25_out_1;_SP_expr_25_out_1 = _SC_expr_25_out_1;_LP_expr_25_out_1 = _LC_expr_25_out_1;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_25_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_25_out_0 = _C_expr_25_out_0 + (4); _LC_expr_25_out_0 = ((D1Ind_NextLast)?1:4); _SC_expr_25_out_0 = (4112*_LC_expr_25_out_0); 
			}
			_SC_expr_25_out_1 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_25_out_1 = _C_expr_25_out_1 + (4); _LC_expr_25_out_1 = ((D1Ind_NextLast)?1:4); _SC_expr_25_out_1 = (4112*_LC_expr_25_out_1); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_25_out_0 */
	if (_SPP_expr_25_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_25_out_0 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_25_out_0+_P_expr_25_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)), _SP_expr_25_out_0, 65, _LP_expr_25_out_0, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write expr_25_out_0 */
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_25_out_1 */
	if (_SPP_expr_25_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_25_out_1 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_25_out_1+_P_expr_25_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total+-1)%2)), _SP_expr_25_out_1, 65, _LP_expr_25_out_1, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_25_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S101__conv_5_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT)

{
	/* Shared L1: 115504 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	expr_24_args_t S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	Ker Arg: RsqrtLUT, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115120 (Total Size: 384 )[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		Tile0: [0, 384, 384], Tile1: [0, 384, 384], Tile2; [0, 384, 384]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->Feat = (unsigned short int) (1);
	KerArg1->RsqrtLUT = (unsigned int * __restrict__) (main_1_L1_Memory+115120);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) RsqrtLUT+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115120), 384, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		KerArg1->expr_24_in_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->expr_24_out_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->W = (unsigned short int) (T0Ind_Last?624:872);
		AT_FORK(gap_ncore(), (void *) expr_24, (void *) KerArg1);
		__CALL(expr_24, KerArg1);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S104_expr_26(
		unsigned char * __restrict__ expr_26_in_0,
		signed char * __restrict__ expr_26_in_1,
		signed char * __restrict__ expr_26_in_2,
		signed char * __restrict__ expr_26_in_3,
		unsigned char * __restrict__ expr_26_out_0)

{
	/* Shared L1: 67104 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s104_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int D2Ind, D2Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _P_expr_26_out_0, _C_expr_26_out_0;
	unsigned int _SPP_expr_26_out_0, _SP_expr_26_out_0, _SC_expr_26_out_0;
	unsigned int _NN_expr_26_in_0;
	unsigned int _SN_expr_26_in_0, _SNN_expr_26_in_0;
	unsigned int _N_expr_26_in_1;
	unsigned int _SN_expr_26_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 16][D1 Dim: Init: 257, Tiled: 2][D2 Dim: Init: 65, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_26_out_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 0 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_26_in_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 33280 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_26_in_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 66560 (Total Size: 4112 )[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		Tile0: [0, 256, 256], Tile1: [256, 1, 1], Tile2; [257, 256, 256]
	Ker Arg: expr_26_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67072 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: expr_26_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67088 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1);
	KerArg0->I2 = (unsigned int) (65);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_26_out_0=0; _SC_expr_26_out_0=16640;
	_SPP_expr_26_out_0=0; _SP_expr_26_out_0=0;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_26_in_0+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33280+0), 16640, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_26_in_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_26_in_0+16640), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33280+16640), 65, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33280+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+0), 16640, 0, DmaR_Evt1);
	_NN_expr_26_in_0=16640; _SN_expr_26_in_0=65;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_26_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+0), 256, 0, DmaR_Evt2);
	_N_expr_26_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_26_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67072), 16, 0, DmaR_Evt3);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_26_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67088), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read expr_26_in_3 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<16; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==15), D0Ind_NextLast = ((D0Ind+1)==15), D0Ind_NextNextLast = ((D0Ind+2)==15);
		for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1), D1Ind_NextNextLast = ((D1Ind+2)==1);
			/*================================= Prepare Tiles ===================================*/
			_SNN_expr_26_in_0 = 0;
			if (!(D1Ind_Last)) {
				if (!(1)) {
					_NN_expr_26_in_0 = _NN_expr_26_in_0 + (16640); _SNN_expr_26_in_0 = (((1)?1:256)*(65)); 
				} else if (!(D0Ind_Last)) {
					_NN_expr_26_in_0 = _NN_expr_26_in_0 + (16705)+(-16640); _SNN_expr_26_in_0 = (256*(65)); 
				}
			} else if (!(D0Ind_Last)) {
				_NN_expr_26_in_0 = _NN_expr_26_in_0 + 0; _SNN_expr_26_in_0 = (((D1Ind_Last)?1:256)*(65)); 
			}
			_SN_expr_26_in_1 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_26_in_1 = _N_expr_26_in_1 + (256); _SN_expr_26_in_1 = ((1)?1:256); 
			} else if (!(D0Ind_Last)) {
				_N_expr_26_in_1 = _N_expr_26_in_1 + (257)+(-256); _SN_expr_26_in_1 = (256); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_26_in_0 */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_26_in_0 before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_expr_26_in_0) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_26_in_0+_NN_expr_26_in_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33280+16640*((D1Ind_Total)%2)),
						1*(_SNN_expr_26_in_0), 0, UchanHR1);
			}
			if (_SN_expr_26_in_0) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+33280+16640*((D1Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+16640*((D1Ind_Total+1)%2)),
						1*(_SN_expr_26_in_0), 0, DmaR_Evt1);
			}
			AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_26_in_1 */
			if (_SN_expr_26_in_1) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_26_in_1+_N_expr_26_in_1), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+256*((D1Ind_Total+1)%2)),
						1*(_SN_expr_26_in_1), 0, DmaR_Evt2);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D2 */
				int D2Ind_Last = 1;
				{ /* Single iteration on Tile0 */
					int T0Ind_Last = 1;
				} /* End iteration on Tile0 */
				/*====================== Call Kernel LOC_D2 =========================*/
				KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:256);
				KerArg0->expr_26_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+33280+16640*((D1Ind_Total)%2));
				KerArg0->expr_26_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+66560+256*((D1Ind_Total)%2));
				KerArg0->expr_26_in_2 = (signed char *__restrict__ ) (main_1_L1_Memory+67072+((D0Ind)*1));
				KerArg0->expr_26_in_3 = (signed char *__restrict__ ) (main_1_L1_Memory+67088+((D0Ind)*1));
				KerArg0->expr_26_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16640*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) s104_kernel, (void *) KerArg0);
				__CALL(s104_kernel, KerArg0);
			} /* End iteration on D2 */
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_26_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_26_out_0 */
			if (_SPP_expr_26_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_26_out_0 */
			if (_SP_expr_26_out_0) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_26_out_0+_P_expr_26_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16640*((D1Ind_Total+-1)%2)),
						_SP_expr_26_out_0, 1, UchanHR2);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16640*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16640*((D1Ind_Total)%2)),
					_SC_expr_26_out_0, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_26_out_0 = _SP_expr_26_out_0;
			_P_expr_26_out_0 = _C_expr_26_out_0;_SP_expr_26_out_0 = _SC_expr_26_out_0;
			_SN_expr_26_in_0 = _SNN_expr_26_in_0;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_26_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_26_out_0 = _C_expr_26_out_0 + (16640); _SC_expr_26_out_0 = (((1)?1:256)*(65)); 
			} else if (!(D0Ind_Last)) {
				_C_expr_26_out_0 = _C_expr_26_out_0 + (16705)+(-16640); _SC_expr_26_out_0 = (256*(65)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_26_out_0 */
	if (_SPP_expr_26_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_26_out_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_26_out_0+_P_expr_26_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16640*((D1Ind_Total+-1)%2)), _SP_expr_26_out_0, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_26_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S105_expr_19(
		unsigned char * __restrict__ expr_19_in_0,
		unsigned char * __restrict__ expr_19_in_1,
		unsigned char * __restrict__ expr_19_out_0)

{
	/* Shared L1: 115680 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s105_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_19_out_0;
	unsigned int _SP_expr_19_out_0, _SC_expr_19_out_0;
	unsigned int _N_expr_19_in_0;
	unsigned int _SN_expr_19_in_0;
	unsigned int _NN_expr_19_in_1;
	unsigned int _SN_expr_19_in_1, _SNN_expr_19_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 267280, Tiled: 14][Tile0 Dim: 1]
	Ker Arg: expr_19_out_0, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 0 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_19_in_0, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 38560 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_19_in_1, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 77120 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_19_in_1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 19280, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_19_in_1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_19_in_1+19280), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280), 19280, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+0), 19280, 0, DmaR_Evt1);
	_NN_expr_19_in_1=19280; _SN_expr_19_in_1=19280;
	_C_expr_19_out_0=0; _SC_expr_19_out_0=19280;
	_SP_expr_19_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_19_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+0), 19280, 0, DmaR_Evt2);
	_N_expr_19_in_0=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<14; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==13), D0Ind_NextLast = ((D0Ind+1)==13), D0Ind_NextNextLast = ((D0Ind+2)==13);
		/*================================= Prepare Tiles ===================================*/
		_SN_expr_19_in_0 = 0;
		if (!(D0Ind_Last)) {
			_N_expr_19_in_0 = _N_expr_19_in_0 + (19280); _SN_expr_19_in_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		_SNN_expr_19_in_1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_19_in_1 = _NN_expr_19_in_1 + (19280); _SNN_expr_19_in_1 = ((D0Ind_NextNextLast)?16640:19280); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_19_in_0 */
		if (_SN_expr_19_in_0) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_19_in_0+_N_expr_19_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_19_in_0), 0, DmaR_Evt2);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_19_in_1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_19_in_1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_19_in_1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_19_in_1+_NN_expr_19_in_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280*((D0Ind_Total)%2)),
					1*(_SNN_expr_19_in_1), 0, UchanHR1);
		}
		if (_SN_expr_19_in_1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_19_in_1), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		KerArg0->I0 = (unsigned int) ((D0Ind_Last)?16640:19280);
		KerArg0->expr_19_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+38560+19280*((D0Ind_Total)%2));
		KerArg0->expr_19_in_1 = (unsigned char *__restrict__ ) (main_1_L1_Memory+77120+19280*((D0Ind_Total)%2));
		KerArg0->expr_19_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+19280*((D0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) s105_kernel, (void *) KerArg0);
		__CALL(s105_kernel, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_expr_19_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_19_out_0 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_19_out_0+_C_expr_19_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+19280*((D0Ind_Total)%2)),
				_SC_expr_19_out_0, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_expr_19_out_0 = _SC_expr_19_out_0;
		_SN_expr_19_in_1 = _SNN_expr_19_in_1;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_expr_19_out_0 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_19_out_0 = _C_expr_19_out_0 + (19280); _SC_expr_19_out_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_19_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S107__conv_6_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 66832 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 16]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 16705], Tile1: [16705, 16705, 16705], Tile2; [33410, 16705, 16705]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 33416 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 1], Tile1: [1, 16705, 1], Tile2; [2, 16705, 1]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16705, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=16705; _LC_Out=1;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<16; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==15), T0Ind_NextLast = ((T0Ind+1)==15);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (16705); _SN_In = (16705); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16708*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+16708*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33416+16708*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33416+16708*((T0Ind_Total)%2)),
					_SC_Out, 16, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1); _LC_Out = (1); _SC_Out = (16705*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S110__conv_6_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 93940 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerConv_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerConvLinReduct_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 29][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 29 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 29:[65x13, 27:65x17, 65x9], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 29:[65x13, 27:65x17, 65x9], 16][D0, [0 x 16, 16]]
		Tile0: [0, 13520, 13520], Tile1: [5200, 17680, 17680], Tile2; [14560, 17680, 17680]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 35360 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 35424 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 35440 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 35456 (Total Size: 2304 )[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 1 physical tiles
			@ 37760 (Total Size: 1069120 )[Tile0, 29:[65x9, 27:65x9, 65x5], 64][D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][Tile0, 29:[65x9], 64]
		Tile0: [0, 37440, 37440], Tile1: [0, 37440, 37440], Tile2; [0, 37440, 37440]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 29 logical tiles, 29 physical tiles
			@ 75200 (Total Size: 267280 )[Tile0, 29:[65x9, 27:65x9, 65x5], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 29:[65x9], 16]
		Tile0: [0, 9360, 9360], Tile1: [9360, 9360, 9360], Tile2; [18720, 9360, 9360]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 1 physical tiles
			@ 93920 (Total Size: 20 )[Tile0, 29:[20x1, 27:20x1, 20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 29:[20x1, 27:20x1, 20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->Filter = (unsigned short * __restrict__) (main_1_L1_Memory+35456);
	KerArg2->Bias = (int * __restrict__) (main_1_L1_Memory+35360);
	KerArg2->Out = (unsigned char * __restrict__) (main_1_L1_Memory+37760);
	KerArg2->Scale = (unsigned char * __restrict__) (main_1_L1_Memory+35424);
	KerArg2->ScaleN = (unsigned char * __restrict__) (main_1_L1_Memory+35440);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InW = (unsigned short int) (65);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutW = (unsigned short int) (65);
	KerArg2->Pad_Val = (unsigned short int) (102);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947351);
	KerArg2->Dx = (unsigned char) (4);
	KerArg2->Dy = (unsigned char) (4);
	KerArg3->In = (int *__restrict__) (main_1_L1_Memory+37760);
	KerArg3->Feat = (unsigned short int) (16);
	KerArg3->W = (unsigned short int) (65);
	KerArg3->Scale = (unsigned char *__restrict__) (main_1_L1_Memory+35424);
	KerArg3->ScaleN = (unsigned char *__restrict__) (main_1_L1_Memory+35440);
	KerArg3->Infos = (signed char *__restrict__) (main_1_L1_Memory+93920);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=9360;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 13520, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+35456), 2304, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+35360), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+93920), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+35424), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+35440), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1, D1Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<29; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==28), T0Ind_NextLast = ((T0Ind+1)==28), T0Ind_NextNextLast = ((T0Ind+2)==28);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (9360-(4160*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?585:1105)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-257920); _SN_In = (845*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+17680*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (main_1_L1_Memory+0+17680*((T0Ind_Total)%2));
				KerArg2->Tile_InH = (unsigned short int) (((T0Ind_Last)?9:17)-4*(T0Ind==0));
				KerArg2->Tile_OutH = (unsigned short int) (T0Ind_Last?5:9);
				KerArg2->Pad = (v4s) ((v4s){4,4,4*(T0Ind==0),4*(T0Ind_Last)});
				KerArg2->W_Offset = (int) (((int *)(main_1_L1_Memory+93920))[4]);
				KerConv3x3Stride1_DxDy_NE16(KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg3->Out = (void *__restrict__) (main_1_L1_Memory+75200+9360*((T0Ind_Total)%2));
			KerArg3->H = (unsigned short int) (T0Ind_Last?5:9);
			AT_FORK(gap_ncore(), (void *) KerReduct_CC_NoScale_LeakyReLU_USQ8, (void *) KerArg3);
			__CALL(KerReduct_CC_NoScale_LeakyReLU_USQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+9360*((T0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+9360*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+75200+9360*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (9360); _SC_Out = (((T0Ind_NextLast)?325:585)*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+9360*((T0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S111__conv_6_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 115648 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 10]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 28912], Tile1: [28912, 28912, 28912], Tile2; [57824, 28912, 28912]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57824 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 1807], Tile1: [1807, 28912, 1807], Tile2; [3614, 28912, 1807]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 28912, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+28912), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912), 28912, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28912, 0, DmaR_Evt1);
	_NN_In=28912; _SN_In=28912;
	_C_Out=0; _SC_Out=28912; _LC_Out=1807;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<10; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==9), T0Ind_NextLast = ((T0Ind+1)==9), T0Ind_NextNextLast = ((T0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_In = _NN_In + (28912); _SNN_In = ((T0Ind_NextNextLast)?7072:28912); 
				}
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912*((T0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28912*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28912*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+28912*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+57824+28912*((T0Ind_Total)%2));
			KerArg0->H = (unsigned short int) (T0Ind_Last?442:1807);
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57824+28912*((T0Ind_Total)%2)),
					_SC_Out, 16705, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1807); _LC_Out = ((T0Ind_NextLast)?442:1807); _SC_Out = (16*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S113__conv_6_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	CNN_UFpsFps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 267280, Tiled: 10]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57840 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (main_1_L1_Memory+115680);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28920;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28920, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115680), 8, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D0Ind=0; D0Ind<10; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
			int D0Ind_Last = (D0Ind==9), D0Ind_NextLast = ((D0Ind+1)==9), D0Ind_NextNextLast = ((D0Ind+2)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(D0Ind_Last)) {
				_N_In = _N_In + (28920); _SN_In = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_N_In = _N_In + (-260280); _SN_In = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28920*((D0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_D0 =========================*/
			KerArg0->In = (unsigned char *__restrict__) (main_1_L1_Memory+0+28920*((D0Ind_Total)%2));
			KerArg0->Out = (signed char *__restrict__) (main_1_L1_Memory+57840+28920*((D0Ind_Total)%2));
			KerArg0->W = (unsigned short int) ((D0Ind_Last)?7000:28920);
			AT_FORK(gap_ncore(), (void *) CNN_UFpsFpsScaled, (void *) KerArg0);
			__CALL(CNN_UFpsFpsScaled, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total+-1)%2)),
						_SP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57840+28920*((D0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(D0Ind_Last)) {
				_C_Out = _C_Out + (28920); _SC_Out = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_C_Out = _C_Out + (-260280); _SC_Out = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+28920*((D0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S114__conv_6_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115120 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S115_expr_28(
		unsigned char * __restrict__ expr_28_in_0,
		signed char * __restrict__ expr_28_in_1,
		unsigned char * __restrict__ expr_28_out_0,
		signed char * __restrict__ expr_28_out_1)

{
	/* Shared L1: 102800 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	s115_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_expr_28_in_0;
	unsigned int _SN_expr_28_in_0;
	unsigned int _LN_expr_28_in_0;
	unsigned int _P_expr_28_out_0, _C_expr_28_out_0;
	unsigned int _SPP_expr_28_out_0, _SP_expr_28_out_0, _SC_expr_28_out_0;
	unsigned int _LPP_expr_28_out_0, _LP_expr_28_out_0, _LC_expr_28_out_0;
	unsigned int _P_expr_28_out_1, _C_expr_28_out_1;
	unsigned int _SPP_expr_28_out_1, _SP_expr_28_out_1, _SC_expr_28_out_1;
	unsigned int _LPP_expr_28_out_1, _LP_expr_28_out_1, _LC_expr_28_out_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 4112, Tiled: 1][D1 Dim: Init: 65, Tiled: 17][Tile0 Dim: 1]
	Ker Arg: expr_28_in_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_28_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32896 (Total Size: 4112 )[D0, [0 x 4112, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4112, 4112]]
		Tile0: [0, 4112, 4112], Tile1: [0, 4112, 4112], Tile2; [0, 4112, 4112]
	Ker Arg: expr_28_out_0, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 37008 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_28_out_1, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 69904 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (4112);
	KerArg0->expr_28_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+32896);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_28_out_0=0; _SC_expr_28_out_0=16448; _LC_expr_28_out_0=4;
	_SPP_expr_28_out_0=0; _SP_expr_28_out_0=0;
	_C_expr_28_out_1=0; _SC_expr_28_out_1=16448; _LC_expr_28_out_1=4;
	_SPP_expr_28_out_1=0; _SP_expr_28_out_1=0;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_28_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16448, 65, 4, 0, DmaR_Evt1);
	_N_expr_28_in_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_28_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+32896), 4112, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_28_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (D1Ind=0; D1Ind<17; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==16), D1Ind_NextLast = ((D1Ind+1)==16), D1Ind_NextNextLast = ((D1Ind+2)==16);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_28_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_28_in_0 = _N_expr_28_in_0 + (4); _LN_expr_28_in_0 = ((D1Ind_NextLast)?1:4); _SN_expr_28_in_0 = (4112*_LN_expr_28_in_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_28_in_0 */
			if (_SN_expr_28_in_0) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_28_in_0+_N_expr_28_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16448*((D1Ind_Total+1)%2)),
						1*(_SN_expr_28_in_0), 65, _LN_expr_28_in_0, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:4);
			KerArg0->expr_28_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16448*((D1Ind_Total)%2));
			KerArg0->expr_28_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+37008+16448*((D1Ind_Total)%2));
			KerArg0->expr_28_out_1 = (signed char *__restrict__ ) (main_1_L1_Memory+69904+16448*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) s115_kernel, (void *) KerArg0);
			__CALL(s115_kernel, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_28_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_28_out_0 */
			if (_SPP_expr_28_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_28_out_0 */
			if (_SP_expr_28_out_0) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_28_out_0+_P_expr_28_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_28_out_0, 65, _LP_expr_28_out_0, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+37008+16448*((D1Ind_Total)%2)),
					_SC_expr_28_out_0, 1, DmaW_Evt1);
			if (_SP_expr_28_out_1) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_28_out_1 */
			if (_SPP_expr_28_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_28_out_1 */
			if (_SP_expr_28_out_1) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_28_out_1+_P_expr_28_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_28_out_1, 65, _LP_expr_28_out_1, 1, UchanHR2);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+69904+16448*((D1Ind_Total)%2)),
					_SC_expr_28_out_1, 1, DmaW_Evt2);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_28_out_0 = _SP_expr_28_out_0;_LPP_expr_28_out_0 = _LP_expr_28_out_0;
			_P_expr_28_out_0 = _C_expr_28_out_0;_SP_expr_28_out_0 = _SC_expr_28_out_0;_LP_expr_28_out_0 = _LC_expr_28_out_0;
			_SPP_expr_28_out_1 = _SP_expr_28_out_1;_LPP_expr_28_out_1 = _LP_expr_28_out_1;
			_P_expr_28_out_1 = _C_expr_28_out_1;_SP_expr_28_out_1 = _SC_expr_28_out_1;_LP_expr_28_out_1 = _LC_expr_28_out_1;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_28_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_28_out_0 = _C_expr_28_out_0 + (4); _LC_expr_28_out_0 = ((D1Ind_NextLast)?1:4); _SC_expr_28_out_0 = (4112*_LC_expr_28_out_0); 
			}
			_SC_expr_28_out_1 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_28_out_1 = _C_expr_28_out_1 + (4); _LC_expr_28_out_1 = ((D1Ind_NextLast)?1:4); _SC_expr_28_out_1 = (4112*_LC_expr_28_out_1); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_28_out_0 */
	if (_SPP_expr_28_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_28_out_0 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_28_out_0+_P_expr_28_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+834736+16448*((D1Ind_Total+-1)%2)), _SP_expr_28_out_0, 65, _LP_expr_28_out_0, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write expr_28_out_0 */
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_28_out_1 */
	if (_SPP_expr_28_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_28_out_1 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_28_out_1+_P_expr_28_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)), _SP_expr_28_out_1, 65, _LP_expr_28_out_1, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_28_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S116__conv_6_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT)

{
	/* Shared L1: 115504 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	expr_27_args_t S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	Ker Arg: RsqrtLUT, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115120 (Total Size: 384 )[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		Tile0: [0, 384, 384], Tile1: [0, 384, 384], Tile2; [0, 384, 384]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->Feat = (unsigned short int) (1);
	KerArg1->RsqrtLUT = (unsigned int * __restrict__) (main_1_L1_Memory+115120);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) RsqrtLUT+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115120), 384, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		KerArg1->expr_27_in_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->expr_27_out_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->W = (unsigned short int) (T0Ind_Last?624:872);
		AT_FORK(gap_ncore(), (void *) expr_27, (void *) KerArg1);
		__CALL(expr_27, KerArg1);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S119_expr_29(
		unsigned char * __restrict__ expr_29_in_0,
		signed char * __restrict__ expr_29_in_1,
		signed char * __restrict__ expr_29_in_2,
		signed char * __restrict__ expr_29_in_3,
		unsigned char * __restrict__ expr_29_out_0)

{
	/* Shared L1: 67104 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s119_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int D2Ind, D2Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _P_expr_29_out_0, _C_expr_29_out_0;
	unsigned int _SPP_expr_29_out_0, _SP_expr_29_out_0, _SC_expr_29_out_0;
	unsigned int _NN_expr_29_in_0;
	unsigned int _SN_expr_29_in_0, _SNN_expr_29_in_0;
	unsigned int _N_expr_29_in_1;
	unsigned int _SN_expr_29_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 16][D1 Dim: Init: 257, Tiled: 2][D2 Dim: Init: 65, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_29_out_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 0 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_29_in_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 33280 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_29_in_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 66560 (Total Size: 4112 )[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		Tile0: [0, 256, 256], Tile1: [256, 1, 1], Tile2; [257, 256, 256]
	Ker Arg: expr_29_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67072 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: expr_29_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67088 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1);
	KerArg0->I2 = (unsigned int) (65);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_29_out_0=0; _SC_expr_29_out_0=16640;
	_SPP_expr_29_out_0=0; _SP_expr_29_out_0=0;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_29_in_0+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+0), 16640, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_29_in_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_29_in_0+16640), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+16640), 65, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+0), 16640, 0, DmaR_Evt1);
	_NN_expr_29_in_0=16640; _SN_expr_29_in_0=65;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_29_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+0), 256, 0, DmaR_Evt2);
	_N_expr_29_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_29_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67072), 16, 0, DmaR_Evt3);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_29_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67088), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read expr_29_in_3 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<16; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==15), D0Ind_NextLast = ((D0Ind+1)==15), D0Ind_NextNextLast = ((D0Ind+2)==15);
		for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1), D1Ind_NextNextLast = ((D1Ind+2)==1);
			/*================================= Prepare Tiles ===================================*/
			_SNN_expr_29_in_0 = 0;
			if (!(D1Ind_Last)) {
				if (!(1)) {
					_NN_expr_29_in_0 = _NN_expr_29_in_0 + (16640); _SNN_expr_29_in_0 = (((1)?1:256)*(65)); 
				} else if (!(D0Ind_Last)) {
					_NN_expr_29_in_0 = _NN_expr_29_in_0 + (16705)+(-16640); _SNN_expr_29_in_0 = (256*(65)); 
				}
			} else if (!(D0Ind_Last)) {
				_NN_expr_29_in_0 = _NN_expr_29_in_0 + 0; _SNN_expr_29_in_0 = (((D1Ind_Last)?1:256)*(65)); 
			}
			_SN_expr_29_in_1 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_29_in_1 = _N_expr_29_in_1 + (256); _SN_expr_29_in_1 = ((1)?1:256); 
			} else if (!(D0Ind_Last)) {
				_N_expr_29_in_1 = _N_expr_29_in_1 + (257)+(-256); _SN_expr_29_in_1 = (256); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_29_in_0 */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_29_in_0 before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_expr_29_in_0) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_29_in_0+_NN_expr_29_in_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+16640*((D1Ind_Total)%2)),
						1*(_SNN_expr_29_in_0), 0, UchanHR1);
			}
			if (_SN_expr_29_in_0) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+567840+16640*((D1Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+16640*((D1Ind_Total+1)%2)),
						1*(_SN_expr_29_in_0), 0, DmaR_Evt1);
			}
			AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_29_in_1 */
			if (_SN_expr_29_in_1) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_29_in_1+_N_expr_29_in_1), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+256*((D1Ind_Total+1)%2)),
						1*(_SN_expr_29_in_1), 0, DmaR_Evt2);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D2 */
				int D2Ind_Last = 1;
				{ /* Single iteration on Tile0 */
					int T0Ind_Last = 1;
				} /* End iteration on Tile0 */
				/*====================== Call Kernel LOC_D2 =========================*/
				KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:256);
				KerArg0->expr_29_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+33280+16640*((D1Ind_Total)%2));
				KerArg0->expr_29_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+66560+256*((D1Ind_Total)%2));
				KerArg0->expr_29_in_2 = (signed char *__restrict__ ) (main_1_L1_Memory+67072+((D0Ind)*1));
				KerArg0->expr_29_in_3 = (signed char *__restrict__ ) (main_1_L1_Memory+67088+((D0Ind)*1));
				KerArg0->expr_29_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16640*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) s119_kernel, (void *) KerArg0);
				__CALL(s119_kernel, KerArg0);
			} /* End iteration on D2 */
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_29_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_29_out_0 */
			if (_SPP_expr_29_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_29_out_0 */
			if (_SP_expr_29_out_0) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_29_out_0+_P_expr_29_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+16640*((D1Ind_Total+-1)%2)),
						_SP_expr_29_out_0, 1, UchanHR2);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+16640*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16640*((D1Ind_Total)%2)),
					_SC_expr_29_out_0, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_expr_29_out_0 = _SP_expr_29_out_0;
			_P_expr_29_out_0 = _C_expr_29_out_0;_SP_expr_29_out_0 = _SC_expr_29_out_0;
			_SN_expr_29_in_0 = _SNN_expr_29_in_0;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_29_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_29_out_0 = _C_expr_29_out_0 + (16640); _SC_expr_29_out_0 = (((1)?1:256)*(65)); 
			} else if (!(D0Ind_Last)) {
				_C_expr_29_out_0 = _C_expr_29_out_0 + (16705)+(-16640); _SC_expr_29_out_0 = (256*(65)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_29_out_0 */
	if (_SPP_expr_29_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_29_out_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_29_out_0+_P_expr_29_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+16640*((D1Ind_Total+-1)%2)), _SP_expr_29_out_0, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_29_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S120_expr_20(
		unsigned char * __restrict__ expr_20_in_0,
		unsigned char * __restrict__ expr_20_in_1,
		unsigned char * __restrict__ expr_20_out_0)

{
	/* Shared L1: 115680 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s120_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_20_out_0;
	unsigned int _SP_expr_20_out_0, _SC_expr_20_out_0;
	unsigned int _N_expr_20_in_0;
	unsigned int _SN_expr_20_in_0;
	unsigned int _NN_expr_20_in_1;
	unsigned int _SN_expr_20_in_1, _SNN_expr_20_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 267280, Tiled: 14][Tile0 Dim: 1]
	Ker Arg: expr_20_out_0, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 0 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_20_in_0, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 38560 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	Ker Arg: expr_20_in_1, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 14 logical tiles, 14 physical tiles
			@ 77120 (Total Size: 267280 )[D0, [13 x 19280, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [13 x 19280, 16640]]
		Tile0: [0, 19280, 19280], Tile1: [19280, 19280, 19280], Tile2; [38560, 19280, 19280]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_20_in_1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 19280, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_20_in_1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_20_in_1+19280), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280), 19280, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+0), 19280, 0, DmaR_Evt1);
	_NN_expr_20_in_1=19280; _SN_expr_20_in_1=19280;
	_C_expr_20_out_0=0; _SC_expr_20_out_0=19280;
	_SP_expr_20_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_20_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+0), 19280, 0, DmaR_Evt2);
	_N_expr_20_in_0=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<14; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==13), D0Ind_NextLast = ((D0Ind+1)==13), D0Ind_NextNextLast = ((D0Ind+2)==13);
		/*================================= Prepare Tiles ===================================*/
		_SN_expr_20_in_0 = 0;
		if (!(D0Ind_Last)) {
			_N_expr_20_in_0 = _N_expr_20_in_0 + (19280); _SN_expr_20_in_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		_SNN_expr_20_in_1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_20_in_1 = _NN_expr_20_in_1 + (19280); _SNN_expr_20_in_1 = ((D0Ind_NextNextLast)?16640:19280); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_20_in_0 */
		if (_SN_expr_20_in_0) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_20_in_0+_N_expr_20_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38560+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_20_in_0), 0, DmaR_Evt2);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_20_in_1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_20_in_1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_20_in_1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_20_in_1+_NN_expr_20_in_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280*((D0Ind_Total)%2)),
					1*(_SNN_expr_20_in_1), 0, UchanHR1);
		}
		if (_SN_expr_20_in_1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+19280*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77120+19280*((D0Ind_Total+1)%2)),
					1*(_SN_expr_20_in_1), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		KerArg0->I0 = (unsigned int) ((D0Ind_Last)?16640:19280);
		KerArg0->expr_20_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+38560+19280*((D0Ind_Total)%2));
		KerArg0->expr_20_in_1 = (unsigned char *__restrict__ ) (main_1_L1_Memory+77120+19280*((D0Ind_Total)%2));
		KerArg0->expr_20_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+19280*((D0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) s120_kernel, (void *) KerArg0);
		__CALL(s120_kernel, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_expr_20_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_20_out_0 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_20_out_0+_C_expr_20_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+19280*((D0Ind_Total)%2)),
				_SC_expr_20_out_0, 1, DmaW_Evt1);

		
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_expr_20_out_0 = _SC_expr_20_out_0;
		_SN_expr_20_in_1 = _SNN_expr_20_in_1;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_expr_20_out_0 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_20_out_0 = _C_expr_20_out_0 + (19280); _SC_expr_20_out_0 = ((D0Ind_NextLast)?16640:19280); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_20_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S122__conv_7_conv1d_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 66832 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	unsigned int _LPP_Out, _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 16]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 16705], Tile1: [16705, 16705, 16705], Tile2; [33410, 16705, 16705]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 33416 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 1], Tile1: [1, 16705, 1], Tile2; [2, 16705, 1]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=16705; _LC_Out=1;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16705, 0, DmaR_Evt1);
	_N_In=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (T0Ind=0; T0Ind<16; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==15), T0Ind_NextLast = ((T0Ind+1)==15), T0Ind_NextNextLast = ((T0Ind+2)==15);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (16705); _SN_In = (16705); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16708*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+16708*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33416+16708*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out&&D0Ind!=10) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16708*((T0Ind_Total+-1)%2)),
						_SP_Out, 16, _LP_Out, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16708*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33416+16708*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);

			if (T0Ind == 9){
				
				
				AT_L2_WAIT(0, DmaR_Evt1);
				AT_L2_WAIT(0, DmaW_Evt1);

				main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + 801840;
				main_2CNN(G2_Input,output_imaginary,output_real);

				if (_SN_In) {
					AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16708*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
				}
				
			}
			
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;_LPP_Out = _LP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1); _LC_Out = (1); _SC_Out = (16705*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0+16708*((T0Ind_Total+-1)%2)), _SP_Out, 16, _LP_Out, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S125__conv_7_conv1d_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 110580 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerConv_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerConvLinReduct_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 29][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 29 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 29:[65x17, 27:65x25, 65x13], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 29:[65x17, 27:65x25, 65x13], 16][D0, [0 x 16, 16]]
		Tile0: [0, 17680, 17680], Tile1: [1040, 26000, 26000], Tile2; [10400, 26000, 26000]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 52000 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 52064 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 52080 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 52096 (Total Size: 2304 )[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2304, 2304]][D0, [0 x 2304, 2304]]
		Tile0: [0, 2304, 2304], Tile1: [0, 2304, 2304], Tile2; [0, 2304, 2304]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 1 physical tiles
			@ 54400 (Total Size: 1069120 )[Tile0, 29:[65x9, 27:65x9, 65x5], 64][D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][Tile0, 29:[65x9], 64]
		Tile0: [0, 37440, 37440], Tile1: [0, 37440, 37440], Tile2; [0, 37440, 37440]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 29 logical tiles, 29 physical tiles
			@ 91840 (Total Size: 267280 )[Tile0, 29:[65x9, 27:65x9, 65x5], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 29:[65x9], 16]
		Tile0: [0, 9360, 9360], Tile1: [9360, 9360, 9360], Tile2; [18720, 9360, 9360]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 1 physical tiles
			@ 110560 (Total Size: 20 )[Tile0, 29:[20x1, 27:20x1, 20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 29:[20x1, 27:20x1, 20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->Filter = (unsigned short * __restrict__) (main_1_L1_Memory+52096);
	KerArg2->Bias = (int * __restrict__) (main_1_L1_Memory+52000);
	KerArg2->Out = (unsigned char * __restrict__) (main_1_L1_Memory+54400);
	KerArg2->Scale = (unsigned char * __restrict__) (main_1_L1_Memory+52064);
	KerArg2->ScaleN = (unsigned char * __restrict__) (main_1_L1_Memory+52080);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InW = (unsigned short int) (65);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutW = (unsigned short int) (65);
	KerArg2->Pad_Val = (unsigned short int) (93);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947351);
	KerArg2->Dx = (unsigned char) (8);
	KerArg2->Dy = (unsigned char) (8);
	KerArg3->In = (int *__restrict__) (main_1_L1_Memory+54400);
	KerArg3->Feat = (unsigned short int) (16);
	KerArg3->W = (unsigned short int) (65);
	KerArg3->Scale = (unsigned char *__restrict__) (main_1_L1_Memory+52064);
	KerArg3->ScaleN = (unsigned char *__restrict__) (main_1_L1_Memory+52080);
	KerArg3->Infos = (signed char *__restrict__) (main_1_L1_Memory+110560);
	KerArg3->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), 17680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+1040), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+26000), 26000, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 17680, 0, DmaR_Evt1);
	_NN_In=1040; _SN_In=26000;
	_C_Out=0; _SC_Out=9360;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+52096), 2304, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+52000), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+110560), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+52064), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+52080), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<29; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==28), T0Ind_NextLast = ((T0Ind+1)==28), T0Ind_NextNextLast = ((T0Ind+2)==28);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_In = _NN_In + (9360); _SNN_In = (((T0Ind_NextNextLast)?845:1625)*(16)); 
				} else if (!(1)) {
					_NN_In = _NN_In + (-253760); _SNN_In = (1105*(16)); 
				}
			} else if (!((1))) {
				_NN_In = _NN_In + (9360-8320); _SNN_In = (1105*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+26000*((T0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if ((T0Ind)==27) {
				AT_TileClear((main_1_L1_Memory+0+26000*((T0Ind_Total)%2)), 65, 25, (16), 1, 3, 93, 0, 1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+26000*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+26000*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (main_1_L1_Memory+0+26000*((T0Ind_Total)%2));
				KerArg2->Tile_InH = (unsigned short int) (((T0Ind_Last)?13:25)-8*(T0Ind==0));
				KerArg2->Tile_OutH = (unsigned short int) (T0Ind_Last?5:9);
				KerArg2->Pad = (v4s) ((v4s){8,8,8*(T0Ind==0),8*(T0Ind_Last)});
				KerArg2->W_Offset = (int) (((int *)(main_1_L1_Memory+110560))[4]);
				KerConv3x3Stride1_DxDy_NE16(KerArg2);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg3->Out = (void *__restrict__) (main_1_L1_Memory+91840+9360*((T0Ind_Total)%2));
			KerArg3->H = (unsigned short int) (T0Ind_Last?5:9);
			AT_FORK(gap_ncore(), (void *) KerReduct_CC_NoScale_LeakyReLU_USQ8, (void *) KerArg3);
			__CALL(KerReduct_CC_NoScale_LeakyReLU_USQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+91840+9360*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (9360); _SC_Out = (((T0Ind_NextLast)?325:585)*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S126__conv_7_conv1d_Conv_fusion_trans_out0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 115648 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 10]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 28912], Tile1: [28912, 28912, 28912], Tile2; [57824, 28912, 28912]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57824 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 10:[16x1807, 8:16x1807, 16x442], 1]
		Tile0: [0, 28912, 1807], Tile1: [1807, 28912, 1807], Tile2; [3614, 28912, 1807]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28912, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=28912; _LC_Out=1807;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<10; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==9), T0Ind_NextLast = ((T0Ind+1)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (28912); _SN_In = ((T0Ind_NextLast)?7072:28912); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28912*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+28912*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+57824+28912*((T0Ind_Total)%2));
			KerArg0->H = (unsigned short int) (T0Ind_Last?442:1807);
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57824+28912*((T0Ind_Total)%2)),
					_SC_Out, 16705, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1807); _LC_Out = ((T0Ind_NextLast)?442:1807); _SC_Out = (16*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S128__conv_7_conv1d_Conv_reshape_out_qout0(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115688 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	CNN_UFpsFps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 267280, Tiled: 10]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 0 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 10 logical tiles, 10 physical tiles
			@ 57840 (Total Size: 267280 )[D0, [9 x 28920, 7000]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [9 x 28920, 7000]]
		Tile0: [0, 28920, 28920], Tile1: [28920, 28920, 28920], Tile2; [57840, 28920, 28920]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (main_1_L1_Memory+115680);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 28920, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=28920;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115680), 8, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		for (D0Ind=0; D0Ind<10; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
			int D0Ind_Last = (D0Ind==9), D0Ind_NextLast = ((D0Ind+1)==9);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(D0Ind_Last)) {
				_N_In = _N_In + (28920); _SN_In = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_N_In = _N_In + (-260280); _SN_In = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+28920*((D0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_D0 =========================*/
			KerArg0->In = (unsigned char *__restrict__) (main_1_L1_Memory+0+28920*((D0Ind_Total)%2));
			KerArg0->Out = (signed char *__restrict__) (main_1_L1_Memory+57840+28920*((D0Ind_Total)%2));
			KerArg0->W = (unsigned short int) ((D0Ind_Last)?7000:28920);
			AT_FORK(gap_ncore(), (void *) CNN_UFpsFpsScaled, (void *) KerArg0);
			__CALL(CNN_UFpsFpsScaled, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+57840+28920*((D0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(D0Ind_Last)) {
				_C_Out = _C_Out + (28920); _SC_Out = ((D0Ind_NextLast)?7000:28920); 
			} else if (!(1)) {
				_C_Out = _C_Out + (-260280); _SC_Out = (28920); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S129__conv_7_reg1_ReduceMean(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115120 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (56680); _SN_In = ((T0Ind_NextLast)?40560:56680); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S130_expr_31(
		unsigned char * __restrict__ expr_31_in_0,
		signed char * __restrict__ expr_31_in_1,
		unsigned char * __restrict__ expr_31_out_0,
		signed char * __restrict__ expr_31_out_1)

{
	/* Shared L1: 102800 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	s130_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_expr_31_in_0;
	unsigned int _SN_expr_31_in_0;
	unsigned int _LN_expr_31_in_0;
	unsigned int _C_expr_31_out_0;
	unsigned int _SP_expr_31_out_0, _SC_expr_31_out_0;
	unsigned int _LP_expr_31_out_0, _LC_expr_31_out_0;
	unsigned int _P_expr_31_out_1, _C_expr_31_out_1;
	unsigned int _SPP_expr_31_out_1, _SP_expr_31_out_1, _SC_expr_31_out_1;
	unsigned int _LPP_expr_31_out_1, _LP_expr_31_out_1, _LC_expr_31_out_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 4112, Tiled: 1][D1 Dim: Init: 65, Tiled: 17][Tile0 Dim: 1]
	Ker Arg: expr_31_in_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_31_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 32896 (Total Size: 4112 )[D0, [0 x 4112, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 4112, 4112]]
		Tile0: [0, 4112, 4112], Tile1: [0, 4112, 4112], Tile2; [0, 4112, 4112]
	Ker Arg: expr_31_out_0, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 37008 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	Ker Arg: expr_31_out_1, Tiled Space: D1
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 17 logical tiles, 17 physical tiles
			@ 69904 (Total Size: 267280 )[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][D1, [16 x 16448, 4112]]
		Tile0: [0, 16448, 4], Tile1: [4, 16448, 4], Tile2; [8, 16448, 4]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (4112);
	KerArg0->expr_31_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+32896);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_31_out_1=0; _SC_expr_31_out_1=16448; _LC_expr_31_out_1=4;
	_SPP_expr_31_out_1=0; _SP_expr_31_out_1=0;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_31_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16448, 65, 4, 0, DmaR_Evt1);
	_N_expr_31_in_0=0;
	_C_expr_31_out_0=0; _SC_expr_31_out_0=16448; _LC_expr_31_out_0=4;
	_SP_expr_31_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_31_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+32896), 4112, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_31_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		for (D1Ind=0; D1Ind<17; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==16), D1Ind_NextLast = ((D1Ind+1)==16), D1Ind_NextNextLast = ((D1Ind+2)==16);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_31_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_31_in_0 = _N_expr_31_in_0 + (4); _LN_expr_31_in_0 = ((D1Ind_NextLast)?1:4); _SN_expr_31_in_0 = (4112*_LN_expr_31_in_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_31_in_0 */
			if (_SN_expr_31_in_0) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_31_in_0+_N_expr_31_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16448*((D1Ind_Total+1)%2)),
						1*(_SN_expr_31_in_0), 65, _LN_expr_31_in_0, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:4);
			KerArg0->expr_31_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16448*((D1Ind_Total)%2));
			KerArg0->expr_31_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+37008+16448*((D1Ind_Total)%2));
			KerArg0->expr_31_out_1 = (signed char *__restrict__ ) (main_1_L1_Memory+69904+16448*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) s130_kernel, (void *) KerArg0);
			__CALL(s130_kernel, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_31_out_0) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_31_out_0 */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_31_out_0+_C_expr_31_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+37008+16448*((D1Ind_Total)%2)),
					_SC_expr_31_out_0, 65, _LC_expr_31_out_0, 1, DmaW_Evt2);
			if (_SP_expr_31_out_1) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_31_out_1 */
			if (_SPP_expr_31_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_31_out_1 */
			if (_SP_expr_31_out_1) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_31_out_1+_P_expr_31_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)),
						_SP_expr_31_out_1, 65, _LP_expr_31_out_1, 1, UchanHR1);
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+69904+16448*((D1Ind_Total)%2)),
					_SC_expr_31_out_1, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_expr_31_out_0 = _SC_expr_31_out_0;_LP_expr_31_out_0 = _LC_expr_31_out_0;
			_SPP_expr_31_out_1 = _SP_expr_31_out_1;_LPP_expr_31_out_1 = _LP_expr_31_out_1;
			_P_expr_31_out_1 = _C_expr_31_out_1;_SP_expr_31_out_1 = _SC_expr_31_out_1;_LP_expr_31_out_1 = _LC_expr_31_out_1;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_31_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_31_out_0 = _C_expr_31_out_0 + (4); _LC_expr_31_out_0 = ((D1Ind_NextLast)?1:4); _SC_expr_31_out_0 = (4112*_LC_expr_31_out_0); 
			}
			_SC_expr_31_out_1 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_31_out_1 = _C_expr_31_out_1 + (4); _LC_expr_31_out_1 = ((D1Ind_NextLast)?1:4); _SC_expr_31_out_1 = (4112*_LC_expr_31_out_1); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_31_out_0 */
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_31_out_1 */
	if (_SPP_expr_31_out_1) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_31_out_1 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_31_out_1+_P_expr_31_out_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+16448*((D1Ind_Total+-1)%2)), _SP_expr_31_out_1, 65, _LP_expr_31_out_1, 1, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait current uDMA write expr_31_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S131__conv_7_reg1_ReduceMean_1_fusion(
		signed char * __restrict__ In,
		signed char * __restrict__ Out,
		signed char * __restrict__ Infos,
		unsigned int * __restrict__ RsqrtLUT)

{
	/* Shared L1: 115504 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerGlobalPool_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	expr_30_args_t S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 5]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[65x872, 3:65x872, 65x624], 1]
		Tile0: [0, 56680, 56680], Tile1: [56680, 56680, 56680], Tile2; [113360, 56680, 56680]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 113360 (Total Size: 4112 )[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x872, 3:1x872, 1x624], 1]
		Tile0: [0, 872, 872], Tile1: [872, 872, 872], Tile2; [1744, 872, 872]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115104 (Total Size: 13 )[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[13x1, 3:13x1, 13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	Ker Arg: RsqrtLUT, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115120 (Total Size: 384 )[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[96x1, 3:96x1, 96x1], 4]
		Tile0: [0, 384, 384], Tile1: [0, 384, 384], Tile2; [0, 384, 384]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (void * __restrict__) (main_1_L1_Memory+115104);
	KerArg1->H = (unsigned short int) (1);
	KerArg1->Feat = (unsigned short int) (1);
	KerArg1->RsqrtLUT = (unsigned int * __restrict__) (main_1_L1_Memory+115120);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), 56680, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+56680), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680), 56680, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 56680, 0, DmaR_Evt1);
	_NN_In=56680; _SN_In=56680;
	_C_Out=0; _SC_Out=872;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) RsqrtLUT+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115120), 384, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+115104), 13, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4), T0Ind_NextNextLast = ((T0Ind+2)==4);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(T0Ind_Last)) {
			if (!(T0Ind_NextLast)) {
				_NN_In = _NN_In + (56680); _SNN_In = ((T0Ind_NextNextLast)?40560:56680); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680*((T0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+534560+56680*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+56680*((T0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void * __restrict__) (main_1_L1_Memory+0+56680*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?624:872);
		KerArg0->Out = (int * __restrict__) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) KerParGlobalAvgPoolFullFeat_SQ8, (void *) KerArg0);
		__CALL(KerParGlobalAvgPoolFullFeat_SQ8, KerArg0);
		KerArg1->expr_30_in_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->expr_30_out_0 = (signed char *__restrict__ ) (main_1_L1_Memory+113360+872*((T0Ind_Total)%2));
		KerArg1->W = (unsigned short int) (T0Ind_Last?624:872);
		AT_FORK(gap_ncore(), (void *) expr_30, (void *) KerArg1);
		__CALL(expr_30, KerArg1);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+113360+872*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In = _SNN_In;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (872); _SC_Out = ((T0Ind_NextLast)?624:872); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S134_expr_32(
		unsigned char * __restrict__ expr_32_in_0,
		signed char * __restrict__ expr_32_in_1,
		signed char * __restrict__ expr_32_in_2,
		signed char * __restrict__ expr_32_in_3,
		unsigned char * __restrict__ expr_32_out_0)

{
	/* Shared L1: 67104 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	s134_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int D2Ind, D2Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_32_out_0;
	unsigned int _SP_expr_32_out_0, _SC_expr_32_out_0;
	unsigned int _N_expr_32_in_0;
	unsigned int _SN_expr_32_in_0;
	unsigned int _N_expr_32_in_1;
	unsigned int _SN_expr_32_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 16][D1 Dim: Init: 257, Tiled: 2][D2 Dim: Init: 65, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_32_out_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 0 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_32_in_0, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 33280 (Total Size: 267280 )[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 16705, 16705]][D1, [1 x 16640, 65]][D2, [0 x 16640, 16640]]
		Tile0: [0, 16640, 16640], Tile1: [16640, 65, 65], Tile2; [16705, 16640, 16640]
	Ker Arg: expr_32_in_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 32 logical tiles, 32 physical tiles
			@ 66560 (Total Size: 4112 )[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 257, 257]][D1, [1 x 256, 1]]
		Tile0: [0, 256, 256], Tile1: [256, 1, 1], Tile2; [257, 256, 256]
	Ker Arg: expr_32_in_2, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67072 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: expr_32_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 16 logical tiles, 1 physical tiles
			@ 67088 (Total Size: 16 )[D0, [15 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [15 x 1, 1]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1);
	KerArg0->I2 = (unsigned int) (65);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_32_out_0=0; _SC_expr_32_out_0=16640;
	_SP_expr_32_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_32_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+0), 16640, 0, DmaR_Evt1);
	_N_expr_32_in_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_32_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+0), 256, 0, DmaR_Evt2);
	_N_expr_32_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_32_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67072), 16, 0, DmaR_Evt3);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_32_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+67088), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read expr_32_in_3 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<16; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==15), D0Ind_NextLast = ((D0Ind+1)==15);
		for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_32_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_32_in_0 = _N_expr_32_in_0 + (16640); _SN_expr_32_in_0 = (((1)?1:256)*(65)); 
			} else if (!(D0Ind_Last)) {
				_N_expr_32_in_0 = _N_expr_32_in_0 + (16705)+(-16640); _SN_expr_32_in_0 = (256*(65)); 
			}
			_SN_expr_32_in_1 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_32_in_1 = _N_expr_32_in_1 + (256); _SN_expr_32_in_1 = ((1)?1:256); 
			} else if (!(D0Ind_Last)) {
				_N_expr_32_in_1 = _N_expr_32_in_1 + (257)+(-256); _SN_expr_32_in_1 = (256); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_32_in_0 */
			if (_SN_expr_32_in_0) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_32_in_0+_N_expr_32_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33280+16640*((D1Ind_Total+1)%2)),
						1*(_SN_expr_32_in_0), 0, DmaR_Evt1);
			}
			AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_32_in_1 */
			if (_SN_expr_32_in_1) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_32_in_1+_N_expr_32_in_1), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66560+256*((D1Ind_Total+1)%2)),
						1*(_SN_expr_32_in_1), 0, DmaR_Evt2);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D2 */
				int D2Ind_Last = 1;
				{ /* Single iteration on Tile0 */
					int T0Ind_Last = 1;
				} /* End iteration on Tile0 */
				/*====================== Call Kernel LOC_D2 =========================*/
				KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:256);
				KerArg0->expr_32_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+33280+16640*((D1Ind_Total)%2));
				KerArg0->expr_32_in_1 = (signed char *__restrict__ ) (main_1_L1_Memory+66560+256*((D1Ind_Total)%2));
				KerArg0->expr_32_in_2 = (signed char *__restrict__ ) (main_1_L1_Memory+67072+((D0Ind)*1));
				KerArg0->expr_32_in_3 = (signed char *__restrict__ ) (main_1_L1_Memory+67088+((D0Ind)*1));
				KerArg0->expr_32_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+16640*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) s134_kernel, (void *) KerArg0);
				__CALL(s134_kernel, KerArg0);
			} /* End iteration on D2 */
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_32_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_32_out_0 */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_32_out_0+_C_expr_32_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16640*((D1Ind_Total)%2)),
					_SC_expr_32_out_0, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_expr_32_out_0 = _SC_expr_32_out_0;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_32_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_32_out_0 = _C_expr_32_out_0 + (16640); _SC_expr_32_out_0 = (((1)?1:256)*(65)); 
			} else if (!(D0Ind_Last)) {
				_C_expr_32_out_0 = _C_expr_32_out_0 + (16705)+(-16640); _SC_expr_32_out_0 = (256*(65)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_32_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S135_expr_4(
		unsigned char * __restrict__ expr_4_in_0,
		unsigned char * __restrict__ expr_4_in_1,
		unsigned char * __restrict__ expr_4_in_2,
		unsigned char * __restrict__ expr_4_in_3,
		unsigned char * __restrict__ expr_4_in_4,
		unsigned char * __restrict__ expr_4_in_5,
		unsigned char * __restrict__ expr_4_in_6,
		unsigned char * __restrict__ expr_4_in_7,
		unsigned char * __restrict__ expr_4_out_0)

{
	/* Shared L1: 115632 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt7, *DmaR_Evt7 = &_DmaR_Evt7;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_L2_EVENT _DmaR_Evt4, *DmaR_Evt4 = &_DmaR_Evt4;
	AT_L2_EVENT _DmaR_Evt5, *DmaR_Evt5 = &_DmaR_Evt5;
	AT_L2_EVENT _DmaR_Evt6, *DmaR_Evt6 = &_DmaR_Evt6;
	AT_L2_EVENT _DmaR_Evt8, *DmaR_Evt8 = &_DmaR_Evt8;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR3, *UchanHR3 = &_UchanHR3;
	AT_DEFAULTRAM_CL_EVENT _UchanHR4, *UchanHR4 = &_UchanHR4;
	AT_DEFAULTRAM_CL_EVENT _UchanHR5, *UchanHR5 = &_UchanHR5;
	AT_DEFAULTRAM_CL_EVENT _UchanHR6, *UchanHR6 = &_UchanHR6;
	s135_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_4_out_0;
	unsigned int _SP_expr_4_out_0, _SC_expr_4_out_0;
	unsigned int _N_expr_4_in_0;
	unsigned int _SN_expr_4_in_0;
	unsigned int _NN_expr_4_in_1;
	unsigned int _SN_expr_4_in_1, _SNN_expr_4_in_1;
	unsigned int _NN_expr_4_in_2;
	unsigned int _SN_expr_4_in_2, _SNN_expr_4_in_2;
	unsigned int _NN_expr_4_in_3;
	unsigned int _SN_expr_4_in_3, _SNN_expr_4_in_3;
	unsigned int _NN_expr_4_in_4;
	unsigned int _SN_expr_4_in_4, _SNN_expr_4_in_4;
	unsigned int _NN_expr_4_in_5;
	unsigned int _SN_expr_4_in_5, _SNN_expr_4_in_5;
	unsigned int _NN_expr_4_in_6;
	unsigned int _SN_expr_4_in_6, _SNN_expr_4_in_6;
	unsigned int _N_expr_4_in_7;
	unsigned int _SN_expr_4_in_7;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 267280, Tiled: 42][Tile0 Dim: 1]
	Ker Arg: expr_4_out_0, Tiled Space: D0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 42 logical tiles, 42 physical tiles
			@ 0 (Total Size: 267280 )[D0, [41 x 6424, 3896]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [41 x 6424, 3896]]
		Tile0: [0, 6424, 6424], Tile1: [6424, 6424, 6424], Tile2; [12848, 6424, 6424]
	Ker Arg: expr_4_in_0, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 42 logical tiles, 42 physical tiles
			@ 12848 (Total Size: 267280 )[D0, [41 x 6424, 3896]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [41 x 6424, 3896]]
		Tile0: [0, 6424, 6424], Tile1: [6424, 6424, 6424], Tile2; [12848, 6424, 6424]
	Ker Arg: expr_4_in_1, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 42 logical tiles, 42 physical tiles
			@ 25696 (Total Size: 267280 )[D0, [41 x 6424, 3896]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [41 x 6424, 3896]]
		Tile0: [0, 6424, 6424], Tile1: [6424, 6424, 6424], Tile2; [12848, 6424, 6424]
	Ker Arg: expr_4_in_2, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 42 logical tiles, 42 physical tiles
			@ 38544 (Total Size: 267280 )[D0, [41 x 6424, 3896]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [41 x 6424, 3896]]
		Tile0: [0, 6424, 6424], Tile1: [6424, 6424, 6424], Tile2; [12848, 6424, 6424]
	Ker Arg: expr_4_in_3, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 42 logical tiles, 42 physical tiles
			@ 51392 (Total Size: 267280 )[D0, [41 x 6424, 3896]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [41 x 6424, 3896]]
		Tile0: [0, 6424, 6424], Tile1: [6424, 6424, 6424], Tile2; [12848, 6424, 6424]
	Ker Arg: expr_4_in_4, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 42 logical tiles, 42 physical tiles
			@ 64240 (Total Size: 267280 )[D0, [41 x 6424, 3896]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [41 x 6424, 3896]]
		Tile0: [0, 6424, 6424], Tile1: [6424, 6424, 6424], Tile2; [12848, 6424, 6424]
	Ker Arg: expr_4_in_5, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 42 logical tiles, 42 physical tiles
			@ 77088 (Total Size: 267280 )[D0, [41 x 6424, 3896]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [41 x 6424, 3896]]
		Tile0: [0, 6424, 6424], Tile1: [6424, 6424, 6424], Tile2; [12848, 6424, 6424]
	Ker Arg: expr_4_in_6, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 42 logical tiles, 42 physical tiles
			@ 89936 (Total Size: 267280 )[D0, [41 x 6424, 3896]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [41 x 6424, 3896]]
		Tile0: [0, 6424, 6424], Tile1: [6424, 6424, 6424], Tile2; [12848, 6424, 6424]
	Ker Arg: expr_4_in_7, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 42 logical tiles, 42 physical tiles
			@ 102784 (Total Size: 267280 )[D0, [41 x 6424, 3896]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [41 x 6424, 3896]]
		Tile0: [0, 6424, 6424], Tile1: [6424, 6424, 6424], Tile2; [12848, 6424, 6424]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), 6424, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_4_in_1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_1+6424), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+6424), 6424, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+25696+0), 6424, 0, DmaR_Evt1);
	_NN_expr_4_in_1=6424; _SN_expr_4_in_1=6424;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_2+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+814688+0), 6424, 0, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read expr_4_in_2 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_2+6424), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+814688+6424), 6424, 0, UchanHR2);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+814688+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38544+0), 6424, 0, DmaR_Evt2);
	_NN_expr_4_in_2=6424; _SN_expr_4_in_2=6424;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_3+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+827536+0), 6424, 0, UchanHR3);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR3); /* Wait previous uDMA read expr_4_in_3 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_3+6424), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+827536+6424), 6424, 0, UchanHR3);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+827536+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+51392+0), 6424, 0, DmaR_Evt3);
	_NN_expr_4_in_3=6424; _SN_expr_4_in_3=6424;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_4+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+840384+0), 6424, 0, UchanHR4);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR4); /* Wait previous uDMA read expr_4_in_4 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_4+6424), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+840384+6424), 6424, 0, UchanHR4);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+840384+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+64240+0), 6424, 0, DmaR_Evt4);
	_NN_expr_4_in_4=6424; _SN_expr_4_in_4=6424;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_5+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+853232+0), 6424, 0, UchanHR5);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR5); /* Wait previous uDMA read expr_4_in_5 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_5+6424), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+853232+6424), 6424, 0, UchanHR5);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+853232+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77088+0), 6424, 0, DmaR_Evt5);
	_NN_expr_4_in_5=6424; _SN_expr_4_in_5=6424;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_6+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+866080+0), 6424, 0, UchanHR6);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR6); /* Wait previous uDMA read expr_4_in_6 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_6+6424), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+866080+6424), 6424, 0, UchanHR6);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+866080+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+89936+0), 6424, 0, DmaR_Evt6);
	_NN_expr_4_in_6=6424; _SN_expr_4_in_6=6424;
	_C_expr_4_out_0=0; _SC_expr_4_out_0=6424;
	_SP_expr_4_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_4_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+12848+0), 6424, 0, DmaR_Evt7);
	_N_expr_4_in_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_4_in_7+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+102784+0), 6424, 0, DmaR_Evt8);
	_N_expr_4_in_7=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<42; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==41), D0Ind_NextLast = ((D0Ind+1)==41), D0Ind_NextNextLast = ((D0Ind+2)==41);
		/*================================= Prepare Tiles ===================================*/
		_SN_expr_4_in_0 = 0;
		if (!(D0Ind_Last)) {
			_N_expr_4_in_0 = _N_expr_4_in_0 + (6424); _SN_expr_4_in_0 = ((D0Ind_NextLast)?3896:6424); 
		}
		_SNN_expr_4_in_1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_4_in_1 = _NN_expr_4_in_1 + (6424); _SNN_expr_4_in_1 = ((D0Ind_NextNextLast)?3896:6424); 
			}
		}
		_SNN_expr_4_in_2 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_4_in_2 = _NN_expr_4_in_2 + (6424); _SNN_expr_4_in_2 = ((D0Ind_NextNextLast)?3896:6424); 
			}
		}
		_SNN_expr_4_in_3 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_4_in_3 = _NN_expr_4_in_3 + (6424); _SNN_expr_4_in_3 = ((D0Ind_NextNextLast)?3896:6424); 
			}
		}
		_SNN_expr_4_in_4 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_4_in_4 = _NN_expr_4_in_4 + (6424); _SNN_expr_4_in_4 = ((D0Ind_NextNextLast)?3896:6424); 
			}
		}
		_SNN_expr_4_in_5 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_4_in_5 = _NN_expr_4_in_5 + (6424); _SNN_expr_4_in_5 = ((D0Ind_NextNextLast)?3896:6424); 
			}
		}
		_SNN_expr_4_in_6 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_expr_4_in_6 = _NN_expr_4_in_6 + (6424); _SNN_expr_4_in_6 = ((D0Ind_NextNextLast)?3896:6424); 
			}
		}
		_SN_expr_4_in_7 = 0;
		if (!(D0Ind_Last)) {
			_N_expr_4_in_7 = _N_expr_4_in_7 + (6424); _SN_expr_4_in_7 = ((D0Ind_NextLast)?3896:6424); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt7); /* Wait previous DMA read expr_4_in_0 */
		if (_SN_expr_4_in_0) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_4_in_0+_N_expr_4_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+12848+6424*((D0Ind_Total+1)%2)),
					1*(_SN_expr_4_in_0), 0, DmaR_Evt7);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_4_in_1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_4_in_1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_4_in_1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_1+_NN_expr_4_in_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+6424*((D0Ind_Total)%2)),
					1*(_SNN_expr_4_in_1), 0, UchanHR1);
		}
		if (_SN_expr_4_in_1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+801840+6424*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+25696+6424*((D0Ind_Total+1)%2)),
					1*(_SN_expr_4_in_1), 0, DmaR_Evt1);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read expr_4_in_2 */
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_4_in_2 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_4_in_2) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_2+_NN_expr_4_in_2), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+814688+6424*((D0Ind_Total)%2)),
					1*(_SNN_expr_4_in_2), 0, UchanHR2);
		}
		if (_SN_expr_4_in_2) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+814688+6424*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+38544+6424*((D0Ind_Total+1)%2)),
					1*(_SN_expr_4_in_2), 0, DmaR_Evt2);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR3); /* Wait previous uDMA read expr_4_in_3 */
		AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read expr_4_in_3 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_4_in_3) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_3+_NN_expr_4_in_3), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+827536+6424*((D0Ind_Total)%2)),
					1*(_SNN_expr_4_in_3), 0, UchanHR3);
		}
		if (_SN_expr_4_in_3) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+827536+6424*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+51392+6424*((D0Ind_Total+1)%2)),
					1*(_SN_expr_4_in_3), 0, DmaR_Evt3);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR4); /* Wait previous uDMA read expr_4_in_4 */
		AT_L2_WAIT(0, DmaR_Evt4); /* Wait previous DMA read expr_4_in_4 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_4_in_4) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_4+_NN_expr_4_in_4), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+840384+6424*((D0Ind_Total)%2)),
					1*(_SNN_expr_4_in_4), 0, UchanHR4);
		}
		if (_SN_expr_4_in_4) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+840384+6424*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+64240+6424*((D0Ind_Total+1)%2)),
					1*(_SN_expr_4_in_4), 0, DmaR_Evt4);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR5); /* Wait previous uDMA read expr_4_in_5 */
		AT_L2_WAIT(0, DmaR_Evt5); /* Wait previous DMA read expr_4_in_5 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_4_in_5) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_5+_NN_expr_4_in_5), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+853232+6424*((D0Ind_Total)%2)),
					1*(_SNN_expr_4_in_5), 0, UchanHR5);
		}
		if (_SN_expr_4_in_5) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+853232+6424*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+77088+6424*((D0Ind_Total+1)%2)),
					1*(_SN_expr_4_in_5), 0, DmaR_Evt5);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR6); /* Wait previous uDMA read expr_4_in_6 */
		AT_L2_WAIT(0, DmaR_Evt6); /* Wait previous DMA read expr_4_in_6 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_expr_4_in_6) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_in_6+_NN_expr_4_in_6), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+866080+6424*((D0Ind_Total)%2)),
					1*(_SNN_expr_4_in_6), 0, UchanHR6);
		}
		if (_SN_expr_4_in_6) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+866080+6424*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+89936+6424*((D0Ind_Total+1)%2)),
					1*(_SN_expr_4_in_6), 0, DmaR_Evt6);
		}
		AT_L2_WAIT(0, DmaR_Evt8); /* Wait previous DMA read expr_4_in_7 */
		if (_SN_expr_4_in_7) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_4_in_7+_N_expr_4_in_7), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+102784+6424*((D0Ind_Total+1)%2)),
					1*(_SN_expr_4_in_7), 0, DmaR_Evt8);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		KerArg0->I0 = (unsigned int) ((D0Ind_Last)?3896:6424);
		KerArg0->expr_4_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+12848+6424*((D0Ind_Total)%2));
		KerArg0->expr_4_in_1 = (unsigned char *__restrict__ ) (main_1_L1_Memory+25696+6424*((D0Ind_Total)%2));
		KerArg0->expr_4_in_2 = (unsigned char *__restrict__ ) (main_1_L1_Memory+38544+6424*((D0Ind_Total)%2));
		KerArg0->expr_4_in_3 = (unsigned char *__restrict__ ) (main_1_L1_Memory+51392+6424*((D0Ind_Total)%2));
		KerArg0->expr_4_in_4 = (unsigned char *__restrict__ ) (main_1_L1_Memory+64240+6424*((D0Ind_Total)%2));
		KerArg0->expr_4_in_5 = (unsigned char *__restrict__ ) (main_1_L1_Memory+77088+6424*((D0Ind_Total)%2));
		KerArg0->expr_4_in_6 = (unsigned char *__restrict__ ) (main_1_L1_Memory+89936+6424*((D0Ind_Total)%2));
		KerArg0->expr_4_in_7 = (unsigned char *__restrict__ ) (main_1_L1_Memory+102784+6424*((D0Ind_Total)%2));
		KerArg0->expr_4_out_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+0+6424*((D0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) s135_kernel, (void *) KerArg0);
		__CALL(s135_kernel, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_expr_4_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_4_out_0 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_4_out_0+_C_expr_4_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+6424*((D0Ind_Total)%2)),
				_SC_expr_4_out_0, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_expr_4_out_0 = _SC_expr_4_out_0;
		_SN_expr_4_in_1 = _SNN_expr_4_in_1;
		_SN_expr_4_in_2 = _SNN_expr_4_in_2;
		_SN_expr_4_in_3 = _SNN_expr_4_in_3;
		_SN_expr_4_in_4 = _SNN_expr_4_in_4;
		_SN_expr_4_in_5 = _SNN_expr_4_in_5;
		_SN_expr_4_in_6 = _SNN_expr_4_in_6;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_expr_4_out_0 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_4_out_0 = _C_expr_4_out_0 + (6424); _SC_expr_4_out_0 = ((D0Ind_NextLast)?3896:6424); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_4_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S137__reshape_speech_reshape_speech_0_Conv_fusion_trans_in0(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out)

{
	/* Shared L1: 66832 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerMatTranspose_fp_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 1][Tile0 Dim: 16]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 0 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 16705], Tile1: [16705, 16705, 16705], Tile2; [33410, 16705, 16705]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 16 logical tiles, 16 physical tiles
			@ 33416 (Total Size: 267280 )[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 267280, 267280]][Tile0, 16:[16705x1, 14:16705x1, 16705x1], 1]
		Tile0: [0, 16705, 1], Tile1: [1, 16705, 1], Tile2; [2, 16705, 1]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (1);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 16705, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=16705; _LC_Out=1;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<16; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==15), T0Ind_NextLast = ((T0Ind+1)==15);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (16705); _SN_In = (16705); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+16708*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (void *__restrict__) (main_1_L1_Memory+0+16708*((T0Ind_Total)%2));
			KerArg0->Out = (void *__restrict__) (main_1_L1_Memory+33416+16708*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) CNN_Transpose_fps, (void *) KerArg0);
			__CALL(CNN_Transpose_fps, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+33416+16708*((T0Ind_Total)%2)),
					_SC_Out, 16, _LC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (1); _LC_Out = (1); _SC_Out = (16705*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S140__reshape_speech_reshape_speech_0_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8)

{
	/* Shared L1: 112960 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	KerConv_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 1, Tiled: 1][Tile0 Dim: 6][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 0 (Total Size: 267280 )[Tile0, 6:[65x51, 4:65x51, 65x2], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 6:[65x51, 4:65x51, 65x2], 16][D0, [0 x 16, 16]]
		Tile0: [0, 53040, 53040], Tile1: [53040, 53040, 53040], Tile2; [106080, 53040, 53040]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 106080 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 106084 (Total Size: 1 )[D1, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 106088 (Total Size: 1 )[D1, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 106092 (Total Size: 16 )[D1, [0 x 16, 16]][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][D0, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 106108 (Total Size: 16705 )[Tile0, 6:[65x51, 4:65x51, 65x2], 1][D1, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1, 1]][Tile0, 6:[65x51], 1]
		Tile0: [0, 3315, 3315], Tile1: [3315, 3315, 3315], Tile2; [6630, 3315, 3315]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 6 logical tiles, 1 physical tiles
			@ 112740 (Total Size: 20 )[Tile0, 6:[20x1, 4:20x1, 20x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 6:[20x1, 4:20x1, 20x1], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 112760 (Total Size: 72 )[D1, [0 x 72, 72]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 72, 72]]
		Tile0: [0, 72, 72], Tile1: [0, 72, 72], Tile2; [0, 72, 72]
	Ker Arg: SigmoidLUT_u8, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 6 logical tiles, 1 physical tiles
			@ 112832 (Total Size: 128 )[Tile0, 6:[128x1, 4:128x1, 128x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 6:[128x1, 4:128x1, 128x1], 1]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->Filter = (unsigned short * __restrict__) (main_1_L1_Memory+106092);
	KerArg2->Bias = (int * __restrict__) (main_1_L1_Memory+106080);
	KerArg2->Scale = (unsigned char * __restrict__) (main_1_L1_Memory+106084);
	KerArg2->ScaleN = (unsigned char * __restrict__) (main_1_L1_Memory+106088);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InW = (unsigned short int) (65);
	KerArg2->Tile_OutFeat = (unsigned short int) (1);
	KerArg2->Tile_OutW = (unsigned short int) (65);
	KerArg2->Pad_Val = (unsigned short int) (84);
	KerArg2->Pad = (v4s) 0;
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947415);
	KerArg2->BuffOut = (int * __restrict__) (main_1_L1_Memory+112760);
	KerArg2->Infos = (unsigned char * __restrict__) (main_1_L1_Memory+112740);
	KerArg2->Extra = (void * __restrict__) (main_1_L1_Memory+112832);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+0), 53040, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=3315;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) SigmoidLUT_u8+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+112832), 128, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+112740), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+106092), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+106080), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+106084), 1, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+106088), 1, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<6; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==5), T0Ind_NextLast = ((T0Ind+1)==5);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (53040); _SN_In = (((T0Ind_NextLast)?130:3315)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-265200); _SN_In = (3315*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0+53040*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (main_1_L1_Memory+0+53040*((T0Ind_Total)%2));
				KerArg2->Out = (unsigned char * __restrict__) (main_1_L1_Memory+106108+3316*((T0Ind_Total)%2));
				KerArg2->Tile_InH = (unsigned short int) (T0Ind_Last?2:51);
				KerArg2->Tile_OutH = (unsigned short int) (T0Ind_Last?2:51);
				KerArg2->W_Offset = (int) (((int *)(main_1_L1_Memory+112740))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerConv1x1_SmallHW_Stride1Sigmoid_NE16, (void *) KerArg2);
				__CALL(KerConv1x1_SmallHW_Stride1Sigmoid_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+106108+3316*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (3315); _SC_Out = (((T0Ind_NextLast)?130:3315)*(1)); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*====================== Call Kernel LOC_D1_EPILOG =========================*/
	NE16_Disable(
	);
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S142_expr_33(
		unsigned char * __restrict__ expr_33_in_0,
		float * __restrict__ expr_33_out_0)

{
	/* Shared L1: 83528 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	s142_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 16705, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_33_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 66820 )[D0, [0 x 66820, 66820]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 66820, 66820]]
		Tile0: [0, 66820, 66820], Tile1: [0, 66820, 66820], Tile2; [0, 66820, 66820]
	Ker Arg: expr_33_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 66820 (Total Size: 16705 )[D0, [0 x 16705, 16705]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 16705, 16705]]
		Tile0: [0, 16705, 16705], Tile1: [0, 16705, 16705], Tile2; [0, 16705, 16705]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (16705);
	KerArg0->expr_33_in_0 = (unsigned char *__restrict__ ) (main_1_L1_Memory+66820);
	KerArg0->expr_33_out_0 = (float *__restrict__ ) (main_1_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_33_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+66820), 16705, 0, DmaR_Evt1);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_33_in_0 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) s142_kernel, (void *) KerArg0);
		__CALL(s142_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_33_out_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0), 66820, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_33_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  S144__reshape_speech_reshape_speech_0_Conv_reshape_qout0(
		unsigned char * __restrict__ In,
		float * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 83536 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	CNN_UFpsFloat32_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D0 Dim: Init: 16705, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 16705 )[D0, [0 x 16705, 16705]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 16705, 16705]]
		Tile0: [0, 16705, 16705], Tile1: [0, 16705, 16705], Tile2; [0, 16705, 16705]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 16708 (Total Size: 66820 )[D0, [0 x 66820, 66820]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 66820, 66820]]
		Tile0: [0, 66820, 66820], Tile1: [0, 66820, 66820], Tile2; [0, 66820, 66820]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 83528 (Total Size: 8 )[Tile0, 1:[1x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 8]
		Tile0: [0, 8, 8], Tile1: [0, 8, 8], Tile2; [0, 8, 8]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (unsigned char *__restrict__) (main_1_L1_Memory+0);
	KerArg0->Out = (float *__restrict__) (main_1_L1_Memory+16708);
	KerArg0->W = (unsigned short int) (16705);
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Infos = (signed char *__restrict__) (main_1_L1_Memory+83528);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+0), 16705, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+83528), 8, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		{ /* Single iteration on D0 */
			int D0Ind_Last = 1;
			/*====================== Call Kernel LOC_D0 =========================*/
			AT_FORK(gap_ncore(), (void *) CNN_UFpsFloat32, (void *) KerArg0);
			__CALL(CNN_UFpsFloat32, KerArg0);
		} /* End iteration on D0 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_1_L1_Memory+16708), 66820, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
#pragma GCC diagnostic pop
int  main_1CNN_Construct()

{
	int Error;

	AT_DEFAULTRAM_CONF_T DefaultRamConf;
	AT_DEFAULTRAM_CONF_INIT(&DefaultRamConf, AT_MEM_L3_DEFAULTRAM, 0);
	AT_DEFAULTRAM_OPEN(&DefaultRam, &DefaultRamConf, &Error);
	if (Error) return AT_RAM_OPEN_ERROR;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "main_1_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;

	main_1_L3_Memory_Dyn = (AT_DEFAULTRAM_POINTER) AT_DEFAULTRAM_ALLOC(&DefaultRam, 2138240+1677696+296064+32000+801840);
	if (main_1_L3_Memory_Dyn == 0) return AT_RAM_OPEN_ERROR;
	main_1_L2_Memory = (AT_L2_POINTER) AT_L2_ALLOC(0, 20924);
	if (main_1_L2_Memory == 0) return AT_L2_OPEN_ERROR;
	main_1_L2_Memory_Dyn = (AT_L2_POINTER) AT_L2_ALLOC(0, 1169000);//baseline 919312 reached maximum 1100000 to accomodate other networks
	if (main_1_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	main_1_L1_Memory = (AT_L1_POINTER) AT_L1_ALLOC(0, 115688);
	if (main_1_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	AT_DEFAULTFLASH_FS_FC_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	/* Static Moving S1_Infos, size 8 from DefaultFlash at 20824 to (size 8) L2 at 20824..20831 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20824), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20824), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S4_Infos, size 13 from DefaultFlash at 19976 to (size 13) L2 at 19976..19988 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19976), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19976), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S6_Infos, size 13 from DefaultFlash at 19992 to (size 13) L2 at 19992..20004 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19992), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19992), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__mul_302, size 2 from DefaultFlash at 20904 to (size 2) L2 at 20904..20905 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20904), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20904), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__add_303, size 2 from DefaultFlash at 20908 to (size 2) L2 at 20908..20909 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20908), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20908), 2, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _bn_conv_weights, size 256 from DefaultFlash at 18816 to (size 256) L2 at 18816..19071 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 18816), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 18816), 256, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_bn_bias, size 64 from DefaultFlash at 19200 to (size 64) L2 at 19200..19263 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19200), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19200), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S14_Mul_scale, size 16 from DefaultFlash at 20008 to (size 16) L2 at 20008..20023 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20008), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20008), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S14_Mul_shift, size 16 from DefaultFlash at 20024 to (size 16) L2 at 20024..20039 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20024), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20024), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S14_Infos, size 20 from DefaultFlash at 19776 to (size 20) L2 at 19776..19795 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19776), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19776), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv_0_conv1d_conv_weights, size 2304 from DefaultFlash at 384 to (size 2304) L2 at 384..2687 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 384), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 384), 2304, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_conv_0_conv1d_bias, size 64 from DefaultFlash at 19264 to (size 64) L2 at 19264..19327 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19264), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19264), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S21_Mul_scale, size 16 from DefaultFlash at 20040 to (size 16) L2 at 20040..20055 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20040), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20040), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S21_Mul_shift, size 16 from DefaultFlash at 20056 to (size 16) L2 at 20056..20071 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20056), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20056), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S21_Infos, size 20 from DefaultFlash at 19796 to (size 20) L2 at 19796..19815 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19796), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19796), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S24_Infos, size 8 from DefaultFlash at 20832 to (size 8) L2 at 20832..20839 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20832), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20832), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S25_Infos, size 13 from DefaultFlash at 20072 to (size 13) L2 at 20072..20084 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20072), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20072), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S27_Infos, size 13 from DefaultFlash at 20088 to (size 13) L2 at 20088..20100 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20088), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20088), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__mul_309, size 16 from DefaultFlash at 20104 to (size 16) L2 at 20104..20119 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20104), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20104), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__add_310, size 16 from DefaultFlash at 20120 to (size 16) L2 at 20120..20135 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20120), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20120), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv_1_conv1d_conv_weights, size 2304 from DefaultFlash at 2688 to (size 2304) L2 at 2688..4991 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 2688), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 2688), 2304, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_conv_1_conv1d_bias, size 64 from DefaultFlash at 19328 to (size 64) L2 at 19328..19391 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19328), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19328), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S35_Mul_scale, size 16 from DefaultFlash at 20136 to (size 16) L2 at 20136..20151 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20136), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20136), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S35_Mul_shift, size 16 from DefaultFlash at 20152 to (size 16) L2 at 20152..20167 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20152), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20152), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S35_Infos, size 20 from DefaultFlash at 19816 to (size 20) L2 at 19816..19835 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19816), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19816), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S38_Infos, size 8 from DefaultFlash at 20840 to (size 8) L2 at 20840..20847 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20840), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20840), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S39_Infos, size 13 from DefaultFlash at 20168 to (size 13) L2 at 20168..20180 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20168), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20168), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S41_Infos, size 13 from DefaultFlash at 20184 to (size 13) L2 at 20184..20196 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20184), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20184), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__mul_316, size 16 from DefaultFlash at 20200 to (size 16) L2 at 20200..20215 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20200), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20200), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__add_317, size 16 from DefaultFlash at 20216 to (size 16) L2 at 20216..20231 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20216), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20216), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv_2_conv1d_conv_weights, size 2304 from DefaultFlash at 4992 to (size 2304) L2 at 4992..7295 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 4992), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 4992), 2304, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_conv_2_conv1d_bias, size 64 from DefaultFlash at 19392 to (size 64) L2 at 19392..19455 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19392), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19392), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S50_Mul_scale, size 16 from DefaultFlash at 20232 to (size 16) L2 at 20232..20247 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20232), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20232), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S50_Mul_shift, size 16 from DefaultFlash at 20248 to (size 16) L2 at 20248..20263 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20248), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20248), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S50_Infos, size 20 from DefaultFlash at 19836 to (size 20) L2 at 19836..19855 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19836), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19836), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S53_Infos, size 8 from DefaultFlash at 20848 to (size 8) L2 at 20848..20855 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20848), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20848), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S54_Infos, size 13 from DefaultFlash at 20264 to (size 13) L2 at 20264..20276 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20264), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20264), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S56_Infos, size 13 from DefaultFlash at 20280 to (size 13) L2 at 20280..20292 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20280), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20280), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__mul_323, size 16 from DefaultFlash at 20296 to (size 16) L2 at 20296..20311 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20296), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20296), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__add_324, size 16 from DefaultFlash at 20312 to (size 16) L2 at 20312..20327 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20312), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20312), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv_3_conv1d_conv_weights, size 2304 from DefaultFlash at 7296 to (size 2304) L2 at 7296..9599 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 7296), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 7296), 2304, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_conv_3_conv1d_bias, size 64 from DefaultFlash at 19456 to (size 64) L2 at 19456..19519 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19456), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19456), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S65_Mul_scale, size 16 from DefaultFlash at 20328 to (size 16) L2 at 20328..20343 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20328), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20328), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S65_Mul_shift, size 16 from DefaultFlash at 20344 to (size 16) L2 at 20344..20359 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20344), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20344), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S65_Infos, size 20 from DefaultFlash at 19856 to (size 20) L2 at 19856..19875 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19856), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19856), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S68_Infos, size 8 from DefaultFlash at 20856 to (size 8) L2 at 20856..20863 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20856), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20856), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S69_Infos, size 13 from DefaultFlash at 20360 to (size 13) L2 at 20360..20372 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20360), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20360), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S71_Infos, size 13 from DefaultFlash at 20376 to (size 13) L2 at 20376..20388 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20376), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20376), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__mul_330, size 16 from DefaultFlash at 20392 to (size 16) L2 at 20392..20407 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20392), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20392), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__add_331, size 16 from DefaultFlash at 20408 to (size 16) L2 at 20408..20423 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20408), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20408), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv_4_conv1d_conv_weights, size 2304 from DefaultFlash at 9600 to (size 2304) L2 at 9600..11903 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 9600), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 9600), 2304, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_conv_4_conv1d_bias, size 64 from DefaultFlash at 19520 to (size 64) L2 at 19520..19583 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19520), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19520), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S80_Mul_scale, size 16 from DefaultFlash at 20424 to (size 16) L2 at 20424..20439 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20424), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20424), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S80_Mul_shift, size 16 from DefaultFlash at 20440 to (size 16) L2 at 20440..20455 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20440), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20440), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S80_Infos, size 20 from DefaultFlash at 19876 to (size 20) L2 at 19876..19895 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19876), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19876), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S83_Infos, size 8 from DefaultFlash at 20864 to (size 8) L2 at 20864..20871 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20864), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20864), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S84_Infos, size 13 from DefaultFlash at 20456 to (size 13) L2 at 20456..20468 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20456), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20456), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S86_Infos, size 13 from DefaultFlash at 20472 to (size 13) L2 at 20472..20484 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20472), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20472), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__mul_337, size 16 from DefaultFlash at 20488 to (size 16) L2 at 20488..20503 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20488), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20488), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__add_338, size 16 from DefaultFlash at 20504 to (size 16) L2 at 20504..20519 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20504), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20504), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv_5_conv1d_conv_weights, size 2304 from DefaultFlash at 11904 to (size 2304) L2 at 11904..14207 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 11904), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 11904), 2304, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_conv_5_conv1d_bias, size 64 from DefaultFlash at 19584 to (size 64) L2 at 19584..19647 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19584), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19584), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S95_Mul_scale, size 16 from DefaultFlash at 20520 to (size 16) L2 at 20520..20535 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20520), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20520), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S95_Mul_shift, size 16 from DefaultFlash at 20536 to (size 16) L2 at 20536..20551 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20536), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20536), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S95_Infos, size 20 from DefaultFlash at 19896 to (size 20) L2 at 19896..19915 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19896), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19896), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S98_Infos, size 8 from DefaultFlash at 20872 to (size 8) L2 at 20872..20879 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20872), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20872), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S99_Infos, size 13 from DefaultFlash at 20552 to (size 13) L2 at 20552..20564 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20552), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20552), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S101_Infos, size 13 from DefaultFlash at 20568 to (size 13) L2 at 20568..20580 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20568), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20568), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__mul_344, size 16 from DefaultFlash at 20584 to (size 16) L2 at 20584..20599 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20584), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20584), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__add_345, size 16 from DefaultFlash at 20600 to (size 16) L2 at 20600..20615 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20600), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20600), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv_6_conv1d_conv_weights, size 2304 from DefaultFlash at 14208 to (size 2304) L2 at 14208..16511 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 14208), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 14208), 2304, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_conv_6_conv1d_bias, size 64 from DefaultFlash at 19648 to (size 64) L2 at 19648..19711 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19648), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19648), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S110_Mul_scale, size 16 from DefaultFlash at 20616 to (size 16) L2 at 20616..20631 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20616), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20616), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S110_Mul_shift, size 16 from DefaultFlash at 20632 to (size 16) L2 at 20632..20647 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20632), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20632), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S110_Infos, size 20 from DefaultFlash at 19916 to (size 20) L2 at 19916..19935 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19916), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19916), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S113_Infos, size 8 from DefaultFlash at 20880 to (size 8) L2 at 20880..20887 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20880), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20880), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S114_Infos, size 13 from DefaultFlash at 20648 to (size 13) L2 at 20648..20660 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20648), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20648), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S116_Infos, size 13 from DefaultFlash at 20664 to (size 13) L2 at 20664..20676 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20664), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20664), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__mul_351, size 16 from DefaultFlash at 20680 to (size 16) L2 at 20680..20695 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20680), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20680), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__add_352, size 16 from DefaultFlash at 20696 to (size 16) L2 at 20696..20711 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20696), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20696), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _conv_7_conv1d_conv_weights, size 2304 from DefaultFlash at 16512 to (size 2304) L2 at 16512..18815 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 16512), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 16512), 2304, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_conv_7_conv1d_bias, size 64 from DefaultFlash at 19712 to (size 64) L2 at 19712..19775 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19712), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19712), 64, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S125_Mul_scale, size 16 from DefaultFlash at 20712 to (size 16) L2 at 20712..20727 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20712), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20712), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S125_Mul_shift, size 16 from DefaultFlash at 20728 to (size 16) L2 at 20728..20743 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20728), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20728), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S125_Infos, size 20 from DefaultFlash at 19936 to (size 20) L2 at 19936..19955 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19936), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19936), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S128_Infos, size 8 from DefaultFlash at 20888 to (size 8) L2 at 20888..20895 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20888), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20888), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S129_Infos, size 13 from DefaultFlash at 20744 to (size 13) L2 at 20744..20756 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20744), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20744), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S131_Infos, size 13 from DefaultFlash at 20760 to (size 13) L2 at 20760..20772 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20760), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20760), 13, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__mul_358, size 16 from DefaultFlash at 20776 to (size 16) L2 at 20776..20791 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20776), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20776), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_onnx__add_359, size 16 from DefaultFlash at 20792 to (size 16) L2 at 20792..20807 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20792), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20792), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving _reshape_speech_reshape_speech_0_conv_weights, size 16 from DefaultFlash at 20808 to (size 16) L2 at 20808..20823 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20808), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20808), 16, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving Constant_reshape_speech_0_bias, size 4 from DefaultFlash at 20912 to (size 4) L2 at 20912..20915 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20912), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20912), 4, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S140_Mul_scale, size 1 from DefaultFlash at 20916 to (size 1) L2 at 20916..20916 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20916), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20916), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S140_Mul_shift, size 1 from DefaultFlash at 20920 to (size 1) L2 at 20920..20920 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20920), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20920), 1, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S140_Infos, size 20 from DefaultFlash at 19956 to (size 20) L2 at 19956..19975 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19956), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19956), 20, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving S144_Infos, size 8 from DefaultFlash at 20896 to (size 8) L2 at 20896..20903 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 20896), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 20896), 8, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving RsqrtLUT, size 384 from DefaultFlash at 0 to (size 384) L2 at 0..383 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 0), 384, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	/* Static Moving SigmoidLUT_u8, size 128 from DefaultFlash at 19072 to (size 128) L2 at 19072..19199 */
	AT_DEFAULTFLASH_FS_FC_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_L3_Flash + 19072), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_L2_Memory + 19072), 128, 0, UchanHF1);
	AT_DEFAULTFLASH_FS_FC_WAIT(&DefaultFlash, UchanHF1);
	Input_1 = (float * __restrict__) (main_1_L3_Memory_Dyn + 0);
	Output_1 = (float * __restrict__) (main_1_L2_Memory_Dyn + 83528);
	Output_2 = (float * __restrict__) (main_1_L2_Memory_Dyn + 0);
	return AT_NO_ERROR;
}
void main_1CNN_ConstructCluster()

{
}
int  main_1CNN_Destruct()

{
	AT_DEFAULTRAM_FREE(&DefaultRam, main_1_L3_Memory_Dyn, 2138240);
	AT_L2_FREE(0, main_1_L2_Memory_Dyn, 919312);
	AT_L2_FREE(0, main_1_L2_Memory, 20924);
	AT_L1_FREE(0, main_1_L1_Memory, 115688);
	AT_DEFAULTRAM_CLOSE(&DefaultRam);
	AT_DEFAULTFLASH_FS_CLOSE(&DefaultFlash);
	Input_1 = 0;
	Output_1 = 0;
	Output_2 = 0;
	return 0;
}
int main_1CNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 115688; /* L1 Memory */
		case AT_L2_MEM:     return 20924; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 919312; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 2138240; /* L3 Memory, dynamic */
		default:            return 0;
	}
}
unsigned int G1_AT_GraphPerf[85];
unsigned int G1_AT_GraphPerf_CNN_Total = 0;
unsigned int G1_AT_GraphOperInfosNames[85] = {
	33410,
	33410,
	33410,
	133640,
	33410,
	167050,
	33410,
	534560,
	267280,
	267280,
	38755600,
	267280,
	267280,
	267280,
	1069120,
	267280,
	2138240,
	267280,
	38755600,
	267280,
	267280,
	267280,
	1069120,
	267280,
	801840,
	267280,
	267280,
	38755600,
	267280,
	267280,
	267280,
	1069120,
	267280,
	801840,
	267280,
	267280,
	38755600,
	267280,
	267280,
	267280,
	1069120,
	267280,
	801840,
	267280,
	267280,
	38755600,
	267280,
	267280,
	267280,
	1069120,
	267280,
	801840,
	267280,
	267280,
	38755600,
	267280,
	267280,
	267280,
	1069120,
	267280,
	801840,
	267280,
	267280,
	38755600,
	267280,
	267280,
	267280,
	1069120,
	267280,
	801840,
	267280,
	267280,
	38755600,
	267280,
	267280,
	267280,
	1069120,
	267280,
	801840,
	1870960,
	267280,
	283985,
	16705,
	16705,
	0,
};
char *G1_AT_GraphNodeNames[85] = {
	"S1_input_1_qout0",
	"S3__Transpose",
	"S4__enc_LN_ReduceMean",
	"S5_expr_0",
	"S6__enc_LN_ReduceMean_1",
	"S9_expr_1",
	"S11__BN_Conv_trans_in0",
	"S14__BN_Conv",
	"S15__BN_Conv_trans_out0",
	"S18__conv_0_conv1d_Conv_fusion_trans_in0",
	"S21__conv_0_conv1d_Conv_fusion",
	"S22__conv_0_conv1d_Conv_fusion_trans_out0",
	"S24__conv_0_conv1d_Conv_reshape_out_qout0",
	"S25__conv_0_reg1_ReduceMean",
	"S26_expr_3",
	"S27__conv_0_reg1_ReduceMean_1_fusion",
	"S30_expr_6",
	"S32__conv_1_conv1d_Conv_fusion_trans_in0",
	"S35__conv_1_conv1d_Conv_fusion",
	"S36__conv_1_conv1d_Conv_fusion_trans_out0",
	"S38__conv_1_conv1d_Conv_reshape_out_qout0",
	"S39__conv_1_reg1_ReduceMean",
	"S40_expr_7",
	"S41__conv_1_reg1_ReduceMean_1_fusion",
	"S44_expr_8",
	"S45_expr_9",
	"S47__conv_2_conv1d_Conv_fusion_trans_in0",
	"S50__conv_2_conv1d_Conv_fusion",
	"S51__conv_2_conv1d_Conv_fusion_trans_out0",
	"S53__conv_2_conv1d_Conv_reshape_out_qout0",
	"S54__conv_2_reg1_ReduceMean",
	"S55_expr_12",
	"S56__conv_2_reg1_ReduceMean_1_fusion",
	"S59_expr_13",
	"S60_expr_11",
	"S62__conv_3_conv1d_Conv_fusion_trans_in0",
	"S65__conv_3_conv1d_Conv_fusion",
	"S66__conv_3_conv1d_Conv_fusion_trans_out0",
	"S68__conv_3_conv1d_Conv_reshape_out_qout0",
	"S69__conv_3_reg1_ReduceMean",
	"S70_expr_17",
	"S71__conv_3_reg1_ReduceMean_1_fusion",
	"S74_expr_18",
	"S75_expr_14",
	"S77__conv_4_conv1d_Conv_fusion_trans_in0",
	"S80__conv_4_conv1d_Conv_fusion",
	"S81__conv_4_conv1d_Conv_fusion_trans_out0",
	"S83__conv_4_conv1d_Conv_reshape_out_qout0",
	"S84__conv_4_reg1_ReduceMean",
	"S85_expr_22",
	"S86__conv_4_reg1_ReduceMean_1_fusion",
	"S89_expr_23",
	"S90_expr_16",
	"S92__conv_5_conv1d_Conv_fusion_trans_in0",
	"S95__conv_5_conv1d_Conv_fusion",
	"S96__conv_5_conv1d_Conv_fusion_trans_out0",
	"S98__conv_5_conv1d_Conv_reshape_out_qout0",
	"S99__conv_5_reg1_ReduceMean",
	"S100_expr_25",
	"S101__conv_5_reg1_ReduceMean_1_fusion",
	"S104_expr_26",
	"S105_expr_19",
	"S107__conv_6_conv1d_Conv_fusion_trans_in0",
	"S110__conv_6_conv1d_Conv_fusion",
	"S111__conv_6_conv1d_Conv_fusion_trans_out0",
	"S113__conv_6_conv1d_Conv_reshape_out_qout0",
	"S114__conv_6_reg1_ReduceMean",
	"S115_expr_28",
	"S116__conv_6_reg1_ReduceMean_1_fusion",
	"S119_expr_29",
	"S120_expr_20",
	"S122__conv_7_conv1d_Conv_fusion_trans_in0",
	"S125__conv_7_conv1d_Conv_fusion",
	"S126__conv_7_conv1d_Conv_fusion_trans_out0",
	"S128__conv_7_conv1d_Conv_reshape_out_qout0",
	"S129__conv_7_reg1_ReduceMean",
	"S130_expr_31",
	"S131__conv_7_reg1_ReduceMean_1_fusion",
	"S134_expr_32",
	"S135_expr_4",
	"S137__reshape_speech_reshape_speech_0_Conv_fusion_trans_in0",
	"S140__reshape_speech_reshape_speech_0_Conv_fusion",
	"S142_expr_33",
	"S144__reshape_speech_reshape_speech_0_Conv_reshape_qout0",
	"IO_Wait",
};
float * __restrict__ Input_1;
float * __restrict__ Output_1;
float * __restrict__ Output_2;





// int cumsums [10];
pi_callback_t fc_l2_movement_event;




int movement_values [3]; // these 3 ints are position from [0], to [1], how much data [2] are to be moved
/*
{'S24__conv_0_conv1d_Conv_reshape_out_qout0': 5545746, 'S39__conv_1_reg1_ReduceMean': 5324313, 
'S54__conv_2_reg1_ReduceMean': 4407214, 'S69__conv_3_reg1_ReduceMean': 4962458, 
'S84__conv_4_reg1_ReduceMean': 4258127, 'S99__conv_5_reg1_ReduceMean': 4089098, 
'S114__conv_6_reg1_ReduceMean': 4346634, 'S120_expr_20': 1403293, 
'S131__conv_7_reg1_ReduceMean_1_fusion': 5116600}
*/

void move_fc_l2(void* movement){
	int * movement_values_passed = (int *)movement;
	// printf("starting value %d \n",main_1_L2_Memory_Dyn[movement_values_passed[0]]);

	// printf("pointer value here %x \n",(main_1_L2_Memory_Dyn+movement_values_passed[0]));

	for (int i = 0;i<movement_values_passed[2];++i)
		*(main_1_L2_Memory_Dyn + movement_values_passed[1] + i) = *(main_1_L2_Memory_Dyn + movement_values_passed[0] + i);

	// printf("ending value %d \n",main_1_L2_Memory_Dyn[movement_values_passed[1]]);

	// printf("pointer value here after %x \n",(main_1_L2_Memory_Dyn+movement_values_passed[1]));
}

int  main_1CNN(
)

{	

	// unsigned int L3_move = gap_cl_readhwtimer(); 

	// AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	// AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) main_1_L3_Memory_Dyn+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0), 450000, 0, UchanHR1);
	// AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1);
	// AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) main_1_L3_Memory_Dyn+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_L2_Memory_Dyn+0), 450000, 1, UchanHR1);
	// AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1);
	// L3_move =  gap_cl_readhwtimer() - L3_move;

	// printf("time for moving out L3 %u \n",L3_move);
	
	for (int i=0;i<6;++i)
		{	
			
			BiG_fft_forwardCNN();
		}
	
	unsigned int Start_IO;
	G1_AT_GraphPerf_CNN_Total = gap_cl_readhwtimer();
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[0]);
	G1_AT_GraphPerf[0] = gap_cl_readhwtimer();
	G1_AT_GraphPerf[84] = 0;
	S1_input_1_qout0(
		((float * __restrict__) (main_1_L3_Memory_Dyn+2138240+1677696+296064+32000)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20824)) /* Infos */
	);
	G1_AT_GraphPerf[0] = gap_cl_readhwtimer() - G1_AT_GraphPerf[0];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[1]);
	G1_AT_GraphPerf[1] = gap_cl_readhwtimer();
	S3__Transpose(
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+33412)) /* Out */
	);
	G1_AT_GraphPerf[1] = gap_cl_readhwtimer() - G1_AT_GraphPerf[1];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[2]);
	G1_AT_GraphPerf[2] = gap_cl_readhwtimer();
	S4__enc_LN_ReduceMean(
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+33412)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+100236)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+19976)) /* Infos */
	);
	G1_AT_GraphPerf[2] = gap_cl_readhwtimer() - G1_AT_GraphPerf[2];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[3]);
	G1_AT_GraphPerf[3] = gap_cl_readhwtimer();
	S5_expr_0(
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+33412)), /* expr_0_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+100236)), /* expr_0_in_1 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* expr_0_out_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+66824)) /* expr_0_out_1 */
	);
	G1_AT_GraphPerf[3] = gap_cl_readhwtimer() - G1_AT_GraphPerf[3];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[4]);
	G1_AT_GraphPerf[4] = gap_cl_readhwtimer();
	S6__enc_LN_ReduceMean_1(
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+66824)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+100236)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+19992)) /* Infos */
	);
	G1_AT_GraphPerf[4] = gap_cl_readhwtimer() - G1_AT_GraphPerf[4];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[5]);
	G1_AT_GraphPerf[5] = gap_cl_readhwtimer();
	S9_expr_1(
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+100236)), /* expr_1_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* expr_1_in_1 */
		((signed char * __restrict__) (main_1_L2_Memory+20904)), /* expr_1_in_2 */
		((signed char * __restrict__) (main_1_L2_Memory+20908)), /* expr_1_in_3 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+33412)), /* expr_1_out_0 */
		((unsigned int * __restrict__) (main_1_L2_Memory+0)) /* RsqrtLUT */
	);
	G1_AT_GraphPerf[5] = gap_cl_readhwtimer() - G1_AT_GraphPerf[5];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[6]);
	G1_AT_GraphPerf[6] = gap_cl_readhwtimer();
	S11__BN_Conv_trans_in0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+33412)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)) /* Out */
	);
	G1_AT_GraphPerf[6] = gap_cl_readhwtimer() - G1_AT_GraphPerf[6];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[7]);
	G1_AT_GraphPerf[7] = gap_cl_readhwtimer();
	S14__BN_Conv(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory+18816)), /* Filter */
		((signed int * __restrict__) (main_1_L2_Memory+19200)), /* Bias */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (main_1_L2_Memory+20008)), /* Scale */
		((signed char * __restrict__) (main_1_L2_Memory+20024)), /* ScaleN */
		((signed char * __restrict__) (main_1_L2_Memory+19776)) /* Infos */
	);
	G1_AT_GraphPerf[7] = gap_cl_readhwtimer() - G1_AT_GraphPerf[7];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[8]);
	G1_AT_GraphPerf[8] = gap_cl_readhwtimer();
	S15__BN_Conv_trans_out0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)) /* Out */
	);
	G1_AT_GraphPerf[8] = gap_cl_readhwtimer() - G1_AT_GraphPerf[8];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[9]);
	G1_AT_GraphPerf[9] = gap_cl_readhwtimer();
	S18__conv_0_conv1d_Conv_fusion_trans_in0(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)) /* Out */
	);
	G1_AT_GraphPerf[9] = gap_cl_readhwtimer() - G1_AT_GraphPerf[9];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[10]);
	G1_AT_GraphPerf[10] = gap_cl_readhwtimer();
	S21__conv_0_conv1d_Conv_fusion(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory+384)), /* Filter */
		((signed int * __restrict__) (main_1_L2_Memory+19264)), /* Bias */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (main_1_L2_Memory+20040)), /* Scale */
		((signed char * __restrict__) (main_1_L2_Memory+20056)), /* ScaleN */
		((signed char * __restrict__) (main_1_L2_Memory+19796)) /* Infos */
	);
	G1_AT_GraphPerf[10] = gap_cl_readhwtimer() - G1_AT_GraphPerf[10];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[11]);
	G1_AT_GraphPerf[11] = gap_cl_readhwtimer();
	S22__conv_0_conv1d_Conv_fusion_trans_out0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)) /* Out */
	);
	G1_AT_GraphPerf[11] = gap_cl_readhwtimer() - G1_AT_GraphPerf[11];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[12]);
	G1_AT_GraphPerf[12] = gap_cl_readhwtimer();
	S24__conv_0_conv1d_Conv_reshape_out_qout0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20832)) /* Infos */
	);

	 
	
	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + 267280*2;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}

	// for (int i=0; i<267280;++i)
	// 	cumsums[0] += (main_1_L2_Memory_Dyn+0)[i];

	// printf("cumsum 1 %d \n",cumsums[0]);



	G1_AT_GraphPerf[12] = gap_cl_readhwtimer() - G1_AT_GraphPerf[12];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[13]);
	G1_AT_GraphPerf[13] = gap_cl_readhwtimer();
	S25__conv_0_reg1_ReduceMean(
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+801840)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20072)) /* Infos */
	);
	G1_AT_GraphPerf[13] = gap_cl_readhwtimer() - G1_AT_GraphPerf[13];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[14]);
	G1_AT_GraphPerf[14] = gap_cl_readhwtimer();
	S26_expr_3(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)), /* expr_3_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+801840)), /* expr_3_in_1 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_3_out_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+0)) /* expr_3_out_1 */
	);
	G1_AT_GraphPerf[14] = gap_cl_readhwtimer() - G1_AT_GraphPerf[14];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[15]);
	G1_AT_GraphPerf[15] = gap_cl_readhwtimer();
	S27__conv_0_reg1_ReduceMean_1_fusion(
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+801840)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20088)), /* Infos */
		((unsigned int * __restrict__) (main_1_L2_Memory+0)) /* RsqrtLUT */
	);
	G1_AT_GraphPerf[15] = gap_cl_readhwtimer() - G1_AT_GraphPerf[15];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[16]);
	G1_AT_GraphPerf[16] = gap_cl_readhwtimer();
	S30_expr_6(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_6_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+801840)), /* expr_6_in_1 */
		((signed char * __restrict__) (main_1_L2_Memory+20104)), /* expr_6_in_2 */
		((signed char * __restrict__) (main_1_L2_Memory+20120)), /* expr_6_in_3 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* expr_6_in_4 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)), /* expr_6_out_0 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)) /* expr_6_out_1 */
	);
	G1_AT_GraphPerf[16] = gap_cl_readhwtimer() - G1_AT_GraphPerf[16];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[17]);
	G1_AT_GraphPerf[17] = gap_cl_readhwtimer();
	S32__conv_1_conv1d_Conv_fusion_trans_in0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* Out */
	);
	G1_AT_GraphPerf[17] = gap_cl_readhwtimer() - G1_AT_GraphPerf[17];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[18]);
	G1_AT_GraphPerf[18] = gap_cl_readhwtimer();
	S35__conv_1_conv1d_Conv_fusion(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory+2688)), /* Filter */
		((signed int * __restrict__) (main_1_L2_Memory+19328)), /* Bias */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (main_1_L2_Memory+20136)), /* Scale */
		((signed char * __restrict__) (main_1_L2_Memory+20152)), /* ScaleN */
		((signed char * __restrict__) (main_1_L2_Memory+19816)) /* Infos */
	);
	G1_AT_GraphPerf[18] = gap_cl_readhwtimer() - G1_AT_GraphPerf[18];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[19]);
	G1_AT_GraphPerf[19] = gap_cl_readhwtimer();
	S36__conv_1_conv1d_Conv_fusion_trans_out0(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* Out */
	);
	G1_AT_GraphPerf[19] = gap_cl_readhwtimer() - G1_AT_GraphPerf[19];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[20]);
	G1_AT_GraphPerf[20] = gap_cl_readhwtimer();
	S38__conv_1_conv1d_Conv_reshape_out_qout0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20840)) /* Infos */
	);
	G1_AT_GraphPerf[20] = gap_cl_readhwtimer() - G1_AT_GraphPerf[20];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[21]);
	G1_AT_GraphPerf[21] = gap_cl_readhwtimer();
	S39__conv_1_reg1_ReduceMean(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+915200)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20168)) /* Infos */
	);


	movement_values[0] = 915200;
	movement_values[1] = 801840;
	movement_values[2] = 4112;

	move_in_L2(movement_values);

	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + movement_values[1]+movement_values[2]+10000;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}

	

	
	movement_values[0] = 801840;
	movement_values[1] = 915200;

	move_in_L2(movement_values);

	// for (int i=0; i<movement_values[2];++i)
	// 	cumsums[1] += (main_1_L2_Memory_Dyn+movement_values[0])[i];

	// printf("cumsum 2 %d \n",cumsums[1]);


	G1_AT_GraphPerf[21] = gap_cl_readhwtimer() - G1_AT_GraphPerf[21];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[22]);
	G1_AT_GraphPerf[22] = gap_cl_readhwtimer();
	S40_expr_7(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_7_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+915200)), /* expr_7_in_1 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+534560)), /* expr_7_out_0 */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)) /* expr_7_out_1 */
	);

	movement_values[0] = 915200;
	movement_values[1] = 534560;
	movement_values[2] = 4112;

	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + 534560 + 10000;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}



	

	G1_AT_GraphPerf[22] = gap_cl_readhwtimer() - G1_AT_GraphPerf[22];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[23]);
	G1_AT_GraphPerf[23] = gap_cl_readhwtimer();
	S41__conv_1_reg1_ReduceMean_1_fusion(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+647920)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20184)), /* Infos */
		((unsigned int * __restrict__) (main_1_L2_Memory+0)) /* RsqrtLUT */
	);

	// for (int i=0; i<movement_values[2];++i)
	// 	cumsums[7] += (main_1_L2_Memory_Dyn+647920)[i];

	// printf("cumsum 8 %d \n",cumsums[7]);



	G1_AT_GraphPerf[23] = gap_cl_readhwtimer() - G1_AT_GraphPerf[23];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[24]);
	G1_AT_GraphPerf[24] = gap_cl_readhwtimer();
	S44_expr_8(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+534560)), /* expr_8_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+647920)), /* expr_8_in_1 */
		((signed char * __restrict__) (main_1_L2_Memory+20200)), /* expr_8_in_2 */
		((signed char * __restrict__) (main_1_L2_Memory+20216)), /* expr_8_in_3 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+267280)) /* expr_8_out_0 */
	);
	G1_AT_GraphPerf[24] = gap_cl_readhwtimer() - G1_AT_GraphPerf[24];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[25]);
	G1_AT_GraphPerf[25] = gap_cl_readhwtimer();
	S45_expr_9(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* expr_9_in_0 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+267280)), /* expr_9_in_1 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* expr_9_out_0 */
	);
	G1_AT_GraphPerf[25] = gap_cl_readhwtimer() - G1_AT_GraphPerf[25];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[26]);
	G1_AT_GraphPerf[26] = gap_cl_readhwtimer();
	S47__conv_2_conv1d_Conv_fusion_trans_in0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)) /* Out */
	);
	G1_AT_GraphPerf[26] = gap_cl_readhwtimer() - G1_AT_GraphPerf[26];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[27]);
	G1_AT_GraphPerf[27] = gap_cl_readhwtimer();
	S50__conv_2_conv1d_Conv_fusion(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory+4992)), /* Filter */
		((signed int * __restrict__) (main_1_L2_Memory+19392)), /* Bias */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (main_1_L2_Memory+20232)), /* Scale */
		((signed char * __restrict__) (main_1_L2_Memory+20248)), /* ScaleN */
		((signed char * __restrict__) (main_1_L2_Memory+19836)) /* Infos */
	);
	G1_AT_GraphPerf[27] = gap_cl_readhwtimer() - G1_AT_GraphPerf[27];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[28]);
	G1_AT_GraphPerf[28] = gap_cl_readhwtimer();
	S51__conv_2_conv1d_Conv_fusion_trans_out0(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)) /* Out */
	);
	G1_AT_GraphPerf[28] = gap_cl_readhwtimer() - G1_AT_GraphPerf[28];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[29]);
	G1_AT_GraphPerf[29] = gap_cl_readhwtimer();
	S53__conv_2_conv1d_Conv_reshape_out_qout0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20848)) /* Infos */
	);
	G1_AT_GraphPerf[29] = gap_cl_readhwtimer() - G1_AT_GraphPerf[29];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[30]);
	G1_AT_GraphPerf[30] = gap_cl_readhwtimer();
	S54__conv_2_reg1_ReduceMean(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+915200)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20264)) /* Infos */
	);

	movement_values[0] = 915200;
	movement_values[1] = 801840;
	movement_values[2] = 4112;

	
	

	move_in_L2(movement_values);




	// for (int i=0; i<movement_values[2];++i)
	// 	cumsums[2] += (main_1_L2_Memory_Dyn+movement_values[0])[i];
	
	
	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + movement_values[1]+4112+20000;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}

	

	
	movement_values[0] = 801840;
	movement_values[1] = 915200;

	move_in_L2(movement_values);

	// cumsums[2] = 0;

	// for (int i=0; i<movement_values[2];++i)
	// 	cumsums[2] += (main_1_L2_Memory_Dyn+915200)[i];

	// printf("starting cumsum 3 %d \n",cumsums[2]);

	

	G1_AT_GraphPerf[30] = gap_cl_readhwtimer() - G1_AT_GraphPerf[30];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[31]);
	G1_AT_GraphPerf[31] = gap_cl_readhwtimer();
	S55_expr_12(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* expr_12_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+915200)), /* expr_12_in_1 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* expr_12_out_0 */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+534560)) /* expr_12_out_1 */
	);

	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + 801840 ;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}


	G1_AT_GraphPerf[31] = gap_cl_readhwtimer() - G1_AT_GraphPerf[31];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[32]);
	G1_AT_GraphPerf[32] = gap_cl_readhwtimer();
	S56__conv_2_reg1_ReduceMean_1_fusion(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+534560)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+113360)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20280)), /* Infos */
		((unsigned int * __restrict__) (main_1_L2_Memory+0)) /* RsqrtLUT */
	);
	G1_AT_GraphPerf[32] = gap_cl_readhwtimer() - G1_AT_GraphPerf[32];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[33]);
	G1_AT_GraphPerf[33] = gap_cl_readhwtimer();
	S59_expr_13(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* expr_13_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+113360)), /* expr_13_in_1 */
		((signed char * __restrict__) (main_1_L2_Memory+20296)), /* expr_13_in_2 */
		((signed char * __restrict__) (main_1_L2_Memory+20312)), /* expr_13_in_3 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+534560)) /* expr_13_out_0 */
	);
	G1_AT_GraphPerf[33] = gap_cl_readhwtimer() - G1_AT_GraphPerf[33];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[34]);
	G1_AT_GraphPerf[34] = gap_cl_readhwtimer();
	S60_expr_11(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_11_in_0 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+534560)), /* expr_11_in_1 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)) /* expr_11_out_0 */
	);
	G1_AT_GraphPerf[34] = gap_cl_readhwtimer() - G1_AT_GraphPerf[34];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[35]);
	G1_AT_GraphPerf[35] = gap_cl_readhwtimer();
	S62__conv_3_conv1d_Conv_fusion_trans_in0(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* Out */
	);
	G1_AT_GraphPerf[35] = gap_cl_readhwtimer() - G1_AT_GraphPerf[35];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[36]);
	G1_AT_GraphPerf[36] = gap_cl_readhwtimer();
	S65__conv_3_conv1d_Conv_fusion(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory+7296)), /* Filter */
		((signed int * __restrict__) (main_1_L2_Memory+19456)), /* Bias */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+801840)), /* Out */
		((unsigned char * __restrict__) (main_1_L2_Memory+20328)), /* Scale */
		((signed char * __restrict__) (main_1_L2_Memory+20344)), /* ScaleN */
		((signed char * __restrict__) (main_1_L2_Memory+19856)) /* Infos */
	);
	G1_AT_GraphPerf[36] = gap_cl_readhwtimer() - G1_AT_GraphPerf[36];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[37]);
	G1_AT_GraphPerf[37] = gap_cl_readhwtimer();
	S66__conv_3_conv1d_Conv_fusion_trans_out0(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+801840)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)) /* Out */
	);
	G1_AT_GraphPerf[37] = gap_cl_readhwtimer() - G1_AT_GraphPerf[37];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[38]);
	G1_AT_GraphPerf[38] = gap_cl_readhwtimer();
	S68__conv_3_conv1d_Conv_reshape_out_qout0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20856)) /* Infos */
	);
	G1_AT_GraphPerf[38] = gap_cl_readhwtimer() - G1_AT_GraphPerf[38];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[39]);
	G1_AT_GraphPerf[39] = gap_cl_readhwtimer();
	S69__conv_3_reg1_ReduceMean(
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+834736)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20360)) /* Infos */
	);

	// for (int i=0; i<4112;++i)
	// 	cumsums[3] += (main_1_L2_Memory_Dyn+834736)[i];

	// printf("cumsum 4 %d \n",cumsums[3]);
	
	movement_values[0] = 915200;
	movement_values[1] = 834736;
	movement_values[2] = 4112;

	if (!first_execution){
		main_2_L2_Memory_Dyn = (main_1_L2_Memory_Dyn + 834736 + 16*257 );
		main_2CNN(G2_Input,output_imaginary,output_real);
	}
	// cumsums[3]=0;
	// for (int i=0; i<4112;++i)
	// 	cumsums[3] += (main_1_L2_Memory_Dyn+834736)[i];

	// printf("cumsum 4 %d \n",cumsums[3]);

	G1_AT_GraphPerf[39] = gap_cl_readhwtimer() - G1_AT_GraphPerf[39];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[40]);
	G1_AT_GraphPerf[40] = gap_cl_readhwtimer();
	S70_expr_17(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* expr_17_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+834736)), /* expr_17_in_1 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_17_out_0 */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+801840)) /* expr_17_out_1 */
	);
	G1_AT_GraphPerf[40] = gap_cl_readhwtimer() - G1_AT_GraphPerf[40];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[41]);
	G1_AT_GraphPerf[41] = gap_cl_readhwtimer();
	S71__conv_3_reg1_ReduceMean_1_fusion(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+801840)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+113360)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20376)), /* Infos */
		((unsigned int * __restrict__) (main_1_L2_Memory+0)) /* RsqrtLUT */
	);
	G1_AT_GraphPerf[41] = gap_cl_readhwtimer() - G1_AT_GraphPerf[41];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[42]);
	G1_AT_GraphPerf[42] = gap_cl_readhwtimer();
	S74_expr_18(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_18_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+113360)), /* expr_18_in_1 */
		((signed char * __restrict__) (main_1_L2_Memory+20392)), /* expr_18_in_2 */
		((signed char * __restrict__) (main_1_L2_Memory+20408)), /* expr_18_in_3 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+801840)) /* expr_18_out_0 */
	);
	G1_AT_GraphPerf[42] = gap_cl_readhwtimer() - G1_AT_GraphPerf[42];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[43]);
	G1_AT_GraphPerf[43] = gap_cl_readhwtimer();
	S75_expr_14(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* expr_14_in_0 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+801840)), /* expr_14_in_1 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)) /* expr_14_out_0 */
	);
	G1_AT_GraphPerf[43] = gap_cl_readhwtimer() - G1_AT_GraphPerf[43];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[44]);
	G1_AT_GraphPerf[44] = gap_cl_readhwtimer();
	S77__conv_4_conv1d_Conv_fusion_trans_in0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* Out */
	);
	G1_AT_GraphPerf[44] = gap_cl_readhwtimer() - G1_AT_GraphPerf[44];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[45]);
	G1_AT_GraphPerf[45] = gap_cl_readhwtimer();

	// cumsums[8]=0;
	// for (int i=0;i<16*65*257;++i)
	// 	cumsums[8]+=(main_1_L2_Memory_Dyn+534560)[i];

	// printf("cumsum before five %d \n",cumsums[8]);
	
	S80__conv_4_conv1d_Conv_fusion(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory+9600)), /* Filter */
		((signed int * __restrict__) (main_1_L2_Memory+19520)), /* Bias */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (main_1_L2_Memory+20424)), /* Scale */
		((signed char * __restrict__) (main_1_L2_Memory+20440)), /* ScaleN */
		((signed char * __restrict__) (main_1_L2_Memory+19876)) /* Infos */
	);
	G1_AT_GraphPerf[45] = gap_cl_readhwtimer() - G1_AT_GraphPerf[45];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[46]);
	G1_AT_GraphPerf[46] = gap_cl_readhwtimer();
	S81__conv_4_conv1d_Conv_fusion_trans_out0(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* Out */
	);
	G1_AT_GraphPerf[46] = gap_cl_readhwtimer() - G1_AT_GraphPerf[46];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[47]);
	G1_AT_GraphPerf[47] = gap_cl_readhwtimer();
	S83__conv_4_conv1d_Conv_reshape_out_qout0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20864)) /* Infos */
	);
	G1_AT_GraphPerf[47] = gap_cl_readhwtimer() - G1_AT_GraphPerf[47];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[48]);
	G1_AT_GraphPerf[48] = gap_cl_readhwtimer();
	S84__conv_4_reg1_ReduceMean(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+915200)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20456)) /* Infos */
	);


	movement_values[0] = 915200;
	movement_values[1] = 801840;
	movement_values[2] = 4112;

	

	// for (int i=0; i<movement_values[2];++i)
	// 	cumsums[4] += (main_1_L2_Memory_Dyn+movement_values[0])[i];

	


	if (!first_execution){
		move_in_L2(movement_values);

		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + movement_values[1]+movement_values[2];
		main_2CNN(G2_Input,output_imaginary,output_real);


		movement_values[0] = 801840;
		movement_values[1] = 915200;

		move_in_L2(movement_values);
	}

	
	
	

	// cumsums[4]=0;

	// for (int i=0; i<movement_values[2];++i)
	// 	cumsums[4] += (main_1_L2_Memory_Dyn+movement_values[1])[i];

	// printf("cumsum 5 after %d \n",cumsums[4]);


	G1_AT_GraphPerf[48] = gap_cl_readhwtimer() - G1_AT_GraphPerf[48];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[49]);
	G1_AT_GraphPerf[49] = gap_cl_readhwtimer();
	S85_expr_22(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_22_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+915200)), /* expr_22_in_1 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* expr_22_out_0 */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+1069120)) /* expr_22_out_1 */
	);


	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + 801840;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}


	G1_AT_GraphPerf[49] = gap_cl_readhwtimer() - G1_AT_GraphPerf[49];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[50]);
	G1_AT_GraphPerf[50] = gap_cl_readhwtimer();
	S86__conv_4_reg1_ReduceMean_1_fusion(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+1069120)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+647920)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20472)), /* Infos */
		((unsigned int * __restrict__) (main_1_L2_Memory+0)) /* RsqrtLUT */
	);
	G1_AT_GraphPerf[50] = gap_cl_readhwtimer() - G1_AT_GraphPerf[50];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[51]);
	G1_AT_GraphPerf[51] = gap_cl_readhwtimer();
	S89_expr_23(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* expr_23_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+647920)), /* expr_23_in_1 */
		((signed char * __restrict__) (main_1_L2_Memory+20488)), /* expr_23_in_2 */
		((signed char * __restrict__) (main_1_L2_Memory+20504)), /* expr_23_in_3 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1069120)) /* expr_23_out_0 */
	);
	G1_AT_GraphPerf[51] = gap_cl_readhwtimer() - G1_AT_GraphPerf[51];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[52]);
	G1_AT_GraphPerf[52] = gap_cl_readhwtimer();
	S90_expr_16(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* expr_16_in_0 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1069120)), /* expr_16_in_1 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* expr_16_out_0 */
	);
	G1_AT_GraphPerf[52] = gap_cl_readhwtimer() - G1_AT_GraphPerf[52];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[53]);
	G1_AT_GraphPerf[53] = gap_cl_readhwtimer();
	S92__conv_5_conv1d_Conv_fusion_trans_in0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)) /* Out */
	);
	G1_AT_GraphPerf[53] = gap_cl_readhwtimer() - G1_AT_GraphPerf[53];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[54]);
	G1_AT_GraphPerf[54] = gap_cl_readhwtimer();
	S95__conv_5_conv1d_Conv_fusion(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory+11904)), /* Filter */
		((signed int * __restrict__) (main_1_L2_Memory+19584)), /* Bias */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (main_1_L2_Memory+20520)), /* Scale */
		((signed char * __restrict__) (main_1_L2_Memory+20536)), /* ScaleN */
		((signed char * __restrict__) (main_1_L2_Memory+19896)) /* Infos */
	);
	G1_AT_GraphPerf[54] = gap_cl_readhwtimer() - G1_AT_GraphPerf[54];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[55]);
	G1_AT_GraphPerf[55] = gap_cl_readhwtimer();
	S96__conv_5_conv1d_Conv_fusion_trans_out0(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)) /* Out */
	);
	G1_AT_GraphPerf[55] = gap_cl_readhwtimer() - G1_AT_GraphPerf[55];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[56]);
	G1_AT_GraphPerf[56] = gap_cl_readhwtimer();
	S98__conv_5_conv1d_Conv_reshape_out_qout0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20872)) /* Infos */
	);
	G1_AT_GraphPerf[56] = gap_cl_readhwtimer() - G1_AT_GraphPerf[56];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[57]);
	G1_AT_GraphPerf[57] = gap_cl_readhwtimer();
	S99__conv_5_reg1_ReduceMean(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+915200)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20552)) /* Infos */
	);
	
	// cumsums[5]=0;
	// for (int i=0; i<4112;++i)
	// 	cumsums[5] += (main_1_L2_Memory_Dyn+915200)[i];

	// printf("cumsum 6 %d \n",cumsums[5]);

	movement_values[0] = 915200;
	movement_values[1] = 801840;
	movement_values[2] = 4112;

	move_in_L2(movement_values);

	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + movement_values[1]+movement_values[2];
		main_2CNN(G2_Input,output_imaginary,output_real);
	}


	// cumsums[5]=0;
	// for (int i=0; i<movement_values[2];++i)
	// 	cumsums[5] += (main_1_L2_Memory_Dyn+movement_values[1])[i];

	// printf("cumsum 6 %d \n",cumsums[5]);

	
	movement_values[0] = 801840;
	movement_values[1] = 915200;

	move_in_L2(movement_values);


	G1_AT_GraphPerf[57] = gap_cl_readhwtimer() - G1_AT_GraphPerf[57];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[58]);
	G1_AT_GraphPerf[58] = gap_cl_readhwtimer();
	S100_expr_25(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* expr_25_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+915200)), /* expr_25_in_1 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* expr_25_out_0 */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+1336400)) /* expr_25_out_1 */
	);

	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + 534560 + 267280;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}


	G1_AT_GraphPerf[58] = gap_cl_readhwtimer() - G1_AT_GraphPerf[58];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[59]);
	G1_AT_GraphPerf[59] = gap_cl_readhwtimer();
	S101__conv_5_reg1_ReduceMean_1_fusion(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+1336400)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+113360)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20568)), /* Infos */
		((unsigned int * __restrict__) (main_1_L2_Memory+0)) /* RsqrtLUT */
	);
	G1_AT_GraphPerf[59] = gap_cl_readhwtimer() - G1_AT_GraphPerf[59];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[60]);
	G1_AT_GraphPerf[60] = gap_cl_readhwtimer();
	S104_expr_26(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* expr_26_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+113360)), /* expr_26_in_1 */
		((signed char * __restrict__) (main_1_L2_Memory+20584)), /* expr_26_in_2 */
		((signed char * __restrict__) (main_1_L2_Memory+20600)), /* expr_26_in_3 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1336400)) /* expr_26_out_0 */
	);
	G1_AT_GraphPerf[60] = gap_cl_readhwtimer() - G1_AT_GraphPerf[60];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[61]);
	G1_AT_GraphPerf[61] = gap_cl_readhwtimer();
	S105_expr_19(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_19_in_0 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1336400)), /* expr_19_in_1 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)) /* expr_19_out_0 */
	);
	G1_AT_GraphPerf[61] = gap_cl_readhwtimer() - G1_AT_GraphPerf[61];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[62]);
	G1_AT_GraphPerf[62] = gap_cl_readhwtimer();
	S107__conv_6_conv1d_Conv_fusion_trans_in0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* Out */
	);
	G1_AT_GraphPerf[62] = gap_cl_readhwtimer() - G1_AT_GraphPerf[62];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[63]);
	G1_AT_GraphPerf[63] = gap_cl_readhwtimer();
	S110__conv_6_conv1d_Conv_fusion(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory+14208)), /* Filter */
		((signed int * __restrict__) (main_1_L2_Memory+19648)), /* Bias */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (main_1_L2_Memory+20616)), /* Scale */
		((signed char * __restrict__) (main_1_L2_Memory+20632)), /* ScaleN */
		((signed char * __restrict__) (main_1_L2_Memory+19916)) /* Infos */
	);
	G1_AT_GraphPerf[63] = gap_cl_readhwtimer() - G1_AT_GraphPerf[63];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[64]);
	G1_AT_GraphPerf[64] = gap_cl_readhwtimer();
	S111__conv_6_conv1d_Conv_fusion_trans_out0(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* Out */
	);
	G1_AT_GraphPerf[64] = gap_cl_readhwtimer() - G1_AT_GraphPerf[64];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[65]);
	G1_AT_GraphPerf[65] = gap_cl_readhwtimer();
	S113__conv_6_conv1d_Conv_reshape_out_qout0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20880)) /* Infos */
	);
	G1_AT_GraphPerf[65] = gap_cl_readhwtimer() - G1_AT_GraphPerf[65];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[66]);
	G1_AT_GraphPerf[66] = gap_cl_readhwtimer();
	S114__conv_6_reg1_ReduceMean(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+915200)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20648)) /* Infos */
	);

	

	// cumsums[5]=0;


	// for (int i=0; i<movement_values[2];++i)
	// 	cumsums[5] += (main_1_L2_Memory_Dyn+915200)[i];

	// printf("cumsum 6 %d \n",cumsums[5]);

	if (!first_execution){

		movement_values[0] = 915200;
		movement_values[1] = 801840;
		movement_values[2] = 4112;

		move_in_L2(movement_values);

		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + movement_values[1]+movement_values[2];
		main_2CNN(G2_Input,output_imaginary,output_real);

		movement_values[0] = 801840;
		movement_values[1] = 915200;

		move_in_L2(movement_values);


	}
	// cumsums[5]=0;
	
	// for (int i=0; i<movement_values[2];++i)
	// 	cumsums[5] += (main_1_L2_Memory_Dyn+915200)[i];

	// printf("cumsum 6 %d \n",cumsums[5]);

	
	



	G1_AT_GraphPerf[66] = gap_cl_readhwtimer() - G1_AT_GraphPerf[66];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[67]);
	G1_AT_GraphPerf[67] = gap_cl_readhwtimer();
	S115_expr_28(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_28_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+915200)), /* expr_28_in_1 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1870960)), /* expr_28_out_0 */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)) /* expr_28_out_1 */
	);

	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + 534560;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}


	G1_AT_GraphPerf[67] = gap_cl_readhwtimer() - G1_AT_GraphPerf[67];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[68]);
	G1_AT_GraphPerf[68] = gap_cl_readhwtimer();
	S116__conv_6_reg1_ReduceMean_1_fusion(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+647920)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20664)), /* Infos */
		((unsigned int * __restrict__) (main_1_L2_Memory+0)) /* RsqrtLUT */
	);
	G1_AT_GraphPerf[68] = gap_cl_readhwtimer() - G1_AT_GraphPerf[68];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[69]);
	G1_AT_GraphPerf[69] = gap_cl_readhwtimer();
	S119_expr_29(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1870960)), /* expr_29_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+647920)), /* expr_29_in_1 */
		((signed char * __restrict__) (main_1_L2_Memory+20680)), /* expr_29_in_2 */
		((signed char * __restrict__) (main_1_L2_Memory+20696)), /* expr_29_in_3 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1603680)) /* expr_29_out_0 */
	);
	G1_AT_GraphPerf[69] = gap_cl_readhwtimer() - G1_AT_GraphPerf[69];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[70]);
	G1_AT_GraphPerf[70] = gap_cl_readhwtimer();
	S120_expr_20(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* expr_20_in_0 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1603680)), /* expr_20_in_1 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* expr_20_out_0 */
	);
	G1_AT_GraphPerf[70] = gap_cl_readhwtimer() - G1_AT_GraphPerf[70];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[71]);
	G1_AT_GraphPerf[71] = gap_cl_readhwtimer();
	S122__conv_7_conv1d_Conv_fusion_trans_in0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)) /* Out */
	);


	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_L2_Memory_Dyn + 534560;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}

	G1_AT_GraphPerf[71] = gap_cl_readhwtimer() - G1_AT_GraphPerf[71];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[72]);
	G1_AT_GraphPerf[72] = gap_cl_readhwtimer();
	S125__conv_7_conv1d_Conv_fusion(
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory+16512)), /* Filter */
		((signed int * __restrict__) (main_1_L2_Memory+19712)), /* Bias */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (main_1_L2_Memory+20712)), /* Scale */
		((signed char * __restrict__) (main_1_L2_Memory+20728)), /* ScaleN */
		((signed char * __restrict__) (main_1_L2_Memory+19936)) /* Infos */
	);
	G1_AT_GraphPerf[72] = gap_cl_readhwtimer() - G1_AT_GraphPerf[72];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[73]);
	G1_AT_GraphPerf[73] = gap_cl_readhwtimer();
	S126__conv_7_conv1d_Conv_fusion_trans_out0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* Out */
	);
	G1_AT_GraphPerf[73] = gap_cl_readhwtimer() - G1_AT_GraphPerf[73];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[74]);
	G1_AT_GraphPerf[74] = gap_cl_readhwtimer();
	S128__conv_7_conv1d_Conv_reshape_out_qout0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20888)) /* Infos */
	);
	G1_AT_GraphPerf[74] = gap_cl_readhwtimer() - G1_AT_GraphPerf[74];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[75]);
	G1_AT_GraphPerf[75] = gap_cl_readhwtimer();
	S129__conv_7_reg1_ReduceMean(
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+834736)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20744)) /* Infos */
	);
	G1_AT_GraphPerf[75] = gap_cl_readhwtimer() - G1_AT_GraphPerf[75];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[76]);
	G1_AT_GraphPerf[76] = gap_cl_readhwtimer();
	S130_expr_31(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_31_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+834736)), /* expr_31_in_1 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* expr_31_out_0 */
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)) /* expr_31_out_1 */
	);
	G1_AT_GraphPerf[76] = gap_cl_readhwtimer() - G1_AT_GraphPerf[76];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[77]);
	G1_AT_GraphPerf[77] = gap_cl_readhwtimer();
	S131__conv_7_reg1_ReduceMean_1_fusion(
		((signed char * __restrict__) (main_1_L3_Memory_Dyn+0)), /* In */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+801840)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20760)), /* Infos */
		((unsigned int * __restrict__) (main_1_L2_Memory+0)) /* RsqrtLUT */
	);
	G1_AT_GraphPerf[77] = gap_cl_readhwtimer() - G1_AT_GraphPerf[77];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[78]);
	G1_AT_GraphPerf[78] = gap_cl_readhwtimer();
	S134_expr_32(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* expr_32_in_0 */
		((signed char * __restrict__) (main_1_L2_Memory_Dyn+801840)), /* expr_32_in_1 */
		((signed char * __restrict__) (main_1_L2_Memory+20776)), /* expr_32_in_2 */
		((signed char * __restrict__) (main_1_L2_Memory+20792)), /* expr_32_in_3 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)) /* expr_32_out_0 */
	);
	G1_AT_GraphPerf[78] = gap_cl_readhwtimer() - G1_AT_GraphPerf[78];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[79]);
	G1_AT_GraphPerf[79] = gap_cl_readhwtimer();
	S135_expr_4(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)), /* expr_4_in_0 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+267280)), /* expr_4_in_1 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+534560)), /* expr_4_in_2 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+801840)), /* expr_4_in_3 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1069120)), /* expr_4_in_4 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1336400)), /* expr_4_in_5 */
		((unsigned char * __restrict__) (main_1_L3_Memory_Dyn+1603680)), /* expr_4_in_6 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+534560)), /* expr_4_in_7 */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)) /* expr_4_out_0 */
	);
	G1_AT_GraphPerf[79] = gap_cl_readhwtimer() - G1_AT_GraphPerf[79];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[80]);
	G1_AT_GraphPerf[80] = gap_cl_readhwtimer();
	S137__reshape_speech_reshape_speech_0_Conv_fusion_trans_in0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)) /* Out */
	);
	G1_AT_GraphPerf[80] = gap_cl_readhwtimer() - G1_AT_GraphPerf[80];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[81]);
	G1_AT_GraphPerf[81] = gap_cl_readhwtimer();
	S140__reshape_speech_reshape_speech_0_Conv_fusion(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+267280)), /* In */
		((unsigned char * __restrict__) (main_1_L2_Memory+20808)), /* Filter */
		((signed int * __restrict__) (main_1_L2_Memory+20912)), /* Bias */
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+66820)), /* Out */
		((unsigned char * __restrict__) (main_1_L2_Memory+20916)), /* Scale */
		((signed char * __restrict__) (main_1_L2_Memory+20920)), /* ScaleN */
		((signed char * __restrict__) (main_1_L2_Memory+19956)), /* Infos */
		((unsigned char * __restrict__) (main_1_L2_Memory+19072)) /* SigmoidLUT_u8 */
	);
	G1_AT_GraphPerf[81] = gap_cl_readhwtimer() - G1_AT_GraphPerf[81];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[82]);
	G1_AT_GraphPerf[82] = gap_cl_readhwtimer();
	S142_expr_33(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+66820)), /* expr_33_in_0 */
		((float * __restrict__) (main_1_L2_Memory_Dyn+83528)) /* expr_33_out_0 */
	);
	G1_AT_GraphPerf[82] = gap_cl_readhwtimer() - G1_AT_GraphPerf[82];
	//printf("Node %s starts\n", G1_AT_GraphNodeNames[83]);
	G1_AT_GraphPerf[83] = gap_cl_readhwtimer();
	S144__reshape_speech_reshape_speech_0_Conv_reshape_qout0(
		((unsigned char * __restrict__) (main_1_L2_Memory_Dyn+66820)), /* In */
		((float * __restrict__) (main_1_L2_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (main_1_L2_Memory+20896)) /* Infos */
	);
	G1_AT_GraphPerf[83] = gap_cl_readhwtimer() - G1_AT_GraphPerf[83];
	G1_AT_GraphPerf_CNN_Total = gap_cl_readhwtimer() - G1_AT_GraphPerf_CNN_Total;
	return 0;
}
