#include "Arduino.h"
#include "Wire.h"
#include "RTClib.h"
#include "FastLED.h"
#include "Minuten_Stunden.h"

#define NUM_LEDS 95
#define DATA_PIN 6

const int buttonPin = 12;

int buttonState = 0;
int general_state = 1;

void setup()
{
  rtc.begin();

  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);

  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                     // wait for a second
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);

  Serial.begin(9600);

  pinMode(buttonPin, INPUT);

  if (!rtc.initialized() || rtc.lostPower())
  {
    Serial.println("RTC is NOT initialized, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  delay(500);
  FastLED.clear();
  FastLED.show();
  delay(500);
}

void loop()
{
  //digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  buttonState = digitalRead(buttonPin);

  DateTime now = rtc.now();

  if (general_state == 0)
  { // an!!
    if (buttonState == 1)
    {
      general_state = 1;
      delay(500);
    }
  }
  else if (general_state == 1)
  { // aus
    if (buttonState == 1)
    {
      general_state = 0;
      delay(250);
    }
  }

  Serial.println(general_state);

  if (general_state == 1)
  {
    stunde = now.hour() + 1;
  }
  else if (general_state == 0)
  {
    stunde = now.hour();
  }

  Serial.print(stunde); // stunde usw. ausgeben
  Serial.print(" ");
  Serial.print(now.minute());
  Serial.print(" ");
  Serial.print(now.second());
  Serial.println();

  if (stunde < 22 && stunde > 6)
  {
    es();
    ist();
    minuten();
    stunden();
  }
  else
  {
    FastLED.clear();
    FastLED.show();
  }

  if (currentMinute != previousMinute)
  {
    // update the previous value
    previousMinute = currentMinute;
    Serial.println("Wechsel!!!");
    FastLED.clear();
    FastLED.show();
  }
  if (currentHour != previousHour)
  {
    // update the previous value
    previousHour = currentHour;
    Serial.println("Wechsel!!!");
    FastLED.clear();
    FastLED.show();
  }
  digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
}
