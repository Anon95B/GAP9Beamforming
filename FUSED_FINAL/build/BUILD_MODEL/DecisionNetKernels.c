#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "main_2Kernels.h"
#ifdef __EMUL__
unsigned int __L3_Read, __L3_Write, __L2_Read, __L2_Write;
#endif
L1_CL_MEM AT_L1_POINTER DecisionNet_L1_Memory;
L2_MEM AT_L2_POINTER DecisionNet_L2_Memory;
L2_MEM AT_L2_POINTER DecisionNet_L2_Memory_Dyn;
AT_DEFAULTRAM_POINTER DecisionNet_L3_Memory;
static AT_EMRAMFLASH_FS_T EmramFlash;
void  Decision_S3__conv1_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115660 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_DEFAULTRAM_CL_EVENT _UchanHR1, *UchanHR1 = &_UchanHR1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

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
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 3][D0 Dim: Init: 1, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 56 (Total Size: 8000 )[Tile0, 3:[1x3390, 1:1x3391, 1x1223], 1][D0, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[1x3390, 1:1x3391, 1x1223], 1][D0, [0 x 1, 1]]
		Tile0: [0, 3390, 3390], Tile1: [3388, 3391, 3391], Tile2; [6777, 1223, 1223]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 1 physical tiles
			@ 0 (Total Size: 54 )[Tile0, 3:[1x54, 1:1x54, 1x54], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[1x54, 1:1x54, 1x54], 1]
		Tile0: [0, 54, 54], Tile1: [0, 54, 54], Tile2; [0, 54, 54]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6840 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6904 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6920 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 6936 (Total Size: 256 )[D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 7192 (Total Size: 128000 )[Tile0, 3:[1x3389, 1:1x3389, 1x1222], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 3:[1x3389], 16]
		Tile0: [0, 54224, 54224], Tile1: [54224, 54224, 54224], Tile2; [108448, 19552, 19552]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 1 physical tiles
			@ 115640 (Total Size: 20 )[Tile0, 3:[1x20, 1:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 3:[1x20, 1:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->ColBuff = (unsigned char * __restrict__) (DecisionNet_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (DecisionNet_L1_Memory+6936);
	KerArg2->Bias = (int * __restrict__) (DecisionNet_L1_Memory+6840);
	KerArg2->Scale = (unsigned char * __restrict__) (DecisionNet_L1_Memory+6904);
	KerArg2->ScaleN = (unsigned char * __restrict__) (DecisionNet_L1_Memory+6920);
	KerArg2->Tile_InFeat = (unsigned short int) (1);
	KerArg2->TotalInFeatures = (unsigned short int) (1);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (128);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+0), ((AT_DEFAULTRAM_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+0+0), 3390, 0, UchanHR1);
	AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
	AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+3388), ((AT_DEFAULTRAM_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+0+3392), 3391, 0, UchanHR1);
	AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+56+0), 3390, 0, DmaR_Evt1);
	_NN_In=3388; _SN_In=3391;
	_C_Out=0; _SC_Out=54224;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+6936), 256, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+6840), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115640), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+6904), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+6920), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<3; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==2), T0Ind_NextLast = ((T0Ind+1)==2), T0Ind_NextNextLast = ((T0Ind+2)==2);
			/*================================= Prepare Tiles ===================================*/
			_SNN_In = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_In = _NN_In + (3389); _SNN_In = (((1)?1224:3391)*(1)); 
				} else if (!(1)) {
					_NN_In = _NN_In + (-6777); _SNN_In = (3391*(1)); 
				}
			} else if (!((1))) {
				_NN_In = _NN_In + (3389-1); _SNN_In = (3391*(1)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_DEFAULTRAM_CL_WAIT(&DefaultRam, UchanHR1); /* Wait previous uDMA read In */
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In before starting the next buffer load from L3 which will overwrite this */
			if (_SNN_In) {
				AT_DEFAULTRAM_CL_COPY(&DefaultRam, ((AT_DEFAULTRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_DEFAULTRAM_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+0+3392*((T0Ind_Total)%2)),
						1*(_SNN_In), 0, UchanHR1);
			}
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_DEFAULTRAM_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+0+3392*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+56+3392*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (DecisionNet_L1_Memory+56+3392*((T0Ind_Total)%2));
				KerArg2->Out = (unsigned char * __restrict__) (DecisionNet_L1_Memory+7192+54224*((T0Ind_Total)%2));
				KerArg2->Tile_InW = (unsigned short int) (((T0Ind_Last)?1223:3391)-1*(T0Ind==0));
				KerArg2->Tile_OutW = (unsigned short int) ((T0Ind_Last)?1222:3389);
				KerArg2->Pad = (v4s) ((v4s){1*(T0Ind==0),1*(T0Ind_Last),0,0});
				KerArg2->FirstTile = (unsigned char) ((T0Ind==0));
				KerArg2->W_Offset = (int) (((int *)(DecisionNet_L1_Memory+115640))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+7192+54224*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SN_In = _SNN_In;
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (54224); _SC_Out = (((T0Ind_NextLast)?1222:3389)*(16)); 
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
void  Decision_S6__layer1_layer1_0_conv1_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115668 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

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
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 5][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 864 (Total Size: 128000 )[Tile0, 5:[1x1780, 3:1x1781, 1x885], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x1780, 3:1x1781, 1x885], 16][D0, [0 x 16, 16]]
		Tile0: [0, 28480, 28480], Tile1: [28448, 28496, 28496], Tile2; [56912, 28496, 28496]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 0 (Total Size: 864 )[Tile0, 5:[1x864, 3:1x864, 1x864], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x864, 3:1x864, 1x864], 1]
		Tile0: [0, 864, 864], Tile1: [0, 864, 864], Tile2; [0, 864, 864]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57856 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57920 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57936 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57952 (Total Size: 768 )[D1, [0 x 768, 768]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 768, 768]]
		Tile0: [0, 768, 768], Tile1: [0, 768, 768], Tile2; [0, 768, 768]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 58720 (Total Size: 128000 )[Tile0, 5:[1x1779, 3:1x1779, 1x884], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 5:[1x1779], 16]
		Tile0: [0, 28464, 28464], Tile1: [28464, 28464, 28464], Tile2; [56928, 28464, 28464]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115648 (Total Size: 20 )[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->ColBuff = (unsigned char * __restrict__) (DecisionNet_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (DecisionNet_L1_Memory+57952);
	KerArg2->Bias = (int * __restrict__) (DecisionNet_L1_Memory+57856);
	KerArg2->Scale = (unsigned char * __restrict__) (DecisionNet_L1_Memory+57920);
	KerArg2->ScaleN = (unsigned char * __restrict__) (DecisionNet_L1_Memory+57936);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+864+0), 28480, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=28464;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57952), 768, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57856), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115648), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57920), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57936), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (28464-(16*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?886:1781)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-113840); _SN_In = (1781*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+864+28496*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (DecisionNet_L1_Memory+864+28496*((T0Ind_Total)%2));
				KerArg2->Out = (unsigned char * __restrict__) (DecisionNet_L1_Memory+58720+28464*((T0Ind_Total)%2));
				KerArg2->Tile_InW = (unsigned short int) (((T0Ind_Last)?885:1781)-1*(T0Ind==0));
				KerArg2->Tile_OutW = (unsigned short int) ((T0Ind_Last)?884:1779);
				KerArg2->Pad = (v4s) ((v4s){1*(T0Ind==0),1*(T0Ind_Last),0,0});
				KerArg2->FirstTile = (unsigned char) ((T0Ind==0));
				KerArg2->W_Offset = (int) (((int *)(DecisionNet_L1_Memory+115648))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+58720+28464*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (28464); _SC_Out = (((T0Ind_NextLast)?884:1779)*(16)); 
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
void  Decision_S9__layer1_layer1_0_conv2_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115668 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

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
		[D1 Dim: Init: 16, Tiled: 1][Tile0 Dim: 5][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 864 (Total Size: 128000 )[Tile0, 5:[1x1780, 3:1x1781, 1x885], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x1780, 3:1x1781, 1x885], 16][D0, [0 x 16, 16]]
		Tile0: [0, 28480, 28480], Tile1: [28448, 28496, 28496], Tile2; [56912, 28496, 28496]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 0 (Total Size: 864 )[Tile0, 5:[1x864, 3:1x864, 1x864], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x864, 3:1x864, 1x864], 1]
		Tile0: [0, 864, 864], Tile1: [0, 864, 864], Tile2; [0, 864, 864]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57856 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57920 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57936 (Total Size: 16 )[D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]]
		Tile0: [0, 16, 16], Tile1: [0, 16, 16], Tile2; [0, 16, 16]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57952 (Total Size: 768 )[D1, [0 x 768, 768]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 768, 768]]
		Tile0: [0, 768, 768], Tile1: [0, 768, 768], Tile2; [0, 768, 768]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 58720 (Total Size: 128000 )[Tile0, 5:[1x1779, 3:1x1779, 1x884], 16][D1, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 16, 16]][Tile0, 5:[1x1779], 16]
		Tile0: [0, 28464, 28464], Tile1: [28464, 28464, 28464], Tile2; [56928, 28464, 28464]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115648 (Total Size: 20 )[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->ColBuff = (unsigned char * __restrict__) (DecisionNet_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (DecisionNet_L1_Memory+57952);
	KerArg2->Bias = (int * __restrict__) (DecisionNet_L1_Memory+57856);
	KerArg2->Scale = (unsigned char * __restrict__) (DecisionNet_L1_Memory+57920);
	KerArg2->ScaleN = (unsigned char * __restrict__) (DecisionNet_L1_Memory+57936);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (16);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+864+0), 28480, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=28464;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57952), 768, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57856), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115648), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57920), 16, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57936), 16, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (28464-(16*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?886:1781)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-113840); _SN_In = (1781*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+864+28496*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (DecisionNet_L1_Memory+864+28496*((T0Ind_Total)%2));
				KerArg2->Out = (unsigned char * __restrict__) (DecisionNet_L1_Memory+58720+28464*((T0Ind_Total)%2));
				KerArg2->Tile_InW = (unsigned short int) (((T0Ind_Last)?885:1781)-1*(T0Ind==0));
				KerArg2->Tile_OutW = (unsigned short int) ((T0Ind_Last)?884:1779);
				KerArg2->Pad = (v4s) ((v4s){1*(T0Ind==0),1*(T0Ind_Last),0,0});
				KerArg2->FirstTile = (unsigned char) ((T0Ind==0));
				KerArg2->W_Offset = (int) (((int *)(DecisionNet_L1_Memory+115648))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+58720+28464*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (28464); _SC_Out = (((T0Ind_NextLast)?884:1779)*(16)); 
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
void  Decision_S10__layer1_layer1_0_Add_fusion(
		unsigned char * __restrict__ In1,
		unsigned char * __restrict__ In2,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115696 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	KerMat3_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

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
		[Tile0 Dim: 7]
	Ker Arg: In1, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 7 logical tiles, 7 physical tiles
			@ 0 (Total Size: 128000 )[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		Tile0: [0, 19279, 19279], Tile1: [19279, 19279, 19279], Tile2; [38558, 19279, 19279]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 7 logical tiles, 7 physical tiles
			@ 38560 (Total Size: 128000 )[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		Tile0: [0, 19279, 19279], Tile1: [19279, 19279, 19279], Tile2; [38558, 19279, 19279]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 7 logical tiles, 7 physical tiles
			@ 77120 (Total Size: 128000 )[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		Tile0: [0, 19279, 19279], Tile1: [19279, 19279, 19279], Tile2; [38558, 19279, 19279]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 7 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 14 )[Tile0, 7:[1x1, 5:1x1, 1x1], 14]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x1, 5:1x1, 1x1], 14]
		Tile0: [0, 14, 14], Tile1: [0, 14, 14], Tile2; [0, 14, 14]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (signed char *__restrict__) (DecisionNet_L1_Memory+115680);
	KerArg0->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+0), 19279, 0, DmaR_Evt1);
	_N_In1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+38560+0), 19279, 0, DmaR_Evt2);
	_N_In2=0;
	_C_Out=0; _SC_Out=19279;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115680), 14, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<7; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==6), T0Ind_NextLast = ((T0Ind+1)==6);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(T0Ind_Last)) {
			_N_In1 = _N_In1 + (19279); _SN_In1 = ((T0Ind_NextLast)?12326:19279); 
		}
		_SN_In2 = 0;
		if (!(T0Ind_Last)) {
			_N_In2 = _N_In2 + (19279); _SN_In2 = ((T0Ind_NextLast)?12326:19279); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+19280*((T0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 */
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+_N_In2), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+38560+19280*((T0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In1 = (signed char *__restrict__) (DecisionNet_L1_Memory+0+19280*((T0Ind_Total)%2));
		KerArg0->In2 = (signed char *__restrict__) (DecisionNet_L1_Memory+38560+19280*((T0Ind_Total)%2));
		KerArg0->Out = (signed char *__restrict__) (DecisionNet_L1_Memory+77120+19280*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?12326:19279);
		AT_FORK(gap_ncore(), (void *) KerMatAdd_USQ8, (void *) KerArg0);
		__CALL(KerMatAdd_USQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+77120+19280*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (19279); _SC_Out = ((T0Ind_NextLast)?12326:19279); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  Decision_S13__layer2_layer2_0_conv1_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115668 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _N_In;
	unsigned int _SN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 5][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 59136 (Total Size: 128000 )[Tile0, 5:[1x883, 3:1x883, 1x468], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 5:[1x883], 32]
		Tile0: [0, 28256, 28256], Tile1: [28256, 28256, 28256], Tile2; [56512, 28256, 28256]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 864 (Total Size: 128000 )[Tile0, 5:[1x1766, 3:1x1767, 1x937], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x1766, 3:1x1767, 1x937], 16][D0, [0 x 16, 16]]
		Tile0: [0, 28256, 28256], Tile1: [28240, 28272, 28272], Tile2; [56496, 28272, 28272]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57408 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57536 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57568 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57600 (Total Size: 1536 )[D1, [0 x 1536, 1536]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1536, 1536]]
		Tile0: [0, 1536, 1536], Tile1: [0, 1536, 1536], Tile2; [0, 1536, 1536]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 0 (Total Size: 864 )[Tile0, 5:[1x864, 3:1x864, 1x864], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x864, 3:1x864, 1x864], 1]
		Tile0: [0, 864, 864], Tile1: [0, 864, 864], Tile2; [0, 864, 864]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115648 (Total Size: 20 )[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->ColBuff = (unsigned char * __restrict__) (DecisionNet_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (DecisionNet_L1_Memory+57600);
	KerArg2->Bias = (int * __restrict__) (DecisionNet_L1_Memory+57408);
	KerArg2->Scale = (unsigned char * __restrict__) (DecisionNet_L1_Memory+57536);
	KerArg2->ScaleN = (unsigned char * __restrict__) (DecisionNet_L1_Memory+57568);
	KerArg2->Tile_InFeat = (unsigned short int) (16);
	KerArg2->TotalInFeatures = (unsigned short int) (16);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (2);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (1);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28256;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+864+0), 28256, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57600), 1536, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57408), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57536), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57568), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115648), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (28256-(16*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?937:1767)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-113008); _SN_In = (1767*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+864+28272*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (DecisionNet_L1_Memory+864+28272*((T0Ind_Total)%2));
				KerArg2->Out = (unsigned char * __restrict__) (DecisionNet_L1_Memory+59136+28256*((T0Ind_Total)%2));
				KerArg2->Tile_InW = (unsigned short int) (((T0Ind_Last)?937:1767)-1*(T0Ind==0));
				KerArg2->Tile_OutW = (unsigned short int) ((T0Ind_Last)?468:883);
				KerArg2->Pad = (v4s) ((v4s){1*(T0Ind==0),0*(T0Ind_Last),0,0});
				KerArg2->FirstTile = (unsigned char) ((T0Ind==0));
				KerArg2->W_Offset = (int) (((int *)(DecisionNet_L1_Memory+115648))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+59136+28256*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (28256); _SC_Out = (((T0Ind_NextLast)?468:883)*(32)); 
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
void  Decision_S16__layer2_layer2_0_conv2_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115604 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

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
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 5][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 1728 (Total Size: 128000 )[Tile0, 5:[1x864, 3:1x865, 1x549], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x864, 3:1x865, 1x549], 32][D0, [0 x 32, 32]]
		Tile0: [0, 27648, 27648], Tile1: [27584, 27680, 27680], Tile2; [55200, 27680, 27680]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1728 )[Tile0, 5:[1x1728, 3:1x1728, 1x1728], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x1728, 3:1x1728, 1x1728], 1]
		Tile0: [0, 1728, 1728], Tile1: [0, 1728, 1728], Tile2; [0, 1728, 1728]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57088 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57216 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57248 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57280 (Total Size: 3072 )[D1, [0 x 3072, 3072]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 3072, 3072]]
		Tile0: [0, 3072, 3072], Tile1: [0, 3072, 3072], Tile2; [0, 3072, 3072]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 60352 (Total Size: 128000 )[Tile0, 5:[1x863, 3:1x863, 1x548], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 5:[1x863], 32]
		Tile0: [0, 27616, 27616], Tile1: [27616, 27616, 27616], Tile2; [55232, 27616, 27616]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115584 (Total Size: 20 )[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->ColBuff = (unsigned char * __restrict__) (DecisionNet_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (DecisionNet_L1_Memory+57280);
	KerArg2->Bias = (int * __restrict__) (DecisionNet_L1_Memory+57088);
	KerArg2->Scale = (unsigned char * __restrict__) (DecisionNet_L1_Memory+57216);
	KerArg2->ScaleN = (unsigned char * __restrict__) (DecisionNet_L1_Memory+57248);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (32);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+1728+0), 27648, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=27616;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57280), 3072, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57088), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57216), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57248), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115584), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (27616-(32*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?550:865)*(32)); 
			} else if (!(1)) {
				_N_In = _N_In + (-110432); _SN_In = (865*(32)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+1728+27680*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (DecisionNet_L1_Memory+1728+27680*((T0Ind_Total)%2));
				KerArg2->Out = (unsigned char * __restrict__) (DecisionNet_L1_Memory+60352+27616*((T0Ind_Total)%2));
				KerArg2->Tile_InW = (unsigned short int) (((T0Ind_Last)?549:865)-1*(T0Ind==0));
				KerArg2->Tile_OutW = (unsigned short int) ((T0Ind_Last)?548:863);
				KerArg2->Pad = (v4s) ((v4s){1*(T0Ind==0),1*(T0Ind_Last),0,0});
				KerArg2->FirstTile = (unsigned char) ((T0Ind==0));
				KerArg2->W_Offset = (int) (((int *)(DecisionNet_L1_Memory+115584))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+60352+27616*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (27616); _SC_Out = (((T0Ind_NextLast)?548:863)*(32)); 
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
void  Decision_S19__layer2_layer2_0_shortcut_shortcut_0_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 114740 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _N_In;
	unsigned int _SN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 5][D0 Dim: Init: 16, Tiled: 1]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 57696 (Total Size: 128000 )[Tile0, 5:[1x891, 3:1x891, 1x436], 32][D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]][Tile0, 5:[1x891], 32]
		Tile0: [0, 28512, 28512], Tile1: [28512, 28512, 28512], Tile2; [57024, 28512, 28512]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 56992 (Total Size: 128 )[D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57120 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57152 (Total Size: 32 )[D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 57184 (Total Size: 512 )[D1, [0 x 512, 512]][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 512, 512]][D0, [0 x 16, 16]]
		Tile0: [0, 512, 512], Tile1: [0, 512, 512], Tile2; [0, 512, 512]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 128000 )[Tile0, 5:[1x1781, 3:1x1781, 1x871], 16][D0, [0 x 16, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x1781, 3:1x1781, 1x871], 16][D0, [0 x 16, 16]]
		Tile0: [0, 28496, 28496], Tile1: [28512, 28496, 28496], Tile2; [57024, 28496, 28496]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 114720 (Total Size: 20 )[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28512;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+0), 28496, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57184), 512, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+56992), 128, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57120), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57152), 32, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+114720), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (28512); _SN_In = (((T0Ind_NextLast)?871:1781)*(16)); 
			} else if (!(1)) {
				_N_In = _N_In + (-114048); _SN_In = (1781*(16)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+28496*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerConv1x1StrideS_NE16Seq(
					(unsigned char * __restrict__) (DecisionNet_L1_Memory+0+28496*((T0Ind_Total)%2)),  // In
					(unsigned char * __restrict__) (DecisionNet_L1_Memory+57696+28512*((T0Ind_Total)%2)),  // Out
					(int * __restrict__) (DecisionNet_L1_Memory+56992),  // Bias
					(unsigned char * __restrict__) (DecisionNet_L1_Memory+57184),  // Filter
					(unsigned char * __restrict__) (DecisionNet_L1_Memory+57120),  // Scale
					(unsigned char * __restrict__) (DecisionNet_L1_Memory+57152),  // ScaleN
					(unsigned int) (((16) % (16))?(((16) / (16)) + (1)):((16) / (16))),  // Nb_KI
					(unsigned int) (((16) % (16))?((16) % (16)):(16)),  // Rem_KI
					(unsigned int) (((32) % (32))?(((32) / (32)) + (1)):((32) / (32))),  // Nb_KO
					(unsigned int) (((32) % (32))?((32) % (32)):(32)),  // Rem_KO
					(unsigned int) (((1) % (3))?(((1) / (3)) + (1)):((1) / (3))),  // Nb_HO
					(unsigned int) ((1) % (3)),  // Rem_HO
					(unsigned int) ((((T0Ind_Last)?436:891) % (3))?((((T0Ind_Last)?436:891) / (3)) + (1)):(((T0Ind_Last)?436:891) / (3))),  // Nb_WO
					(unsigned int) (((T0Ind_Last)?436:891) % (3)),  // Rem_WO
					(unsigned int) ((1) % (3)),  // Rem_HI
					(unsigned int) (((T0Ind_Last)?871:1781) % (3)),  // Rem_WI
					(unsigned int) ((16) * (2)),  // InD0
					(unsigned int) (((16) * ((T0Ind_Last)?871:1781)) * (1)),  // InD1
					(unsigned int) (0),  // InD2
					(unsigned int) (16),  // WD0
					(unsigned int) (0),  // WD1
					(unsigned int) (0),  // WD2
					(unsigned int) (0),  // OutD0
					(unsigned int) ((32) * (1)),  // OutD1
					(unsigned int) (((32) * (1)) * ((T0Ind_Last)?436:891)),  // OutD2
					(v4s) 0,  // Pad
					(unsigned int) (0),  // PadVal
					(unsigned int) (((int *)(DecisionNet_L1_Memory+114720))[4]),  // WOffset
					(unsigned char) ((1)),  // LastD0
					(unsigned char) ((1)),  // FirstD0
					(unsigned int) (50364503)  // NE16JobCfg
				);
				NE16_FireJob(
				);
				NE16_WaitJob(
				);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+57696+28512*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (28512); _SC_Out = (((T0Ind_NextLast)?436:891)*(32)); 
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
void  Decision_S20__layer2_layer2_0_Add_fusion(
		unsigned char * __restrict__ In1,
		unsigned char * __restrict__ In2,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115696 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	KerMat3_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

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
		[Tile0 Dim: 7]
	Ker Arg: In1, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 7 logical tiles, 7 physical tiles
			@ 0 (Total Size: 128000 )[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		Tile0: [0, 19279, 19279], Tile1: [19279, 19279, 19279], Tile2; [38558, 19279, 19279]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 7 logical tiles, 7 physical tiles
			@ 38560 (Total Size: 128000 )[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		Tile0: [0, 19279, 19279], Tile1: [19279, 19279, 19279], Tile2; [38558, 19279, 19279]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 7 logical tiles, 7 physical tiles
			@ 77120 (Total Size: 128000 )[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		Tile0: [0, 19279, 19279], Tile1: [19279, 19279, 19279], Tile2; [38558, 19279, 19279]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 7 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 14 )[Tile0, 7:[1x1, 5:1x1, 1x1], 14]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x1, 5:1x1, 1x1], 14]
		Tile0: [0, 14, 14], Tile1: [0, 14, 14], Tile2; [0, 14, 14]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (signed char *__restrict__) (DecisionNet_L1_Memory+115680);
	KerArg0->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+0), 19279, 0, DmaR_Evt1);
	_N_In1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+38560+0), 19279, 0, DmaR_Evt2);
	_N_In2=0;
	_C_Out=0; _SC_Out=19279;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115680), 14, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<7; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==6), T0Ind_NextLast = ((T0Ind+1)==6);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(T0Ind_Last)) {
			_N_In1 = _N_In1 + (19279); _SN_In1 = ((T0Ind_NextLast)?12326:19279); 
		}
		_SN_In2 = 0;
		if (!(T0Ind_Last)) {
			_N_In2 = _N_In2 + (19279); _SN_In2 = ((T0Ind_NextLast)?12326:19279); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+19280*((T0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 */
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+_N_In2), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+38560+19280*((T0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In1 = (signed char *__restrict__) (DecisionNet_L1_Memory+0+19280*((T0Ind_Total)%2));
		KerArg0->In2 = (signed char *__restrict__) (DecisionNet_L1_Memory+38560+19280*((T0Ind_Total)%2));
		KerArg0->Out = (signed char *__restrict__) (DecisionNet_L1_Memory+77120+19280*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?12326:19279);
		AT_FORK(gap_ncore(), (void *) KerMatAdd_USQ8, (void *) KerArg0);
		__CALL(KerMatAdd_USQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+77120+19280*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (19279); _SC_Out = ((T0Ind_NextLast)?12326:19279); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  Decision_S23__layer3_layer3_0_conv1_Conv_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115604 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _N_In;
	unsigned int _SN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 64, Tiled: 1][Tile0 Dim: 5][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 61952 (Total Size: 128000 )[Tile0, 5:[1x419, 3:1x419, 1x324], 64][D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][Tile0, 5:[1x419], 64]
		Tile0: [0, 26816, 26816], Tile1: [26816, 26816, 26816], Tile2; [53632, 26816, 26816]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 1728 (Total Size: 128000 )[Tile0, 5:[1x838, 3:1x839, 1x649], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x838, 3:1x839, 1x649], 32][D0, [0 x 32, 32]]
		Tile0: [0, 26816, 26816], Tile1: [26784, 26848, 26848], Tile2; [53600, 26848, 26848]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 55424 (Total Size: 256 )[D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 55680 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 55744 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 55808 (Total Size: 6144 )[D1, [0 x 6144, 6144]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 6144, 6144]]
		Tile0: [0, 6144, 6144], Tile1: [0, 6144, 6144], Tile2; [0, 6144, 6144]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 0 (Total Size: 1728 )[Tile0, 5:[1x1728, 3:1x1728, 1x1728], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x1728, 3:1x1728, 1x1728], 1]
		Tile0: [0, 1728, 1728], Tile1: [0, 1728, 1728], Tile2; [0, 1728, 1728]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115584 (Total Size: 20 )[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->ColBuff = (unsigned char * __restrict__) (DecisionNet_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (DecisionNet_L1_Memory+55808);
	KerArg2->Bias = (int * __restrict__) (DecisionNet_L1_Memory+55424);
	KerArg2->Scale = (unsigned char * __restrict__) (DecisionNet_L1_Memory+55680);
	KerArg2->ScaleN = (unsigned char * __restrict__) (DecisionNet_L1_Memory+55744);
	KerArg2->Tile_InFeat = (unsigned short int) (32);
	KerArg2->TotalInFeatures = (unsigned short int) (32);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (64);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (2);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (1);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=26816;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+1728+0), 26816, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+55808), 6144, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+55424), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+55680), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+55744), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115584), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (26816-(32*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?649:839)*(32)); 
			} else if (!(1)) {
				_N_In = _N_In + (-107232); _SN_In = (839*(32)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+1728+26848*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (DecisionNet_L1_Memory+1728+26848*((T0Ind_Total)%2));
				KerArg2->Out = (unsigned char * __restrict__) (DecisionNet_L1_Memory+61952+26816*((T0Ind_Total)%2));
				KerArg2->Tile_InW = (unsigned short int) (((T0Ind_Last)?649:839)-1*(T0Ind==0));
				KerArg2->Tile_OutW = (unsigned short int) ((T0Ind_Last)?324:419);
				KerArg2->Pad = (v4s) ((v4s){1*(T0Ind==0),0*(T0Ind_Last),0,0});
				KerArg2->FirstTile = (unsigned char) ((T0Ind==0));
				KerArg2->W_Offset = (int) (((int *)(DecisionNet_L1_Memory+115584))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+61952+26816*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (26816); _SC_Out = (((T0Ind_NextLast)?324:419)*(64)); 
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
void  Decision_S26__layer3_layer3_0_conv2_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115476 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	KerConv_MM_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

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
		[D1 Dim: Init: 64, Tiled: 1][Tile0 Dim: 6][D0 Dim: Init: 64, Tiled: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 3456 (Total Size: 128000 )[Tile0, 6:[1x388, 4:1x389, 1x66], 64][D0, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 6:[1x388, 4:1x389, 1x66], 64][D0, [0 x 64, 64]]
		Tile0: [0, 24832, 24832], Tile1: [24704, 24896, 24896], Tile2; [49472, 24896, 24896]
	Ker Arg: ColBuff, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 6 logical tiles, 1 physical tiles
			@ 0 (Total Size: 3456 )[Tile0, 6:[1x3456, 4:1x3456, 1x3456], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 6:[1x3456, 4:1x3456, 1x3456], 1]
		Tile0: [0, 3456, 3456], Tile1: [0, 3456, 3456], Tile2; [0, 3456, 3456]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 53248 (Total Size: 256 )[D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 53504 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 53568 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 53632 (Total Size: 12288 )[D1, [0 x 12288, 12288]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 12288, 12288]]
		Tile0: [0, 12288, 12288], Tile1: [0, 12288, 12288], Tile2; [0, 12288, 12288]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 6 logical tiles, 6 physical tiles
			@ 65920 (Total Size: 128000 )[Tile0, 6:[1x387, 4:1x387, 1x65], 64][D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][Tile0, 6:[1x387], 64]
		Tile0: [0, 24768, 24768], Tile1: [24768, 24768, 24768], Tile2; [49536, 24768, 24768]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 6 logical tiles, 1 physical tiles
			@ 115456 (Total Size: 20 )[Tile0, 6:[1x20, 4:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 6:[1x20, 4:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->ColBuff = (unsigned char * __restrict__) (DecisionNet_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (DecisionNet_L1_Memory+53632);
	KerArg2->Bias = (int * __restrict__) (DecisionNet_L1_Memory+53248);
	KerArg2->Scale = (unsigned char * __restrict__) (DecisionNet_L1_Memory+53504);
	KerArg2->ScaleN = (unsigned char * __restrict__) (DecisionNet_L1_Memory+53568);
	KerArg2->Tile_InFeat = (unsigned short int) (64);
	KerArg2->TotalInFeatures = (unsigned short int) (64);
	KerArg2->Tile_InH = (unsigned short int) (1);
	KerArg2->Tile_OutFeat = (unsigned short int) (64);
	KerArg2->Tile_OutH = (unsigned short int) (1);
	KerArg2->Pad_Val = (unsigned short int) (0);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (50364503);
	KerArg2->Fx = (unsigned short) (3);
	KerArg2->Sx = (unsigned short) (1);
	KerArg2->Sy = (unsigned char) (1);
	KerArg2->Orientation = (unsigned char) (1);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+3456+0), 24832, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=24768;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+53632), 12288, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+53248), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+53504), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+53568), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115456), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
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
				_N_In = _N_In + (24768-(64*(T0Ind==0))); _SN_In = (((T0Ind_NextLast)?67:389)*(64)); 
			} else if (!(1)) {
				_N_In = _N_In + (-123776); _SN_In = (389*(64)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+3456+24896*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->In = (unsigned char * __restrict__) (DecisionNet_L1_Memory+3456+24896*((T0Ind_Total)%2));
				KerArg2->Out = (unsigned char * __restrict__) (DecisionNet_L1_Memory+65920+24768*((T0Ind_Total)%2));
				KerArg2->Tile_InW = (unsigned short int) (((T0Ind_Last)?66:389)-1*(T0Ind==0));
				KerArg2->Tile_OutW = (unsigned short int) ((T0Ind_Last)?65:387);
				KerArg2->Pad = (v4s) ((v4s){1*(T0Ind==0),1*(T0Ind_Last),0,0});
				KerArg2->FirstTile = (unsigned char) ((T0Ind==0));
				KerArg2->W_Offset = (int) (((int *)(DecisionNet_L1_Memory+115456))[4]);
				AT_FORK_CC(gap_ncore(), (void *) Ker_MM_Conv1DSmallv2_NE16, (void *) KerArg2);
				__CALL(Ker_MM_Conv1DSmallv2_NE16, KerArg2);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+65920+24768*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (24768); _SC_Out = (((T0Ind_NextLast)?65:387)*(64)); 
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
void  Decision_S29__layer3_layer3_0_shortcut_shortcut_0_Conv(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115284 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _N_In;
	unsigned int _SN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 64, Tiled: 1][Tile0 Dim: 5][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: Out, Tiled Space: D1
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 58816 (Total Size: 128000 )[Tile0, 5:[1x441, 3:1x441, 1x236], 64][D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][Tile0, 5:[1x441], 64]
		Tile0: [0, 28224, 28224], Tile1: [28224, 28224, 28224], Tile2; [56448, 28224, 28224]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 56384 (Total Size: 256 )[D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 56640 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 56704 (Total Size: 64 )[D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 56768 (Total Size: 2048 )[D1, [0 x 2048, 2048]][D0, [0 x 2048, 2048]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 2048, 2048]][D0, [0 x 2048, 2048]]
		Tile0: [0, 2048, 2048], Tile1: [0, 2048, 2048], Tile2; [0, 2048, 2048]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 5 physical tiles
			@ 0 (Total Size: 128000 )[Tile0, 5:[1x881, 3:1x881, 1x471], 32][D0, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x881, 3:1x881, 1x471], 32][D0, [0 x 32, 32]]
		Tile0: [0, 28192, 28192], Tile1: [28224, 28192, 28192], Tile2; [56448, 28192, 28192]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 5 logical tiles, 1 physical tiles
			@ 115264 (Total Size: 20 )[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 5:[1x20, 3:1x20, 1x20], 1]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=28224;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+0), 28192, 0, DmaR_Evt1);
	_N_In=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+56768), 2048, 0, DmaR_Evt2);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+56384), 256, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+56640), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+56704), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115264), 20, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_D1_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1, D1Ind_NextLast = 1;
		for (T0Ind=0; T0Ind<5; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==4), T0Ind_NextLast = ((T0Ind+1)==4);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (28224); _SN_In = (((T0Ind_NextLast)?471:881)*(32)); 
			} else if (!(1)) {
				_N_In = _N_In + (-112896); _SN_In = (881*(32)); 
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+28192*((T0Ind_Total+1)%2)),
						1*(_SN_In), 0, DmaR_Evt1);
			}
			/*============================= End Read Tiles ======================================*/
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerConv1x1StrideS_NE16Seq(
					(unsigned char * __restrict__) (DecisionNet_L1_Memory+0+28192*((T0Ind_Total)%2)),  // In
					(unsigned char * __restrict__) (DecisionNet_L1_Memory+58816+28224*((T0Ind_Total)%2)),  // Out
					(int * __restrict__) (DecisionNet_L1_Memory+56384),  // Bias
					(unsigned char * __restrict__) (DecisionNet_L1_Memory+56768),  // Filter
					(unsigned char * __restrict__) (DecisionNet_L1_Memory+56640),  // Scale
					(unsigned char * __restrict__) (DecisionNet_L1_Memory+56704),  // ScaleN
					(unsigned int) (((32) % (16))?(((32) / (16)) + (1)):((32) / (16))),  // Nb_KI
					(unsigned int) (((32) % (16))?((32) % (16)):(16)),  // Rem_KI
					(unsigned int) (((64) % (32))?(((64) / (32)) + (1)):((64) / (32))),  // Nb_KO
					(unsigned int) (((64) % (32))?((64) % (32)):(32)),  // Rem_KO
					(unsigned int) (((1) % (3))?(((1) / (3)) + (1)):((1) / (3))),  // Nb_HO
					(unsigned int) ((1) % (3)),  // Rem_HO
					(unsigned int) ((((T0Ind_Last)?236:441) % (3))?((((T0Ind_Last)?236:441) / (3)) + (1)):(((T0Ind_Last)?236:441) / (3))),  // Nb_WO
					(unsigned int) (((T0Ind_Last)?236:441) % (3)),  // Rem_WO
					(unsigned int) ((1) % (3)),  // Rem_HI
					(unsigned int) (((T0Ind_Last)?471:881) % (3)),  // Rem_WI
					(unsigned int) ((32) * (2)),  // InD0
					(unsigned int) (((32) * ((T0Ind_Last)?471:881)) * (1)),  // InD1
					(unsigned int) (0),  // InD2
					(unsigned int) (16),  // WD0
					(unsigned int) (0),  // WD1
					(unsigned int) (0),  // WD2
					(unsigned int) (0),  // OutD0
					(unsigned int) ((64) * (1)),  // OutD1
					(unsigned int) (((64) * (1)) * ((T0Ind_Last)?236:441)),  // OutD2
					(v4s) 0,  // Pad
					(unsigned int) (0),  // PadVal
					(unsigned int) (((int *)(DecisionNet_L1_Memory+115264))[4]),  // WOffset
					(unsigned char) ((1)),  // LastD0
					(unsigned char) ((1)),  // FirstD0
					(unsigned int) (50364503)  // NE16JobCfg
				);
				NE16_FireJob(
				);
				NE16_WaitJob(
				);
			} /* End iteration on D0 */
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+58816+28224*((T0Ind_Total)%2)),
					_SC_Out, 1, DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (28224); _SC_Out = (((T0Ind_NextLast)?236:441)*(64)); 
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
void  Decision_S30__layer3_layer3_0_Add_fusion(
		unsigned char * __restrict__ In1,
		unsigned char * __restrict__ In2,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 115696 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	KerMat3_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

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
		[Tile0 Dim: 7]
	Ker Arg: In1, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 7 logical tiles, 7 physical tiles
			@ 0 (Total Size: 128000 )[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		Tile0: [0, 19279, 19279], Tile1: [19279, 19279, 19279], Tile2; [38558, 19279, 19279]
	Ker Arg: In2, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 7 logical tiles, 7 physical tiles
			@ 38560 (Total Size: 128000 )[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		Tile0: [0, 19279, 19279], Tile1: [19279, 19279, 19279], Tile2; [38558, 19279, 19279]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 1
		KerArgItSpace: 7 logical tiles, 7 physical tiles
			@ 77120 (Total Size: 128000 )[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x19279, 5:1x19279, 1x12326], 1]
		Tile0: [0, 19279, 19279], Tile1: [19279, 19279, 19279], Tile2; [38558, 19279, 19279]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 7 logical tiles, 1 physical tiles
			@ 115680 (Total Size: 14 )[Tile0, 7:[1x1, 5:1x1, 1x1], 14]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 7:[1x1, 5:1x1, 1x1], 14]
		Tile0: [0, 14, 14], Tile1: [0, 14, 14], Tile2; [0, 14, 14]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->DoScale = (unsigned char) (1);
	KerArg0->Infos = (signed char *__restrict__) (DecisionNet_L1_Memory+115680);
	KerArg0->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+0), 19279, 0, DmaR_Evt1);
	_N_In1=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+38560+0), 19279, 0, DmaR_Evt2);
	_N_In2=0;
	_C_Out=0; _SC_Out=19279;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+115680), 14, 0, DmaR_Evt3);
	AT_L2_WAIT(0, DmaR_Evt3); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<7; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==6), T0Ind_NextLast = ((T0Ind+1)==6);
		/*================================= Prepare Tiles ===================================*/
		_SN_In1 = 0;
		if (!(T0Ind_Last)) {
			_N_In1 = _N_In1 + (19279); _SN_In1 = ((T0Ind_NextLast)?12326:19279); 
		}
		_SN_In2 = 0;
		if (!(T0Ind_Last)) {
			_N_In2 = _N_In2 + (19279); _SN_In2 = ((T0Ind_NextLast)?12326:19279); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In1 */
		if (_SN_In1) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In1+_N_In1), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+19280*((T0Ind_Total+1)%2)),
					1*(_SN_In1), 0, DmaR_Evt1);
		}
		AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read In2 */
		if (_SN_In2) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In2+_N_In2), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+38560+19280*((T0Ind_Total+1)%2)),
					1*(_SN_In2), 0, DmaR_Evt2);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In1 = (signed char *__restrict__) (DecisionNet_L1_Memory+0+19280*((T0Ind_Total)%2));
		KerArg0->In2 = (signed char *__restrict__) (DecisionNet_L1_Memory+38560+19280*((T0Ind_Total)%2));
		KerArg0->Out = (signed char *__restrict__) (DecisionNet_L1_Memory+77120+19280*((T0Ind_Total)%2));
		KerArg0->Feat = (unsigned short int) (T0Ind_Last?12326:19279);
		AT_FORK(gap_ncore(), (void *) KerMatAdd_USQ8, (void *) KerArg0);
		__CALL(KerMatAdd_USQ8, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+77120+19280*((T0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(T0Ind_Last)) {
			_C_Out = _C_Out + (19279); _SC_Out = ((T0Ind_NextLast)?12326:19279); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  Decision_S31__gap_MaxPool(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 96064 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	Ker_MM_Pool_USQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _LN_In;
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 64, Tiled: 3][Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 0 (Total Size: 128000 )[Tile0, 1:[2000x1], 64][D0, [2 x 24, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [2 x 24, 16]][Tile0, 1:[2000x1, 1:2000x1, 2000x1], 64]
		Tile0: [0, 48000, 24], Tile1: [24, 48000, 24], Tile2; [48, 32000, 16]
	Ker Arg: Out, Tiled Space: D0
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 3 logical tiles, 3 physical tiles
			@ 96000 (Total Size: 64 )[Tile0, 1:[1x1], 64][D0, [2 x 24, 16]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [2 x 24, 16]][Tile0, 1:[1x1, 1:1x1, 1x1], 64]
		Tile0: [0, 24, 24], Tile1: [24, 24, 24], Tile2; [48, 16, 16]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 96048 (Total Size: 13 )[Tile0, 1:[13x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[13x1], 1]
		Tile0: [0, 13, 13], Tile1: [0, 13, 13], Tile2; [0, 13, 13]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (2000);
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Fx = (unsigned short int) (2000);
	KerArg0->Fy = (unsigned short int) (1);
	KerArg0->Sx = (unsigned char) (2000);
	KerArg0->Sy = (unsigned char) (1);
	KerArg0->FirstTile = (unsigned char) ((1));
	KerArg0->Pad = (v4s) 0;
	KerArg0->Wo = (unsigned short int) (1);
	KerArg0->Ho = (unsigned short int) (1);
	KerArg0->Infos = (signed char * __restrict__) (DecisionNet_L1_Memory+96048);
	KerArg0->Extra = (void *) (0);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+0), 48000, 64, 24, 0, DmaR_Evt1);
	_N_In=0;
	_C_Out=0; _SC_Out=24;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+96048), 13, 0, DmaR_Evt2);
	AT_L2_WAIT(0, DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D0Ind=0; D0Ind<3; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
		int D0Ind_Last = (D0Ind==2), D0Ind_NextLast = ((D0Ind+1)==2);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(D0Ind_Last)) {
			_N_In = _N_In + (24); _LN_In = ((D0Ind_NextLast)?16:24); _SN_In = (2000*_LN_In); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0+48000*((D0Ind_Total+1)%2)),
					1*(_SN_In), 64, _LN_In, 0, DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg0->In = (unsigned char * __restrict__) (DecisionNet_L1_Memory+0+48000*((D0Ind_Total)%2));
			KerArg0->Out = (unsigned char * __restrict__) (DecisionNet_L1_Memory+96000+24*((D0Ind_Total)%2));
			KerArg0->Feat = (unsigned short int) ((D0Ind_Last)?16:24);
			AT_FORK(gap_ncore(), (void *) KerParMaxPoolNxMStrideSxSy_HWC_USQ8, (void *) KerArg0);
			__CALL(KerParMaxPoolNxMStrideSxSy_HWC_USQ8, KerArg0);
		} /* End iteration on Tile0 */
		/*================================= Write Tiles =====================================*/
		if (_SP_Out) AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
		AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+96000+24*((D0Ind_Total)%2)),
				_SC_Out, 1, DmaW_Evt1);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SP_Out = _SC_Out;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out = 0;
		if (!(D0Ind_Last)) {
			_C_Out = _C_Out + (24); _SC_Out = (1*((D0Ind_NextLast)?16:24)); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void  Decision_S35__fc_Gemm_fusion(
		unsigned char * __restrict__ In,
		unsigned char * __restrict__ Filter,
		int * __restrict__ Bias,
		unsigned char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		signed char * __restrict__ ScaleN,
		signed char * __restrict__ Infos,
		unsigned char * __restrict__ SigmoidLUT_u8)

{
	/* Shared L1: 548 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT _DmaR_Evt4, *DmaR_Evt4 = &_DmaR_Evt4;
	AT_L2_EVENT _DmaR_Evt2, *DmaR_Evt2 = &_DmaR_Evt2;
	AT_L2_EVENT _DmaW_Evt1, *DmaW_Evt1 = &_DmaW_Evt1;
	AT_L2_EVENT _DmaR_Evt3, *DmaR_Evt3 = &_DmaR_Evt3;
	AT_L2_EVENT _DmaR_Evt1, *DmaR_Evt1 = &_DmaR_Evt1;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF2, *UchanMRF2 = &_UchanMRF2;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF3, *UchanMRF3 = &_UchanMRF3;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF1, *UchanMRF1 = &_UchanMRF1;
	KerLinear_NE16_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	int D1Ind, D1Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1][D1 Dim: Init: 1, Tiled: 1][D0 Dim: Init: 64, Tiled: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 0 (Total Size: 64 )[D0, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 64 (Total Size: 64 )[D1, [0 x 64, 64]][D0, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]][D0, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 128 (Total Size: 4 )[D1, [0 x 4, 4]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4, 4]]
		Tile0: [0, 4, 4], Tile1: [0, 4, 4], Tile2; [0, 4, 4]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 132 (Total Size: 1 )[D1, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 136 (Total Size: 1 )[D1, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 140 (Total Size: 1 )[D1, [0 x 1, 1]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1, 1]]
		Tile0: [0, 1, 1], Tile1: [0, 1, 1], Tile2; [0, 1, 1]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 144 (Total Size: 20 )[Tile0, 1:[1x1], 20]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 20]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: BuffOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 164 (Total Size: 256 )[Tile0, 1:[32x1], 8]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[32x1], 8]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: SigmoidLUT_u8, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			@ 420 (Total Size: 128 )[Tile0, 1:[128x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[128x1], 1]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg2->In = (signed char * __restrict__) (DecisionNet_L1_Memory+0);
	KerArg2->Filter = (unsigned short * __restrict__) (DecisionNet_L1_Memory+64);
	KerArg2->Bias = (int * __restrict__) (DecisionNet_L1_Memory+128);
	KerArg2->Out = (int * __restrict__) (DecisionNet_L1_Memory+132);
	KerArg2->Scale = (unsigned char * __restrict__) (DecisionNet_L1_Memory+136);
	KerArg2->ScaleN = (unsigned char * __restrict__) (DecisionNet_L1_Memory+140);
	KerArg2->Tile_InFeat = (unsigned short int) (64);
	KerArg2->Tile_OutFeat = (unsigned short int) (1);
	KerArg2->LastD0 = (unsigned char) ((1));
	KerArg2->FirstD0 = (unsigned char) ((1));
	KerArg2->Qw = (unsigned char) (8);
	KerArg2->Default_NE16_Job_Cfg = (unsigned int) (62947575);
	KerArg2->BuffOut = (int * __restrict__) (DecisionNet_L1_Memory+164);
	KerArg2->Infos = (unsigned char * __restrict__) (DecisionNet_L1_Memory+144);
	KerArg2->Extra = (void * __restrict__) (DecisionNet_L1_Memory+420);
	/*================================= Read Tiles Prolog ===============================*/
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) SigmoidLUT_u8+0), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+0+0), 128, 0, UchanMRF1);
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF1); /* Wait previous uDMA read SigmoidLUT_u8 */
	AT_L2_COPY(0, ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+0+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+420), 128, 0, DmaR_Evt1);
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) Filter+0), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+128+0), 64, 0, UchanMRF2);
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF2); /* Wait previous uDMA read Filter */
	AT_L2_COPY_MERGED(0, ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+128+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+64), 64, 0, 0);
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) Infos+0), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+192+0), 20, 0, UchanMRF3);
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF3); /* Wait previous uDMA read Infos */
	AT_L2_COPY_MERGED(0, ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn+192+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+144), 20, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+0), 64, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+128), 4, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+136), 1, 0, 0);
	AT_L2_COPY_MERGED(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+140), 1, 0, 0);
	AT_L2_WAIT(0, DmaR_Evt1); /* Wait previous DMA read ScaleN */
	/*============================= End Read Tiles Prolog ===============================*/
	/*====================== Call Kernel LOC_PROLOG =========================*/
	NE16_Enable(
	);
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		{ /* Single iteration on D1 */
			int D1Ind_Last = 1;
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				NE16_SoftReset(
				);
				KerArg2->W_Offset = (int) (((int *)(DecisionNet_L1_Memory+144))[4]);
				AT_FORK_CC(gap_ncore(), (void *) KerLinear_8aSigmoid_NE16, (void *) KerArg2);
				__CALL(KerLinear_8aSigmoid_NE16, KerArg2);
			} /* End iteration on D0 */
		} /* End iteration on D1 */
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) DecisionNet_L1_Memory+132), 1, 1, DmaW_Evt1);
	AT_L2_WAIT(0, DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
	/*====================== Call Kernel LOC_EPILOG =========================*/
	NE16_Disable(
	);
}
#pragma GCC diagnostic pop
int  DecisionNetCNN_Construct()

