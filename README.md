# TinyML-NucleoF411RE
This repo contains a Nucleo-F411RE firmware workspace. It enables inference with the FTLite Micro engine on NASA-MSL data. 

# Getting started

## Prerequis

This installation is tested on Ubuntu with python3.9 installed.

1. Clone the repo with the submodule
```bash
git clone --recursive git@github.com:AII4-0/TinyML-NucleoF411RE.git
cd TinyML-NucleoF411RE
```

2. Install dependencies
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

# Prepare data, train the mode and export it
python3 main.py --dataset NASA-MSL --batch_size 1024 --window_size 100 --model LSTM --epochs 10 --hidden_size 128 --num_layers 2 --dropout 0 --prediction_length 1 --learning_rate 0.001 --export_folder ../output

# Convert the exported model into TFLite model
python3 convert_to_tflite.py --dataset NASA-MSL --entity 0 --window_size 100 --model ../output/lstm_0.pt

# Test the model exported in TFLite
python3 check_tflite_model.py --dataset NASA-MSL --entity 0 --window_size 100 --pytorch_model ../output/lstm_0.pt --tflite_model ../output/lstm_0.tflite --n_inputs_exported_in_c 500

# Test the model exported into quantized tf lite model
python3 check_tflite_model.py --dataset NASA-MSL --entity 0 --window_size 100 --pytorch_model ../output/lstm_0.pt --tflite_model ../output/lstm_0_quant.tflite --start_index_inputs_exported_in_c 400 --n_inputs_exported_in_c 100


cd ..
```

## 2 Generate the TFLiteMicro library for the embedded system

1. Generate the source tree
```bash
cd tflite-micro
python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py \
  --makefile_options="TARGET=cortex_m_generic OPTIMIZED_KERNEL_DIR=cmsis_nn TARGET_ARCH=project_generation" \
  /tmp/tflm-tree
```

## 3 Deploy the model on a the Nucleo-F411RE

1. Install STM32CubeIDE v1.13.2
2. Open STM32CubeIDE and select as workspace this repo.
    ![Alt text](docs/images/workspace.png)
3. 


## Create a new project to deploy the model

1. clone
2. Open worksapce
3. Create a new project : File > New > New STM32 project and choose the right board
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
10. Include Headers and source in build process. Go to project > Properties. Then, go to C/C++ General> Paths and Symbols > INcludes tab > GNU C. Click Add. In the pop-up, click workspace. Select the tensorflow_lite directoy in your project. CHeck Add to all configurations and Add to all languages. Repeat the last two step to iclude directories show in the figure below.
    ![Alt text](docs/images/include.png)
11. Include the tensorflow_lite directory in the Source Location
    ![Alt text](docs/images/source.png)
12. In Settings > MCU Settings, check the option **Use float with printf from newlib-nano**. It's needed to print float values.
    ![Alt text](<docs/images/MCU settings.png>)
13. Add the compiler option `CMSIS_NN`.
    ![Alt text](docs/images/CMSIS.png)
14. Copy the files `array.cc` and `array.h` in the folder `tensorflow_lite/tensorflow/lite/`.
    ```bash
    cp -r tflite-micro/tensorflow/lite/array.* P_DeployTSAD/tensorflow_lite/tensorflow/lite
    ```
15. Modify the file `P_test_Nucleo411RE\tensorflow_lite\tensorflow\lite\micro\micro_time.cc` like below :
    ```c
    #include "tensorflow/lite/micro/micro_time.h"
    #include "stm32f4xx_hal.h"

    #if defined(TF_LITE_USE_CTIME)
    #include <ctime>
    #endif

    namespace tflite {

    #if !defined(TF_LITE_USE_CTIME)

    // Reference implementation of the ticks_per_second() function that's required
    // for a platform to support Tensorflow Lite for Microcontrollers profiling.
    // This returns 0 by default because timing is an optional feature that builds
    // without errors on platforms that do not need it.
    uint32_t ticks_per_second()
    {
        return 1000;
    }

    // Reference implementation of the GetCurrentTimeTicks() function that's
    // required for a platform to support Tensorflow Lite for Microcontrollers
    // profiling. This returns 0 by default because timing is an optional feature
    // that builds without errors on platforms that do not need it.
    uint32_t GetCurrentTimeTicks()
    {
        return HAL_GetTick();		// Return the number of ticks. 1 tick == 1ms
    }

    #else  // defined(TF_LITE_USE_CTIME)

    // For platforms that support ctime, we implment the micro_time interface in
    // this central location.
    uint32_t ticks_per_second() { return CLOCKS_PER_SEC; }

    uint32_t GetCurrentTimeTicks() { return clock(); }
    #endif

    }  // namespace tflite
    ```
16. Build the project
17. If the flash is too small, add the optimization for size :
    ![Alt text](docs/images/optimize.png)