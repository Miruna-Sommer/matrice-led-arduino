#include <MD_Parola.h>        // Pentru afișarea textului pe LED-uri
#include <MD_MAX72xx.h>       // Pentru controlul modulului MAX7219
#include <SPI.h>              // Biblioteca de comunicare SPI

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW // Tipul modulului FC-16
#define MAX_DEVICES 4       // Avem 4 matrice conectate
#define CS_PIN 3            // CS (Chip Select) pe pinul digital 3

MD_Parola afisaj = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES); // Inițializăm afișajul

void setup() {
  afisaj.begin();                     // Start afișaj
  afisaj.setIntensity(4);             // Setează luminozitatea la 4
  afisaj.displayClear();              // Șterge tot de pe afișaj
  // Textul indică linia 32 și direcția tramvaiului
  afisaj.displayScroll("Linia 32 - Piata Rahova -> Gara Progresu", PA_LEFT, PA_SCROLL_LEFT, 35);
}

void loop() {
  if (afisaj.displayAnimate()) {
    afisaj.displayReset();            // Repornește animația
  }
}
