#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wpointer-sign"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "Expression_Kernels.h"

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

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void s5_kernel(s5_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    signed char *__restrict__  expr_0_in_0 = Args->expr_0_in_0; // (1, 2, 257, 65) int8 67.089 Q7
    signed char *__restrict__  expr_0_in_1 = Args->expr_0_in_1; // (1, 2, 257, 1)  int8 5.513 Q7
    signed char *__restrict__  expr_0_out_0 = Args->expr_0_out_0; // (1, 2, 257, 65) (int8--5) 64.351 Q7
    signed char *__restrict__  expr_0_out_1 = Args->expr_0_out_1; // (1, 2, 257, 65) int8 4467.189 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (1, 2, 257, 65) var shapes:
    // inter__enc_LN_Sub: (1, 2, 257, 65) expr_0_in_0: (1, 2, 257, 65)
    // expr_0_in_1: (1, 2, 257, 1) expr_0_out_0: (1, 2, 257, 65) expr_0_out_1:
    // (1, 2, 257, 65)
    // Iteration reduced to spaces ((1, 2), (3,))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3,))
    // Paralelized space (3,)
    // Interior spaces ()
    for (int i0=0; i0<I0; i0++) {
        for (int i1=First; i1<Last; i1++) {
            // inputs expr_0_in_0: int8 67.089 Q7 expr_0_in_1: int8 5.513 Q7
            // inter__enc_LN_Sub = Sub(Norm(Mul(Cast(expr_0_in_0, int32), [195]), [4]), Cast(expr_0_in_1, int32))
            // _enc_LN_Sub scale arg 1 (no zp adj) - int8 5.513 Q7 -> int32 88.201 Q11
            int _SYMBOL_Cast238 = ((int)expr_0_in_1[i0]);
            int inter__enc_LN_Sub = (gap_roundnorm_reg((((int)expr_0_in_0[(i0*I1)+i1])*(195)), ((unsigned char)4))-_SYMBOL_Cast238);
            // inputs inter__enc_LN_Sub: int32 176.402 Q12
            // expr_0_out_0 = Cast(Clip(Sub(Norm(Mul(inter__enc_LN_Sub, [175]), [11]), [5]), -128, 127), int8)
            // scale clip and cast - int32 176.402 Q12 -> (int8--5) 64.351 Q7
            expr_0_out_0[(i0*I1)+i1] = ((signed char)gap_clip(((gap_roundnorm_reg((inter__enc_LN_Sub*(175)), ((unsigned char)11))-(5))), (((signed char)7))));
            // inputs inter__enc_LN_Sub: int32 176.402 Q12
            // expr_0_out_1 = Cast(Clip(Norm(Mul(Square1715(LShift(inter__enc_LN_Sub, [3])), [223]), [13]), -128, 127), int8)
            // scale clip and cast - int32 31117.555 Q15 -> int8 4467.189 Q7
            expr_0_out_1[(i0*I1)+i1] = ((signed char)gap_clip((gap_roundnorm_reg((square_17_15((inter__enc_LN_Sub<<((unsigned char)3)))*(223)), ((unsigned char)13))), (((signed char)7))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 3 external iteration spaces
void s9_kernel(s9_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    unsigned int *__restrict__  RsqrtLUT = Args->RsqrtLUT; // (1, 1, 1, 96)   
    signed char *__restrict__  expr_1_in_0 = Args->expr_1_in_0; // (1, 2, 257, 1)  int8 409.089 Q7
    signed char *__restrict__  expr_1_in_1 = Args->expr_1_in_1; // (1, 2, 257, 65) (int8--5) 64.351 Q7
    signed char *__restrict__  expr_1_in_2 = Args->expr_1_in_2; // (1, 2, 1, 1)    int8 0.991 Q7
    signed char *__restrict__  expr_1_in_3 = Args->expr_1_in_3; // (1, 2, 1, 1)    int8 1169400.066 Q7
    unsigned char *__restrict__  expr_1_out_0 = Args->expr_1_out_0; // (1, 2, 257, 65) (uint8-130) 15.077 Q8
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (1, 2, 257, 65) var shapes:
    // expr_1_out_0: (1, 2, 257, 65) expr_1_in_1: (1, 2, 257, 65) expr_1_in_0:
    // (1, 2, 257, 1) expr_1_in_2: (1, 2, 1, 1) expr_1_in_3: (1, 2, 1, 1)
    // RsqrtLUT: (1, 1, 1, 96)
    // Iteration reduced to spaces ((1,), (2,), (3,))
    // Fixed spaces ((1,),)
    // Parameteric spaces ((2,), (3,))
    // Paralelized space (2,)
    // Interior spaces ()
    for (int i1=First; i1<Last; i1++) {
        for (int i2=0; i2<I2; i2++) {
            // inputs expr_1_in_1: (int8--5) 64.351 Q7 expr_1_in_0: int8
            // 409.089 Q7 expr_1_in_2: int8 0.991 Q7 expr_1_in_3: int8
            // 1169400.066 Q7
            // expr_1_out_0 = Cast(Clip(Sub(LShift(Mul(Add(Norm(Mul(Norm(Mul(Sub(Cast(expr_1_in_1, int32), [-5]), Cast(Norm(RSqrt1616(Add(ScaleQuantized(expr_1_in_0, [int8 409.089 Q7]->[int32 409.089 Q7]), ScaleQuantized([1], [int32 0.000 Q0]->[int32 409.089 Q7])), RsqrtLUT), [24]), int32)), [7]), Cast(expr_1_in_2, int32)), [7]), LShift(Cast(expr_1_in_3, int32), [8])), [151]), [2]), [-130]), 0, 255), uint8)
            // _enc_LN_Add scale arg 0 (equalize zp adj) - int8 409.089 Q7 -> int32 409.089 Q7
            int _SYMBOL_ScaleQuantized237 = ((int)expr_1_in_0[i1]);
            // _enc_LN_Add scale arg 1 (equalize zp adj) - int32 0.000 Q0 -> int32 409.089 Q7
            int _SYMBOL_ScaleQuantized238 = (0);
            int _SYMBOL__enc_LN_Add = (_SYMBOL_ScaleQuantized237+_SYMBOL_ScaleQuantized238);
            int _SYMBOL_Inv__enc_LN_Sqrt = ((int)gap_roundnormu_reg(rsqrt_16_16_lut(_SYMBOL__enc_LN_Add, RsqrtLUT), (24)));
            // scale clip and cast - int32 2338800.132 Q16 -> (uint8-130) 15.077 Q8
            expr_1_out_0[(i1*I2)+i2] = ((unsigned char)gap_clipu((((((gap_roundnorm_reg((gap_roundnorm_reg(((((int)expr_1_in_1[(i1*I2)+i2])-(-5))*_SYMBOL_Inv__enc_LN_Sqrt), (7))*((int)expr_1_in_2[0])), (7))+(((int)expr_1_in_3[0])<<((unsigned char)8)))*(151))<<((unsigned char)2))-(-130))), (((signed char)8))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void s26_kernel(s26_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned char *__restrict__  expr_3_in_0 = Args->expr_3_in_0; // (1, 16, 257, 65) (uint8-49) 8.702 Q8
    signed char *__restrict__  expr_3_in_1 = Args->expr_3_in_1; // (1, 16, 257, 1)  int8 1.211 Q7
    unsigned char *__restrict__  expr_3_out_0 = Args->expr_3_out_0; // (1, 16, 257, 65) (uint8-62) 9.087 Q8
    signed char *__restrict__  expr_3_out_1 = Args->expr_3_out_1; // (1, 16, 257, 65) int8 47.304 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // inter__conv_0_reg1_Sub: (1, 16, 257, 65) expr_3_in_0: (1, 16, 257, 65)
    // expr_3_in_1: (1, 16, 257, 1) expr_3_out_0: (1, 16, 257, 65)
    // expr_3_out_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2), (3,))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3,))
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_3_in_0: (uint8-49) 8.702 Q8 expr_3_in_1: int8 1.211
            // Q7
            // inter__conv_0_reg1_Sub = Sub(Norm(Mul(Cast(expr_3_in_0, int32), [230]), [6]), Cast(expr_3_in_1, int32))
            // _conv_0_reg1_Sub scale arg 1 (no zp adj) - int8 1.211 Q7 -> int32 4.845 Q9
            int _SYMBOL_Cast221 = ((int)expr_3_in_1[i0]);
            int inter__conv_0_reg1_Sub = (gap_roundnorm_reg((((int)expr_3_in_0[(i0*I1)+i1])*(230)), ((unsigned char)6))-_SYMBOL_Cast221);
            // inputs inter__conv_0_reg1_Sub: (int32-176) 9.690 Q10
            // expr_3_out_0 = Cast(Clip(Sub(Norm(Mul(inter__conv_0_reg1_Sub, [137]), [9]), [-15]), 0, 255), uint8)
            // scale clip and cast - (int32-176) 9.690 Q10 -> (uint8-62) 9.087 Q8
            expr_3_out_0[(i0*I1)+i1] = ((unsigned char)gap_clipu(((gap_roundnorm_reg((inter__conv_0_reg1_Sub*(137)), ((unsigned char)9))-(-15))), (((signed char)8))));
            // inputs inter__conv_0_reg1_Sub: (int32-176) 9.690 Q10
            // expr_3_out_1 = Cast(Clip(Norm(Mul(Square1715(LShift(Sub(inter__conv_0_reg1_Sub, [176]), [5])), [254]), [15]), -128, 127), int8)
            // scale clip and cast - int32 93.902 Q15 -> int8 47.304 Q7
            expr_3_out_1[(i0*I1)+i1] = ((signed char)gap_clip((gap_roundnorm_reg((square_17_15(((inter__conv_0_reg1_Sub-(176))<<((unsigned char)5)))*(254)), ((unsigned char)15))), (((signed char)7))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s135_kernel(s135_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_4_in_0 = Args->expr_4_in_0; // (1, 16, 257, 65) (uint8-121) 15.186 Q8
    unsigned char *__restrict__  expr_4_in_1 = Args->expr_4_in_1; // (1, 16, 257, 65) (uint8-101) 12.839 Q8
    unsigned char *__restrict__  expr_4_in_2 = Args->expr_4_in_2; // (1, 16, 257, 65) (uint8-99) 11.812 Q8
    unsigned char *__restrict__  expr_4_in_3 = Args->expr_4_in_3; // (1, 16, 257, 65) (uint8-93) 10.660 Q8
    unsigned char *__restrict__  expr_4_in_4 = Args->expr_4_in_4; // (1, 16, 257, 65) (uint8-97) 11.746 Q8
    unsigned char *__restrict__  expr_4_in_5 = Args->expr_4_in_5; // (1, 16, 257, 65) (uint8-101) 11.862 Q8
    unsigned char *__restrict__  expr_4_in_6 = Args->expr_4_in_6; // (1, 16, 257, 65) (uint8-98) 11.189 Q8
    unsigned char *__restrict__  expr_4_in_7 = Args->expr_4_in_7; // (1, 16, 257, 65) (uint8-89) 10.421 Q8
    unsigned char *__restrict__  expr_4_out_0 = Args->expr_4_out_0; // (1, 16, 257, 65) (uint8-84) 23.931 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_4_out_0: (1, 16, 257, 65) expr_4_in_0: (1, 16, 257, 65)
    // expr_4_in_1: (1, 16, 257, 65) expr_4_in_2: (1, 16, 257, 65) expr_4_in_3:
    // (1, 16, 257, 65) expr_4_in_4: (1, 16, 257, 65) expr_4_in_5: (1, 16, 257,
    // 65) expr_4_in_6: (1, 16, 257, 65) expr_4_in_7: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2, 3),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2, 3),)
    // Paralelized space (1, 2, 3)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_4_in_0: (uint8-121) 15.186 Q8 expr_4_in_1: (uint8-101)
        // 12.839 Q8 expr_4_in_2: (uint8-99) 11.812 Q8 expr_4_in_3: (uint8-93)
        // 10.660 Q8 expr_4_in_4: (uint8-97) 11.746 Q8 expr_4_in_5: (uint8-101)
        // 11.862 Q8 expr_4_in_6: (uint8-98) 11.189 Q8 expr_4_in_7: (uint8-89)
        // 10.421 Q8
        // expr_4_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Add(Add(Add(Add(Norm(Mul(Add(Norm(Mul(Add(Norm(Mul(Cast(expr_4_in_0, int32), [151]), [7]), Cast(expr_4_in_1, int32)), [139]), [7]), Cast(expr_4_in_2, int32)), [142]), [7]), Cast(expr_4_in_3, int32)), Norm(Mul(Cast(expr_4_in_4, int32), [141]), [7])), Norm(Mul(Cast(expr_4_in_5, int32), [142]), [7])), Norm(Mul(Cast(expr_4_in_6, int32), [134]), [7])), [131]), [7]), Cast(expr_4_in_7, int32)), [223]), [10]), [118]), 0, 255), uint8)
        // _Add_2 scale arg 1 (no zp adj) - (uint8-101) 12.839 Q8 -> (int32-101) 25.678 Q9
        int _SYMBOL_Cast145 = ((int)expr_4_in_1[i0]);
        // _Add_4 scale arg 1 (no zp adj) - (uint8-99) 11.812 Q8 -> (int32-99) 23.624 Q9
        int _SYMBOL_Cast146 = ((int)expr_4_in_2[i0]);
        // _Add_6 scale arg 1 (no zp adj) - (uint8-93) 10.660 Q8 -> (int32-93) 21.321 Q9
        int _SYMBOL_Cast147 = ((int)expr_4_in_3[i0]);
        // _Add_14 scale arg 1 (no zp adj) - (uint8-89) 10.421 Q8 -> (int32-89) 20.841 Q9
        int _SYMBOL_Cast151 = ((int)expr_4_in_7[i0]);
        // scale clip and cast - (int32-927) 41.682 Q10 -> (uint8-84) 23.931 Q7
        expr_4_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((((gap_roundnorm_reg(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_4_in_0[i0])*(151)), ((unsigned char)7))+_SYMBOL_Cast145)*(139)), ((unsigned char)7))+_SYMBOL_Cast146)*(142)), ((unsigned char)7))+_SYMBOL_Cast147)+gap_roundnorm_reg((((int)expr_4_in_4[i0])*(141)), ((unsigned char)7)))+gap_roundnorm_reg((((int)expr_4_in_5[i0])*(142)), ((unsigned char)7)))+gap_roundnorm_reg((((int)expr_4_in_6[i0])*(134)), ((unsigned char)7)))*(131)), ((unsigned char)7))+_SYMBOL_Cast151)*(223)), ((unsigned char)10))-(118))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 3 external iteration spaces
