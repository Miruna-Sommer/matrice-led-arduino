#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

MD_Parola afisaj = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  afisaj.begin();                     // Inițializare
  afisaj.setIntensity(6);             // Luminozitate mare pentru exterior
  afisaj.displayClear();              // Curăță ecranul
  afisaj.displayScroll("ATENTIE: DRUM IN LUCRU!", PA_CENTER, PA_SCROLL_LEFT, 30); // Afișează avertisment
}

void loop() {
  if (afisaj.displayAnimate()) {
    afisaj.displayReset();            // Reia afișarea
  }
}
