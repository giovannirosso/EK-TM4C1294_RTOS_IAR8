#ifndef __DRIVERLEDS_H__
#define __DRIVERLEDS_H__

#include <stdint.h>

#define LED1    1
#define LED2    2
#define LED3    4
#define LED4    8

extern void LEDInit(uint8_t);
extern void LEDOn(uint8_t);
extern void LEDOff(uint8_t);
extern void LEDToggle(uint8_t);
extern void LEDWrite(uint8_t, uint8_t);

#endif // __DRIVERLEDS_H__
