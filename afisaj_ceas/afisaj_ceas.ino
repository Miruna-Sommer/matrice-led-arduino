#include <MD_Parola.h>         // Afișare și efecte pe matrice LED
#include <MD_MAX72xx.h>        // Control hardware MAX7219
#include <SPI.h>               // Comunicare SPI

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

MD_Parola afisaj = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES); // Creăm obiectul afisaj

// Exemplu simplificat: ora și data sunt text fix (simulare).
// Codul poate fi extins cu un modul RTC (Real Time Clock) pentru a afișa ora în timp real.

void setup() {
  afisaj.begin();                    // Inițializare afișaj
  afisaj.setIntensity(4);            // Luminozitate medie
  afisaj.displayClear();             // Curățare ecran
  // Afișăm ora și data (text fix, simulare)
  afisaj.displayScroll("Ora: 14:35 Data: 30.04.2025", PA_CENTER, PA_SCROLL_LEFT, 25);
}

void loop() {
  if (afisaj.displayAnimate()) {
    afisaj.displayReset();           // Repornește afișajul după fiecare ciclu
  }
}
