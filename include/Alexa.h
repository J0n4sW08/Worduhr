#pragma once

#include <stdint.h>

typedef void (*AlexaCallback)(bool on, uint8_t brightness);

void alexaSetup(AlexaCallback callback);
void alexaLoop();
void alexaReportState(bool on, uint8_t brightness);
