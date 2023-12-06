/**
  ******************************************************************************
  * @file    network_1701866511190.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Dec  6 13:47:00 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network_1701866511190.h"
#include "network_1701866511190_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network_1701866511190
 
#undef AI_NETWORK_1701866511190_MODEL_SIGNATURE
#define AI_NETWORK_1701866511190_MODEL_SIGNATURE     "9338d397e161973af17109e27ddbaf15"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Dec  6 13:47:00 2023"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_1701866511190_N_BATCHES
#define AI_NETWORK_1701866511190_N_BATCHES         (1)

static ai_ptr g_network_1701866511190_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_network_1701866511190_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  gemm_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)
/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  gemm_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1, AI_STATIC)
/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 99, AI_STATIC)
/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  gemm_3_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 128, AI_STATIC)
/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  gemm_4_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 128, AI_STATIC)
/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  gemm_5_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 128, AI_STATIC)
/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  gemm_7_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 99, AI_STATIC)
/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  gemm_8_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 128, AI_STATIC)
/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  gemm_9_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 128, AI_STATIC)
/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  gemm_10_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 128, AI_STATIC)
/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_args_00_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 99, AI_STATIC)
/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 99, AI_STATIC)
/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)
/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  gemm_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)
/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  gemm_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)
/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  gemm_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 99, AI_STATIC)
/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  nl_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 99, AI_STATIC)
/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  gemm_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)
/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  gemm_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)
/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  gemm_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)
/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  gemm_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1, AI_STATIC)
/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  nl_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1, AI_STATIC)
/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conversion_13_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)
/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12672, AI_STATIC)
/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  gemm_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)
/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  gemm_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  gemm_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)
/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  gemm_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12672, AI_STATIC)
/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  gemm_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 99, AI_STATIC)
/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  gemm_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12672, AI_STATIC)
/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  gemm_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)
/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  gemm_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)
/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  gemm_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)
/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_10_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007138022338040173f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002456009155139327f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_2_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007504951674491167f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_3_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012613669969141483f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_4_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021980056539177895f),
    AI_PACK_INTQ_ZP(7)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_5_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02101803570985794f),
    AI_PACK_INTQ_ZP(71)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_6_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_7_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008184771053493023f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_8_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008998564444482327f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_9_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008410121314227581f),
    AI_PACK_INTQ_ZP(14)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_10_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010713807307183743f),
    AI_PACK_INTQ_ZP(127)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_11_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_2_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010614943457767367f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_3_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009391256608068943f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_4_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009088726947084069f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_5_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00097756611648947f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_7_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008712088456377387f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_8_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008272083941847086f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_9_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007827207446098328f),
    AI_PACK_INTQ_ZP(0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  gemm_10_weights, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 1), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &gemm_10_weights_array, &gemm_10_weights_array_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  gemm_10_bias, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &gemm_10_bias_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_scratch0, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 99, 1, 1), AI_STRIDE_INIT(4, 2, 2, 198, 198),
  1, &gemm_2_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  gemm_3_scratch0, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 2, 2, 256, 256),
  1, &gemm_3_scratch0_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  gemm_4_scratch0, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 2, 2, 256, 256),
  1, &gemm_4_scratch0_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  gemm_5_scratch0, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 2, 2, 256, 256),
  1, &gemm_5_scratch0_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  gemm_7_scratch0, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 99, 1, 1), AI_STRIDE_INIT(4, 2, 2, 198, 198),
  1, &gemm_7_scratch0_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  gemm_8_scratch0, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 2, 2, 256, 256),
  1, &gemm_8_scratch0_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  gemm_9_scratch0, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 2, 2, 256, 256),
  1, &gemm_9_scratch0_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  gemm_10_scratch0, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 2, 2, 256, 256),
  1, &gemm_10_scratch0_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_args_00_output, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 99), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &serving_default_args_00_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 99), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &conversion_0_output_array, &conversion_0_output_array_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output0, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 99, 1, 1), AI_STRIDE_INIT(4, 1, 1, 99, 99),
  1, &conversion_0_output_array, &conversion_0_output_array_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &gemm_2_output_array, &gemm_2_output_array_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  gemm_3_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &gemm_3_output_array, &gemm_3_output_array_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  gemm_4_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &gemm_4_output_array, &gemm_4_output_array_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  gemm_5_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 99, 1, 1), AI_STRIDE_INIT(4, 1, 1, 99, 99),
  1, &gemm_5_output_array, &gemm_5_output_array_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  nl_6_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 99, 1, 1), AI_STRIDE_INIT(4, 1, 1, 99, 99),
  1, &nl_6_output_array, &nl_6_output_array_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  gemm_7_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &gemm_7_output_array, &gemm_7_output_array_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  gemm_8_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &gemm_8_output_array, &gemm_8_output_array_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  gemm_9_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &gemm_9_output_array, &gemm_9_output_array_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  gemm_10_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &gemm_10_output_array, &gemm_10_output_array_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  nl_11_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &nl_11_output_array, &nl_11_output_array_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conversion_13_output, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conversion_13_output_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_weights, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 99, 128, 1, 1), AI_STRIDE_INIT(4, 1, 99, 12672, 12672),
  1, &gemm_2_weights_array, &gemm_2_weights_array_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_bias, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &gemm_2_bias_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  gemm_3_weights, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 128, 128, 1, 1), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &gemm_3_weights_array, &gemm_3_weights_array_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  gemm_3_bias, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &gemm_3_bias_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  gemm_4_weights, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 128, 128, 1, 1), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &gemm_4_weights_array, &gemm_4_weights_array_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  gemm_5_weights, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 128, 99, 1, 1), AI_STRIDE_INIT(4, 1, 128, 12672, 12672),
  1, &gemm_5_weights_array, &gemm_5_weights_array_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  gemm_5_bias, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 99, 1, 1), AI_STRIDE_INIT(4, 4, 4, 396, 396),
  1, &gemm_5_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  gemm_7_weights, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 99, 128, 1, 1), AI_STRIDE_INIT(4, 1, 99, 12672, 12672),
  1, &gemm_7_weights_array, &gemm_7_weights_array_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  gemm_8_weights, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 128, 128, 1, 1), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &gemm_8_weights_array, &gemm_8_weights_array_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  gemm_8_bias, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &gemm_8_bias_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  gemm_9_weights, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 128, 128, 1, 1), AI_STRIDE_INIT(4, 1, 128, 16384, 16384),
  1, &gemm_9_weights_array, &gemm_9_weights_array_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_13_layer, 13,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conversion_13_chain,
  NULL, &conversion_13_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i8 nl_11_nl_params_data[] = { -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -109, -109, -109, -109, -109, -109, -108, -108, -108, -108, -108, -107, -107, -107, -107, -106, -106, -106, -106, -106, -105, -105, -105, -105, -105, -104, -104, -104, -104, -103, -103, -103, -103, -102, -102, -102, -102, -101, -101, -101, -101, -100, -100, -100, -100, -99, -99, -99, -98, -98, -98, -98, -97, -97, -97, -96, -96, -96, -96, -95, -95, -95, -94, -94, -94, -93, -93, -93, -92, -92, -92, -91, -91, -91, -90, -90, -90, -89, -89, -89, -88, -88, -87, -87, -87, -86, -86, -86, -85, -85, -84, -84, -84, -83, -83, -83, -82, -82, -81, -81, -80, -80, -80, -79, -79, -78, -78, -78, -77, -77, -76, -76, -75, -75, -74, -74, -73, -73, -73, -72, -72, -71, -71, -70, -70, -69, -69, -68, -68, -67, -67, -66, -66, -65, -65, -64, -64, -63, -63, -62, -62, -61, -61, -60, -60, -59, -58, -58, -57, -57, -56, -56, -55, -55, -54, -53, -53, -52, -52, -51, -51, -50, -49, -49, -48, -48, -47, -46, -46, -45, -45, -44, -43, -43, -42, -42, -41, -40, -40, -39, -39, -38, -37, -37, -36, -35, -35, -34, -33, -33, -32, -32, -31, -30, -30, -29, -28, -28, -27, -26, -26, -25, -24, -24, -23, -22, -22, -21, -20, -20, -19, -18, -18, -17, -16, -16, -15, -14, -14, -13, -12, -12, -11, -10, -10, -9, -8, -8, -7, -6, -5, -5, -4, -3, -3, -2, -1, -1, 0 };
AI_ARRAY_OBJ_DECLARE(
    nl_11_nl_params, AI_ARRAY_FORMAT_S8,
    nl_11_nl_params_data, nl_11_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_11_layer, 11,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_11_chain,
  NULL, &conversion_13_layer, AI_STATIC, 
  .nl_params = &nl_11_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_10_weights, &gemm_10_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_10_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_10_layer, 10,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_10_chain,
  NULL, &nl_11_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_9_weights, &gemm_2_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_9_layer, 9,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_9_chain,
  NULL, &gemm_10_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_8_weights, &gemm_8_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_8_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_8_layer, 8,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_8_chain,
  NULL, &gemm_9_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_7_weights, &gemm_2_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_7_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_7_layer, 7,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_7_chain,
  NULL, &gemm_8_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i8 nl_6_nl_params_data[] = { -124, -124, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -117, -117, -117, -117, -116, -116, -116, -116, -115, -115, -115, -115, -114, -114, -114, -114, -113, -113, -113, -112, -112, -112, -111, -111, -111, -110, -110, -110, -109, -109, -109, -108, -108, -107, -107, -107, -106, -106, -105, -105, -104, -104, -104, -103, -103, -102, -102, -101, -101, -100, -100, -99, -99, -98, -97, -97, -96, -96, -95, -94, -94, -93, -93, -92, -91, -91, -90, -89, -89, -88, -87, -86, -86, -85, -84, -83, -83, -82, -81, -80, -79, -79, -78, -77, -76, -75, -74, -73, -72, -71, -71, -70, -69, -68, -67, -66, -65, -64, -63, -62, -61, -60, -59, -57, -56, -55, -54, -53, -52, -51, -50, -49, -47, -46, -45, -44, -43, -41, -40, -39, -38, -37, -35, -34, -33, -32, -30, -29, -28, -27, -25, -24, -23, -21, -20, -19, -17, -16, -15, -13, -12, -11, -9, -8, -7, -5, -4, -3, -1, 0, 1, 3, 4, 5, 7, 8, 9, 11, 12, 13, 15, 16, 17, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 37, 38, 39, 40, 41, 43, 44, 45, 46, 47, 49, 50, 51, 52, 53, 54, 55, 56, 57, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68 };
AI_ARRAY_OBJ_DECLARE(
    nl_6_nl_params, AI_ARRAY_FORMAT_S8,
    nl_6_nl_params_data, nl_6_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_6_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_6_layer, 6,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_6_chain,
  NULL, &gemm_7_layer, AI_STATIC, 
  .nl_params = &nl_6_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_5_weights, &gemm_5_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_5_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_5_layer, 5,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_5_chain,
  NULL, &nl_6_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_4_weights, &gemm_2_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_4_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_4_layer, 4,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_4_chain,
  NULL, &gemm_5_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_3_weights, &gemm_3_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_3_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_3_layer, 3,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_3_chain,
  NULL, &gemm_4_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_2_weights, &gemm_2_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_2_layer, 2,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_2_chain,
  NULL, &gemm_3_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_args_00_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &conversion_0_chain,
  NULL, &gemm_2_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 105616, 1, 1),
    105616, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
    512, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_1701866511190_IN_NUM, &serving_default_args_00_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_1701866511190_OUT_NUM, &conversion_13_output),
  &conversion_0_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 105616, 1, 1),
      105616, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 512, 1, 1),
      512, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_1701866511190_IN_NUM, &serving_default_args_00_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_1701866511190_OUT_NUM, &conversion_13_output),
  &conversion_0_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_1701866511190_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_1701866511190_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_args_00_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 116);
    serving_default_args_00_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 116);
    
    conversion_0_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 16);
    conversion_0_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 16);
    
    gemm_2_scratch0_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 116);
    gemm_2_scratch0_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 116);
    
    gemm_2_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 384);
    gemm_2_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 384);
    
    gemm_3_scratch0_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 128);
    gemm_3_scratch0_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 128);
    
    gemm_3_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    gemm_3_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    
    gemm_4_scratch0_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 128);
    gemm_4_scratch0_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 128);
    
    gemm_4_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 384);
    gemm_4_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 384);
    
    gemm_5_scratch0_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    gemm_5_scratch0_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    
    gemm_5_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 256);
    gemm_5_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 256);
    
    nl_6_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    nl_6_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    
    gemm_7_scratch0_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 100);
    gemm_7_scratch0_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 100);
    
    gemm_7_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 384);
    gemm_7_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 384);
    
    gemm_8_scratch0_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    gemm_8_scratch0_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    
    gemm_8_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 256);
    gemm_8_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 256);
    
    gemm_9_scratch0_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    gemm_9_scratch0_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    
    gemm_9_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 384);
    gemm_9_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 384);
    
    gemm_10_scratch0_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    gemm_10_scratch0_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    
    gemm_10_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 256);
    gemm_10_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 256);
    
    nl_11_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    nl_11_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 0);
    
    conversion_13_output_array.data = AI_PTR(g_network_1701866511190_activations_map[0] + 4);
    conversion_13_output_array.data_start = AI_PTR(g_network_1701866511190_activations_map[0] + 4);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_1701866511190_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_1701866511190_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    gemm_10_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_10_weights_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 0);
    gemm_10_weights_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 0);
    
    gemm_10_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_10_bias_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 128);
    gemm_10_bias_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 128);
    
    gemm_2_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_2_weights_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 132);
    gemm_2_weights_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 132);
    
    gemm_2_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_2_bias_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 12804);
    gemm_2_bias_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 12804);
    
    gemm_3_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_3_weights_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 13316);
    gemm_3_weights_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 13316);
    
    gemm_3_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_3_bias_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 29700);
    gemm_3_bias_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 29700);
    
    gemm_4_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_4_weights_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 30212);
    gemm_4_weights_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 30212);
    
    gemm_5_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_5_weights_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 46596);
    gemm_5_weights_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 46596);
    
    gemm_5_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_5_bias_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 59268);
    gemm_5_bias_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 59268);
    
    gemm_7_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_7_weights_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 59664);
    gemm_7_weights_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 59664);
    
    gemm_8_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_8_weights_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 72336);
    gemm_8_weights_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 72336);
    
    gemm_8_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_8_bias_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 88720);
    gemm_8_bias_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 88720);
    
    gemm_9_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_9_weights_array.data = AI_PTR(g_network_1701866511190_weights_map[0] + 89232);
    gemm_9_weights_array.data_start = AI_PTR(g_network_1701866511190_weights_map[0] + 89232);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/


AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_1701866511190_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_1701866511190_MODEL_NAME,
      .model_signature   = AI_NETWORK_1701866511190_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 104848,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_network_1701866511190_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_1701866511190_MODEL_NAME,
      .model_signature   = AI_NETWORK_1701866511190_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 104848,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_network_1701866511190_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_1701866511190_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_network_1701866511190_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_network_1701866511190_create(network, AI_NETWORK_1701866511190_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_network_1701866511190_data_params_get(&params) != true) {
        err = ai_network_1701866511190_get_error(*network);
        return err;
    }
#if defined(AI_NETWORK_1701866511190_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_NETWORK_1701866511190_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_network_1701866511190_init(*network, &params) != true) {
        err = ai_network_1701866511190_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_network_1701866511190_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_network_1701866511190_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_network_1701866511190_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_1701866511190_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= network_1701866511190_configure_weights(net_ctx, params);
  ok &= network_1701866511190_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_1701866511190_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_1701866511190_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_1701866511190_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

