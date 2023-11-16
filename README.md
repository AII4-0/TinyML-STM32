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
python3 main.py --dataset NASA-MSL --batch_size 1024 --window_size 100 --model LSTM --epochs 10 --hidden_size 256 --num_layers 2 --dropout 0 --prediction_length 1 --learning_rate 0.001 --export_folder ../output

# Convert the exported model into TFLite model
python3 convert_to_tflite.py --dataset NASA-MSL --entity 0 --window_size 100 --model ../output/lstm_0.pt

# Test the model exported in TFLite
python3 check_tflite_model.py --dataset NASA-MSL --entity 0 --window_size 100 --pytorch_model ../output/lstm_0.pt --tflite_model ../output/lstm_0.tflite

cd ..
```

## 2 Generate the TFLiteMicro library for the embedded system

...