#pragma once

#include <FastLED.h>
#include <RTClib.h>

#define NUM_LEDS 95

extern CRGB leds[NUM_LEDS];
extern RTC_PCF8523 rtc;
extern int currentMinute;
extern int previousMinute;
extern int currentHour;
extern int previousHour;
extern int stunde;

void es();
void ist();
void fuenf();
void zehn();
void zwanzig();
void drei();
void viertel();
void vor();
void nach();
void halb();
void elf();
void fuenf_uhr();
void eins();
void ein_uhr();
void zwei();
void drei_uhr();
void vier();
void sechs();
void acht();
void sieben();
void zwoelf();
void zehn_uhr();
void neun();
void uhr();
