#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "main_2Kernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER fft_forward_L1_Memory;
L2_MEM AT_L2_POINTER fft_forward_L2_Memory;
L2_MEM AT_L2_POINTER fft_forward_L2_Memory_Dyn;
static AT_DEFAULTFLASH_FS_T DefaultFlash;
void  S5_RfftNode(
		float * __restrict__ In,
		float * __restrict__ Out,
		float * __restrict__ Twiddles_fft_int,
		float * __restrict__ Twiddles_rfft,
		short int * SwapTable_fft,
		float * __restrict__ WinTable)

{
	/* Shared L1: 9228 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	Windowing_T S_KerArg0, *KerArg0 = &S_KerArg0;
	RFFT_Arg_T S_KerArg1, *KerArg1 = &S_KerArg1;

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
			@ 0 (Total Size: 2048 )[Tile0, 1:[512x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 4]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2048 (Total Size: 2056 )[D0, [0 x 2056, 2056]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2056, 2056]]
		Tile0: [0, 2056, 2056], Tile1: [0, 2056, 2056], Tile2; [0, 2056, 2056]
	Ker Arg: WinTable, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4104 (Total Size: 1028 )[Tile0, 1:[257x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[257x1], 4]
		Tile0: [0, 1028, 1028], Tile1: [0, 1028, 1028], Tile2; [0, 1028, 1028]
	Ker Arg: Twiddles_fft_int, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5132 (Total Size: 1536 )[Tile0, 1:[384x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[384x1], 4]
		Tile0: [0, 1536, 1536], Tile1: [0, 1536, 1536], Tile2; [0, 1536, 1536]
	Ker Arg: SwapTable_fft, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6668 (Total Size: 512 )[Tile0, 1:[256x1], 2]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[256x1], 2]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Twiddles_rfft, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 7180 (Total Size: 2048 )[Tile0, 1:[512x1], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[512x1], 4]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Frame = (void *__restrict__) (fft_forward_L1_Memory+0);
	KerArg0->OutFrame = (void *__restrict__) (fft_forward_L1_Memory+0);
	KerArg0->Window = (void *__restrict__) (fft_forward_L1_Memory+4104);
	KerArg0->WinSize = (int) (257);
	KerArg0->FrameSize = (int) (512);
	KerArg1->Data = (void * __restrict__) (fft_forward_L1_Memory+0);
	KerArg1->RFFT_Out = (void * __restrict__) (fft_forward_L1_Memory+2048);
	KerArg1->Twiddles = (void * __restrict__) (fft_forward_L1_Memory+5132);
	KerArg1->RTwiddles = (void * __restrict__) (fft_forward_L1_Memory+7180);
	KerArg1->SwapTable = (void * __restrict__) (fft_forward_L1_Memory+6668);
	KerArg1->N_fft = (short int) (512);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+0), 2048, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Twiddles_rfft+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+7180), 2048, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Twiddles_fft_int+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+5132), 1536, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) WinTable+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+4104), 1028, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SwapTable_fft+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+6668), 512, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read SwapTable_fft */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_LOOP =========================*/
			AT_FORK(gap_ncore(), (void *) WindowingReal2Real_f32, (void *) KerArg0);
			__CALL(WindowingReal2Real_f32, KerArg0);
			AT_FORK(gap_ncore(), (void *) RFFT_DIF_Par_f32, (void *) KerArg1);
			__CALL(RFFT_DIF_Par_f32, KerArg1);
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) fft_forward_L1_Memory+2048), 2056, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
#pragma GCC diagnostic pop
int  fft_forwardCNN_Construct()

{
	int Error;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "fft_forward_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;
	
	fft_forward_L2_Memory_Dyn = main_1_L2_Memory_Dyn+1000000;
	if (fft_forward_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	fft_forward_L1_Memory = main_1_L1_Memory;
	if (fft_forward_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	return AT_NO_ERROR;
}
void fft_forwardCNN_ConstructCluster()

{
}
int  fft_forwardCNN_Destruct()

{
	AT_L2_FREE(0, fft_forward_L2_Memory_Dyn, 5124);
	AT_L1_FREE(0, fft_forward_L1_Memory, 9228);
	AT_DEFAULTFLASH_FS_CLOSE(&DefaultFlash);
	return 0;
}
int fft_forwardCNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 9228; /* L1 Memory */
		case AT_L2_MEM:     return 0; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 5124; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 0; /* L3 Memory, dynamic */
		default:            return 0;
	}
}
int  fft_forwardCNN(
		float * __restrict__ Input_1,
		float * __restrict__ Output_1)

{
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF0, *UchanHF0 = &_UchanHF0;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF2, *UchanHF2 = &_UchanHF2;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF3, *UchanHF3 = &_UchanHF3;
	/* Moving Rfftnode_winlut (1/1), size 1028 from DefaultFlash at 3584 to (size 1028) L2 at 3584 using event 0 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) fft_forward_L3_Flash + 3584), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn + 3584), 1028, 0, UchanHF0);
	/* Moving Rfftnode_fft_twiddles (1/1), size 1536 from DefaultFlash at 2048 to (size 1536) L2 at 2048 using event 1 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) fft_forward_L3_Flash + 2048), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn + 2048), 1536, 0, UchanHF1);
	/* Moving Rfftnode_swaptable (1/1), size 512 from DefaultFlash at 4612 to (size 512) L2 at 4612 using event 2 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) fft_forward_L3_Flash + 4612), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn + 4612), 512, 0, UchanHF2);
	/* Moving Rfftnode_rfft_twiddles (1/1), size 2048 from DefaultFlash at 0 to (size 2048) L2 at 0 using event 3 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) fft_forward_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) fft_forward_L2_Memory_Dyn + 0), 2048, 0, UchanHF3);
	/* Waiting completion of transfer of Rfftnode_winlut using event 0 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF0);
	/* Waiting completion of transfer of Rfftnode_fft_twiddles using event 1 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF1);
	/* Waiting completion of transfer of Rfftnode_swaptable using event 2 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF2);
	/* Waiting completion of transfer of Rfftnode_rfft_twiddles using event 3 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF3);
	S5_RfftNode(
		((float * __restrict__) Input_1), /* In */
		((float * __restrict__) Output_1), /* Out */
		((float * __restrict__) (fft_forward_L2_Memory_Dyn+2048)), /* Twiddles_fft_int */
		((float * __restrict__) (fft_forward_L2_Memory_Dyn+0)), /* Twiddles_rfft */
		((signed short * __restrict__) (fft_forward_L2_Memory_Dyn+4612)), /* SwapTable_fft */
		((float * __restrict__) (fft_forward_L2_Memory_Dyn+3584)) /* WinTable */
	);
	return 0;
}
