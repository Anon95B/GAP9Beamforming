#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wpointer-sign"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "Graph1_2_Expression_Kernels.h"

static int CoreCountDynamic = 1;
static int ActiveCore = gap_ncore();

static inline unsigned int __attribute__((always_inline)) ChunkSize(unsigned int X)

{
	unsigned int NCore;
	unsigned int Log2Core;
	unsigned int Chunk;

	if (CoreCountDynamic) NCore = ActiveCore; else NCore = gap_ncore();
	Log2Core = gap_fl1(NCore);
	Chunk = (X>>Log2Core) + ((X&(NCore-1))!=0);
	return Chunk;
}

#ifndef AT_NORM
#define AT_NORM(x, n)   gap_roundnorm_reg((x), (n))
#endif
#define ATLShift(x, n)  ((x) << (n))


#ifndef B_CLR
#define B_CLR(x, bits) ((x) & (~((1 << (bits)) - 1)))
#endif

static inline void __attribute__((always_inline)) Copy(char *__restrict__ To, char *__restrict__ From, unsigned int Size)
{
	int *pFrom = (int *)(From), *pTo = (int *)(To);
	for (int i = 0; i < Size / 8; i++)
	{
		int V0 = pFrom[2 * i], V1 = pFrom[2 * i + 1];
		pTo[2 * i] = V0;
		pTo[2 * i + 1] = V1;
	}
	if (Size & 0x4)
		*((int *)(To + B_CLR(Size, 3))) = *((int *)(From + B_CLR(Size, 3)));
	if (Size & 0x2)
		*((short int *)(To + B_CLR(Size, 2))) = *((short int *)(From + B_CLR(Size, 2)));
	if (Size & 0x1)
		*((signed char *)(To + Size - 1)) = *((signed char *)(From + Size - 1));
}

static inline void __attribute__((always_inline)) ParCopy(char *__restrict__ To, char *__restrict__ From, unsigned int Size, unsigned int CoreId)
{
	unsigned int Chunk = ChunkSize(Size), First = Min(Chunk * CoreId, Size), Last = Min(First + Chunk, Size);
	unsigned int Iter = Last - First;
	int *pFrom = (int *)(From + First), *pTo = (int *)(To + First);
	for (int i = 0; i < Iter / 8; i++)
	{
		int V0 = pFrom[2 * i], V1 = pFrom[2 * i + 1];
		pTo[2 * i] = V0;
		pTo[2 * i + 1] = V1;
	}
	if (Iter & 0x4)
		*((int *)(To + First + B_CLR(Iter, 3))) = *((int *)(From + First + B_CLR(Iter, 3)));
	if (Iter & 0x2)
		*((short int *)(To + First + B_CLR(Iter, 2))) = *((short int *)(From + First + B_CLR(Iter, 2)));
	if (Iter & 0x1)
		*((signed char *)(To + First + Iter - 1)) = *((signed char *)(From + First + Iter - 1));
}

void CNN_Split_Width_In2_Unused_1(SplitWidthIn2Arg_T *Arg)
{
    char *__restrict__ In = (char *__restrict__)Arg->In;
    int DataSize = (int)Arg->DataSize;
    int H = (int)Arg->H;
    char *__restrict__ Out1 = (char *__restrict__)Arg->Out1;
    int W1 = (int)Arg->W1 * DataSize;
    int S1 = (int)Arg->S1 * DataSize;
    int W2 = (int)Arg->W2 * DataSize;
    int S2 = (int)Arg->S2 * DataSize;
    int Wi = (int)Arg->InWidth * DataSize;
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(H), First = Min(Chunk * CoreId, H), Last = Min(First + Chunk, H);
    for (int h = First; h < Last; h++)
    {
        Copy(Out1 + h * W1, In + h * Wi + S1, W1);
    }
    gap_waitbarrier(0);
}

