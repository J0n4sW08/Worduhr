#include "Alexa.h"

#include <fauxmoESP.h>

#define ALEXA_DEVICE_NAME "Wortuhr"

static fauxmoESP fauxmo;
static AlexaCallback alexaCallback = nullptr;

void alexaSetup(AlexaCallback callback)
{
    alexaCallback = callback;
    fauxmo.addDevice(ALEXA_DEVICE_NAME);
    fauxmo.setPort(80);
    fauxmo.enable(true);
    fauxmo.onSetState([](unsigned char, const char *, bool state, unsigned char value)
                      {
                          if (alexaCallback != nullptr)
                          {
                              alexaCallback(state, value);
                          }
                      });
}

void alexaLoop()
{
    fauxmo.handle();
}

void alexaReportState(bool on, uint8_t brightness)
{
    fauxmo.setState((unsigned char)0, on, brightness);
}
