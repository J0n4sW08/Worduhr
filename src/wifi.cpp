#include "Arduino.h"
#include "Wire.h"
#include "Clock.h"
#include <ESP8266WiFi.h>
#include <time.h>
#include "secrets.h"

void connect()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Success!! ");
    Serial.print(WiFi.localIP());

    // NTP liefert UTC; TZ wandelt die Anzeige automatisch in Berliner
    // Sommer- bzw. Winterzeit um.
    configTime(0, 0, "pool.ntp.org", "time.nist.gov");
    setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
    tzset();

    Serial.print("Warte auf NTP-Zeit");
    while (time(nullptr) < 100000) {
        delay(500);
        Serial.print(".");
    }
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