{
	int Error;

	AT_EMRAMFLASH_FS_CONF_T EmramFlashConf;
	AT_EMRAMFLASH_FS_CONF_INIT(&EmramFlashConf, AT_MEM_L3_MRAMFLASH, 0);
	AT_EMRAMFLASH_FS_OPEN(&EmramFlash, &EmramFlashConf, 0, "DecisionNet_L3_Flash_Const.dat", &Error);
	if (Error) return AT_FLASH_OPEN_ERROR;

	DecisionNet_L3_Memory = main_1_L3_Memory_Dyn+2138240+1677696+296064;

	DecisionNet_L2_Memory_Dyn = main_1_L2_Memory_Dyn;
	if (DecisionNet_L2_Memory_Dyn == 0) return AT_L2_OPEN_ERROR;
	DecisionNet_L1_Memory = main_1_L1_Memory;
	if (DecisionNet_L1_Memory == 0) return AT_L1_OPEN_ERROR;
	return AT_NO_ERROR;
}
void DecisionNetCNN_ConstructCluster()

{
}
int  DecisionNetCNN_Destruct()

{
	AT_L2_FREE(0, DecisionNet_L2_Memory_Dyn, 403240);
	AT_L1_FREE(0, DecisionNet_L1_Memory, 115696);
	AT_EMRAMFLASH_FS_CLOSE(&EmramFlash);
	return 0;
}
int DecisionNetCNN_Memory(AT_MEM_TYPE Which)

