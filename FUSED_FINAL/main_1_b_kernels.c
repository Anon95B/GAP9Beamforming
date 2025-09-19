#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "main_2Kernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER main_1_b_L1_Memory;
L2_MEM AT_L2_POINTER main_1_b_L2_Memory;
L2_MEM AT_L2_POINTER main_1_b_L2_Memory_Dyn;
AT_DEFAULTRAM_POINTER main_1_b_L3_Memory_Dyn;
// static AT_DEFAULTRAM_T DefaultRam;
static AT_DEFAULTFLASH_FS_T DefaultFlash;
void  G1_2S2__ReduceSum(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 67848 bytes, L2 buffer: 0 bytes */
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
			@ 0 (Total Size: 66820 )[D0, [0 x 66820, 66820]][Tile0, 1:[13x5], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 66820, 66820]][Tile0, 1:[13x5], 4]
		Tile0: [0, 66820, 66820], Tile1: [0, 66820, 66820], Tile2; [0, 66820, 66820]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 66820 (Total Size: 1028 )[D0, [0 x 1028, 1028]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 1028, 1028]]
		Tile0: [0, 1028, 1028], Tile1: [0, 1028, 1028], Tile2; [0, 1028, 1028]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (float * __restrict__) (main_1_b_L1_Memory+0);
	KerArg0->W = (unsigned short int) (13);
	KerArg0->H = (unsigned short int) (5);
	KerArg0->FullHW = (unsigned int) (65);
	KerArg0->OutFeatures = (unsigned short int) (257);
	KerArg0->Out = (float * __restrict__) (main_1_b_L1_Memory+66820);
	KerArg0->LastTile = (unsigned int) ((1));
	KerArg0->TileIndex = (unsigned int) ((0));
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), 66820, 0, DmaR_Evt1);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+66820), 1028, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S10_expr_0(
		float * __restrict__ expr_0_in_0,
		float * __restrict__ expr_0_in_1,
		float * __restrict__ expr_0_in_2,
		float * __restrict__ expr_0_out_0,
		float * __restrict__ expr_0_out_1)

{
	/* Shared L1: 10240 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	G1_2s10_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int D2Ind, D2Ind_Last, D2Ind_NextLast, D2Ind_NextNextLast;
	int D3Ind, D3Ind_Total=0, D3Ind_Last, D3Ind_NextLast, D3Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _P_expr_0_out_0, _C_expr_0_out_0;
	unsigned int _SPP_expr_0_out_0, _SP_expr_0_out_0, _SC_expr_0_out_0;
	unsigned int _LPP_expr_0_out_0, _LP_expr_0_out_0, _LC_expr_0_out_0;
	unsigned int _NN_expr_0_in_0;
	unsigned int _SN_expr_0_in_0, _SNN_expr_0_in_0;
	unsigned int _LN_expr_0_in_0, _LNN_expr_0_in_0;
	unsigned int _N_expr_0_in_1;
	unsigned int _SN_expr_0_in_1;
	unsigned int _C_expr_0_out_1;
	unsigned int _SP_expr_0_out_1, _SC_expr_0_out_1;
	unsigned int _LP_expr_0_out_1, _LC_expr_0_out_1;
	unsigned int _N_expr_0_in_2;
	unsigned int _SN_expr_0_in_2;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 2][D1 Dim: 257][D2 Dim: Init: 6, Tiled: 1][D3 Dim: Init: 65, Tiled: 2][Tile0 Dim: 1]
	Ker Arg: expr_0_out_0, Tiled Space: D3
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 1028 logical tiles, 1028 physical tiles
			@ 0 (Total Size: 801840 )[D0, [1 x 400920, 400920]][D1, [256 x 1560, 1560]][D2, [0 x 1560, 1560]][D3, [1 x 1536, 24]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 400920, 400920]][D1, [256 x 1560, 1560]][D2, [0 x 1560, 1560]][D3, [1 x 1536, 24]]
		Tile0: [0, 1536, 256], Tile1: [256, 24, 4], Tile2; [1560, 1536, 256]
	Ker Arg: expr_0_in_0, Tiled Space: D3
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 1028 logical tiles, 1028 physical tiles
			@ 3072 (Total Size: 801840 )[D0, [1 x 400920, 400920]][D1, [256 x 1560, 1560]][D2, [0 x 1560, 1560]][D3, [1 x 1536, 24]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 400920, 400920]][D1, [256 x 1560, 1560]][D2, [0 x 1560, 1560]][D3, [1 x 1536, 24]]
		Tile0: [0, 1536, 256], Tile1: [256, 24, 4], Tile2; [1560, 1536, 256]
	Ker Arg: expr_0_in_1, Tiled Space: D3
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 514 logical tiles, 514 physical tiles
			@ 6144 (Total Size: 66820 )[D1, [256 x 260, 260]][D3, [1 x 256, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [256 x 260, 260]][D3, [1 x 256, 4]]
		Tile0: [0, 256, 256], Tile1: [256, 4, 4], Tile2; [260, 256, 256]
	Ker Arg: expr_0_out_1, Tiled Space: D3
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 1028 logical tiles, 1028 physical tiles
			@ 6656 (Total Size: 801840 )[D0, [1 x 400920, 400920]][D1, [256 x 1560, 1560]][D2, [0 x 1560, 1560]][D3, [1 x 1536, 24]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 400920, 400920]][D1, [256 x 1560, 1560]][D2, [0 x 1560, 1560]][D3, [1 x 1536, 24]]
		Tile0: [0, 1536, 256], Tile1: [256, 24, 4], Tile2; [1560, 1536, 256]
	Ker Arg: expr_0_in_2, Tiled Space: D3
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 514 logical tiles, 514 physical tiles
			@ 9728 (Total Size: 66820 )[D1, [256 x 260, 260]][D3, [1 x 256, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [256 x 260, 260]][D3, [1 x 256, 4]]
		Tile0: [0, 256, 256], Tile1: [256, 4, 4], Tile2; [260, 256, 256]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1);
	KerArg0->I1 = (unsigned int) (1);
	KerArg0->I2 = (unsigned int) (6);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_0_out_0=0; _SC_expr_0_out_0=1536; _LC_expr_0_out_0=256;
	_SPP_expr_0_out_0=0; _SP_expr_0_out_0=0;
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_0_in_0+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+939580+0), 1536, 260, 256, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_0_in_0 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_0_in_0+256), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+939580+1536), 24, 260, 4, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+939580+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3072+0), 1536, 0, DmaR_Evt1);
	_NN_expr_0_in_0=256; _SN_expr_0_in_0=24;
	_C_expr_0_out_1=0; _SC_expr_0_out_1=1536; _LC_expr_0_out_1=256;
	_SP_expr_0_out_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6144+0), 256, 0, DmaR_Evt2);
	_N_expr_0_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+9728+0), 256, 0, DmaR_Evt3);
	_N_expr_0_in_2=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<2; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==1), D0Ind_NextLast = ((D0Ind+1)==1), D0Ind_NextNextLast = ((D0Ind+2)==1);
		for (D1Ind=0; D1Ind<257; D1Ind++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==256), D1Ind_NextLast = ((D1Ind+1)==256), D1Ind_NextNextLast = ((D1Ind+2)==256);
			{ /* Single iteration on D2 */
				int D2Ind_Last = 1, D2Ind_NextLast = 1, D2Ind_NextNextLast = 1;
				for (D3Ind=0; D3Ind<2; D3Ind++, D3Ind_Total++) { /* Iteration on D3 */
					int D3Ind_Last = (D3Ind==1), D3Ind_NextLast = ((D3Ind+1)==1), D3Ind_NextNextLast = ((D3Ind+2)==1);
					/*================================= Prepare Tiles ===================================*/
					_SNN_expr_0_in_0 = 0;
					if (!(D3Ind_Last)) {
						if (!(1)) {
							_NN_expr_0_in_0 = _NN_expr_0_in_0 + (256); _LNN_expr_0_in_0 = ((1)?4:256); _SNN_expr_0_in_0 = (6*_LNN_expr_0_in_0); 
						} else if (!((1))) {
							_NN_expr_0_in_0 = _NN_expr_0_in_0 + (-256); _LNN_expr_0_in_0 = (256); _SNN_expr_0_in_0 = (6*_LNN_expr_0_in_0); 
						} else if (!(D1Ind_Last)) {
							_NN_expr_0_in_0 = _NN_expr_0_in_0 + (1560)+(-256); _LNN_expr_0_in_0 = (256); _SNN_expr_0_in_0 = (6*_LNN_expr_0_in_0); 
						} else if (!(D0Ind_Last)) {
							_NN_expr_0_in_0 = _NN_expr_0_in_0 + (400920)+(-399360)+(-256); _LNN_expr_0_in_0 = (256); _SNN_expr_0_in_0 = (6*_LNN_expr_0_in_0); 
						}
					} else if (!((1))) {
						_NN_expr_0_in_0 = _NN_expr_0_in_0 + (256); _LNN_expr_0_in_0 = (4); _SNN_expr_0_in_0 = (6*_LNN_expr_0_in_0); 
					} else if (!(D1Ind_Last)) {
						_NN_expr_0_in_0 = _NN_expr_0_in_0 + (256); _LNN_expr_0_in_0 = (4); _SNN_expr_0_in_0 = (6*_LNN_expr_0_in_0); 
					} else if (!(D0Ind_Last)) {
						_NN_expr_0_in_0 = _NN_expr_0_in_0 + (256); _LNN_expr_0_in_0 = (4); _SNN_expr_0_in_0 = (6*_LNN_expr_0_in_0); 
					}
					_SN_expr_0_in_1 = 0;
					if (!(D3Ind_Last)) {
						_N_expr_0_in_1 = _N_expr_0_in_1 + (256); _SN_expr_0_in_1 = ((1)?4:256); 
					} else if (!((1))) {
						_N_expr_0_in_1 = _N_expr_0_in_1 + (-256); _SN_expr_0_in_1 = (256); 
					} else if (!(D1Ind_Last)) {
						_N_expr_0_in_1 = _N_expr_0_in_1 + (260)+(-256); _SN_expr_0_in_1 = (256); 
					} else if (!(D0Ind_Last)) {
						_N_expr_0_in_1 = _N_expr_0_in_1 + (-66560)+(-256); _SN_expr_0_in_1 = (256); 
					}
					_SN_expr_0_in_2 = 0;
					if (!(D3Ind_Last)) {
						_N_expr_0_in_2 = _N_expr_0_in_2 + (256); _SN_expr_0_in_2 = ((1)?4:256); 
					} else if (!((1))) {
						_N_expr_0_in_2 = _N_expr_0_in_2 + (-256); _SN_expr_0_in_2 = (256); 
					} else if (!(D1Ind_Last)) {
						_N_expr_0_in_2 = _N_expr_0_in_2 + (260)+(-256); _SN_expr_0_in_2 = (256); 
					} else if (!(D0Ind_Last)) {
						_N_expr_0_in_2 = _N_expr_0_in_2 + (-66560)+(-256); _SN_expr_0_in_2 = (256); 
					}
					/*============================= End Prepare Tiles ===================================*/
					/*================================= Read Tiles ======================================*/
					AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_0_in_0 */
					AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_0_in_0 before starting the next buffer load from L3 which will overwrite this */
					if (_SNN_expr_0_in_0) {
						AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_0_in_0+_NN_expr_0_in_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+939580+1536*((D3Ind_Total)%2)),
								1*(_SNN_expr_0_in_0), 260, _LNN_expr_0_in_0, 0, UchanHR1);
					}
					if (_SN_expr_0_in_0) {
						AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+939580+1536*((D3Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3072+1536*((D3Ind_Total+1)%2)),
								1*(_SN_expr_0_in_0), 0, DmaR_Evt1);
					}
					AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_0_in_1 */
					if (_SN_expr_0_in_1) {
						AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_1+_N_expr_0_in_1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6144+256*((D3Ind_Total+1)%2)),
								1*(_SN_expr_0_in_1), 0, DmaR_Evt2);
					}
					AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read expr_0_in_2 */
					if (_SN_expr_0_in_2) {
						AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_in_2+_N_expr_0_in_2), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+9728+256*((D3Ind_Total+1)%2)),
								1*(_SN_expr_0_in_2), 0, DmaR_Evt3);
					}
					/*============================= End Read Tiles ======================================*/
					{ /* Single iteration on Tile0 */
						int T0Ind_Last = 1;
					} /* End iteration on Tile0 */
					/*====================== Call Kernel LOC_D3 =========================*/
					KerArg0->I3 = (unsigned int) ((D3Ind_Last)?1:64);
					KerArg0->expr_0_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+3072+1536*((D3Ind_Total)%2));
					KerArg0->expr_0_in_1 = (float *__restrict__ ) (main_1_b_L1_Memory+6144+256*((D3Ind_Total)%2));
					KerArg0->expr_0_in_2 = (float *__restrict__ ) (main_1_b_L1_Memory+9728+256*((D3Ind_Total)%2));
					KerArg0->expr_0_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+0+1536*((D3Ind_Total)%2));
					KerArg0->expr_0_out_1 = (float *__restrict__ ) (main_1_b_L1_Memory+6656+1536*((D3Ind_Total)%2));
					AT_FORK(gap_ncore(), (void *) G1_2s10_kernel, (void *) KerArg0);
					__CALL(G1_2s10_kernel, KerArg0);
					/*================================= Write Tiles =====================================*/
					if (_SP_expr_0_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_0_out_0 */
					if (_SPP_expr_0_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_0_out_0 */
					if (_SP_expr_0_out_0) AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_0_out_0+_P_expr_0_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+935480+1536*((D3Ind_Total+-1)%2)),
								_SP_expr_0_out_0, 260, _LP_expr_0_out_0, 1, UchanHR2);
					AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+935480+1536*((D3Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+1536*((D3Ind_Total)%2)),
							_SC_expr_0_out_0, 1, DmaW_Evt1);
					if (_SP_expr_0_out_1) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_0_out_1 */
					AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_0_out_1+_C_expr_0_out_1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6656+1536*((D3Ind_Total)%2)),
							_SC_expr_0_out_1, 260, _LC_expr_0_out_1, 1, DmaW_Evt2);
					/*============================= End Write Tiles =====================================*/
					/*================================= Update Arg Pipeline =============================*/
					_SPP_expr_0_out_0 = _SP_expr_0_out_0;_LPP_expr_0_out_0 = _LP_expr_0_out_0;
					_P_expr_0_out_0 = _C_expr_0_out_0;_SP_expr_0_out_0 = _SC_expr_0_out_0;_LP_expr_0_out_0 = _LC_expr_0_out_0;
					_SN_expr_0_in_0 = _SNN_expr_0_in_0;_LN_expr_0_in_0 = _LNN_expr_0_in_0;
					_SP_expr_0_out_1 = _SC_expr_0_out_1;_LP_expr_0_out_1 = _LC_expr_0_out_1;
					/*============================= End Update Arg Pipeline =============================*/
					/*================================= Prepare Tiles ===================================*/
					_SC_expr_0_out_0 = 0;
					if (!(D3Ind_Last)) {
						_C_expr_0_out_0 = _C_expr_0_out_0 + (256); _LC_expr_0_out_0 = ((1)?4:256); _SC_expr_0_out_0 = (6*_LC_expr_0_out_0); 
					} else if (!(D1Ind_Last)) {
						_C_expr_0_out_0 = _C_expr_0_out_0 + (1560)+(-256); _LC_expr_0_out_0 = (256); _SC_expr_0_out_0 = (6*_LC_expr_0_out_0); 
					} else if (!(D0Ind_Last)) {
						_C_expr_0_out_0 = _C_expr_0_out_0 + (400920)+(-399360)+(-256); _LC_expr_0_out_0 = (256); _SC_expr_0_out_0 = (6*_LC_expr_0_out_0); 
					}
					_SC_expr_0_out_1 = 0;
					if (!(D3Ind_Last)) {
						_C_expr_0_out_1 = _C_expr_0_out_1 + (256); _LC_expr_0_out_1 = ((1)?4:256); _SC_expr_0_out_1 = (6*_LC_expr_0_out_1); 
					} else if (!(D1Ind_Last)) {
						_C_expr_0_out_1 = _C_expr_0_out_1 + (1560)+(-256); _LC_expr_0_out_1 = (256); _SC_expr_0_out_1 = (6*_LC_expr_0_out_1); 
					} else if (!(D0Ind_Last)) {
						_C_expr_0_out_1 = _C_expr_0_out_1 + (400920)+(-399360)+(-256); _LC_expr_0_out_1 = (256); _SC_expr_0_out_1 = (6*_LC_expr_0_out_1); 
					}
					/*============================= End Prepare Tiles ===================================*/
				} /* End iteration on D3 */
			} /* End iteration on D2 */
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_0_out_0 */
	if (_SPP_expr_0_out_0) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write expr_0_out_0 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_0_out_0+_P_expr_0_out_0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+935480+1536*((D3Ind_Total+-1)%2)), _SP_expr_0_out_0, 260, _LP_expr_0_out_0, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write expr_0_out_0 */
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_0_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S18__MatMul(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out)

