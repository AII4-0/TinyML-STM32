/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define RUN_INFERENCE	// Choose RUN_INFERENCE or BASELINE_MEMORY_FOOTPRINT or PROFILE_MEMORY_AND_LATENCY
#define GAN_QUANT		//Choose between LSTM_0_QUANT, LSTM_1_QUANT, GAN or GAN_QUANT

#if defined( RUN_INFERENCE ) || defined( PROFILE_MEMORY_AND_LATENCY )
	#include "tensorflow/lite/core/c/common.h"
	#include "tensorflow/lite/micro/micro_interpreter.h"
	#include "tensorflow/lite/micro/micro_log.h"
	#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
	#include "tensorflow/lite/micro/micro_profiler.h"
	#include "tensorflow/lite/micro/recording_micro_interpreter.h"
	#include "tensorflow/lite/micro/system_setup.h"
	#include "tensorflow/lite/schema/schema_generated.h"
	#include "tensorflow/lite/micro/micro_utils.h"
	#include "tensorflow/lite/micro/cortex_m_generic/debug_log_callback.h"

	#include "lstm_0_quant.h"
	#include "lstm_0.h"
	#include "lstm_1_quant.h"
	#include "lstm_1.h"
	#include "gan_0_quant.h"
	#include "gan_0.h"
//	#include "C_1_test.h"
	#include "C_1_test_400.h"
//	#include "C_2_test.h"
	#include "C_2_test_400.h"

#elif defined( BASELINE_MEMORY_FOOTPRINT )
	#include <stdio.h>

#endif
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#if defined( PROFILE_MEMORY_AND_LATENCY ) || defined( RUN_INFERENCE )
	#define TENSOR_ARENA_SIZE (4 * 1024)
	#define N_SAMPLE_PER_INPUT 100
#endif

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
#if defined( PROFILE_MEMORY_AND_LATENCY ) || defined( RUN_INFERENCE )
	uint8_t tensor_arena[TENSOR_ARENA_SIZE];
#endif

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
static void debug_log_printf(const char* s);

#ifdef RUN_INFERENCE
	static TfLiteStatus runInference(void);

#elif defined( PROFILE_MEMORY_AND_LATENCY )
	static TfLiteStatus profileMemoryAndLatency(void);

#elif defined ( BASELINE_MEMORY_FOOTPRINT )
	static void baseLineMemoryFootprint(void);

#else

