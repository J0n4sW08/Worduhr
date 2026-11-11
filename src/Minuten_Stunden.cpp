#include <Arduino.h>
#include <FastLED.h>
#include "Words.h"
#include "Clock.h"

void minuten() { 
  int slot = ((minute() + 2) / 5) % 12;

  switch (slot) {
    case 0:  uhr();                         Serial.println("uhr");        break;
    case 1:  fuenf();   nach();             Serial.println("5 nach");     break;
    case 2:  zehn();    nach();             Serial.println("10 nach");    break;
    case 3:  viertel(); nach();             Serial.println("15 nach");    break;
    case 4:  zwanzig(); nach();             Serial.println("20 nach");    break;
    case 5:  fuenf();   vor();   halb();    Serial.println("5 vor halb"); break;
    case 6:  halb();                        Serial.println("halb");       break;
    case 7:  fuenf();   nach();  halb();    Serial.println("5 nach halb"); break;
    case 8:  zwanzig(); vor();              Serial.println("20 vor");     break;
    case 9:  viertel(); vor();              Serial.println("15 vor");     break;
    case 10: zehn();    vor();              Serial.println("10 vor");     break;
    case 11: fuenf();   vor();              Serial.println("5 vor");      break;
  }
  currentMinute = slot;
}

void stunden() {
  int h = stunde();
  int slot = ((minute() + 2) / 5) % 12;
  if (slot >= 5 || minute() >= 58) h += 1;

  int h12 = h % 12;
  if (h12 == 0) h12 = 12;

  switch (h12) {
    case 1:
      if (slot == 0) ein_uhr();   // "ein uhr"
      else           eins();      // "eins" (z. B. "halb eins")
      break;
    case 2:  zwei();       break;
    case 3:  drei_uhr();   break;
    case 4:  vier();       break;
    case 5:  fuenf_uhr();  break;
    case 6:  sechs();      break;
    case 7:  sieben();     break;
    case 8:  acht();       break;
    case 9:  neun();       break;
    case 10: zehn_uhr();   break;
    case 11: elf();        break;
    case 12: zwoelf();     break;
  }

  Serial.println(h12);
  currentHour = h12;
}