{
	switch (Which) {
		case AT_L1_MEM:     return 115696; /* L1 Memory */
		case AT_L2_MEM:     return 0; /* L2 Memory, permanent */
		case AT_L2_DYN_MEM: return 403240; /* L2 Memory, dynamic */
		case AT_L3_MEM:     return 0; /* L3 Memory, permanent */
		case AT_L3_DYN_MEM: return 0; /* L3 Memory, dynamic */
		default:            return 0;
	}
}
unsigned int Decision_AT_GraphPerf[15];
unsigned int Decision_AT_GraphPerf_CNN_Total = 0;
unsigned int Decision_AT_GraphOperInfosNames[15] = {
	384000,
	6144000,
	6144000,
	128000,
	6144000,
	12288000,
	2048000,
	128000,
	12288000,
	24576000,
	4096000,
	128000,
	128000,
	65,
	0,
};
char *Decision_AT_GraphNodeNames[15] = {
	"Decision_S3__conv1_Conv_fusion",
	"Decision_S6__layer1_layer1_0_conv1_Conv_fusion",
	"Decision_S9__layer1_layer1_0_conv2_Conv",
	"Decision_S10__layer1_layer1_0_Add_fusion",
	"Decision_S13__layer2_layer2_0_conv1_Conv_fusion",
	"Decision_S16__layer2_layer2_0_conv2_Conv",
	"Decision_S19__layer2_layer2_0_shortcut_shortcut_0_Conv",
	"Decision_S20__layer2_layer2_0_Add_fusion",
	"Decision_S23__layer3_layer3_0_conv1_Conv_fusion",
	"Decision_S26__layer3_layer3_0_conv2_Conv",
	"Decision_S29__layer3_layer3_0_shortcut_shortcut_0_Conv",
	"Decision_S30__layer3_layer3_0_Add_fusion",
	"Decision_S31__gap_MaxPool",
	"Decision_S35__fc_Gemm_fusion",
	"IO_Wait",
};
int  DecisionNetCNN(
		unsigned char * __restrict__ Input_1,
		unsigned char * __restrict__ Output_1)

