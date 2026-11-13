#include "Arduino.h"
#include "Wire.h"
#include "Clock.h"
#include <ESP8266WiFi.h>
#include <FastLED.h>
#include "Words.h"
#include <time.h>
#include "secrets.h"

static void showStatus(const CRGB &color, bool on)
{
    FastLED.setBrightness(32);
    fill_solid(leds, NUM_LEDS, on ? color : CRGB::Black);
    FastLED.show();
}

void connect()
{
    bool ledOn = true;
    showStatus(CRGB::Blue, ledOn);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        ledOn = !ledOn;
        showStatus(CRGB::Blue, ledOn);
        Serial.print(".");
    }
    FastLED.clear(true);
    Serial.println("Success!! ");
    Serial.print(WiFi.localIP());

    // NTP liefert UTC; TZ wandelt die Anzeige automatisch in Berliner
    // Sommer- bzw. Winterzeit um.
    configTime(0, 0, "pool.ntp.org", "time.nist.gov");
    setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
    tzset();

    Serial.print("Warte auf NTP-Zeit");
    ledOn = true;
    showStatus(CRGB::Yellow, ledOn);
    while (time(nullptr) < 100000) {
        delay(500);
        ledOn = !ledOn;
        showStatus(CRGB::Yellow, ledOn);
        Serial.print(".");
    }
    FastLED.clear(true);
    FastLED.setBrightness(255);
    Serial.println("\nNTP-Zeit synchronisiert");
}

int minute()
{
    time_t now = time(nullptr);
    struct tm localTime;
    localtime_r(&now, &localTime);
    return localTime.tm_min;
}

int stunde()
{
    time_t now = time(nullptr);
    struct tm localTime;
    localtime_r(&now, &localTime);
    return localTime.tm_hour;
}