#endif

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern "C" {

// Needed to use printf. If printf don't want be used, redefine the function "DebugLog" in file "tensorflow/lite/micro/debug_log.cc"
// This function is used by tensorflow to print some info.
	int __io_putchar(int ch)
	{
		HAL_UART_Transmit(&huart2, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
		return ch;
	}
}

static void debug_log_printf(const char* s)
{
	printf(s);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  printf("Test printf\r\n");

#if defined(RUN_INFERENCE) || defined(PROFILE_MEMORY_AND_LATENCY)
  // Register callback for printing debug log
  RegisterDebugLogCallback(debug_log_printf);
#endif

  // Run inference
#ifdef RUN_INFERENCE
    TfLiteStatus aStatus = runInference();

	if (aStatus != kTfLiteOk)
	{
	  MicroPrintf("run inference error");
	  return kTfLiteError;
	}

#elif defined ( BASELINE_MEMORY_FOOTPRINT )
    baseLineMemoryFootprint();

#elif defined( PROFILE_MEMORY_AND_LATENCY )
  	TfLiteStatus aStatus = profileMemoryAndLatency();

	if (aStatus != kTfLiteOk)
	{
	  MicroPrintf("Profile Memory and Latency error");
	  return kTfLiteError;
	}

#endif


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
#ifdef RUN_INFERENCE
	static TfLiteStatus runInference(void)
	{
		int inputDimSize = 0;
		int outputDimSize = 0;
		int nInference = 0;

		MicroPrintf("Test MicroPrintf");
		MicroPrintf("You are in inference mode\r\n\r\n");

		// Model
#if defined(LSTM_0_QUANT)
		const tflite::Model* model = tflite::GetModel(lstm_0_quant);
#elif defined(LSTM_1_QUANT)
		const tflite::Model* model = tflite::GetModel(lstm_1_quant);
#elif defined(GAN_QUANT)
		const tflite::Model* model = tflite::GetModel(gan_0_quant);
#elif defined(GAN)
		const tflite::Model* model = tflite::GetModel(gan_0);
#endif
		if (model->version() != TFLITE_SCHEMA_VERSION)
		{
		MicroPrintf(
			"Model provided is schema version %d not equal "
			"to supported version %d.\n",
			model->version(), TFLITE_SCHEMA_VERSION);
		return kTfLiteError;
		}

#if defined(LSTM_0_QUANT) || defined (LSTM_1_QUANT)
		// Resolver
		tflite::MicroMutableOpResolver<6> micro_op_resolver;

		// Add dense neural network layer operation
		micro_op_resolver.AddFullyConnected();
		micro_op_resolver.AddQuantize();
		micro_op_resolver.AddUnidirectionalSequenceLSTM();
		micro_op_resolver.AddStridedSlice();
		micro_op_resolver.AddReshape();
		micro_op_resolver.AddDequantize();
#elif defined(GAN_QUANT)
		// Resolver
		tflite::MicroMutableOpResolver<5> micro_op_resolver;

		// Add dense neural network layer operation
		micro_op_resolver.AddFullyConnected();
		micro_op_resolver.AddLogistic();
		micro_op_resolver.AddQuantize();
		micro_op_resolver.AddReshape();
		micro_op_resolver.AddDequantize();
#elif defined(GAN)
		// Resolver
		tflite::MicroMutableOpResolver<3> micro_op_resolver;

		// Add dense neural network layer operation
		micro_op_resolver.AddFullyConnected();
		micro_op_resolver.AddLogistic();
		micro_op_resolver.AddReshape();
#endif

		// Build an interpreter to run the model with.
		tflite::MicroInterpreter interpreter(model, micro_op_resolver, tensor_arena,
										   TENSOR_ARENA_SIZE);

		// Allocate memory from the tensor_arena for the model's tensors.
		TfLiteStatus allocate_status = interpreter.AllocateTensors();
		if (allocate_status != kTfLiteOk)
		{
		  MicroPrintf("Allocate error");
		  return kTfLiteError;
		}


		MicroPrintf("MicroSpeech model arena size = %u\n",
				  interpreter.arena_used_bytes());

		// Assign model input and output buffers (tensors) to pointers
		TfLiteTensor* model_input = interpreter.input(0);
		TfLiteTensor* model_output = interpreter.output(0);

		// Print size of input
		inputDimSize = model_input->dims->size;
		MicroPrintf("Input dimension size : %d", inputDimSize);
		for(int i=0; i < inputDimSize; i++)
		{
		  MicroPrintf("size input number %d : %d", i, model_input->dims->data[i]);
		}

		MicroPrintf("");

		// Print size of output
		outputDimSize = model_output->dims->size;
		MicroPrintf("Output dimension size : %d", outputDimSize);
		for(int i=0; i < outputDimSize; i++)
		{
		  MicroPrintf("size output number %d : %d", i, model_output->dims->data[i]);
		}
		MicroPrintf("\n");

		// Print type of data
		MicroPrintf("Input type: %d", model_input->type);
		MicroPrintf("Type \"1\" means \"kTfLiteFloat32\" \n");

		// Get number of elements in input tensor
		uint32_t num_elements = model_input->bytes / sizeof(float);
		MicroPrintf("Number of input elements: %lu\r\n", num_elements);


		//****************************************************
		// Perform inference
		//****************************************************

		nInference = C_1_test_nInputs;

		for(int iInference = 0; iInference < nInference ; iInference++)
		{
			// Copy test data into the input model
#if defined(LSTM_1_QUANT)
			  for(int i=0; i < (C_1_test_window_size - 1); i++)
			  {
				  for(int y=0; y < C_2_test_dimension; y++)
				  {
					  model_input->data.f[(i*C_2_test_dimension) + y] = C_2_test[iInference][i][y];
				  }
			  }
#else
			  for(int i=0; i < (C_1_test_window_size - 1); i++)
			  {
				  for(int y=0; y < C_1_test_dimension; y++)
				  {
					  model_input->data.f[(i*C_1_test_dimension) + y] = C_1_test[iInference][i][y];
				  }
			  }
#endif

		  uint32_t atimeStart = HAL_GetTick();

		  // Infer
		  TfLiteStatus invoke_status = interpreter.Invoke();
		  if (invoke_status != kTfLiteOk)
		  {
			  MicroPrintf("Invoke error");
			  return kTfLiteError;
		  }

		  uint32_t atimeStop = HAL_GetTick();

		  // Print result
		  MicroPrintf("Inference counter : %d", iInference);
		  for(int i=0; i < model_output->dims->data[1]; i++)
		  {
			  MicroPrintf("class %d, score : %f", i, model_output->data.f[i]);
		  }

		  MicroPrintf("");  // Print an empty new line
		  MicroPrintf("Time measured manually for inference : %d ms", atimeStop - atimeStart);

		  MicroPrintf("");  // Print an empty new line
		}

		return kTfLiteOk;
	}

#elif defined( PROFILE_MEMORY_AND_LATENCY )
	static TfLiteStatus profileMemoryAndLatency(void)
	{
		tflite::MicroProfiler profiler;
		constexpr int kNumResourceVariables = 24;

#if defined(LSTM_0_QUANT) || defined(LSTM_1_QUANT)
		// Resolver
		tflite::MicroMutableOpResolver<6> op_resolver;

		// Add dense neural network layer operation
		op_resolver.AddFullyConnected();
		op_resolver.AddQuantize();
		op_resolver.AddUnidirectionalSequenceLSTM();
		op_resolver.AddStridedSlice();
		op_resolver.AddReshape();
		op_resolver.AddDequantize();
#elif defined(GAN_QUANT)
		// Resolver
		tflite::MicroMutableOpResolver<5> op_resolver;

		// Add dense neural network layer operation
		op_resolver.AddFullyConnected();
		op_resolver.AddLogistic();
		op_resolver.AddQuantize();
		op_resolver.AddReshape();
		op_resolver.AddDequantize();
#elif defined(GAN)
		// Resolver
		tflite::MicroMutableOpResolver<3> op_resolver;

		// Add dense neural network layer operation
		op_resolver.AddFullyConnected();
		op_resolver.AddLogistic();
		op_resolver.AddReshape();
#endif

		// Model
#if defined(LSTM_0_QUANT)
		const tflite::Model* model = tflite::GetModel(lstm_0_quant);
#elif defined(LSTM_1_QUANT)
		const tflite::Model* model = tflite::GetModel(lstm_1_quant);
#elif defined(GAN_QUANT)
		const tflite::Model* model = tflite::GetModel(gan_0_quant);
#elif defined(GAN)
		const tflite::Model* model = tflite::GetModel(gan_0);
#endif
		if (model->version() != TFLITE_SCHEMA_VERSION)
		{
		MicroPrintf(
			"Model provided is schema version %d not equal "
			"to supported version %d.\n",
			model->version(), TFLITE_SCHEMA_VERSION);
		return kTfLiteError;
		}

		// Allocator
		tflite::RecordingMicroAllocator* allocator(
		      tflite::RecordingMicroAllocator::Create(tensor_arena, TENSOR_ARENA_SIZE));

		// Build an recording interpreter to run the model with.
		tflite::RecordingMicroInterpreter interpreter(
				model, op_resolver, allocator,
			  tflite::MicroResourceVariables::Create(allocator, kNumResourceVariables),
			  &profiler);


		// Allocate memory from the tensor_arena for the model's tensors.
		TfLiteStatus allocate_status = interpreter.AllocateTensors();
		if (allocate_status != kTfLiteOk)
		{
		  MicroPrintf("Allocate error");
		  return kTfLiteError;
		}


		// Check input size
		size_t inputSize = interpreter.inputs_size();
//		TFLITE_CHECK_EQ(inputSize, 1);

		// Assign model input and output buffers (tensors) to pointers
		TfLiteTensor* model_input = interpreter.input(0);
		TfLiteTensor* model_output = interpreter.output(0);

		//****************************************************
		// Perform inference
		//****************************************************

		  // Copy test data into the input model
#if defined(LSTM_1_QUANT)
		for(int i=0; i < (C_1_test_window_size - 1); i++)
		{
		  for(int y=0; y < C_2_test_dimension; y++)
		  {
			  model_input->data.f[(i*C_2_test_dimension) + y] = C_2_test[0][i][y];
		  }
		}
#else
		for(int i=0; i < (C_1_test_window_size - 1); i++)
		{
		  for(int y=0; y < C_1_test_dimension; y++)
		  {
			  model_input->data.f[(i*C_1_test_dimension) + y] = C_1_test[0][i][y];
		  }
		}
#endif

		uint32_t atimeStart = HAL_GetTick();

		// Infer
		TfLiteStatus invoke_status = interpreter.Invoke();
		if (invoke_status != kTfLiteOk)
		{
		  MicroPrintf("Invoke error");
		  return kTfLiteError;
		}

		uint32_t atimeStop = HAL_GetTick();

		MicroPrintf("");  // Print an empty new line

		MicroPrintf("Print result of the inference");  // Print an empty new line
		// Print result
		for(int i=0; i < model_output->dims->data[1]; i++)
		{
		  MicroPrintf("class %d, score : %f", i, model_output->data.f[i]);
		}

		MicroPrintf("");  // Print an empty new line
		profiler.LogTicksPerTagCsv();

		MicroPrintf("");  // Print an empty new line
		interpreter.GetMicroAllocator().PrintAllocations();

		MicroPrintf("");  // Print an empty new line
		profiler.Log();

		MicroPrintf("");  // Print an empty new line
		MicroPrintf("Time measured manually : %d ms", atimeStop - atimeStart);

		return kTfLiteOk;
	}

#elif defined( BASELINE_MEMORY_FOOTPRINT )
	static void baseLineMemoryFootprint(void)
	{
		// Nothing
	}

#endif

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
