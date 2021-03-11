#include <Arduino.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
#include <Adafruit_NeoPixel.h>
#include "Effekte.h"
#include "Secret.h"   // Ich will meine WLAN Zugangsdaten nicht veröffentlichen


// Netzwerkdaten damit sich Blynk über WLAN verbinden kann ========================================
char auth[] = secret_auth_wand;     // Code für Wand Streifen
// char auth[] = secret_auth_lounge    // Code für Lounge Steifen
char ssid[] = secret_ssid;
char pass[] = secret_pass;


// Standartwerte ==================================================================================
// #define leds 237  // Lounge
// #define leds 239  // Wand
#define leds 20   // Debug
#define led_pin 2
#define startmodus fade
#define standartfarbe 21845
#define standarthelligkeit 50


// Initialisierung für globale Variablen und Objekte ==============================================
Adafruit_NeoPixel strip(leds, led_pin, NEO_GRB + NEO_KHZ800);
WidgetTerminal terminal(V3);
enum Modus modus = startmodus;
uint16_t farbe = standartfarbe;
int helligkeit = standarthelligkeit;
bool reset = false;


// ================================================================================================
void setup() {
  // Initialisierung der LED-Streifen und von Blynk
  strip.begin();
  strip.show();
  Blynk.begin(auth, ssid, pass);
  while(Blynk.connected() == false);
  terminal.clear();
  terminal.println("Initialisiert!");
  terminal.flush();
}


void loop() {
  // Selektor für den Effekt, der angezeigt werden soll
  switch (modus){
    case einfarbig:
      Einfarbig(farbe, helligkeit);
    break;
    
    case breath:
      Breath(farbe, helligkeit, 10);
    break;
    
    case fade:
      Fade(helligkeit, 10);
    break;

    case welle_einfarbig:
      WelleEinfarbig(farbe, helligkeit, 10);
    break;

    case welle_fade:
      WelleFade(helligkeit, 10);
    break;
    
    case regenbogen:
      Regenbogen(helligkeit, 5, 10);
    break;
  }
}


// Syncronisiert mit dem Blynk server und stoppt Effekt falls nötig ===============================
bool Sync() {
  Blynk.run();
  if(reset == true){
    reset = false;
    return true;
  } else{
    reset = false;
    return false;
  }
}


// Empfängt, welcher Effekt ausgewählt werden soll (Virtual Pin 0) ================================
BLYNK_WRITE(V0) {
  int index = param.asInt();
  if(index == 1) modus = einfarbig;
  else if(index == 2) modus = breath;
  else if(index == 3) modus = fade;
  else if(index == 4) modus = welle_einfarbig;
  else if(index == 5) modus = welle_fade;
  else if(index == 6) modus = regenbogen;
  terminal.println("Effekt geändert!");
  terminal.flush();
  reset = true;
}


// Ändert Helligkeit ==============================================================================
BLYNK_WRITE(V1) {
  helligkeit = param.asInt();
  terminal.println("Helligkeit geändert!");
  terminal.flush();
  reset = true;
}


// Ändert Farbe ===================================================================================
BLYNK_WRITE(V2) {
  double r = param[0].asInt() / 255.0;
  double g = param[1].asInt() / 255.0;
  double b = param[2].asInt() / 255.0;

  double Cmin;
  if(r < g && r < b) Cmin = r;
  else if(g < r && g < b) Cmin = g;
  else Cmin = b;

  double buffer;
  if(r > g && r > b) buffer = (g - b) / (r - Cmin);
  else if(g > r && g > b) buffer = 2.0 + (b - r) / (g - Cmin);
  else buffer = 4.0 + (r - g) / (b - Cmin);

  if(buffer < 0) buffer += 360;
  farbe = buffer * 60;
  terminal.println("Farbe geändert!");
  terminal.flush();

  reset = true;
}
