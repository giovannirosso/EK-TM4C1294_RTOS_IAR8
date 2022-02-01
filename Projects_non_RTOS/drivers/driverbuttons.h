#ifndef __DRIVERBUTTONS_H__
#define __DRIVERBUTTONS_H__

#include <stdint.h>

#define USW1    1
#define USW2    2

extern void ButtonInit(uint8_t);
extern uint8_t ButtonRead(uint8_t);
extern void ButtonIntEnable(uint8_t);
extern void ButtonIntDisable(uint8_t);
extern void ButtonIntClear(uint8_t);

#endif // __DRIVERBUTTONS_H__
