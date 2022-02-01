#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverbuttons.h"

void ButtonInit(uint8_t buttons){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ); // Habilita GPIO J (push-button SW1 = PJ0, push-button SW2 = PJ1)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ)); // Aguarda final da habilitação
  if(buttons & USW1){
    GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_0); // push-button SW1 como entrada
    GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU); // habilita pull-up
  } // if
  if(buttons & USW2){
    GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_1); // push-button SW2 como entrada
    GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU); // habilita pull-up
  } // if
} // ButtonInit

uint8_t ButtonRead(uint8_t buttons){
  uint8_t states = 0;
  if(buttons & USW1)
    states |= GPIOPinRead(GPIO_PORTJ_BASE, GPIO_PIN_0);
  if(buttons & USW2)
    states |= GPIOPinRead(GPIO_PORTJ_BASE, GPIO_PIN_1);
  return states;
} // ButtonRead

void ButtonIntEnable(uint8_t buttons){
  if(buttons & USW1){
    GPIOIntTypeSet(GPIO_PORTJ_BASE, GPIO_PIN_0, GPIO_FALLING_EDGE);
    GPIOIntEnable(GPIO_PORTJ_BASE, GPIO_INT_PIN_0);
  } // if
  if(buttons & USW2){
    GPIOIntTypeSet(GPIO_PORTJ_BASE, GPIO_PIN_1, GPIO_FALLING_EDGE);
    GPIOIntEnable(GPIO_PORTJ_BASE, GPIO_INT_PIN_1);
  } // if
  if(buttons & (USW1 | USW2))
    IntEnable(INT_GPIOJ);
} // ButtonIntEnable

void ButtonIntDisable(uint8_t buttons){
  if(buttons & USW1)
    GPIOIntDisable(GPIO_PORTJ_BASE, GPIO_INT_PIN_0);
  if(buttons & USW2)
    GPIOIntDisable(GPIO_PORTJ_BASE, GPIO_INT_PIN_1);
  if(buttons & (USW1 | USW2))
    IntDisable(INT_GPIOJ);
} // ButtonIntDisable

void ButtonIntClear(uint8_t buttons){
  if(buttons & USW1)
    GPIOIntClear(GPIO_PORTJ_BASE, GPIO_INT_PIN_0);
  if(buttons & USW2)
    GPIOIntClear(GPIO_PORTJ_BASE, GPIO_INT_PIN_1);
} // ButtonIntClear
