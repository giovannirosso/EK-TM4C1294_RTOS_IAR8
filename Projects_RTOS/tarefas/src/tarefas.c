//GIOVANNI DE ROSSO UNRUH

#include "system_tm4c1294.h" // CMSIS-Core
#include "driverleds.h"      // device drivers
#include "cmsis_os2.h"       // CMSIS-RTOS

osThreadId_t thread_led1_id, thread_led2_id, thread_led3_id, thread_led4_id;

typedef struct
{
  int periodo;
  uint8_t led_state;
} ledStruct;

void piscaLed(void *args)
{
  uint8_t on_off = 0;
  uint32_t tickCount;
  ledStruct *arg = (ledStruct *)args;
  while (1)
  {
    tickCount = osKernelGetTickCount();
    on_off ^= arg->led_state;
    LEDWrite(arg->led_state, on_off);
    osDelayUntil(tickCount + arg->periodo);
  }
}

void main(void)
{
  LEDInit(LED1 | LED2 | LED3 | LED4);

  osKernelInitialize();

  ledStruct led_1;
  led_1.periodo = 200; //ms
  led_1.led_state = LED1;

  ledStruct led_2;
  led_2.periodo = 300; //ms
  led_2.led_state = LED2;

  ledStruct led_3;
  led_3.periodo = 500; //ms
  led_3.led_state = LED3;

  ledStruct led_4;
  led_4.periodo = 700; //ms
  led_4.led_state = LED4;

  thread_led1_id = osThreadNew(piscaLed, &led_1, NULL);
  thread_led2_id = osThreadNew(piscaLed, &led_2, NULL);
  thread_led3_id = osThreadNew(piscaLed, &led_3, NULL);
  thread_led4_id = osThreadNew(piscaLed, &led_4, NULL);

  if (osKernelGetState() == osKernelReady)
    osKernelStart();

  while (1)
    ;
} // main
