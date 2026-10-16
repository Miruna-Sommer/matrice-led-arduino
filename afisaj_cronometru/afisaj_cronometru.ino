#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

MD_Parola afisaj = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

unsigned long ultimaActualizare = 0;   // Momentul ultimei schimbări de timp
int timpRamas = 10;                    // Durata totală a cronometrului (în secunde)

void setup() {
  afisaj.begin();                      // Inițializare afișaj
  afisaj.setIntensity(4);              // Luminozitate medie
  afisaj.displayClear();               // Șterge afișajul
}

void loop() {
  // Verifică dacă a trecut o secundă (fără delay(), programul nu se blochează)
  if (millis() - ultimaActualizare >= 1000 && timpRamas >= 0) {
    afisaj.displayClear();             // Curăță ecranul înainte de actualizare

    String mesaj = "Timp: " + String(timpRamas) + " sec";  // Creează mesajul dinamic
    afisaj.displayText(mesaj.c_str(), PA_CENTER, 30, 0, PA_PRINT, PA_NO_EFFECT); // Afișează textul

    afisaj.displayAnimate();           // Activează afișarea mesajului
    timpRamas--;                       // Scade o secundă
    ultimaActualizare = millis();      // Reține timpul actual
  }
}
