#include "system_tm4c1294.h" // CMSIS-Core
#include "driverleds.h"      // device drivers
#include "cmsis_os2.h"       // CMSIS-RTOS

osThreadId_t thread1_id, thread2_id;

void thread1(void *arg)
{
  uint8_t state = 0;

  while (1)
  {
    state ^= LED1;
    LEDWrite(LED1, state);
    osDelay(100);
  } // while
} // thread1

void thread2(void *arg)
{
  uint8_t state = 0;
  uint32_t tick;

  while (1)
  {
    tick = osKernelGetTickCount();

    state ^= LED2;
    LEDWrite(LED2, state);

    osDelayUntil(tick + 100);
  } // while
} // thread2

void main(void)
{
  LEDInit(LED2 | LED1);

  osKernelInitialize();

  thread1_id = osThreadNew(thread1, NULL, NULL);
  thread2_id = osThreadNew(thread2, NULL, NULL);

  if (osKernelGetState() == osKernelReady)
    osKernelStart();

  while (1)
    ;
} // main
