#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "driverlib/systick.h"
#include "driverleds.h" // Projects/drivers

volatile uint8_t Evento = 0;

void SysTick_Handler(void)
{
  Evento = 1;
} // SysTick_Handler

void main(void)
{
  static int pos = 0; // estado inicial da MEF

  LEDInit(LED1);
  LEDInit(LED2);
  LEDInit(LED3);
  SysTickPeriodSet(12000000); // f = 1Hz para clock = 24MHz
  SysTickIntEnable();
  SysTickEnable();

  while (1)
  {
    if (pos > 7)
      pos = 0;
    if (Evento)
    {
      Evento = 0;
      switch (pos)  //000, 001, 011, 010, 110, 111, 101, 100
      {
      case 0:
        LEDOff(LED1);
        LEDOff(LED2);
        LEDOff(LED3);
        pos++;
        break;
      case 1:
        LEDOff(LED1);
        LEDOff(LED2);
        LEDOn(LED3);
        pos++;
        break;
      case 2:
        LEDOff(LED1);
        LEDOn(LED2);
        LEDOn(LED3);
        pos++;
        break;
      case 3:
        LEDOff(LED1);
        LEDOn(LED2);
        LEDOff(LED3);
        pos++;
        break;
      case 4:
        LEDOn(LED1);
        LEDOn(LED2);
        LEDOff(LED3);
        pos++;
        break;
      case 5:
        LEDOn(LED1);
        LEDOn(LED2);
        LEDOn(LED3);
        pos++;
        break;
      case 6:
        LEDOn(LED1);
        LEDOff(LED2);
        LEDOn(LED3);
        pos++;
        break;
      case 7:
        LEDOn(LED1);
        LEDOff(LED2);
        LEDOff(LED3);
        pos++;
        break;
      } // switch
    }   // if
  }     // while
} // main