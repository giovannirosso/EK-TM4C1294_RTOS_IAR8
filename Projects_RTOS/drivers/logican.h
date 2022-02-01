#ifndef __LOGICAN_H__
#define __LOGICAN_H__

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#define PIN0    0x01
#define PIN1    0x02
#define PIN2    0x04
#define PIN3    0x08
#define PIN4    0x10
#define PIN5    0x20
#define PIN6    0x40
#define PIN7    0x80

extern void sigInit(uint8_t);
extern void sigHi(uint8_t);
extern void sigLo(uint8_t);
extern void sigTg(uint8_t);

#endif // __LOGICAN_H__
