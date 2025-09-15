#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wpointer-sign"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "G2_Expression_Kernels.h"

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


// Output iteration space reduced to 0 internal and 2 external iteration spaces
void G2s8_kernel(G2s8_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    float *__restrict__  expr_0_in_0 = Args->expr_0_in_0; // (1, 1, 12, 12)   f32
    float *__restrict__  expr_0_in_1 = Args->expr_0_in_1; // (1, 257, 12, 12) f32
    float *__restrict__  expr_0_out_0 = Args->expr_0_out_0; // (1, 257, 12, 12) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 257, 12, 12) var shapes:
    // expr_0_out_0: (1, 257, 12, 12) expr_0_in_0: (1, 1, 12, 12) expr_0_in_1:
    // (1, 257, 12, 12)
    // Iteration reduced to spaces ((1,), (2, 3))
    // Fixed spaces ()
    // Parameteric spaces ((1,), (2, 3))
    // Paralelized space (1,)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_0_in_0: f32 expr_0_in_1: f32
            // expr_0_out_0 = Mul(expr_0_in_0, expr_0_in_1)
            expr_0_out_0[(i0*I1)+i1] = (expr_0_in_0[i1]*expr_0_in_1[(i0*I1)+i1]);
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void G2s10_kernel(G2s10_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    float *__restrict__  expr_1_in_0 = Args->expr_1_in_0; // (1, 257, 12, 12) f32
    float *__restrict__  expr_1_in_1 = Args->expr_1_in_1; // (1, 257, 1, 1)   f32
    float *__restrict__  expr_1_out_0 = Args->expr_1_out_0; // (1, 257, 12, 12) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 257, 12, 12) var shapes:
    // expr_1_out_0: (1, 257, 12, 12) expr_1_in_0: (1, 257, 12, 12)
    // expr_1_in_1: (1, 257, 1, 1)
    // Iteration reduced to spaces ((1,), (2, 3))
    // Fixed spaces ()
    // Parameteric spaces ((1,), (2, 3))
    // Paralelized space (1,)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_1_in_0: f32 expr_1_in_1: f32
            // expr_1_out_0 = Div(expr_1_in_0, expr_1_in_1)
            expr_1_out_0[(i0*I1)+i1] = (expr_1_in_0[(i0*I1)+i1]/expr_1_in_1[i0]);
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void G2s18_kernel(G2s18_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    float *__restrict__  expr_2_in_0 = Args->expr_2_in_0; // (1, 1, 257, 6) f32
    float *__restrict__  expr_2_in_1 = Args->expr_2_in_1; // (1, 1, 257, 6) f32
    float *__restrict__  expr_2_in_2 = Args->expr_2_in_2; // (1, 1, 257, 6) f32
    float *__restrict__  expr_2_in_3 = Args->expr_2_in_3; // (1, 1, 257, 6) f32
    float *__restrict__  expr_2_out_0 = Args->expr_2_out_0; // (1, 1, 257, 6) f32
    float *__restrict__  expr_2_out_1 = Args->expr_2_out_1; // (1, 1, 257, 6) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 1, 257, 6) var shapes:
    // expr_2_out_0: (1, 1, 257, 6) expr_2_in_0: (1, 1, 257, 6) expr_2_in_1:
    // (1, 1, 257, 6) expr_2_in_3: (1, 1, 257, 6) expr_2_in_2: (1, 1, 257, 6)
    // expr_2_out_1: (1, 1, 257, 6)
    // Iteration reduced to spaces ((2, 3),)
    // Fixed spaces ()
    // Parameteric spaces ((2, 3),)
    // Paralelized space (2, 3)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_2_in_0: f32 expr_2_in_1: f32 expr_2_in_3: f32
        // expr_2_in_2: f32
        // expr_2_out_0 = Add(Mul(expr_2_in_0, expr_2_in_1), Mul(expr_2_in_3, expr_2_in_2))
        expr_2_out_0[i0] = ((expr_2_in_0[i0]*expr_2_in_1[i0])+(expr_2_in_3[i0]*expr_2_in_2[i0]));
        // inputs expr_2_in_0: f32 expr_2_in_2: f32 expr_2_in_3: f32
        // expr_2_in_1: f32
        // expr_2_out_1 = Sub(Mul(expr_2_in_0, expr_2_in_2), Mul(expr_2_in_3, expr_2_in_1))
        expr_2_out_1[i0] = ((expr_2_in_0[i0]*expr_2_in_2[i0])-(expr_2_in_3[i0]*expr_2_in_1[i0]));
    }
    gap_waitbarrier(0);
}


#pragma GCC diagnostic pop