{
	/* Shared L1: 6552 bytes, L2 buffer: 0 bytes */
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
			@ 0 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3408 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6528 (Total Size: 24 )[Tile0, 1:[1x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x6], 4]
		Tile0: [0, 24, 24], Tile1: [0, 24, 24], Tile2; [0, 24, 24]
	Ker Arg: Out, Tiled Space: Tile1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3120 (Total Size: 37008 )[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		Tile0: [0, 144, 144], Tile1: [144, 144, 144], Tile2; [288, 144, 144]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W_In1 = (unsigned short int) (65);
	KerArg0->H_In1 = (unsigned short int) (6);
	KerArg0->W_In2 = (unsigned short int) (6);
	KerArg0->Bias = (float *__restrict__) (main_1_b_L1_Memory+6528);
	KerArg0->W_Out = (unsigned short int) (6);
	KerArg0->ColFirst = (unsigned char) (0);
	KerArg0->UB = (float) (6.000000e+00);
	KerArg0->LB = (float) (0.000000e+00);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+0), 1560, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560), 1560, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 1560, 0, DmaR_Evt1);
	_NN_In1=1560; _SN_In1=1560;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+3120+0), 1560, 0, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read In2 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+3120+1560), 1560, 0, UchanHR2);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+3120+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+0), 1560, 0, DmaR_Evt2);
	_NN_In2=1560; _SN_In2=1560;
	_C_Out=0; _SC_Out=144;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6528), 24, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Bias */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<257; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==256), D0Ind_NextLast = ((D0Ind+1)==256), D0Ind_NextNextLast = ((D0Ind+2)==256);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In1 = _NN_In1 + (1560); _SNN_In1 = (1560); 
			}
		}
		_SNN_In2 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In2 = _NN_In2 + (1560); _SNN_In2 = (1560); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+_NN_In1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560*((D0Ind_Total)%2)),
					1*(_SNN_In1), 0, UchanHR1);
		}
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read In2 */
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In2) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+_NN_In2), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+3120+1560*((D0Ind_Total)%2)),
					1*(_SNN_In2), 0, UchanHR2);
		}
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+3120+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile1 */
			int T1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
				/*====================== Call Kernel LOC_LOOP =========================*/
				KerArg0->In1 = (float *__restrict__) (main_1_b_L1_Memory+0+1560*((D0Ind_Total)%2));
				KerArg0->In2 = (float *__restrict__) (main_1_b_L1_Memory+3408+1560*((D0Ind_Total)%2));
				KerArg0->Out = (float *__restrict__) (main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2));
				KerArg0->OutFirstCol = (unsigned int) ((0)*6);
				AT_FORK(gap_ncore(), (void *) KerParMatMulTransposed_fp32, (void *) KerArg0);
				__CALL(KerParMatMulTransposed_fp32, KerArg0);
			} /* End iteration on Tile0 */
		} /* End iteration on Tile1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2)),
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
			_C_Out = _C_Out + (144); _SC_Out = (144); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S21__MatMul_1(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out)

{
	/* Shared L1: 6552 bytes, L2 buffer: 0 bytes */
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
			@ 0 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3408 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6528 (Total Size: 24 )[Tile0, 1:[1x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x6], 4]
		Tile0: [0, 24, 24], Tile1: [0, 24, 24], Tile2; [0, 24, 24]
	Ker Arg: Out, Tiled Space: Tile1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3120 (Total Size: 37008 )[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		Tile0: [0, 144, 144], Tile1: [144, 144, 144], Tile2; [288, 144, 144]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W_In1 = (unsigned short int) (65);
	KerArg0->H_In1 = (unsigned short int) (6);
	KerArg0->W_In2 = (unsigned short int) (6);
	KerArg0->Bias = (float *__restrict__) (main_1_b_L1_Memory+6528);
	KerArg0->W_Out = (unsigned short int) (6);
	KerArg0->ColFirst = (unsigned char) (0);
	KerArg0->UB = (float) (6.000000e+00);
	KerArg0->LB = (float) (0.000000e+00);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+0), 1560, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560), 1560, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 1560, 0, DmaR_Evt1);
	_NN_In1=1560; _SN_In1=1560;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+77136+0), 1560, 0, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read In2 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+77136+1560), 1560, 0, UchanHR2);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+77136+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+0), 1560, 0, DmaR_Evt2);
	_NN_In2=1560; _SN_In2=1560;
	_C_Out=0; _SC_Out=144;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6528), 24, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Bias */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<257; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==256), D0Ind_NextLast = ((D0Ind+1)==256), D0Ind_NextNextLast = ((D0Ind+2)==256);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In1 = _NN_In1 + (1560); _SNN_In1 = (1560); 
			}
		}
		_SNN_In2 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In2 = _NN_In2 + (1560); _SNN_In2 = (1560); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+_NN_In1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560*((D0Ind_Total)%2)),
					1*(_SNN_In1), 0, UchanHR1);
		}
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read In2 */
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In2) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+_NN_In2), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+77136+1560*((D0Ind_Total)%2)),
					1*(_SNN_In2), 0, UchanHR2);
		}
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+77136+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile1 */
			int T1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
				/*====================== Call Kernel LOC_LOOP =========================*/
				KerArg0->In1 = (float *__restrict__) (main_1_b_L1_Memory+0+1560*((D0Ind_Total)%2));
				KerArg0->In2 = (float *__restrict__) (main_1_b_L1_Memory+3408+1560*((D0Ind_Total)%2));
				KerArg0->Out = (float *__restrict__) (main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2));
				KerArg0->OutFirstCol = (unsigned int) ((0)*6);
				AT_FORK(gap_ncore(), (void *) KerParMatMulTransposed_fp32, (void *) KerArg0);
				__CALL(KerParMatMulTransposed_fp32, KerArg0);
			} /* End iteration on Tile0 */
		} /* End iteration on Tile1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2)),
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
			_C_Out = _C_Out + (144); _SC_Out = (144); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S23_expr_1(
		float * __restrict__ expr_1_in_0,
		float * __restrict__ expr_1_in_1,
		float * __restrict__ expr_1_out_0)

{
	/* Shared L1: 111024 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	G1_2s23_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 9252, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_1_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	Ker Arg: expr_1_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 37008 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	Ker Arg: expr_1_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 74016 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (9252);
	KerArg0->expr_1_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+37008);
	KerArg0->expr_1_in_1 = (float *__restrict__ ) (main_1_b_L1_Memory+74016);
	KerArg0->expr_1_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+37008), 37008, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+74016), 37008, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_1_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) G1_2s23_kernel, (void *) KerArg0);
		__CALL(G1_2s23_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_1_out_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), 37008, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_1_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S25__MatMul_2(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out)

{
	/* Shared L1: 6552 bytes, L2 buffer: 0 bytes */
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
			@ 0 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3408 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6528 (Total Size: 24 )[Tile0, 1:[1x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x6], 4]
		Tile0: [0, 24, 24], Tile1: [0, 24, 24], Tile2; [0, 24, 24]
	Ker Arg: Out, Tiled Space: Tile1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3120 (Total Size: 37008 )[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		Tile0: [0, 144, 144], Tile1: [144, 144, 144], Tile2; [288, 144, 144]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W_In1 = (unsigned short int) (65);
	KerArg0->H_In1 = (unsigned short int) (6);
	KerArg0->W_In2 = (unsigned short int) (6);
	KerArg0->Bias = (float *__restrict__) (main_1_b_L1_Memory+6528);
	KerArg0->W_Out = (unsigned short int) (6);
	KerArg0->ColFirst = (unsigned char) (0);
	KerArg0->UB = (float) (6.000000e+00);
	KerArg0->LB = (float) (0.000000e+00);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+0), 1560, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560), 1560, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 1560, 0, DmaR_Evt1);
	_NN_In1=1560; _SN_In1=1560;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+3120+0), 1560, 0, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read In2 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+3120+1560), 1560, 0, UchanHR2);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+3120+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+0), 1560, 0, DmaR_Evt2);
	_NN_In2=1560; _SN_In2=1560;
	_C_Out=0; _SC_Out=144;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6528), 24, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Bias */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<257; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==256), D0Ind_NextLast = ((D0Ind+1)==256), D0Ind_NextNextLast = ((D0Ind+2)==256);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In1 = _NN_In1 + (1560); _SNN_In1 = (1560); 
			}
		}
		_SNN_In2 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In2 = _NN_In2 + (1560); _SNN_In2 = (1560); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+_NN_In1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560*((D0Ind_Total)%2)),
					1*(_SNN_In1), 0, UchanHR1);
		}
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read In2 */
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In2) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+_NN_In2), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+3120+1560*((D0Ind_Total)%2)),
					1*(_SNN_In2), 0, UchanHR2);
		}
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+3120+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile1 */
			int T1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
				/*====================== Call Kernel LOC_LOOP =========================*/
				KerArg0->In1 = (float *__restrict__) (main_1_b_L1_Memory+0+1560*((D0Ind_Total)%2));
				KerArg0->In2 = (float *__restrict__) (main_1_b_L1_Memory+3408+1560*((D0Ind_Total)%2));
				KerArg0->Out = (float *__restrict__) (main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2));
				KerArg0->OutFirstCol = (unsigned int) ((0)*6);
				AT_FORK(gap_ncore(), (void *) KerParMatMulTransposed_fp32, (void *) KerArg0);
				__CALL(KerParMatMulTransposed_fp32, KerArg0);
			} /* End iteration on Tile0 */
		} /* End iteration on Tile1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2)),
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
			_C_Out = _C_Out + (144); _SC_Out = (144); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S28__MatMul_3(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out)

{
	/* Shared L1: 6552 bytes, L2 buffer: 0 bytes */
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
			@ 0 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3408 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6528 (Total Size: 24 )[Tile0, 1:[1x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x6], 4]
		Tile0: [0, 24, 24], Tile1: [0, 24, 24], Tile2; [0, 24, 24]
	Ker Arg: Out, Tiled Space: Tile1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3120 (Total Size: 37008 )[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		Tile0: [0, 144, 144], Tile1: [144, 144, 144], Tile2; [288, 144, 144]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W_In1 = (unsigned short int) (65);
	KerArg0->H_In1 = (unsigned short int) (6);
	KerArg0->W_In2 = (unsigned short int) (6);
	KerArg0->Bias = (float *__restrict__) (main_1_b_L1_Memory+6528);
	KerArg0->W_Out = (unsigned short int) (6);
	KerArg0->ColFirst = (unsigned char) (0);
	KerArg0->UB = (float) (6.000000e+00);
	KerArg0->LB = (float) (0.000000e+00);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+0), 1560, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In1 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+1560), 1560, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 1560, 0, DmaR_Evt1);
	_NN_In1=1560; _SN_In1=1560;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+151152+0), 1560, 0, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read In2 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+151152+1560), 1560, 0, UchanHR2);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+151152+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+0), 1560, 0, DmaR_Evt2);
	_NN_In2=1560; _SN_In2=1560;
	_C_Out=0; _SC_Out=144;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6528), 24, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Bias */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<257; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==256), D0Ind_NextLast = ((D0Ind+1)==256), D0Ind_NextNextLast = ((D0Ind+2)==256);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In1 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In1 = _NN_In1 + (1560); _SNN_In1 = (1560); 
			}
		}
		_SNN_In2 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In2 = _NN_In2 + (1560); _SNN_In2 = (1560); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In1 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In1) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In1+_NN_In1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+1560*((D0Ind_Total)%2)),
					1*(_SNN_In1), 0, UchanHR1);
		}
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA read In2 */
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In2) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+_NN_In2), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+151152+1560*((D0Ind_Total)%2)),
					1*(_SNN_In2), 0, UchanHR2);
		}
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+151152+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile1 */
			int T1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
				/*====================== Call Kernel LOC_LOOP =========================*/
				KerArg0->In1 = (float *__restrict__) (main_1_b_L1_Memory+0+1560*((D0Ind_Total)%2));
				KerArg0->In2 = (float *__restrict__) (main_1_b_L1_Memory+3408+1560*((D0Ind_Total)%2));
				KerArg0->Out = (float *__restrict__) (main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2));
				KerArg0->OutFirstCol = (unsigned int) ((0)*6);
				AT_FORK(gap_ncore(), (void *) KerParMatMulTransposed_fp32, (void *) KerArg0);
				__CALL(KerParMatMulTransposed_fp32, KerArg0);
			} /* End iteration on Tile0 */
		} /* End iteration on Tile1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2)),
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
			_C_Out = _C_Out + (144); _SC_Out = (144); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S30_expr_2(
		float * __restrict__ expr_2_in_0,
		float * __restrict__ expr_2_in_1,
		float * __restrict__ expr_2_out_0)

{
	/* Shared L1: 111024 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	G1_2s30_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 9252, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_2_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	Ker Arg: expr_2_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 37008 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	Ker Arg: expr_2_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 74016 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (9252);
	KerArg0->expr_2_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+37008);
	KerArg0->expr_2_in_1 = (float *__restrict__ ) (main_1_b_L1_Memory+74016);
	KerArg0->expr_2_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+37008), 37008, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+74016), 37008, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_2_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) G1_2s30_kernel, (void *) KerArg0);
		__CALL(G1_2s30_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_2_out_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), 37008, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_2_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S32__Concat_trans(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 115136 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 3]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 74016 )[Tile0, 3:[514x14, 1:514x14, 514x8], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[514x14, 1:514x14, 514x8], 4]
		Tile0: [0, 28784, 56], Tile1: [56, 28784, 56], Tile2; [112, 16448, 32]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 57568 (Total Size: 74016 )[Tile0, 3:[514x14, 1:514x14, 514x8], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[514x14, 1:514x14, 514x8], 4]
		Tile0: [0, 28784, 56], Tile1: [56, 28784, 56], Tile2; [112, 16448, 32]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (2);
	KerArg0->H = (unsigned short int) (257);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 28784, 144, 56, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=28784; _LC_Out=56;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<3; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==2), T0Ind_NextLast = ((T0Ind+1)==2);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (56); _LN_In = ((T0Ind_NextLast)?32:56); _SN_In = (514*_LN_In); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+28784*((T0Ind_Total+1)%2)),
					1*(_SN_In), 144, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_1_b_L1_Memory+0+28784*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+57568+28784*((T0Ind_Total)%2));
		KerArg0->W = (unsigned short int) ((T0Ind_Last)?8:14);
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2HCW_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2HCW_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+57568+28784*((T0Ind_Total)%2)),
				_SC_Out, 144, _LC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;_LP_Out = _LC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (56); _LC_Out = ((T0Ind_NextLast)?32:56); _SC_Out = (514*_LC_Out); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S34__MatMul_4(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out)

{
	/* Shared L1: 6552 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatMul_fp32_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T1Ind, T1Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In1;
	unsigned int _SN_In1;
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
			@ 0 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3408 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6528 (Total Size: 24 )[Tile0, 1:[1x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x6], 4]
		Tile0: [0, 24, 24], Tile1: [0, 24, 24], Tile2; [0, 24, 24]
	Ker Arg: Out, Tiled Space: Tile1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3120 (Total Size: 37008 )[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		Tile0: [0, 144, 144], Tile1: [144, 144, 144], Tile2; [288, 144, 144]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W_In1 = (unsigned short int) (65);
	KerArg0->H_In1 = (unsigned short int) (6);
	KerArg0->W_In2 = (unsigned short int) (6);
	KerArg0->Bias = (float *__restrict__) (main_1_b_L1_Memory+6528);
	KerArg0->W_Out = (unsigned short int) (6);
	KerArg0->ColFirst = (unsigned char) (0);
	KerArg0->UB = (float) (6.000000e+00);
	KerArg0->LB = (float) (0.000000e+00);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+0), 1560, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In2 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560), 1560, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+0), 1560, 0, DmaR_Evt1);
	_NN_In2=1560; _SN_In2=1560;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 1560, 0, DmaR_Evt2);
	_N_In1=0;
	_C_Out=0; _SC_Out=144;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6528), 24, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Bias */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<257; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==256), D0Ind_NextLast = ((D0Ind+1)==256), D0Ind_NextNextLast = ((D0Ind+2)==256);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(D0Ind_Last)) {
			_N_In1 = _N_In1 + (1560); _SN_In1 = (1560); 
		}
		_SNN_In2 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In2 = _NN_In2 + (1560); _SNN_In2 = (1560); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt2);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In2 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In2 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In2) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+_NN_In2), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560*((D0Ind_Total)%2)),
					1*(_SNN_In2), 0, UchanHR1);
		}
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile1 */
			int T1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
				/*====================== Call Kernel LOC_LOOP =========================*/
				KerArg0->In1 = (float *__restrict__) (main_1_b_L1_Memory+0+1560*((D0Ind_Total)%2));
				KerArg0->In2 = (float *__restrict__) (main_1_b_L1_Memory+3408+1560*((D0Ind_Total)%2));
				KerArg0->Out = (float *__restrict__) (main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2));
				KerArg0->OutFirstCol = (unsigned int) ((0)*6);
				AT_FORK(gap_ncore(), (void *) KerParMatMulTransposed_fp32, (void *) KerArg0);
				__CALL(KerParMatMulTransposed_fp32, KerArg0);
			} /* End iteration on Tile0 */
		} /* End iteration on Tile1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In2 = _SNN_In2;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(D0Ind_Last)) {
			_C_Out = _C_Out + (144); _SC_Out = (144); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S37__MatMul_5(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out)

{
	/* Shared L1: 6552 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatMul_fp32_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T1Ind, T1Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In1;
	unsigned int _SN_In1;
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
			@ 0 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3408 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6528 (Total Size: 24 )[Tile0, 1:[1x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x6], 4]
		Tile0: [0, 24, 24], Tile1: [0, 24, 24], Tile2; [0, 24, 24]
	Ker Arg: Out, Tiled Space: Tile1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3120 (Total Size: 37008 )[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		Tile0: [0, 144, 144], Tile1: [144, 144, 144], Tile2; [288, 144, 144]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W_In1 = (unsigned short int) (65);
	KerArg0->H_In1 = (unsigned short int) (6);
	KerArg0->W_In2 = (unsigned short int) (6);
	KerArg0->Bias = (float *__restrict__) (main_1_b_L1_Memory+6528);
	KerArg0->W_Out = (unsigned short int) (6);
	KerArg0->ColFirst = (unsigned char) (0);
	KerArg0->UB = (float) (6.000000e+00);
	KerArg0->LB = (float) (0.000000e+00);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+0), 1560, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In2 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+1560), 1560, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+0), 1560, 0, DmaR_Evt1);
	_NN_In2=1560; _SN_In2=1560;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 1560, 0, DmaR_Evt2);
	_N_In1=0;
	_C_Out=0; _SC_Out=144;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6528), 24, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Bias */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<257; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==256), D0Ind_NextLast = ((D0Ind+1)==256), D0Ind_NextNextLast = ((D0Ind+2)==256);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(D0Ind_Last)) {
			_N_In1 = _N_In1 + (1560); _SN_In1 = (1560); 
		}
		_SNN_In2 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In2 = _NN_In2 + (1560); _SNN_In2 = (1560); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt2);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In2 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In2 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In2) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+_NN_In2), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+1560*((D0Ind_Total)%2)),
					1*(_SNN_In2), 0, UchanHR1);
		}
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile1 */
			int T1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
				/*====================== Call Kernel LOC_LOOP =========================*/
				KerArg0->In1 = (float *__restrict__) (main_1_b_L1_Memory+0+1560*((D0Ind_Total)%2));
				KerArg0->In2 = (float *__restrict__) (main_1_b_L1_Memory+3408+1560*((D0Ind_Total)%2));
				KerArg0->Out = (float *__restrict__) (main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2));
				KerArg0->OutFirstCol = (unsigned int) ((0)*6);
				AT_FORK(gap_ncore(), (void *) KerParMatMulTransposed_fp32, (void *) KerArg0);
				__CALL(KerParMatMulTransposed_fp32, KerArg0);
			} /* End iteration on Tile0 */
		} /* End iteration on Tile1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In2 = _SNN_In2;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(D0Ind_Last)) {
			_C_Out = _C_Out + (144); _SC_Out = (144); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S39_expr_3(
		float * __restrict__ expr_3_in_0,
		float * __restrict__ expr_3_in_1,
		float * __restrict__ expr_3_out_0)

{
	/* Shared L1: 111024 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	G1_2s39_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 9252, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_3_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	Ker Arg: expr_3_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 37008 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	Ker Arg: expr_3_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 74016 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (9252);
	KerArg0->expr_3_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+37008);
	KerArg0->expr_3_in_1 = (float *__restrict__ ) (main_1_b_L1_Memory+74016);
	KerArg0->expr_3_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_3_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+37008), 37008, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_3_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+74016), 37008, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_3_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) G1_2s39_kernel, (void *) KerArg0);
		__CALL(G1_2s39_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), 37008, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_3_out_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_3_out_0+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+37008+0), 
37008, 1, UchanHR1);	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_3_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S41__MatMul_6(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out)

{
	/* Shared L1: 6552 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatMul_fp32_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T1Ind, T1Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In1;
	unsigned int _SN_In1;
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
			@ 0 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3408 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6528 (Total Size: 24 )[Tile0, 1:[1x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x6], 4]
		Tile0: [0, 24, 24], Tile1: [0, 24, 24], Tile2; [0, 24, 24]
	Ker Arg: Out, Tiled Space: Tile1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3120 (Total Size: 37008 )[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		Tile0: [0, 144, 144], Tile1: [144, 144, 144], Tile2; [288, 144, 144]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W_In1 = (unsigned short int) (65);
	KerArg0->H_In1 = (unsigned short int) (6);
	KerArg0->W_In2 = (unsigned short int) (6);
	KerArg0->Bias = (float *__restrict__) (main_1_b_L1_Memory+6528);
	KerArg0->W_Out = (unsigned short int) (6);
	KerArg0->ColFirst = (unsigned char) (0);
	KerArg0->UB = (float) (6.000000e+00);
	KerArg0->LB = (float) (0.000000e+00);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+0), 1560, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In2 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560), 1560, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+0), 1560, 0, DmaR_Evt1);
	_NN_In2=1560; _SN_In2=1560;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 1560, 0, DmaR_Evt2);
	_N_In1=0;
	_C_Out=0; _SC_Out=144;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6528), 24, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Bias */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<257; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==256), D0Ind_NextLast = ((D0Ind+1)==256), D0Ind_NextNextLast = ((D0Ind+2)==256);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(D0Ind_Last)) {
			_N_In1 = _N_In1 + (1560); _SN_In1 = (1560); 
		}
		_SNN_In2 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In2 = _NN_In2 + (1560); _SNN_In2 = (1560); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt2);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In2 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In2 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In2) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+_NN_In2), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560*((D0Ind_Total)%2)),
					1*(_SNN_In2), 0, UchanHR1);
		}
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+0+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile1 */
			int T1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
				/*====================== Call Kernel LOC_LOOP =========================*/
				KerArg0->In1 = (float *__restrict__) (main_1_b_L1_Memory+0+1560*((D0Ind_Total)%2));
				KerArg0->In2 = (float *__restrict__) (main_1_b_L1_Memory+3408+1560*((D0Ind_Total)%2));
				KerArg0->Out = (float *__restrict__) (main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2));
				KerArg0->OutFirstCol = (unsigned int) ((0)*6);
				AT_FORK(gap_ncore(), (void *) KerParMatMulTransposed_fp32, (void *) KerArg0);
				__CALL(KerParMatMulTransposed_fp32, KerArg0);
			} /* End iteration on Tile0 */
		} /* End iteration on Tile1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In2 = _SNN_In2;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(D0Ind_Last)) {
			_C_Out = _C_Out + (144); _SC_Out = (144); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S44__MatMul_7(
		float * __restrict__ In2,
		float * __restrict__ In1,
		float * __restrict__ Bias,
		float * __restrict__ Out)

{
	/* Shared L1: 6552 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerMatMul_fp32_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T1Ind, T1Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In1;
	unsigned int _SN_In1;
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
			@ 0 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile1, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3408 (Total Size: 400920 )[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 1560, 1560]][Tile0, 1:[65x6], 4]
		Tile0: [0, 1560, 1560], Tile1: [1560, 1560, 1560], Tile2; [3120, 1560, 1560]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6528 (Total Size: 24 )[Tile0, 1:[1x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x6], 4]
		Tile0: [0, 24, 24], Tile1: [0, 24, 24], Tile2; [0, 24, 24]
	Ker Arg: Out, Tiled Space: Tile1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 257 logical tiles, 257 physical tiles
			@ 3120 (Total Size: 37008 )[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [256 x 144, 144]][Tile1, 1:[6x6], 4]
		Tile0: [0, 144, 144], Tile1: [144, 144, 144], Tile2; [288, 144, 144]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W_In1 = (unsigned short int) (65);
	KerArg0->H_In1 = (unsigned short int) (6);
	KerArg0->W_In2 = (unsigned short int) (6);
	KerArg0->Bias = (float *__restrict__) (main_1_b_L1_Memory+6528);
	KerArg0->W_Out = (unsigned short int) (6);
	KerArg0->ColFirst = (unsigned char) (0);
	KerArg0->UB = (float) (6.000000e+00);
	KerArg0->LB = (float) (0.000000e+00);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+950000+0), 1560, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In2 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+1560), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+950000+1560), 1560, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+950000+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+0), 1560, 0, DmaR_Evt1);
	_NN_In2=1560; _SN_In2=1560;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 1560, 0, DmaR_Evt2);
	_N_In1=0;
	_C_Out=0; _SC_Out=144;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+6528), 24, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Bias */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<257; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==256), D0Ind_NextLast = ((D0Ind+1)==256), D0Ind_NextNextLast = ((D0Ind+2)==256);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(D0Ind_Last)) {
			_N_In1 = _N_In1 + (1560); _SN_In1 = (1560); 
		}
		_SNN_In2 = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In2 = _NN_In2 + (1560); _SNN_In2 = (1560); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt2);
		}
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In2 */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In2 before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In2) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In2+_NN_In2), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+950000+1560*((D0Ind_Total)%2)),
					1*(_SNN_In2), 0, UchanHR1);
		}
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+950000+1560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3408+1560*((D0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile1 */
			int T1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
				/*====================== Call Kernel LOC_LOOP =========================*/
				KerArg0->In1 = (float *__restrict__) (main_1_b_L1_Memory+0+1560*((D0Ind_Total)%2));
				KerArg0->In2 = (float *__restrict__) (main_1_b_L1_Memory+3408+1560*((D0Ind_Total)%2));
				KerArg0->Out = (float *__restrict__) (main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2));
				KerArg0->OutFirstCol = (unsigned int) ((0)*6);
				AT_FORK(gap_ncore(), (void *) KerParMatMulTransposed_fp32, (void *) KerArg0);
				__CALL(KerParMatMulTransposed_fp32, KerArg0);
			} /* End iteration on Tile0 */
		} /* End iteration on Tile1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+3120+144*((D0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SN_In2 = _SNN_In2;
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(D0Ind_Last)) {
			_C_Out = _C_Out + (144); _SC_Out = (144); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S46_expr_4(
		float * __restrict__ expr_4_in_0,
		float * __restrict__ expr_4_in_1,
		float * __restrict__ expr_4_out_0)

{
	/* Shared L1: 111024 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	G1_2s46_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 9252, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_4_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	Ker Arg: expr_4_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 37008 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	Ker Arg: expr_4_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 74016 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (9252);
	KerArg0->expr_4_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+37008);
	KerArg0->expr_4_in_1 = (float *__restrict__ ) (main_1_b_L1_Memory+74016);
	KerArg0->expr_4_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_4_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+37008), 37008, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_4_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+74016), 37008, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_4_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) G1_2s46_kernel, (void *) KerArg0);
		__CALL(G1_2s46_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+74016+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), 37008, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_4_out_0 */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_4_out_0+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+74016+0), 
