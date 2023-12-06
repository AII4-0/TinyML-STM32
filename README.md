# TinyML-STM32
This repo contains a Nucleo-F411RE and a Nucleo-H7A3ZI-Q firmware project. It enables inference with the FTLite Micro engine on NASA-MSL data. 

# Getting started

To test the project on a Nucleo-F411RE or a Nucleo-H7a3ZI-Q, you juste need to STM32CubeIDE and Git installed on Windows or Linux.
Versions tested : 
- Windows 11 : STM32CubeIDE v1.13.2
- Linux Ubuntu20.04 : STM32CubeIDE v1.13.2

To test inference on a Nucleo board, follow the instructions below :
1. Clone the repo :

    ```bash
    git clone --recursive git@github.com:AII4-0/TinyML-STM32.git
    ```
3. Open STM32CubeIDE and open as workspace the repo cloned.
4. Import the project as following :
    1. File > Import > General > Existing Projects into Workspace
    2. Next
    3. Browse and select P_DeployTSAD (Nucleo-F411RE) or P_DeployTSAD_h7 (Nucleo-H7A3ZI-Q) folder.
    4. Finish
5. Build the project with the hammer.
6. Connect the Nucleo via an USB cable to your PC.
7. Open a terminal or putty to open a virtual serial port where the Nucleo is connected. Set the baudrate to 9600.
    
    ![Alt text](docs/images/portcom.png)

8. In the STM32CubeIDE, start debugging.
9. You can change the configuration if you change the define below in the main.cpp file.
    ```cpp
    /* Private includes ----------------------------------------------------------*/
    /* USER CODE BEGIN Includes */
    #define RUN_INFERENCE	// Choose RUN_INFERENCE or BASELINE_MEMORY_FOOTPRINT or PROFILE_MEMORY_AND_LATENCY
    #define LSTM_QUANT				//Choose between LSTM_QUANT, GAN or GAN_QUANT
    ```

# How to reproduce these Nucleo project from scratch

## Prerequis

This installation is tested on Ubuntu20.04 with python3.9 installed.

1. Clone the repo with the submodule

    ```bash
    git clone --recursive git@github.com:AII4-0/TinyML-STM32.git
    cd TinyML-STM32
    ```

2. Install dependencies below and STM32CubeIDE (tested with v1.13.2).

    ```bash
    # Create virtual env
    sudo apt update
    sudo apt install make git zip

    python3.9 -m venv venv39
    source venv39/bin/activate

    pip install -r tsad-benchmark/requirements/requirements.txt
    pip install -r tsad-benchmark/requirements/requirements_tflite.txt
    ```

## 1 Generate the TFLite model and export data

1. Go to the submodule tsad-benchmark and generate the model. Refer to the readme of the submodule for more information.

    ```bash
    cd tsad-benchmark

    ############################################
    # Prepare data, train the mode and export it
    ############################################
    # LSTM
    python3 main.py --dataset NASA-MSL --batch_size 1024 --window_size 100 --model LSTM --epochs 10 --hidden_size 256 --num_layers 2 --dropout 0 --prediction_length 1 --learning_rate 0.001 --export_folder ../output
    # GAN
    python3 main.py --model GAN --dataset NASA-MSL --epochs 10 --batch_size 512 --window_size 100 --hidden_size 128 --prediction_length 1 --num_layers 3 --learning_rate 0.001 --export_folder ../output

    ##############################################
    # Convert the exported model into TFLite model
    ##############################################
    # LSTM - entity 0
    python3 convert_to_tflite.py --dataset NASA-MSL --entity 0 --window_size 100 --model ../output/lstm_0.pt
    # LSTM - entity 1
    python3 convert_to_tflite.py --dataset NASA-MSL --entity 1 --window_size 100 --model ../output/lstm_1.pt
    # GAN - entity 0
    python3 convert_to_tflite.py --dataset NASA-MSL --entity 0 --window_size 100 --model ../output/gan_0.pt

    ###################################
    # Test the model exported in TFLite
    # and convert dataset in C source
    ###################################
    # LSTM TFLite - entity 0
    python3 check_tflite_model.py --dataset NASA-MSL --entity 0 --window_size 100 --pytorch_model ../output/lstm_0.pt --tflite_model ../output/lstm_0.tflite --start_index_inputs_exported_in_c 400 --n_inputs_exported_in_c 100
    # LSTM TFLite - entity 1
    python3 check_tflite_model.py --dataset NASA-MSL --entity 1 --window_size 100 --pytorch_model ../output/lstm_1.pt --tflite_model ../output/lstm_1.tflite --start_index_inputs_exported_in_c 400 --n_inputs_exported_in_c 100
    # GAN TFLite - entity 0
    python3 check_tflite_model.py --dataset NASA-MSL --entity 0 --window_size 100 --pytorch_model ../output/gan_0.pt --tflite_model ../output/gan_0.tflite --start_index_inputs_exported_in_c 400 --n_inputs_exported_in_c 100

    #############################################
    # Test the model exported in quantized TFLite
    # and convert dataset in C source
    #############################################
    # LSTM TFLite quantize - entity 0
    python3 check_tflite_model.py --dataset NASA-MSL --entity 0 --window_size 100 --pytorch_model ../output/lstm_0.pt --tflite_model ../output/lstm_0_quant.tflite --start_index_inputs_exported_in_c 400 --n_inputs_exported_in_c 100
    # LSTM TFLite quantize - entity 1
    python3 check_tflite_model.py --dataset NASA-MSL --entity 1 --window_size 100 --pytorch_model ../output/lstm_1.pt --tflite_model ../output/lstm_1_quant.tflite --start_index_inputs_exported_in_c 400 --n_inputs_exported_in_c 100
    # GAN TFLite quantize - entity 0
    python3 check_tflite_model.py --dataset NASA-MSL --entity 0 --window_size 100 --pytorch_model ../output/gan_0.pt --tflite_model ../output/gan_0_quant.tflite --start_index_inputs_exported_in_c 400 --n_inputs_exported_in_c 100


    cd ..
    ```

