#line 1 "c:\\Users\\memon\\OneDrive\\Projects\\dispenser_esp32Code\\dispenser_esp32Code\\globals.h"
#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#define LED_2 32