{
	unsigned int Start_IO;
	Decision_AT_GraphPerf_CNN_Total = gap_cl_readhwtimer();
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF0, *UchanMRF0 = &_UchanMRF0;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF1, *UchanMRF1 = &_UchanMRF1;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF2, *UchanMRF2 = &_UchanMRF2;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF3, *UchanMRF3 = &_UchanMRF3;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF4, *UchanMRF4 = &_UchanMRF4;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF5, *UchanMRF5 = &_UchanMRF5;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF6, *UchanMRF6 = &_UchanMRF6;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF7, *UchanMRF7 = &_UchanMRF7;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF8, *UchanMRF8 = &_UchanMRF8;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF9, *UchanMRF9 = &_UchanMRF9;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF10, *UchanMRF10 = &_UchanMRF10;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF11, *UchanMRF11 = &_UchanMRF11;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF12, *UchanMRF12 = &_UchanMRF12;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF13, *UchanMRF13 = &_UchanMRF13;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF14, *UchanMRF14 = &_UchanMRF14;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF15, *UchanMRF15 = &_UchanMRF15;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF16, *UchanMRF16 = &_UchanMRF16;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF17, *UchanMRF17 = &_UchanMRF17;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF18, *UchanMRF18 = &_UchanMRF18;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF19, *UchanMRF19 = &_UchanMRF19;
	AT_EMRAMFLASH_FS_CL_EVENT _UchanMRF20, *UchanMRF20 = &_UchanMRF20;
	/* Moving _conv1_conv_weights (1/1), size 256 from eMRAM at 27136 to (size 256) L2 at 6784 using event 0 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 27136), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 6784), 256, 0, UchanMRF0);
	/* Moving Constant_onnx__conv_92 (1/1), size 64 from eMRAM at 28672 to (size 64) L2 at 7040 using event 1 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 28672), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 7040), 64, 0, UchanMRF1);
	/* Moving Decision_S3_Mul_scale (1/1), size 16 from eMRAM at 29704 to (size 16) L2 at 7124 using event 2 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29704), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 7124), 16, 0, UchanMRF2);
	/* Moving Decision_S3_Mul_shift (1/1), size 16 from eMRAM at 29720 to (size 16) L2 at 7140 using event 3 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29720), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 7140), 16, 0, UchanMRF3);
	/* Moving Decision_S3_Infos (1/1), size 20 from eMRAM at 29504 to (size 20) L2 at 7104 using event 4 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29504), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 7104), 20, 0, UchanMRF4);

	

	
	/* Moving _layer1_layer1_0_conv1_conv_weights (1/1), size 768 from eMRAM at 25088 to (size 768) L2 at 128000 using event 5 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 25088), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 128000), 768, 0, UchanMRF5);
	/* Moving Constant_onnx__conv_95 (1/1), size 64 from eMRAM at 28736 to (size 64) L2 at 128768 using event 6 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 28736), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 128768), 64, 0, UchanMRF6);
	/* Moving Decision_S6_Mul_scale (1/1), size 16 from eMRAM at 29736 to (size 16) L2 at 128852 using event 7 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29736), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 128852), 16, 0, UchanMRF7);
	/* Moving Decision_S6_Mul_shift (1/1), size 16 from eMRAM at 29752 to (size 16) L2 at 128868 using event 8 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29752), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 128868), 16, 0, UchanMRF8);
	/* Moving Decision_S6_Infos (1/1), size 20 from eMRAM at 29524 to (size 20) L2 at 128832 using event 9 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29524), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 128832), 20, 0, UchanMRF9);


	/* Waiting completion of transfer of _layer1_layer1_0_conv1_conv_weights using event 5 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF5);
	/* Waiting completion of transfer of Constant_onnx__conv_95 using event 6 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF6);
	/* Waiting completion of transfer of Decision_S6_Mul_scale using event 7 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF7);
	/* Waiting completion of transfer of Decision_S6_Mul_shift using event 8 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF8);
	/* Waiting completion of transfer of Decision_S6_Infos using event 9 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF9);

	
	/* Moving Decision_S9_Mul_scale (1/1), size 16 from eMRAM at 29768 to (size 16) L2 at 384852 using event 10 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29768), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384852), 16, 0, UchanMRF10);
	/* Moving Decision_S9_Mul_shift (1/1), size 16 from eMRAM at 29784 to (size 16) L2 at 384868 using event 11 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29784), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384868), 16, 0, UchanMRF11);
	/* Moving Decision_S9_Infos (1/1), size 20 from eMRAM at 29544 to (size 20) L2 at 384832 using event 12 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29544), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384832), 20, 0, UchanMRF12);
	/* Moving Decision_S10_Infos (1/1), size 14 from eMRAM at 29800 to (size 14) L2 at 384884 using event 13 */

	/* Waiting completion of transfer of Decision_S9_Mul_scale using event 10 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF10);
	/* Waiting completion of transfer of Decision_S9_Mul_shift using event 11 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF11);
	/* Waiting completion of transfer of Decision_S9_Infos using event 12 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF12);

	
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29800), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384884), 14, 0, UchanMRF13);
	/* Moving Decision_S13_Mul_scale (1/1), size 32 from eMRAM at 29312 to (size 32) L2 at 388864 using event 14 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29312), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 388864), 32, 0, UchanMRF14);
	/* Moving Decision_S13_Mul_shift (1/1), size 32 from eMRAM at 29344 to (size 32) L2 at 388896 using event 15 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29344), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 388896), 32, 0, UchanMRF15);
	/* Moving Decision_S13_Infos (1/1), size 20 from eMRAM at 29564 to (size 20) L2 at 388992 using event 16 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29564), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 388992), 20, 0, UchanMRF16);
	/* Moving Decision_S16_Mul_scale (1/1), size 32 from eMRAM at 29376 to (size 32) L2 at 388928 using event 17 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29376), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 388928), 32, 0, UchanMRF17);
	/* Moving Decision_S16_Infos (1/1), size 20 from eMRAM at 29584 to (size 20) L2 at 389012 using event 18 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29584), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 389012), 20, 0, UchanMRF18);
	/* Moving Decision_S23_Infos (1/1), size 20 from eMRAM at 29624 to (size 20) L2 at 403200 using event 19 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29624), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 403200), 20, 0, UchanMRF19);
	/* Moving Decision_S26_Infos (1/1), size 20 from eMRAM at 29644 to (size 20) L2 at 403220 using event 20 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29644), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 403220), 20, 0, UchanMRF20);
	Start_IO = gap_cl_readhwtimer();
	
	Decision_AT_GraphPerf[0] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] = 0;
	Decision_S3__conv1_Conv_fusion(
		((unsigned char * __restrict__) Input_1), /* In */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+6784)), /* Filter */
		((signed int * __restrict__) (DecisionNet_L2_Memory_Dyn+7040)), /* Bias */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+256000)), /* Out */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+7124)), /* Scale */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+7140)), /* ScaleN */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+7104)) /* Infos */
	);
	Decision_AT_GraphPerf[0] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[0];
	/* Moving _layer1_layer1_0_conv2_conv_weights (1/1), size 768 from eMRAM at 25856 to (size 768) L2 at 384000 using event 0 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 25856), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384000), 768, 0, UchanMRF0);
	/* Moving Constant_onnx__conv_98 (1/1), size 64 from eMRAM at 28800 to (size 64) L2 at 384768 using event 1 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 28800), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384768), 64, 0, UchanMRF1);
	/* Moving Decision_S16_Mul_shift (1/1), size 32 from eMRAM at 29408 to (size 32) L2 at 388960 using event 2 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29408), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 388960), 32, 0, UchanMRF2);
	/* Moving Decision_S23_Mul_scale (1/1), size 64 from eMRAM at 28864 to (size 64) L2 at 402944 using event 3 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 28864), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 402944), 64, 0, UchanMRF3);
	/* Moving Decision_S23_Mul_shift (1/1), size 64 from eMRAM at 28928 to (size 64) L2 at 403008 using event 4 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 28928), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 403008), 64, 0, UchanMRF4);
	Start_IO = gap_cl_readhwtimer();
	
	Decision_AT_GraphPerf[1] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[1] - Start_IO;
	Decision_S6__layer1_layer1_0_conv1_Conv_fusion(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+256000)), /* In */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* Filter */
		((signed int * __restrict__) (DecisionNet_L2_Memory_Dyn+128768)), /* Bias */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+0)), /* Out */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128852)), /* Scale */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+128868)), /* ScaleN */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+128832)) /* Infos */
	);
	Decision_AT_GraphPerf[1] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[1];
	/* Moving Constant_onnx__conv_101 (1/1), size 128 from eMRAM at 28160 to (size 128) L2 at 388608 using event 5 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 28160), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 388608), 128, 0, UchanMRF5);
	/* Moving Constant_onnx__conv_104 (1/1), size 128 from eMRAM at 28288 to (size 128) L2 at 388736 using event 6 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 28288), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 388736), 128, 0, UchanMRF6);
	/* Moving Decision_S26_Mul_scale (1/1), size 64 from eMRAM at 28992 to (size 64) L2 at 403072 using event 7 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 28992), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 403072), 64, 0, UchanMRF7);
	/* Moving Decision_S26_Mul_shift (1/1), size 64 from eMRAM at 29056 to (size 64) L2 at 403136 using event 8 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29056), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 403136), 64, 0, UchanMRF8);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _layer1_layer1_0_conv2_conv_weights using event 0 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF0);
	/* Waiting completion of transfer of Constant_onnx__conv_98 using event 1 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF1);
	
	Decision_AT_GraphPerf[2] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[2] - Start_IO;
	Decision_S9__layer1_layer1_0_conv2_Conv(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+384000)), /* Filter */
		((signed int * __restrict__) (DecisionNet_L2_Memory_Dyn+384768)), /* Bias */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* Out */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+384852)), /* Scale */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+384868)), /* ScaleN */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+384832)) /* Infos */
	);
	Decision_AT_GraphPerf[2] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[2];
	/* Moving _layer2_layer2_0_conv1_conv_weights (1/1), size 1536 from eMRAM at 23552 to (size 1536) L2 at 387072 using event 0 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 23552), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 387072), 1536, 0, UchanMRF0);
	/* Moving Constant_onnx__conv_110 (1/1), size 256 from eMRAM at 27392 to (size 256) L2 at 402432 using event 1 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 27392), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 402432), 256, 0, UchanMRF1);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of Decision_S10_Infos using event 13 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF13);
	Decision_AT_GraphPerf[3] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[3] - Start_IO;
	Decision_S10__layer1_layer1_0_Add_fusion(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* In1 */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+256000)), /* In2 */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+384884)) /* Infos */
	);
	Decision_AT_GraphPerf[3] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[3];
	/* Moving _layer2_layer2_0_conv2_conv_weights (1/1), size 3072 from eMRAM at 18432 to (size 3072) L2 at 384000 using event 9 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 18432), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384000), 3072, 0, UchanMRF9);
	/* Moving _layer3_layer3_0_conv1_conv_weights (1/1), size 6144 from eMRAM at 12288 to (size 6144) L2 at 396288 using event 10 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 12288), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 396288), 6144, 0, UchanMRF10);
	/* Moving Constant_onnx__conv_113 (1/1), size 256 from eMRAM at 27648 to (size 256) L2 at 402688 using event 11 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 27648), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 402688), 256, 0, UchanMRF11);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _layer2_layer2_0_conv1_conv_weights using event 0 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF0);
	/* Waiting completion of transfer of Constant_onnx__conv_101 using event 5 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF5);
	/* Waiting completion of transfer of Decision_S13_Mul_scale using event 14 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF14);
	/* Waiting completion of transfer of Decision_S13_Mul_shift using event 15 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF15);
	/* Waiting completion of transfer of Decision_S13_Infos using event 16 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF16);
	Decision_AT_GraphPerf[4] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[4] - Start_IO;
	Decision_S13__layer2_layer2_0_conv1_Conv_fusion(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+387072)), /* Filter */
		((signed int * __restrict__) (DecisionNet_L2_Memory_Dyn+388608)), /* Bias */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* Out */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+388864)), /* Scale */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+388896)), /* ScaleN */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+388992)) /* Infos */
	);
	Decision_AT_GraphPerf[4] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[4];
	/* Moving _layer2_layer2_0_shortcut_shortcut_0_conv_weights (1/1), size 512 from eMRAM at 26624 to (size 512) L2 at 387072 using event 0 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 26624), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 387072), 512, 0, UchanMRF0);
	/* Moving Constant_onnx__conv_107 (1/1), size 128 from eMRAM at 28416 to (size 128) L2 at 387584 using event 5 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 28416), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 387584), 128, 0, UchanMRF5);
	/* Moving Decision_S19_Mul_scale (1/1), size 32 from eMRAM at 29440 to (size 32) L2 at 387712 using event 12 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29440), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 387712), 32, 0, UchanMRF12);
	/* Moving Decision_S19_Mul_shift (1/1), size 32 from eMRAM at 29472 to (size 32) L2 at 387744 using event 13 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29472), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 387744), 32, 0, UchanMRF13);
	/* Moving Decision_S19_Infos (1/1), size 20 from eMRAM at 29604 to (size 20) L2 at 387776 using event 14 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29604), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 387776), 20, 0, UchanMRF14);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _layer2_layer2_0_conv2_conv_weights using event 9 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF9);
	/* Waiting completion of transfer of Constant_onnx__conv_104 using event 6 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF6);
	/* Waiting completion of transfer of Decision_S16_Mul_scale using event 17 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF17);
	/* Waiting completion of transfer of Decision_S16_Mul_shift using event 2 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF2);
	/* Waiting completion of transfer of Decision_S16_Infos using event 18 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF18);
	Decision_AT_GraphPerf[5] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[5] - Start_IO;
	Decision_S16__layer2_layer2_0_conv2_Conv(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* In */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+384000)), /* Filter */
		((signed int * __restrict__) (DecisionNet_L2_Memory_Dyn+388736)), /* Bias */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+256000)), /* Out */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+388928)), /* Scale */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+388960)), /* ScaleN */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+389012)) /* Infos */
	);
	Decision_AT_GraphPerf[5] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[5];
	/* Moving Decision_S20_Infos (1/1), size 14 from eMRAM at 29816 to (size 14) L2 at 384000 using event 2 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29816), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384000), 14, 0, UchanMRF2);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _layer2_layer2_0_shortcut_shortcut_0_conv_weights using event 0 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF0);
	/* Waiting completion of transfer of Constant_onnx__conv_107 using event 5 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF5);
	/* Waiting completion of transfer of Decision_S19_Mul_scale using event 12 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF12);
	/* Waiting completion of transfer of Decision_S19_Mul_shift using event 13 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF13);
	/* Waiting completion of transfer of Decision_S19_Infos using event 14 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF14);
	Decision_AT_GraphPerf[6] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[6] - Start_IO;
	Decision_S19__layer2_layer2_0_shortcut_shortcut_0_Conv(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+387072)), /* Filter */
		((signed int * __restrict__) (DecisionNet_L2_Memory_Dyn+387584)), /* Bias */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* Out */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+387712)), /* Scale */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+387744)), /* ScaleN */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+387776)) /* Infos */
	);
	Decision_AT_GraphPerf[6] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[6];
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of Decision_S20_Infos using event 2 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF2);
	Decision_AT_GraphPerf[7] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[7] - Start_IO;
	Decision_S20__layer2_layer2_0_Add_fusion(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+256000)), /* In1 */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* In2 */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+384000)) /* Infos */
	);
	Decision_AT_GraphPerf[7] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[7];
	/* Moving _layer3_layer3_0_conv2_conv_weights (1/1), size 12288 from eMRAM at 0 to (size 12288) L2 at 384000 using event 0 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 0), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384000), 12288, 0, UchanMRF0);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _layer3_layer3_0_conv1_conv_weights using event 10 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF10);
	/* Waiting completion of transfer of Constant_onnx__conv_110 using event 1 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF1);
	/* Waiting completion of transfer of Decision_S23_Mul_scale using event 3 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF3);
	/* Waiting completion of transfer of Decision_S23_Mul_shift using event 4 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF4);
	/* Waiting completion of transfer of Decision_S23_Infos using event 19 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF19);
	Decision_AT_GraphPerf[8] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[8] - Start_IO;
	Decision_S23__layer3_layer3_0_conv1_Conv_fusion(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+396288)), /* Filter */
		((signed int * __restrict__) (DecisionNet_L2_Memory_Dyn+402432)), /* Bias */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* Out */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+402944)), /* Scale */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+403008)), /* ScaleN */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+403200)) /* Infos */
	);
	Decision_AT_GraphPerf[8] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[8];
	/* Moving _layer3_layer3_0_shortcut_shortcut_0_conv_weights (1/1), size 2048 from eMRAM at 21504 to (size 2048) L2 at 396288 using event 1 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 21504), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 396288), 2048, 0, UchanMRF1);
	/* Moving Constant_onnx__conv_116 (1/1), size 256 from eMRAM at 27904 to (size 256) L2 at 398336 using event 2 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 27904), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 398336), 256, 0, UchanMRF2);
	/* Moving Decision_S29_Mul_scale (1/1), size 64 from eMRAM at 29120 to (size 64) L2 at 398592 using event 3 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29120), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 398592), 64, 0, UchanMRF3);
	/* Moving Decision_S29_Mul_shift (1/1), size 64 from eMRAM at 29184 to (size 64) L2 at 398656 using event 4 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29184), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 398656), 64, 0, UchanMRF4);
	/* Moving Decision_S29_Infos (1/1), size 20 from eMRAM at 29664 to (size 20) L2 at 398720 using event 5 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29664), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 398720), 20, 0, UchanMRF5);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _layer3_layer3_0_conv2_conv_weights using event 0 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF0);
	/* Waiting completion of transfer of Constant_onnx__conv_113 using event 11 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF11);
	/* Waiting completion of transfer of Decision_S26_Mul_scale using event 7 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF7);
	/* Waiting completion of transfer of Decision_S26_Mul_shift using event 8 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF8);
	/* Waiting completion of transfer of Decision_S26_Infos using event 20 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF20);
	Decision_AT_GraphPerf[9] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[9] - Start_IO;
	Decision_S26__layer3_layer3_0_conv2_Conv(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* In */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+384000)), /* Filter */
		((signed int * __restrict__) (DecisionNet_L2_Memory_Dyn+402688)), /* Bias */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+256000)), /* Out */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+403072)), /* Scale */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+403136)), /* ScaleN */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+403220)) /* Infos */
	);
	Decision_AT_GraphPerf[9] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[9];
	/* Moving Decision_S30_Infos (1/1), size 14 from eMRAM at 29832 to (size 14) L2 at 384000 using event 0 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29832), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384000), 14, 0, UchanMRF0);
	/* Moving Decision_S31_Infos (1/1), size 13 from eMRAM at 29848 to (size 13) L2 at 384016 using event 6 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29848), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 384016), 13, 0, UchanMRF6);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _layer3_layer3_0_shortcut_shortcut_0_conv_weights using event 1 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF1);
	/* Waiting completion of transfer of Constant_onnx__conv_116 using event 2 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF2);
	/* Waiting completion of transfer of Decision_S29_Mul_scale using event 3 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF3);
	/* Waiting completion of transfer of Decision_S29_Mul_shift using event 4 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF4);
	/* Waiting completion of transfer of Decision_S29_Infos using event 5 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF5);
	Decision_AT_GraphPerf[10] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[10] - Start_IO;
	Decision_S29__layer3_layer3_0_shortcut_shortcut_0_Conv(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+396288)), /* Filter */
		((signed int * __restrict__) (DecisionNet_L2_Memory_Dyn+398336)), /* Bias */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* Out */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+398592)), /* Scale */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+398656)), /* ScaleN */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+398720)) /* Infos */
	);
	Decision_AT_GraphPerf[10] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[10];
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of Decision_S30_Infos using event 0 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF0);
	Decision_AT_GraphPerf[11] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[11] - Start_IO;
	Decision_S30__layer3_layer3_0_Add_fusion(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+256000)), /* In1 */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* In2 */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+0)), /* Out */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+384000)) /* Infos */
	);
	Decision_AT_GraphPerf[11] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[11];
	/* Moving _fc_gemm_biases (1/1), size 4 from eMRAM at 29864 to (size 4) L2 at 128064 using event 0 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29864), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 128064), 4, 0, UchanMRF0);
	/* Moving Decision_S35_Mul_scale (1/1), size 1 from eMRAM at 29868 to (size 1) L2 at 128068 using event 1 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29868), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 128068), 1, 0, UchanMRF1);
	/* Moving Decision_S35_Mul_shift (1/1), size 1 from eMRAM at 29872 to (size 1) L2 at 128072 using event 2 */
	AT_EMRAMFLASH_FS_CL_COPY(&EmramFlash, ((AT_EMRAMFLASH_FS_EXT_ADDR_TYPE) DecisionNet_L3_Flash + 29872), ((AT_EMRAMFLASH_FS_INT_ADDR_TYPE) DecisionNet_L2_Memory_Dyn + 128072), 1, 0, UchanMRF2);
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of Decision_S31_Infos using event 6 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF6);
	Decision_AT_GraphPerf[12] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[12] - Start_IO;
	Decision_S31__gap_MaxPool(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+0)), /* In */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* Out */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+384016)) /* Infos */
	);
	Decision_AT_GraphPerf[12] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[12];
	Start_IO = gap_cl_readhwtimer();
	/* Waiting completion of transfer of _fc_gemm_biases using event 0 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF0);
	/* Waiting completion of transfer of Decision_S35_Mul_scale using event 1 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF1);
	/* Waiting completion of transfer of Decision_S35_Mul_shift using event 2 */
	AT_EMRAMFLASH_FS_CL_WAIT(&EmramFlash, UchanMRF2);
	Decision_AT_GraphPerf[13] = gap_cl_readhwtimer();
	Decision_AT_GraphPerf[14] += Decision_AT_GraphPerf[13] - Start_IO;
	Decision_S35__fc_Gemm_fusion(
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128000)), /* In */
		((unsigned char * __restrict__) (DecisionNet_L3_Flash+29248)), /* Filter */
		((signed int * __restrict__) (DecisionNet_L2_Memory_Dyn+128064)), /* Bias */
		((unsigned char * __restrict__) Output_1), /* Out */
		((unsigned char * __restrict__) (DecisionNet_L2_Memory_Dyn+128068)), /* Scale */
		((signed char * __restrict__) (DecisionNet_L2_Memory_Dyn+128072)), /* ScaleN */
		((signed char * __restrict__) (DecisionNet_L3_Flash+29684)), /* Infos */
		((unsigned char * __restrict__) (DecisionNet_L3_Flash+28544)) /* SigmoidLUT_u8 */
	);
	Decision_AT_GraphPerf[13] = gap_cl_readhwtimer() - Decision_AT_GraphPerf[13];
	Decision_AT_GraphPerf_CNN_Total = gap_cl_readhwtimer() - Decision_AT_GraphPerf_CNN_Total;

	return 0;
	
}