37008, 1, UchanHR1);	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA write expr_4_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S48_expr_5(
		float * __restrict__ expr_5_in_0,
		float * __restrict__ expr_5_in_1,
		float * __restrict__ expr_5_out_0)

{
	/* Shared L1: 111620 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	G1_2s48_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int D1Ind, D1Ind_Last, D1Ind_NextLast, D1Ind_NextNextLast;
	int D2Ind, D2Ind_Total=0, D2Ind_Last, D2Ind_NextLast, D2Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_5_out_0;
	unsigned int _SP_expr_5_out_0, _SC_expr_5_out_0;
	unsigned int _LP_expr_5_out_0, _LC_expr_5_out_0;
	unsigned int _NN_expr_5_in_1;
	unsigned int _SN_expr_5_in_1, _SNN_expr_5_in_1;
	unsigned int _LN_expr_5_in_1, _LNN_expr_5_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 2][D1 Dim: Init: 257, Tiled: 2][D2 Dim: Init: 36, Tiled: 2][Tile0 Dim: 1]
	Ker Arg: expr_5_out_0, Tiled Space: D2
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 8 logical tiles, 8 physical tiles
			@ 0 (Total Size: 74016 )[D0, [1 x 37008, 37008]][D1, [1 x 36864, 144]][D2, [1 x 27648, 9216]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 37008, 37008]][D1, [1 x 36864, 144]][D2, [1 x 27648, 9216]]
		Tile0: [0, 27648, 108], Tile1: [108, 9216, 36], Tile2; [36864, 108, 108]
	Ker Arg: expr_5_in_1, Tiled Space: D2
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 8 logical tiles, 8 physical tiles
			@ 55296 (Total Size: 74016 )[D0, [1 x 37008, 37008]][D1, [1 x 36864, 144]][D2, [1 x 27648, 9216]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 37008, 37008]][D1, [1 x 36864, 144]][D2, [1 x 27648, 9216]]
		Tile0: [0, 27648, 108], Tile1: [108, 9216, 36], Tile2; [36864, 108, 108]
	Ker Arg: expr_5_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 110592 (Total Size: 1028 )[D1, [1 x 1024, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 1024, 4]]
		Tile0: [0, 1028, 1028], Tile1: [0, 1028, 1028], Tile2; [0, 1028, 1028]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_5_in_1+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+74016+0), 27648, 144, 108, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_5_in_1 */
	AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_5_in_1+108), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+74016+27648), 9216, 144, 36, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+74016+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+55296+0), 27648, 0, DmaR_Evt1);
	_NN_expr_5_in_1=108; _SN_expr_5_in_1=9216;
	_C_expr_5_out_0=0; _SC_expr_5_out_0=27648; _LC_expr_5_out_0=108;
	_SP_expr_5_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_5_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+110592), 1028, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_5_in_0 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<2; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==1), D0Ind_NextLast = ((D0Ind+1)==1), D0Ind_NextNextLast = ((D0Ind+2)==1);
		for (D1Ind=0; D1Ind<2; D1Ind++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1), D1Ind_NextNextLast = ((D1Ind+2)==1);
			for (D2Ind=0; D2Ind<2; D2Ind++, D2Ind_Total++) { /* Iteration on D2 */
				int D2Ind_Last = (D2Ind==1), D2Ind_NextLast = ((D2Ind+1)==1), D2Ind_NextNextLast = ((D2Ind+2)==1);
				/*================================= Prepare Tiles ===================================*/
				_SNN_expr_5_in_1 = 0;
				if (!(D2Ind_Last)) {
					if (!(1)) {
						_NN_expr_5_in_1 = _NN_expr_5_in_1 + (108); _LNN_expr_5_in_1 = ((1)?36:108); _SNN_expr_5_in_1 = (((D1Ind_Last)?1:256)*_LNN_expr_5_in_1); 
					} else if (!(D1Ind_Last)) {
						_NN_expr_5_in_1 = _NN_expr_5_in_1 + (36864)+(-108); _LNN_expr_5_in_1 = (108); _SNN_expr_5_in_1 = (((1)?1:256)*_LNN_expr_5_in_1); 
					} else if (!(D0Ind_Last)) {
						_NN_expr_5_in_1 = _NN_expr_5_in_1 + (37008)+(-36864)+(-108); _LNN_expr_5_in_1 = (108); _SNN_expr_5_in_1 = (256*_LNN_expr_5_in_1); 
					}
				} else if (!(D1Ind_Last)) {
					_NN_expr_5_in_1 = _NN_expr_5_in_1 + (108); _LNN_expr_5_in_1 = (36); _SNN_expr_5_in_1 = (((1)?1:256)*_LNN_expr_5_in_1); 
				} else if (!(D0Ind_Last)) {
					_NN_expr_5_in_1 = _NN_expr_5_in_1 + (108); _LNN_expr_5_in_1 = (36); _SNN_expr_5_in_1 = (((D1Ind_Last)?1:256)*_LNN_expr_5_in_1); 
				}
				/*============================= End Prepare Tiles ===================================*/
				/*================================= Read Tiles ======================================*/
				AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read expr_5_in_1 */
				AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_5_in_1 before starting the next buffer load from L3 which will overwrite this */
				if (_SNN_expr_5_in_1) {
					AT_DEFAULTRAM_CL_COPY2D(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) expr_5_in_1+_NN_expr_5_in_1), ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+74016+27648*((D2Ind_Total)%2)),
							1*(_SNN_expr_5_in_1), 144, _LNN_expr_5_in_1, 0, UchanHR1);
				}
				if (_SN_expr_5_in_1) {
					AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn+74016+27648*((D2Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+55296+27648*((D2Ind_Total+1)%2)),
							1*(_SN_expr_5_in_1), 0, DmaR_Evt1);
				}
				/*============================= End Read Tiles ======================================*/
				{ /* Single iteration on Tile0 */
					int T0Ind_Last = 1;
				} /* End iteration on Tile0 */
				/*====================== Call Kernel LOC_D2 =========================*/
				KerArg0->I1 = (unsigned int) ((D1Ind_Last)?1:256);
				KerArg0->I2 = (unsigned int) ((D2Ind_Last)?9:27);
				KerArg0->expr_5_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+110592+((D1Ind)*1024));
				KerArg0->expr_5_in_1 = (float *__restrict__ ) (main_1_b_L1_Memory+55296+27648*((D2Ind_Total)%2));
				KerArg0->expr_5_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+0+27648*((D2Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) G1_2s48_kernel, (void *) KerArg0);
				__CALL(G1_2s48_kernel, KerArg0);
				/*================================= Write Tiles =====================================*/
				if (_SP_expr_5_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_5_out_0 */
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_5_out_0+_C_expr_5_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+27648*((D2Ind_Total)%2)),
						_SC_expr_5_out_0, 144, _LC_expr_5_out_0, 1, DmaW_Evt1);
				/*============================= End Write Tiles =====================================*/
				/*================================= Update Arg Pipeline =============================*/
				_SP_expr_5_out_0 = _SC_expr_5_out_0;_LP_expr_5_out_0 = _LC_expr_5_out_0;
				_SN_expr_5_in_1 = _SNN_expr_5_in_1;_LN_expr_5_in_1 = _LNN_expr_5_in_1;
				/*============================= End Update Arg Pipeline =============================*/
				/*================================= Prepare Tiles ===================================*/
				_SC_expr_5_out_0 = 0;
				if (!(D2Ind_Last)) {
					_C_expr_5_out_0 = _C_expr_5_out_0 + (108); _LC_expr_5_out_0 = ((1)?36:108); _SC_expr_5_out_0 = (((D1Ind_Last)?1:256)*_LC_expr_5_out_0); 
				} else if (!(D1Ind_Last)) {
					_C_expr_5_out_0 = _C_expr_5_out_0 + (36864)+(-108); _LC_expr_5_out_0 = (108); _SC_expr_5_out_0 = (((1)?1:256)*_LC_expr_5_out_0); 
				} else if (!(D0Ind_Last)) {
					_C_expr_5_out_0 = _C_expr_5_out_0 + (37008)+(-36864)+(-108); _LC_expr_5_out_0 = (108); _SC_expr_5_out_0 = (256*_LC_expr_5_out_0); 
				}
				/*============================= End Prepare Tiles ===================================*/
			} /* End iteration on D2 */
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_5_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S52__Concat_3(
		float * __restrict__ In1,
		float * __restrict__ In2,
		float * __restrict__ Out)

