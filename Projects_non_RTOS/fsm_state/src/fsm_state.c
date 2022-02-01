#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "driverlib/systick.h"
#include "driverleds.h" // Projects/drivers

// MEF com apenas 2 estados e 1 evento temporal que alterna entre eles
// Seleção por estado

typedef enum {Desligado, Ligado} state_t;

volatile uint8_t Evento = 0;

void SysTick_Handler(void){
  Evento = 1;
} // SysTick_Handler

void main(void){
  static state_t Estado = Desligado; // estado inicial da MEF
  
  LEDInit(LED1);
  SysTickPeriodSet(12000000); // f = 1Hz para clock = 24MHz
  SysTickIntEnable();
  SysTickEnable();

  while(1){
    switch(Estado){
    case Desligado:
      LEDOff(LED1);
      if(Evento){
        Evento = 0;
        Estado = Ligado;
      } // if
      break;
    case Ligado:
      LEDOn(LED1);
      if(Evento){
        Evento = 0;
        Estado = Desligado;
      } // if
      break;
    } // switch
  } // while
} // main
