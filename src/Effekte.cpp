#include <Adafruit_NeoPixel.h>
#include "Effekte.h"

extern Adafruit_NeoPixel strip;

void Einfarbig(uint16_t hue, uint8_t helligkeit) {
  uint32_t farbe = strip.ColorHSV(hue, 255, helligkeit);
  strip.fill(farbe);
  strip.show();
  if(Sync() == true){return;}
  delay(10);
}

void Breath(uint16_t hue, uint8_t helligkeit, uint8_t warten) {
  uint32_t farbe;
  for(int j = 0; j < helligkeit; j++){
    farbe = strip.ColorHSV(hue, 255, j);
    strip.fill(farbe);
    strip.show();
    if(Sync() == true){return;}
    delay(warten);
  }
  for(int j = helligkeit; j > 0; j--){
    farbe = strip.ColorHSV(hue, 255, j);
    strip.fill(farbe);
    strip.show();
    if(Sync() == true){return;}
    delay(warten);
  }
}

void Fade(uint8_t helligkeit, uint32_t warten) {
  uint32_t farbe;
  for(int m = 0; m < 6; m++){
    switch(m){
      case 0:
        for(int j = 0; j < helligkeit; j++){
          farbe = strip.ColorHSV(0, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }

        for(int j = helligkeit; j > 0; j--){
          farbe = strip.ColorHSV(0, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }
      return;

      case 1:
        for(int j = 0; j < helligkeit; j++){
          farbe = strip.ColorHSV(65536 / 6, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }

        for(int j = helligkeit; j > 0; j--){
          farbe = strip.ColorHSV(65536 / 6, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }
      return;

      case 2:
        for(int j = 0; j < helligkeit; j++){
          farbe = strip.ColorHSV(65536 / 3, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }

        for(int j = helligkeit; j > 0; j--){
          farbe = strip.ColorHSV(65536 / 3, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }
      return;

      case 3:
        for(int j = 0; j < helligkeit; j++){
          farbe = strip.ColorHSV(65536 / 2, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }
        for(int j = helligkeit; j > 0; j--){
          farbe = strip.ColorHSV(65536 / 2, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }
      return;

      case 4:
        for(int j = 0; j < helligkeit; j++){
          farbe = strip.ColorHSV((65536 * 2) / 3, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }

        for(int j = helligkeit; j > 0; j--){
          uint32_t farbe = strip.ColorHSV((65536 * 2) / 3, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }
      return;

      case 5:
        for(int j = 0; j < helligkeit; j++){
          farbe = strip.ColorHSV((65536 * 5) / 6, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }

        for(int j = helligkeit; j > 0; j--){
          farbe = strip.ColorHSV((65536 * 5) / 6, 255, j);
          strip.fill(farbe);
          strip.show();
          if(Sync() == true){return;}
        }
      return;
    }
  }
}

void WelleEinfarbig(uint16_t hue, uint8_t helligkeit, uint8_t warten) {
  uint32_t farbe = strip.ColorHSV(hue, 255, helligkeit);
  for(int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, farbe);
    strip.show();
    if(Sync() == true){return;}
    delay(warten);
  }

  for(int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
    if(Sync() == true){return;}
    delay(warten);
  }
}

void WelleFade(uint8_t helligkeit, uint8_t warten) {
  uint32_t farbe;
  for(int m = 0; m < 6; m++){
    switch(m){
      case 0:
        farbe = strip.ColorHSV(0, 255, helligkeit);
        for(int i = 0; i < strip.numPixels(); i++){
          strip.setPixelColor(i, farbe);
          strip.show();
          if(Sync() == true){return;}
          delay(warten);
        }
      return;

      case 1:
        farbe = strip.ColorHSV(65536 / 6, 255, helligkeit);
        for(int i = 0; i < strip.numPixels(); i++){
          strip.setPixelColor(i, farbe);
          strip.show();
          if(Sync() == true){return;}
          delay(warten);
        }
      return;

      case 2:
        farbe = strip.ColorHSV(65536 / 3, 255, helligkeit);
        for(int i = 0; i < strip.numPixels(); i++){
          strip.setPixelColor(i, farbe);
          strip.show();
          if(Sync() == true){return;}
          delay(warten);
        }
      return;

      case 3:
        farbe = strip.ColorHSV(65536 / 2, 255, helligkeit);
        for(int i = 0; i < strip.numPixels(); i++){
          strip.setPixelColor(i, farbe);
          strip.show();
          if(Sync() == true){return;}
          delay(warten);
        }
      return;

      case 4:
        farbe = strip.ColorHSV((65536 * 2) / 3, 255, helligkeit);
        for(int i = 0; i < strip.numPixels(); i++){
          strip.setPixelColor(i, farbe);
          strip.show();
          if(Sync() == true){return;}
          delay(warten);
        }
      return;

      case 5:
        farbe = strip.ColorHSV((65536 * 5) / 6, 255, helligkeit);
        for(int i = 0; i < strip.numPixels(); i++){
          strip.setPixelColor(i, farbe);
          strip.show();
          if(Sync() == true){return;}
          delay(warten);
        }
      return;
    }
  }
}

void Regenbogen(uint8_t helligkeit, uint8_t faktor, uint8_t warten) {
  uint32_t farbe;
  for(int j = 0; j < strip.numPixels(); j++){
    for(int i = 0; i < strip.numPixels(); i++){
      farbe = strip.ColorHSV(((65536 / strip.numPixels()) * i * faktor) + j, 255, helligkeit);
      strip.setPixelColor(i, farbe);
      strip.show();
      if(Sync() == true){return;}
      delay(warten);
    }
  }
}
