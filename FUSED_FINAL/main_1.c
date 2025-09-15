
/*
 * Copyright (C) 2017 GreenWaves Technologies
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 *
 */


/* Autotiler includes. */
#include "main_1.h"
#include "main_2Kernels.h"
#include "gaplib/fs_switch.h"
#include "measurments_utils.h"


#ifndef STACK_SIZE
#define STACK_SIZE      1024
#endif

pi_gpio_e gpio_test_0, gpio_test_1, gpio_test_2;
#define TEST_GPIO_0 PI_GPIO_A89
#define WRITE_GPIO(gpio_pin_x, x) {hal_compiler_barrier(); pi_gpio_pin_write(gpio_pin_x, x); hal_compiler_barrier();}
#define SWITCH_GPIO(gpio_pin_x) {hal_compiler_barrier(); pi_gpio_pin_toggle(gpio_pin_x); hal_compiler_barrier();}

AT_DEFAULTFLASH_EXT_ADDR_TYPE main_1_L3_Flash = 0 ;
AT_DEFAULTFLASH_EXT_ADDR_TYPE main_1_b_L3_Flash = 0 ;
AT_DEFAULTFLASH_EXT_ADDR_TYPE main_2_L3_Flash = 0 ;
AT_DEFAULTFLASH_EXT_ADDR_TYPE DecisionNet_L3_Flash = 0;
AT_DEFAULTFLASH_EXT_ADDR_TYPE Big_fft_forward_L3_Flash = 0;
AT_DEFAULTFLASH_EXT_ADDR_TYPE fft_forward_L3_Flash = 0;
AT_DEFAULTFLASH_EXT_ADDR_TYPE irfft_forward_L3_Flash = 0;

float G2_Input [6144];
float G2_out [512];
float G2_before_irfft [514];
float* output_imaginary = &(G2_before_irfft[0]);
float* output_real = &(G2_before_irfft[257]);
uint8_t first_execution = 0;


/* Inputs */
/* Outputs */

/* Copy inputs functions */
switch_fs_t input_fs;
void *Input_File_Input_1;
int Input_File_Input_1_Position;
#define EXPECTED_NUM_ITERATIONS 1
int open_inputs() {
    __FS_INIT(input_fs);
    /* opening file Input_1 */
    #ifdef __EMUL__
    Input_File_Input_1 = __OPEN_READ(input_fs, "../Input_1.bin");
    #else
    Input_File_Input_1 = __OPEN_READ(input_fs, "../Input_1.bin");
    #endif
    if (!Input_File_Input_1) return 1;
    Input_File_Input_1_Position = 0;
    return 0;
}



void close_inputs() {
    __CLOSE(Input_File_Input_1);

    __FS_DEINIT(input_fs);
}

/* Copy outputs functions */
switch_fs_t output_fs;
int open_outputs() {
    return 0;
}

void write_outputs() {
}

void close_outputs() {
}


float decision;


static void cluster(void * arg)
{
    #ifdef PERF
    printf("Start timer\n");
    gap_cl_starttimer();
    gap_cl_resethwtimer();
    #endif
    int iteration = (int) arg;
    main_1CNN_ConstructCluster();
    
    WRITE_GPIO(gpio_test_0, 1);
    DecisionNetCNN((unsigned char * __restrict__)DecisionNet_L3_Memory,(unsigned char * __restrict__)&decision);
    SWITCH_GPIO(gpio_test_0);
    main_1CNN();
    SWITCH_GPIO(gpio_test_0);
    main_1_bCNN();
    SWITCH_GPIO(gpio_test_0);
    main_2CNN(G2_Input,output_imaginary,output_real);
    WRITE_GPIO(gpio_test_0, 0);
    printf("Runner completed: %d\n", iteration);
}

// static void cluster_b(void * arg)
// {
//     #ifdef PERF
//     printf("Start timer\n");
//     gap_cl_starttimer();
//     gap_cl_resethwtimer();
//     #endif
//     int iteration = (int) arg;
    
    
    
// }


// static void cluster_2(void * arg)
// {
//     #ifdef PERF
//     printf("Start timer\n");
//     gap_cl_starttimer();
//     gap_cl_resethwtimer();
//     #endif
//     int iteration = (int) arg;
    
   
// }

