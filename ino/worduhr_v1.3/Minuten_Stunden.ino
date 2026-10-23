void minuten() { 
  DateTime now = rtc.now();
  minute = rtc.now.minute();

  switch(minute){
    case minute >= 5:
      fuenf();
      nach();
      //Serial.println("5 nach");
      currentMinute = "5 nach";
      break;
    case minute >= 10:
      zehn();
      nach();
      //Serial.println("10 nach");
      currentMinute = "10 nach";
      break;
    case minute >= 15:
      viertel();
      nach();
      //Serial.println("10 nach");
      currentMinute = "15 nach";
      break;
    case minute >= 20:
      zwanzig();
      nach();
      //Serial.println("20 nach");
      currentMinute = "20 nach";
      break;
    case minute >= 25:
      fuenf();
      vor();
      halb();
      //Serial.println("5 vor halb");
      currentMinute = "5 vor halb";
      break;
    case minute >= 30:
      halb();
      //Serial.println("halb");
      currentMinute = "halb";
      break;
    case minute >= 35:
      fuenf();
      nach();
      halb();
      //Serial.println("5 nach halb");
      currentMinute = "5 nach halb";
      break;
    case minute >= 40:
      zwanzig();
      vor();
      //Serial.println("20 vor");
      currentMinute = "20 vor";
      break;
    case minute >= 45:
      viertel();
      vor();
      //Serial.println("viertel vor");
      currentMinute = "15 vor";
      break;
    case minute >= 50:
      zehn();
      vor();
      //Serial.println("5 vor halb");
      currentMinute = "10 vor";
      break;
    case minute >= 55:
      fuenf();
      vor();
      //Serial.println("5 vor");
      currentMinute = "5 vor";
      break;
    default:
      Serial.println("uhr");
      uhr();
      currentMinute = "voll";
  }
  //delay(500);
}

void stunden() {
  DateTime now = rtc.now();

  if (now.minute() > 58 || now.minute() < 23) {
    if (stunde == 1) {
      FastLED.clear();
      FastLED.show();
      Serial.println("Eins");
      currentHour = "1";
    }else if (stunde == 7){
      sieben();
      Serial.println("sieben");
      currentHour = "7";
    }else if (stunde == 8){
      acht();
      Serial.println("acht");
      currentHour = "8";
    }else if (stunde == 9){
      neun();
      Serial.println("neun");
      currentHour = "9";
    }else if (stunde == 10){
      zehn_uhr();
      Serial.println("zehn");
      currentHour = "10";
    }else if (stunde == 11){
      elf();
      Serial.println("elf");
      currentHour = "11";
    }else if (stunde == 12){
      zwoelf();
      Serial.println("zwölf");
      currentHour = "11";
    }else if (stunde == 13){
      if (now.minute() > 56 && now. minute() < 2) {
        ein_uhr();
        Serial.println("ein");
      }
      else {
          eins();
          Serial.println("Eins");
      }
      currentHour = "13";
    }else if (stunde == 14){
      zwei();
      Serial.println("zwei");
      currentHour = "14";

    }else if (stunde == 15){
      drei_uhr();
      Serial.println("drei");
      currentHour = "15";
    }else if (stunde == 16){
      vier();
      Serial.println("vier");
      currentHour = "16";
    }else if (stunde == 17){
      fuenf_uhr();
      Serial.println("fünf");
      currentHour = "17";
    }else if (stunde == 18){
      sechs();
      Serial.println("sechs");
      currentHour = "18";
    }else if (stunde == 19){
      sieben();
      Serial.println("sieben");
      currentHour = "19";
    }else if (stunde == 20){
      acht();
      Serial.println("acht");
      currentHour = "20";
    }else if (stunde == 21){
      neun();
      Serial.println("neun");
      currentHour = "21";
    }else if (stunde == 22){
      zehn_uhr();
      Serial.println("zehn");
      currentHour = "22";
    }else if (stunde == 23){
      FastLED.clear();
      FastLED.show();
      Serial.println("elf");
      currentHour = "23";
    }else if (stunde == 24){
      FastLED.clear();
      FastLED.show();
      Serial.println("zwölf");
      currentHour = "24";
    }
  }else if (now.minute() > 23 && now.minute() < 58) {
    if (stunde + 1 == 1) {
      FastLED.clear();
      FastLED.show();
      Serial.println("Eins");
      currentHour = "1";
    }else if (stunde + 1 == 2){
      FastLED.clear();
      FastLED.show();
      Serial.println("zwei");
      currentHour = "2";

    }else if (stunde + 1 == 3){
      FastLED.clear();
      FastLED.show();
      Serial.println("drei");
      currentHour = "3";
    }else if (stunde + 1 == 4){
      FastLED.clear();
      FastLED.show();
      Serial.println("vier");
      currentHour = "4";
    }else if (stunde + 1 == 5){
      FastLED.clear();
      FastLED.show();
      Serial.println("fünf");
      currentHour = "5";
    }else if (stunde + 1 == 6){
      FastLED.clear();
      FastLED.show();
      Serial.println("sechs");
      currentHour = "6";
    }else if (stunde + 1 == 7){
      sieben();
      Serial.println("sieben");
      currentHour = "7";
    }else if (stunde + 1 == 8){
      acht();
      Serial.println("acht");
      currentHour = "8";
    }else if (stunde + 1 == 9){
      neun();
      Serial.println("neun");
      currentHour = "9";
    }else if (stunde + 1 == 10){
      zehn_uhr();
      Serial.println("zehn");
      currentHour = "10";
    }else if (stunde + 1 == 11){
      elf();
      Serial.println("elf");
      currentHour = "11";
    }else if (stunde + 1 == 12){
      zwoelf();
      Serial.println("zwölf");
      currentHour = "12";
    }else if (stunde + 1 == 13){
      if (now.minute() > 56 && now. minute() < 2) {
        ein_uhr();
        Serial.println("ein");
        
      }
      else {
          eins();
          Serial.println("Eins");
      }
      currentHour = "13";
    }else if (stunde + 1 == 14){
      zwei();
      Serial.println("zwei");
      currentHour = "14";

    }else if (stunde + 1 == 15){
      drei_uhr();
      Serial.println("drei");
      currentHour = "15";
    }else if (stunde + 1 == 16){
      vier();
      Serial.println("vier");
      currentHour = "16";
    }else if (stunde + 1 == 17){
      fuenf_uhr();
      Serial.println("fünf");
      currentHour = "17";
    }else if (stunde + 1 == 18){
      sechs();
      Serial.println("sechs");
      currentHour = "18";
    }else if (stunde + 1 == 19){
      sieben();
      Serial.println("sieben");
      currentHour = "19";
    }else if (stunde + 1 == 20){
      acht();
      Serial.println("acht");
      currentHour = "20";
    }else if (stunde + 1 == 21){
      neun();
      Serial.println("neun");
      currentHour = "21";
    }else if (stunde + 1 == 22){
      zehn_uhr();
      Serial.println("zehn");
      currentHour = "22";
    }else if (stunde + 1 == 23){
      FastLED.clear();
      FastLED.show();
      Serial.println("elf");
      currentHour = "23";
    }else if (stunde + 1 == 24){
      FastLED.clear();
      FastLED.show();
      Serial.println("zwölf");
      currentHour = "24";
    }
  }
  
}
