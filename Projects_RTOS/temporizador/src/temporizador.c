#include "system_tm4c1294.h" // CMSIS-Core
#include "driverleds.h" // device drivers
#include "cmsis_os2.h" // CMSIS-RTOS

uint8_t state = 0;
osTimerId_t timer1_id;
osThreadId_t app_main_id;

void callback(void *arg){
  state ^= LED1;
  LEDWrite(LED1, state);
} // callback

void app_main(void *arg){
  osTimerStart(timer1_id, 100);
  osDelay(osWaitForever);
} // app_main

void main(void){
  SystemInit();
  LEDInit(LED1);

  osKernelInitialize();

  app_main_id = osThreadNew(app_main, NULL, NULL);
  timer1_id = osTimerNew(callback, osTimerPeriodic, NULL, NULL);

  if(osKernelGetState() == osKernelReady)
    osKernelStart();

  while(1);
} // main
