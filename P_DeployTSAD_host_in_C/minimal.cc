/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include <cstdio>
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"
#include "tensorflow/lite/optional_debug_tools.h"

// #include "C_1_test_0.h"
#include "C_1_test_400.h"

// This is an example that is minimal to read a model
// from disk and perform inference.
//
// Usage: minimal <tflite model> <indexInputToInfer>

#define TFLITE_MINIMAL_CHECK(x)                              \
  if (!(x)) {                                                \
    fprintf(stderr, "Error at %s:%d\n", __FILE__, __LINE__); \
    exit(1);                                                 \
  }

int main(int argc, char* argv[]) {
  if (argc != 3) {
    fprintf(stderr, "minimal <tflite model>\n");
    return 1;
  }
  const char* filename = argv[1];
  const char* indexInputToInfer = argv[2];

  // Load model
  std::unique_ptr<tflite::FlatBufferModel> model =
      tflite::FlatBufferModel::BuildFromFile(filename);
  TFLITE_MINIMAL_CHECK(model != nullptr);

  // Build the interpreter with the InterpreterBuilder.
  // Note: all Interpreters should be built with the InterpreterBuilder,
  // which allocates memory for the Interpreter and does various set up
  // tasks so that the Interpreter can read the provided model.
  tflite::ops::builtin::BuiltinOpResolver resolver;
  tflite::InterpreterBuilder builder(*model, resolver);
  std::unique_ptr<tflite::Interpreter> interpreter;
  builder(&interpreter);
  TFLITE_MINIMAL_CHECK(interpreter != nullptr);

  // Allocate tensor buffers.
  TFLITE_MINIMAL_CHECK(interpreter->AllocateTensors() == kTfLiteOk);
  // printf("=== Pre-invoke Interpreter State ===\n");
  // tflite::PrintInterpreterState(interpreter.get());

  // Fill input buffers
  float* inputTyped = interpreter->typed_input_tensor<float>(0);
  int index = atoi(indexInputToInfer);
  printf("index : %d\n", index);

  TfLiteTensor* input = interpreter->input_tensor(0);

  // Print size of input
  int inputDimSize = input->dims->size;
  printf("Input dimension size : %d\n", inputDimSize);
  for(int i=0; i < inputDimSize; i++)
  {
    printf("size input number %d : %d\n", i, input->dims->data[i]);
  }

  printf("First input value : %f\n", C_1_test[index][0][0]);
  // memcpy(input->data.f, C_1_test[index][0], (C_1_test_nInputs - 1) * C_1_test_dimension);
  for(int i=0; i<100;i++)
  {
    input->data.f[i] = C_1_test[index][i][0];
  }

  // Run inference
  TFLITE_MINIMAL_CHECK(interpreter->Invoke() == kTfLiteOk);
  // printf("\n\n=== Post-invoke Interpreter State ===\n");
  // tflite::PrintInterpreterState(interpreter.get());

  // Read output buffers
  float* outputTyped = interpreter->typed_output_tensor<float>(0);
  TfLiteTensor* output = interpreter->output_tensor(0);
  // Print result
  for(int i=0; i < output->dims->data[1]; i++)
  {
    printf("class %d, score : %f\n", i, output->data.f[i]);
  }

  return 0;
}