int main(int argc, char *argv[])
{
    printf("\n\n\t *** NNTOOL main_1 Example ***\n\n");
    printf("Entering main controller\n");

    /* Configure And open cluster. */
    gpio_test_0 = TEST_GPIO_0;
    pi_pad_function_set(PI_PAD_089, 1);
    pi_gpio_pin_configure(gpio_test_0, PI_GPIO_OUTPUT);

    struct pi_device cluster_dev;
    struct pi_cluster_conf cl_conf;
    pi_cluster_conf_init(&cl_conf);
    cl_conf.cc_stack_size = STACK_SIZE;

    cl_conf.id = 0; /* Set cluster ID. */
                    // Enable the special icache for the master core
    cl_conf.icache_conf = PI_CLUSTER_MASTER_CORE_ICACHE_ENABLE |
                    // Enable the prefetch for all the cores, it's a 9bits mask (from bit 2 to bit 10), each bit correspond to 1 core
                    PI_CLUSTER_ICACHE_PREFETCH_ENABLE |
                    // Enable the icache for all the cores
                    PI_CLUSTER_ICACHE_ENABLE;

    pi_open_from_conf(&cluster_dev, (void *) &cl_conf);
    if (pi_cluster_open(&cluster_dev))
    {
        printf("Cluster open failed !\n");
        return -4;
    }

    /* Frequency Settings: defined in the Makefile */
    int cur_fc_freq = pi_freq_set(PI_FREQ_DOMAIN_FC, FREQ_FC*1000*1000);
    int cur_cl_freq = pi_freq_set(PI_FREQ_DOMAIN_CL, FREQ_CL*1000*1000);
    int cur_pe_freq = pi_freq_set(PI_FREQ_DOMAIN_PERIPH, FREQ_PE*1000*1000);
    if (cur_fc_freq == -1 || cur_cl_freq == -1 || cur_pe_freq == -1)
    {
        printf("Error changing frequency !\nTest failed...\n");
        return -4;
    }
	printf("FC Frequency = %d Hz CL Frequency = %d Hz PERIPH Frequency = %d Hz\n", 
            pi_freq_get(PI_FREQ_DOMAIN_FC), pi_freq_get(PI_FREQ_DOMAIN_CL), pi_freq_get(PI_FREQ_DOMAIN_PERIPH));

	#ifdef VOLTAGE
	pi_pmu_voltage_set(PI_PMU_VOLTAGE_DOMAIN_CHIP, VOLTAGE);
	pi_pmu_voltage_set(PI_PMU_VOLTAGE_DOMAIN_CHIP, VOLTAGE);
	#endif
	printf("Voltage: %dmV\n", pi_pmu_voltage_get(PI_PMU_VOLTAGE_DOMAIN_CHIP));

    


    {
        /* DEFAULTRAM Externally managed */
        AT_DEFAULTRAM_CONF_T DefaultRamConf;

        int Error;
        AT_DEFAULTRAM_CONF_INIT(&DefaultRamConf, AT_MEM_L3_DEFAULTRAM, 0);
        AT_DEFAULTRAM_OPEN(&DefaultRam, &DefaultRamConf, &Error);
        if (Error) {
            printf("Error opening DEFAULTRAM\n");
            return -6;
        }
    }
    

    // IMPORTANT - MUST BE CALLED AFTER THE CLUSTER IS SWITCHED ON!!!!
    printf("Constructor\n");
    int ConstructorErr = main_1CNN_Construct();
    if (ConstructorErr)
    {
        printf("Graph constructor exited with error: (%s)\n", GetAtErrorName(ConstructorErr));
        return -6;
    }
    

    /*
     * Put here Your input settings
     */
    if (open_inputs()) return -7;
    if (open_outputs()) return -8;
    printf("Call cluster\n");

    struct pi_cluster_task task;
    pi_cluster_task(&task, (void (*)(void *))cluster, NULL);
    pi_cluster_task_stacks(&task, NULL, SLAVE_STACK_SIZE);

    // struct pi_cluster_task task_b;
    // pi_cluster_task(&task_b, (void (*)(void *))cluster_b, NULL);
    // pi_cluster_task_stacks(&task_b, NULL, SLAVE_STACK_SIZE);

    // struct pi_cluster_task task_2;
    // pi_cluster_task(&task_2, (void (*)(void *))cluster_2, NULL);
    // pi_cluster_task_stacks(&task_2, NULL, SLAVE_STACK_SIZE);

    int iteration = 0;
    BiG_fft_forwardCNN_Construct();
    irfft_forwardCNN_Construct();
    fft_forwardCNN_Construct();
    DecisionNetCNN_Construct();
    main_1_bCNN_Construct();
    main_2CNN_Construct();
    

    while (iteration < EXPECTED_NUM_ITERATIONS) {
        if (EXPECTED_NUM_ITERATIONS > 1) printf("Iteration: %d of %d\n", iteration, EXPECTED_NUM_ITERATIONS);
        // if (!copy_inputs(iteration)) return -9;


        task.arg = (void *)iteration;
        pi_cluster_send_task_to_cl(&cluster_dev, &task);
        

        // pi_cluster_send_task_to_cl(&cluster_dev, &task_b);

        

        // pi_cluster_send_task_to_cl(&cluster_dev, &task_2);
        
        // write_outputs();
        iteration++;
    }

    
    


    close_inputs();
    close_outputs();
    

    main_1CNN_Destruct();
    main_1_bCNN_Destruct();
    main_2CNN_Destruct();

#ifdef PERF
	{
		unsigned long long int TotalCycles = 0, TotalOper = 0;
		printf("\n");
		for (unsigned int i=0; i<(sizeof(G1_AT_GraphPerf)/sizeof(unsigned int)); i++) {
			TotalCycles += G1_AT_GraphPerf[i]; TotalOper += G1_AT_GraphOperInfosNames[i];
		}
        for (unsigned int i=0; i<(sizeof(G1_2_AT_GraphPerf)/sizeof(unsigned int)); i++) {
			TotalCycles += G1_2_AT_GraphPerf[i]; TotalOper += G1_2_AT_GraphOperInfosNames[i];
		}
        for (unsigned int i=0; i<(sizeof(G2_AT_GraphPerf)/sizeof(unsigned int)); i++) {
			TotalCycles += G2_AT_GraphPerf[i]; TotalOper += G2_AT_GraphOperInfosNames[i];
		}
		for (unsigned int i=0; i<(sizeof(G1_AT_GraphPerf)/sizeof(unsigned int)); i++) {
			printf("%45s: Cycles: %12u, Cyc%%: %5.1f%%, Operations: %12u, Op%%: %5.1f%%, Operations/Cycle: %f\n", G1_AT_GraphNodeNames[i], G1_AT_GraphPerf[i], 100*((float) (G1_AT_GraphPerf[i]) / TotalCycles), G1_AT_GraphOperInfosNames[i], 100*((float) (G1_AT_GraphOperInfosNames[i]) / TotalOper), ((float) G1_AT_GraphOperInfosNames[i])/ G1_AT_GraphPerf[i]);
		}

        printf("\n");
		
		for (unsigned int i=0; i<(sizeof(G1_2_AT_GraphPerf)/sizeof(unsigned int)); i++) {
			printf("%45s: Cycles: %12u, Cyc%%: %5.1f%%, Operations: %12u, Op%%: %5.1f%%, Operations/Cycle: %f\n", G1_2_AT_GraphNodeNames[i], G1_2_AT_GraphPerf[i], 100*((float) (G1_2_AT_GraphPerf[i]) / TotalCycles), G1_2_AT_GraphOperInfosNames[i], 100*((float) (G1_2_AT_GraphOperInfosNames[i]) / TotalOper), ((float) G1_2_AT_GraphOperInfosNames[i])/ G1_2_AT_GraphPerf[i]);
		}

        printf("\n");

        for (unsigned int i=0; i<(sizeof(G2_AT_GraphPerf)/sizeof(unsigned int)); i++) {
			printf("%45s: Cycles: %12u, Cyc%%: %5.1f%%, Operations: %12u, Op%%: %5.1f%%, Operations/Cycle: %f\n", G2_AT_GraphNodeNames[i], G2_AT_GraphPerf[i], 100*((float) (G2_AT_GraphPerf[i]) / TotalCycles), G2_AT_GraphOperInfosNames[i], 100*((float) (G2_AT_GraphOperInfosNames[i]) / TotalOper), ((float) G2_AT_GraphOperInfosNames[i])/ G2_AT_GraphPerf[i]);
		}

		printf("\n");
		printf("%45s: Cycles: %12llu, Cyc%%: 100.0%%, Operations: %12llu, Op%%: 100.0%%, Operations/Cycle: %f\n", "Total", TotalCycles, TotalOper, ((float) TotalOper)/ TotalCycles);
		printf("\n");
	}
#endif

    printf("Ended\n");
    return 0;
}
