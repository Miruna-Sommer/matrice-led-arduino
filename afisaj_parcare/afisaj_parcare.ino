#include <MD_Parola.h>        // Biblioteca pentru afișare text pe matrice LED
#include <MD_MAX72xx.h>       // Biblioteca pentru controlul hardware MAX7219
#include <SPI.h>              // Biblioteca pentru comunicare SPI

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW   // Tipul modulului LED folosit (FC-16)
#define MAX_DEVICES 4                       // Număr de module (4 matrice LED 8x8)
#define CS_PIN 3                            // Pinul CS (Chip Select) conectat la pinul digital 3 pe Arduino

MD_Parola afisaj = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES); // Inițializare obiect pentru controlul afișajului

void setup() {
  afisaj.begin();                     // Pornirea afișajului
  afisaj.setIntensity(3);             // Setează luminozitatea (valori între 0 și 15)
  afisaj.displayClear();              // Curăță ecranul
  afisaj.displayScroll("Locuri disponibile: 12", PA_CENTER, PA_SCROLL_LEFT, 40); // Afișează mesajul cu derulare spre stânga
}

void loop() {
  if (afisaj.displayAnimate()) {      // Verifică dacă animația s-a terminat
    afisaj.displayReset();            // Repornește animația pentru afișare continuă
  }
}
