#if !defined(EFFEKTE)
#define EFFEKTE

#include <Arduino.h>

enum Modus{
  einfarbig,
  breath,
  fade,
  welle_einfarbig,
  welle_fade,
  regenbogen,
};

// Support Funkionen
bool Sync();

// Farbeffekte
void Einfarbig(uint16_t hue, uint8_t helligkeit);
void Breath(uint16_t hue, uint8_t helligkeit, uint8_t warten);
void Fade(uint8_t helligkeit, uint32_t warten);
void WelleEinfarbig(uint16_t hue, uint8_t helligkeit, uint8_t warten);
void WelleFade(uint8_t helligkeit, uint8_t warten);
void Regenbogen(uint8_t helligkeit, uint8_t faktor, uint8_t warten);

#endif // EFFEKTE
