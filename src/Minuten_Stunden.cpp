#include <Arduino.h>
#include <FastLED.h>
#include "Words.h"
#include "Clock.h"

void minuten()
{
  const int slot = ((minute() + 2) / 5) % 12;

  static int previousPrintedSlot = -1;
  if (slot != previousPrintedSlot)
  {
    switch (slot)
    {
    case 0:  Serial.println("uhr");         break;
    case 1:  Serial.println("5 nach");      break;
    case 2:  Serial.println("10 nach");     break;
    case 3:  Serial.println("15 nach");     break;
    case 4:  Serial.println("20 nach");     break;
    case 5:  Serial.println("5 vor halb");  break;
    case 6:  Serial.println("halb");        break;
    case 7:  Serial.println("5 nach halb"); break;
    case 8:  Serial.println("20 vor");      break;
    case 9:  Serial.println("15 vor");      break;
    case 10: Serial.println("10 vor");      break;
    case 11: Serial.println("5 vor");       break;
    }
    previousPrintedSlot = slot;
  }

  switch (slot)
  {
  case 0:  uhr();                      break;
  case 1:  fuenf();   nach();           break;
  case 2:  zehn();    nach();           break;
  case 3:  viertel(); nach();           break;
  case 4:  zwanzig(); nach();           break;
  case 5:  fuenf();   vor(); halb();    break;
  case 6:  halb();                      break;
  case 7:  fuenf();   nach(); halb();   break;
  case 8:  zwanzig(); vor();            break;
  case 9:  viertel(); vor();            break;
  case 10: zehn();    vor();            break;
  case 11: fuenf();   vor();            break;
  }
  currentMinute = slot;
}

void stunden()
{
  int h = stunde();
  const int slot = ((minute() + 2) / 5) % 12;
  if (slot >= 5 || minute() >= 58)
  {
    h += 1;
  }

  int h12 = h % 12;
  if (h12 == 0)
  {
    h12 = 12;
  }

  switch (h12)
  {
  case 1:
    if (slot == 0) ein_uhr();
    else           eins();
    break;
  case 2:  zwei();      break;
  case 3:  drei_uhr();  break;
  case 4:  vier();      break;
  case 5:  fuenf_uhr(); break;
  case 6:  sechs();     break;
  case 7:  sieben();    break;
  case 8:  acht();      break;
  case 9:  neun();      break;
  case 10: zehn_uhr();  break;
  case 11: elf();       break;
  case 12: zwoelf();    break;
  }

  static int previousPrintedHour = -1;
  if (h12 != previousPrintedHour)
  {
    Serial.println(h12);
    previousPrintedHour = h12;
  }
  currentHour = h12;
}