{
	/* Shared L1: 115200 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	CNN_Concat_Width_Arg_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In1;
	unsigned int _SN_In1;
	unsigned int _N_In2;
	unsigned int _SN_In2;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 3]
	Ker Arg: In1, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 37008 )[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		Tile0: [0, 14400, 14400], Tile1: [14400, 14400, 14400], Tile2; [28800, 8208, 8208]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 28800 (Total Size: 37008 )[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		Tile0: [0, 14400, 14400], Tile1: [14400, 14400, 14400], Tile2; [28800, 8208, 8208]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 57600 (Total Size: 74016 )[Tile0, 3:[12x600, 1:12x600, 12x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[12x600, 1:12x600, 12x342], 4]
		Tile0: [0, 28800, 28800], Tile1: [28800, 28800, 28800], Tile2; [57600, 16416, 16416]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W1 = (unsigned short int) (6);
	KerArg0->W2 = (unsigned short int) (6);
	KerArg0->W3 = (unsigned short int) (0);
	KerArg0->W4 = (unsigned short int) (0);
	KerArg0->DataSize = (unsigned char) (4);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28800;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 14400, 0, DmaR_Evt1);
	_N_In1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+28800+0), 14400, 0, DmaR_Evt2);
	_N_In2=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<3; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==2), T0Ind_NextLast = ((T0Ind+1)==2);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(T0Ind_Last)) {
			_N_In1 = _N_In1 + (14400); _SN_In1 = ((T0Ind_NextLast)?8208:14400); 
		}
		_SN_In2 = 0;
		if (!(T0Ind_Last)) {
			_N_In2 = _N_In2 + (14400); _SN_In2 = ((T0Ind_NextLast)?8208:14400); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+14400*((T0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 */
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+_N_In2), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+28800+14400*((T0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+57600+28800*((T0Ind_Total)%2));
		KerArg0->H = (unsigned short int) (T0Ind_Last?342:600);
		KerArg0->In1 = (void *__restrict__) (main_1_b_L1_Memory+0+14400*((T0Ind_Total)%2));
		KerArg0->In2 = (void *__restrict__) (main_1_b_L1_Memory+28800+14400*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_Concat_Width, (void *) KerArg0);
		__CALL(CNN_Concat_Width, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+57600+28800*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (28800); _SC_Out = ((T0Ind_NextLast)?16416:28800); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S53__Concat_4_trans_in1(
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
		Tile0: [0, 24672, 16], Tile1: [16, 24672, 16], Tile2; [32, 24672, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (257);
	KerArg0->W = (unsigned short int) (4);
	KerArg0->H = (unsigned short int) (6);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 24672, 48, 16, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=24672; _LC_Out=16;
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
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+24672*((T0Ind_Total+1)%2)),
					1*(_SN_In), 48, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_1_b_L1_Memory+0+24672*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2HCW_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2HCW_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2)),
				_SC_Out, 48, _LC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;_LP_Out = _LC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (16); _LC_Out = (16); _SC_Out = (1542*_LC_Out); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S54_expr_9(
		float * __restrict__ expr_9_in_0,
		float * __restrict__ expr_9_out_0)

{
	/* Shared L1: 74016 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	G1_2s54_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 9252, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_9_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	Ker Arg: expr_9_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 37008 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (9252);
	KerArg0->expr_9_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+37008);
	KerArg0->expr_9_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_9_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+37008), 37008, 0, DmaR_Evt1);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_9_in_0 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) G1_2s54_kernel, (void *) KerArg0);
		__CALL(G1_2s54_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_9_out_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), 37008, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_9_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S55__Concat_2(
		float * __restrict__ In1,
		float * __restrict__ In2,
		float * __restrict__ Out)

{
	/* Shared L1: 115200 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	CNN_Concat_Width_Arg_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In1;
	unsigned int _SN_In1;
	unsigned int _N_In2;
	unsigned int _SN_In2;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 3]
	Ker Arg: In1, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 37008 )[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		Tile0: [0, 14400, 14400], Tile1: [14400, 14400, 14400], Tile2; [28800, 8208, 8208]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 28800 (Total Size: 37008 )[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		Tile0: [0, 14400, 14400], Tile1: [14400, 14400, 14400], Tile2; [28800, 8208, 8208]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 57600 (Total Size: 74016 )[Tile0, 3:[12x600, 1:12x600, 12x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[12x600, 1:12x600, 12x342], 4]
		Tile0: [0, 28800, 28800], Tile1: [28800, 28800, 28800], Tile2; [57600, 16416, 16416]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W1 = (unsigned short int) (6);
	KerArg0->W2 = (unsigned short int) (6);
	KerArg0->W3 = (unsigned short int) (0);
	KerArg0->W4 = (unsigned short int) (0);
	KerArg0->DataSize = (unsigned char) (4);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28800;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 14400, 0, DmaR_Evt1);
	_N_In1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+28800+0), 14400, 0, DmaR_Evt2);
	_N_In2=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<3; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==2), T0Ind_NextLast = ((T0Ind+1)==2);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(T0Ind_Last)) {
			_N_In1 = _N_In1 + (14400); _SN_In1 = ((T0Ind_NextLast)?8208:14400); 
		}
		_SN_In2 = 0;
		if (!(T0Ind_Last)) {
			_N_In2 = _N_In2 + (14400); _SN_In2 = ((T0Ind_NextLast)?8208:14400); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+14400*((T0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 */
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+_N_In2), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+28800+14400*((T0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+57600+28800*((T0Ind_Total)%2));
		KerArg0->H = (unsigned short int) (T0Ind_Last?342:600);
		KerArg0->In1 = (void *__restrict__) (main_1_b_L1_Memory+0+14400*((T0Ind_Total)%2));
		KerArg0->In2 = (void *__restrict__) (main_1_b_L1_Memory+28800+14400*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_Concat_Width, (void *) KerArg0);
		__CALL(CNN_Concat_Width, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+57600+28800*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (28800); _SC_Out = ((T0Ind_NextLast)?16416:28800); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S56__Concat_4_trans_in0(
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
		Tile0: [0, 24672, 16], Tile1: [16, 24672, 16], Tile2; [32, 24672, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (257);
	KerArg0->W = (unsigned short int) (4);
	KerArg0->H = (unsigned short int) (6);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 24672, 48, 16, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=24672; _LC_Out=16;
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
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+24672*((T0Ind_Total+1)%2)),
					1*(_SN_In), 48, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_1_b_L1_Memory+0+24672*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2HCW_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2HCW_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2)),
				_SC_Out, 48, _LC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;_LP_Out = _LC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (16); _LC_Out = (16); _SC_Out = (1542*_LC_Out); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S58__Concat_4_trans_out0(
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
	KerArg0->Feat = (unsigned short int) (12);
	KerArg0->W = (unsigned short int) (2);
	KerArg0->H = (unsigned short int) (257);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 24672, 48, 8, 0, DmaR_Evt1);
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
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+24672*((T0Ind_Total+1)%2)),
					1*(_SN_In), 48, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_1_b_L1_Memory+0+24672*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2HCW_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2HCW_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2)),
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
void  G1_2S61_expr_6(
		float * __restrict__ expr_6_in_0,
		float * __restrict__ expr_6_in_1,
		float * __restrict__ expr_6_out_0)

