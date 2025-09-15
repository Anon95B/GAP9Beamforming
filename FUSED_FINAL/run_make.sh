cd /home/bomps/Scrivania/workfile/DATE_BEAMFORMING/Graph_1

source /home/bomps/Scrivania/workfile/gap_sdk_private/configs/gap9_evk_audio.sh
export TILER_INTEGRAL_GENERATOR_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/Generators/IntegralImage
export TILER_CNN_GENERATOR_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/CNN_Generators
export TILER_FFT_GEN_LUT_SCRIPT=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/DSP_Libraries/LUT_Tables/gen_scripts/GenFFTLUT.py
export TILER_INTEGRAL_KERNEL_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/Generators/IntegralImage
export TILER_WIN_GEN_LUT_SCRIPT=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/DSP_Libraries/LUT_Tables/gen_scripts/GenWinLUT.py
export TILER_ISP_GENERATOR_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/ISP_Generators
export TILER_FFT2D_TWIDDLE_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/Generators/FFT2DModel
export TILER_CNN_GENERATOR_PATH_SQ8=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/CNN_Generators_SQ8
export TILER_BILINEAR_RESIZE_KERNEL_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/ISP_Libraries
export TILER_LIB=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/Autotiler/LibTile.a
export TILER_FFT2D_GENERATOR_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/Generators/FFT2DModel
export TILER_CNN_KERNEL_PATH_SQ8=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_SQ8
export TILER_DSP_GENERATOR_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/DSP_Generators
export TILER_CNN_KERNEL_PATH_FP16X=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_fp16/CNN_Libraries_fp16x
export TILER_INC=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/Autotiler
export TILER_MFCC_GEN_LUT_SCRIPT=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/DSP_Libraries/LUT_Tables/gen_scripts/GenMFCCLUT.py
export TILER_CNN_KERNEL_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/CNN_Libraries
export AT_HOME=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3
export TILER_CNN_KERNEL_PATH_NE16=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_NE16
export TILER_GENERATOR_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/Generators
export TILER_CNN_KERNEL_PATH_FP16=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_fp16
export TILER_ISP_KERNEL_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/ISP_Libraries
export TILER_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3
export TILER_CNN_GENERATOR_PATH_FP16=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/CNN_Generators_fp16
export TILER_BILINEAR_RESIZE_GENERATOR_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/ISP_Generators
export TILER_DSP_KERNEL_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/DSP_Libraries
export TILER_DSP_KERNEL_V2_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/DSP_Librariesv2
export TILER_FFT2D_KERNEL_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/Generators/FFT2DModel
export TILER_TWID_GEN_SCRIPT=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/DSP_Librariesv2/TransformFunctions/GenTwid/GenTwid.py
export TILER_CNN_GENERATOR_PATH_NE16=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/CNN_Generators_NE16
export TILER_EMU_INC=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/Emulation
export TILER_FFT_LUT_PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/autotiler_v3/DSP_Libraries/LUT_Tables
export PATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/nntool/scripts:$PATH
export PYTHONPATH=/home/bomps/Scrivania/workfile/gap_sdk_private/tools/nntool:$PYTHONPATH
export CCACHE_BASEDIR=/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/Graph_1
mkdir -p /home/bomps/Scrivania/workfile/DATE_BEAMFORMING/Graph_1/build
retVal=$?
if [ $retVal -ne 0 ]; then
    exit $retVal
fi
(cd /home/bomps/Scrivania/workfile/DATE_BEAMFORMING/Graph_1; cmake -B build -G"Unix Makefiles")
retVal=$?
if [ $retVal -ne 0 ]; then
    exit $retVal
fi
(cd /home/bomps/Scrivania/workfile/DATE_BEAMFORMING/Graph_1; cmake --build build --target clean)
retVal=$?
if [ $retVal -ne 0 ]; then
    exit $retVal
fi
(cd /home/bomps/Scrivania/workfile/DATE_BEAMFORMING/Graph_1; cmake --build build --target all -j 32 )
retVal=$?
if [ $retVal -ne 0 ]; then
    exit $retVal
fi
(cd /home/bomps/Scrivania/workfile/DATE_BEAMFORMING/Graph_1; rm -f build/S*ArgName*ItemSize*Dim*.dat; cmake --build build --target run )
exit $?