void CNN_ParSplit_Width_In2_Unused_1(SplitWidthIn2Arg_T *Arg)
{
    char *__restrict__ In = (char *__restrict__)Arg->In;
    int DataSize = (int)Arg->DataSize;
    int H = (int)Arg->H;
    char *__restrict__ Out1 = (char *__restrict__)Arg->Out1;
    int W1 = (int)Arg->W1 * DataSize;
    int S1 = (int)Arg->S1 * DataSize;
    int W2 = (int)Arg->W2 * DataSize;
    int S2 = (int)Arg->S2 * DataSize;
    int Wi = (int)Arg->InWidth * DataSize;
    unsigned int CoreId = gap_coreid();
    for (int h = 0; h < H; h++)
    {
        ParCopy(Out1 + h * W1, In + h * Wi + S1, W1, CoreId);
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 4 external iteration spaces
void G1_2s10_kernel(G1_2s10_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    unsigned int I3 = Args->I3;
    float *__restrict__  expr_0_in_0 = Args->expr_0_in_0; // (2, 1, 257, 6, 65) f32
    float *__restrict__  expr_0_in_1 = Args->expr_0_in_1; // (1, 1, 257, 1, 65) f32
    float *__restrict__  expr_0_in_2 = Args->expr_0_in_2; // (1, 1, 257, 1, 65) f32
    float *__restrict__  expr_0_out_0 = Args->expr_0_out_0; // (2, 1, 257, 6, 65) f32
    float *__restrict__  expr_0_out_1 = Args->expr_0_out_1; // (2, 1, 257, 6, 65) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I3);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I3);
    // Max shape: (2, 1, 257, 6, 65) var shapes:
    // expr_0_out_0: (2, 1, 257, 6, 65) expr_0_in_0: (2, 1, 257, 6, 65)
    // expr_0_in_1: (1, 1, 257, 1, 65) expr_0_out_1: (2, 1, 257, 6, 65)
    // expr_0_in_2: (1, 1, 257, 1, 65)
    // Iteration reduced to spaces ((0,), (2,), (3,), (4,))
    // Fixed spaces ((0,), (2,))
    // Parameteric spaces ((3,), (4,))
    // Paralelized space (4,)
    // Interior spaces ()
    for (int i2=0; i2<I2; i2++) {
        for (int i3=First; i3<Last; i3++) {
            // inputs expr_0_in_0: f32 expr_0_in_1: f32
            // expr_0_out_0 = Mul(expr_0_in_0, expr_0_in_1)
            expr_0_out_0[(i2*I3)+i3] = (expr_0_in_0[(i2*I3)+i3]*expr_0_in_1[i3]);
            // inputs expr_0_in_0: f32 expr_0_in_2: f32
            // expr_0_out_1 = Mul(expr_0_in_0, expr_0_in_2)
            expr_0_out_1[(i2*I3)+i3] = (expr_0_in_0[(i2*I3)+i3]*expr_0_in_2[i3]);
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void G1_2s23_kernel(G1_2s23_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    float *__restrict__  expr_1_in_0 = Args->expr_1_in_0; // (1, 1, 257, 6, 6) f32
    float *__restrict__  expr_1_in_1 = Args->expr_1_in_1; // (1, 1, 257, 6, 6) f32
    float *__restrict__  expr_1_out_0 = Args->expr_1_out_0; // (1, 1, 257, 6, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 1, 257, 6, 6) var shapes:
    // expr_1_out_0: (1, 1, 257, 6, 6) expr_1_in_0: (1, 1, 257, 6, 6)
    // expr_1_in_1: (1, 1, 257, 6, 6)
    // Iteration reduced to spaces ((2, 3, 4),)
    // Fixed spaces ()
    // Parameteric spaces ((2, 3, 4),)
    // Paralelized space (2, 3, 4)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_1_in_0: f32 expr_1_in_1: f32
        // expr_1_out_0 = Add(expr_1_in_0, expr_1_in_1)
        expr_1_out_0[i0] = (expr_1_in_0[i0]+expr_1_in_1[i0]);
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void G1_2s30_kernel(G1_2s30_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    float *__restrict__  expr_2_in_0 = Args->expr_2_in_0; // (1, 1, 257, 6, 6) f32
    float *__restrict__  expr_2_in_1 = Args->expr_2_in_1; // (1, 1, 257, 6, 6) f32
    float *__restrict__  expr_2_out_0 = Args->expr_2_out_0; // (1, 1, 257, 6, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 1, 257, 6, 6) var shapes:
    // expr_2_out_0: (1, 1, 257, 6, 6) expr_2_in_0: (1, 1, 257, 6, 6)
    // expr_2_in_1: (1, 1, 257, 6, 6)
    // Iteration reduced to spaces ((2, 3, 4),)
    // Fixed spaces ()
    // Parameteric spaces ((2, 3, 4),)
    // Paralelized space (2, 3, 4)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_2_in_0: f32 expr_2_in_1: f32
        // expr_2_out_0 = Sub(expr_2_in_0, expr_2_in_1)
        expr_2_out_0[i0] = (expr_2_in_0[i0]-expr_2_in_1[i0]);
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void G1_2s39_kernel(G1_2s39_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    float *__restrict__  expr_3_in_0 = Args->expr_3_in_0; // (1, 1, 257, 6, 6) f32
    float *__restrict__  expr_3_in_1 = Args->expr_3_in_1; // (1, 1, 257, 6, 6) f32
    float *__restrict__  expr_3_out_0 = Args->expr_3_out_0; // (1, 1, 257, 6, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 1, 257, 6, 6) var shapes:
    // expr_3_out_0: (1, 1, 257, 6, 6) expr_3_in_0: (1, 1, 257, 6, 6)
    // expr_3_in_1: (1, 1, 257, 6, 6)
    // Iteration reduced to spaces ((2, 3, 4),)
    // Fixed spaces ()
    // Parameteric spaces ((2, 3, 4),)
    // Paralelized space (2, 3, 4)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_3_in_0: f32 expr_3_in_1: f32
        // expr_3_out_0 = Add(expr_3_in_0, expr_3_in_1)
        expr_3_out_0[i0] = (expr_3_in_0[i0]+expr_3_in_1[i0]);
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void G1_2s46_kernel(G1_2s46_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    float *__restrict__  expr_4_in_0 = Args->expr_4_in_0; // (1, 1, 257, 6, 6) f32
    float *__restrict__  expr_4_in_1 = Args->expr_4_in_1; // (1, 1, 257, 6, 6) f32
    float *__restrict__  expr_4_out_0 = Args->expr_4_out_0; // (1, 1, 257, 6, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 1, 257, 6, 6) var shapes:
    // expr_4_out_0: (1, 1, 257, 6, 6) expr_4_in_0: (1, 1, 257, 6, 6)
    // expr_4_in_1: (1, 1, 257, 6, 6)
    // Iteration reduced to spaces ((2, 3, 4),)
    // Fixed spaces ()
    // Parameteric spaces ((2, 3, 4),)
    // Paralelized space (2, 3, 4)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_4_in_0: f32 expr_4_in_1: f32
        // expr_4_out_0 = Sub(expr_4_in_0, expr_4_in_1)
        expr_4_out_0[i0] = (expr_4_in_0[i0]-expr_4_in_1[i0]);
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 3 external iteration spaces
void G1_2s48_kernel(G1_2s48_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    float *__restrict__  expr_5_in_0 = Args->expr_5_in_0; // (1, 1, 257, 1, 1) f32
    float *__restrict__  expr_5_in_1 = Args->expr_5_in_1; // (2, 1, 257, 6, 6) f32
    float *__restrict__  expr_5_out_0 = Args->expr_5_out_0; // (2, 1, 257, 6, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (2, 1, 257, 6, 6) var shapes:
    // expr_5_out_0: (2, 1, 257, 6, 6) expr_5_in_1: (2, 1, 257, 6, 6)
    // expr_5_in_0: (1, 1, 257, 1, 1)
    // Iteration reduced to spaces ((0,), (2,), (3, 4))
    // Fixed spaces ((0,),)
    // Parameteric spaces ((2,), (3, 4))
    // Paralelized space (2,)
    // Interior spaces ()
    for (int i1=First; i1<Last; i1++) {
        for (int i2=0; i2<I2; i2++) {
            // inputs expr_5_in_1: f32 expr_5_in_0: f32
            // expr_5_out_0 = Div(expr_5_in_1, Add(expr_5_in_0, [1.e-15]))
            expr_5_out_0[(i1*I2)+i2] = (expr_5_in_1[(i1*I2)+i2]/(expr_5_in_0[i1]+(1.000000e-15f)));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void G1_2s61_kernel(G1_2s61_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    float *__restrict__  expr_6_in_0 = Args->expr_6_in_0; // (1, 1, 1, 6, 6)   f32
    float *__restrict__  expr_6_in_1 = Args->expr_6_in_1; // (1, 257, 2, 6, 6) f32
    float *__restrict__  expr_6_out_0 = Args->expr_6_out_0; // (1, 257, 2, 6, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 257, 2, 6, 6) var shapes:
    // expr_6_out_0: (1, 257, 2, 6, 6) expr_6_in_0: (1, 1, 1, 6, 6)
    // expr_6_in_1: (1, 257, 2, 6, 6)
    // Iteration reduced to spaces ((1, 2), (3, 4))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3, 4))
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_6_in_0: f32 expr_6_in_1: f32
            // expr_6_out_0 = Mul(expr_6_in_0, expr_6_in_1)
            expr_6_out_0[(i0*I1)+i1] = (expr_6_in_0[i1]*expr_6_in_1[(i0*I1)+i1]);
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void G1_2s65_kernel(G1_2s65_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    float *__restrict__  expr_7_in_0 = Args->expr_7_in_0; // (1, 257, 2, 1, 1) f32
    float *__restrict__  expr_7_in_1 = Args->expr_7_in_1; // (1, 1, 1, 6, 6)   f32
    float *__restrict__  expr_7_in_2 = Args->expr_7_in_2; // (1, 257, 2, 6, 6) f32
    float *__restrict__  expr_7_in_3 = Args->expr_7_in_3; // (1, 1, 1, 6, 6)   f32
    float *__restrict__  expr_7_out_0 = Args->expr_7_out_0; // (1, 257, 2, 6, 6) f32
    float *__restrict__  expr_7_out_1 = Args->expr_7_out_1; // (1, 257, 2, 6, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 257, 2, 6, 6) var shapes:
    // inter__Div_2: (1, 257, 2, 6, 6) expr_7_in_2: (1, 257, 2, 6, 6)
    // expr_7_in_1: (1, 1, 1, 6, 6) expr_7_in_0: (1, 257, 2, 1, 1)
    // expr_7_out_0: (1, 257, 2, 6, 6) expr_7_out_1: (1, 257, 2, 6, 6)
    // expr_7_in_3: (1, 1, 1, 6, 6)
    // Iteration reduced to spaces ((1, 2), (3, 4))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3, 4))
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_7_in_2: f32 expr_7_in_1: f32 expr_7_in_0: f32
            // inter__Div_2 = Mul(Add(expr_7_in_2, Mul(expr_7_in_1, Mul(Mul(expr_7_in_0, [1.e-06]), [0.16666667]))), [0.99999905])
            float inter__Div_2 = ((expr_7_in_2[(i0*I1)+i1]+(expr_7_in_1[i1]*((expr_7_in_0[i0]*(1.000000e-06f))*(1.666667e-01f))))*(9.999990e-01f));
            // inputs inter__Div_2: f32
            // expr_7_out_0 = inter__Div_2
            expr_7_out_0[(i0*I1)+i1] = inter__Div_2;
            // inputs expr_7_in_3: f32 inter__Div_2: f32
            // expr_7_out_1 = Mul(expr_7_in_3, inter__Div_2)
            expr_7_out_1[(i0*I1)+i1] = (expr_7_in_3[i1]*inter__Div_2);
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void G1_2s68_kernel(G1_2s68_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    float *__restrict__  expr_8_in_0 = Args->expr_8_in_0; // (1, 257, 2, 6, 6) f32
    float *__restrict__  expr_8_in_1 = Args->expr_8_in_1; // (1, 257, 1, 1, 1) f32
    float *__restrict__  expr_8_out_0 = Args->expr_8_out_0; // (1, 257, 2, 6, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 257, 2, 6, 6) var shapes:
    // expr_8_out_0: (1, 257, 2, 6, 6) expr_8_in_0: (1, 257, 2, 6, 6)
    // expr_8_in_1: (1, 257, 1, 1, 1)
    // Iteration reduced to spaces ((1,), (2, 3, 4))
    // Fixed spaces ()
    // Parameteric spaces ((1,), (2, 3, 4))
    // Paralelized space (1,)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_8_in_0: f32 expr_8_in_1: f32
            // expr_8_out_0 = Div(expr_8_in_0, expr_8_in_1)
            expr_8_out_0[(i0*I1)+i1] = (expr_8_in_0[(i0*I1)+i1]/expr_8_in_1[i0]);
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void G1_2s54_kernel(G1_2s54_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    float *__restrict__  expr_9_in_0 = Args->expr_9_in_0; // (1, 257, 6, 6) f32
    float *__restrict__  expr_9_out_0 = Args->expr_9_out_0; // (1, 257, 6, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 257, 6, 6) var shapes:
    // expr_9_out_0: (1, 257, 6, 6) expr_9_in_0: (1, 257, 6, 6)
    // Iteration reduced to spaces ((1, 2, 3),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2, 3),)
    // Paralelized space (1, 2, 3)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_9_in_0: f32
        // expr_9_out_0 = Mul(expr_9_in_0, [-1.])
        expr_9_out_0[i0] = (expr_9_in_0[i0]*(-1.0f));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void G1_2s75_kernel(G1_2s75_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    float *__restrict__  expr_10_in_0 = Args->expr_10_in_0; // (1, 257, 6, 6) f32
    float *__restrict__  expr_10_out_0 = Args->expr_10_out_0; // (1, 257, 6, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 257, 6, 6) var shapes:
    // expr_10_out_0: (1, 257, 6, 6) expr_10_in_0: (1, 257, 6, 6)
    // Iteration reduced to spaces ((1, 2, 3),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2, 3),)
    // Paralelized space (1, 2, 3)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_10_in_0: f32
        // expr_10_out_0 = Mul(expr_10_in_0, [-1.])
        expr_10_out_0[i0] = (expr_10_in_0[i0]*(-1.0f));
    }
    gap_waitbarrier(0);
}


#pragma GCC diagnostic pop