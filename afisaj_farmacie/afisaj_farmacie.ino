#include <MD_Parola.h>      // Efecte animate text
#include <MD_MAX72xx.h>     // Control hardware MAX7219
#include <SPI.h>            // Comunicare SPI

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

MD_Parola afisaj = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES); // Inițializare afișaj

void setup() {
  afisaj.begin();                    // Pornește afișajul
  afisaj.setIntensity(5);            // Setează luminozitate mai puternică
  afisaj.displayClear();             // Șterge afișajul
  // Afișează mesajul că farmacia e deschisă non-stop
  afisaj.displayScroll("Farmacie deschisa NON-STOP", PA_CENTER, PA_SCROLL_LEFT, 30);
}

void loop() {
  if (afisaj.displayAnimate()) {
    afisaj.displayReset();           // Repetă afișarea
  }
}
