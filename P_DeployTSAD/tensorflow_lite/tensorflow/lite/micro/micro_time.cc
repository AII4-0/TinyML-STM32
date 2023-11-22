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