{
	/* Shared L1: 115344 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	G1_2s61_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast;
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_6_out_0;
	unsigned int _SP_expr_6_out_0, _SC_expr_6_out_0;
	unsigned int _N_expr_6_in_1;
	unsigned int _SN_expr_6_in_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 514, Tiled: 3][D1 Dim: Init: 36, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_6_out_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 74016 )[D0, [2 x 28800, 16416]][D1, [0 x 28800, 28800]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [2 x 28800, 16416]][D1, [0 x 28800, 28800]]
		Tile0: [0, 28800, 28800], Tile1: [28800, 28800, 28800], Tile2; [57600, 16416, 16416]
	Ker Arg: expr_6_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57600 (Total Size: 144 )[D1, [0 x 144, 144]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 144, 144]]
		Tile0: [0, 144, 144], Tile1: [0, 144, 144], Tile2; [0, 144, 144]
	Ker Arg: expr_6_in_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 57744 (Total Size: 74016 )[D0, [2 x 28800, 16416]][D1, [0 x 28800, 28800]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [2 x 28800, 16416]][D1, [0 x 28800, 28800]]
		Tile0: [0, 28800, 28800], Tile1: [28800, 28800, 28800], Tile2; [57600, 16416, 16416]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I1 = (unsigned int) (36);
	KerArg0->expr_6_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+57600);
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_6_out_0=0; _SC_expr_6_out_0=28800;
	_SP_expr_6_out_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+57744+0), 28800, 0, DmaR_Evt1);
	_N_expr_6_in_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+57600), 144, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_6_in_0 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<3; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==2), D0Ind_NextLast = ((D0Ind+1)==2);
		/*================================= Prepare Tiles ===================================*/
		_SN_expr_6_in_1 = 0;
		if (!(D0Ind_Last)) {
			_N_expr_6_in_1 = _N_expr_6_in_1 + (28800); _SN_expr_6_in_1 = (((D0Ind_NextLast)?114:200)*(144)); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_6_in_1 */
		if (_SN_expr_6_in_1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_in_1+_N_expr_6_in_1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+57744+28800*((D0Ind_Total+1)%2)),
					1*(_SN_expr_6_in_1), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on D1 */
			int D1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I0 = (unsigned int) ((D0Ind_Last)?114:200);
			KerArg0->expr_6_in_1 = (float *__restrict__ ) (main_1_b_L1_Memory+57744+28800*((D0Ind_Total)%2));
			KerArg0->expr_6_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+0+28800*((D0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) G1_2s61_kernel, (void *) KerArg0);
			__CALL(G1_2s61_kernel, KerArg0);
		} /* End iteration on D1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_expr_6_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_6_out_0 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_6_out_0+_C_expr_6_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+28800*((D0Ind_Total)%2)),
				_SC_expr_6_out_0, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_expr_6_out_0 = _SC_expr_6_out_0;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_expr_6_out_0 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_6_out_0 = _C_expr_6_out_0 + (28800); _SC_expr_6_out_0 = (((D0Ind_NextLast)?114:200)*(144)); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_6_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S62__ReduceSum_1(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 76072 bytes, L2 buffer: 0 bytes */
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
		[D0 Dim: Init: 514, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 74016 )[D0, [0 x 74016, 74016]][Tile0, 1:[6x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 74016, 74016]][Tile0, 1:[6x6], 4]
		Tile0: [0, 74016, 74016], Tile1: [0, 74016, 74016], Tile2; [0, 74016, 74016]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 74016 (Total Size: 2056 )[D0, [0 x 2056, 2056]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2056, 2056]]
		Tile0: [0, 2056, 2056], Tile1: [0, 2056, 2056], Tile2; [0, 2056, 2056]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (float * __restrict__) (main_1_b_L1_Memory+0);
	KerArg0->W = (unsigned short int) (6);
	KerArg0->H = (unsigned short int) (6);
	KerArg0->FullHW = (unsigned int) (36);
	KerArg0->OutFeatures = (unsigned short int) (514);
	KerArg0->Out = (float * __restrict__) (main_1_b_L1_Memory+74016);
	KerArg0->LastTile = (unsigned int) ((1));
	KerArg0->TileIndex = (unsigned int) ((0));
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), 74016, 0, DmaR_Evt1);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+74016), 2056, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S65_expr_7(
		float * __restrict__ expr_7_in_0,
		float * __restrict__ expr_7_in_1,
		float * __restrict__ expr_7_in_2,
		float * __restrict__ expr_7_in_3,
		float * __restrict__ expr_7_out_0,
		float * __restrict__ expr_7_out_1)

{
	/* Shared L1: 112936 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaW_Evt2, *DmaW_Evt2 = &_DmaW_Evt2;
	G1_2s65_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast;
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_expr_7_in_2;
	unsigned int _SN_expr_7_in_2;
	unsigned int _C_expr_7_out_0;
	unsigned int _SP_expr_7_out_0, _SC_expr_7_out_0;
	unsigned int _C_expr_7_out_1;
	unsigned int _SP_expr_7_out_1, _SC_expr_7_out_1;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 514, Tiled: 5][D1 Dim: Init: 36, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_7_in_2, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 74016 )[D0, [4 x 18432, 288]][D1, [0 x 18432, 18432]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [4 x 18432, 288]][D1, [0 x 18432, 18432]]
		Tile0: [0, 18432, 18432], Tile1: [18432, 18432, 18432], Tile2; [36864, 18432, 18432]
	Ker Arg: expr_7_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 36864 (Total Size: 144 )[D1, [0 x 144, 144]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 144, 144]]
		Tile0: [0, 144, 144], Tile1: [0, 144, 144], Tile2; [0, 144, 144]
	Ker Arg: expr_7_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 37008 (Total Size: 2056 )[D0, [4 x 512, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [4 x 512, 8]]
		Tile0: [0, 2056, 2056], Tile1: [0, 2056, 2056], Tile2; [0, 2056, 2056]
	Ker Arg: expr_7_out_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 39064 (Total Size: 74016 )[D0, [4 x 18432, 288]][D1, [0 x 18432, 18432]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [4 x 18432, 288]][D1, [0 x 18432, 18432]]
		Tile0: [0, 18432, 18432], Tile1: [18432, 18432, 18432], Tile2; [36864, 18432, 18432]
	Ker Arg: expr_7_out_1, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 75928 (Total Size: 74016 )[D0, [4 x 18432, 288]][D1, [0 x 18432, 18432]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [4 x 18432, 288]][D1, [0 x 18432, 18432]]
		Tile0: [0, 18432, 18432], Tile1: [18432, 18432, 18432], Tile2; [36864, 18432, 18432]
	Ker Arg: expr_7_in_3, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 112792 (Total Size: 144 )[D1, [0 x 144, 144]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 144, 144]]
		Tile0: [0, 144, 144], Tile1: [0, 144, 144], Tile2; [0, 144, 144]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I1 = (unsigned int) (36);
	KerArg0->expr_7_in_1 = (float *__restrict__ ) (main_1_b_L1_Memory+36864);
	KerArg0->expr_7_in_3 = (float *__restrict__ ) (main_1_b_L1_Memory+112792);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_in_2+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 18432, 0, DmaR_Evt1);
	_N_expr_7_in_2=0;
	_C_expr_7_out_0=0; _SC_expr_7_out_0=18432;
	_SP_expr_7_out_0=0;
	_C_expr_7_out_1=0; _SC_expr_7_out_1=18432;
	_SP_expr_7_out_1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+37008), 2056, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+36864), 144, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_in_3+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+112792), 144, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_7_in_3 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<5; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==4), D0Ind_NextLast = ((D0Ind+1)==4);
		/*================================= Prepare Tiles ===================================*/
		_SN_expr_7_in_2 = 0;
		if (!(D0Ind_Last)) {
			_N_expr_7_in_2 = _N_expr_7_in_2 + (18432); _SN_expr_7_in_2 = (((D0Ind_NextLast)?2:128)*(144)); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_7_in_2 */
		if (_SN_expr_7_in_2) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_in_2+_N_expr_7_in_2), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+18432*((D0Ind_Total+1)%2)),
					1*(_SN_expr_7_in_2), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on D1 */
			int D1Ind_Last = 1;
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I0 = (unsigned int) ((D0Ind_Last)?2:128);
			KerArg0->expr_7_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+37008+((D0Ind)*512));
			KerArg0->expr_7_in_2 = (float *__restrict__ ) (main_1_b_L1_Memory+0+18432*((D0Ind_Total)%2));
			KerArg0->expr_7_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+39064+18432*((D0Ind_Total)%2));
			KerArg0->expr_7_out_1 = (float *__restrict__ ) (main_1_b_L1_Memory+75928+18432*((D0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) G1_2s65_kernel, (void *) KerArg0);
			__CALL(G1_2s65_kernel, KerArg0);
		} /* End iteration on D1 */
		/*================================= Write Tiles =====================================*/
		if (_SP_expr_7_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_7_out_0 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_out_0+_C_expr_7_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+39064+18432*((D0Ind_Total)%2)),
				_SC_expr_7_out_0, 1, DmaW_Evt1);
		if (_SP_expr_7_out_1) AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_7_out_1 */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_7_out_1+_C_expr_7_out_1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+75928+18432*((D0Ind_Total)%2)),
				_SC_expr_7_out_1, 1, DmaW_Evt2);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_expr_7_out_0 = _SC_expr_7_out_0;
		_SP_expr_7_out_1 = _SC_expr_7_out_1;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_expr_7_out_0 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_7_out_0 = _C_expr_7_out_0 + (18432); _SC_expr_7_out_0 = (((D0Ind_NextLast)?2:128)*(144)); 
		}
		_SC_expr_7_out_1 = 0;
		if (!(D0Ind_Last)) {
			_C_expr_7_out_1 = _C_expr_7_out_1 + (18432); _SC_expr_7_out_1 = (((D0Ind_NextLast)?2:128)*(144)); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_7_out_0 */
	AT_L2_WAIT(0, DmaW_Evt2); /* Wait previous DMA write expr_7_out_1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S66__ReduceSum_2(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 76072 bytes, L2 buffer: 0 bytes */
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
		[D0 Dim: Init: 514, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 74016 )[D0, [0 x 74016, 74016]][Tile0, 1:[6x6], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 74016, 74016]][Tile0, 1:[6x6], 4]
		Tile0: [0, 74016, 74016], Tile1: [0, 74016, 74016], Tile2; [0, 74016, 74016]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 74016 (Total Size: 2056 )[D0, [0 x 2056, 2056]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2056, 2056]]
		Tile0: [0, 2056, 2056], Tile1: [0, 2056, 2056], Tile2; [0, 2056, 2056]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (float * __restrict__) (main_1_b_L1_Memory+0);
	KerArg0->W = (unsigned short int) (6);
	KerArg0->H = (unsigned short int) (6);
	KerArg0->FullHW = (unsigned int) (36);
	KerArg0->OutFeatures = (unsigned short int) (514);
	KerArg0->Out = (float * __restrict__) (main_1_b_L1_Memory+74016);
	KerArg0->LastTile = (unsigned int) ((1));
	KerArg0->TileIndex = (unsigned int) ((0));
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), 74016, 0, DmaR_Evt1);
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
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+74016), 2056, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S67__Gather_6(
		float * __restrict__ In,
		float * __restrict__ Out1)

