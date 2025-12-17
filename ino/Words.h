#include "Arduino.h"
#include "Wire.h"
#include "RTClib.h"
#include "FastLED.h"

#define NUM_LEDS 120
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void es() {
  leds[0] = CRGB(255, 255, 255);
  FastLED.show();
  leds[1] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}

void ist() {
  leds[3] = CRGB(255, 255, 255);
  FastLED.show();
  leds[4] = CRGB(255, 255, 255);
  FastLED.show();
  leds[5] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}

void fuenf() {
  leds[6] = CRGB(255, 255, 255);
  FastLED.show();
  leds[7] = CRGB(255, 255, 255);
  FastLED.show();
  leds[8] = CRGB(255, 255, 255);
  FastLED.show();
  leds[9] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}

void zehn() {
  leds[10] = CRGB(255, 255, 255);
  FastLED.show();
  leds[11] = CRGB(255, 255, 255);
  FastLED.show();
  leds[12] = CRGB(255, 255, 255);
  FastLED.show();
  leds[13] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}
                                        
void zwanzig() {                                        
  leds[14] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[15] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[16] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[17] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[18] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[19] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[20] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  return;                                       
}                                       
                                        
void drei() {                                       
  leds[21] = CRGB(255, 255, 255);
  FastLED.show();
  leds[22] = CRGB(255, 255, 255);
  FastLED.show();
  leds[23] = CRGB(255, 255, 255);
  FastLED.show();
  leds[24] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
                                        
void viertel() {                                        
  leds[25] = CRGB(255, 255, 255);
  FastLED.show();
  leds[26] = CRGB(255, 255, 255);
  FastLED.show();
  leds[27] = CRGB(255, 255, 255);
  FastLED.show();
  leds[28] = CRGB(255, 255, 255);
  FastLED.show();
  leds[29] = CRGB(255, 255, 255);
  FastLED.show();
  leds[30] = CRGB(255, 255, 255);
  FastLED.show();
  leds[31] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
                                        
void vor() {                                        
  leds[32] = CRGB(255, 255, 255);
  FastLED.show();
  leds[33] = CRGB(255, 255, 255);
  FastLED.show();
  leds[34] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
                                        
void nach() {                                       
  leds[35] = CRGB(255, 255, 255);
  FastLED.show();
  leds[36] = CRGB(255, 255, 255);
  FastLED.show();
  leds[37] = CRGB(255, 255, 255);
  FastLED.show();
  leds[38] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
                                        
void halb() {                                       
  leds[39] = CRGB(255, 255, 255);
  FastLED.show();
  leds[40] = CRGB(255, 255, 255);
  FastLED.show();
  leds[41] = CRGB(255, 255, 255);
  FastLED.show();
  leds[42] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
void elf() {                                        
  leds[43] = CRGB(255, 255, 255);
  FastLED.show();
  leds[44] = CRGB(255, 255, 255);
  FastLED.show();
  leds[45] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
void fuenf_uhr() {                                        
  leds[45] = CRGB(255, 255, 255);
  FastLED.show();
  leds[46] = CRGB(255, 255, 255);
  FastLED.show();
  leds[47] = CRGB(255, 255, 255);
  FastLED.show();
  leds[48] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
void eins() {                                       
  leds[49] = CRGB(255, 255, 255);
  FastLED.show();
  leds[50] = CRGB(255, 255, 255);
  FastLED.show();
  leds[51] = CRGB(255, 255, 255);
  FastLED.show();
  leds[52] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}     
void ein_uhr() {                                       
  leds[49] = CRGB(255, 255, 255);
  FastLED.show();
  leds[50] = CRGB(255, 255, 255);
  FastLED.show();
  leds[51] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                   
void zwei() {                                       
  leds[53] = CRGB(255, 255, 255);
  FastLED.show();
  leds[54] = CRGB(255, 255, 255);
  FastLED.show();
  leds[55] = CRGB(255, 255, 255);
  FastLED.show();
  leds[56] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
                                        
void drei_uhr() {                                       
  leds[57] = CRGB(255, 255, 255);
  FastLED.show();
  leds[58] = CRGB(255, 255, 255);
  FastLED.show();
  leds[59] = CRGB(255, 255, 255);
  FastLED.show();
  leds[60] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
void vier() {                                       
  leds[61] = CRGB(255, 255, 255);
  FastLED.show();
  leds[62] = CRGB(255, 255, 255);
  FastLED.show();
  leds[63] = CRGB(255, 255, 255);
  FastLED.show();
  leds[64] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
                                        
void sechs() {                                        
  leds[65] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[66] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[67] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[68] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[69] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  return;                                       
}                                       
void acht() {                                       

  leds[70] = CRGB(255, 255, 255);
  FastLED.show();
  leds[71] = CRGB(255, 255, 255);
  FastLED.show();
  leds[72] = CRGB(255, 255, 255);
  FastLED.show();
  leds[73] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
void sieben() {                                       
  leds[74] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[75] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[76] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[77] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[78] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  leds[79] = CRGB(255, 255, 255);                                       
  FastLED.show();                                       
  return;                                       
}                                       
void zwoelf() {                                       
  leds[80] = CRGB(255, 255, 255);
  FastLED.show();
  leds[81] = CRGB(255, 255, 255);
  FastLED.show();
  leds[82] = CRGB(255, 255, 255);
  FastLED.show();
  leds[83] = CRGB(255, 255, 255);
  FastLED.show();
  leds[84] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
void zehn_uhr() {                                       
  leds[85] = CRGB(255, 255, 255);
  FastLED.show();
  leds[86] = CRGB(255, 255, 255);
  FastLED.show();
  leds[87] = CRGB(255, 255, 255);
  FastLED.show();
  leds[88] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
void neun() {                                       
  leds[88] = CRGB(255, 255, 255);
  FastLED.show();
  leds[89] = CRGB(255, 255, 255);
  FastLED.show();
  leds[90] = CRGB(255, 255, 255);
  FastLED.show();
  leds[91] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       
                                        
void uhr() {                                        
  leds[92] = CRGB(255, 255, 255);
  FastLED.show();
  leds[93] = CRGB(255, 255, 255);
  FastLED.show();
  leds[94] = CRGB(255, 255, 255);
  FastLED.show();
  return;
}                                       