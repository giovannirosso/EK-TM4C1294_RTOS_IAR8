#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "driverlib/systick.h"
#include "driverleds.h" // Projects/drivers
#include "driverbuttons.h" // Projects/drivers

// MEF com apenas 2 estados e 2 eventos
// Seleção por matriz estado-evento

#define N_ST    (4)
#define N_EV    (2)

typedef enum {LED1_Apaga, LED1_Acende, LED2_Apaga, LED2_Acende} state_t;
typedef enum {Nada, Tempo, Botao} event_t;

volatile event_t Evento = Nada;

void SysTick_Handler(void){
  ButtonIntDisable(USW1);
  Evento = Tempo;
} // SysTick_Handler

void GPIOJ_Handler(void){
  ButtonIntClear(USW1);
  Evento = Botao;
} // GPIOJ_Handler

state_t f_LED1_Apaga_Tempo(state_t curr){
  LEDOn(LED1);
  return LED1_Acende;
} // f_Des

state_t f_LED1_Acende_Tempo(state_t curr){
  LEDOff(LED1);
  return LED1_Apaga;
} // f_Lig

state_t f_LED1_Apaga_Botao(state_t curr){
  LEDOff(LED2);
  return LED2_Apaga;
} // f_Des

state_t f_LED1_Acende_Botao(state_t curr){
  LEDOn(LED2);
  return LED2_Acende;
} // f_Des

state_t f_LED2_Apaga_Tempo(state_t curr){
  LEDOn(LED2);
  return LED2_Acende;
} // f_Des

state_t f_LED2_Acende_Tempo(state_t curr){
  LEDOff(LED2);
  return LED2_Apaga;
} // f_Lig

state_t f_LED2_Apaga_Botao(state_t curr){
  LEDOff(LED1);
  return LED1_Apaga;
} // f_Des

state_t f_LED2_Acende_Botao(state_t curr){
  LEDOn(LED1);
  return LED1_Acende;
} // f_Des

state_t f_Null(state_t curr){
  return curr;
} // f_Des

void main(void){
  state_t (*matriz[N_EV][N_ST])(state_t) = {{f_LED1_Apaga_Tempo, f_LED1_Acende_Tempo,
                                             f_LED2_Apaga_Tempo, f_LED2_Acende_Tempo},
                                            {f_LED1_Apaga_Botao, f_LED1_Acende_Botao,
                                             f_LED2_Apaga_Botao, f_LED2_Acende_Botao}};
  static state_t Estado = LED1_Apaga; // estado inicial da MEF
  
  LEDInit(LED1|LED2);
  ButtonInit(USW1);
  ButtonIntEnable(USW1);
  SysTickPeriodSet(12000000); // f = 1Hz para clock = 24MHz
  SysTickIntEnable();
  SysTickEnable();

  while(1){
    if(Evento){
      Estado = (*matriz[Evento - 1][Estado])(Estado);
      Evento = Nada;
      ButtonIntEnable(USW1);
    } // if
  } // while
} // main
