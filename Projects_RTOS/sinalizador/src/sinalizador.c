#include "system_tm4c1294.h" // CMSIS-Core
#include "driverleds.h" // device drivers
#include "cmsis_os2.h" // CMSIS-RTOS

osThreadId_t AcionaLED_id, Temporiza_id;

void AcionaLED(void *arg){
  uint8_t led = (uint32_t)arg;
  uint8_t state = 0;
  
  while(1){
    osThreadFlagsWait(0x0001, osFlagsWaitAny, osWaitForever);
    
    state ^= led;
    LEDWrite(led, state);
  } // while
} // AcionaLED

void Temporiza(void *arg){
  uint32_t delay = (uint32_t)arg;
  uint32_t tick;
  
  while(1){
    tick = osKernelGetTickCount();
    
    osThreadFlagsSet(AcionaLED_id, 0x0001);
    
    osDelayUntil(tick + delay);
  } // while
} // Temporiza

void main(void){
  SystemInit();
  LEDInit(LED1);

  osKernelInitialize();

  AcionaLED_id = osThreadNew(AcionaLED, (void* )LED1, NULL);
  Temporiza_id = osThreadNew(Temporiza, (void *)100, NULL);

  if(osKernelGetState() == osKernelReady)
    osKernelStart();

  while(1);
} // main
