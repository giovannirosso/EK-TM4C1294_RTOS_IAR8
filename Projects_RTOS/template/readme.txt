Template files for embedded system projects using the Texas InstrumentsEK-TM4C1294XL evaluation kit.

CMSIS-Core files:
TM4C1294NCPDT.h
	__FPU_PRESENT
startup_TM4C1294.s
system_TM4C1294.h
system_TM4C1294.c (for projects not using the TivaWare library)
	__CONFIG_CLOCK
	__SYSTEM_CLOCK
system_TM4C1294_TW.c (for projects using the TivaWare library)
	__CONFIG_CLOCK
	__SYSTEM_CLOCK

Possible clock configurations using the main or the internal oscillator and the PLL:
#define __CONFIG_CLOCK	  (SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480)
#define __CONFIG_CLOCK	  (SYSCTL_OSC_INT | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480)
#define __SYSTEM_CLOCK    (120000000UL)
#define __SYSTEM_CLOCK    (60000000UL)
#define __SYSTEM_CLOCK    (48000000UL)
#define __SYSTEM_CLOCK    (30000000UL)
#define __SYSTEM_CLOCK    (24000000UL)
#define __SYSTEM_CLOCK    (15000000UL)
#define __SYSTEM_CLOCK    (12000000UL)
#define __SYSTEM_CLOCK    (9600000UL)
#define __SYSTEM_CLOCK    (7500000UL)
#define __CONFIG_CLOCK	  (SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_320)
#define __CONFIG_CLOCK	  (SYSCTL_OSC_INT | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_320)
#define __SYSTEM_CLOCK    (80000000UL)
#define __SYSTEM_CLOCK    (40000000UL)
#define __SYSTEM_CLOCK    (32000000UL)
#define __SYSTEM_CLOCK    (20000000UL)
#define __SYSTEM_CLOCK    (16000000UL)
#define __SYSTEM_CLOCK    (10000000UL)
#define __SYSTEM_CLOCK    (8000000UL)
#define __SYSTEM_CLOCK    (6400000UL)
#define __SYSTEM_CLOCK    (5000000UL)
#define __CONFIG_CLOCK    (SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_OSC)
#define __SYSTEM_CLOCK    (25000000UL)