{
	/* Shared L1: 3084 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	SplitWidthIn2Arg_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 2056 )[Tile0, 1:[2x257], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[2x257], 4]
		Tile0: [0, 2056, 2056], Tile1: [0, 2056, 2056], Tile2; [0, 2056, 2056]
	Ker Arg: Out1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2056 (Total Size: 1028 )[Tile0, 1:[1x257], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x257], 4]
		Tile0: [0, 1028, 1028], Tile1: [0, 1028, 1028], Tile2; [0, 1028, 1028]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (void * __restrict__) (main_1_b_L1_Memory+0);
	KerArg0->H = (unsigned short int) (257);
	KerArg0->Out1 = (void * __restrict__) (main_1_b_L1_Memory+2056);
	KerArg0->S1 = (unsigned short int) (0);
	KerArg0->W1 = (unsigned short int) (1);
	KerArg0->S2 = (unsigned short int) (1);
	KerArg0->W2 = (unsigned short int) (1);
	KerArg0->InWidth = (unsigned short int) (2);
	KerArg0->DataSize = (unsigned char) (4);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), 2056, 0, DmaR_Evt1);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		AT_FORK(gap_ncore(), (void *) CNN_ParSplit_Width_In2_Unused_1, (void *) KerArg0);
		__CALL(CNN_ParSplit_Width_In2_Unused_1, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+2056), 1028, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out1 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S68_expr_8(
		float * __restrict__ expr_8_in_0,
		float * __restrict__ expr_8_in_1,
		float * __restrict__ expr_8_out_0)

{
	/* Shared L1: 111620 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	G1_2s68_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast;
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_expr_8_out_0;
	unsigned int _SP_expr_8_out_0, _SC_expr_8_out_0;
	unsigned int _LP_expr_8_out_0, _LC_expr_8_out_0;
	unsigned int _N_expr_8_in_0;
	unsigned int _SN_expr_8_in_0;
	unsigned int _LN_expr_8_in_0;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 257, Tiled: 2][D1 Dim: Init: 72, Tiled: 3][Tile0 Dim: 1]
	Ker Arg: expr_8_out_0, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 0 (Total Size: 74016 )[D0, [1 x 73728, 288]][D1, [2 x 27648, 18432]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 73728, 288]][D1, [2 x 27648, 18432]]
		Tile0: [0, 27648, 108], Tile1: [108, 27648, 108], Tile2; [216, 18432, 72]
	Ker Arg: expr_8_in_0, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 55296 (Total Size: 74016 )[D0, [1 x 73728, 288]][D1, [2 x 27648, 18432]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 73728, 288]][D1, [2 x 27648, 18432]]
		Tile0: [0, 27648, 108], Tile1: [108, 27648, 108], Tile2; [216, 18432, 72]
	Ker Arg: expr_8_in_1, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			@ 110592 (Total Size: 1028 )[D0, [1 x 1024, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [1 x 1024, 4]]
		Tile0: [0, 1028, 1028], Tile1: [0, 1028, 1028], Tile2; [0, 1028, 1028]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	_C_expr_8_out_0=0; _SC_expr_8_out_0=27648; _LC_expr_8_out_0=108;
	_SP_expr_8_out_0=0;
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_8_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+55296+0), 27648, 288, 108, 0, DmaR_Evt1);
	_N_expr_8_in_0=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_8_in_1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+110592), 1028, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read expr_8_in_1 */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<2; D0Ind++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==1), D0Ind_NextLast = ((D0Ind+1)==1);
		for (D1Ind=0; D1Ind<3; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
			int D1Ind_Last = (D1Ind==2), D1Ind_NextLast = ((D1Ind+1)==2);
			/*================================= Prepare Tiles ===================================*/
			_SN_expr_8_in_0 = 0;
			if (!(D1Ind_Last)) {
				_N_expr_8_in_0 = _N_expr_8_in_0 + (108); _LN_expr_8_in_0 = ((D1Ind_NextLast)?72:108); _SN_expr_8_in_0 = (((D0Ind_Last)?1:256)*_LN_expr_8_in_0); 
			} else if (!(D0Ind_Last)) {
				_N_expr_8_in_0 = _N_expr_8_in_0 + (73728)+(-216); _LN_expr_8_in_0 = (108); _SN_expr_8_in_0 = (((1)?1:256)*_LN_expr_8_in_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_8_in_0 */
			if (_SN_expr_8_in_0) {
				AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_8_in_0+_N_expr_8_in_0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+55296+27648*((D1Ind_Total+1)%2)),
						1*(_SN_expr_8_in_0), 288, _LN_expr_8_in_0, 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on Tile0 */
				int T0Ind_Last = 1;
			} /* End iteration on Tile0 */
			/*====================== Call Kernel LOC_D1 =========================*/
			KerArg0->I0 = (unsigned int) ((D0Ind_Last)?1:256);
			KerArg0->I1 = (unsigned int) ((D1Ind_Last)?18:27);
			KerArg0->expr_8_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+55296+27648*((D1Ind_Total)%2));
			KerArg0->expr_8_in_1 = (float *__restrict__ ) (main_1_b_L1_Memory+110592+((D0Ind)*1024));
			KerArg0->expr_8_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+0+27648*((D1Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) G1_2s68_kernel, (void *) KerArg0);
			__CALL(G1_2s68_kernel, KerArg0);
			/*================================= Write Tiles =====================================*/
			if (_SP_expr_8_out_0) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_8_out_0 */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) expr_8_out_0+_C_expr_8_out_0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+27648*((D1Ind_Total)%2)),
					_SC_expr_8_out_0, 288, _LC_expr_8_out_0, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_expr_8_out_0 = _SC_expr_8_out_0;_LP_expr_8_out_0 = _LC_expr_8_out_0;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_expr_8_out_0 = 0;
			if (!(D1Ind_Last)) {
				_C_expr_8_out_0 = _C_expr_8_out_0 + (108); _LC_expr_8_out_0 = ((D1Ind_NextLast)?72:108); _SC_expr_8_out_0 = (((D0Ind_Last)?1:256)*_LC_expr_8_out_0); 
			} else if (!(D0Ind_Last)) {
				_C_expr_8_out_0 = _C_expr_8_out_0 + (73728)+(-216); _LC_expr_8_out_0 = (108); _SC_expr_8_out_0 = (((1)?1:256)*_LC_expr_8_out_0); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on D1 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write expr_8_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S69__Gather_9_split_trans(
		float * __restrict__ In,
		float * __restrict__ Out)

{
	/* Shared L1: 115136 bytes, L2 buffer: 0 bytes */
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
		[Tile0 Dim: 3]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 74016 )[Tile0, 3:[514x14, 1:514x14, 514x8], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[514x14, 1:514x14, 514x8], 4]
		Tile0: [0, 28784, 56], Tile1: [56, 28784, 56], Tile2; [112, 16448, 32]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 57568 (Total Size: 74016 )[Tile0, 3:[514x14, 1:514x14, 514x8], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[514x14, 1:514x14, 514x8], 4]
		Tile0: [0, 28784, 56], Tile1: [56, 28784, 56], Tile2; [112, 16448, 32]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (257);
	KerArg0->H = (unsigned short int) (2);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 28784, 144, 56, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=28784; _LC_Out=56;
	_SP_Out=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<3; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==2), T0Ind_NextLast = ((T0Ind+1)==2);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (56); _LN_In = ((T0Ind_NextLast)?32:56); _SN_In = (514*_LN_In); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+28784*((T0Ind_Total+1)%2)),
					1*(_SN_In), 144, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_1_b_L1_Memory+0+28784*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+57568+28784*((T0Ind_Total)%2));
		KerArg0->W = (unsigned short int) ((T0Ind_Last)?8:14);
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2HCW_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2HCW_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+57568+28784*((T0Ind_Total)%2)),
				_SC_Out, 144, _LC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;_LP_Out = _LC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (56); _LC_Out = ((T0Ind_NextLast)?32:56); _SC_Out = (514*_LC_Out); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S73__Concat_6(
		float * __restrict__ In1,
		float * __restrict__ In2,
		float * __restrict__ Out)

{
	/* Shared L1: 115200 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	CNN_Concat_Width_Arg_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In1;
	unsigned int _SN_In1;
	unsigned int _N_In2;
	unsigned int _SN_In2;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 3]
	Ker Arg: In1, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 37008 )[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		Tile0: [0, 14400, 14400], Tile1: [14400, 14400, 14400], Tile2; [28800, 8208, 8208]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 28800 (Total Size: 37008 )[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		Tile0: [0, 14400, 14400], Tile1: [14400, 14400, 14400], Tile2; [28800, 8208, 8208]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 57600 (Total Size: 74016 )[Tile0, 3:[12x600, 1:12x600, 12x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[12x600, 1:12x600, 12x342], 4]
		Tile0: [0, 28800, 28800], Tile1: [28800, 28800, 28800], Tile2; [57600, 16416, 16416]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W1 = (unsigned short int) (6);
	KerArg0->W2 = (unsigned short int) (6);
	KerArg0->W3 = (unsigned short int) (0);
	KerArg0->W4 = (unsigned short int) (0);
	KerArg0->DataSize = (unsigned char) (4);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28800;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 14400, 0, DmaR_Evt1);
	_N_In1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+28800+0), 14400, 0, DmaR_Evt2);
	_N_In2=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<3; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==2), T0Ind_NextLast = ((T0Ind+1)==2);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(T0Ind_Last)) {
			_N_In1 = _N_In1 + (14400); _SN_In1 = ((T0Ind_NextLast)?8208:14400); 
		}
		_SN_In2 = 0;
		if (!(T0Ind_Last)) {
			_N_In2 = _N_In2 + (14400); _SN_In2 = ((T0Ind_NextLast)?8208:14400); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+14400*((T0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 */
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+_N_In2), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+28800+14400*((T0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+57600+28800*((T0Ind_Total)%2));
		KerArg0->H = (unsigned short int) (T0Ind_Last?342:600);
		KerArg0->In1 = (void *__restrict__) (main_1_b_L1_Memory+0+14400*((T0Ind_Total)%2));
		KerArg0->In2 = (void *__restrict__) (main_1_b_L1_Memory+28800+14400*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_Concat_Width, (void *) KerArg0);
		__CALL(CNN_Concat_Width, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+57600+28800*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (28800); _SC_Out = ((T0Ind_NextLast)?16416:28800); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S74__Concat_7_trans_in1(
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
		Tile0: [0, 24672, 16], Tile1: [16, 24672, 16], Tile2; [32, 24672, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (257);
	KerArg0->W = (unsigned short int) (4);
	KerArg0->H = (unsigned short int) (6);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 24672, 48, 16, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=24672; _LC_Out=16;
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
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+24672*((T0Ind_Total+1)%2)),
					1*(_SN_In), 48, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_1_b_L1_Memory+0+24672*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2HCW_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2HCW_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2)),
				_SC_Out, 48, _LC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;_LP_Out = _LC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (16); _LC_Out = (16); _SC_Out = (1542*_LC_Out); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S75_expr_10(
		float * __restrict__ expr_10_in_0,
		float * __restrict__ expr_10_out_0)

{
	/* Shared L1: 74016 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	G1_2s75_kernel_args_t S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 9252, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: expr_10_out_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	Ker Arg: expr_10_in_0, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 37008 (Total Size: 37008 )[D0, [0 x 37008, 37008]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 37008, 37008]]
		Tile0: [0, 37008, 37008], Tile1: [0, 37008, 37008], Tile2; [0, 37008, 37008]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->I0 = (unsigned int) (9252);
	KerArg0->expr_10_in_0 = (float *__restrict__ ) (main_1_b_L1_Memory+37008);
	KerArg0->expr_10_out_0 = (float *__restrict__ ) (main_1_b_L1_Memory+0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_10_in_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+37008), 37008, 0, DmaR_Evt1);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read expr_10_in_0 */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_D0 =========================*/
		AT_FORK(gap_ncore(), (void *) G1_2s75_kernel, (void *) KerArg0);
		__CALL(G1_2s75_kernel, KerArg0);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) expr_10_out_0+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), 37008, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write expr_10_out_0 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S76__Concat_5(
		float * __restrict__ In1,
		float * __restrict__ In2,
		float * __restrict__ Out)

{
	/* Shared L1: 115200 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	CNN_Concat_Width_Arg_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In1;
	unsigned int _SN_In1;
	unsigned int _N_In2;
	unsigned int _SN_In2;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 3]
	Ker Arg: In1, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 37008 )[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		Tile0: [0, 14400, 14400], Tile1: [14400, 14400, 14400], Tile2; [28800, 8208, 8208]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 28800 (Total Size: 37008 )[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[6x600, 1:6x600, 6x342], 4]
		Tile0: [0, 14400, 14400], Tile1: [14400, 14400, 14400], Tile2; [28800, 8208, 8208]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 57600 (Total Size: 74016 )[Tile0, 3:[12x600, 1:12x600, 12x342], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[12x600, 1:12x600, 12x342], 4]
		Tile0: [0, 28800, 28800], Tile1: [28800, 28800, 28800], Tile2; [57600, 16416, 16416]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W1 = (unsigned short int) (6);
	KerArg0->W2 = (unsigned short int) (6);
	KerArg0->W3 = (unsigned short int) (0);
	KerArg0->W4 = (unsigned short int) (0);
	KerArg0->DataSize = (unsigned char) (4);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28800;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 14400, 0, DmaR_Evt1);
	_N_In1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+28800+0), 14400, 0, DmaR_Evt2);
	_N_In2=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<3; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==2), T0Ind_NextLast = ((T0Ind+1)==2);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(T0Ind_Last)) {
			_N_In1 = _N_In1 + (14400); _SN_In1 = ((T0Ind_NextLast)?8208:14400); 
		}
		_SN_In2 = 0;
		if (!(T0Ind_Last)) {
			_N_In2 = _N_In2 + (14400); _SN_In2 = ((T0Ind_NextLast)?8208:14400); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+14400*((T0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 */
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+_N_In2), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+28800+14400*((T0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+57600+28800*((T0Ind_Total)%2));
		KerArg0->H = (unsigned short int) (T0Ind_Last?342:600);
		KerArg0->In1 = (void *__restrict__) (main_1_b_L1_Memory+0+14400*((T0Ind_Total)%2));
		KerArg0->In2 = (void *__restrict__) (main_1_b_L1_Memory+28800+14400*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_Concat_Width, (void *) KerArg0);
		__CALL(CNN_Concat_Width, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+57600+28800*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (28800); _SC_Out = ((T0Ind_NextLast)?16416:28800); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S77__Concat_7_trans_in0(
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
		Tile0: [0, 24672, 16], Tile1: [16, 24672, 16], Tile2; [32, 24672, 16]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Feat = (unsigned short int) (257);
	KerArg0->W = (unsigned short int) (4);
	KerArg0->H = (unsigned short int) (6);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 24672, 48, 16, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=24672; _LC_Out=16;
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
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+24672*((T0Ind_Total+1)%2)),
					1*(_SN_In), 48, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_1_b_L1_Memory+0+24672*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2HCW_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2HCW_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2)),
				_SC_Out, 48, _LC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;_LP_Out = _LC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (16); _LC_Out = (16); _SC_Out = (1542*_LC_Out); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  G1_2S79__Concat_7_trans_out0(
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
	KerArg0->Feat = (unsigned short int) (12);
	KerArg0->W = (unsigned short int) (2);
	KerArg0->H = (unsigned short int) (257);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+0), 24672, 48, 8, 0, DmaR_Evt1);
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
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0+24672*((T0Ind_Total+1)%2)),
					1*(_SN_In), 48, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (void *__restrict__) (main_1_b_L1_Memory+0+24672*((T0Ind_Total)%2));
		KerArg0->Out = (void *__restrict__) (main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2));
		AT_FORK(gap_ncore(), (void *) CNN_MatPermCHW2HCW_fp32, (void *) KerArg0);
		__CALL(CNN_MatPermCHW2HCW_fp32, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+49344+24672*((T0Ind_Total)%2)),
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
#pragma GCC diagnostic pop
int  main_1_bCNN_Construct()

{
	int Error;

	// AT_DEFAULTRAM_CONF_T DefaultRamConf;
	// AT_DEFAULTRAM_CONF_INIT(&DefaultRamConf, AT_MEM_L3_DEFAULTRAM, 0);
	// AT_DEFAULTRAM_OPEN(&DefaultRam, &DefaultRamConf, &Error);
	// if (Error) return AT_RAM_OPEN_ERROR;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "main_1_b_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;

	main_1_b_L3_Memory_Dyn = (AT_DEFAULTRAM_POINTER) main_1_L3_Memory_Dyn;
	if (main_1_b_L3_Memory_Dyn == 0) return AT_RAM_OPEN_ERROR;
	main_1_b_L2_Memory_Dyn = main_1_L2_Memory_Dyn;
	if (main_1_b_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	main_1_b_L1_Memory = (AT_L1_POINTER) main_1_L1_Memory;
	if (main_1_b_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	G1_2Input_1 = (float * __restrict__) (main_1_b_L2_Memory_Dyn + 0);
	G1_2Input_2 = (float * __restrict__) (main_1_b_L2_Memory_Dyn + 66820);

	for (int i = 0;  i<66820;++i)
		G1_2Input_2[i] = Output_1[i];

	G1_2Input_3 = (float * __restrict__) (main_1_b_L3_Memory_Dyn + 0);
	G1_2Output_1 = (float * __restrict__) (main_1_b_L2_Memory_Dyn + 333072);
	G1_2Output_2 = (float * __restrict__) (main_1_b_L2_Memory_Dyn + 0);
	return AT_NO_ERROR;
}
void main_1_bCNN_ConstructCluster()

{
}
int  main_1_bCNN_Destruct()

{
	AT_DEFAULTRAM_FREE(&DefaultRam, main_1_b_L3_Memory_Dyn, 1677696);
	AT_L2_FREE(0, main_1_b_L2_Memory_Dyn, 942676);
	AT_L1_FREE(0, main_1_b_L1_Memory, 115344);
	AT_DEFAULTRAM_CLOSE(&DefaultRam);
	AT_DEFAULTFLASH_FS_CLOSE(&DefaultFlash);
	G1_2Input_1 = 0;
	G1_2Input_2 = 0;
	G1_2Input_3 = 0;
	G1_2Output_1 = 0;
	G1_2Output_2 = 0;
	return 0;
}
int main_1_bCNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 115344; /* L1 Memory */
		case AT_L2_MEM:     return 0; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 942676; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 1677696; /* L3 Memory, dynamic */
		default:            return 0;
	}
}

