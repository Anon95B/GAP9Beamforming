#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "main_2Kernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER irfft_forward_L1_Memory;
L2_MEM AT_L2_POINTER irfft_forward_L2_Memory;
L2_MEM AT_L2_POINTER irfft_forward_L2_Memory_Dyn;
static AT_DEFAULTFLASH_FS_T DefaultFlash;
void  S4_IRfftNode(
		float * __restrict__ In,
		float * __restrict__ Out,
		float * __restrict__ Twiddles_fft_int,
		float * __restrict__ Twiddles_rfft,
		short int * SwapTable_fft)

{
	/* Shared L1: 8200 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	RFFT_Arg_T S_KerArg0, *KerArg0 = &S_KerArg0;

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
			@ 0 (Total Size: 2056 )[D0, [0 x 2056, 2056]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2056, 2056]]
		Tile0: [0, 2056, 2056], Tile1: [0, 2056, 2056], Tile2; [0, 2056, 2056]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 2056 (Total Size: 2048 )[D0, [0 x 2048, 2048]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2048, 2048]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: Twiddles_fft_int, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 4104 (Total Size: 1536 )[Tile0, 1:[1x384], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x384], 4]
		Tile0: [0, 1536, 1536], Tile1: [0, 1536, 1536], Tile2; [0, 1536, 1536]
	Ker Arg: SwapTable_fft, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 5640 (Total Size: 512 )[Tile0, 1:[1x256], 2]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x256], 2]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: Twiddles_rfft, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6152 (Total Size: 2048 )[Tile0, 1:[1x512], 4]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x512], 4]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Data = (void * __restrict__) (irfft_forward_L1_Memory+0);
	KerArg0->RFFT_Out = (void * __restrict__) (irfft_forward_L1_Memory+2056);
	KerArg0->Twiddles = (void * __restrict__) (irfft_forward_L1_Memory+4104);
	KerArg0->RTwiddles = (void * __restrict__) (irfft_forward_L1_Memory+6152);
	KerArg0->SwapTable = (void * __restrict__) (irfft_forward_L1_Memory+5640);
	KerArg0->N_fft = (short int) (512);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) irfft_forward_L1_Memory+0), 2056, 0, DmaR_Evt1);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Twiddles_rfft+0), ((AT_L2_INT_ADDR_TYPE) irfft_forward_L1_Memory+6152), 2048, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Twiddles_fft_int+0), ((AT_L2_INT_ADDR_TYPE) irfft_forward_L1_Memory+4104), 1536, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) SwapTable_fft+0), ((AT_L2_INT_ADDR_TYPE) irfft_forward_L1_Memory+5640), 512, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read SwapTable_fft */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_LOOP =========================*/
			AT_FORK(gap_ncore(), (void *) IRFFT_DIF_Par_f32, (void *) KerArg0);
			__CALL(IRFFT_DIF_Par_f32, KerArg0);
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) irfft_forward_L1_Memory+2056), 2048, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
#pragma GCC diagnostic pop
int  irfft_forwardCNN_Construct()

{
	int Error;

	AT_DEFAULTFLASH_FS_CONF_T DefaultFlashConf;
	AT_DEFAULTFLASH_FS_CONF_INIT(&DefaultFlashConf, AT_MEM_L3_DEFAULTFLASH, 0);
	AT_DEFAULTFLASH_FS_OPEN(&DefaultFlash, &DefaultFlashConf, 0, "irfft_forward_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;

	irfft_forward_L2_Memory_Dyn = main_1_L2_Memory_Dyn+1000000;
	if (irfft_forward_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	irfft_forward_L1_Memory = main_1_L1_Memory;
	if (irfft_forward_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	return AT_NO_ERROR;
}
void irfft_forwardCNN_ConstructCluster()

{
}
int  irfft_forwardCNN_Destruct()

{
	AT_L2_FREE(0, irfft_forward_L2_Memory_Dyn, 4096);
	AT_L1_FREE(0, irfft_forward_L1_Memory, 8200);
	AT_DEFAULTFLASH_FS_CLOSE(&DefaultFlash);
	return 0;
}
int irfft_forwardCNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 8200; /* L1 Memory */
		case AT_L2_MEM:     return 0; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 4096; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 0; /* L3 Memory, dynamic */
		default:            return 0;
	}
}
int  irfft_forwardCNN(
		float * __restrict__ Input_1,
		float * __restrict__ Output_1)

{
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF0, *UchanHF0 = &_UchanHF0;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF1, *UchanHF1 = &_UchanHF1;
	AT_DEFAULTFLASH_FS_CL_EVENT _UchanHF2, *UchanHF2 = &_UchanHF2;
	/* Moving Irfftnode_fft_twiddles (1/1), size 1536 from DefaultFlash at 2048 to (size 1536) L2 at 2048 using event 0 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) irfft_forward_L3_Flash + 2048), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) irfft_forward_L2_Memory_Dyn + 2048), 1536, 0, UchanHF0);
	/* Moving Irfftnode_swaptable (1/1), size 512 from DefaultFlash at 3584 to (size 512) L2 at 3584 using event 1 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) irfft_forward_L3_Flash + 3584), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) irfft_forward_L2_Memory_Dyn + 3584), 512, 0, UchanHF1);
	/* Moving Irfftnode_rfft_twiddles (1/1), size 2048 from DefaultFlash at 0 to (size 2048) L2 at 0 using event 2 */
	AT_DEFAULTFLASH_FS_CL_COPY(&DefaultFlash, ((AT_DEFAULTFLASH_FS_EXT_ADDR_TYPE) irfft_forward_L3_Flash + 0), ((AT_DEFAULTFLASH_FS_INT_ADDR_TYPE) irfft_forward_L2_Memory_Dyn + 0), 2048, 0, UchanHF2);
	/* Waiting completion of transfer of Irfftnode_fft_twiddles using event 0 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF0);
	/* Waiting completion of transfer of Irfftnode_swaptable using event 1 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF1);
	/* Waiting completion of transfer of Irfftnode_rfft_twiddles using event 2 */
	AT_DEFAULTFLASH_FS_CL_WAIT(&DefaultFlash, UchanHF2);
	S4_IRfftNode(
		((float * __restrict__) Input_1), /* In */
		((float * __restrict__) Output_1), /* Out */
		((float * __restrict__) (irfft_forward_L2_Memory_Dyn+2048)), /* Twiddles_fft_int */
		((float * __restrict__) (irfft_forward_L2_Memory_Dyn+0)), /* Twiddles_rfft */
		((signed short * __restrict__) (irfft_forward_L2_Memory_Dyn+3584)) /* SwapTable_fft */
	);
	return 0;
}
