#include "logican.h"

void sigInit(uint8_t pins){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK); // Habilita GPIO K (boosterpack 2)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOK)); // Aguarda final da habilitação
  
//  GPIOPadConfigSet(GPIO_PORTK_BASE, pins, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);
  GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, pins); // terminais como saída
  GPIOPinWrite(GPIO_PORTK_BASE, pins, 0); // estado inicial zero (low)
} // sigInit

void sigHi(uint8_t pin){
  GPIOPinWrite(GPIO_PORTK_BASE, pin, pin);
} // sigHi

void sigLo(uint8_t pin){
  GPIOPinWrite(GPIO_PORTK_BASE, pin, 0);
} // sigLo

void sigTg(uint8_t pin){
  GPIOPinWrite(GPIO_PORTK_BASE, pin, ~GPIOPinRead(GPIO_PORTK_BASE, pin));
} // sigTg