int plp_mat_inv_f32s_xpulpv2(float *__restrict__ pSrc, float *__restrict__ pDst, uint32_t N)
{
    float *pSrcT1, *pSrcT2;                    /* Temporary input data matrix pointer */
    float *pDstT1, *pDstT2;                    /* Temporary output data matrix pointer */
    float *pPivotRowIn;                        /* Pivot row in input */
    float *pPivotRowDst;                       /* Pivot row in destination */
    float *pPRT_in, *pPRT_pDst;                /* Walkers over pivot rows */

    float Xchg, in = 0.0f, in1;                /* Temporary values  */
    uint32_t i, j, k, l;                       /* Loop indices */
    uint32_t loopCnt;                          /* Remaining pivot steps */
    uint32_t M = N;                            /* Square matrices */
    uint32_t flag = 0U;                        /* Row-exchange flag in the current pivot step */

    /* ----------------------------------------------------------------
     * Initialize destination to identity (faster than memset+diag set)
     * ---------------------------------------------------------------- */
    pDstT1 = pDst;
    for (i = 0; i < M; ++i) {
        /* zeros before diagonal */
        for (j = 0; j < i; ++j) {
            *pDstT1++ = 0.0f;
        }
        /* one on diagonal */
        *pDstT1++ = 1.0f;
        /* zeros after diagonal */
        for (j = i + 1; j < M; ++j) {
            *pDstT1++ = 0.0f;
        }
    }

    /* ----------------------------------------------------------------
     * Gauss–Jordan elimination with simple partial pivoting (non-zero)
     * ---------------------------------------------------------------- */
    loopCnt = N;
    l = 0U;

    for (; loopCnt > 0U; --loopCnt, ++l) {

        /* Working pointers to the l-th row (start of row) */
        pSrcT1 = pSrc + (l * N);
        pDstT1 = pDst + (l * N);

        /* Pivot value at (l,l) */
        in = pSrcT1[l];
        flag = 0U;

        /* If pivot is zero, search a row below with non-zero in column l and swap */
        if (in == 0.0f) {
            for (i = l + 1U; i < M; ++i) {
                pSrcT2 = pSrc + (i * N);              /* row i */
                pDstT2 = pDst + (i * N);              /* row i (dst) */

                if (pSrcT2[l] != 0.0f) {
                    /* Swap INPUT: columns l..N-1 of rows l and i */
                    for (j = l; j < N; ++j) {
                        Xchg = pSrcT2[j];
                        pSrcT2[j] = pSrcT1[j];
                        pSrcT1[j] = Xchg;
                    }
                    /* Swap DEST: full N columns of rows l and i */
                    for (j = 0; j < N; ++j) {
                        Xchg = pDstT2[j];
                        pDstT2[j] = pDstT1[j];
                        pDstT1[j] = Xchg;
                    }

                    flag = 1U;
                    break; /* done swapping */
                }
            }
            /* Reload pivot after potential swap */
            in = pSrcT1[l];
        }

        /* If still zero, singular */
        if ((flag != 1U) && (in == 0.0f)) {
            return 1;
        }

        /* Pivot rows (base addresses) */
        pPivotRowIn  = pSrc + (l * N);
        pPivotRowDst = pDst + (l * N);

        /* Normalize pivot row: Input (cols l..N-1) and Dest (all N) */
        {
            float inv_pivot = in;
            /* divide input row segment */
            for (j = l; j < N; ++j) {
                pPivotRowIn[j] = pPivotRowIn[j] / inv_pivot;
            }
            /* divide destination full row */
            for (j = 0; j < N; ++j) {
                pPivotRowDst[j] = pPivotRowDst[j] / inv_pivot;
            }
        }

        /* Eliminate column l in all other rows */
        for (i = 0U; i < M; ++i) {
            if (i == l) continue;

            float *rowIn  = pSrc + (i * N);
            float *rowDst = pDst + (i * N);
            float alpha   = rowIn[l];

            /* rowIn[l..N-1] -= alpha * pivotIn[l..N-1] */
            for (j = l; j < N; ++j) {
                rowIn[j] -= alpha * pPivotRowIn[j];
            }
            /* rowDst[:] -= alpha * pivotDst[:] */
            for (j = 0; j < N; ++j) {
                rowDst[j] -= alpha * pPivotRowDst[j];
            }
        }
    }

    /* Final singularity safeguard: if all zeros remain (degenerate case) */
    if ((flag != 1U) && (in == 0.0f)) {
        for (i = 0; i < M * N; ++i) {
            if (pSrc[i] != 0.0f) break;
        }
        if (i == M * N) return 1;
    }

    return 0;
}
typedef struct inverse_args {
	float* _In;
	float* _Out;
	uint32_t num_matrices;
	uint32_t size;
}inverse_args_t ;



int plp_mat_inv_f32p_xpulpv2(float *__restrict__ pSrc ,float *__restrict__ pDst,uint32_t N ) {

    int core_id = 0;
    uint32_t *flag = 0U;
    uint32_t nPE = 1;
    float *pSrcT1, *pSrcT2;                         /* Temporary input data matrix pointer */
    float *pDstT1, *pDstT2;                         /* Temporary output data matrix pointer */
    float *pPivotRowIn;                             /* Temporary input and output data matrix pointer */
    float *pPRT_in, *pPivotRowDst, *pPRT_pDst;      /* Temporary input and output data matrix pointer */
    float Xchg, in = 0.0f, in1;                     /* Temporary input values  */
    uint32_t i, rowCnt, j, loopCnt, k, l;   /* loop counters */
    uint32_t M = N;                         /* M is the number of rows. However, the matirces must be square. */
    pDstT1 = pDst;                          /* Working pointer for destination matrix */

    
    /* CREATE IDENTITY MATRIX */

    for (uint32_t i = core_id; i < M; i += nPE) {
        for (uint32_t j = 0; j < M; j++) {
            pDstT1[i * M + j] = (float)(i == j);
        }
    }

    /* Loop over the number of columns of the input matrix.
       All the elements in each column are processed by the row operations */
    loopCnt = N;
    l = 0U; // Column index
    while (loopCnt > 0U) {

        /* SEARCH FOR 0 AND SWITCH ROWS */

        pSrcT1 = pSrc + (l * N); // Input pivot
        pDstT1 = pDst + (l * N); // Destination pivot

        in = *pSrcT1;
        k = 1U;
        /* Check if the pivot element is zero */
        if (*pSrcT1 == 0.0f) {
            /* Loop over the number rows present below */
            for (i = (l + 1U) + core_id; i < M; i += nPE) {
                pSrcT2 = pSrcT1 + (N * i);
                /* Check if there is element to exchange */
                if (*pSrcT2 != 0.0f)
                    *flag = k;
                if (*flag != 0) {
                    pSrcT2 = pSrcT1 + (N * *flag + l);
                    pDstT2 = pDstT1 + (N * *flag);
                    /* Loop over number of columns
                     * to the right of the pilot element */
                    for (j = core_id; j < N - l; j += nPE) {
                        /* Exchange the row elements of the input matrix */
                        Xchg = pSrcT2[j];
                        pSrcT2[j] = pSrcT1[j];
                        pSrcT1[j] = Xchg;
                    }
                    pSrcT1 += N - l;
                    pSrcT2 += N - l;
                    /* Loop over number of columns of the destination matrix */
                    for(j = core_id; j < N; j += nPE) {
                        /* Exchange the row elements of the destination matrix */
                        Xchg = pDstT2[j];
                        pDstT2[j] = pDstT1[j];
                        pDstT1[j] = Xchg;
                    }
                    pDstT2 += N;
                    pDstT1 += N;
                    break;
                }
            }
            k++;
        }

        /* Update the status if the matrix is singular */
        if ((*flag == 0U) && (in == 0.0f)) {
            return 1;
        }

        /* DIVIDE BY PIVOT */

        /* Points to the pivot row of input and destination matrices */
        pPivotRowIn = pSrc + (l * N);
        pPivotRowDst = pDst + (l * N);
        /* Temporary pointers to the pivot row pointers */
        pSrcT1 = pPivotRowIn;
        pSrcT2 = pPivotRowDst;
        /* Pivot element of the row */
        in = *pPivotRowIn;
        /* Loop over number of columns to the right of the pilot element */
        for(j = core_id; j < N - l; j += nPE) {
            in1 = pSrcT1[j];
            pSrcT1[j] = in1 / in;
        }
        /* Loop over number of columns of the destination matrix */
        for(j = core_id; j < N; j += nPE) {
            in1 = pSrcT2[j];
            pSrcT2[j] = in1 / in;
        }

        /*REPLACE ROWS */

        pSrcT1 = pSrc + core_id * N;
        pSrcT2 = pDst + core_id * N;
        i = core_id;
        k = M;
        for(k = core_id; k < M; k += nPE) {
            if (i != l) {
                /* Element of the reference row */
                in = *pSrcT1;
                /* Working pointers for input and destination pivot rows */
                pPRT_in = pPivotRowIn;
                pPRT_pDst = pPivotRowDst;
                /* Loop over the number of columns to the right of the pivot element,
                   to replace the elements in the input matrix */
                for (j = 0; j < N - l; j++) {
                    in1 = pSrcT1[j];
                    pSrcT1[j] = in1 - (in * pPRT_in[j]);
                }
                /* Loop over the number of columns to
                   replace the elements in the destination matrix */
                for (j = 0; j < N; j++) {
                    in1 = pSrcT2[j];
                    pSrcT2[j] = in1 - (in * pPRT_pDst[j]);
                }
            }
            i += nPE;
            pSrcT1 += nPE * N;
            pSrcT2 += nPE * N;
        }
        /* Increment the input pointer */
        pSrc++;
        /* Decrement the loop counter */
        loopCnt--;
        /* Increment the index modifier */
        l++;
    }
    
    if ((*flag == 0) && (in == 0.0f)) {
        for (i = 0; i < M * N; i++) {
            if (pSrc[i] != 0.0f)
                break;
        }
        if (i == M * N)
            return 1;
    }
    return 0;
}


void dispatch_inverse (void* ker_args_v){

	inverse_args_t* ker_args = (inverse_args_t*)ker_args_v;
	float* _In = (*ker_args)._In;
	float* _Out = (*ker_args)._Out;
	uint32_t num_matrices = (*ker_args).num_matrices;
	uint32_t size = (*ker_args).size;

	for (uint32_t i =  pi_core_id(); i < num_matrices; i += 8){

		plp_mat_inv_f32p_xpulpv2(_In+i*size*size,_Out+i*size*size,size);
		// printf("esegui la numero %d \n",i);
	}

}


void inverse(float* _In,float* _Out,uint32_t num_matrices,uint32_t size){

	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;

	for (uint32_t i=0;i<num_matrices;)
	{	
	uint32_t matrix_to_move = (i+64)>=num_matrices?num_matrices-i:64;
	uint32_t movement = matrix_to_move*4*12*12;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) _In+i*144*4), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+0), movement, 0, DmaR_Evt1);
	AT_L2_WAIT(0,DmaR_Evt1);
	inverse_args_t inverse_args[1] = {{._In = (float*)(main_1_b_L1_Memory + 0), ._Out = (float*)(main_1_b_L1_Memory + movement), .num_matrices = matrix_to_move, .size = size}};
	pi_cl_team_fork(gap_ncore(),(void (*)(void *))dispatch_inverse, (void *) inverse_args);
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) _Out+i*144*4), ((AT_L2_INT_ADDR_TYPE) main_1_b_L1_Memory+movement), movement, 1, DmaW_Evt1);
	AT_L2_WAIT(0,DmaW_Evt1);

	i+=matrix_to_move;



}
	// __CALL(dispatch_inverse, inverse_args);
}


unsigned int G1_2_AT_GraphPerf[36];
unsigned int G1_2_AT_GraphPerf_CNN_Total = 0;
unsigned int G1_2_AT_GraphOperInfosNames[36] = {
	16705,
	801840,
	601380,
	601380,
	9252,
	601380,
	601380,
	9252,
	37008,
	9252,
	18504,
	18504,
	18504,
	18504,
	37008,
	601380,
	601380,
	9252,
	601380,
	601380,
	9252,
	18504,
	18504,
	18504,
	222048,
	18504,
	514,
	18504,
	18504,
	9252,
	18504,
	18504,
	18504,
	18504,
	37008,
	0,
};
char *G1_2_AT_GraphNodeNames[36] = {
	"G1_2S2__ReduceSum",
	"G1_2S10_expr_0",
	"G1_2S34__MatMul_4",
	"G1_2S37__MatMul_5",
	"G1_2S39_expr_3",
	"G1_2S41__MatMul_6",
	"G1_2S44__MatMul_7",
	"G1_2S46_expr_4",
	"G1_2S48_expr_5",
	"G1_2S54_expr_9",
	"G1_2S52__Concat_3",
	"G1_2S53__Concat_4_trans_in1",
	"G1_2S55__Concat_2",
	"G1_2S56__Concat_4_trans_in0",
	"G1_2S58__Concat_4_trans_out0",
	"G1_2S18__MatMul",
	"G1_2S21__MatMul_1",
	"G1_2S23_expr_1",
	"G1_2S25__MatMul_2",
	"G1_2S28__MatMul_3",
	"G1_2S30_expr_2",
	"G1_2S32__Concat_trans",
	"G1_2S61_expr_6",
	"G1_2S62__ReduceSum_1",
	"G1_2S65_expr_7",
	"G1_2S66__ReduceSum_2",
	"G1_2S67__Gather_6",
	"G1_2S68_expr_8",
	"G1_2S69__Gather_9_split_trans",
	"G1_2S75_expr_10",
	"G1_2S73__Concat_6",
	"G1_2S74__Concat_7_trans_in1",
	"G1_2S76__Concat_5",
	"G1_2S77__Concat_7_trans_in0",
	"G1_2S79__Concat_7_trans_out0",
	"IO_Wait",
};

unsigned int Inversion;

float * __restrict__ G1_2Input_1;
float * __restrict__ G1_2Input_2;
float * __restrict__ G1_2Input_3;
float * __restrict__ G1_2Output_1;
float * __restrict__ G1_2Output_2;