## 2 Test TFLite model on the host

The tsad-benchmark repo test the TFLite model with the python framework. A good practice is to test the TFLite model on the host with the TFLite C++ framework. It's based on the minimal example [here](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/examples/minimal).

Follow the procedure below to test the model.

1. Install CMake 3.16 or higher
    ```bash
    sudo apt-get install cmake
    ```
2. Generate and compile the test program to test the model.
    ```bash
    cd P_DeployTSAD_host_in_C
    mkdir build
    cd build

    cmake ../
    cmake --build . -j
    ```
3. Test the model
    ```bash
    # ./minimal <model> <index to start inference in C_1_test_400.h>
    ./minimal ../../output/gan_0_quant.tflite 0
    ```
4. The result must be the same as the result of the `tsad-benchmark/check_tflite_model.py` scipt.



## 2 Generate the TFLiteMicro library for the embedded system

1. Generate the source tree

    ```bash
    cd tflite-micro
    python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py \
    --makefile_options="TARGET=cortex_m_generic OPTIMIZED_KERNEL_DIR=cmsis_nn TARGET_ARCH=project_generation" \
    /tmp/tflm-tree
    ```


## 3 Create a new project to deploy the model

1. Open STM32CubeIDE and open as workspace the repo cloned.
3. Create a new project : **File > New > New STM32 project** and choose the right board

    ![Alt text](docs/images/project.png)
4. Choose a name for the project and select C++ project. Click until finish.

    ![Alt text](docs/images/project2.png)
5. Go the the pinout configuration tab and activate the CRC.

    ![Alt text](docs/images/pinout.png)
6. The configuration perspective open it. Go to the Clock configuration tab and set the clock to the max (100MHz)

    ![Alt text](docs/images/clock.png)
7. Save and generate the new C code.
8. Right click on the project and create a new folder named **tensorflow_lite**.

    ![Alt text](docs/images/folder.png)
9. Copy the content of the folder `/tmp/tflm-tree`, generated on the section [2 Generate the TFLiteMicro library for the embedded system](##-2-Generate-the-TFLiteMicro-library-for-the-embedded-system).

    ```bash
    cp -r /tmp/tflm-tree/* P_DeployTSAD/tensorflow_lite
    ```
10. Include Headers and source in build process. Go to project > Properties. Then, go to C/C++ General> Paths and Symbols > Includes tab > GNU C. Click Add. In the pop-up, click workspace. Select the tensorflow_lite directoy in your project. CHeck Add to all configurations and Add to all languages. Repeat the last two step to iclude directories show in the figure below.

    ![Alt text](docs/images/include.png)
11. Include the tensorflow_lite directory in the Source Location

    ![Alt text](docs/images/source.png)
12. In Settings > MCU Settings, check the option **Use float with printf from newlib-nano**. It's needed to print float values.

    ![Alt text](<docs/images/MCU settings.png>)
13. Add the compiler option `CMSIS_NN`, `ARMCM4`, `CMSIS_DEVICE_ARM_CORTEX_M_XX_HEADER_FILE`, `CPU_M4`, `TF_LITE_DISABLE_X86_NEON`, `TF_LITE_MCU_DEBUG_LOG`, `TF_LITE_STATIC_MEMORY` and `USE_HAL_DRIVER`. Check **Add to all configurations** and **Add to all languages**.

    ![Alt text](docs/images/CMSIS.png)

14. Add the compiler flag `MD` in **MCU GCC Assembler**, **MCU GCC Compiler** and **MCU G++ Compiler**

    ![Alt text](docs/images/mdFlag.png)

15. Modify the function `ticks_per_second()` of the file `P_DeployTSAD_h7\tensorflow_lite\tensorflow\lite\micro\cortex_m_generic\micro_time.cc`. It depends of the clock speed.
    ```c
    uint32_t ticks_per_second() { return SystemCoreClock; }
    ```
16. Rename main.c to main.cpp
17. Build the project
18. If the flash is too small, add the optimization for size :

    ![Alt text](docs/images/optimize.png)

19. Implement your application and add model + data (gan_0_quant.cpp, gan_0_quant.h, C_1_test.h) in the project.

20. Follow the same procedure for the Nucleo-H7a3ZI-Q.
