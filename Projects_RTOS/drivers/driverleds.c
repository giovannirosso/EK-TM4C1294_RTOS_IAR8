#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverleds.h"

void LEDInit(uint8_t leds){
  if(leds & (LED1 | LED2)){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION); // Habilita GPIO N (LED D1 = PN1, LED D2 = PN0)
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION)); // Aguarda final da habilitação
  } // if
  if(leds & LED1){
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1); // LED D1 como saída
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
    GPIOPadConfigSet(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);
  } // if
  if(leds & LED2){
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0); // LED D2 como saída
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
    GPIOPadConfigSet(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);
  } // if
  if(leds & (LED3 | LED4)){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F (LED D3 = PF4, LED D4 = PF0)
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilitação
  } // if
  if(leds & LED3){    
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_4); // LED D3 como saída
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);
  } // if
  if(leds & LED4){    
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0); // LED D4 como saída
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);
  } // if
} // LEDInit

void LEDOn(uint8_t leds){
  if(leds & LED1)
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
  if(leds & LED2)
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
  if(leds & LED3)
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
  if(leds & LED4)
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
} // LEDOn

void LEDOff(uint8_t leds){
  if(leds & LED1)
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
  if(leds & LED2)
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
  if(leds & LED3)
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
  if(leds & LED4)
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
} // LEDOff

void LEDToggle(uint8_t leds){
  if(leds & LED1)
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, ~GPIOPinRead(GPIO_PORTN_BASE, GPIO_PIN_1));
  if(leds & LED2)
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, ~GPIOPinRead(GPIO_PORTN_BASE, GPIO_PIN_0));
  if(leds & LED3)
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, ~GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4));
  if(leds & LED4)
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, ~GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0));
} // LEDToggle

void LEDWrite(uint8_t leds, uint8_t states){
  if(leds & LED1)
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, (states & LED1)?GPIO_PIN_1:0);
  if(leds & LED2)
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, (states & LED2)?GPIO_PIN_0:0);
  if(leds & LED3)
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, (states & LED3)?GPIO_PIN_4:0);
  if(leds & LED4)
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, (states & LED4)?GPIO_PIN_0:0);
} // LEDWrite
