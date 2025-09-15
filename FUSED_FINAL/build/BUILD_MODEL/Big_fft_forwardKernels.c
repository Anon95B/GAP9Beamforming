#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "main_2Kernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER Big_fft_forward_L1_Memory;
L2_MEM AT_L2_POINTER Big_fft_forward_L2_Memory;
L2_MEM AT_L2_POINTER Big_fft_forward_L2_Memory_Dyn;
AT_DEFAULTRAM_POINTER Big_fft_forward_L3_Memory_Dyn;

float * __restrict__ BiG_STFT_Input_1;
float * __restrict__ BiG_STFT_Output_1;

static AT_DEFAULTFLASH_FS_T DefaultFlash;
void  BiG_S5_RfftNode(
		float * __restrict__ In,
		float * __restrict__ Out,
		float * __restrict__ Twiddles_fft_int,
		float * __restrict__ Twiddles_rfft,
		short int * SwapTable_fft,
		float * __restrict__ WinTable)

{
	/* Shared L1: 13340 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR2, *UchanHR2 = &_UchanHR2;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	Windowing_T S_KerArg0, *KerArg0 = &S_KerArg0;
	RFFT_Arg_T S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: 65][Tile0 Dim: 1]
	Ker Arg: In_rfft, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6168 (Total Size: 2048 )[Tile0, 1:[512x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 4]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: -2, Max Pipe Depth: 2
		KerArgItSpace: 65 logical tiles, 65 physical tiles
			@ 2056 (Total Size: 133640 )[D0, [64 x 2056, 2056]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [64 x 2056, 2056]]
		Tile0: [0, 2056, 2056], Tile1: [2056, 2056, 2056], Tile2; [4112, 2056, 2056]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 65 logical tiles, 65 physical tiles
			@ 0 (Total Size: 132100 )[D0, [64 x 1028, 1028]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [64 x 1028, 1028]]
		Tile0: [0, 1028, 1028], Tile1: [2048, 1028, 1028], Tile2; [4096, 1028, 1028]
	Ker Arg: WinTable, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 8216 (Total Size: 1028 )[Tile0, 1:[257x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[257x1], 4]
		Tile0: [0, 1028, 1028], Tile1: [0, 1028, 1028], Tile2; [0, 1028, 1028]
	Ker Arg: Twiddles_fft_int, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 9244 (Total Size: 1536 )[Tile0, 1:[384x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[384x1], 4]
		Tile0: [0, 1536, 1536], Tile1: [0, 1536, 1536], Tile2; [0, 1536, 1536]
	Ker Arg: SwapTable_fft, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 10780 (Total Size: 512 )[Tile0, 1:[256x1], 2]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 2]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Twiddles_rfft, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 11292 (Total Size: 2048 )[Tile0, 1:[512x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 4]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->OutFrame = (void *__restrict__) (fft_forward_L1_Memory+6168);
	KerArg0->Window = (void *__restrict__) (fft_forward_L1_Memory+8216);
	KerArg0->WinSize = (int) (257);
	KerArg0->FrameSize = (int) (512);
	KerArg1->Data = (void * __restrict__) (fft_forward_L1_Memory+6168);
	KerArg1->Twiddles = (void * __restrict__) (fft_forward_L1_Memory+9244);
	KerArg1->RTwiddles = (void * __restrict__) (fft_forward_L1_Memory+11292);
	KerArg1->SwapTable = (void * __restrict__) (fft_forward_L1_Memory+10780);
	KerArg1->N_fft = (short int) (512);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=2056;
	_SPP_Out=0; _SP_Out=0;
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn+0+0), 1028, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+2048), ((AT_DEFAULTRAM_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn+0+1028), 1028, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+0+0), 1028, 0, DmaR_Evt1);
	_NN_In=2048; _SN_In=1028;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Twiddles_rfft+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+11292), 2048, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Twiddles_fft_int+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+9244), 1536, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) WinTable+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+8216), 1028, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SwapTable_fft+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+10780), 512, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read SwapTable_fft */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<65; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==64), D0Ind_NextLast = ((D0Ind+1)==64), D0Ind_NextNextLast = ((D0Ind+2)==64);
		/*================================= Prepare Tiles ===================================*/
		_SNN_In = 0;
		if (!(D0Ind_Last)) {
			if (!(D0Ind_NextLast)) {
				_NN_In = _NN_In + (2048); _SNN_In = (1028); 
			}
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
		if (_SNN_In) {
			AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn+0+1028*((D0Ind_Total)%2)),
					1*(_SNN_In), 0, UchanHR1);
		}
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn+0+1028*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+0+1028*((D0Ind_Total+1)%2)),
					1*(_SN_In), 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->Frame = (void *__restrict__) (fft_forward_L1_Memory+0+1028*((D0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) WindowingReal2Real_f32, (void *) KerArg0);
			__CALL(WindowingReal2Real_f32, KerArg0);
			KerArg1->RFFT_Out = (void * __restrict__) (fft_forward_L1_Memory+2056+2056*((D0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) RFFT_DIF_Par_f32, (void *) KerArg1);
			__CALL(RFFT_DIF_Par_f32, KerArg1);
		} /* End iteration on Tile0 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write Out */
		if (_SP_Out) AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn+2056+2056*((D0Ind_Total+-1)%2)),
					_SP_Out, 1, UchanHR2);
		AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn+2056+2056*((D0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+2056+2056*((D0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SPP_Out = _SP_Out;
		_P_Out = _C_Out;_SP_Out = _SC_Out;
		_SN_In = _SNN_In;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(D0Ind_Last)) {
			_C_Out = _C_Out + (2056); _SC_Out = (2056); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait previous uDMA write Out */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_DEFAULTRAM_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn+2056+2056*((D0Ind_Total+-1)%2)), _SP_Out, 1, UchanHR2);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR2); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
#pragma GCC diagnostic pop
int  BiG_fft_forwardCNN_Construct()

{
	int Error;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "BIG_fft_forward_L3_Flash_Const.dat", &Error);
	if (Error){
		//printf("OPENING error \n");
		return AT_FLASH_OPEN_ERROR;}

	Big_fft_forward_L3_Memory_Dyn = main_1_L3_Memory_Dyn;
	if (Big_fft_forward_L3_Memory_Dyn == 0) return AT_RAM_OPEN_ERROR;
	Big_fft_forward_L2_Memory = main_1_L2_Memory_Dyn ;
	if (Big_fft_forward_L2_Memory == 0) return AT_L2_OPEN_ERROR;
	Big_fft_forward_L2_Memory_Dyn = (main_1_L2_Memory_Dyn + 5124);
	if (Big_fft_forward_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	Big_fft_forward_L1_Memory = main_1_L1_Memory;
	if (Big_fft_forward_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	
	BiG_STFT_Input_1 = (float * __restrict__) (Big_fft_forward_L3_Memory_Dyn + 0);
	BiG_STFT_Output_1 = (float * __restrict__) (Big_fft_forward_L3_Memory_Dyn + 132100);
	return AT_NO_ERROR;
}


int  BiG_fft_forwardCNN(
)

{
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	/* Static Moving Rfftnode_winlut, size 1028 from DefaultFlash at 3584 to (size 1028) L2 at 3584..4611 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) Big_fft_forward_L3_Flash + 3584), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) Big_fft_forward_L2_Memory + 3584), 1028, 0, UchanHF1);
	//printf("la 1 \n");
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF1);
	//printf("la 1 finisce \n");
	/* Static Moving Rfftnode_fft_twiddles, size 1536 from DefaultFlash at 2048 to (size 1536) L2 at 2048..3583 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) Big_fft_forward_L3_Flash + 2048), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) Big_fft_forward_L2_Memory + 2048), 1536, 0, UchanHF1);
	//printf("la 2 \n");
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF1);
	//printf("la 2 finisce\n");
	/* Static Moving Rfftnode_swaptable, size 512 from DefaultFlash at 4612 to (size 512) L2 at 4612..5123 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) Big_fft_forward_L3_Flash + 4612), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) Big_fft_forward_L2_Memory + 4612), 512, 0, UchanHF1);
	//printf("la 3 \n");
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF1);
	//printf("la 3 finisce\n");
	/* Static Moving Rfftnode_rfft_twiddles, size 2048 from DefaultFlash at 0 to (size 2048) L2 at 0..2047 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) Big_fft_forward_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) Big_fft_forward_L2_Memory + 0), 2048, 0, UchanHF1);
	//printf("la 4 finisce\n");
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF1);
	//printf("la 4 \n");


	BiG_S5_RfftNode(
		((float * __restrict__) (BiG_STFT_Input_1)), /* In */
		((float * __restrict__) (BiG_STFT_Output_1)), /* Out */
		((float * __restrict__) (Big_fft_forward_L2_Memory+2048)), /* Twiddles_fft_int */
		((float * __restrict__) (Big_fft_forward_L2_Memory+0)), /* Twiddles_rfft */
		((signed short * __restrict__) (Big_fft_forward_L2_Memory+4612)), /* SwapTable_fft */
		((float * __restrict__) (Big_fft_forward_L2_Memory+3584)) /* WinTable */
	);
	
	return 0;
}