// where to insert Graph 2 : S2 , S39 ,  S25, after the inverse (remember to optimize)
int  main_1_bCNN()
{
	unsigned int Start_IO;
	G1_2_AT_GraphPerf_CNN_Total = gap_cl_readhwtimer();
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF0, *UchanHF0 = &_UchanHF0;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF2, *UchanHF2 = &_UchanHF2;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF3, *UchanHF3 = &_UchanHF3;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF4, *UchanHF4 = &_UchanHF4;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF5, *UchanHF5 = &_UchanHF5;
	/* Moving _matmul_4_biases (1/1), size 24 from DefaultFlash at 528 to (size 24) L2 at 942652 using event 0 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 528), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 942652), 24, 0, UchanHF0);
	G1_2_AT_GraphPerf[0] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] = 0;
	G1_2S2__ReduceSum(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* In */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+938552)) /* Out */
	);

	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_b_L2_Memory_Dyn + 133640;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}

	G1_2_AT_GraphPerf[0] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[0];
	G1_2_AT_GraphPerf[1] = gap_cl_readhwtimer();
	G1_2S10_expr_0(
		((float * __restrict__) (main_1_b_L3_Memory_Dyn+0)), /* expr_0_in_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+66820)), /* expr_0_in_1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* expr_0_in_2 */
		((float * __restrict__) (main_1_b_L3_Memory_Dyn+801840)), /* expr_0_out_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+133640)) /* expr_0_out_1 */
	);
	G1_2_AT_GraphPerf[1] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[1];
	/* Moving _matmul_5_biases (1/1), size 24 from DefaultFlash at 552 to (size 24) L2 at 40128 using event 1 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 552), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 40128), 24, 0, UchanHF1);
	/* Moving _matmul_6_biases (1/1), size 24 from DefaultFlash at 576 to (size 24) L2 at 111024 using event 2 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 576), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 111024), 24, 0, UchanHF2);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _matmul_4_biases using event 0 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF0);
	G1_2_AT_GraphPerf[2] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] += G1_2_AT_GraphPerf[2] - Start_IO;
	G1_2S34__MatMul_4(
		((float * __restrict__) (main_1_b_L3_Memory_Dyn+0)), /* In2 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+133640)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+942652)), /* Bias */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)) /* Out */
	);
	G1_2_AT_GraphPerf[2] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[2];
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 600), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 1000000), 24, 0, UchanHF0);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _matmul_7_biases using event 0 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF0);
	G1_2_AT_GraphPerf[6] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] += G1_2_AT_GraphPerf[6] - Start_IO;
	G1_2S44__MatMul_7(
		((float * __restrict__) ((main_1_b_L3_Memory_Dyn+0) + 400920)), /* In2 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+133640)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+1000000)), /* Bias */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+1050000)) /* Out */
	);


	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_b_L2_Memory_Dyn + 133640;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}

	G1_2_AT_GraphPerf[6] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[6];


	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _matmul_5_biases using event 1 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF1);
	G1_2_AT_GraphPerf[3] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] += G1_2_AT_GraphPerf[3] - Start_IO;
	G1_2S37__MatMul_5(
		((float * __restrict__) ((main_1_b_L3_Memory_Dyn+0) + 400920)), /* In2 */
		((float * __restrict__) ((main_1_b_L2_Memory_Dyn+133640) + 400920)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+40128)), /* Bias */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)) /* Out */
	);
	G1_2_AT_GraphPerf[3] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[3];
	G1_2_AT_GraphPerf[4] = gap_cl_readhwtimer();
	G1_2S39_expr_3(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)), /* expr_3_in_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* expr_3_in_1 */
		((float * __restrict__) (main_1_b_L3_Memory_Dyn+1603680)) /* expr_3_out_0 */
	);
	G1_2_AT_GraphPerf[4] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[4];
	/* Moving _matmul_7_biases (1/1), size 24 from DefaultFlash at 600 to (size 24) L2 at 77136 using event 0 */
	
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _matmul_6_biases using event 2 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF2);
	G1_2_AT_GraphPerf[5] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] += G1_2_AT_GraphPerf[5] - Start_IO;
	G1_2S41__MatMul_6(
		((float * __restrict__) (main_1_b_L3_Memory_Dyn+0)), /* In2 */
		((float * __restrict__) ((main_1_b_L2_Memory_Dyn+133640) + 400920)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+111024)), /* Bias */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+37008)) /* Out */
	);
	G1_2_AT_GraphPerf[5] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[5];
	
	G1_2_AT_GraphPerf[7] = gap_cl_readhwtimer();
	G1_2S46_expr_4(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+37008)), /* expr_4_in_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+1050000)), /* expr_4_in_1 */
		((float * __restrict__) ((main_1_b_L3_Memory_Dyn+1603680) + 37008)) /* expr_4_out_0 */
	);
	G1_2_AT_GraphPerf[7] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[7];
	G1_2_AT_GraphPerf[8] = gap_cl_readhwtimer();
	G1_2S48_expr_5(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+938552)), /* expr_5_in_0 */
		((float * __restrict__) (main_1_b_L3_Memory_Dyn+1603680)), /* expr_5_in_1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)) /* expr_5_out_0 */
	);
	G1_2_AT_GraphPerf[8] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[8];
	G1_2_AT_GraphPerf[9] = gap_cl_readhwtimer();
	G1_2S54_expr_9(
		((float * __restrict__) ((main_1_b_L2_Memory_Dyn+0) + 37008)), /* expr_9_in_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+296064)) /* expr_9_out_0 */
	);
	G1_2_AT_GraphPerf[9] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[9];
	G1_2_AT_GraphPerf[10] = gap_cl_readhwtimer();
	G1_2S52__Concat_3(
		((float * __restrict__) ((main_1_b_L2_Memory_Dyn+0) + 37008)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* In2 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)) /* Out */
	);
	G1_2_AT_GraphPerf[10] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[10];
	G1_2_AT_GraphPerf[11] = gap_cl_readhwtimer();
	G1_2S53__Concat_4_trans_in1(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)), /* In */
		((float * __restrict__) ((main_1_b_L2_Memory_Dyn+148032) + 74016)) /* Out */
	);
	G1_2_AT_GraphPerf[11] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[11];
	G1_2_AT_GraphPerf[12] = gap_cl_readhwtimer();
	G1_2S55__Concat_2(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+296064)), /* In2 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)) /* Out */
	);
	G1_2_AT_GraphPerf[12] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[12];
	/* Moving _matmul_biases (1/1), size 24 from DefaultFlash at 432 to (size 24) L2 at 6240 using event 0 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 432), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 6240), 24, 0, UchanHF0);
	G1_2_AT_GraphPerf[13] = gap_cl_readhwtimer();
	G1_2S56__Concat_4_trans_in0(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)), /* In */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+148032)) /* Out */
	);
	G1_2_AT_GraphPerf[13] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[13];
	/* Moving _matmul_1_biases (1/1), size 24 from DefaultFlash at 456 to (size 24) L2 at 80256 using event 1 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 456), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 80256), 24, 0, UchanHF1);
	G1_2_AT_GraphPerf[14] = gap_cl_readhwtimer();
	G1_2S58__Concat_4_trans_out0(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+148032)), /* In */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+333072)) /* Out */
	);
	G1_2_AT_GraphPerf[14] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[14];
	/* Moving _matmul_2_biases (1/1), size 24 from DefaultFlash at 480 to (size 24) L2 at 151152 using event 2 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 480), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 151152), 24, 0, UchanHF2);
	/* Moving _matmul_3_biases (1/1), size 24 from DefaultFlash at 504 to (size 24) L2 at 154272 using event 3 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 504), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 154272), 24, 0, UchanHF3);
	/* Moving Constant__constant_17_output_0_1 (1/1), size 144 from DefaultFlash at 144 to (size 144) L2 at 224104 using event 4 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 144), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 224104), 144, 0, UchanHF4);
	/* Moving Constant__constant_17_output_0_2 (1/1), size 144 from DefaultFlash at 288 to (size 144) L2 at 224248 using event 5 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 288), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 224248), 144, 0, UchanHF5);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _matmul_biases using event 0 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF0);
	G1_2_AT_GraphPerf[15] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] += G1_2_AT_GraphPerf[15] - Start_IO;
	G1_2S18__MatMul(
		((float * __restrict__) (main_1_b_L3_Memory_Dyn+0)), /* In2 */
		((float * __restrict__) (main_1_b_L3_Memory_Dyn+801840)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+6240)), /* Bias */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+40128)) /* Out */
	);
	G1_2_AT_GraphPerf[15] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[15];
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _matmul_1_biases using event 1 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF1);
	G1_2_AT_GraphPerf[16] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] += G1_2_AT_GraphPerf[16] - Start_IO;
	G1_2S21__MatMul_1(
		((float * __restrict__) ((main_1_b_L3_Memory_Dyn+0) + 400920)), /* In2 */
		((float * __restrict__) ((main_1_b_L3_Memory_Dyn+801840) + 400920)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+80256)), /* Bias */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+3120)) /* Out */
	);
	G1_2_AT_GraphPerf[16] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[16];
	G1_2_AT_GraphPerf[17] = gap_cl_readhwtimer();
	G1_2S23_expr_1(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+40128)), /* expr_1_in_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+3120)), /* expr_1_in_1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+77136)) /* expr_1_out_0 */
	);
	G1_2_AT_GraphPerf[17] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[17];
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _matmul_2_biases using event 2 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF2);
	G1_2_AT_GraphPerf[18] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] += G1_2_AT_GraphPerf[18] - Start_IO;
	G1_2S25__MatMul_2(
		((float * __restrict__) (main_1_b_L3_Memory_Dyn+0)), /* In2 */
		((float * __restrict__) ((main_1_b_L3_Memory_Dyn+801840) + 400920)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+151152)), /* Bias */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+40128)) /* Out */
	);

	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_b_L2_Memory_Dyn + 133640 + 400920;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}
	
	G1_2_AT_GraphPerf[18] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[18];
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _matmul_3_biases using event 3 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF3);
	G1_2_AT_GraphPerf[19] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] += G1_2_AT_GraphPerf[19] - Start_IO;
	G1_2S28__MatMul_3(
		((float * __restrict__) ((main_1_b_L3_Memory_Dyn+0) + 400920)), /* In2 */
		((float * __restrict__) (main_1_b_L3_Memory_Dyn+801840)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+154272)), /* Bias */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)) /* Out */
	);
	G1_2_AT_GraphPerf[19] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[19];
	/* Moving Constant__constant_17_output_0 (1/1), size 144 from DefaultFlash at 0 to (size 144) L2 at 151152 using event 0 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) main_1_b_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) main_1_b_L2_Memory_Dyn + 151152), 144, 0, UchanHF0);
	G1_2_AT_GraphPerf[20] = gap_cl_readhwtimer();
	G1_2S30_expr_2(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+40128)), /* expr_2_in_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* expr_2_in_1 */
		((float * __restrict__) ((main_1_b_L2_Memory_Dyn+77136) + 37008)) /* expr_2_out_0 */
	);
	G1_2_AT_GraphPerf[20] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[20];
	G1_2_AT_GraphPerf[21] = gap_cl_readhwtimer();
	G1_2S32__Concat_trans(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+77136)), /* In */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)) /* Out */
	);
	G1_2_AT_GraphPerf[21] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[21];
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of Constant__constant_17_output_0 using event 0 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF0);
	G1_2_AT_GraphPerf[22] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] += G1_2_AT_GraphPerf[22] - Start_IO;
	G1_2S61_expr_6(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+151152)), /* expr_6_in_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* expr_6_in_1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)) /* expr_6_out_0 */
	);
	G1_2_AT_GraphPerf[22] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[22];
	G1_2_AT_GraphPerf[23] = gap_cl_readhwtimer();
	G1_2S62__ReduceSum_1(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)), /* In */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+222048)) /* Out */
	);
	G1_2_AT_GraphPerf[23] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[23];
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of Constant__constant_17_output_0_1 using event 4 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF4);
	/* Waiting completion of transfer of Constant__constant_17_output_0_2 using event 5 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF5);
	G1_2_AT_GraphPerf[24] = gap_cl_readhwtimer();
	G1_2_AT_GraphPerf[35] += G1_2_AT_GraphPerf[24] - Start_IO;
	G1_2S65_expr_7(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+222048)), /* expr_7_in_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+224104)), /* expr_7_in_1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* expr_7_in_2 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+224248)), /* expr_7_in_3 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)), /* expr_7_out_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+148032)) /* expr_7_out_1 */
	);
	G1_2_AT_GraphPerf[24] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[24];
	G1_2_AT_GraphPerf[25] = gap_cl_readhwtimer();
	G1_2S66__ReduceSum_2(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+148032)), /* In */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)) /* Out */
	);
	G1_2_AT_GraphPerf[25] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[25];
	G1_2_AT_GraphPerf[26] = gap_cl_readhwtimer();
	G1_2S67__Gather_6(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* In */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+2056)) /* Out1 */
	);
	G1_2_AT_GraphPerf[26] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[26];
	G1_2_AT_GraphPerf[27] = gap_cl_readhwtimer();
	G1_2S68_expr_8(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)), /* expr_8_in_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+2056)), /* expr_8_in_1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+148032)) /* expr_8_out_0 */
	);
	G1_2_AT_GraphPerf[27] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[27];
	G1_2_AT_GraphPerf[28] = gap_cl_readhwtimer();
	G1_2S69__Gather_9_split_trans(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+148032)), /* In */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)) /* Out */
	);
	G1_2_AT_GraphPerf[28] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[28];
	G1_2_AT_GraphPerf[29] = gap_cl_readhwtimer();
	G1_2S75_expr_10(
		((float * __restrict__) ((main_1_b_L2_Memory_Dyn+0) + 37008)), /* expr_10_in_0 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+296064)) /* expr_10_out_0 */
	);
	G1_2_AT_GraphPerf[29] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[29];
	G1_2_AT_GraphPerf[30] = gap_cl_readhwtimer();
	G1_2S73__Concat_6(
		((float * __restrict__) ((main_1_b_L2_Memory_Dyn+0) + 37008)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* In2 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)) /* Out */
	);
	G1_2_AT_GraphPerf[30] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[30];
	G1_2_AT_GraphPerf[31] = gap_cl_readhwtimer();
	G1_2S74__Concat_7_trans_in1(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)), /* In */
		((float * __restrict__) ((main_1_b_L2_Memory_Dyn+148032) + 74016)) /* Out */
	);
	G1_2_AT_GraphPerf[31] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[31];
	G1_2_AT_GraphPerf[32] = gap_cl_readhwtimer();
	G1_2S76__Concat_5(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)), /* In1 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+296064)), /* In2 */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)) /* Out */
	);
	G1_2_AT_GraphPerf[32] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[32];
	G1_2_AT_GraphPerf[33] = gap_cl_readhwtimer();
	G1_2S77__Concat_7_trans_in0(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+74016)), /* In */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+148032)) /* Out */
	);
	G1_2_AT_GraphPerf[33] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[33];
	G1_2_AT_GraphPerf[34] = gap_cl_readhwtimer();
	G1_2S79__Concat_7_trans_out0(
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+148032)), /* In */
		((float * __restrict__) (main_1_b_L2_Memory_Dyn+0)) /* Out */
	);
	G1_2_AT_GraphPerf[34] = gap_cl_readhwtimer() - G1_2_AT_GraphPerf[34];

	Inversion = gap_cl_readhwtimer();

	inverse(G1_2Output_1,(float *) (main_1_b_L2_Memory_Dyn+600000),257,12);

	Inversion = gap_cl_readhwtimer() - Inversion;
	if (!first_execution){
		main_2_L2_Memory_Dyn = main_1_b_L2_Memory_Dyn + 748032;
		main_2CNN(G2_Input,output_imaginary,output_real);
	}

	G1_2_AT_GraphPerf_CNN_Total = gap_cl_readhwtimer() - G1_2_AT_GraphPerf_CNN_Total;
	return 0;
}