void s30_kernel(s30_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    unsigned char *__restrict__  expr_6_in_0 = Args->expr_6_in_0; // (1, 16, 257, 65) (uint8-62) 9.087 Q8
    signed char *__restrict__  expr_6_in_1 = Args->expr_6_in_1; // (1, 16, 257, 1)  (int8--128) 47.174 Q7
    signed char *__restrict__  expr_6_in_2 = Args->expr_6_in_2; // (1, 16, 1, 1)    int8 1.014 Q7
    signed char *__restrict__  expr_6_in_3 = Args->expr_6_in_3; // (1, 16, 1, 1)    int8 0.013 Q7
    unsigned char *__restrict__  expr_6_in_4 = Args->expr_6_in_4; // (1, 16, 257, 65) (uint8-128) 14.929 Q8
    unsigned char *__restrict__  expr_6_out_0 = Args->expr_6_out_0; // (1, 16, 257, 65) (uint8-121) 7.593 Q7
    unsigned char *__restrict__  expr_6_out_1 = Args->expr_6_out_1; // (1, 16, 257, 65) (uint8-122) 12.468 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (1, 16, 257, 65) var shapes:
    // inter__conv_0_reg1_Add_1: (1, 16, 257, 65) expr_6_in_0: (1, 16, 257, 65)
    // expr_6_in_1: (1, 16, 257, 1) expr_6_in_2: (1, 16, 1, 1) expr_6_in_3: (1,
    // 16, 1, 1) expr_6_out_0: (1, 16, 257, 65) expr_6_out_1: (1, 16, 257, 65)
    // expr_6_in_4: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1,), (2,), (3,))
    // Fixed spaces ((1,),)
    // Parameteric spaces ((2,), (3,))
    // Paralelized space (2,)
    // Interior spaces ()
    for (int i1=First; i1<Last; i1++) {
        for (int i2=0; i2<I2; i2++) {
            // inputs expr_6_in_0: (uint8-62) 9.087 Q8 expr_6_in_1: (int8--128)
            // 47.174 Q7 expr_6_in_2: int8 1.014 Q7 expr_6_in_3: int8 434.481
            // Q7
            // inter__conv_0_reg1_Add_1 = Add(Norm(Mul(Mul(Sub(Cast(expr_6_in_0, int32), [62]), Sub(Cast(expr_6_in_1, int32), [-128])), Cast(expr_6_in_2, int32)), [7]), LShift(Cast(expr_6_in_3, int32), [8]))
            int inter__conv_0_reg1_Add_1 = (gap_roundnorm_reg((((((int)expr_6_in_0[(i1*I2)+i2])-(62))*(((int)expr_6_in_1[i1])-(-128)))*((int)expr_6_in_2[0])), (7))+(((int)expr_6_in_3[0])<<((unsigned char)8)));
            // inputs inter__conv_0_reg1_Add_1: int32 868.962 Q16
            // expr_6_out_0 = Cast(Clip(Sub(Norm(Mul(inter__conv_0_reg1_Add_1, [229]), [10]), [-121]), 0, 255), uint8)
            // scale clip and cast - int32 868.962 Q16 -> (uint8-121) 7.593 Q7
            expr_6_out_0[(i1*I2)+i2] = ((unsigned char)gap_clipu(((gap_roundnorm_reg((inter__conv_0_reg1_Add_1*(229)), ((unsigned char)10))-(-121))), (((signed char)8))));
            // inputs expr_6_in_4: (uint8-128) 14.929 Q8
            // inter__conv_0_reg1_Add_1: int32 868.962 Q16
            // expr_6_out_1 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Cast(expr_6_in_4, int32), [141]), [5]), inter__conv_0_reg1_Add_1), [139]), [10]), [-45]), 0, 255), uint8)
            // scale clip and cast - (int32-564) 13903.391 Q20 -> (uint8-122) 12.468 Q7
            expr_6_out_1[(i1*I2)+i2] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_6_in_4[(i1*I2)+i2])*(141)), ((unsigned char)5))+inter__conv_0_reg1_Add_1)*(139)), ((unsigned char)10))-(-45))), (((signed char)8))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void s40_kernel(s40_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned char *__restrict__  expr_7_in_0 = Args->expr_7_in_0; // (1, 16, 257, 65) (uint8-54) 18.375 Q8
    signed char *__restrict__  expr_7_in_1 = Args->expr_7_in_1; // (1, 16, 257, 1)  int8 1.687 Q7
    unsigned char *__restrict__  expr_7_out_0 = Args->expr_7_out_0; // (1, 16, 257, 65) (uint8-69) 19.249 Q8
    signed char *__restrict__  expr_7_out_1 = Args->expr_7_out_1; // (1, 16, 257, 65) int8 196.524 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // inter__conv_1_reg1_Sub: (1, 16, 257, 65) expr_7_in_0: (1, 16, 257, 65)
    // expr_7_in_1: (1, 16, 257, 1) expr_7_out_0: (1, 16, 257, 65)
    // expr_7_out_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2), (3,))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3,))
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_7_in_0: (uint8-54) 18.375 Q8 expr_7_in_1: int8 1.687
            // Q7
            // inter__conv_1_reg1_Sub = Sub(Norm(Mul(Cast(expr_7_in_0, int32), [174]), [5]), Cast(expr_7_in_1, int32))
            // _conv_1_reg1_Sub scale arg 1 (no zp adj) - int8 1.687 Q7 -> int32 13.498 Q10
            int _SYMBOL_Cast212 = ((int)expr_7_in_1[i0]);
            int inter__conv_1_reg1_Sub = (gap_roundnorm_reg((((int)expr_7_in_0[(i0*I1)+i1])*(174)), ((unsigned char)5))-_SYMBOL_Cast212);
            // inputs inter__conv_1_reg1_Sub: (int32-294) 26.997 Q11
            // expr_7_out_0 = Cast(Clip(Sub(Norm(Mul(inter__conv_1_reg1_Sub, [180]), [10]), [-17]), 0, 255), uint8)
            // scale clip and cast - (int32-294) 26.997 Q11 -> (uint8-69) 19.249 Q8
            expr_7_out_0[(i0*I1)+i1] = ((unsigned char)gap_clipu(((gap_roundnorm_reg((inter__conv_1_reg1_Sub*(180)), ((unsigned char)10))-(-17))), (((signed char)8))));
            // inputs inter__conv_1_reg1_Sub: (int32-294) 26.997 Q11
            // expr_7_out_1 = Cast(Clip(Norm(Mul(Square1715(LShift(Sub(inter__conv_1_reg1_Sub, [294]), [4])), [237]), [14]), -128, 127), int8)
            // scale clip and cast - int32 728.832 Q15 -> int8 196.524 Q7
            expr_7_out_1[(i0*I1)+i1] = ((signed char)gap_clip((gap_roundnorm_reg((square_17_15(((inter__conv_1_reg1_Sub-(294))<<((unsigned char)4)))*(237)), ((unsigned char)14))), (((signed char)7))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 3 external iteration spaces
void s44_kernel(s44_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    unsigned char *__restrict__  expr_8_in_0 = Args->expr_8_in_0; // (1, 16, 257, 65) (uint8-69) 19.249 Q8
    signed char *__restrict__  expr_8_in_1 = Args->expr_8_in_1; // (1, 16, 257, 1)  (int8--128) 8.495 Q7
    signed char *__restrict__  expr_8_in_2 = Args->expr_8_in_2; // (1, 16, 1, 1)    int8 1.019 Q7
    signed char *__restrict__  expr_8_in_3 = Args->expr_8_in_3; // (1, 16, 1, 1)    int8 0.012 Q7
    unsigned char *__restrict__  expr_8_out_0 = Args->expr_8_out_0; // (1, 16, 257, 65) (uint8-101) 6.419 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_8_out_0: (1, 16, 257, 65) expr_8_in_0: (1, 16, 257, 65)
    // expr_8_in_1: (1, 16, 257, 1) expr_8_in_2: (1, 16, 1, 1) expr_8_in_3: (1,
    // 16, 1, 1)
    // Iteration reduced to spaces ((1,), (2,), (3,))
    // Fixed spaces ((1,),)
    // Parameteric spaces ((2,), (3,))
    // Paralelized space (2,)
    // Interior spaces ()
    for (int i1=First; i1<Last; i1++) {
        for (int i2=0; i2<I2; i2++) {
            // inputs expr_8_in_0: (uint8-69) 19.249 Q8 expr_8_in_1:
            // (int8--128) 8.495 Q7 expr_8_in_2: int8 1.019 Q7 expr_8_in_3:
            // int8 166.707 Q7
            // expr_8_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Mul(Sub(Cast(expr_8_in_0, int32), [69]), Sub(Cast(expr_8_in_1, int32), [-128])), Cast(expr_8_in_2, int32)), [7]), LShift(Cast(expr_8_in_3, int32), [8])), [208]), [11]), [-101]), 0, 255), uint8)
            // scale clip and cast - int32 333.414 Q16 -> (uint8-101) 6.419 Q7
            expr_8_out_0[(i1*I2)+i2] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((((int)expr_8_in_0[(i1*I2)+i2])-(69))*(((int)expr_8_in_1[i1])-(-128)))*((int)expr_8_in_2[0])), (7))+(((int)expr_8_in_3[0])<<((unsigned char)8)))*(208)), ((unsigned char)11))-(-101))), (((signed char)8))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s45_kernel(s45_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_9_in_0 = Args->expr_9_in_0; // (1, 16, 257, 65) (uint8-122) 24.935 Q8
    unsigned char *__restrict__  expr_9_in_1 = Args->expr_9_in_1; // (1, 16, 257, 65) (uint8-101) 12.839 Q8
    unsigned char *__restrict__  expr_9_out_0 = Args->expr_9_out_0; // (1, 16, 257, 65) (uint8-111) 15.727 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_9_out_0: (1, 16, 257, 65) expr_9_in_0: (1, 16, 257, 65)
    // expr_9_in_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2, 3),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2, 3),)
    // Paralelized space (1, 2, 3)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_9_in_0: (uint8-122) 24.935 Q8 expr_9_in_1: (uint8-101)
        // 12.839 Q8
        // expr_9_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Cast(expr_9_in_0, int32), [249]), [7]), Cast(expr_9_in_1, int32)), [209]), [9]), [27]), 0, 255), uint8)
        // _Add_3 scale arg 1 (no zp adj) - (uint8-101) 12.839 Q8 -> (int32-101) 25.678 Q9
        int _SYMBOL_Cast43 = ((int)expr_9_in_1[i0]);
        // scale clip and cast - (int32-338) 51.356 Q10 -> (uint8-111) 15.727 Q7
        expr_9_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_9_in_0[i0])*(249)), ((unsigned char)7))+_SYMBOL_Cast43)*(209)), ((unsigned char)9))-(27))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s60_kernel(s60_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_11_in_0 = Args->expr_11_in_0; // (1, 16, 257, 65) (uint8-111) 31.454 Q8
    unsigned char *__restrict__  expr_11_in_1 = Args->expr_11_in_1; // (1, 16, 257, 65) (uint8-99) 11.812 Q8
    unsigned char *__restrict__  expr_11_out_0 = Args->expr_11_out_0; // (1, 16, 257, 65) (uint8-104) 16.605 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_11_out_0: (1, 16, 257, 65) expr_11_in_0: (1, 16, 257, 65)
    // expr_11_in_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2, 3),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2, 3),)
    // Paralelized space (1, 2, 3)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_11_in_0: (uint8-111) 31.454 Q8 expr_11_in_1: (uint8-99)
        // 11.812 Q8
        // expr_11_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Cast(expr_11_in_0, int32), [170]), [6]), Cast(expr_11_in_1, int32)), [182]), [9]), [36]), 0, 255), uint8)
        // _Add_5 scale arg 1 (no zp adj) - (uint8-99) 11.812 Q8 -> (int32-99) 47.248 Q10
        int _SYMBOL_Cast60 = ((int)expr_11_in_1[i0]);
        // scale clip and cast - (int32-394) 94.496 Q11 -> (uint8-104) 16.605 Q7
        expr_11_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_11_in_0[i0])*(170)), ((unsigned char)6))+_SYMBOL_Cast60)*(182)), ((unsigned char)9))-(36))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void s55_kernel(s55_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned char *__restrict__  expr_12_in_0 = Args->expr_12_in_0; // (1, 16, 257, 65) (uint8-66) 21.388 Q8
    signed char *__restrict__  expr_12_in_1 = Args->expr_12_in_1; // (1, 16, 257, 1)  int8 2.327 Q7
    unsigned char *__restrict__  expr_12_out_0 = Args->expr_12_out_0; // (1, 16, 257, 65) (uint8-82) 21.649 Q8
    signed char *__restrict__  expr_12_out_1 = Args->expr_12_out_1; // (1, 16, 257, 65) int8 214.707 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // inter__conv_2_reg1_Sub: (1, 16, 257, 65) expr_12_in_0: (1, 16, 257, 65)
    // expr_12_in_1: (1, 16, 257, 1) expr_12_out_0: (1, 16, 257, 65)
    // expr_12_out_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2), (3,))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3,))
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_12_in_0: (uint8-66) 21.388 Q8 expr_12_in_1: int8
            // 2.327 Q7
            // inter__conv_2_reg1_Sub = Sub(Norm(Mul(Cast(expr_12_in_0, int32), [147]), [5]), Cast(expr_12_in_1, int32))
            // _conv_2_reg1_Sub scale arg 1 (no zp adj) - int8 2.327 Q7 -> int32 18.615 Q10
            int _SYMBOL_Cast203 = ((int)expr_12_in_1[i0]);
            int inter__conv_2_reg1_Sub = (gap_roundnorm_reg((((int)expr_12_in_0[(i0*I1)+i1])*(147)), ((unsigned char)5))-_SYMBOL_Cast203);
            // inputs inter__conv_2_reg1_Sub: (int32-303) 37.229 Q11
            // expr_12_out_0 = Cast(Clip(Sub(Norm(Mul(inter__conv_2_reg1_Sub, [220]), [10]), [-17]), 0, 255), uint8)
            // scale clip and cast - (int32-303) 37.229 Q11 -> (uint8-82) 21.649 Q8
            expr_12_out_0[(i0*I1)+i1] = ((unsigned char)gap_clipu(((gap_roundnorm_reg((inter__conv_2_reg1_Sub*(220)), ((unsigned char)10))-(-17))), (((signed char)8))));
            // inputs inter__conv_2_reg1_Sub: (int32-303) 37.229 Q11
            // expr_12_out_1 = Cast(Clip(Norm(Mul(Square1715(LShift(Sub(inter__conv_2_reg1_Sub, [303]), [4])), [207]), [13]), -128, 127), int8)
            // scale clip and cast - int32 1386.006 Q15 -> int8 214.707 Q7
            expr_12_out_1[(i0*I1)+i1] = ((signed char)gap_clip((gap_roundnorm_reg((square_17_15(((inter__conv_2_reg1_Sub-(303))<<((unsigned char)4)))*(207)), ((unsigned char)13))), (((signed char)7))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 3 external iteration spaces
void s59_kernel(s59_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    unsigned char *__restrict__  expr_13_in_0 = Args->expr_13_in_0; // (1, 16, 257, 65) (uint8-82) 21.649 Q8
    signed char *__restrict__  expr_13_in_1 = Args->expr_13_in_1; // (1, 16, 257, 1)  (int8--128) 3.735 Q7
    signed char *__restrict__  expr_13_in_2 = Args->expr_13_in_2; // (1, 16, 1, 1)    int8 1.022 Q7
    signed char *__restrict__  expr_13_in_3 = Args->expr_13_in_3; // (1, 16, 1, 1)    int8 0.016 Q7
    unsigned char *__restrict__  expr_13_out_0 = Args->expr_13_out_0; // (1, 16, 257, 65) (uint8-99) 5.906 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_13_out_0: (1, 16, 257, 65) expr_13_in_0: (1, 16, 257, 65)
    // expr_13_in_1: (1, 16, 257, 1) expr_13_in_2: (1, 16, 1, 1) expr_13_in_3:
    // (1, 16, 1, 1)
    // Iteration reduced to spaces ((1,), (2,), (3,))
    // Fixed spaces ((1,),)
    // Parameteric spaces ((2,), (3,))
    // Paralelized space (2,)
    // Interior spaces ()
    for (int i1=First; i1<Last; i1++) {
        for (int i2=0; i2<I2; i2++) {
            // inputs expr_13_in_0: (uint8-82) 21.649 Q8 expr_13_in_1:
            // (int8--128) 3.735 Q7 expr_13_in_2: int8 1.022 Q7 expr_13_in_3:
            // int8 82.654 Q7
            // expr_13_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Mul(Sub(Cast(expr_13_in_0, int32), [82]), Sub(Cast(expr_13_in_1, int32), [-128])), Cast(expr_13_in_2, int32)), [7]), LShift(Cast(expr_13_in_3, int32), [8])), [224]), [12]), [-99]), 0, 255), uint8)
            // scale clip and cast - int32 165.309 Q16 -> (uint8-99) 5.906 Q7
            expr_13_out_0[(i1*I2)+i2] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((((int)expr_13_in_0[(i1*I2)+i2])-(82))*(((int)expr_13_in_1[i1])-(-128)))*((int)expr_13_in_2[0])), (7))+(((int)expr_13_in_3[0])<<((unsigned char)8)))*(224)), ((unsigned char)12))-(-99))), (((signed char)8))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s75_kernel(s75_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_14_in_0 = Args->expr_14_in_0; // (1, 16, 257, 65) (uint8-104) 33.210 Q8
    unsigned char *__restrict__  expr_14_in_1 = Args->expr_14_in_1; // (1, 16, 257, 65) (uint8-93) 10.660 Q8
    unsigned char *__restrict__  expr_14_out_0 = Args->expr_14_out_0; // (1, 16, 257, 65) (uint8-99) 18.896 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_14_out_0: (1, 16, 257, 65) expr_14_in_0: (1, 16, 257, 65)
    // expr_14_in_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2, 3),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2, 3),)
    // Paralelized space (1, 2, 3)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_14_in_0: (uint8-104) 33.210 Q8 expr_14_in_1: (uint8-93)
        // 10.660 Q8
        // expr_14_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Cast(expr_14_in_0, int32), [199]), [6]), Cast(expr_14_in_1, int32)), [144]), [9]), [18]), 0, 255), uint8)
        // _Add_7 scale arg 1 (no zp adj) - (uint8-93) 10.660 Q8 -> (int32-93) 42.642 Q10
        int _SYMBOL_Cast77 = ((int)expr_14_in_1[i0]);
        // scale clip and cast - (int32-416) 85.283 Q11 -> (uint8-99) 18.896 Q7
        expr_14_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_14_in_0[i0])*(199)), ((unsigned char)6))+_SYMBOL_Cast77)*(144)), ((unsigned char)9))-(18))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s90_kernel(s90_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_16_in_0 = Args->expr_16_in_0; // (1, 16, 257, 65) (uint8-99) 37.791 Q8
    unsigned char *__restrict__  expr_16_in_1 = Args->expr_16_in_1; // (1, 16, 257, 65) (uint8-97) 11.746 Q8
    unsigned char *__restrict__  expr_16_out_0 = Args->expr_16_out_0; // (1, 16, 257, 65) (uint8-101) 20.260 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_16_out_0: (1, 16, 257, 65) expr_16_in_0: (1, 16, 257, 65)
    // expr_16_in_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2, 3),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2, 3),)
    // Paralelized space (1, 2, 3)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_16_in_0: (uint8-99) 37.791 Q8 expr_16_in_1: (uint8-97)
        // 11.746 Q8
        // expr_16_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Cast(expr_16_in_0, int32), [206]), [6]), Cast(expr_16_in_1, int32)), [148]), [9]), [19]), 0, 255), uint8)
        // _Add_9 scale arg 1 (no zp adj) - (uint8-97) 11.746 Q8 -> (int32-97) 46.984 Q10
        int _SYMBOL_Cast94 = ((int)expr_16_in_1[i0]);
        // scale clip and cast - (int32-416) 93.968 Q11 -> (uint8-101) 20.260 Q7
        expr_16_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_16_in_0[i0])*(206)), ((unsigned char)6))+_SYMBOL_Cast94)*(148)), ((unsigned char)9))-(19))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void s70_kernel(s70_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned char *__restrict__  expr_17_in_0 = Args->expr_17_in_0; // (1, 16, 257, 65) (uint8-46) 24.806 Q8
    signed char *__restrict__  expr_17_in_1 = Args->expr_17_in_1; // (1, 16, 257, 1)  int8 1.839 Q7
    unsigned char *__restrict__  expr_17_out_0 = Args->expr_17_out_0; // (1, 16, 257, 65) (uint8-54) 24.118 Q8
    signed char *__restrict__  expr_17_out_1 = Args->expr_17_out_1; // (1, 16, 257, 65) int8 361.130 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // inter__conv_3_reg1_Sub: (1, 16, 257, 65) expr_17_in_0: (1, 16, 257, 65)
    // expr_17_in_1: (1, 16, 257, 1) expr_17_out_0: (1, 16, 257, 65)
    // expr_17_out_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2), (3,))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3,))
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_17_in_0: (uint8-46) 24.806 Q8 expr_17_in_1: int8
            // 1.839 Q7
            // inter__conv_3_reg1_Sub = Sub(Norm(Mul(Cast(expr_17_in_0, int32), [216]), [5]), Cast(expr_17_in_1, int32))
            // _conv_3_reg1_Sub scale arg 1 (no zp adj) - int8 1.839 Q7 -> int32 14.715 Q10
            int _SYMBOL_Cast194 = ((int)expr_17_in_1[i0]);
            int inter__conv_3_reg1_Sub = (gap_roundnorm_reg((((int)expr_17_in_0[(i0*I1)+i1])*(216)), ((unsigned char)5))-_SYMBOL_Cast194);
            // inputs inter__conv_3_reg1_Sub: (int32-311) 29.431 Q11
            // expr_17_out_0 = Cast(Clip(Sub(Norm(Mul(inter__conv_3_reg1_Sub, [156]), [10]), [-7]), 0, 255), uint8)
            // scale clip and cast - (int32-311) 29.431 Q11 -> (uint8-54) 24.118 Q8
            expr_17_out_0[(i0*I1)+i1] = ((unsigned char)gap_clipu(((gap_roundnorm_reg((inter__conv_3_reg1_Sub*(156)), ((unsigned char)10))-(-7))), (((signed char)8))));
            // inputs inter__conv_3_reg1_Sub: (int32-311) 29.431 Q11
            // expr_17_out_1 = Cast(Clip(Norm(Mul(Square1715(LShift(Sub(inter__conv_3_reg1_Sub, [311]), [4])), [154]), [14]), -128, 127), int8)
            // scale clip and cast - int32 866.168 Q15 -> int8 361.130 Q7
            expr_17_out_1[(i0*I1)+i1] = ((signed char)gap_clip((gap_roundnorm_reg((square_17_15(((inter__conv_3_reg1_Sub-(311))<<((unsigned char)4)))*(154)), ((unsigned char)14))), (((signed char)7))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 3 external iteration spaces
void s74_kernel(s74_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    unsigned char *__restrict__  expr_18_in_0 = Args->expr_18_in_0; // (1, 16, 257, 65) (uint8-54) 24.118 Q8
    signed char *__restrict__  expr_18_in_1 = Args->expr_18_in_1; // (1, 16, 257, 1)  (int8--128) 3.687 Q7
    signed char *__restrict__  expr_18_in_2 = Args->expr_18_in_2; // (1, 16, 1, 1)    int8 1.016 Q7
    signed char *__restrict__  expr_18_in_3 = Args->expr_18_in_3; // (1, 16, 1, 1)    int8 0.009 Q7
    unsigned char *__restrict__  expr_18_out_0 = Args->expr_18_out_0; // (1, 16, 257, 65) (uint8-93) 5.330 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_18_out_0: (1, 16, 257, 65) expr_18_in_0: (1, 16, 257, 65)
    // expr_18_in_1: (1, 16, 257, 1) expr_18_in_2: (1, 16, 1, 1) expr_18_in_3:
    // (1, 16, 1, 1)
    // Iteration reduced to spaces ((1,), (2,), (3,))
    // Fixed spaces ((1,),)
    // Parameteric spaces ((2,), (3,))
    // Paralelized space (2,)
    // Interior spaces ()
    for (int i1=First; i1<Last; i1++) {
        for (int i2=0; i2<I2; i2++) {
            // inputs expr_18_in_0: (uint8-54) 24.118 Q8 expr_18_in_1:
            // (int8--128) 3.687 Q7 expr_18_in_2: int8 1.016 Q7 expr_18_in_3:
            // int8 90.403 Q7
            // expr_18_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Mul(Sub(Cast(expr_18_in_0, int32), [54]), Sub(Cast(expr_18_in_1, int32), [-128])), Cast(expr_18_in_2, int32)), [7]), LShift(Cast(expr_18_in_3, int32), [8])), [136]), [11]), [-93]), 0, 255), uint8)
            // scale clip and cast - int32 180.807 Q16 -> (uint8-93) 5.330 Q7
            expr_18_out_0[(i1*I2)+i2] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((((int)expr_18_in_0[(i1*I2)+i2])-(54))*(((int)expr_18_in_1[i1])-(-128)))*((int)expr_18_in_2[0])), (7))+(((int)expr_18_in_3[0])<<((unsigned char)8)))*(136)), ((unsigned char)11))-(-93))), (((signed char)8))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s105_kernel(s105_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_19_in_0 = Args->expr_19_in_0; // (1, 16, 257, 65) (uint8-101) 40.521 Q8
    unsigned char *__restrict__  expr_19_in_1 = Args->expr_19_in_1; // (1, 16, 257, 65) (uint8-101) 11.862 Q8
    unsigned char *__restrict__  expr_19_out_0 = Args->expr_19_out_0; // (1, 16, 257, 65) (uint8-102) 23.361 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_19_out_0: (1, 16, 257, 65) expr_19_in_0: (1, 16, 257, 65)
    // expr_19_in_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2, 3),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2, 3),)
    // Paralelized space (1, 2, 3)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_19_in_0: (uint8-101) 40.521 Q8 expr_19_in_1: (uint8-101)
        // 11.862 Q8
        // expr_19_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Cast(expr_19_in_0, int32), [219]), [6]), Cast(expr_19_in_1, int32)), [130]), [9]), [11]), 0, 255), uint8)
        // _Add_11 scale arg 1 (no zp adj) - (uint8-101) 11.862 Q8 -> (int32-101) 47.447 Q10
        int _SYMBOL_Cast111 = ((int)expr_19_in_1[i0]);
        // scale clip and cast - (int32-447) 94.894 Q11 -> (uint8-102) 23.361 Q7
        expr_19_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_19_in_0[i0])*(219)), ((unsigned char)6))+_SYMBOL_Cast111)*(130)), ((unsigned char)9))-(11))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s120_kernel(s120_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_20_in_0 = Args->expr_20_in_0; // (1, 16, 257, 65) (uint8-102) 46.723 Q8
    unsigned char *__restrict__  expr_20_in_1 = Args->expr_20_in_1; // (1, 16, 257, 65) (uint8-98) 11.189 Q8
    unsigned char *__restrict__  expr_20_out_0 = Args->expr_20_out_0; // (1, 16, 257, 65) (uint8-93) 25.285 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_20_out_0: (1, 16, 257, 65) expr_20_in_0: (1, 16, 257, 65)
    // expr_20_in_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2, 3),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2, 3),)
    // Paralelized space (1, 2, 3)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_20_in_0: (uint8-102) 46.723 Q8 expr_20_in_1: (uint8-98)
        // 11.189 Q8
        // expr_20_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Cast(expr_20_in_0, int32), [134]), [5]), Cast(expr_20_in_1, int32)), [227]), [10]), [23]), 0, 255), uint8)
        // _Add_13 scale arg 1 (no zp adj) - (uint8-98) 11.189 Q8 -> (int32-98) 89.513 Q11
        int _SYMBOL_Cast128 = ((int)expr_20_in_1[i0]);
        // scale clip and cast - (int32-525) 179.025 Q12 -> (uint8-93) 25.285 Q7
        expr_20_out_0[i0] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((int)expr_20_in_0[i0])*(134)), ((unsigned char)5))+_SYMBOL_Cast128)*(227)), ((unsigned char)10))-(23))), (((signed char)8))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void s85_kernel(s85_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned char *__restrict__  expr_22_in_0 = Args->expr_22_in_0; // (1, 16, 257, 65) (uint8-52) 23.989 Q8
    signed char *__restrict__  expr_22_in_1 = Args->expr_22_in_1; // (1, 16, 257, 1)  int8 1.401 Q7
    unsigned char *__restrict__  expr_22_out_0 = Args->expr_22_out_0; // (1, 16, 257, 65) (uint8-59) 23.448 Q8
    signed char *__restrict__  expr_22_out_1 = Args->expr_22_out_1; // (1, 16, 257, 65) int8 324.566 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // inter__conv_4_reg1_Sub: (1, 16, 257, 65) expr_22_in_0: (1, 16, 257, 65)
    // expr_22_in_1: (1, 16, 257, 1) expr_22_out_0: (1, 16, 257, 65)
    // expr_22_out_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2), (3,))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3,))
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_22_in_0: (uint8-52) 23.989 Q8 expr_22_in_1: int8
            // 1.401 Q7
            // inter__conv_4_reg1_Sub = Sub(Norm(Mul(Cast(expr_22_in_0, int32), [137]), [4]), Cast(expr_22_in_1, int32))
            // _conv_4_reg1_Sub scale arg 1 (no zp adj) - int8 1.401 Q7 -> int32 22.415 Q11
            int _SYMBOL_Cast185 = ((int)expr_22_in_1[i0]);
            int inter__conv_4_reg1_Sub = (gap_roundnorm_reg((((int)expr_22_in_0[(i0*I1)+i1])*(137)), ((unsigned char)4))-_SYMBOL_Cast185);
            // inputs inter__conv_4_reg1_Sub: (int32-445) 44.829 Q12
            // expr_22_out_0 = Cast(Clip(Sub(Norm(Mul(inter__conv_4_reg1_Sub, [245]), [11]), [-6]), 0, 255), uint8)
            // scale clip and cast - (int32-445) 44.829 Q12 -> (uint8-59) 23.448 Q8
            expr_22_out_0[(i0*I1)+i1] = ((unsigned char)gap_clipu(((gap_roundnorm_reg((inter__conv_4_reg1_Sub*(245)), ((unsigned char)11))-(-6))), (((signed char)8))));
            // inputs inter__conv_4_reg1_Sub: (int32-445) 44.829 Q12
            // expr_22_out_1 = Cast(Clip(Norm(Mul(Square1715(LShift(Sub(inter__conv_4_reg1_Sub, [445]), [3])), [198]), [13]), -128, 127), int8)
            // scale clip and cast - int32 2009.640 Q15 -> int8 324.566 Q7
            expr_22_out_1[(i0*I1)+i1] = ((signed char)gap_clip((gap_roundnorm_reg((square_17_15(((inter__conv_4_reg1_Sub-(445))<<((unsigned char)3)))*(198)), ((unsigned char)13))), (((signed char)7))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 3 external iteration spaces
void s89_kernel(s89_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    unsigned char *__restrict__  expr_23_in_0 = Args->expr_23_in_0; // (1, 16, 257, 65) (uint8-59) 23.448 Q8
    signed char *__restrict__  expr_23_in_1 = Args->expr_23_in_1; // (1, 16, 257, 1)  (int8--128) 2.492 Q7
    signed char *__restrict__  expr_23_in_2 = Args->expr_23_in_2; // (1, 16, 1, 1)    int8 1.022 Q7
    signed char *__restrict__  expr_23_in_3 = Args->expr_23_in_3; // (1, 16, 1, 1)    int8 0.013 Q7
    unsigned char *__restrict__  expr_23_out_0 = Args->expr_23_out_0; // (1, 16, 257, 65) (uint8-97) 5.873 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_23_out_0: (1, 16, 257, 65) expr_23_in_0: (1, 16, 257, 65)
    // expr_23_in_1: (1, 16, 257, 1) expr_23_in_2: (1, 16, 1, 1) expr_23_in_3:
    // (1, 16, 1, 1)
    // Iteration reduced to spaces ((1,), (2,), (3,))
    // Fixed spaces ((1,),)
    // Parameteric spaces ((2,), (3,))
    // Paralelized space (2,)
    // Interior spaces ()
    for (int i1=First; i1<Last; i1++) {
        for (int i2=0; i2<I2; i2++) {
            // inputs expr_23_in_0: (uint8-59) 23.448 Q8 expr_23_in_1:
            // (int8--128) 2.492 Q7 expr_23_in_2: int8 1.022 Q7 expr_23_in_3:
            // int8 59.742 Q7
            // expr_23_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Mul(Sub(Cast(expr_23_in_0, int32), [59]), Sub(Cast(expr_23_in_1, int32), [-128])), Cast(expr_23_in_2, int32)), [7]), LShift(Cast(expr_23_in_3, int32), [8])), [163]), [12]), [-97]), 0, 255), uint8)
            // scale clip and cast - int32 119.484 Q16 -> (uint8-97) 5.873 Q7
            expr_23_out_0[(i1*I2)+i2] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((((int)expr_23_in_0[(i1*I2)+i2])-(59))*(((int)expr_23_in_1[i1])-(-128)))*((int)expr_23_in_2[0])), (7))+(((int)expr_23_in_3[0])<<((unsigned char)8)))*(163)), ((unsigned char)12))-(-97))), (((signed char)8))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void s100_kernel(s100_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned char *__restrict__  expr_25_in_0 = Args->expr_25_in_0; // (1, 16, 257, 65) (uint8-27) 46.787 Q8
    signed char *__restrict__  expr_25_in_1 = Args->expr_25_in_1; // (1, 16, 257, 1)  int8 2.695 Q7
    unsigned char *__restrict__  expr_25_out_0 = Args->expr_25_out_0; // (1, 16, 257, 65) (uint8-36) 46.201 Q8
    signed char *__restrict__  expr_25_out_1 = Args->expr_25_out_1; // (1, 16, 257, 65) int8 1569.733 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // inter__conv_5_reg1_Sub: (1, 16, 257, 65) expr_25_in_0: (1, 16, 257, 65)
    // expr_25_in_1: (1, 16, 257, 1) expr_25_out_0: (1, 16, 257, 65)
    // expr_25_out_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2), (3,))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3,))
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_25_in_0: (uint8-27) 46.787 Q8 expr_25_in_1: int8
            // 2.695 Q7
            // inter__conv_5_reg1_Sub = Sub(Norm(Mul(Cast(expr_25_in_0, int32), [139]), [4]), Cast(expr_25_in_1, int32))
            // _conv_5_reg1_Sub scale arg 1 (no zp adj) - int8 2.695 Q7 -> int32 43.118 Q11
            int _SYMBOL_Cast176 = ((int)expr_25_in_1[i0]);
            int inter__conv_5_reg1_Sub = (gap_roundnorm_reg((((int)expr_25_in_0[(i0*I1)+i1])*(139)), ((unsigned char)4))-_SYMBOL_Cast176);
            // inputs inter__conv_5_reg1_Sub: (int32-235) 86.237 Q12
            // expr_25_out_0 = Cast(Clip(Sub(Norm(Mul(inter__conv_5_reg1_Sub, [239]), [11]), [-9]), 0, 255), uint8)
            // scale clip and cast - (int32-235) 86.237 Q12 -> (uint8-36) 46.201 Q8
            expr_25_out_0[(i0*I1)+i1] = ((unsigned char)gap_clipu(((gap_roundnorm_reg((inter__conv_5_reg1_Sub*(239)), ((unsigned char)11))-(-9))), (((signed char)8))));
            // inputs inter__conv_5_reg1_Sub: (int32-235) 86.237 Q12
            // expr_25_out_1 = Cast(Clip(Norm(Mul(Square1715(LShift(Sub(inter__conv_5_reg1_Sub, [235]), [3])), [152]), [13]), -128, 127), int8)
            // scale clip and cast - int32 7436.806 Q15 -> int8 1569.733 Q7
            expr_25_out_1[(i0*I1)+i1] = ((signed char)gap_clip((gap_roundnorm_reg((square_17_15(((inter__conv_5_reg1_Sub-(235))<<((unsigned char)3)))*(152)), ((unsigned char)13))), (((signed char)7))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 3 external iteration spaces
void s104_kernel(s104_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    unsigned char *__restrict__  expr_26_in_0 = Args->expr_26_in_0; // (1, 16, 257, 65) (uint8-36) 46.201 Q8
    signed char *__restrict__  expr_26_in_1 = Args->expr_26_in_1; // (1, 16, 257, 1)  (int8--128) 2.207 Q7
    signed char *__restrict__  expr_26_in_2 = Args->expr_26_in_2; // (1, 16, 1, 1)    int8 1.021 Q7
    signed char *__restrict__  expr_26_in_3 = Args->expr_26_in_3; // (1, 16, 1, 1)    int8 0.012 Q7
    unsigned char *__restrict__  expr_26_out_0 = Args->expr_26_out_0; // (1, 16, 257, 65) (uint8-101) 5.931 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_26_out_0: (1, 16, 257, 65) expr_26_in_0: (1, 16, 257, 65)
    // expr_26_in_1: (1, 16, 257, 1) expr_26_in_2: (1, 16, 1, 1) expr_26_in_3:
    // (1, 16, 1, 1)
    // Iteration reduced to spaces ((1,), (2,), (3,))
    // Fixed spaces ((1,),)
    // Parameteric spaces ((2,), (3,))
    // Paralelized space (2,)
    // Interior spaces ()
    for (int i1=First; i1<Last; i1++) {
        for (int i2=0; i2<I2; i2++) {
            // inputs expr_26_in_0: (uint8-36) 46.201 Q8 expr_26_in_1:
            // (int8--128) 2.207 Q7 expr_26_in_2: int8 1.021 Q7 expr_26_in_3:
            // int8 104.152 Q7
            // expr_26_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Mul(Sub(Cast(expr_26_in_0, int32), [36]), Sub(Cast(expr_26_in_1, int32), [-128])), Cast(expr_26_in_2, int32)), [7]), LShift(Cast(expr_26_in_3, int32), [8])), [140]), [11]), [-101]), 0, 255), uint8)
            // scale clip and cast - int32 208.305 Q16 -> (uint8-101) 5.931 Q7
            expr_26_out_0[(i1*I2)+i2] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((((int)expr_26_in_0[(i1*I2)+i2])-(36))*(((int)expr_26_in_1[i1])-(-128)))*((int)expr_26_in_2[0])), (7))+(((int)expr_26_in_3[0])<<((unsigned char)8)))*(140)), ((unsigned char)11))-(-101))), (((signed char)8))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void s115_kernel(s115_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned char *__restrict__  expr_28_in_0 = Args->expr_28_in_0; // (1, 16, 257, 65) (uint8-53) 43.124 Q8
    signed char *__restrict__  expr_28_in_1 = Args->expr_28_in_1; // (1, 16, 257, 1)  int8 2.917 Q7
    unsigned char *__restrict__  expr_28_out_0 = Args->expr_28_out_0; // (1, 16, 257, 65) (uint8-61) 42.189 Q8
    signed char *__restrict__  expr_28_out_1 = Args->expr_28_out_1; // (1, 16, 257, 65) int8 1027.832 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // inter__conv_6_reg1_Sub: (1, 16, 257, 65) expr_28_in_0: (1, 16, 257, 65)
    // expr_28_in_1: (1, 16, 257, 1) expr_28_out_0: (1, 16, 257, 65)
    // expr_28_out_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2), (3,))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3,))
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_28_in_0: (uint8-53) 43.124 Q8 expr_28_in_1: int8
            // 2.917 Q7
            // inter__conv_6_reg1_Sub = Sub(Norm(Mul(Cast(expr_28_in_0, int32), [237]), [5]), Cast(expr_28_in_1, int32))
            // _conv_6_reg1_Sub scale arg 1 (no zp adj) - int8 2.917 Q7 -> int32 23.334 Q10
            int _SYMBOL_Cast167 = ((int)expr_28_in_1[i0]);
            int inter__conv_6_reg1_Sub = (gap_roundnorm_reg((((int)expr_28_in_0[(i0*I1)+i1])*(237)), ((unsigned char)5))-_SYMBOL_Cast167);
            // inputs inter__conv_6_reg1_Sub: (int32-393) 46.667 Q11
            // expr_28_out_0 = Cast(Clip(Sub(Norm(Mul(inter__conv_6_reg1_Sub, [142]), [10]), [-7]), 0, 255), uint8)
            // scale clip and cast - (int32-393) 46.667 Q11 -> (uint8-61) 42.189 Q8
            expr_28_out_0[(i0*I1)+i1] = ((unsigned char)gap_clipu(((gap_roundnorm_reg((inter__conv_6_reg1_Sub*(142)), ((unsigned char)10))-(-7))), (((signed char)8))));
            // inputs inter__conv_6_reg1_Sub: (int32-393) 46.667 Q11
            // expr_28_out_1 = Cast(Clip(Norm(Mul(Square1715(LShift(Sub(inter__conv_6_reg1_Sub, [393]), [4])), [136]), [14]), -128, 127), int8)
            // scale clip and cast - int32 2177.830 Q15 -> int8 1027.832 Q7
            expr_28_out_1[(i0*I1)+i1] = ((signed char)gap_clip((gap_roundnorm_reg((square_17_15(((inter__conv_6_reg1_Sub-(393))<<((unsigned char)4)))*(136)), ((unsigned char)14))), (((signed char)7))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 3 external iteration spaces
void s119_kernel(s119_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    unsigned char *__restrict__  expr_29_in_0 = Args->expr_29_in_0; // (1, 16, 257, 65) (uint8-61) 42.189 Q8
    signed char *__restrict__  expr_29_in_1 = Args->expr_29_in_1; // (1, 16, 257, 1)  (int8--128) 1.874 Q7
    signed char *__restrict__  expr_29_in_2 = Args->expr_29_in_2; // (1, 16, 1, 1)    int8 1.017 Q7
    signed char *__restrict__  expr_29_in_3 = Args->expr_29_in_3; // (1, 16, 1, 1)    int8 0.012 Q7
    unsigned char *__restrict__  expr_29_out_0 = Args->expr_29_out_0; // (1, 16, 257, 65) (uint8-98) 5.595 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_29_out_0: (1, 16, 257, 65) expr_29_in_0: (1, 16, 257, 65)
    // expr_29_in_1: (1, 16, 257, 1) expr_29_in_2: (1, 16, 1, 1) expr_29_in_3:
    // (1, 16, 1, 1)
    // Iteration reduced to spaces ((1,), (2,), (3,))
    // Fixed spaces ((1,),)
    // Parameteric spaces ((2,), (3,))
    // Paralelized space (2,)
    // Interior spaces ()
    for (int i1=First; i1<Last; i1++) {
        for (int i2=0; i2<I2; i2++) {
            // inputs expr_29_in_0: (uint8-61) 42.189 Q8 expr_29_in_1:
            // (int8--128) 1.874 Q7 expr_29_in_2: int8 1.017 Q7 expr_29_in_3:
            // int8 80.398 Q7
            // expr_29_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Mul(Sub(Cast(expr_29_in_0, int32), [61]), Sub(Cast(expr_29_in_1, int32), [-128])), Cast(expr_29_in_2, int32)), [7]), LShift(Cast(expr_29_in_3, int32), [8])), [230]), [12]), [-98]), 0, 255), uint8)
            // scale clip and cast - int32 160.795 Q16 -> (uint8-98) 5.595 Q7
            expr_29_out_0[(i1*I2)+i2] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((((int)expr_29_in_0[(i1*I2)+i2])-(61))*(((int)expr_29_in_1[i1])-(-128)))*((int)expr_29_in_2[0])), (7))+(((int)expr_29_in_3[0])<<((unsigned char)8)))*(230)), ((unsigned char)12))-(-98))), (((signed char)8))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 2 external iteration spaces
