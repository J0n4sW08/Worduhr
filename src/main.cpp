#include "Arduino.h"
#include "Wire.h"
#include "FastLED.h"
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include "Words.h"
#include "Clock.h"

#define DATA_PIN 4

int currentMinute;
int previousMinute;

int currentHour;
int previousHour;

int buttonState = 0;
int general_state = 1;

void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  connect();

  ArduinoOTA.setHostname("wortuhr");
  ArduinoOTA.begin();
  Serial.print("OTA bereit unter wortuhr.local (IP: ");
  Serial.print(WiFi.localIP());
  Serial.println(")");

  FastLED.setBrightness(255);

  Serial.println("run");
  knightRider(0, 255, 0, 3, 30, 50);

  delay(500);
  FastLED.clear();
  FastLED.show();
  delay(500);
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::White;
  }
  delay(500);
}

void loop()
{
  ArduinoOTA.handle();

  // TODO Add debugging Prints
  const int aktuelleStunde = stunde();
  Serial.print("Uhrzeit: ");
  Serial.print(stunde());
  Serial.print(":");
  Serial.println(minute());

  if (aktuelleStunde < 22 && aktuelleStunde > 6)
  {
    FastLED.clear();
    es();
    ist();
    minuten();
    stunden();
    FastLED.show();
  }
  else
  {
    FastLED.clear(true);
  }
}
