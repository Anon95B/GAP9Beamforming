#include <stdint.h>
#include <stdio.h>
#include "AutoTilerLib.h"
#include "CNN_Generators_SQ8.h"
#include "CNN_Generators.h"
#include "CNN_Generators_fp16.h"
#include "CNN_Generators_NE16.h"

#include "CNN_Copy_Generators.h"

void load_expressions_kernels() {
    LibKernelTemplate(
        "s5_kernel_args_t",
        CArgs(6,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("signed char *__restrict__ ", "expr_0_in_0"),
            TCArg("signed char *__restrict__ ", "expr_0_in_1"),
            TCArg("signed char *__restrict__ ", "expr_0_out_0"),
            TCArg("signed char *__restrict__ ", "expr_0_out_1")
        )
    );
    
    LibKernel(
        "s5_kernel",
        CALL_PARALLEL,
        0,
        "s5_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s9_kernel_args_t",
        CArgs(9,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned int", "I2"),
            TCArg("unsigned int *__restrict__ ", "RsqrtLUT"),
            TCArg("signed char *__restrict__ ", "expr_1_in_0"),
            TCArg("signed char *__restrict__ ", "expr_1_in_1"),
            TCArg("signed char *__restrict__ ", "expr_1_in_2"),
            TCArg("signed char *__restrict__ ", "expr_1_in_3"),
            TCArg("unsigned char *__restrict__ ", "expr_1_out_0")
        )
    );
    
    LibKernel(
        "s9_kernel",
        CALL_PARALLEL,
        0,
        "s9_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s26_kernel_args_t",
        CArgs(6,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned char *__restrict__ ", "expr_3_in_0"),
            TCArg("signed char *__restrict__ ", "expr_3_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_3_out_0"),
            TCArg("signed char *__restrict__ ", "expr_3_out_1")
        )
    );
    
    LibKernel(
        "s26_kernel",
        CALL_PARALLEL,
        0,
        "s26_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s135_kernel_args_t",
        CArgs(10,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_4_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_4_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_4_in_2"),
            TCArg("unsigned char *__restrict__ ", "expr_4_in_3"),
            TCArg("unsigned char *__restrict__ ", "expr_4_in_4"),
            TCArg("unsigned char *__restrict__ ", "expr_4_in_5"),
            TCArg("unsigned char *__restrict__ ", "expr_4_in_6"),
            TCArg("unsigned char *__restrict__ ", "expr_4_in_7"),
            TCArg("unsigned char *__restrict__ ", "expr_4_out_0")
        )
    );
    
    LibKernel(
        "s135_kernel",
        CALL_PARALLEL,
        0,
        "s135_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s30_kernel_args_t",
        CArgs(10,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned int", "I2"),
            TCArg("unsigned char *__restrict__ ", "expr_6_in_0"),
            TCArg("signed char *__restrict__ ", "expr_6_in_1"),
            TCArg("signed char *__restrict__ ", "expr_6_in_2"),
            TCArg("signed char *__restrict__ ", "expr_6_in_3"),
            TCArg("unsigned char *__restrict__ ", "expr_6_in_4"),
            TCArg("unsigned char *__restrict__ ", "expr_6_out_0"),
            TCArg("unsigned char *__restrict__ ", "expr_6_out_1")
        )
    );
    
    LibKernel(
        "s30_kernel",
        CALL_PARALLEL,
        0,
        "s30_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s40_kernel_args_t",
        CArgs(6,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned char *__restrict__ ", "expr_7_in_0"),
            TCArg("signed char *__restrict__ ", "expr_7_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_7_out_0"),
            TCArg("signed char *__restrict__ ", "expr_7_out_1")
        )
    );
    
    LibKernel(
        "s40_kernel",
        CALL_PARALLEL,
        0,
        "s40_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s44_kernel_args_t",
        CArgs(8,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned int", "I2"),
            TCArg("unsigned char *__restrict__ ", "expr_8_in_0"),
            TCArg("signed char *__restrict__ ", "expr_8_in_1"),
            TCArg("signed char *__restrict__ ", "expr_8_in_2"),
            TCArg("signed char *__restrict__ ", "expr_8_in_3"),
            TCArg("unsigned char *__restrict__ ", "expr_8_out_0")
        )
    );
    
    LibKernel(
        "s44_kernel",
        CALL_PARALLEL,
        0,
        "s44_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s45_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_9_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_9_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_9_out_0")
        )
    );
    
    LibKernel(
        "s45_kernel",
        CALL_PARALLEL,
        0,
        "s45_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s60_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_11_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_11_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_11_out_0")
        )
    );
    
    LibKernel(
        "s60_kernel",
        CALL_PARALLEL,
        0,
        "s60_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s55_kernel_args_t",
        CArgs(6,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned char *__restrict__ ", "expr_12_in_0"),
            TCArg("signed char *__restrict__ ", "expr_12_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_12_out_0"),
            TCArg("signed char *__restrict__ ", "expr_12_out_1")
        )
    );
    
    LibKernel(
        "s55_kernel",
        CALL_PARALLEL,
        0,
        "s55_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s59_kernel_args_t",
        CArgs(8,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned int", "I2"),
            TCArg("unsigned char *__restrict__ ", "expr_13_in_0"),
            TCArg("signed char *__restrict__ ", "expr_13_in_1"),
            TCArg("signed char *__restrict__ ", "expr_13_in_2"),
            TCArg("signed char *__restrict__ ", "expr_13_in_3"),
            TCArg("unsigned char *__restrict__ ", "expr_13_out_0")
        )
    );
    
    LibKernel(
        "s59_kernel",
        CALL_PARALLEL,
        0,
        "s59_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s75_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_14_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_14_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_14_out_0")
        )
    );
    
    LibKernel(
        "s75_kernel",
        CALL_PARALLEL,
        0,
        "s75_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s90_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_16_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_16_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_16_out_0")
        )
    );
    
    LibKernel(
        "s90_kernel",
        CALL_PARALLEL,
        0,
        "s90_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s70_kernel_args_t",
        CArgs(6,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned char *__restrict__ ", "expr_17_in_0"),
            TCArg("signed char *__restrict__ ", "expr_17_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_17_out_0"),
            TCArg("signed char *__restrict__ ", "expr_17_out_1")
        )
    );
    
    LibKernel(
        "s70_kernel",
        CALL_PARALLEL,
        0,
        "s70_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s74_kernel_args_t",
        CArgs(8,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned int", "I2"),
            TCArg("unsigned char *__restrict__ ", "expr_18_in_0"),
            TCArg("signed char *__restrict__ ", "expr_18_in_1"),
            TCArg("signed char *__restrict__ ", "expr_18_in_2"),
            TCArg("signed char *__restrict__ ", "expr_18_in_3"),
            TCArg("unsigned char *__restrict__ ", "expr_18_out_0")
        )
    );
    
    LibKernel(
        "s74_kernel",
        CALL_PARALLEL,
        0,
        "s74_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s105_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_19_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_19_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_19_out_0")
        )
    );
    
    LibKernel(
        "s105_kernel",
        CALL_PARALLEL,
        0,
        "s105_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s120_kernel_args_t",
        CArgs(4,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_20_in_0"),
            TCArg("unsigned char *__restrict__ ", "expr_20_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_20_out_0")
        )
    );
    
    LibKernel(
        "s120_kernel",
        CALL_PARALLEL,
        0,
        "s120_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s85_kernel_args_t",
        CArgs(6,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned char *__restrict__ ", "expr_22_in_0"),
            TCArg("signed char *__restrict__ ", "expr_22_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_22_out_0"),
            TCArg("signed char *__restrict__ ", "expr_22_out_1")
        )
    );
    
    LibKernel(
        "s85_kernel",
        CALL_PARALLEL,
        0,
        "s85_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s89_kernel_args_t",
        CArgs(8,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned int", "I2"),
            TCArg("unsigned char *__restrict__ ", "expr_23_in_0"),
            TCArg("signed char *__restrict__ ", "expr_23_in_1"),
            TCArg("signed char *__restrict__ ", "expr_23_in_2"),
            TCArg("signed char *__restrict__ ", "expr_23_in_3"),
            TCArg("unsigned char *__restrict__ ", "expr_23_out_0")
        )
    );
    
    LibKernel(
        "s89_kernel",
        CALL_PARALLEL,
        0,
        "s89_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s100_kernel_args_t",
        CArgs(6,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned char *__restrict__ ", "expr_25_in_0"),
            TCArg("signed char *__restrict__ ", "expr_25_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_25_out_0"),
            TCArg("signed char *__restrict__ ", "expr_25_out_1")
        )
    );
    
    LibKernel(
        "s100_kernel",
        CALL_PARALLEL,
        0,
        "s100_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s104_kernel_args_t",
        CArgs(8,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned int", "I2"),
            TCArg("unsigned char *__restrict__ ", "expr_26_in_0"),
            TCArg("signed char *__restrict__ ", "expr_26_in_1"),
            TCArg("signed char *__restrict__ ", "expr_26_in_2"),
            TCArg("signed char *__restrict__ ", "expr_26_in_3"),
            TCArg("unsigned char *__restrict__ ", "expr_26_out_0")
        )
    );
    
    LibKernel(
        "s104_kernel",
        CALL_PARALLEL,
        0,
        "s104_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s115_kernel_args_t",
        CArgs(6,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned char *__restrict__ ", "expr_28_in_0"),
            TCArg("signed char *__restrict__ ", "expr_28_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_28_out_0"),
            TCArg("signed char *__restrict__ ", "expr_28_out_1")
        )
    );
    
    LibKernel(
        "s115_kernel",
        CALL_PARALLEL,
        0,
        "s115_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s119_kernel_args_t",
        CArgs(8,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned int", "I2"),
            TCArg("unsigned char *__restrict__ ", "expr_29_in_0"),
            TCArg("signed char *__restrict__ ", "expr_29_in_1"),
            TCArg("signed char *__restrict__ ", "expr_29_in_2"),
            TCArg("signed char *__restrict__ ", "expr_29_in_3"),
            TCArg("unsigned char *__restrict__ ", "expr_29_out_0")
        )
    );
    
    LibKernel(
        "s119_kernel",
        CALL_PARALLEL,
        0,
        "s119_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s130_kernel_args_t",
        CArgs(6,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned char *__restrict__ ", "expr_31_in_0"),
            TCArg("signed char *__restrict__ ", "expr_31_in_1"),
            TCArg("unsigned char *__restrict__ ", "expr_31_out_0"),
            TCArg("signed char *__restrict__ ", "expr_31_out_1")
        )
    );
    
    LibKernel(
        "s130_kernel",
        CALL_PARALLEL,
        0,
        "s130_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s134_kernel_args_t",
        CArgs(8,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned int", "I1"),
            TCArg("unsigned int", "I2"),
            TCArg("unsigned char *__restrict__ ", "expr_32_in_0"),
            TCArg("signed char *__restrict__ ", "expr_32_in_1"),
            TCArg("signed char *__restrict__ ", "expr_32_in_2"),
            TCArg("signed char *__restrict__ ", "expr_32_in_3"),
            TCArg("unsigned char *__restrict__ ", "expr_32_out_0")
        )
    );
    
    LibKernel(
        "s134_kernel",
        CALL_PARALLEL,
        0,
        "s134_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "s142_kernel_args_t",
        CArgs(3,
            TCArg("unsigned int", "I0"),
            TCArg("unsigned char *__restrict__ ", "expr_33_in_0"),
            TCArg("float *__restrict__ ", "expr_33_out_0")
        )
    );
    
    LibKernel(
        "s142_kernel",
        CALL_PARALLEL,
        0,
        "s142_kernel_args_t",
        0
    );
    LibKernelTemplate(
        "expr_2_args_t",
        CArgs(6,
            TCArg("signed char *__restrict__ ", "expr_2_in_0"),
            TCArg("signed char *__restrict__ ", "expr_2_out_0"),
            TCArg("unsigned short int", "W"),
            TCArg("unsigned short int", "H"),
            TCArg("unsigned short int", "Feat"),
            TCArg("unsigned int * __restrict__", "RsqrtLUT")
        )
    );
    
    LibKernel(
        "expr_2",
        CALL_PARALLEL,
        0,
        "expr_2_args_t",
        0
    );
    LibKernelTemplate(
        "expr_5_args_t",
        CArgs(6,
            TCArg("signed char *__restrict__ ", "expr_5_in_0"),
            TCArg("signed char *__restrict__ ", "expr_5_out_0"),
            TCArg("unsigned short int", "W"),
            TCArg("unsigned short int", "H"),
            TCArg("unsigned short int", "Feat"),
            TCArg("unsigned int * __restrict__", "RsqrtLUT")
        )
    );
    
    LibKernel(
        "expr_5",
        CALL_PARALLEL,
        0,
        "expr_5_args_t",
        0
    );
    LibKernelTemplate(
        "expr_10_args_t",
        CArgs(6,
            TCArg("signed char *__restrict__ ", "expr_10_in_0"),
            TCArg("signed char *__restrict__ ", "expr_10_out_0"),
            TCArg("unsigned short int", "W"),
            TCArg("unsigned short int", "H"),
            TCArg("unsigned short int", "Feat"),
            TCArg("unsigned int * __restrict__", "RsqrtLUT")
        )
    );
    
    LibKernel(
        "expr_10",
        CALL_PARALLEL,
        0,
        "expr_10_args_t",
        0
    );
    LibKernelTemplate(
        "expr_15_args_t",
        CArgs(6,
            TCArg("signed char *__restrict__ ", "expr_15_in_0"),
            TCArg("signed char *__restrict__ ", "expr_15_out_0"),
            TCArg("unsigned short int", "W"),
            TCArg("unsigned short int", "H"),
            TCArg("unsigned short int", "Feat"),
            TCArg("unsigned int * __restrict__", "RsqrtLUT")
        )
    );
    
    LibKernel(
        "expr_15",
        CALL_PARALLEL,
        0,
        "expr_15_args_t",
        0
    );
    LibKernelTemplate(
        "expr_21_args_t",
        CArgs(6,
            TCArg("signed char *__restrict__ ", "expr_21_in_0"),
            TCArg("signed char *__restrict__ ", "expr_21_out_0"),
            TCArg("unsigned short int", "W"),
            TCArg("unsigned short int", "H"),
            TCArg("unsigned short int", "Feat"),
            TCArg("unsigned int * __restrict__", "RsqrtLUT")
        )
    );
    
    LibKernel(
        "expr_21",
        CALL_PARALLEL,
        0,
        "expr_21_args_t",
        0
    );
    LibKernelTemplate(
        "expr_24_args_t",
        CArgs(6,
            TCArg("signed char *__restrict__ ", "expr_24_in_0"),
            TCArg("signed char *__restrict__ ", "expr_24_out_0"),
            TCArg("unsigned short int", "W"),
            TCArg("unsigned short int", "H"),
            TCArg("unsigned short int", "Feat"),
            TCArg("unsigned int * __restrict__", "RsqrtLUT")
        )
    );
    
    LibKernel(
        "expr_24",
        CALL_PARALLEL,
        0,
        "expr_24_args_t",
        0
    );
    LibKernelTemplate(
        "expr_27_args_t",
        CArgs(6,
            TCArg("signed char *__restrict__ ", "expr_27_in_0"),
            TCArg("signed char *__restrict__ ", "expr_27_out_0"),
            TCArg("unsigned short int", "W"),
            TCArg("unsigned short int", "H"),
            TCArg("unsigned short int", "Feat"),
            TCArg("unsigned int * __restrict__", "RsqrtLUT")
        )
    );
    
    LibKernel(
        "expr_27",
        CALL_PARALLEL,
        0,
        "expr_27_args_t",
        0
    );
    LibKernelTemplate(
        "expr_30_args_t",
        CArgs(6,
            TCArg("signed char *__restrict__ ", "expr_30_in_0"),
            TCArg("signed char *__restrict__ ", "expr_30_out_0"),
            TCArg("unsigned short int", "W"),
            TCArg("unsigned short int", "H"),
            TCArg("unsigned short int", "Feat"),
            TCArg("unsigned int * __restrict__", "RsqrtLUT")
        )
    );
    
    LibKernel(
        "expr_30",
        CALL_PARALLEL,
        0,
        "expr_30_args_t",
        0
    );
}