void s130_kernel(s130_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned char *__restrict__  expr_31_in_0 = Args->expr_31_in_0; // (1, 16, 257, 65) (uint8-43) 32.247 Q8
    signed char *__restrict__  expr_31_in_1 = Args->expr_31_in_1; // (1, 16, 257, 1)  int8 2.978 Q7
    unsigned char *__restrict__  expr_31_out_0 = Args->expr_31_out_0; // (1, 16, 257, 65) (uint8-60) 32.250 Q8
    signed char *__restrict__  expr_31_out_1 = Args->expr_31_out_1; // (1, 16, 257, 65) int8 607.233 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 65) var shapes:
    // inter__conv_7_reg1_Sub: (1, 16, 257, 65) expr_31_in_0: (1, 16, 257, 65)
    // expr_31_in_1: (1, 16, 257, 1) expr_31_out_0: (1, 16, 257, 65)
    // expr_31_out_1: (1, 16, 257, 65)
    // Iteration reduced to spaces ((1, 2), (3,))
    // Fixed spaces ()
    // Parameteric spaces ((1, 2), (3,))
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        for (int i1=0; i1<I1; i1++) {
            // inputs expr_31_in_0: (uint8-43) 32.247 Q8 expr_31_in_1: int8
            // 2.978 Q7
            // inter__conv_7_reg1_Sub = Sub(Norm(Mul(Cast(expr_31_in_0, int32), [173]), [5]), Cast(expr_31_in_1, int32))
            // _conv_7_reg1_Sub scale arg 1 (no zp adj) - int8 2.978 Q7 -> int32 23.826 Q10
            int _SYMBOL_Cast158 = ((int)expr_31_in_1[i0]);
            int inter__conv_7_reg1_Sub = (gap_roundnorm_reg((((int)expr_31_in_0[(i0*I1)+i1])*(173)), ((unsigned char)5))-_SYMBOL_Cast158);
            // inputs inter__conv_7_reg1_Sub: (int32-232) 47.651 Q11
            // expr_31_out_0 = Cast(Clip(Sub(Norm(Mul(inter__conv_7_reg1_Sub, [189]), [10]), [-17]), 0, 255), uint8)
            // scale clip and cast - (int32-232) 47.651 Q11 -> (uint8-60) 32.250 Q8
            expr_31_out_0[(i0*I1)+i1] = ((unsigned char)gap_clipu(((gap_roundnorm_reg((inter__conv_7_reg1_Sub*(189)), ((unsigned char)10))-(-17))), (((signed char)8))));
            // inputs inter__conv_7_reg1_Sub: (int32-232) 47.651 Q11
            // expr_31_out_1 = Cast(Clip(Norm(Mul(Square1715(LShift(Sub(inter__conv_7_reg1_Sub, [232]), [4])), [239]), [14]), -128, 127), int8)
            // scale clip and cast - int32 2270.633 Q15 -> int8 607.233 Q7
            expr_31_out_1[(i0*I1)+i1] = ((signed char)gap_clip((gap_roundnorm_reg((square_17_15(((inter__conv_7_reg1_Sub-(232))<<((unsigned char)4)))*(239)), ((unsigned char)14))), (((signed char)7))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 3 external iteration spaces
void s134_kernel(s134_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned int I1 = Args->I1;
    unsigned int I2 = Args->I2;
    unsigned char *__restrict__  expr_32_in_0 = Args->expr_32_in_0; // (1, 16, 257, 65) (uint8-60) 32.250 Q8
    signed char *__restrict__  expr_32_in_1 = Args->expr_32_in_1; // (1, 16, 257, 1)  (int8--128) 1.906 Q7
    signed char *__restrict__  expr_32_in_2 = Args->expr_32_in_2; // (1, 16, 1, 1)    int8 1.026 Q7
    signed char *__restrict__  expr_32_in_3 = Args->expr_32_in_3; // (1, 16, 1, 1)    int8 0.008 Q7
    unsigned char *__restrict__  expr_32_out_0 = Args->expr_32_out_0; // (1, 16, 257, 65) (uint8-89) 5.210 Q7
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I1);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I1);
    // Max shape: (1, 16, 257, 65) var shapes:
    // expr_32_out_0: (1, 16, 257, 65) expr_32_in_0: (1, 16, 257, 65)
    // expr_32_in_1: (1, 16, 257, 1) expr_32_in_2: (1, 16, 1, 1) expr_32_in_3:
    // (1, 16, 1, 1)
    // Iteration reduced to spaces ((1,), (2,), (3,))
    // Fixed spaces ((1,),)
    // Parameteric spaces ((2,), (3,))
    // Paralelized space (2,)
    // Interior spaces ()
    for (int i1=First; i1<Last; i1++) {
        for (int i2=0; i2<I2; i2++) {
            // inputs expr_32_in_0: (uint8-60) 32.250 Q8 expr_32_in_1:
            // (int8--128) 1.906 Q7 expr_32_in_2: int8 1.026 Q7 expr_32_in_3:
            // int8 63.038 Q7
            // expr_32_out_0 = Cast(Clip(Sub(Norm(Mul(Add(Norm(Mul(Mul(Sub(Cast(expr_32_in_0, int32), [60]), Sub(Cast(expr_32_in_1, int32), [-128])), Cast(expr_32_in_2, int32)), [7]), LShift(Cast(expr_32_in_3, int32), [8])), [194]), [12]), [-89]), 0, 255), uint8)
            // scale clip and cast - int32 126.076 Q16 -> (uint8-89) 5.210 Q7
            expr_32_out_0[(i1*I2)+i2] = ((unsigned char)gap_clipu(((gap_roundnorm_reg(((gap_roundnorm_reg((((((int)expr_32_in_0[(i1*I2)+i2])-(60))*(((int)expr_32_in_1[i1])-(-128)))*((int)expr_32_in_2[0])), (7))+(((int)expr_32_in_3[0])<<((unsigned char)8)))*(194)), ((unsigned char)12))-(-89))), (((signed char)8))));
        }
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void s142_kernel(s142_kernel_args_t * __restrict__ Args) {
    unsigned int I0 = Args->I0;
    unsigned char *__restrict__  expr_33_in_0 = Args->expr_33_in_0; // (1, 257, 1, 1, 65) uint8 1.004 Q8
    float *__restrict__  expr_33_out_0 = Args->expr_33_out_0; // (1, 257, 1, 1, 65) f32
    unsigned int CoreId = gap_coreid();
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 257, 1, 1, 65) var shapes:
    // expr_33_out_0: (1, 257, 1, 1, 65) expr_33_in_0: (1, 257, 1, 1, 65)
    // Iteration reduced to spaces ((1, 4),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 4),)
    // Paralelized space (1, 4)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_33_in_0: uint8 1.004 Q8
        // expr_33_out_0 = Mul(Cast(Sub([255], Cast(expr_33_in_0, int32)), float32), [0.00392157])
        // _Sub scale arg 1 (equalize zp adj) - uint8 1.004 Q8 -> int32 1.004 Q8
        int _SYMBOL_Cast155 = ((int)expr_33_in_0[i0]);
        expr_33_out_0[i0] = (((float)((255)-_SYMBOL_Cast155))*(3.921569e-03f));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void expr_2(expr_2_args_t * __restrict__ Args) {
    signed char *__restrict__  expr_2_in_0 = Args->expr_2_in_0;
    signed char *__restrict__  expr_2_out_0 = Args->expr_2_out_0; // (1, 1, 1, 96)   
    unsigned int * __restrict__ RsqrtLUT = (unsigned int *)Args->RsqrtLUT;
    unsigned int CoreId = gap_coreid();
    unsigned int I0 = Args->W*Args->H*Args->Feat;
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 1) var shapes:
    // expr_2_out_0: (1, 16, 257, 1) expr_2_in_0: (1, 16, 257, 1) RsqrtLUT: (1,
    // 1, 1, 96)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_2_in_0: int8 0.753 Q7
        // expr_2_out_0 = Cast(Clip(Sub(Norm(Mul(Cast(Norm(RSqrt1616(Add(ScaleQuantized(expr_2_in_0, [int8 0.753 Q7]->[int32 0.753 Q7]), ScaleQuantized([1], [int32 0.000 Q0]->[int32 0.753 Q7])), RsqrtLUT), [12]), int32), [141]), [14]), [128]), -128, 127), int8)
        // _conv_0_reg1_Add scale arg 0 (equalize zp adj) - int8 0.753 Q7 -> int32 0.753 Q7
        int _SYMBOL_ScaleQuantized17 = ((int)expr_2_in_0[i0]);
        // _conv_0_reg1_Add scale arg 1 (equalize zp adj) - int32 0.000 Q0 -> int32 0.753 Q7
        int _SYMBOL_ScaleQuantized18 = (0);
        int _SYMBOL__conv_0_reg1_Add = (_SYMBOL_ScaleQuantized17+_SYMBOL_ScaleQuantized18);
        int _SYMBOL_Inv__conv_0_reg1_Sqrt = ((int)gap_roundnormu_reg(rsqrt_16_16_lut(_SYMBOL__conv_0_reg1_Add, RsqrtLUT), (12)));
        // scale clip and cast - int32 104.293 Q15 -> (int8--128) 47.174 Q7
        expr_2_out_0[i0] = ((signed char)gap_clip(((gap_roundnorm_reg((_SYMBOL_Inv__conv_0_reg1_Sqrt*(141)), ((unsigned char)14))-(128))), (((signed char)7))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void expr_5(expr_5_args_t * __restrict__ Args) {
    signed char *__restrict__  expr_5_in_0 = Args->expr_5_in_0;
    signed char *__restrict__  expr_5_out_0 = Args->expr_5_out_0; // (1, 1, 1, 96)   
    unsigned int * __restrict__ RsqrtLUT = (unsigned int *)Args->RsqrtLUT;
    unsigned int CoreId = gap_coreid();
    unsigned int I0 = Args->W*Args->H*Args->Feat;
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 1) var shapes:
    // expr_5_out_0: (1, 16, 257, 1) expr_5_in_0: (1, 16, 257, 1) RsqrtLUT: (1,
    // 1, 1, 96)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_5_in_0: int8 5.129 Q7
        // expr_5_out_0 = Cast(Clip(Sub(Norm(Mul(Cast(Norm(RSqrt1616(Add(ScaleQuantized(expr_5_in_0, [int8 5.129 Q7]->[int32 5.129 Q7]), ScaleQuantized([1], [int32 0.000 Q0]->[int32 5.129 Q7])), RsqrtLUT), [11]), int32), [151]), [14]), [128]), -128, 127), int8)
        // _conv_1_reg1_Add scale arg 0 (equalize zp adj) - int8 5.129 Q7 -> int32 5.129 Q7
        int _SYMBOL_ScaleQuantized35 = ((int)expr_5_in_0[i0]);
        // _conv_1_reg1_Add scale arg 1 (equalize zp adj) - int32 0.000 Q0 -> int32 5.129 Q7
        int _SYMBOL_ScaleQuantized36 = (0);
        int _SYMBOL__conv_1_reg1_Add = (_SYMBOL_ScaleQuantized35+_SYMBOL_ScaleQuantized36);
        int _SYMBOL_Inv__conv_1_reg1_Sqrt = ((int)gap_roundnormu_reg(rsqrt_16_16_lut(_SYMBOL__conv_1_reg1_Add, RsqrtLUT), (11)));
        // scale clip and cast - int32 19.981 Q15 -> (int8--128) 8.495 Q7
        expr_5_out_0[i0] = ((signed char)gap_clip(((gap_roundnorm_reg((_SYMBOL_Inv__conv_1_reg1_Sqrt*(151)), ((unsigned char)14))-(128))), (((signed char)7))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void expr_10(expr_10_args_t * __restrict__ Args) {
    signed char *__restrict__  expr_10_in_0 = Args->expr_10_in_0;
    signed char *__restrict__  expr_10_out_0 = Args->expr_10_out_0; // (1, 1, 1, 96)   
    unsigned int * __restrict__ RsqrtLUT = (unsigned int *)Args->RsqrtLUT;
    unsigned int CoreId = gap_coreid();
    unsigned int I0 = Args->W*Args->H*Args->Feat;
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 1) var shapes:
    // expr_10_out_0: (1, 16, 257, 1) expr_10_in_0: (1, 16, 257, 1) RsqrtLUT:
    // (1, 1, 1, 96)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_10_in_0: int8 8.029 Q7
        // expr_10_out_0 = Cast(Clip(Sub(Norm(Mul(Cast(Norm(RSqrt1616(Add(ScaleQuantized(expr_10_in_0, [int8 8.029 Q7]->[int32 8.029 Q7]), ScaleQuantized([1], [int32 0.000 Q0]->[int32 8.029 Q7])), RsqrtLUT), [10]), int32), [137]), [14]), [128]), -128, 127), int8)
        // _conv_2_reg1_Add scale arg 0 (equalize zp adj) - int8 8.029 Q7 -> int32 8.029 Q7
        int _SYMBOL_ScaleQuantized53 = ((int)expr_10_in_0[i0]);
        // _conv_2_reg1_Add scale arg 1 (equalize zp adj) - int32 0.000 Q0 -> int32 8.029 Q7
        int _SYMBOL_ScaleQuantized54 = (0);
        int _SYMBOL__conv_2_reg1_Add = (_SYMBOL_ScaleQuantized53+_SYMBOL_ScaleQuantized54);
        int _SYMBOL_Inv__conv_2_reg1_Sqrt = ((int)gap_roundnormu_reg(rsqrt_16_16_lut(_SYMBOL__conv_2_reg1_Add, RsqrtLUT), (10)));
        // scale clip and cast - int32 7.985 Q15 -> (int8--128) 3.735 Q7
        expr_10_out_0[i0] = ((signed char)gap_clip(((gap_roundnorm_reg((_SYMBOL_Inv__conv_2_reg1_Sqrt*(137)), ((unsigned char)14))-(128))), (((signed char)7))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void expr_15(expr_15_args_t * __restrict__ Args) {
    signed char *__restrict__  expr_15_in_0 = Args->expr_15_in_0;
    signed char *__restrict__  expr_15_out_0 = Args->expr_15_out_0; // (1, 1, 1, 96)   
    unsigned int * __restrict__ RsqrtLUT = (unsigned int *)Args->RsqrtLUT;
    unsigned int CoreId = gap_coreid();
    unsigned int I0 = Args->W*Args->H*Args->Feat;
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 1) var shapes:
    // expr_15_out_0: (1, 16, 257, 1) expr_15_in_0: (1, 16, 257, 1) RsqrtLUT:
    // (1, 1, 1, 96)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_15_in_0: int8 11.082 Q7
        // expr_15_out_0 = Cast(Clip(Sub(Norm(Mul(Cast(Norm(RSqrt1616(Add(ScaleQuantized(expr_15_in_0, [int8 11.082 Q7]->[int32 11.082 Q7]), ScaleQuantized([1], [int32 0.000 Q0]->[int32 11.082 Q7])), RsqrtLUT), [11]), int32), [236]), [14]), [128]), -128, 127), int8)
        // _conv_3_reg1_Add scale arg 0 (equalize zp adj) - int8 11.082 Q7 -> int32 11.082 Q7
        int _SYMBOL_ScaleQuantized71 = ((int)expr_15_in_0[i0]);
        // _conv_3_reg1_Add scale arg 1 (equalize zp adj) - int32 0.000 Q0 -> int32 11.082 Q7
        int _SYMBOL_ScaleQuantized72 = (0);
        int _SYMBOL__conv_3_reg1_Add = (_SYMBOL_ScaleQuantized71+_SYMBOL_ScaleQuantized72);
        int _SYMBOL_Inv__conv_3_reg1_Sqrt = ((int)gap_roundnormu_reg(rsqrt_16_16_lut(_SYMBOL__conv_3_reg1_Add, RsqrtLUT), (11)));
        // scale clip and cast - int32 13.594 Q15 -> (int8--128) 3.687 Q7
        expr_15_out_0[i0] = ((signed char)gap_clip(((gap_roundnorm_reg((_SYMBOL_Inv__conv_3_reg1_Sqrt*(236)), ((unsigned char)14))-(128))), (((signed char)7))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void expr_21(expr_21_args_t * __restrict__ Args) {
    signed char *__restrict__  expr_21_in_0 = Args->expr_21_in_0;
    signed char *__restrict__  expr_21_out_0 = Args->expr_21_out_0; // (1, 1, 1, 96)   
    unsigned int * __restrict__ RsqrtLUT = (unsigned int *)Args->RsqrtLUT;
    unsigned int CoreId = gap_coreid();
    unsigned int I0 = Args->W*Args->H*Args->Feat;
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 1) var shapes:
    // expr_21_out_0: (1, 16, 257, 1) expr_21_in_0: (1, 16, 257, 1) RsqrtLUT:
    // (1, 1, 1, 96)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_21_in_0: int8 10.095 Q7
        // expr_21_out_0 = Cast(Clip(Sub(Norm(Mul(Cast(Norm(RSqrt1616(Add(ScaleQuantized(expr_21_in_0, [int8 10.095 Q7]->[int32 10.095 Q7]), ScaleQuantized([1], [int32 0.000 Q0]->[int32 10.095 Q7])), RsqrtLUT), [10]), int32), [183]), [14]), [128]), -128, 127), int8)
        // _conv_4_reg1_Add scale arg 0 (equalize zp adj) - int8 10.095 Q7 -> int32 10.095 Q7
        int _SYMBOL_ScaleQuantized89 = ((int)expr_21_in_0[i0]);
        // _conv_4_reg1_Add scale arg 1 (equalize zp adj) - int32 0.000 Q0 -> int32 10.095 Q7
        int _SYMBOL_ScaleQuantized90 = (0);
        int _SYMBOL__conv_4_reg1_Add = (_SYMBOL_ScaleQuantized89+_SYMBOL_ScaleQuantized90);
        int _SYMBOL_Inv__conv_4_reg1_Sqrt = ((int)gap_roundnormu_reg(rsqrt_16_16_lut(_SYMBOL__conv_4_reg1_Add, RsqrtLUT), (10)));
        // scale clip and cast - int32 7.122 Q15 -> (int8--128) 2.492 Q7
        expr_21_out_0[i0] = ((signed char)gap_clip(((gap_roundnorm_reg((_SYMBOL_Inv__conv_4_reg1_Sqrt*(183)), ((unsigned char)14))-(128))), (((signed char)7))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void expr_24(expr_24_args_t * __restrict__ Args) {
    signed char *__restrict__  expr_24_in_0 = Args->expr_24_in_0;
    signed char *__restrict__  expr_24_out_0 = Args->expr_24_out_0; // (1, 1, 1, 96)   
    unsigned int * __restrict__ RsqrtLUT = (unsigned int *)Args->RsqrtLUT;
    unsigned int CoreId = gap_coreid();
    unsigned int I0 = Args->W*Args->H*Args->Feat;
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 1) var shapes:
    // expr_24_out_0: (1, 16, 257, 1) expr_24_in_0: (1, 16, 257, 1) RsqrtLUT:
    // (1, 1, 1, 96)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_24_in_0: int8 50.284 Q7
        // expr_24_out_0 = Cast(Clip(Sub(Norm(Mul(Cast(Norm(RSqrt1616(Add(ScaleQuantized(expr_24_in_0, [int8 50.284 Q7]->[int32 50.284 Q7]), ScaleQuantized([1], [int32 0.000 Q0]->[int32 50.284 Q7])), RsqrtLUT), [11]), int32), [185]), [14]), [128]), -128, 127), int8)
        // _conv_5_reg1_Add scale arg 0 (equalize zp adj) - int8 50.284 Q7 -> int32 50.284 Q7
        int _SYMBOL_ScaleQuantized107 = ((int)expr_24_in_0[i0]);
        // _conv_5_reg1_Add scale arg 1 (equalize zp adj) - int32 0.000 Q0 -> int32 50.284 Q7
        int _SYMBOL_ScaleQuantized108 = (0);
        int _SYMBOL__conv_5_reg1_Add = (_SYMBOL_ScaleQuantized107+_SYMBOL_ScaleQuantized108);
        int _SYMBOL_Inv__conv_5_reg1_Sqrt = ((int)gap_roundnormu_reg(rsqrt_16_16_lut(_SYMBOL__conv_5_reg1_Add, RsqrtLUT), (11)));
        // scale clip and cast - int32 6.382 Q15 -> (int8--128) 2.207 Q7
        expr_24_out_0[i0] = ((signed char)gap_clip(((gap_roundnorm_reg((_SYMBOL_Inv__conv_5_reg1_Sqrt*(185)), ((unsigned char)14))-(128))), (((signed char)7))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void expr_27(expr_27_args_t * __restrict__ Args) {
    signed char *__restrict__  expr_27_in_0 = Args->expr_27_in_0;
    signed char *__restrict__  expr_27_out_0 = Args->expr_27_out_0; // (1, 1, 1, 96)   
    unsigned int * __restrict__ RsqrtLUT = (unsigned int *)Args->RsqrtLUT;
    unsigned int CoreId = gap_coreid();
    unsigned int I0 = Args->W*Args->H*Args->Feat;
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 1) var shapes:
    // expr_27_out_0: (1, 16, 257, 1) expr_27_in_0: (1, 16, 257, 1) RsqrtLUT:
    // (1, 1, 1, 96)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_27_in_0: int8 55.331 Q7
        // expr_27_out_0 = Cast(Clip(Sub(Norm(Mul(Cast(Norm(RSqrt1616(Add(ScaleQuantized(expr_27_in_0, [int8 55.331 Q7]->[int32 55.331 Q7]), ScaleQuantized([1], [int32 0.000 Q0]->[int32 55.331 Q7])), RsqrtLUT), [11]), int32), [208]), [14]), [128]), -128, 127), int8)
        // _conv_6_reg1_Add scale arg 0 (equalize zp adj) - int8 55.331 Q7 -> int32 55.331 Q7
        int _SYMBOL_ScaleQuantized125 = ((int)expr_27_in_0[i0]);
        // _conv_6_reg1_Add scale arg 1 (equalize zp adj) - int32 0.000 Q0 -> int32 55.331 Q7
        int _SYMBOL_ScaleQuantized126 = (0);
        int _SYMBOL__conv_6_reg1_Add = (_SYMBOL_ScaleQuantized125+_SYMBOL_ScaleQuantized126);
        int _SYMBOL_Inv__conv_6_reg1_Sqrt = ((int)gap_roundnormu_reg(rsqrt_16_16_lut(_SYMBOL__conv_6_reg1_Add, RsqrtLUT), (11)));
        // scale clip and cast - int32 6.084 Q15 -> (int8--128) 1.874 Q7
        expr_27_out_0[i0] = ((signed char)gap_clip(((gap_roundnorm_reg((_SYMBOL_Inv__conv_6_reg1_Sqrt*(208)), ((unsigned char)14))-(128))), (((signed char)7))));
    }
    gap_waitbarrier(0);
}

// Output iteration space reduced to 0 internal and 1 external iteration spaces
void expr_30(expr_30_args_t * __restrict__ Args) {
    signed char *__restrict__  expr_30_in_0 = Args->expr_30_in_0;
    signed char *__restrict__  expr_30_out_0 = Args->expr_30_out_0; // (1, 1, 1, 96)   
    unsigned int * __restrict__ RsqrtLUT = (unsigned int *)Args->RsqrtLUT;
    unsigned int CoreId = gap_coreid();
    unsigned int I0 = Args->W*Args->H*Args->Feat;
    unsigned int Chunk = ChunkSize(I0);
    unsigned int First = Chunk*CoreId;
    unsigned int Last = gap_min(First+Chunk, I0);
    // Max shape: (1, 16, 257, 1) var shapes:
    // expr_30_out_0: (1, 16, 257, 1) expr_30_in_0: (1, 16, 257, 1) RsqrtLUT:
    // (1, 1, 1, 96)
    // Iteration reduced to spaces ((1, 2),)
    // Fixed spaces ()
    // Parameteric spaces ((1, 2),)
    // Paralelized space (1, 2)
    // Interior spaces ()
    for (int i0=First; i0<Last; i0++) {
        // inputs expr_30_in_0: int8 32.753 Q7
        // expr_30_out_0 = Cast(Clip(Sub(Norm(Mul(Cast(Norm(RSqrt1616(Add(ScaleQuantized(expr_30_in_0, [int8 32.753 Q7]->[int32 32.753 Q7]), ScaleQuantized([1], [int32 0.000 Q0]->[int32 32.753 Q7])), RsqrtLUT), [10]), int32), [133]), [14]), [128]), -128, 127), int8)
        // _conv_7_reg1_Add scale arg 0 (equalize zp adj) - int8 32.753 Q7 -> int32 32.753 Q7
        int _SYMBOL_ScaleQuantized143 = ((int)expr_30_in_0[i0]);
        // _conv_7_reg1_Add scale arg 1 (equalize zp adj) - int32 0.000 Q0 -> int32 32.753 Q7
        int _SYMBOL_ScaleQuantized144 = (-1);
        int _SYMBOL__conv_7_reg1_Add = (_SYMBOL_ScaleQuantized143+_SYMBOL_ScaleQuantized144);
        int _SYMBOL_Inv__conv_7_reg1_Sqrt = ((int)gap_roundnormu_reg(rsqrt_16_16_lut(_SYMBOL__conv_7_reg1_Add, RsqrtLUT), (10)));
        // scale clip and cast - int32 3.954 Q15 -> (int8--128) 1.906 Q7
        expr_30_out_0[i0] = ((signed char)gap_clip(((gap_roundnorm_reg((_SYMBOL_Inv__conv_7_reg1_Sqrt*(133)), ((unsigned char)14))-(128))), (((signed char)7))));
    }
    gap_waitbarrier(0);
}


#pragma GCC diagnostic pop