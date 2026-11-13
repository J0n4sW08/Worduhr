#include "Arduino.h"
#include "Wire.h"
#include "FastLED.h"
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include "Alexa.h"
#include "Words.h"
#include "Clock.h"

#define DATA_PIN 4

enum DisplayMode : uint8_t
{
  MODE_AUTO,
  MODE_ON,
  MODE_OFF
};

int currentMinute;
int previousMinute;

int currentHour;
int previousHour;

int buttonState = 0;
int general_state = 1;

volatile DisplayMode displayMode = MODE_AUTO;
volatile uint8_t displayBrightness = 255;
static volatile bool alexaCommandPending = false;

static bool previousTimeWindow;
static bool previousVisible;
static bool visibleStateKnown = false;
static CRGB alexaStatusColor = CRGB::Purple;
static uint32_t alexaStatusUntil = 0;

static void onAlexaState(bool on, uint8_t brightness)
{
  displayMode = on ? MODE_ON : MODE_OFF;
  if (on)
  {
    displayBrightness = brightness;
  }
  alexaCommandPending = true;
}

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

  const int hour = stunde();
  previousTimeWindow = hour >= 7 && hour < 22;
  alexaSetup(onAlexaState);
  alexaStatusUntil = millis() + 1500;
  Serial.println("Alexa-Dienst bereit; warte auf Befehle");
}

void loop()
{
  ArduinoOTA.handle();
  alexaLoop();

  if (alexaCommandPending)
  {
    alexaCommandPending = false;
    alexaStatusColor = CRGB::Green;
    alexaStatusUntil = millis() + 1200;
    Serial.println("Alexa-Befehl empfangen");
  }

  const int hour = stunde();
  const bool inTimeWindow = hour >= 7 && hour < 22;
  if (inTimeWindow != previousTimeWindow)
  {
    displayMode = MODE_AUTO;
    previousTimeWindow = inTimeWindow;
  }

  const DisplayMode mode = displayMode;
  const bool visible = mode == MODE_ON || (mode == MODE_AUTO && inTimeWindow);
  const uint8_t brightness = displayBrightness;

  const bool alexaStatusActive = alexaStatusUntil != 0 &&
                                 static_cast<int32_t>(alexaStatusUntil - millis()) > 0;
  FastLED.setBrightness(alexaStatusActive ? 64 : brightness);
  FastLED.clear();
  if (alexaStatusActive)
  {
    fill_solid(leds, NUM_LEDS, alexaStatusColor);
  }
  else if (visible)
  {
    es();
    ist();
    minuten();
    stunden();
  }
  FastLED.show();

  if (!visibleStateKnown || visible != previousVisible)
  {
    alexaReportState(visible, brightness);
    previousVisible = visible;
    visibleStateKnown = true;
  }
}