int s5_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 2, 257, 65) spaces: ((1, 2), (3,)) 
        // parametric_spaces: ((1, 2), (3,)) 
        // exterior_shape: (514, 65.0) 
        KernelIterSpace(3, IterParSpace(KER_ITER_D0, 514, 1), IterParSpace(KER_ITER_D1, 65, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(4,
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_0_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_0_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_0_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_0_out_1")
        ),
        Calls(1,
            Call("s5_kernel", LOC_D1,
                Bindings(6,
                    K_ArgPar("expr_0_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_0_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_Arg("expr_0_in_0", KER_ARG_TILE),
                    K_Arg("expr_0_in_1", KER_ARG_TILE),
                    K_Arg("expr_0_out_0", KER_ARG_TILE),
                    K_Arg("expr_0_out_1", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_0_in_0 axes: (0, 1)
        // var: expr_0_in_1 axes: (0,)
        // var: expr_0_out_0 axes: (0, 1)
        // var: expr_0_out_1 axes: (0, 1)
        KerArgs(4,
            KerArg("expr_0_in_0",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_0_in_0"),
            KerArg("expr_0_in_1",  KerArgSpace(1, KER_ITER_D0),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_0_in_1"),
            KerArg("expr_0_out_0", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_0_out_0"),
            KerArg("expr_0_out_1", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_0_out_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 133640, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 100744, 0);
        AddKernelArgDimExplicit(Name, "expr_0_in_0", ARG_INT,  4, 2, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_0_in_1", ARG_INT,  4, 2, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_0_out_0", ARG_INT, 4, 2, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_0_out_1", ARG_INT, 4, 2, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s9_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 2, 257, 65) spaces: ((1,), (2,), (3,)) 
        // fixed_spaces: ((1,),) parametric_spaces: ((2,), (3,)) 
        // exterior_shape: (2, 257, 65.0) 
        KernelIterSpace(4, IterFixedSpace(KER_ITER_D0, 2), IterParSpace(KER_ITER_D1, 257, 8), IterParSpace(KER_ITER_D2, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(6,
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_1_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_1_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_1_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_1_in_3"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_1_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(-4, 1, 1, ARG_INT), "RsqrtLUT")
        ),
        Calls(1,
            Call("s9_kernel", LOC_D2,
                Bindings(9,
                    K_ArgPar("expr_1_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_1_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_ArgPar("expr_1_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D2),
                    K_Arg("RsqrtLUT", KER_ARG_TILE),
                    K_Arg("expr_1_in_0", KER_ARG_TILE),
                    K_Arg("expr_1_in_1", KER_ARG_TILE),
                    K_Arg("expr_1_in_2", KER_ARG_TILE),
                    K_Arg("expr_1_in_3", KER_ARG_TILE),
                    K_Arg("expr_1_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_1_out_0 axes: (0, 1, 2)
        // var: expr_1_in_1 axes: (0, 1, 2)
        // var: expr_1_in_0 axes: (0, 1)
        // var: expr_1_in_2 axes: (0,)
        // var: expr_1_in_3 axes: (0,)
        KerArgs(6,
            KerArg("expr_1_out_0", KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_OUT|O_DB,                   1, 1, 1,   0, 0, 0, "expr_1_out_0"),
            KerArg("expr_1_in_1",  KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_IN|O_DB,                    1, 1, 1,   0, 0, 0, "expr_1_in_1"),
            KerArg("expr_1_in_0",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1),              O_IN|O_DB,                    1, 1, 1,   0, 0, 0, "expr_1_in_0"),
            KerArg("expr_1_in_2",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,                    1, 1, 1,   0, 0, 0, "expr_1_in_2"),
            KerArg("expr_1_in_3",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,                    1, 1, 1,   0, 0, 0, "expr_1_in_3"),
            KerArg("RsqrtLUT",     KerArgSpace(1, KER_ITER_TILE0),                        O_IN|O_BUFF|O_NTILED|O_CONST, 1, 1, 384, 0, 0, 0, "RsqrtLUT")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 167050, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 67434, 0);
        AddKernelArgDimExplicit(Name, "RsqrtLUT", ARG_INT,     2, 96,         4);
        AddKernelArgDimExplicit(Name, "expr_1_in_0", ARG_INT,  4, 2, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_1_in_1", ARG_INT,  4, 2, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_1_in_2", ARG_INT,  4, 2, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_1_in_3", ARG_INT,  4, 2, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_1_out_0", ARG_INT, 4, 2, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s26_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2), (3,)) 
        // parametric_spaces: ((1, 2), (3,)) 
        // exterior_shape: (4112, 65.0) 
        KernelIterSpace(3, IterParSpace(KER_ITER_D0, 4112, 8), IterParSpace(KER_ITER_D1, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(4,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_3_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_3_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_3_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_3_out_1")
        ),
        Calls(1,
            Call("s26_kernel", LOC_D1,
                Bindings(6,
                    K_ArgPar("expr_3_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_3_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_Arg("expr_3_in_0", KER_ARG_TILE),
                    K_Arg("expr_3_in_1", KER_ARG_TILE),
                    K_Arg("expr_3_out_0", KER_ARG_TILE),
                    K_Arg("expr_3_out_1", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_3_in_0 axes: (0, 1)
        // var: expr_3_in_1 axes: (0,)
        // var: expr_3_out_0 axes: (0, 1)
        // var: expr_3_out_1 axes: (0, 1)
        KerArgs(4,
            KerArg("expr_3_in_0",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_3_in_0"),
            KerArg("expr_3_in_1",  KerArgSpace(1, KER_ITER_D0),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_3_in_1"),
            KerArg("expr_3_out_0", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_3_out_0"),
            KerArg("expr_3_out_1", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_3_out_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1069120, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 805952, 0);
        AddKernelArgDimExplicit(Name, "expr_3_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_3_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_3_out_0", ARG_INT, 4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_3_out_1", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s135_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2, 3),) 
        // parametric_spaces: ((1, 2, 3),) 
        // exterior_shape: (267280.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 267280, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(9,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_in_3"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_in_4"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_in_5"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_in_6"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_in_7"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_4_out_0")
        ),
        Calls(1,
            Call("s135_kernel", LOC_D0,
                Bindings(10,
                    K_ArgPar("expr_4_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_4_in_0", KER_ARG_TILE),
                    K_Arg("expr_4_in_1", KER_ARG_TILE),
                    K_Arg("expr_4_in_2", KER_ARG_TILE),
                    K_Arg("expr_4_in_3", KER_ARG_TILE),
                    K_Arg("expr_4_in_4", KER_ARG_TILE),
                    K_Arg("expr_4_in_5", KER_ARG_TILE),
                    K_Arg("expr_4_in_6", KER_ARG_TILE),
                    K_Arg("expr_4_in_7", KER_ARG_TILE),
                    K_Arg("expr_4_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_4_out_0 axes: (0,)
        // var: expr_4_in_0 axes: (0,)
        // var: expr_4_in_1 axes: (0,)
        // var: expr_4_in_2 axes: (0,)
        // var: expr_4_in_3 axes: (0,)
        // var: expr_4_in_4 axes: (0,)
        // var: expr_4_in_5 axes: (0,)
        // var: expr_4_in_6 axes: (0,)
        // var: expr_4_in_7 axes: (0,)
        KerArgs(9,
            KerArg("expr_4_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_4_out_0"),
            KerArg("expr_4_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_4_in_0"),
            KerArg("expr_4_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_4_in_1"),
            KerArg("expr_4_in_2",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_4_in_2"),
            KerArg("expr_4_in_3",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_4_in_3"),
            KerArg("expr_4_in_4",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_4_in_4"),
            KerArg("expr_4_in_5",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_4_in_5"),
            KerArg("expr_4_in_6",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_4_in_6"),
            KerArg("expr_4_in_7",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_4_in_7")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1870960, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 2405520, 0);
        AddKernelArgDimExplicit(Name, "expr_4_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_4_in_1", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_4_in_2", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_4_in_3", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_4_in_4", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_4_in_5", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_4_in_6", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_4_in_7", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_4_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s30_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1,), (2,), (3,)) 
        // fixed_spaces: ((1,),) parametric_spaces: ((2,), (3,)) 
        // exterior_shape: (16, 257, 65.0) 
        KernelIterSpace(4, IterFixedSpace(KER_ITER_D0, 16), IterParSpace(KER_ITER_D1, 257, 8), IterParSpace(KER_ITER_D2, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(7,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_6_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_6_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_6_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_6_in_3"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_6_in_4"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_6_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_6_out_1")
        ),
        Calls(1,
            Call("s30_kernel", LOC_D2,
                Bindings(10,
                    K_ArgPar("expr_6_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_6_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_ArgPar("expr_6_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D2),
                    K_Arg("expr_6_in_0", KER_ARG_TILE),
                    K_Arg("expr_6_in_1", KER_ARG_TILE),
                    K_Arg("expr_6_in_2", KER_ARG_TILE),
                    K_Arg("expr_6_in_3", KER_ARG_TILE),
                    K_Arg("expr_6_in_4", KER_ARG_TILE),
                    K_Arg("expr_6_out_0", KER_ARG_TILE),
                    K_Arg("expr_6_out_1", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_6_in_0 axes: (0, 1, 2)
        // var: expr_6_in_1 axes: (0, 1)
        // var: expr_6_in_2 axes: (0,)
        // var: expr_6_in_3 axes: (0,)
        // var: expr_6_out_0 axes: (0, 1, 2)
        // var: expr_6_out_1 axes: (0, 1, 2)
        // var: expr_6_in_4 axes: (0, 1, 2)
        KerArgs(7,
            KerArg("expr_6_in_0",  KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_6_in_0"),
            KerArg("expr_6_in_1",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_6_in_1"),
            KerArg("expr_6_in_2",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_6_in_2"),
            KerArg("expr_6_in_3",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_6_in_3"),
            KerArg("expr_6_out_0", KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_6_out_0"),
            KerArg("expr_6_out_1", KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_6_out_1"),
            KerArg("expr_6_in_4",  KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_6_in_4")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 2138240, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 1073264, 0);
        AddKernelArgDimExplicit(Name, "expr_6_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_6_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_6_in_2", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_6_in_3", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_6_in_4", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_6_out_0", ARG_INT, 4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_6_out_1", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s40_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2), (3,)) 
        // parametric_spaces: ((1, 2), (3,)) 
        // exterior_shape: (4112, 65.0) 
        KernelIterSpace(3, IterParSpace(KER_ITER_D0, 4112, 8), IterParSpace(KER_ITER_D1, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(4,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_7_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_7_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_7_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_7_out_1")
        ),
        Calls(1,
            Call("s40_kernel", LOC_D1,
                Bindings(6,
                    K_ArgPar("expr_7_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_7_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_Arg("expr_7_in_0", KER_ARG_TILE),
                    K_Arg("expr_7_in_1", KER_ARG_TILE),
                    K_Arg("expr_7_out_0", KER_ARG_TILE),
                    K_Arg("expr_7_out_1", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_7_in_0 axes: (0, 1)
        // var: expr_7_in_1 axes: (0,)
        // var: expr_7_out_0 axes: (0, 1)
        // var: expr_7_out_1 axes: (0, 1)
        KerArgs(4,
            KerArg("expr_7_in_0",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_7_in_0"),
            KerArg("expr_7_in_1",  KerArgSpace(1, KER_ITER_D0),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_7_in_1"),
            KerArg("expr_7_out_0", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_7_out_0"),
            KerArg("expr_7_out_1", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_7_out_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1069120, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 805952, 0);
        AddKernelArgDimExplicit(Name, "expr_7_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_7_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_7_out_0", ARG_INT, 4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_7_out_1", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s44_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1,), (2,), (3,)) 
        // fixed_spaces: ((1,),) parametric_spaces: ((2,), (3,)) 
        // exterior_shape: (16, 257, 65.0) 
        KernelIterSpace(4, IterFixedSpace(KER_ITER_D0, 16), IterParSpace(KER_ITER_D1, 257, 8), IterParSpace(KER_ITER_D2, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(5,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_8_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_8_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_8_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_8_in_3"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_8_out_0")
        ),
        Calls(1,
            Call("s44_kernel", LOC_D2,
                Bindings(8,
                    K_ArgPar("expr_8_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_8_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_ArgPar("expr_8_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D2),
                    K_Arg("expr_8_in_0", KER_ARG_TILE),
                    K_Arg("expr_8_in_1", KER_ARG_TILE),
                    K_Arg("expr_8_in_2", KER_ARG_TILE),
                    K_Arg("expr_8_in_3", KER_ARG_TILE),
                    K_Arg("expr_8_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_8_out_0 axes: (0, 1, 2)
        // var: expr_8_in_0 axes: (0, 1, 2)
        // var: expr_8_in_1 axes: (0, 1)
        // var: expr_8_in_2 axes: (0,)
        // var: expr_8_in_3 axes: (0,)
        KerArgs(5,
            KerArg("expr_8_out_0", KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_8_out_0"),
            KerArg("expr_8_in_0",  KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_8_in_0"),
            KerArg("expr_8_in_1",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_8_in_1"),
            KerArg("expr_8_in_2",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_8_in_2"),
            KerArg("expr_8_in_3",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_8_in_3")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 801840, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 538704, 0);
        AddKernelArgDimExplicit(Name, "expr_8_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_8_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_8_in_2", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_8_in_3", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_8_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s45_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2, 3),) 
        // parametric_spaces: ((1, 2, 3),) 
        // exterior_shape: (267280.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 267280, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_9_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_9_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_9_out_0")
        ),
        Calls(1,
            Call("s45_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_9_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_9_in_0", KER_ARG_TILE),
                    K_Arg("expr_9_in_1", KER_ARG_TILE),
                    K_Arg("expr_9_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_9_out_0 axes: (0,)
        // var: expr_9_in_0 axes: (0,)
        // var: expr_9_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_9_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_9_out_0"),
            KerArg("expr_9_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_9_in_0"),
            KerArg("expr_9_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_9_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 267280, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 801840, 0);
        AddKernelArgDimExplicit(Name, "expr_9_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_9_in_1", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_9_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s60_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2, 3),) 
        // parametric_spaces: ((1, 2, 3),) 
        // exterior_shape: (267280.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 267280, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_11_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_11_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_11_out_0")
        ),
        Calls(1,
            Call("s60_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_11_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_11_in_0", KER_ARG_TILE),
                    K_Arg("expr_11_in_1", KER_ARG_TILE),
                    K_Arg("expr_11_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_11_out_0 axes: (0,)
        // var: expr_11_in_0 axes: (0,)
        // var: expr_11_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_11_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_11_out_0"),
            KerArg("expr_11_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_11_in_0"),
            KerArg("expr_11_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_11_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 267280, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 801840, 0);
        AddKernelArgDimExplicit(Name, "expr_11_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_11_in_1", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_11_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s55_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2), (3,)) 
        // parametric_spaces: ((1, 2), (3,)) 
        // exterior_shape: (4112, 65.0) 
        KernelIterSpace(3, IterParSpace(KER_ITER_D0, 4112, 8), IterParSpace(KER_ITER_D1, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(4,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_12_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_12_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_12_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_12_out_1")
        ),
        Calls(1,
            Call("s55_kernel", LOC_D1,
                Bindings(6,
                    K_ArgPar("expr_12_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_12_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_Arg("expr_12_in_0", KER_ARG_TILE),
                    K_Arg("expr_12_in_1", KER_ARG_TILE),
                    K_Arg("expr_12_out_0", KER_ARG_TILE),
                    K_Arg("expr_12_out_1", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_12_in_0 axes: (0, 1)
        // var: expr_12_in_1 axes: (0,)
        // var: expr_12_out_0 axes: (0, 1)
        // var: expr_12_out_1 axes: (0, 1)
        KerArgs(4,
            KerArg("expr_12_in_0",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_12_in_0"),
            KerArg("expr_12_in_1",  KerArgSpace(1, KER_ITER_D0),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_12_in_1"),
            KerArg("expr_12_out_0", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_12_out_0"),
            KerArg("expr_12_out_1", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_12_out_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1069120, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 805952, 0);
        AddKernelArgDimExplicit(Name, "expr_12_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_12_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_12_out_0", ARG_INT, 4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_12_out_1", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s59_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1,), (2,), (3,)) 
        // fixed_spaces: ((1,),) parametric_spaces: ((2,), (3,)) 
        // exterior_shape: (16, 257, 65.0) 
        KernelIterSpace(4, IterFixedSpace(KER_ITER_D0, 16), IterParSpace(KER_ITER_D1, 257, 8), IterParSpace(KER_ITER_D2, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(5,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_13_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_13_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_13_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_13_in_3"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_13_out_0")
        ),
        Calls(1,
            Call("s59_kernel", LOC_D2,
                Bindings(8,
                    K_ArgPar("expr_13_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_13_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_ArgPar("expr_13_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D2),
                    K_Arg("expr_13_in_0", KER_ARG_TILE),
                    K_Arg("expr_13_in_1", KER_ARG_TILE),
                    K_Arg("expr_13_in_2", KER_ARG_TILE),
                    K_Arg("expr_13_in_3", KER_ARG_TILE),
                    K_Arg("expr_13_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_13_out_0 axes: (0, 1, 2)
        // var: expr_13_in_0 axes: (0, 1, 2)
        // var: expr_13_in_1 axes: (0, 1)
        // var: expr_13_in_2 axes: (0,)
        // var: expr_13_in_3 axes: (0,)
        KerArgs(5,
            KerArg("expr_13_out_0", KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_13_out_0"),
            KerArg("expr_13_in_0",  KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_13_in_0"),
            KerArg("expr_13_in_1",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_13_in_1"),
            KerArg("expr_13_in_2",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_13_in_2"),
            KerArg("expr_13_in_3",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_13_in_3")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 801840, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 538704, 0);
        AddKernelArgDimExplicit(Name, "expr_13_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_13_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_13_in_2", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_13_in_3", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_13_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s75_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2, 3),) 
        // parametric_spaces: ((1, 2, 3),) 
        // exterior_shape: (267280.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 267280, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_14_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_14_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_14_out_0")
        ),
        Calls(1,
            Call("s75_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_14_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_14_in_0", KER_ARG_TILE),
                    K_Arg("expr_14_in_1", KER_ARG_TILE),
                    K_Arg("expr_14_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_14_out_0 axes: (0,)
        // var: expr_14_in_0 axes: (0,)
        // var: expr_14_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_14_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_14_out_0"),
            KerArg("expr_14_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_14_in_0"),
            KerArg("expr_14_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_14_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 267280, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 801840, 0);
        AddKernelArgDimExplicit(Name, "expr_14_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_14_in_1", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_14_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s90_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2, 3),) 
        // parametric_spaces: ((1, 2, 3),) 
        // exterior_shape: (267280.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 267280, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_16_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_16_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_16_out_0")
        ),
        Calls(1,
            Call("s90_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_16_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_16_in_0", KER_ARG_TILE),
                    K_Arg("expr_16_in_1", KER_ARG_TILE),
                    K_Arg("expr_16_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_16_out_0 axes: (0,)
        // var: expr_16_in_0 axes: (0,)
        // var: expr_16_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_16_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_16_out_0"),
            KerArg("expr_16_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_16_in_0"),
            KerArg("expr_16_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_16_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 267280, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 801840, 0);
        AddKernelArgDimExplicit(Name, "expr_16_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_16_in_1", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_16_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s70_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2), (3,)) 
        // parametric_spaces: ((1, 2), (3,)) 
        // exterior_shape: (4112, 65.0) 
        KernelIterSpace(3, IterParSpace(KER_ITER_D0, 4112, 8), IterParSpace(KER_ITER_D1, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(4,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_17_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_17_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_17_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_17_out_1")
        ),
        Calls(1,
            Call("s70_kernel", LOC_D1,
                Bindings(6,
                    K_ArgPar("expr_17_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_17_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_Arg("expr_17_in_0", KER_ARG_TILE),
                    K_Arg("expr_17_in_1", KER_ARG_TILE),
                    K_Arg("expr_17_out_0", KER_ARG_TILE),
                    K_Arg("expr_17_out_1", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_17_in_0 axes: (0, 1)
        // var: expr_17_in_1 axes: (0,)
        // var: expr_17_out_0 axes: (0, 1)
        // var: expr_17_out_1 axes: (0, 1)
        KerArgs(4,
            KerArg("expr_17_in_0",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_17_in_0"),
            KerArg("expr_17_in_1",  KerArgSpace(1, KER_ITER_D0),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_17_in_1"),
            KerArg("expr_17_out_0", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_17_out_0"),
            KerArg("expr_17_out_1", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_17_out_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1069120, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 805952, 0);
        AddKernelArgDimExplicit(Name, "expr_17_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_17_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_17_out_0", ARG_INT, 4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_17_out_1", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s74_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1,), (2,), (3,)) 
        // fixed_spaces: ((1,),) parametric_spaces: ((2,), (3,)) 
        // exterior_shape: (16, 257, 65.0) 
        KernelIterSpace(4, IterFixedSpace(KER_ITER_D0, 16), IterParSpace(KER_ITER_D1, 257, 8), IterParSpace(KER_ITER_D2, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(5,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_18_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_18_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_18_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_18_in_3"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_18_out_0")
        ),
        Calls(1,
            Call("s74_kernel", LOC_D2,
                Bindings(8,
                    K_ArgPar("expr_18_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_18_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_ArgPar("expr_18_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D2),
                    K_Arg("expr_18_in_0", KER_ARG_TILE),
                    K_Arg("expr_18_in_1", KER_ARG_TILE),
                    K_Arg("expr_18_in_2", KER_ARG_TILE),
                    K_Arg("expr_18_in_3", KER_ARG_TILE),
                    K_Arg("expr_18_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_18_out_0 axes: (0, 1, 2)
        // var: expr_18_in_0 axes: (0, 1, 2)
        // var: expr_18_in_1 axes: (0, 1)
        // var: expr_18_in_2 axes: (0,)
        // var: expr_18_in_3 axes: (0,)
        KerArgs(5,
            KerArg("expr_18_out_0", KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_18_out_0"),
            KerArg("expr_18_in_0",  KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_18_in_0"),
            KerArg("expr_18_in_1",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_18_in_1"),
            KerArg("expr_18_in_2",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_18_in_2"),
            KerArg("expr_18_in_3",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_18_in_3")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 801840, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 538704, 0);
        AddKernelArgDimExplicit(Name, "expr_18_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_18_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_18_in_2", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_18_in_3", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_18_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s105_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2, 3),) 
        // parametric_spaces: ((1, 2, 3),) 
        // exterior_shape: (267280.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 267280, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_19_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_19_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_19_out_0")
        ),
        Calls(1,
            Call("s105_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_19_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_19_in_0", KER_ARG_TILE),
                    K_Arg("expr_19_in_1", KER_ARG_TILE),
                    K_Arg("expr_19_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_19_out_0 axes: (0,)
        // var: expr_19_in_0 axes: (0,)
        // var: expr_19_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_19_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_19_out_0"),
            KerArg("expr_19_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_19_in_0"),
            KerArg("expr_19_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_19_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 267280, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 801840, 0);
        AddKernelArgDimExplicit(Name, "expr_19_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_19_in_1", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_19_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s120_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2, 3),) 
        // parametric_spaces: ((1, 2, 3),) 
        // exterior_shape: (267280.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 267280, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(3,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_20_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_20_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_20_out_0")
        ),
        Calls(1,
            Call("s120_kernel", LOC_D0,
                Bindings(4,
                    K_ArgPar("expr_20_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_20_in_0", KER_ARG_TILE),
                    K_Arg("expr_20_in_1", KER_ARG_TILE),
                    K_Arg("expr_20_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_20_out_0 axes: (0,)
        // var: expr_20_in_0 axes: (0,)
        // var: expr_20_in_1 axes: (0,)
        KerArgs(3,
            KerArg("expr_20_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_20_out_0"),
            KerArg("expr_20_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_20_in_0"),
            KerArg("expr_20_in_1",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_20_in_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 267280, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 801840, 0);
        AddKernelArgDimExplicit(Name, "expr_20_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_20_in_1", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_20_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s85_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2), (3,)) 
        // parametric_spaces: ((1, 2), (3,)) 
        // exterior_shape: (4112, 65.0) 
        KernelIterSpace(3, IterParSpace(KER_ITER_D0, 4112, 8), IterParSpace(KER_ITER_D1, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(4,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_22_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_22_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_22_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_22_out_1")
        ),
        Calls(1,
            Call("s85_kernel", LOC_D1,
                Bindings(6,
                    K_ArgPar("expr_22_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_22_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_Arg("expr_22_in_0", KER_ARG_TILE),
                    K_Arg("expr_22_in_1", KER_ARG_TILE),
                    K_Arg("expr_22_out_0", KER_ARG_TILE),
                    K_Arg("expr_22_out_1", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_22_in_0 axes: (0, 1)
        // var: expr_22_in_1 axes: (0,)
        // var: expr_22_out_0 axes: (0, 1)
        // var: expr_22_out_1 axes: (0, 1)
        KerArgs(4,
            KerArg("expr_22_in_0",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_22_in_0"),
            KerArg("expr_22_in_1",  KerArgSpace(1, KER_ITER_D0),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_22_in_1"),
            KerArg("expr_22_out_0", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_22_out_0"),
            KerArg("expr_22_out_1", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_22_out_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1069120, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 805952, 0);
        AddKernelArgDimExplicit(Name, "expr_22_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_22_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_22_out_0", ARG_INT, 4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_22_out_1", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s89_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1,), (2,), (3,)) 
        // fixed_spaces: ((1,),) parametric_spaces: ((2,), (3,)) 
        // exterior_shape: (16, 257, 65.0) 
        KernelIterSpace(4, IterFixedSpace(KER_ITER_D0, 16), IterParSpace(KER_ITER_D1, 257, 8), IterParSpace(KER_ITER_D2, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(5,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_23_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_23_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_23_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_23_in_3"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_23_out_0")
        ),
        Calls(1,
            Call("s89_kernel", LOC_D2,
                Bindings(8,
                    K_ArgPar("expr_23_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_23_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_ArgPar("expr_23_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D2),
                    K_Arg("expr_23_in_0", KER_ARG_TILE),
                    K_Arg("expr_23_in_1", KER_ARG_TILE),
                    K_Arg("expr_23_in_2", KER_ARG_TILE),
                    K_Arg("expr_23_in_3", KER_ARG_TILE),
                    K_Arg("expr_23_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_23_out_0 axes: (0, 1, 2)
        // var: expr_23_in_0 axes: (0, 1, 2)
        // var: expr_23_in_1 axes: (0, 1)
        // var: expr_23_in_2 axes: (0,)
        // var: expr_23_in_3 axes: (0,)
        KerArgs(5,
            KerArg("expr_23_out_0", KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_23_out_0"),
            KerArg("expr_23_in_0",  KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_23_in_0"),
            KerArg("expr_23_in_1",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_23_in_1"),
            KerArg("expr_23_in_2",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_23_in_2"),
            KerArg("expr_23_in_3",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_23_in_3")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 801840, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 538704, 0);
        AddKernelArgDimExplicit(Name, "expr_23_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_23_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_23_in_2", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_23_in_3", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_23_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s100_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2), (3,)) 
        // parametric_spaces: ((1, 2), (3,)) 
        // exterior_shape: (4112, 65.0) 
        KernelIterSpace(3, IterParSpace(KER_ITER_D0, 4112, 8), IterParSpace(KER_ITER_D1, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(4,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_25_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_25_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_25_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_25_out_1")
        ),
        Calls(1,
            Call("s100_kernel", LOC_D1,
                Bindings(6,
                    K_ArgPar("expr_25_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_25_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_Arg("expr_25_in_0", KER_ARG_TILE),
                    K_Arg("expr_25_in_1", KER_ARG_TILE),
                    K_Arg("expr_25_out_0", KER_ARG_TILE),
                    K_Arg("expr_25_out_1", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_25_in_0 axes: (0, 1)
        // var: expr_25_in_1 axes: (0,)
        // var: expr_25_out_0 axes: (0, 1)
        // var: expr_25_out_1 axes: (0, 1)
        KerArgs(4,
            KerArg("expr_25_in_0",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_25_in_0"),
            KerArg("expr_25_in_1",  KerArgSpace(1, KER_ITER_D0),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_25_in_1"),
            KerArg("expr_25_out_0", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_25_out_0"),
            KerArg("expr_25_out_1", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_25_out_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1069120, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 805952, 0);
        AddKernelArgDimExplicit(Name, "expr_25_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_25_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_25_out_0", ARG_INT, 4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_25_out_1", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s104_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1,), (2,), (3,)) 
        // fixed_spaces: ((1,),) parametric_spaces: ((2,), (3,)) 
        // exterior_shape: (16, 257, 65.0) 
        KernelIterSpace(4, IterFixedSpace(KER_ITER_D0, 16), IterParSpace(KER_ITER_D1, 257, 8), IterParSpace(KER_ITER_D2, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(5,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_26_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_26_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_26_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_26_in_3"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_26_out_0")
        ),
        Calls(1,
            Call("s104_kernel", LOC_D2,
                Bindings(8,
                    K_ArgPar("expr_26_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_26_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_ArgPar("expr_26_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D2),
                    K_Arg("expr_26_in_0", KER_ARG_TILE),
                    K_Arg("expr_26_in_1", KER_ARG_TILE),
                    K_Arg("expr_26_in_2", KER_ARG_TILE),
                    K_Arg("expr_26_in_3", KER_ARG_TILE),
                    K_Arg("expr_26_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_26_out_0 axes: (0, 1, 2)
        // var: expr_26_in_0 axes: (0, 1, 2)
        // var: expr_26_in_1 axes: (0, 1)
        // var: expr_26_in_2 axes: (0,)
        // var: expr_26_in_3 axes: (0,)
        KerArgs(5,
            KerArg("expr_26_out_0", KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_26_out_0"),
            KerArg("expr_26_in_0",  KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_26_in_0"),
            KerArg("expr_26_in_1",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_26_in_1"),
            KerArg("expr_26_in_2",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_26_in_2"),
            KerArg("expr_26_in_3",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_26_in_3")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 801840, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 538704, 0);
        AddKernelArgDimExplicit(Name, "expr_26_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_26_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_26_in_2", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_26_in_3", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_26_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s115_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2), (3,)) 
        // parametric_spaces: ((1, 2), (3,)) 
        // exterior_shape: (4112, 65.0) 
        KernelIterSpace(3, IterParSpace(KER_ITER_D0, 4112, 8), IterParSpace(KER_ITER_D1, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(4,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_28_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_28_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_28_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_28_out_1")
        ),
        Calls(1,
            Call("s115_kernel", LOC_D1,
                Bindings(6,
                    K_ArgPar("expr_28_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_28_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_Arg("expr_28_in_0", KER_ARG_TILE),
                    K_Arg("expr_28_in_1", KER_ARG_TILE),
                    K_Arg("expr_28_out_0", KER_ARG_TILE),
                    K_Arg("expr_28_out_1", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_28_in_0 axes: (0, 1)
        // var: expr_28_in_1 axes: (0,)
        // var: expr_28_out_0 axes: (0, 1)
        // var: expr_28_out_1 axes: (0, 1)
        KerArgs(4,
            KerArg("expr_28_in_0",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_28_in_0"),
            KerArg("expr_28_in_1",  KerArgSpace(1, KER_ITER_D0),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_28_in_1"),
            KerArg("expr_28_out_0", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_28_out_0"),
            KerArg("expr_28_out_1", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_28_out_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1069120, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 805952, 0);
        AddKernelArgDimExplicit(Name, "expr_28_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_28_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_28_out_0", ARG_INT, 4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_28_out_1", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s119_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1,), (2,), (3,)) 
        // fixed_spaces: ((1,),) parametric_spaces: ((2,), (3,)) 
        // exterior_shape: (16, 257, 65.0) 
        KernelIterSpace(4, IterFixedSpace(KER_ITER_D0, 16), IterParSpace(KER_ITER_D1, 257, 8), IterParSpace(KER_ITER_D2, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(5,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_29_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_29_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_29_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_29_in_3"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_29_out_0")
        ),
        Calls(1,
            Call("s119_kernel", LOC_D2,
                Bindings(8,
                    K_ArgPar("expr_29_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_29_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_ArgPar("expr_29_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D2),
                    K_Arg("expr_29_in_0", KER_ARG_TILE),
                    K_Arg("expr_29_in_1", KER_ARG_TILE),
                    K_Arg("expr_29_in_2", KER_ARG_TILE),
                    K_Arg("expr_29_in_3", KER_ARG_TILE),
                    K_Arg("expr_29_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_29_out_0 axes: (0, 1, 2)
        // var: expr_29_in_0 axes: (0, 1, 2)
        // var: expr_29_in_1 axes: (0, 1)
        // var: expr_29_in_2 axes: (0,)
        // var: expr_29_in_3 axes: (0,)
        KerArgs(5,
            KerArg("expr_29_out_0", KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_29_out_0"),
            KerArg("expr_29_in_0",  KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_29_in_0"),
            KerArg("expr_29_in_1",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_29_in_1"),
            KerArg("expr_29_in_2",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_29_in_2"),
            KerArg("expr_29_in_3",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_29_in_3")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 801840, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 538704, 0);
        AddKernelArgDimExplicit(Name, "expr_29_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_29_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_29_in_2", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_29_in_3", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_29_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s130_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1, 2), (3,)) 
        // parametric_spaces: ((1, 2), (3,)) 
        // exterior_shape: (4112, 65.0) 
        KernelIterSpace(3, IterParSpace(KER_ITER_D0, 4112, 8), IterParSpace(KER_ITER_D1, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(4,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_31_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_31_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_31_out_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_31_out_1")
        ),
        Calls(1,
            Call("s130_kernel", LOC_D1,
                Bindings(6,
                    K_ArgPar("expr_31_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_31_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_Arg("expr_31_in_0", KER_ARG_TILE),
                    K_Arg("expr_31_in_1", KER_ARG_TILE),
                    K_Arg("expr_31_out_0", KER_ARG_TILE),
                    K_Arg("expr_31_out_1", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_31_in_0 axes: (0, 1)
        // var: expr_31_in_1 axes: (0,)
        // var: expr_31_out_0 axes: (0, 1)
        // var: expr_31_out_1 axes: (0, 1)
        KerArgs(4,
            KerArg("expr_31_in_0",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_31_in_0"),
            KerArg("expr_31_in_1",  KerArgSpace(1, KER_ITER_D0),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_31_in_1"),
            KerArg("expr_31_out_0", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_31_out_0"),
            KerArg("expr_31_out_1", KerArgSpace(2, KER_ITER_D0, KER_ITER_D1), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_31_out_1")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 1069120, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 805952, 0);
        AddKernelArgDimExplicit(Name, "expr_31_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_31_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_31_out_0", ARG_INT, 4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_31_out_1", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s134_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 16, 257, 65) spaces: ((1,), (2,), (3,)) 
        // fixed_spaces: ((1,),) parametric_spaces: ((2,), (3,)) 
        // exterior_shape: (16, 257, 65.0) 
        KernelIterSpace(4, IterFixedSpace(KER_ITER_D0, 16), IterParSpace(KER_ITER_D1, 257, 8), IterParSpace(KER_ITER_D2, 65, 1), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(5,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_32_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_32_in_1"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_32_in_2"),
            TCArg(CNN_ArgDataTypeExplicit(1, 1, 1, ARG_INT), "expr_32_in_3"),
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_32_out_0")
        ),
        Calls(1,
            Call("s134_kernel", LOC_D2,
                Bindings(8,
                    K_ArgPar("expr_32_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_ArgPar("expr_32_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D1),
                    K_ArgPar("expr_32_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D2),
                    K_Arg("expr_32_in_0", KER_ARG_TILE),
                    K_Arg("expr_32_in_1", KER_ARG_TILE),
                    K_Arg("expr_32_in_2", KER_ARG_TILE),
                    K_Arg("expr_32_in_3", KER_ARG_TILE),
                    K_Arg("expr_32_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_32_out_0 axes: (0, 1, 2)
        // var: expr_32_in_0 axes: (0, 1, 2)
        // var: expr_32_in_1 axes: (0, 1)
        // var: expr_32_in_2 axes: (0,)
        // var: expr_32_in_3 axes: (0,)
        KerArgs(5,
            KerArg("expr_32_out_0", KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_OUT|O_DB, 1, 1, 1, 0, 0, 0, "expr_32_out_0"),
            KerArg("expr_32_in_0",  KerArgSpace(3, KER_ITER_D0, KER_ITER_D1, KER_ITER_D2), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_32_in_0"),
            KerArg("expr_32_in_1",  KerArgSpace(2, KER_ITER_D0, KER_ITER_D1),              O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_32_in_1"),
            KerArg("expr_32_in_2",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_32_in_2"),
            KerArg("expr_32_in_3",  KerArgSpace(1, KER_ITER_D0),                           O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_32_in_3")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 801840, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 538704, 0);
        AddKernelArgDimExplicit(Name, "expr_32_in_0", ARG_INT,  4, 16, 257, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_32_in_1", ARG_INT,  4, 16, 257, 1,  1);
        AddKernelArgDimExplicit(Name, "expr_32_in_2", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_32_in_3", ARG_INT,  4, 16, 1, 1,    1);
        AddKernelArgDimExplicit(Name, "expr_32_out_0", ARG_INT, 4, 16, 257, 65, 1);
    }
    return (Kernel!=0);
}
int s142_kernel_gen(char *Name) {
    Kernel_T *Kernel = UserKernel(
        Name,
        // shape: (1, 257, 1, 1, 65) spaces: ((1, 4),) 
        // parametric_spaces: ((1, 4),) 
        // exterior_shape: (16705.0,) 
        KernelIterSpace(2, IterParSpace(KER_ITER_D0, 16705, 8), IterTiledSpace(KER_ITER_TILE0)),
        TILE_VER,
        CArgs(2,
            TCArg(CNN_ArgDataTypeExplicit(-1, 1, 1, ARG_INT), "expr_33_in_0"),
            TCArg(CNN_ArgDataTypeExplicit(4, 1, 1, ARG_FLOAT), "expr_33_out_0")
        ),
        Calls(1,
            Call("s142_kernel", LOC_D0,
                Bindings(3,
                    K_ArgPar("expr_33_out_0", KER_ARG_PARTILE_SIZE, KER_ITER_D0),
                    K_Arg("expr_33_in_0", KER_ARG_TILE),
                    K_Arg("expr_33_out_0", KER_ARG_TILE)
                )
            )
        ),
        // var: expr_33_out_0 axes: (0,)
        // var: expr_33_in_0 axes: (0,)
        KerArgs(2,
            KerArg("expr_33_out_0", KerArgSpace(1, KER_ITER_D0), O_OUT|O_DB, 1, 1, 4, 0, 0, 0, "expr_33_out_0"),
            KerArg("expr_33_in_0",  KerArgSpace(1, KER_ITER_D0), O_IN|O_DB,  1, 1, 1, 0, 0, 0, "expr_33_in_0")
        )
    );
    if (Kernel) {
        AddKernelInfos(Name, AT_KERINFO_OPER, 16705, 0);
        AddKernelInfos(Name, AT_KERINFO_BANDWIDTH, 33410, 0);
        AddKernelArgDimExplicit(Name, "expr_33_in_0", ARG_INT,    5, 257, 1, 1, 65, 1);
        AddKernelArgDimExplicit(Name, "expr_33_out_0", ARG_FLOAT, 5, 257, 1, 1, 65, 4);
    }
    return (Kernel!=0);
}

void main_1Model(unsigned int L1Memory, unsigned int L2Memory, unsigned int L3Memory, unsigned int L3Flash)
{
    KernelOper_T Cop = KOP_CONV;

    // SetKernelOpts(KER_OPT_NONE, KER_OPT_BUFFER_PROMOTE);
    SetSymbolDynamics();

    SetUsedFilesNames(0, 10, "at_api.h", "main_1.h", "CNN_BasicKernels_SQ8.h", "CNN_BasicKernels.h", "CNN_BasicKernels_fp32.h", "CNN_BasicKernels_f16.h", "CNN_BasicKernels_f16a.h", "CNN_BasicKernels_NE16.h", "CNN_BasicKernels_SQ8.h", "Expression_Kernels.h");
    SetGeneratedFilesNames("main_1Kernels.c", "main_1Kernels.h");
    AT_SetGraphCtrl(AT_GRAPH_MONITOR_CYCLES, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_MONITOR_CVAR_NAME, AT_OPT_VAL("G1_AT_GraphPerf"));
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_NODE_NAMES, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_NODE_CVAR_NAME, AT_OPT_VAL("G1_AT_GraphNodeNames"));
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_OPERINFOS, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_PRODUCE_OPERINFOS_CVAR_NAME, AT_OPT_VAL("G1_AT_GraphOperInfosNames"));
    AT_SetGraphCtrl(AT_GRAPH_TRACE_EXEC, AT_OPT_ON);
    AT_SetGraphCtrl(AT_GRAPH_CONST_EXEC_FROM_FLASH, AT_OPT_ON);

    SetMemoryDeviceInfos(4,
        AT_MEM_L1, L1Memory, "main_1_L1_Memory", 0, 0,
        AT_MEM_L2, L2Memory, "main_1_L2_Memory", 0, 1,
        AT_MEM_L3_DEFAULTRAM, L3Memory, "main_1_L3_Memory", 0, 0,
        AT_MEM_L3_DEFAULTFLASH, L3Flash, "main_1_L3_Flash", "main_1_L3_Flash_Const.dat", 0
    );

    LoadCNN_SQ8_Library();
    LoadCNNLibrary();
    LoadCNNLibrary_fp16();
    LoadCNN_NE16_SQ8_Library();
    LoadCNN_Copy_Library();
    load_expressions_kernels();

    
    // generator for input_1_qout0
    CNN_Convert("S1_input_1_qout0", 4, 1, 33410, KOP_CONVERT_FL_FP);
    
    CNN_GenControl_T gen_ctrl_S3__Transpose;
    CNN_InitGenCtrl(&gen_ctrl_S3__Transpose);
    CNN_SetGenCtrl(&gen_ctrl_S3__Transpose, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _Transpose Transpose 1x257x65x2 -> 1x2x257x65 ((1, 0))
    CNN_MatTranspose("S3__Transpose", &gen_ctrl_S3__Transpose, 1,
                      1, 2, 16705, KOP_MATTRANSP);
    
    // generator for _enc_LN_ReduceMean
    CNN_GlobalPoolAct_SQ8("S4__enc_LN_ReduceMean", 0,
                          514, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for expr_0
    s5_kernel_gen("S5_expr_0");
    
    // generator for _enc_LN_ReduceMean_1
    CNN_GlobalPoolAct_SQ8("S6__enc_LN_ReduceMean_1", 0,
                          514, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for expr_1
    s9_kernel_gen("S9_expr_1");
    
    CNN_GenControl_T gen_ctrl_S11__BN_Conv_trans_in0;
    CNN_InitGenCtrl(&gen_ctrl_S11__BN_Conv_trans_in0);
    CNN_SetGenCtrl(&gen_ctrl_S11__BN_Conv_trans_in0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _BN_Conv_trans_in0 Transpose 2x257x65 -> 257x65x2 ((1, 0))
    CNN_MatTranspose("S11__BN_Conv_trans_in0", &gen_ctrl_S11__BN_Conv_trans_in0, -1,
                      1, 16705, 2, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S14__BN_Conv;
    CNN_InitGenCtrl(&gen_ctrl_S14__BN_Conv);
    CNN_SetGenCtrl(&gen_ctrl_S14__BN_Conv, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S14__BN_Conv, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _BN_Conv
    CNN_ConvolutionNE16("S14__BN_Conv", &gen_ctrl_S14__BN_Conv,
                        -1, -1, 4, 1, 8,
                        2, 16, 65, 257,
                        KOP_CONV, 1, 1, 1, 1, 1, 1, 0, 130,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_NONE);
    
    CNN_GenControl_T gen_ctrl_S15__BN_Conv_trans_out0;
    CNN_InitGenCtrl(&gen_ctrl_S15__BN_Conv_trans_out0);
    CNN_SetGenCtrl(&gen_ctrl_S15__BN_Conv_trans_out0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _BN_Conv_trans_out0 Transpose 257x65x16 -> 16x257x65 ((1, 0))
    CNN_MatTranspose("S15__BN_Conv_trans_out0", &gen_ctrl_S15__BN_Conv_trans_out0, -1,
                      1, 16, 16705, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S18__conv_0_conv1d_Conv_fusion_trans_in0;
    CNN_InitGenCtrl(&gen_ctrl_S18__conv_0_conv1d_Conv_fusion_trans_in0);
    CNN_SetGenCtrl(&gen_ctrl_S18__conv_0_conv1d_Conv_fusion_trans_in0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_0_conv1d_Conv_fusion_trans_in0 Transpose 16x257x65 -> 257x65x16 ((1, 0))
    CNN_MatTranspose("S18__conv_0_conv1d_Conv_fusion_trans_in0", &gen_ctrl_S18__conv_0_conv1d_Conv_fusion_trans_in0, -1,
                      1, 16705, 16, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S21__conv_0_conv1d_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S21__conv_0_conv1d_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S21__conv_0_conv1d_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S21__conv_0_conv1d_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv_0_conv1d_Conv_fusion
    CNN_ConvolutionNE16("S21__conv_0_conv1d_Conv_fusion", &gen_ctrl_S21__conv_0_conv1d_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        16, 16, 65, 257,
                        KOP_CONV, 3, 3, 1, 1, 1, 1, 1, 128,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_LEAKYRELU);
    
    CNN_GenControl_T gen_ctrl_S22__conv_0_conv1d_Conv_fusion_trans_out0;
    CNN_InitGenCtrl(&gen_ctrl_S22__conv_0_conv1d_Conv_fusion_trans_out0);
    CNN_SetGenCtrl(&gen_ctrl_S22__conv_0_conv1d_Conv_fusion_trans_out0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_0_conv1d_Conv_fusion_trans_out0 Transpose 257x65x16 -> 16x257x65 ((1, 0))
    CNN_MatTranspose("S22__conv_0_conv1d_Conv_fusion_trans_out0", &gen_ctrl_S22__conv_0_conv1d_Conv_fusion_trans_out0, -1,
                      1, 16, 16705, KOP_MATTRANSP);
    
    
    // generator for _conv_0_conv1d_Conv_reshape_out_qout0
    CNN_Convert("S24__conv_0_conv1d_Conv_reshape_out_qout0", -1, 1, 267280, KOP_CONVERT_FP_FP_SCALE);
    
    // generator for _conv_0_reg1_ReduceMean
    CNN_GlobalPoolAct_SQ8("S25__conv_0_reg1_ReduceMean", 0,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for expr_3
    s26_kernel_gen("S26_expr_3");
    
    CNN_GenControl_T gen_ctrl_S27__conv_0_reg1_ReduceMean_1_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S27__conv_0_reg1_ReduceMean_1_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S27__conv_0_reg1_ReduceMean_1_fusion, "CUSTOM_ACTIVATION_NAME", "expr_2");
    CNN_ExtraActivationArgs_T gen_ctrl_S27__conv_0_reg1_ReduceMean_1_fusion_extra_activation_args = {1, {{"RsqrtLUT", 96, -4}}};
    CNN_SetGenCtrl(&gen_ctrl_S27__conv_0_reg1_ReduceMean_1_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S27__conv_0_reg1_ReduceMean_1_fusion_extra_activation_args);
    // generator for _conv_0_reg1_ReduceMean_1_fusion
    CNN_GlobalPoolAct_SQ8("S27__conv_0_reg1_ReduceMean_1_fusion", &gen_ctrl_S27__conv_0_reg1_ReduceMean_1_fusion,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_CUSTOM);
    
    
    // generator for expr_6
    s30_kernel_gen("S30_expr_6");
    
    CNN_GenControl_T gen_ctrl_S32__conv_1_conv1d_Conv_fusion_trans_in0;
    CNN_InitGenCtrl(&gen_ctrl_S32__conv_1_conv1d_Conv_fusion_trans_in0);
    CNN_SetGenCtrl(&gen_ctrl_S32__conv_1_conv1d_Conv_fusion_trans_in0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_1_conv1d_Conv_fusion_trans_in0 Transpose 16x257x65 -> 257x65x16 ((1, 0))
    CNN_MatTranspose("S32__conv_1_conv1d_Conv_fusion_trans_in0", &gen_ctrl_S32__conv_1_conv1d_Conv_fusion_trans_in0, -1,
                      1, 16705, 16, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S35__conv_1_conv1d_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S35__conv_1_conv1d_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S35__conv_1_conv1d_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S35__conv_1_conv1d_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv_1_conv1d_Conv_fusion
    CNN_ConvolutionNE16("S35__conv_1_conv1d_Conv_fusion", &gen_ctrl_S35__conv_1_conv1d_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        16, 16, 65, 257,
                        KOP_CONV, 3, 3, 2, 2, 1, 1, -262658, 122,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_LEAKYRELU);
    
    CNN_GenControl_T gen_ctrl_S36__conv_1_conv1d_Conv_fusion_trans_out0;
    CNN_InitGenCtrl(&gen_ctrl_S36__conv_1_conv1d_Conv_fusion_trans_out0);
    CNN_SetGenCtrl(&gen_ctrl_S36__conv_1_conv1d_Conv_fusion_trans_out0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_1_conv1d_Conv_fusion_trans_out0 Transpose 257x65x16 -> 16x257x65 ((1, 0))
    CNN_MatTranspose("S36__conv_1_conv1d_Conv_fusion_trans_out0", &gen_ctrl_S36__conv_1_conv1d_Conv_fusion_trans_out0, -1,
                      1, 16, 16705, KOP_MATTRANSP);
    
    
    // generator for _conv_1_conv1d_Conv_reshape_out_qout0
    CNN_Convert("S38__conv_1_conv1d_Conv_reshape_out_qout0", -1, 1, 267280, KOP_CONVERT_FP_FP_SCALE);
    
    // generator for _conv_1_reg1_ReduceMean
    CNN_GlobalPoolAct_SQ8("S39__conv_1_reg1_ReduceMean", 0,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for expr_7
    s40_kernel_gen("S40_expr_7");
    
    CNN_GenControl_T gen_ctrl_S41__conv_1_reg1_ReduceMean_1_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S41__conv_1_reg1_ReduceMean_1_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S41__conv_1_reg1_ReduceMean_1_fusion, "CUSTOM_ACTIVATION_NAME", "expr_5");
    CNN_ExtraActivationArgs_T gen_ctrl_S41__conv_1_reg1_ReduceMean_1_fusion_extra_activation_args = {1, {{"RsqrtLUT", 96, -4}}};
    CNN_SetGenCtrl(&gen_ctrl_S41__conv_1_reg1_ReduceMean_1_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S41__conv_1_reg1_ReduceMean_1_fusion_extra_activation_args);
    // generator for _conv_1_reg1_ReduceMean_1_fusion
    CNN_GlobalPoolAct_SQ8("S41__conv_1_reg1_ReduceMean_1_fusion", &gen_ctrl_S41__conv_1_reg1_ReduceMean_1_fusion,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_CUSTOM);
    
    
    // generator for expr_8
    s44_kernel_gen("S44_expr_8");
    
    
    // generator for expr_9
    s45_kernel_gen("S45_expr_9");
    
    CNN_GenControl_T gen_ctrl_S47__conv_2_conv1d_Conv_fusion_trans_in0;
    CNN_InitGenCtrl(&gen_ctrl_S47__conv_2_conv1d_Conv_fusion_trans_in0);
    CNN_SetGenCtrl(&gen_ctrl_S47__conv_2_conv1d_Conv_fusion_trans_in0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_2_conv1d_Conv_fusion_trans_in0 Transpose 16x257x65 -> 257x65x16 ((1, 0))
    CNN_MatTranspose("S47__conv_2_conv1d_Conv_fusion_trans_in0", &gen_ctrl_S47__conv_2_conv1d_Conv_fusion_trans_in0, -1,
                      1, 16705, 16, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S50__conv_2_conv1d_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S50__conv_2_conv1d_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S50__conv_2_conv1d_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S50__conv_2_conv1d_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv_2_conv1d_Conv_fusion
    CNN_ConvolutionNE16("S50__conv_2_conv1d_Conv_fusion", &gen_ctrl_S50__conv_2_conv1d_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        16, 16, 65, 257,
                        KOP_CONV, 3, 3, 4, 4, 1, 1, -525316, 111,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_LEAKYRELU);
    
    CNN_GenControl_T gen_ctrl_S51__conv_2_conv1d_Conv_fusion_trans_out0;
    CNN_InitGenCtrl(&gen_ctrl_S51__conv_2_conv1d_Conv_fusion_trans_out0);
    CNN_SetGenCtrl(&gen_ctrl_S51__conv_2_conv1d_Conv_fusion_trans_out0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_2_conv1d_Conv_fusion_trans_out0 Transpose 257x65x16 -> 16x257x65 ((1, 0))
    CNN_MatTranspose("S51__conv_2_conv1d_Conv_fusion_trans_out0", &gen_ctrl_S51__conv_2_conv1d_Conv_fusion_trans_out0, -1,
                      1, 16, 16705, KOP_MATTRANSP);
    
    
    // generator for _conv_2_conv1d_Conv_reshape_out_qout0
    CNN_Convert("S53__conv_2_conv1d_Conv_reshape_out_qout0", -1, 1, 267280, KOP_CONVERT_FP_FP_SCALE);
    
    // generator for _conv_2_reg1_ReduceMean
    CNN_GlobalPoolAct_SQ8("S54__conv_2_reg1_ReduceMean", 0,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for expr_12
    s55_kernel_gen("S55_expr_12");
    
    CNN_GenControl_T gen_ctrl_S56__conv_2_reg1_ReduceMean_1_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S56__conv_2_reg1_ReduceMean_1_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S56__conv_2_reg1_ReduceMean_1_fusion, "CUSTOM_ACTIVATION_NAME", "expr_10");
    CNN_ExtraActivationArgs_T gen_ctrl_S56__conv_2_reg1_ReduceMean_1_fusion_extra_activation_args = {1, {{"RsqrtLUT", 96, -4}}};
    CNN_SetGenCtrl(&gen_ctrl_S56__conv_2_reg1_ReduceMean_1_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S56__conv_2_reg1_ReduceMean_1_fusion_extra_activation_args);
    // generator for _conv_2_reg1_ReduceMean_1_fusion
    CNN_GlobalPoolAct_SQ8("S56__conv_2_reg1_ReduceMean_1_fusion", &gen_ctrl_S56__conv_2_reg1_ReduceMean_1_fusion,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_CUSTOM);
    
    
    // generator for expr_13
    s59_kernel_gen("S59_expr_13");
    
    
    // generator for expr_11
    s60_kernel_gen("S60_expr_11");
    
    CNN_GenControl_T gen_ctrl_S62__conv_3_conv1d_Conv_fusion_trans_in0;
    CNN_InitGenCtrl(&gen_ctrl_S62__conv_3_conv1d_Conv_fusion_trans_in0);
    CNN_SetGenCtrl(&gen_ctrl_S62__conv_3_conv1d_Conv_fusion_trans_in0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_3_conv1d_Conv_fusion_trans_in0 Transpose 16x257x65 -> 257x65x16 ((1, 0))
    CNN_MatTranspose("S62__conv_3_conv1d_Conv_fusion_trans_in0", &gen_ctrl_S62__conv_3_conv1d_Conv_fusion_trans_in0, -1,
                      1, 16705, 16, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S65__conv_3_conv1d_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S65__conv_3_conv1d_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S65__conv_3_conv1d_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S65__conv_3_conv1d_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv_3_conv1d_Conv_fusion
    CNN_ConvolutionNE16("S65__conv_3_conv1d_Conv_fusion", &gen_ctrl_S65__conv_3_conv1d_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        16, 16, 65, 257,
                        KOP_CONV, 3, 3, 8, 8, 1, 1, -1050632, 104,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_LEAKYRELU);
    
    CNN_GenControl_T gen_ctrl_S66__conv_3_conv1d_Conv_fusion_trans_out0;
    CNN_InitGenCtrl(&gen_ctrl_S66__conv_3_conv1d_Conv_fusion_trans_out0);
    CNN_SetGenCtrl(&gen_ctrl_S66__conv_3_conv1d_Conv_fusion_trans_out0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_3_conv1d_Conv_fusion_trans_out0 Transpose 257x65x16 -> 16x257x65 ((1, 0))
    CNN_MatTranspose("S66__conv_3_conv1d_Conv_fusion_trans_out0", &gen_ctrl_S66__conv_3_conv1d_Conv_fusion_trans_out0, -1,
                      1, 16, 16705, KOP_MATTRANSP);
    
    
    // generator for _conv_3_conv1d_Conv_reshape_out_qout0
    CNN_Convert("S68__conv_3_conv1d_Conv_reshape_out_qout0", -1, 1, 267280, KOP_CONVERT_FP_FP_SCALE);
    
    // generator for _conv_3_reg1_ReduceMean
    CNN_GlobalPoolAct_SQ8("S69__conv_3_reg1_ReduceMean", 0,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for expr_17
    s70_kernel_gen("S70_expr_17");
    
    CNN_GenControl_T gen_ctrl_S71__conv_3_reg1_ReduceMean_1_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S71__conv_3_reg1_ReduceMean_1_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S71__conv_3_reg1_ReduceMean_1_fusion, "CUSTOM_ACTIVATION_NAME", "expr_15");
    CNN_ExtraActivationArgs_T gen_ctrl_S71__conv_3_reg1_ReduceMean_1_fusion_extra_activation_args = {1, {{"RsqrtLUT", 96, -4}}};
    CNN_SetGenCtrl(&gen_ctrl_S71__conv_3_reg1_ReduceMean_1_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S71__conv_3_reg1_ReduceMean_1_fusion_extra_activation_args);
    // generator for _conv_3_reg1_ReduceMean_1_fusion
    CNN_GlobalPoolAct_SQ8("S71__conv_3_reg1_ReduceMean_1_fusion", &gen_ctrl_S71__conv_3_reg1_ReduceMean_1_fusion,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_CUSTOM);
    
    
    // generator for expr_18
    s74_kernel_gen("S74_expr_18");
    
    
    // generator for expr_14
    s75_kernel_gen("S75_expr_14");
    
    CNN_GenControl_T gen_ctrl_S77__conv_4_conv1d_Conv_fusion_trans_in0;
    CNN_InitGenCtrl(&gen_ctrl_S77__conv_4_conv1d_Conv_fusion_trans_in0);
    CNN_SetGenCtrl(&gen_ctrl_S77__conv_4_conv1d_Conv_fusion_trans_in0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_4_conv1d_Conv_fusion_trans_in0 Transpose 16x257x65 -> 257x65x16 ((1, 0))
    CNN_MatTranspose("S77__conv_4_conv1d_Conv_fusion_trans_in0", &gen_ctrl_S77__conv_4_conv1d_Conv_fusion_trans_in0, -1,
                      1, 16705, 16, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S80__conv_4_conv1d_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S80__conv_4_conv1d_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S80__conv_4_conv1d_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S80__conv_4_conv1d_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv_4_conv1d_Conv_fusion
    CNN_ConvolutionNE16("S80__conv_4_conv1d_Conv_fusion", &gen_ctrl_S80__conv_4_conv1d_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        16, 16, 65, 257,
                        KOP_CONV, 3, 3, 1, 1, 1, 1, 1, 99,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_LEAKYRELU);
    
    CNN_GenControl_T gen_ctrl_S81__conv_4_conv1d_Conv_fusion_trans_out0;
    CNN_InitGenCtrl(&gen_ctrl_S81__conv_4_conv1d_Conv_fusion_trans_out0);
    CNN_SetGenCtrl(&gen_ctrl_S81__conv_4_conv1d_Conv_fusion_trans_out0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_4_conv1d_Conv_fusion_trans_out0 Transpose 257x65x16 -> 16x257x65 ((1, 0))
    CNN_MatTranspose("S81__conv_4_conv1d_Conv_fusion_trans_out0", &gen_ctrl_S81__conv_4_conv1d_Conv_fusion_trans_out0, -1,
                      1, 16, 16705, KOP_MATTRANSP);
    
    
    // generator for _conv_4_conv1d_Conv_reshape_out_qout0
    CNN_Convert("S83__conv_4_conv1d_Conv_reshape_out_qout0", -1, 1, 267280, KOP_CONVERT_FP_FP_SCALE);
    
    // generator for _conv_4_reg1_ReduceMean
    CNN_GlobalPoolAct_SQ8("S84__conv_4_reg1_ReduceMean", 0,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for expr_22
    s85_kernel_gen("S85_expr_22");
    
    CNN_GenControl_T gen_ctrl_S86__conv_4_reg1_ReduceMean_1_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S86__conv_4_reg1_ReduceMean_1_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S86__conv_4_reg1_ReduceMean_1_fusion, "CUSTOM_ACTIVATION_NAME", "expr_21");
    CNN_ExtraActivationArgs_T gen_ctrl_S86__conv_4_reg1_ReduceMean_1_fusion_extra_activation_args = {1, {{"RsqrtLUT", 96, -4}}};
    CNN_SetGenCtrl(&gen_ctrl_S86__conv_4_reg1_ReduceMean_1_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S86__conv_4_reg1_ReduceMean_1_fusion_extra_activation_args);
    // generator for _conv_4_reg1_ReduceMean_1_fusion
    CNN_GlobalPoolAct_SQ8("S86__conv_4_reg1_ReduceMean_1_fusion", &gen_ctrl_S86__conv_4_reg1_ReduceMean_1_fusion,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_CUSTOM);
    
    
    // generator for expr_23
    s89_kernel_gen("S89_expr_23");
    
    
    // generator for expr_16
    s90_kernel_gen("S90_expr_16");
    
    CNN_GenControl_T gen_ctrl_S92__conv_5_conv1d_Conv_fusion_trans_in0;
    CNN_InitGenCtrl(&gen_ctrl_S92__conv_5_conv1d_Conv_fusion_trans_in0);
    CNN_SetGenCtrl(&gen_ctrl_S92__conv_5_conv1d_Conv_fusion_trans_in0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_5_conv1d_Conv_fusion_trans_in0 Transpose 16x257x65 -> 257x65x16 ((1, 0))
    CNN_MatTranspose("S92__conv_5_conv1d_Conv_fusion_trans_in0", &gen_ctrl_S92__conv_5_conv1d_Conv_fusion_trans_in0, -1,
                      1, 16705, 16, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S95__conv_5_conv1d_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S95__conv_5_conv1d_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S95__conv_5_conv1d_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S95__conv_5_conv1d_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv_5_conv1d_Conv_fusion
    CNN_ConvolutionNE16("S95__conv_5_conv1d_Conv_fusion", &gen_ctrl_S95__conv_5_conv1d_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        16, 16, 65, 257,
                        KOP_CONV, 3, 3, 2, 2, 1, 1, -262658, 101,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_LEAKYRELU);
    
    CNN_GenControl_T gen_ctrl_S96__conv_5_conv1d_Conv_fusion_trans_out0;
    CNN_InitGenCtrl(&gen_ctrl_S96__conv_5_conv1d_Conv_fusion_trans_out0);
    CNN_SetGenCtrl(&gen_ctrl_S96__conv_5_conv1d_Conv_fusion_trans_out0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_5_conv1d_Conv_fusion_trans_out0 Transpose 257x65x16 -> 16x257x65 ((1, 0))
    CNN_MatTranspose("S96__conv_5_conv1d_Conv_fusion_trans_out0", &gen_ctrl_S96__conv_5_conv1d_Conv_fusion_trans_out0, -1,
                      1, 16, 16705, KOP_MATTRANSP);
    
    
    // generator for _conv_5_conv1d_Conv_reshape_out_qout0
    CNN_Convert("S98__conv_5_conv1d_Conv_reshape_out_qout0", -1, 1, 267280, KOP_CONVERT_FP_FP_SCALE);
    
    // generator for _conv_5_reg1_ReduceMean
    CNN_GlobalPoolAct_SQ8("S99__conv_5_reg1_ReduceMean", 0,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for expr_25
    s100_kernel_gen("S100_expr_25");
    
    CNN_GenControl_T gen_ctrl_S101__conv_5_reg1_ReduceMean_1_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S101__conv_5_reg1_ReduceMean_1_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S101__conv_5_reg1_ReduceMean_1_fusion, "CUSTOM_ACTIVATION_NAME", "expr_24");
    CNN_ExtraActivationArgs_T gen_ctrl_S101__conv_5_reg1_ReduceMean_1_fusion_extra_activation_args = {1, {{"RsqrtLUT", 96, -4}}};
    CNN_SetGenCtrl(&gen_ctrl_S101__conv_5_reg1_ReduceMean_1_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S101__conv_5_reg1_ReduceMean_1_fusion_extra_activation_args);
    // generator for _conv_5_reg1_ReduceMean_1_fusion
    CNN_GlobalPoolAct_SQ8("S101__conv_5_reg1_ReduceMean_1_fusion", &gen_ctrl_S101__conv_5_reg1_ReduceMean_1_fusion,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_CUSTOM);
    
    
    // generator for expr_26
    s104_kernel_gen("S104_expr_26");
    
    
    // generator for expr_19
    s105_kernel_gen("S105_expr_19");
    
    CNN_GenControl_T gen_ctrl_S107__conv_6_conv1d_Conv_fusion_trans_in0;
    CNN_InitGenCtrl(&gen_ctrl_S107__conv_6_conv1d_Conv_fusion_trans_in0);
    CNN_SetGenCtrl(&gen_ctrl_S107__conv_6_conv1d_Conv_fusion_trans_in0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_6_conv1d_Conv_fusion_trans_in0 Transpose 16x257x65 -> 257x65x16 ((1, 0))
    CNN_MatTranspose("S107__conv_6_conv1d_Conv_fusion_trans_in0", &gen_ctrl_S107__conv_6_conv1d_Conv_fusion_trans_in0, -1,
                      1, 16705, 16, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S110__conv_6_conv1d_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S110__conv_6_conv1d_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S110__conv_6_conv1d_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S110__conv_6_conv1d_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv_6_conv1d_Conv_fusion
    CNN_ConvolutionNE16("S110__conv_6_conv1d_Conv_fusion", &gen_ctrl_S110__conv_6_conv1d_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        16, 16, 65, 257,
                        KOP_CONV, 3, 3, 4, 4, 1, 1, -525316, 102,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_LEAKYRELU);
    
    CNN_GenControl_T gen_ctrl_S111__conv_6_conv1d_Conv_fusion_trans_out0;
    CNN_InitGenCtrl(&gen_ctrl_S111__conv_6_conv1d_Conv_fusion_trans_out0);
    CNN_SetGenCtrl(&gen_ctrl_S111__conv_6_conv1d_Conv_fusion_trans_out0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_6_conv1d_Conv_fusion_trans_out0 Transpose 257x65x16 -> 16x257x65 ((1, 0))
    CNN_MatTranspose("S111__conv_6_conv1d_Conv_fusion_trans_out0", &gen_ctrl_S111__conv_6_conv1d_Conv_fusion_trans_out0, -1,
                      1, 16, 16705, KOP_MATTRANSP);
    
    
    // generator for _conv_6_conv1d_Conv_reshape_out_qout0
    CNN_Convert("S113__conv_6_conv1d_Conv_reshape_out_qout0", -1, 1, 267280, KOP_CONVERT_FP_FP_SCALE);
    
    // generator for _conv_6_reg1_ReduceMean
    CNN_GlobalPoolAct_SQ8("S114__conv_6_reg1_ReduceMean", 0,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for expr_28
    s115_kernel_gen("S115_expr_28");
    
    CNN_GenControl_T gen_ctrl_S116__conv_6_reg1_ReduceMean_1_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S116__conv_6_reg1_ReduceMean_1_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S116__conv_6_reg1_ReduceMean_1_fusion, "CUSTOM_ACTIVATION_NAME", "expr_27");
    CNN_ExtraActivationArgs_T gen_ctrl_S116__conv_6_reg1_ReduceMean_1_fusion_extra_activation_args = {1, {{"RsqrtLUT", 96, -4}}};
    CNN_SetGenCtrl(&gen_ctrl_S116__conv_6_reg1_ReduceMean_1_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S116__conv_6_reg1_ReduceMean_1_fusion_extra_activation_args);
    // generator for _conv_6_reg1_ReduceMean_1_fusion
    CNN_GlobalPoolAct_SQ8("S116__conv_6_reg1_ReduceMean_1_fusion", &gen_ctrl_S116__conv_6_reg1_ReduceMean_1_fusion,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_CUSTOM);
    
    
    // generator for expr_29
    s119_kernel_gen("S119_expr_29");
    
    
    // generator for expr_20
    s120_kernel_gen("S120_expr_20");
    
    CNN_GenControl_T gen_ctrl_S122__conv_7_conv1d_Conv_fusion_trans_in0;
    CNN_InitGenCtrl(&gen_ctrl_S122__conv_7_conv1d_Conv_fusion_trans_in0);
    CNN_SetGenCtrl(&gen_ctrl_S122__conv_7_conv1d_Conv_fusion_trans_in0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_7_conv1d_Conv_fusion_trans_in0 Transpose 16x257x65 -> 257x65x16 ((1, 0))
    CNN_MatTranspose("S122__conv_7_conv1d_Conv_fusion_trans_in0", &gen_ctrl_S122__conv_7_conv1d_Conv_fusion_trans_in0, -1,
                      1, 16705, 16, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S125__conv_7_conv1d_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S125__conv_7_conv1d_Conv_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S125__conv_7_conv1d_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S125__conv_7_conv1d_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _conv_7_conv1d_Conv_fusion
    CNN_ConvolutionNE16("S125__conv_7_conv1d_Conv_fusion", &gen_ctrl_S125__conv_7_conv1d_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        16, 16, 65, 257,
                        KOP_CONV, 3, 3, 8, 8, 1, 1, -1050632, 93,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_LEAKYRELU);
    
    CNN_GenControl_T gen_ctrl_S126__conv_7_conv1d_Conv_fusion_trans_out0;
    CNN_InitGenCtrl(&gen_ctrl_S126__conv_7_conv1d_Conv_fusion_trans_out0);
    CNN_SetGenCtrl(&gen_ctrl_S126__conv_7_conv1d_Conv_fusion_trans_out0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _conv_7_conv1d_Conv_fusion_trans_out0 Transpose 257x65x16 -> 16x257x65 ((1, 0))
    CNN_MatTranspose("S126__conv_7_conv1d_Conv_fusion_trans_out0", &gen_ctrl_S126__conv_7_conv1d_Conv_fusion_trans_out0, -1,
                      1, 16, 16705, KOP_MATTRANSP);
    
    
    // generator for _conv_7_conv1d_Conv_reshape_out_qout0
    CNN_Convert("S128__conv_7_conv1d_Conv_reshape_out_qout0", -1, 1, 267280, KOP_CONVERT_FP_FP_SCALE);
    
    // generator for _conv_7_reg1_ReduceMean
    CNN_GlobalPoolAct_SQ8("S129__conv_7_reg1_ReduceMean", 0,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_NONE);
    
    
    // generator for expr_31
    s130_kernel_gen("S130_expr_31");
    
    CNN_GenControl_T gen_ctrl_S131__conv_7_reg1_ReduceMean_1_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S131__conv_7_reg1_ReduceMean_1_fusion);
    CNN_SetGenCtrl(&gen_ctrl_S131__conv_7_reg1_ReduceMean_1_fusion, "CUSTOM_ACTIVATION_NAME", "expr_30");
    CNN_ExtraActivationArgs_T gen_ctrl_S131__conv_7_reg1_ReduceMean_1_fusion_extra_activation_args = {1, {{"RsqrtLUT", 96, -4}}};
    CNN_SetGenCtrl(&gen_ctrl_S131__conv_7_reg1_ReduceMean_1_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S131__conv_7_reg1_ReduceMean_1_fusion_extra_activation_args);
    // generator for _conv_7_reg1_ReduceMean_1_fusion
    CNN_GlobalPoolAct_SQ8("S131__conv_7_reg1_ReduceMean_1_fusion", &gen_ctrl_S131__conv_7_reg1_ReduceMean_1_fusion,
                          4112, 13, 5,
                          KOP_GLOBAL_AVGPOOL, KOP_CUSTOM);
    
    
    // generator for expr_32
    s134_kernel_gen("S134_expr_32");
    
    
    // generator for expr_4
    s135_kernel_gen("S135_expr_4");
    
    CNN_GenControl_T gen_ctrl_S137__reshape_speech_reshape_speech_0_Conv_fusion_trans_in0;
    CNN_InitGenCtrl(&gen_ctrl_S137__reshape_speech_reshape_speech_0_Conv_fusion_trans_in0);
    CNN_SetGenCtrl(&gen_ctrl_S137__reshape_speech_reshape_speech_0_Conv_fusion_trans_in0, "ARG_DTYPE", AT_OPT_VAL(ARG_INT));
    
    // generator for _reshape_speech_reshape_speech_0_Conv_fusion_trans_in0 Transpose 16x257x65 -> 257x65x16 ((1, 0))
    CNN_MatTranspose("S137__reshape_speech_reshape_speech_0_Conv_fusion_trans_in0", &gen_ctrl_S137__reshape_speech_reshape_speech_0_Conv_fusion_trans_in0, -1,
                      1, 16705, 16, KOP_MATTRANSP);
    
    CNN_GenControl_T gen_ctrl_S140__reshape_speech_reshape_speech_0_Conv_fusion;
    CNN_InitGenCtrl(&gen_ctrl_S140__reshape_speech_reshape_speech_0_Conv_fusion);
    CNN_ExtraActivationArgs_T gen_ctrl_S140__reshape_speech_reshape_speech_0_Conv_fusion_extra_activation_args = {1, {{"SigmoidLUT_u8", 128, -1}}};
    CNN_SetGenCtrl(&gen_ctrl_S140__reshape_speech_reshape_speech_0_Conv_fusion, "EXTRA_ACTIVATION_ARGS", &gen_ctrl_S140__reshape_speech_reshape_speech_0_Conv_fusion_extra_activation_args);
    CNN_SetGenCtrl(&gen_ctrl_S140__reshape_speech_reshape_speech_0_Conv_fusion, "INPUT_DATASIZE", AT_OPT_VAL(-1));
    CNN_SetGenCtrl(&gen_ctrl_S140__reshape_speech_reshape_speech_0_Conv_fusion, "OUTPUT_DATASIZE", AT_OPT_VAL(-1));
    // generator for _reshape_speech_reshape_speech_0_Conv_fusion
    CNN_ConvolutionNE16("S140__reshape_speech_reshape_speech_0_Conv_fusion", &gen_ctrl_S140__reshape_speech_reshape_speech_0_Conv_fusion,
                        -1, -1, 4, 1, 8,
                        16, 1, 65, 257,
                        KOP_CONV, 1, 1, 1, 1, 1, 1, 0, 84,
                        KOP_NONE, 0, 0, 0, 0, 0, 0, 0,
                        KOP_SIGMOID);
    
    
    // generator for expr_33
    s142_kernel_gen("S142_expr_33");
    
    
    // generator for _reshape_speech_reshape_speech_0_Conv_reshape_qout0
    CNN_Convert("S144__reshape_speech_reshape_speech_0_Conv_reshape_qout0", -1, 4, 16705, KOP_CONVERT_FP_FL);
    

#define GRAPH
#ifdef GRAPH
    CreateGraph("main_1CNN",
        /* Arguments either passed or globals */
            CArgs(101,
                TCArgInfo("float * __restrict__", "Input_1", ARG_SCOPE_ARG_ALLOC, ARG_DIR_IN, AT_MEM_L3_DEFAULTRAM, AT_MEM_L3_DEFAULTRAM, 0),
                // in q: f32 out_q: -67.09<(i8-0.00)*0.52413130<66.56
                TCArgInfo("signed char * __restrict__", "S1_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S1_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [195] GLOBAL_SUM_SCALEN: [11]
                TCArgInfo("signed char * __restrict__", "S4_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S4_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [175] GLOBAL_SUM_SCALEN: [11]
                TCArgInfo("signed char * __restrict__", "S6_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S6_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__mul_302", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__mul_302.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__add_303", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__add_303.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_bn_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_bn_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_bn_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_bn_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S14_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S14_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S14_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S14_Mul_shift.tensor", 1, 1, 8, 0)),
                // no activation BIASN: 0 PRENORM: 0 NE16_PADVAL: [130] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S14_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S14_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv_0_conv1d_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_conv_0_conv1d_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_conv_0_conv1d_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_conv_0_conv1d_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S21_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S21_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S21_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S21_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.03399 out: 0.03399  actscale: [1] actscalen: [0] a0: [[[32]]] b0: [49] c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [128] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S21_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S21_Infos.tensor", 1, 1, 8, 0)),
                // in q: -1.67<(u8-49.00)*0.03399073<7.00 out_q: -7.07<(i8-0.00)*0.05526184<7.02
                TCArgInfo("signed char * __restrict__", "S24_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S24_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [187] GLOBAL_SUM_SCALEN: [12]
                TCArgInfo("signed char * __restrict__", "S25_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S25_Infos.tensor", 1, 1, 8, 0)),
                // in: 0.00588 out: 0.36855  GLOBAL_SUM_SCALE: [251] GLOBAL_SUM_SCALEN: [9]
                TCArgInfo("signed char * __restrict__", "S27_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S27_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__mul_309", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__mul_309.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__add_310", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__add_310.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv_1_conv1d_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_conv_1_conv1d_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_conv_1_conv1d_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_conv_1_conv1d_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S35_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S35_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S35_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S35_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.07178 out: 0.07178  actscale: [1] actscalen: [0] a0: [[[33]]] b0: [54] c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [122] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S35_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S35_Infos.tensor", 1, 1, 8, 0)),
                // in q: -3.88<(u8-54.00)*0.07177539<14.43 out_q: -14.53<(i8-0.00)*0.11347695<14.41
                TCArgInfo("signed char * __restrict__", "S38_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S38_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [69] GLOBAL_SUM_SCALEN: [10]
                TCArgInfo("signed char * __restrict__", "S39_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S39_Infos.tensor", 1, 1, 8, 0)),
                // in: 0.04007 out: 0.06637  GLOBAL_SUM_SCALE: [153] GLOBAL_SUM_SCALEN: [9]
                TCArgInfo("signed char * __restrict__", "S41_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S41_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__mul_316", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__mul_316.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__add_317", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__add_317.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv_2_conv1d_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_conv_2_conv1d_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_conv_2_conv1d_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_conv_2_conv1d_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S50_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S50_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S50_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S50_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.08355 out: 0.08355  actscale: [1] actscalen: [0] a0: [[[34]]] b0: [66] c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [111] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S50_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S50_Infos.tensor", 1, 1, 8, 0)),
                // in q: -5.51<(u8-66.00)*0.08354850<15.79 out_q: -15.92<(i8-0.00)*0.12438066<15.80
                TCArgInfo("signed char * __restrict__", "S53_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S53_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [219] GLOBAL_SUM_SCALEN: [12]
                TCArgInfo("signed char * __restrict__", "S54_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S54_Infos.tensor", 1, 1, 8, 0)),
                // in: 0.06273 out: 0.02918  GLOBAL_SUM_SCALE: [107] GLOBAL_SUM_SCALEN: [9]
                TCArgInfo("signed char * __restrict__", "S56_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S56_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__mul_323", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__mul_323.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__add_324", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__add_324.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv_3_conv1d_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_conv_3_conv1d_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_conv_3_conv1d_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_conv_3_conv1d_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S65_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S65_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S65_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S65_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.09690 out: 0.09690  actscale: [1] actscalen: [0] a0: [[[37]]] b0: [46] c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [104] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S65_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S65_Infos.tensor", 1, 1, 8, 0)),
                // in q: -4.46<(u8-46.00)*0.09689682<20.25 out_q: -20.44<(i8-0.00)*0.15971206<20.28
                TCArgInfo("signed char * __restrict__", "S68_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S68_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [89] GLOBAL_SUM_SCALEN: [10]
                TCArgInfo("signed char * __restrict__", "S69_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S69_Infos.tensor", 1, 1, 8, 0)),
                // in: 0.08658 out: 0.02881  GLOBAL_SUM_SCALE: [65] GLOBAL_SUM_SCALEN: [8]
                TCArgInfo("signed char * __restrict__", "S71_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S71_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__mul_330", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__mul_330.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__add_331", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__add_331.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv_4_conv1d_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_conv_4_conv1d_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_conv_4_conv1d_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_conv_4_conv1d_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S80_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S80_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S80_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S80_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.09371 out: 0.09371  actscale: [1] actscalen: [0] a0: [[[36]]] b0: [52] c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [99] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S80_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S80_Infos.tensor", 1, 1, 8, 0)),
                // in q: -4.87<(u8-52.00)*0.09370713<19.02 out_q: -19.20<(i8-0.00)*0.14997536<19.05
                TCArgInfo("signed char * __restrict__", "S83_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S83_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [219] GLOBAL_SUM_SCALEN: [11]
                TCArgInfo("signed char * __restrict__", "S84_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S84_Infos.tensor", 1, 1, 8, 0)),
                // in: 0.07887 out: 0.01947  GLOBAL_SUM_SCALE: [129] GLOBAL_SUM_SCALEN: [9]
                TCArgInfo("signed char * __restrict__", "S86_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S86_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__mul_337", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__mul_337.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__add_338", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__add_338.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv_5_conv1d_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_conv_5_conv1d_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_conv_5_conv1d_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_conv_5_conv1d_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S95_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S95_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S95_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S95_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.18276 out: 0.18276  actscale: [1] actscalen: [0] a0: [[[34]]] b0: [27] c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [101] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S95_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S95_Infos.tensor", 1, 1, 8, 0)),
                // in q: -4.93<(u8-27.00)*0.18276313<41.67 out_q: -41.98<(i8-0.00)*0.32796827<41.65
                TCArgInfo("signed char * __restrict__", "S98_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S98_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [249] GLOBAL_SUM_SCALEN: [11]
                TCArgInfo("signed char * __restrict__", "S99_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S99_Infos.tensor", 1, 1, 8, 0)),
                // in: 0.39284 out: 0.01724  GLOBAL_SUM_SCALE: [125] GLOBAL_SUM_SCALEN: [9]
                TCArgInfo("signed char * __restrict__", "S101_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S101_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__mul_344", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__mul_344.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__add_345", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__add_345.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv_6_conv1d_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_conv_6_conv1d_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_conv_6_conv1d_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_conv_6_conv1d_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S110_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S110_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S110_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S110_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.16845 out: 0.16845  actscale: [1] actscalen: [0] a0: [[[43]]] b0: [53] c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [102] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S110_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S110_Infos.tensor", 1, 1, 8, 0)),
                // in q: -8.93<(u8-53.00)*0.16845165<34.03 out_q: -34.34<(i8-0.00)*0.26825306<34.07
                TCArgInfo("signed char * __restrict__", "S113_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S113_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [47] GLOBAL_SUM_SCALEN: [9]
                TCArgInfo("signed char * __restrict__", "S114_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S114_Infos.tensor", 1, 1, 8, 0)),
                // in: 0.43227 out: 0.01464  GLOBAL_SUM_SCALE: [149] GLOBAL_SUM_SCALEN: [10]
                TCArgInfo("signed char * __restrict__", "S116_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S116_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__mul_351", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__mul_351.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__add_352", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__add_352.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_conv_7_conv1d_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_conv_7_conv1d_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_conv_7_conv1d_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_conv_7_conv1d_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S125_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S125_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S125_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S125_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.12596 out: 0.12596  actscale: [1] actscalen: [0] a0: [[[35]]] b0: [43] c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [93] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S125_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S125_Infos.tensor", 1, 1, 8, 0)),
                // in q: -5.42<(u8-43.00)*0.12596372<26.70 out_q: -26.91<(i8-0.00)*0.21024752<26.70
                TCArgInfo("signed char * __restrict__", "S128_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S128_Infos.tensor", 1, 1, 8, 0)),
                // no activation ACTSCALE: 0 ACTSCALEN: 0 GLOBAL_SUM_SCALE: [145] GLOBAL_SUM_SCALEN: [11]
                TCArgInfo("signed char * __restrict__", "S129_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S129_Infos.tensor", 1, 1, 8, 0)),
                // in: 0.25588 out: 0.01489  GLOBAL_SUM_SCALE: [37] GLOBAL_SUM_SCALEN: [8]
                TCArgInfo("signed char * __restrict__", "S131_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S131_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__mul_358", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__mul_358.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "Constant_onnx__add_359", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_onnx__add_359.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned char * __restrict__", "_reshape_speech_reshape_speech_0_conv_weights", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("_reshape_speech_reshape_speech_0_conv_weights.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed int * __restrict__", "Constant_reshape_speech_0_bias", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("Constant_reshape_speech_0_bias.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "S140_Mul_scale", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S140_Mul_scale.tensor", 1, 1, 8, 0)),
                TCArgInfo("signed char * __restrict__", "S140_Mul_shift", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S140_Mul_shift.tensor", 1, 1, 8, 0)),
                // in: 0.04875 out: 0.00392  actscale: [129] actscalen: [6] a0: [0] b0: 0 c0: 0 BIASN: 0 PRENORM: 0 NE16_PADVAL: [84] NE16_WOFFSET: [-128]
                TCArgInfo("signed char * __restrict__", "S140_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S140_Infos.tensor", 1, 1, 8, 0)),
                // in q: 0.00<(u8-0.00)*0.00392157<1.00 out_q: f32
                TCArgInfo("signed char * __restrict__", "S144_Infos", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("S144_Infos.tensor", 1, 1, 8, 0)),
                TCArgInfo("unsigned int * __restrict__", "RsqrtLUT", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("RsqrtLUT.tensor", 1, 1, 32, 0)),
                TCArgInfo("unsigned char * __restrict__", "SigmoidLUT_u8", ARG_SCOPE_GLOBAL, ARG_DIR_CONSTIN, AT_MEM_L3_DEFAULTFLASH, AT_MEM_UNDEF, ConstInfo("SigmoidLUT_u8.tensor", 1, 1, 8, 0)),
                TCArgInfo("float * __restrict__", "Output_1", ARG_SCOPE_ARG_ALLOC, ARG_DIR_OUT, AT_MEM_L2, AT_MEM_L2, 0),
                TCArgInfo("float * __restrict__", "Output_2", ARG_SCOPE_ARG_ALLOC, ARG_DIR_OUT, AT_MEM_L2, AT_MEM_L2, 0)
            ),
        /* Locals, allocated dynamically */
        CArgs(92,
            TCArgInfo("signed char * __restrict__", "S1_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S3_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S4_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S5_Output_0", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S5_Output_1", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S6_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S9_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S11_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S14_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S15_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S18_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S21_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S22_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S24_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S25_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S26_Output_0", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S26_Output_1", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S27_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S30_Output_1", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S30_Output_0", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S32_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S35_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S36_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S38_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S39_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S40_Output_1", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S40_Output_0", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S41_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S44_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S45_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S47_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S50_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S51_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S53_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S54_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S55_Output_0", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S55_Output_1", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S56_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S59_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S60_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S62_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S65_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S66_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S68_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S69_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S70_Output_0", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S70_Output_1", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S71_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S74_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S75_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S77_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S80_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S81_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S83_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S84_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S85_Output_0", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S85_Output_1", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S86_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S89_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S90_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S92_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S95_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S96_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S98_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S99_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S100_Output_0", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S100_Output_1", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S101_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S104_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S105_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S107_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S110_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S111_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S113_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S114_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S115_Output_1", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S115_Output_0", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S116_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S119_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S120_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S122_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S125_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S126_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S128_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S129_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S130_Output_0", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S130_Output_1", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("signed char * __restrict__", "S131_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S134_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S135_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S137_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0),
            TCArgInfo("unsigned char * __restrict__", "S140_Output", ARG_SCOPE_LOCAL, ARG_DIR_INOUT, AT_MEM_UNDEF, AT_MEM_UNDEF, 0)
        )
    );



    // Node input_1_qout0 inq f32 outq -67.09<(i8-0.00)*0.52413130<66.56
    AddNode("S1_input_1_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "Input_1", 0),
            GNodeArg(GNA_OUT, "S1_Output", 0),
            GNodeArg(GNA_IN, "S1_Infos", 0)
        )
    );
    // Node _Transpose inq -67.09<(i8-0.00)*0.52413130<66.56 outq -67.09<(i8-0.00)*0.52413130<66.56
    AddNode("S3__Transpose",
        Bindings(2,
            GNodeArg(GNA_IN, "S1_Output", 0),
            GNodeArg(GNA_OUT, "S3_Output", 0)
        )
    );
    // Node _enc_LN_ReduceMean inq -67.09<(i8-0.00)*0.52413130<66.56 outq -5.51<(i8-0.00)*0.04306682<5.47
    AddNode("S4__enc_LN_ReduceMean",
        Bindings(3,
            GNodeArg(GNA_IN, "S3_Output", 0),
            GNodeArg(GNA_OUT, "S4_Output", 0),
            GNodeArg(GNA_IN, "S4_Infos", 0)
        )
    );
    // Node expr_0 in_qs [-67.09<(i8-0.00)*0.52413130<66.56,-5.51<(i8-0.00)*0.04306682<5.47] out_qs [-61.84<(i8--5.00)*0.50274202<66.36,-4467.19<(i8-0.00)*34.89991388<4432.29 forced]
    AddNode("S5_expr_0",
        Bindings(4,
            GNodeArg(GNA_IN, "S3_Output", 0),
            GNodeArg(GNA_IN, "S4_Output", 0),
            GNodeArg(GNA_OUT, "S5_Output_0", 0),
            GNodeArg(GNA_OUT, "S5_Output_1", 0)
        )
    );
    // Node _enc_LN_ReduceMean_1 inq -4467.19<(i8-0.00)*34.89991388<4432.29 forced outq -409.09<(i8-0.00)*3.19600892<405.89
    AddNode("S6__enc_LN_ReduceMean_1",
        Bindings(3,
            GNodeArg(GNA_IN, "S5_Output_1", 0),
            GNodeArg(GNA_OUT, "S6_Output", 0),
            GNodeArg(GNA_IN, "S6_Infos", 0)
        )
    );
    // Node expr_1 in_qs [-409.09<(i8-0.00)*3.19600892<405.89,-61.84<(i8--5.00)*0.50274202<66.36,-0.99<(i8-0.00)*0.00774555<0.98,-1169400.07<(i8-0.00)*9135.93801452<1160264.13] out_qs [-7.66<(u8-130.00)*0.05889541<7.36]
    AddNode("S9_expr_1",
        Bindings(6,
            GNodeArg(GNA_IN, "S6_Output", 0),
            GNodeArg(GNA_IN, "S5_Output_0", 0),
            GNodeArg(GNA_IN, "Constant_onnx__mul_302", 0),
            GNodeArg(GNA_IN, "Constant_onnx__add_303", 0),
            GNodeArg(GNA_OUT, "S9_Output", 0),
            GNodeArg(GNA_IN, "RsqrtLUT", 0)
        )
    );
    // Node _BN_Conv_trans_in0 inq -7.66<(u8-130.00)*0.05889541<7.36 outq -7.66<(u8-130.00)*0.05889541<7.36
    AddNode("S11__BN_Conv_trans_in0",
        Bindings(2,
            GNodeArg(GNA_IN, "S9_Output", 0),
            GNodeArg(GNA_OUT, "S11_Output", 0)
        )
    );
    // Node S14__BN_Conv inq -7.66<(u8-130.00)*0.05889541<7.36 weightsq chan<(u8-128.00)*chan<chan outq -7.46<(u8-128.00)*0.05831658<7.41 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S14__BN_Conv",
        Bindings(7,
            GNodeArg(GNA_IN, "S11_Output", 0),
            GNodeArg(GNA_IN, "_bn_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_bn_bias", 0),
            GNodeArg(GNA_OUT, "S14_Output", 0),
            GNodeArg(GNA_IN, "S14_Mul_scale", 0),
            GNodeArg(GNA_IN, "S14_Mul_shift", 0),
            GNodeArg(GNA_IN, "S14_Infos", 0)
        )
    );
    // Node _BN_Conv_trans_out0 inq -7.46<(u8-128.00)*0.05831658<7.41 outq -7.46<(u8-128.00)*0.05831658<7.41
    AddNode("S15__BN_Conv_trans_out0",
        Bindings(2,
            GNodeArg(GNA_IN, "S14_Output", 0),
            GNodeArg(GNA_OUT, "S15_Output", 0)
        )
    );
    // Node _conv_0_conv1d_Conv_fusion_trans_in0 inq -7.46<(u8-128.00)*0.05831658<7.41 outq -7.46<(u8-128.00)*0.05831658<7.41
    AddNode("S18__conv_0_conv1d_Conv_fusion_trans_in0",
        Bindings(2,
            GNodeArg(GNA_IN, "S15_Output", 0),
            GNodeArg(GNA_OUT, "S18_Output", 0)
        )
    );
    // Node S21__conv_0_conv1d_Conv_fusion inq -7.46<(u8-128.00)*0.05831658<7.41 weightsq chan<(u8-128.00)*chan<chan outq -1.67<(u8-49.00)*0.03399073<7.00 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S21__conv_0_conv1d_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S18_Output", 0),
            GNodeArg(GNA_IN, "_conv_0_conv1d_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_conv_0_conv1d_bias", 0),
            GNodeArg(GNA_OUT, "S21_Output", 0),
            GNodeArg(GNA_IN, "S21_Mul_scale", 0),
            GNodeArg(GNA_IN, "S21_Mul_shift", 0),
            GNodeArg(GNA_IN, "S21_Infos", 0)
        )
    );
    // Node _conv_0_conv1d_Conv_fusion_trans_out0 inq -1.67<(u8-49.00)*0.03399073<7.00 outq -1.67<(u8-49.00)*0.03399073<7.00
    AddNode("S22__conv_0_conv1d_Conv_fusion_trans_out0",
        Bindings(2,
            GNodeArg(GNA_IN, "S21_Output", 0),
            GNodeArg(GNA_OUT, "S22_Output", 0)
        )
    );
    // Node _conv_0_conv1d_Conv_reshape_out_qout0 inq -1.67<(u8-49.00)*0.03399073<7.00 outq -7.07<(i8-0.00)*0.05526184<7.02
    AddNode("S24__conv_0_conv1d_Conv_reshape_out_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S22_Output", 0),
            GNodeArg(GNA_OUT, "S24_Output", 0),
            GNodeArg(GNA_IN, "S24_Infos", 0)
        )
    );
    // Node _conv_0_reg1_ReduceMean inq -7.07<(i8-0.00)*0.05526184<7.02 outq -1.21<(i8-0.00)*0.00946321<1.20
    AddNode("S25__conv_0_reg1_ReduceMean",
        Bindings(3,
            GNodeArg(GNA_IN, "S24_Output", 0),
            GNodeArg(GNA_OUT, "S25_Output", 0),
            GNodeArg(GNA_IN, "S25_Infos", 0)
        )
    );
    // Node expr_3 in_qs [-1.67<(u8-49.00)*0.03399073<7.00,-1.21<(i8-0.00)*0.00946321<1.20] out_qs [-2.20<(u8-62.00)*0.03549513<6.85,-47.30<(i8-0.00)*0.36956108<46.93]
    AddNode("S26_expr_3",
        Bindings(4,
            GNodeArg(GNA_IN, "S22_Output", 0),
            GNodeArg(GNA_IN, "S25_Output", 0),
            GNodeArg(GNA_OUT, "S26_Output_0", 0),
            GNodeArg(GNA_OUT, "S26_Output_1", 0)
        )
    );
    // Node _conv_0_reg1_ReduceMean_1_fusion inq -47.30<(i8-0.00)*0.36956108<46.93 outq 0.00<(i8--128.00)*0.36854544<93.98
    AddNode("S27__conv_0_reg1_ReduceMean_1_fusion",
        Bindings(4,
            GNodeArg(GNA_IN, "S26_Output_1", 0),
            GNodeArg(GNA_OUT, "S27_Output", 0),
            GNodeArg(GNA_IN, "S27_Infos", 0),
            GNodeArg(GNA_IN, "RsqrtLUT", 0)
        )
    );
    // Node expr_6 in_qs [-2.20<(u8-62.00)*0.03549513<6.85,0.00<(i8--128.00)*0.36854544<93.98,-1.01<(i8-0.00)*0.00791865<1.01,-434.48<(i8-0.00)*3.39438268<431.09,-7.46<(u8-128.00)*0.05831658<7.41] out_qs [-7.18<(u8-121.00)*0.05931951<7.95,-11.88<(u8-122.00)*0.09740259<12.95]
    AddNode("S30_expr_6",
        Bindings(7,
            GNodeArg(GNA_IN, "S26_Output_0", 0),
            GNodeArg(GNA_IN, "S27_Output", 0),
            GNodeArg(GNA_IN, "Constant_onnx__mul_309", 0),
            GNodeArg(GNA_IN, "Constant_onnx__add_310", 0),
            GNodeArg(GNA_IN, "S15_Output", 0),
            GNodeArg(GNA_OUT, "S30_Output_0", 0),
            GNodeArg(GNA_OUT, "S30_Output_1", 0)
        )
    );
    // Node _conv_1_conv1d_Conv_fusion_trans_in0 inq -11.88<(u8-122.00)*0.09740259<12.95 outq -11.88<(u8-122.00)*0.09740259<12.95
    AddNode("S32__conv_1_conv1d_Conv_fusion_trans_in0",
        Bindings(2,
            GNodeArg(GNA_IN, "S30_Output_1", 0),
            GNodeArg(GNA_OUT, "S32_Output", 0)
        )
    );
    // Node S35__conv_1_conv1d_Conv_fusion inq -11.88<(u8-122.00)*0.09740259<12.95 weightsq chan<(u8-128.00)*chan<chan outq -3.88<(u8-54.00)*0.07177539<14.43 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S35__conv_1_conv1d_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S32_Output", 0),
            GNodeArg(GNA_IN, "_conv_1_conv1d_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_conv_1_conv1d_bias", 0),
            GNodeArg(GNA_OUT, "S35_Output", 0),
            GNodeArg(GNA_IN, "S35_Mul_scale", 0),
            GNodeArg(GNA_IN, "S35_Mul_shift", 0),
            GNodeArg(GNA_IN, "S35_Infos", 0)
        )
    );
    // Node _conv_1_conv1d_Conv_fusion_trans_out0 inq -3.88<(u8-54.00)*0.07177539<14.43 outq -3.88<(u8-54.00)*0.07177539<14.43
    AddNode("S36__conv_1_conv1d_Conv_fusion_trans_out0",
        Bindings(2,
            GNodeArg(GNA_IN, "S35_Output", 0),
            GNodeArg(GNA_OUT, "S36_Output", 0)
        )
    );
    // Node _conv_1_conv1d_Conv_reshape_out_qout0 inq -3.88<(u8-54.00)*0.07177539<14.43 outq -14.53<(i8-0.00)*0.11347695<14.41
    AddNode("S38__conv_1_conv1d_Conv_reshape_out_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S36_Output", 0),
            GNodeArg(GNA_OUT, "S38_Output", 0),
            GNodeArg(GNA_IN, "S38_Infos", 0)
        )
    );
    // Node _conv_1_reg1_ReduceMean inq -14.53<(i8-0.00)*0.11347695<14.41 outq -1.69<(i8-0.00)*0.01318208<1.67
    AddNode("S39__conv_1_reg1_ReduceMean",
        Bindings(3,
            GNodeArg(GNA_IN, "S38_Output", 0),
            GNodeArg(GNA_OUT, "S39_Output", 0),
            GNodeArg(GNA_IN, "S39_Infos", 0)
        )
    );
    // Node expr_7 in_qs [-3.88<(u8-54.00)*0.07177539<14.43,-1.69<(i8-0.00)*0.01318208<1.67] out_qs [-5.19<(u8-69.00)*0.07519315<13.99,-196.52<(i8-0.00)*1.53534663<194.99]
    AddNode("S40_expr_7",
        Bindings(4,
            GNodeArg(GNA_IN, "S36_Output", 0),
            GNodeArg(GNA_IN, "S39_Output", 0),
            GNodeArg(GNA_OUT, "S40_Output_0", 0),
            GNodeArg(GNA_OUT, "S40_Output_1", 0)
        )
    );
    // Node _conv_1_reg1_ReduceMean_1_fusion inq -196.52<(i8-0.00)*1.53534663<194.99 outq 0.00<(i8--128.00)*0.06636859<16.92
    AddNode("S41__conv_1_reg1_ReduceMean_1_fusion",
        Bindings(4,
            GNodeArg(GNA_IN, "S40_Output_1", 0),
            GNodeArg(GNA_OUT, "S41_Output", 0),
            GNodeArg(GNA_IN, "S41_Infos", 0),
            GNodeArg(GNA_IN, "RsqrtLUT", 0)
        )
    );
    // Node expr_8 in_qs [-5.19<(u8-69.00)*0.07519315<13.99,0.00<(i8--128.00)*0.06636859<16.92,-1.02<(i8-0.00)*0.00796439<1.01,-166.71<(i8-0.00)*1.30239719<165.40] out_qs [-5.07<(u8-101.00)*0.05015203<7.72]
    AddNode("S44_expr_8",
        Bindings(5,
            GNodeArg(GNA_IN, "S40_Output_0", 0),
            GNodeArg(GNA_IN, "S41_Output", 0),
            GNodeArg(GNA_IN, "Constant_onnx__mul_316", 0),
            GNodeArg(GNA_IN, "Constant_onnx__add_317", 0),
            GNodeArg(GNA_OUT, "S44_Output", 0)
        )
    );
    // Node expr_9 in_qs [-11.88<(u8-122.00)*0.09740259<12.95,-5.07<(u8-101.00)*0.05015203<7.72] out_qs [-13.64<(u8-111.00)*0.12286843<17.69]
    AddNode("S45_expr_9",
        Bindings(3,
            GNodeArg(GNA_IN, "S30_Output_1", 0),
            GNodeArg(GNA_IN, "S44_Output", 0),
            GNodeArg(GNA_OUT, "S45_Output", 0)
        )
    );
    // Node _conv_2_conv1d_Conv_fusion_trans_in0 inq -13.64<(u8-111.00)*0.12286843<17.69 outq -13.64<(u8-111.00)*0.12286843<17.69
    AddNode("S47__conv_2_conv1d_Conv_fusion_trans_in0",
        Bindings(2,
            GNodeArg(GNA_IN, "S45_Output", 0),
            GNodeArg(GNA_OUT, "S47_Output", 0)
        )
    );
    // Node S50__conv_2_conv1d_Conv_fusion inq -13.64<(u8-111.00)*0.12286843<17.69 weightsq chan<(u8-128.00)*chan<chan outq -5.51<(u8-66.00)*0.08354850<15.79 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S50__conv_2_conv1d_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S47_Output", 0),
            GNodeArg(GNA_IN, "_conv_2_conv1d_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_conv_2_conv1d_bias", 0),
            GNodeArg(GNA_OUT, "S50_Output", 0),
            GNodeArg(GNA_IN, "S50_Mul_scale", 0),
            GNodeArg(GNA_IN, "S50_Mul_shift", 0),
            GNodeArg(GNA_IN, "S50_Infos", 0)
        )
    );
    // Node _conv_2_conv1d_Conv_fusion_trans_out0 inq -5.51<(u8-66.00)*0.08354850<15.79 outq -5.51<(u8-66.00)*0.08354850<15.79
    AddNode("S51__conv_2_conv1d_Conv_fusion_trans_out0",
        Bindings(2,
            GNodeArg(GNA_IN, "S50_Output", 0),
            GNodeArg(GNA_OUT, "S51_Output", 0)
        )
    );
    // Node _conv_2_conv1d_Conv_reshape_out_qout0 inq -5.51<(u8-66.00)*0.08354850<15.79 outq -15.92<(i8-0.00)*0.12438066<15.80
    AddNode("S53__conv_2_conv1d_Conv_reshape_out_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S51_Output", 0),
            GNodeArg(GNA_OUT, "S53_Output", 0),
            GNodeArg(GNA_IN, "S53_Infos", 0)
        )
    );
    // Node _conv_2_reg1_ReduceMean inq -15.92<(i8-0.00)*0.12438066<15.80 outq -2.33<(i8-0.00)*0.01817827<2.31
    AddNode("S54__conv_2_reg1_ReduceMean",
        Bindings(3,
            GNodeArg(GNA_IN, "S53_Output", 0),
            GNodeArg(GNA_OUT, "S54_Output", 0),
            GNodeArg(GNA_IN, "S54_Infos", 0)
        )
    );
    // Node expr_12 in_qs [-5.51<(u8-66.00)*0.08354850<15.79,-2.33<(i8-0.00)*0.01817827<2.31] out_qs [-6.93<(u8-82.00)*0.08456486<14.63,-214.71<(i8-0.00)*1.67739952<213.03]
    AddNode("S55_expr_12",
        Bindings(4,
            GNodeArg(GNA_IN, "S51_Output", 0),
            GNodeArg(GNA_IN, "S54_Output", 0),
            GNodeArg(GNA_OUT, "S55_Output_0", 0),
            GNodeArg(GNA_OUT, "S55_Output_1", 0)
        )
    );
    // Node _conv_2_reg1_ReduceMean_1_fusion inq -214.71<(i8-0.00)*1.67739952<213.03 outq 0.00<(i8--128.00)*0.02917837<7.44
    AddNode("S56__conv_2_reg1_ReduceMean_1_fusion",
        Bindings(4,
            GNodeArg(GNA_IN, "S55_Output_1", 0),
            GNodeArg(GNA_OUT, "S56_Output", 0),
            GNodeArg(GNA_IN, "S56_Infos", 0),
            GNodeArg(GNA_IN, "RsqrtLUT", 0)
        )
    );
    // Node expr_13 in_qs [-6.93<(u8-82.00)*0.08456486<14.63,0.00<(i8--128.00)*0.02917837<7.44,-1.02<(i8-0.00)*0.00798648<1.01,-82.65<(i8-0.00)*0.64573790<82.01] out_qs [-4.57<(u8-99.00)*0.04614057<7.20]
    AddNode("S59_expr_13",
        Bindings(5,
            GNodeArg(GNA_IN, "S55_Output_0", 0),
            GNodeArg(GNA_IN, "S56_Output", 0),
            GNodeArg(GNA_IN, "Constant_onnx__mul_323", 0),
            GNodeArg(GNA_IN, "Constant_onnx__add_324", 0),
            GNodeArg(GNA_OUT, "S59_Output", 0)
        )
    );
    // Node expr_11 in_qs [-13.64<(u8-111.00)*0.12286843<17.69,-4.57<(u8-99.00)*0.04614057<7.20] out_qs [-13.49<(u8-104.00)*0.12972728<19.59]
    AddNode("S60_expr_11",
        Bindings(3,
            GNodeArg(GNA_IN, "S45_Output", 0),
            GNodeArg(GNA_IN, "S59_Output", 0),
            GNodeArg(GNA_OUT, "S60_Output", 0)
        )
    );
    // Node _conv_3_conv1d_Conv_fusion_trans_in0 inq -13.49<(u8-104.00)*0.12972728<19.59 outq -13.49<(u8-104.00)*0.12972728<19.59
    AddNode("S62__conv_3_conv1d_Conv_fusion_trans_in0",
        Bindings(2,
            GNodeArg(GNA_IN, "S60_Output", 0),
            GNodeArg(GNA_OUT, "S62_Output", 0)
        )
    );
    // Node S65__conv_3_conv1d_Conv_fusion inq -13.49<(u8-104.00)*0.12972728<19.59 weightsq chan<(u8-128.00)*chan<chan outq -4.46<(u8-46.00)*0.09689682<20.25 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S65__conv_3_conv1d_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S62_Output", 0),
            GNodeArg(GNA_IN, "_conv_3_conv1d_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_conv_3_conv1d_bias", 0),
            GNodeArg(GNA_OUT, "S65_Output", 0),
            GNodeArg(GNA_IN, "S65_Mul_scale", 0),
            GNodeArg(GNA_IN, "S65_Mul_shift", 0),
            GNodeArg(GNA_IN, "S65_Infos", 0)
        )
    );
    // Node _conv_3_conv1d_Conv_fusion_trans_out0 inq -4.46<(u8-46.00)*0.09689682<20.25 outq -4.46<(u8-46.00)*0.09689682<20.25
    AddNode("S66__conv_3_conv1d_Conv_fusion_trans_out0",
        Bindings(2,
            GNodeArg(GNA_IN, "S65_Output", 0),
            GNodeArg(GNA_OUT, "S66_Output", 0)
        )
    );
    // Node _conv_3_conv1d_Conv_reshape_out_qout0 inq -4.46<(u8-46.00)*0.09689682<20.25 outq -20.44<(i8-0.00)*0.15971206<20.28
    AddNode("S68__conv_3_conv1d_Conv_reshape_out_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S66_Output", 0),
            GNodeArg(GNA_OUT, "S68_Output", 0),
            GNodeArg(GNA_IN, "S68_Infos", 0)
        )
    );
    // Node _conv_3_reg1_ReduceMean inq -20.44<(i8-0.00)*0.15971206<20.28 outq -1.84<(i8-0.00)*0.01437047<1.83
    AddNode("S69__conv_3_reg1_ReduceMean",
        Bindings(3,
            GNodeArg(GNA_IN, "S68_Output", 0),
            GNodeArg(GNA_OUT, "S69_Output", 0),
            GNodeArg(GNA_IN, "S69_Infos", 0)
        )
    );
    // Node expr_17 in_qs [-4.46<(u8-46.00)*0.09689682<20.25,-1.84<(i8-0.00)*0.01437047<1.83] out_qs [-5.09<(u8-54.00)*0.09421269<18.94,-361.13<(i8-0.00)*2.82132578<358.31]
    AddNode("S70_expr_17",
        Bindings(4,
            GNodeArg(GNA_IN, "S66_Output", 0),
            GNodeArg(GNA_IN, "S69_Output", 0),
            GNodeArg(GNA_OUT, "S70_Output_0", 0),
            GNodeArg(GNA_OUT, "S70_Output_1", 0)
        )
    );
    // Node _conv_3_reg1_ReduceMean_1_fusion inq -361.13<(i8-0.00)*2.82132578<358.31 outq 0.00<(i8--128.00)*0.02880841<7.35
    AddNode("S71__conv_3_reg1_ReduceMean_1_fusion",
        Bindings(4,
            GNodeArg(GNA_IN, "S70_Output_1", 0),
            GNodeArg(GNA_OUT, "S71_Output", 0),
            GNodeArg(GNA_IN, "S71_Infos", 0),
            GNodeArg(GNA_IN, "RsqrtLUT", 0)
        )
    );
    // Node expr_18 in_qs [-5.09<(u8-54.00)*0.09421269<18.94,0.00<(i8--128.00)*0.02880841<7.35,-1.02<(i8-0.00)*0.00794139<1.01,-90.40<(i8-0.00)*0.70627685<89.70] out_qs [-3.87<(u8-93.00)*0.04164210<6.75]
    AddNode("S74_expr_18",
        Bindings(5,
            GNodeArg(GNA_IN, "S70_Output_0", 0),
            GNodeArg(GNA_IN, "S71_Output", 0),
            GNodeArg(GNA_IN, "Constant_onnx__mul_330", 0),
            GNodeArg(GNA_IN, "Constant_onnx__add_331", 0),
            GNodeArg(GNA_OUT, "S74_Output", 0)
        )
    );
    // Node expr_14 in_qs [-13.49<(u8-104.00)*0.12972728<19.59,-3.87<(u8-93.00)*0.04164210<6.75] out_qs [-14.61<(u8-99.00)*0.14762190<23.03]
    AddNode("S75_expr_14",
        Bindings(3,
            GNodeArg(GNA_IN, "S60_Output", 0),
            GNodeArg(GNA_IN, "S74_Output", 0),
            GNodeArg(GNA_OUT, "S75_Output", 0)
        )
    );
    // Node _conv_4_conv1d_Conv_fusion_trans_in0 inq -14.61<(u8-99.00)*0.14762190<23.03 outq -14.61<(u8-99.00)*0.14762190<23.03
    AddNode("S77__conv_4_conv1d_Conv_fusion_trans_in0",
        Bindings(2,
            GNodeArg(GNA_IN, "S75_Output", 0),
            GNodeArg(GNA_OUT, "S77_Output", 0)
        )
    );
    // Node S80__conv_4_conv1d_Conv_fusion inq -14.61<(u8-99.00)*0.14762190<23.03 weightsq chan<(u8-128.00)*chan<chan outq -4.87<(u8-52.00)*0.09370713<19.02 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S80__conv_4_conv1d_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S77_Output", 0),
            GNodeArg(GNA_IN, "_conv_4_conv1d_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_conv_4_conv1d_bias", 0),
            GNodeArg(GNA_OUT, "S80_Output", 0),
            GNodeArg(GNA_IN, "S80_Mul_scale", 0),
            GNodeArg(GNA_IN, "S80_Mul_shift", 0),
            GNodeArg(GNA_IN, "S80_Infos", 0)
        )
    );
    // Node _conv_4_conv1d_Conv_fusion_trans_out0 inq -4.87<(u8-52.00)*0.09370713<19.02 outq -4.87<(u8-52.00)*0.09370713<19.02
    AddNode("S81__conv_4_conv1d_Conv_fusion_trans_out0",
        Bindings(2,
            GNodeArg(GNA_IN, "S80_Output", 0),
            GNodeArg(GNA_OUT, "S81_Output", 0)
        )
    );
    // Node _conv_4_conv1d_Conv_reshape_out_qout0 inq -4.87<(u8-52.00)*0.09370713<19.02 outq -19.20<(i8-0.00)*0.14997536<19.05
    AddNode("S83__conv_4_conv1d_Conv_reshape_out_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S81_Output", 0),
            GNodeArg(GNA_OUT, "S83_Output", 0),
            GNodeArg(GNA_IN, "S83_Infos", 0)
        )
    );
    // Node _conv_4_reg1_ReduceMean inq -19.20<(i8-0.00)*0.14997536<19.05 outq -1.40<(i8-0.00)*0.01094458<1.39
    AddNode("S84__conv_4_reg1_ReduceMean",
        Bindings(3,
            GNodeArg(GNA_IN, "S83_Output", 0),
            GNodeArg(GNA_OUT, "S84_Output", 0),
            GNodeArg(GNA_IN, "S84_Infos", 0)
        )
    );
    // Node expr_22 in_qs [-4.87<(u8-52.00)*0.09370713<19.02,-1.40<(i8-0.00)*0.01094458<1.39] out_qs [-5.40<(u8-59.00)*0.09159238<17.95,-324.57<(i8-0.00)*2.53567529<322.03]
    AddNode("S85_expr_22",
        Bindings(4,
            GNodeArg(GNA_IN, "S81_Output", 0),
            GNodeArg(GNA_IN, "S84_Output", 0),
            GNodeArg(GNA_OUT, "S85_Output_0", 0),
            GNodeArg(GNA_OUT, "S85_Output_1", 0)
        )
    );
    // Node _conv_4_reg1_ReduceMean_1_fusion inq -324.57<(i8-0.00)*2.53567529<322.03 outq 0.00<(i8--128.00)*0.01946842<4.96
    AddNode("S86__conv_4_reg1_ReduceMean_1_fusion",
        Bindings(4,
            GNodeArg(GNA_IN, "S85_Output_1", 0),
            GNodeArg(GNA_OUT, "S86_Output", 0),
            GNodeArg(GNA_IN, "S86_Infos", 0),
            GNodeArg(GNA_IN, "RsqrtLUT", 0)
        )
    );
    // Node expr_23 in_qs [-5.40<(u8-59.00)*0.09159238<17.95,0.00<(i8--128.00)*0.01946842<4.96,-1.02<(i8-0.00)*0.00798787<1.01,-59.74<(i8-0.00)*0.46673588<59.28] out_qs [-4.45<(u8-97.00)*0.04588287<7.25]
    AddNode("S89_expr_23",
        Bindings(5,
            GNodeArg(GNA_IN, "S85_Output_0", 0),
            GNodeArg(GNA_IN, "S86_Output", 0),
            GNodeArg(GNA_IN, "Constant_onnx__mul_337", 0),
            GNodeArg(GNA_IN, "Constant_onnx__add_338", 0),
            GNodeArg(GNA_OUT, "S89_Output", 0)
        )
    );
    // Node expr_16 in_qs [-14.61<(u8-99.00)*0.14762190<23.03,-4.45<(u8-97.00)*0.04588287<7.25] out_qs [-15.99<(u8-101.00)*0.15828514<24.38]
    AddNode("S90_expr_16",
        Bindings(3,
            GNodeArg(GNA_IN, "S75_Output", 0),
            GNodeArg(GNA_IN, "S89_Output", 0),
            GNodeArg(GNA_OUT, "S90_Output", 0)
        )
    );
    // Node _conv_5_conv1d_Conv_fusion_trans_in0 inq -15.99<(u8-101.00)*0.15828514<24.38 outq -15.99<(u8-101.00)*0.15828514<24.38
    AddNode("S92__conv_5_conv1d_Conv_fusion_trans_in0",
        Bindings(2,
            GNodeArg(GNA_IN, "S90_Output", 0),
            GNodeArg(GNA_OUT, "S92_Output", 0)
        )
    );
    // Node S95__conv_5_conv1d_Conv_fusion inq -15.99<(u8-101.00)*0.15828514<24.38 weightsq chan<(u8-128.00)*chan<chan outq -4.93<(u8-27.00)*0.18276313<41.67 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S95__conv_5_conv1d_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S92_Output", 0),
            GNodeArg(GNA_IN, "_conv_5_conv1d_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_conv_5_conv1d_bias", 0),
            GNodeArg(GNA_OUT, "S95_Output", 0),
            GNodeArg(GNA_IN, "S95_Mul_scale", 0),
            GNodeArg(GNA_IN, "S95_Mul_shift", 0),
            GNodeArg(GNA_IN, "S95_Infos", 0)
        )
    );
    // Node _conv_5_conv1d_Conv_fusion_trans_out0 inq -4.93<(u8-27.00)*0.18276313<41.67 outq -4.93<(u8-27.00)*0.18276313<41.67
    AddNode("S96__conv_5_conv1d_Conv_fusion_trans_out0",
        Bindings(2,
            GNodeArg(GNA_IN, "S95_Output", 0),
            GNodeArg(GNA_OUT, "S96_Output", 0)
        )
    );
    // Node _conv_5_conv1d_Conv_reshape_out_qout0 inq -4.93<(u8-27.00)*0.18276313<41.67 outq -41.98<(i8-0.00)*0.32796827<41.65
    AddNode("S98__conv_5_conv1d_Conv_reshape_out_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S96_Output", 0),
            GNodeArg(GNA_OUT, "S98_Output", 0),
            GNodeArg(GNA_IN, "S98_Infos", 0)
        )
    );
    // Node _conv_5_reg1_ReduceMean inq -41.98<(i8-0.00)*0.32796827<41.65 outq -2.69<(i8-0.00)*0.02105393<2.67
    AddNode("S99__conv_5_reg1_ReduceMean",
        Bindings(3,
            GNodeArg(GNA_IN, "S98_Output", 0),
            GNodeArg(GNA_OUT, "S99_Output", 0),
            GNodeArg(GNA_IN, "S99_Infos", 0)
        )
    );
    // Node expr_25 in_qs [-4.93<(u8-27.00)*0.18276313<41.67,-2.69<(i8-0.00)*0.02105393<2.67] out_qs [-6.50<(u8-36.00)*0.18047455<39.52,-1569.73<(i8-0.00)*12.26354122<1557.47]
    AddNode("S100_expr_25",
        Bindings(4,
            GNodeArg(GNA_IN, "S96_Output", 0),
            GNodeArg(GNA_IN, "S99_Output", 0),
            GNodeArg(GNA_OUT, "S100_Output_0", 0),
            GNodeArg(GNA_OUT, "S100_Output_1", 0)
        )
    );
    // Node _conv_5_reg1_ReduceMean_1_fusion inq -1569.73<(i8-0.00)*12.26354122<1557.47 outq 0.00<(i8--128.00)*0.01724156<4.40
    AddNode("S101__conv_5_reg1_ReduceMean_1_fusion",
        Bindings(4,
            GNodeArg(GNA_IN, "S100_Output_1", 0),
            GNodeArg(GNA_OUT, "S101_Output", 0),
            GNodeArg(GNA_IN, "S101_Infos", 0),
            GNodeArg(GNA_IN, "RsqrtLUT", 0)
        )
    );
    // Node expr_26 in_qs [-6.50<(u8-36.00)*0.18047455<39.52,0.00<(i8--128.00)*0.01724156<4.40,-1.02<(i8-0.00)*0.00798026<1.01,-104.15<(i8-0.00)*0.81369133<103.34] out_qs [-4.68<(u8-101.00)*0.04633476<7.14]
    AddNode("S104_expr_26",
        Bindings(5,
            GNodeArg(GNA_IN, "S100_Output_0", 0),
            GNodeArg(GNA_IN, "S101_Output", 0),
            GNodeArg(GNA_IN, "Constant_onnx__mul_344", 0),
            GNodeArg(GNA_IN, "Constant_onnx__add_345", 0),
            GNodeArg(GNA_OUT, "S104_Output", 0)
        )
    );
    // Node expr_19 in_qs [-15.99<(u8-101.00)*0.15828514<24.38,-4.68<(u8-101.00)*0.04633476<7.14] out_qs [-18.62<(u8-102.00)*0.18251129<27.92]
    AddNode("S105_expr_19",
        Bindings(3,
            GNodeArg(GNA_IN, "S90_Output", 0),
            GNodeArg(GNA_IN, "S104_Output", 0),
            GNodeArg(GNA_OUT, "S105_Output", 0)
        )
    );
    // Node _conv_6_conv1d_Conv_fusion_trans_in0 inq -18.62<(u8-102.00)*0.18251129<27.92 outq -18.62<(u8-102.00)*0.18251129<27.92
    AddNode("S107__conv_6_conv1d_Conv_fusion_trans_in0",
        Bindings(2,
            GNodeArg(GNA_IN, "S105_Output", 0),
            GNodeArg(GNA_OUT, "S107_Output", 0)
        )
    );
    // Node S110__conv_6_conv1d_Conv_fusion inq -18.62<(u8-102.00)*0.18251129<27.92 weightsq chan<(u8-128.00)*chan<chan outq -8.93<(u8-53.00)*0.16845165<34.03 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S110__conv_6_conv1d_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S107_Output", 0),
            GNodeArg(GNA_IN, "_conv_6_conv1d_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_conv_6_conv1d_bias", 0),
            GNodeArg(GNA_OUT, "S110_Output", 0),
            GNodeArg(GNA_IN, "S110_Mul_scale", 0),
            GNodeArg(GNA_IN, "S110_Mul_shift", 0),
            GNodeArg(GNA_IN, "S110_Infos", 0)
        )
    );
    // Node _conv_6_conv1d_Conv_fusion_trans_out0 inq -8.93<(u8-53.00)*0.16845165<34.03 outq -8.93<(u8-53.00)*0.16845165<34.03
    AddNode("S111__conv_6_conv1d_Conv_fusion_trans_out0",
        Bindings(2,
            GNodeArg(GNA_IN, "S110_Output", 0),
            GNodeArg(GNA_OUT, "S111_Output", 0)
        )
    );
    // Node _conv_6_conv1d_Conv_reshape_out_qout0 inq -8.93<(u8-53.00)*0.16845165<34.03 outq -34.34<(i8-0.00)*0.26825306<34.07
    AddNode("S113__conv_6_conv1d_Conv_reshape_out_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S111_Output", 0),
            GNodeArg(GNA_OUT, "S113_Output", 0),
            GNodeArg(GNA_IN, "S113_Infos", 0)
        )
    );
    // Node _conv_6_reg1_ReduceMean inq -34.34<(i8-0.00)*0.26825306<34.07 outq -2.92<(i8-0.00)*0.02278673<2.89
    AddNode("S114__conv_6_reg1_ReduceMean",
        Bindings(3,
            GNodeArg(GNA_IN, "S113_Output", 0),
            GNodeArg(GNA_OUT, "S114_Output", 0),
            GNodeArg(GNA_IN, "S114_Infos", 0)
        )
    );
    // Node expr_28 in_qs [-8.93<(u8-53.00)*0.16845165<34.03,-2.92<(i8-0.00)*0.02278673<2.89] out_qs [-10.05<(u8-61.00)*0.16480184<31.97,-1027.83<(i8-0.00)*8.02993488<1019.80]
    AddNode("S115_expr_28",
        Bindings(4,
            GNodeArg(GNA_IN, "S111_Output", 0),
            GNodeArg(GNA_IN, "S114_Output", 0),
            GNodeArg(GNA_OUT, "S115_Output_0", 0),
            GNodeArg(GNA_OUT, "S115_Output_1", 0)
        )
    );
    // Node _conv_6_reg1_ReduceMean_1_fusion inq -1027.83<(i8-0.00)*8.02993488<1019.80 outq 0.00<(i8--128.00)*0.01463903<3.73
    AddNode("S116__conv_6_reg1_ReduceMean_1_fusion",
        Bindings(4,
            GNodeArg(GNA_IN, "S115_Output_1", 0),
            GNodeArg(GNA_OUT, "S116_Output", 0),
            GNodeArg(GNA_IN, "S116_Infos", 0),
            GNodeArg(GNA_IN, "RsqrtLUT", 0)
        )
    );
    // Node expr_29 in_qs [-10.05<(u8-61.00)*0.16480184<31.97,0.00<(i8--128.00)*0.01463903<3.73,-1.02<(i8-0.00)*0.00794528<1.01,-80.40<(i8-0.00)*0.62810724<79.77] out_qs [-4.28<(u8-98.00)*0.04370728<6.86]
    AddNode("S119_expr_29",
        Bindings(5,
            GNodeArg(GNA_IN, "S115_Output_0", 0),
            GNodeArg(GNA_IN, "S116_Output", 0),
            GNodeArg(GNA_IN, "Constant_onnx__mul_351", 0),
            GNodeArg(GNA_IN, "Constant_onnx__add_352", 0),
            GNodeArg(GNA_OUT, "S119_Output", 0)
        )
    );
    // Node expr_20 in_qs [-18.62<(u8-102.00)*0.18251129<27.92,-4.28<(u8-98.00)*0.04370728<6.86] out_qs [-18.37<(u8-93.00)*0.19753720<32.00]
    AddNode("S120_expr_20",
        Bindings(3,
            GNodeArg(GNA_IN, "S105_Output", 0),
            GNodeArg(GNA_IN, "S119_Output", 0),
            GNodeArg(GNA_OUT, "S120_Output", 0)
        )
    );
    // Node _conv_7_conv1d_Conv_fusion_trans_in0 inq -18.37<(u8-93.00)*0.19753720<32.00 outq -18.37<(u8-93.00)*0.19753720<32.00
    AddNode("S122__conv_7_conv1d_Conv_fusion_trans_in0",
        Bindings(2,
            GNodeArg(GNA_IN, "S120_Output", 0),
            GNodeArg(GNA_OUT, "S122_Output", 0)
        )
    );
    // Node S125__conv_7_conv1d_Conv_fusion inq -18.37<(u8-93.00)*0.19753720<32.00 weightsq chan<(u8-128.00)*chan<chan outq -5.42<(u8-43.00)*0.12596372<26.70 biasesq chan<(i32-0.00)*chan<chan
    AddNode("S125__conv_7_conv1d_Conv_fusion",
        Bindings(7,
            GNodeArg(GNA_IN, "S122_Output", 0),
            GNodeArg(GNA_IN, "_conv_7_conv1d_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_conv_7_conv1d_bias", 0),
            GNodeArg(GNA_OUT, "S125_Output", 0),
            GNodeArg(GNA_IN, "S125_Mul_scale", 0),
            GNodeArg(GNA_IN, "S125_Mul_shift", 0),
            GNodeArg(GNA_IN, "S125_Infos", 0)
        )
    );
    // Node _conv_7_conv1d_Conv_fusion_trans_out0 inq -5.42<(u8-43.00)*0.12596372<26.70 outq -5.42<(u8-43.00)*0.12596372<26.70
    AddNode("S126__conv_7_conv1d_Conv_fusion_trans_out0",
        Bindings(2,
            GNodeArg(GNA_IN, "S125_Output", 0),
            GNodeArg(GNA_OUT, "S126_Output", 0)
        )
    );
    // Node _conv_7_conv1d_Conv_reshape_out_qout0 inq -5.42<(u8-43.00)*0.12596372<26.70 outq -26.91<(i8-0.00)*0.21024752<26.70
    AddNode("S128__conv_7_conv1d_Conv_reshape_out_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S126_Output", 0),
            GNodeArg(GNA_OUT, "S128_Output", 0),
            GNodeArg(GNA_IN, "S128_Infos", 0)
        )
    );
    // Node _conv_7_reg1_ReduceMean inq -26.91<(i8-0.00)*0.21024752<26.70 outq -2.98<(i8-0.00)*0.02326717<2.95
    AddNode("S129__conv_7_reg1_ReduceMean",
        Bindings(3,
            GNodeArg(GNA_IN, "S128_Output", 0),
            GNodeArg(GNA_OUT, "S129_Output", 0),
            GNodeArg(GNA_IN, "S129_Infos", 0)
        )
    );
    // Node expr_31 in_qs [-5.42<(u8-43.00)*0.12596372<26.70,-2.98<(i8-0.00)*0.02326717<2.95] out_qs [-7.56<(u8-60.00)*0.12597473<24.57,-607.23<(i8-0.00)*4.74400520<602.49]
    AddNode("S130_expr_31",
        Bindings(4,
            GNodeArg(GNA_IN, "S126_Output", 0),
            GNodeArg(GNA_IN, "S129_Output", 0),
            GNodeArg(GNA_OUT, "S130_Output_0", 0),
            GNodeArg(GNA_OUT, "S130_Output_1", 0)
        )
    );
    // Node _conv_7_reg1_ReduceMean_1_fusion inq -607.23<(i8-0.00)*4.74400520<602.49 outq 0.00<(i8--128.00)*0.01489041<3.80
    AddNode("S131__conv_7_reg1_ReduceMean_1_fusion",
        Bindings(4,
            GNodeArg(GNA_IN, "S130_Output_1", 0),
            GNodeArg(GNA_OUT, "S131_Output", 0),
            GNodeArg(GNA_IN, "S131_Infos", 0),
            GNodeArg(GNA_IN, "RsqrtLUT", 0)
        )
    );
    // Node expr_32 in_qs [-7.56<(u8-60.00)*0.12597473<24.57,0.00<(i8--128.00)*0.01489041<3.80,-1.03<(i8-0.00)*0.00801224<1.02,-63.04<(i8-0.00)*0.49248614<62.55] out_qs [-3.62<(u8-89.00)*0.04070546<6.76]
    AddNode("S134_expr_32",
        Bindings(5,
            GNodeArg(GNA_IN, "S130_Output_0", 0),
            GNodeArg(GNA_IN, "S131_Output", 0),
            GNodeArg(GNA_IN, "Constant_onnx__mul_358", 0),
            GNodeArg(GNA_IN, "Constant_onnx__add_359", 0),
            GNodeArg(GNA_OUT, "S134_Output", 0)
        )
    );
    // Node expr_4 in_qs [-7.18<(u8-121.00)*0.05931951<7.95,-5.07<(u8-101.00)*0.05015203<7.72,-4.57<(u8-99.00)*0.04614057<7.20,-3.87<(u8-93.00)*0.04164210<6.75,-4.45<(u8-97.00)*0.04588287<7.25,-4.68<(u8-101.00)*0.04633476<7.14,-4.28<(u8-98.00)*0.04370728<6.86,-3.62<(u8-89.00)*0.04070546<6.76] out_qs [-15.70<(u8-84.00)*0.18695848<31.97]
    AddNode("S135_expr_4",
        Bindings(9,
            GNodeArg(GNA_IN, "S30_Output_0", 0),
            GNodeArg(GNA_IN, "S44_Output", 0),
            GNodeArg(GNA_IN, "S59_Output", 0),
            GNodeArg(GNA_IN, "S74_Output", 0),
            GNodeArg(GNA_IN, "S89_Output", 0),
            GNodeArg(GNA_IN, "S104_Output", 0),
            GNodeArg(GNA_IN, "S119_Output", 0),
            GNodeArg(GNA_IN, "S134_Output", 0),
            GNodeArg(GNA_OUT, "S135_Output", 0)
        )
    );
    // Node _reshape_speech_reshape_speech_0_Conv_fusion_trans_in0 inq -15.70<(u8-84.00)*0.18695848<31.97 outq -15.70<(u8-84.00)*0.18695848<31.97
    AddNode("S137__reshape_speech_reshape_speech_0_Conv_fusion_trans_in0",
        Bindings(2,
            GNodeArg(GNA_IN, "S135_Output", 0),
            GNodeArg(GNA_OUT, "S137_Output", 0)
        )
    );
    // Node S140__reshape_speech_reshape_speech_0_Conv_fusion inq -15.70<(u8-84.00)*0.18695848<31.97 weightsq -0.19<(u8-128.00)*0.00150799<0.19 outq 0.00<(u8-0.00)*0.00392157<1.00 biasesq -605443.82<(i32-0.00)*0.00028193<605443.82
    AddNode("S140__reshape_speech_reshape_speech_0_Conv_fusion",
        Bindings(8,
            GNodeArg(GNA_IN, "S137_Output", 0),
            GNodeArg(GNA_IN, "_reshape_speech_reshape_speech_0_conv_weights", 0),
            GNodeArg(GNA_IN, "Constant_reshape_speech_0_bias", 0),
            GNodeArg(GNA_OUT, "S140_Output", 0),
            GNodeArg(GNA_IN, "S140_Mul_scale", 0),
            GNodeArg(GNA_IN, "S140_Mul_shift", 0),
            GNodeArg(GNA_IN, "S140_Infos", 0),
            GNodeArg(GNA_IN, "SigmoidLUT_u8", 0)
        )
    );
    // Node expr_33 in_qs [0.00<(u8-0.00)*0.00392157<1.00] out_qs [f32]
    AddNode("S142_expr_33",
        Bindings(2,
            GNodeArg(GNA_IN, "S140_Output", 0),
            GNodeArg(GNA_OUT, "Output_1", 0)
        )
    );
    // Node _reshape_speech_reshape_speech_0_Conv_reshape_qout0 inq 0.00<(u8-0.00)*0.00392157<1.00 outq f32
    AddNode("S144__reshape_speech_reshape_speech_0_Conv_reshape_qout0",
        Bindings(3,
            GNodeArg(GNA_IN, "S140_Output", 0),
            GNodeArg(GNA_OUT, "Output_2", 0),
            GNodeArg(GNA_IN, "S144_Infos", 0)
        )
    );
    CloseGraph();
#endif
}

int main(int argc, char **argv)

{
    if (TilerParseOptions(argc, argv)) {
            printf("Failed to initialize or incorrect output arguments directory.\n"); return 1;
    }
    main_1Model(128000, 1100000, 32000000, 64*1024*1024);
    GenerateTilingCode();
    return 0;
}
