// Includerea bibliotecilor Arduino necesare.
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Definirea tipului de hardware. 
// Deoarece am folosit un modul FC-16 pentru proiect, HARDWARE_TYPE este setat la FC16_HW.
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

// Definirea dimensiunii (a numărului de circuite integrate) și a pinilor de ieșire.
// Folosim 4 circuite integrate MAX7219, deci MAX_DEVICES este setat la 4.
// Pinul la care este conectat pinul CS al matricei este pinul 3 de pe Arduino.
#define MAX_DEVICES 4
#define CS_PIN 3

// Crearea unei noi instanțe (myDisplay) a clasei MD_Parola cu conexiune SPI hardware.
// Primul parametru este tipul de hardware, al doilea este pinul corespunzător pinului CS, iar al treilea este numărul de circuite integrate MAX7219 utilizate.
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
	// Inițializarea afișajului.
	myDisplay.begin();

	// Setarea intensității (luminozității) afișajului (0-15).
	myDisplay.setIntensity(4);

	// Golirea afișajului.
	myDisplay.displayClear();

  // Folosirea comenzii de derulare a textului, stabilind alinierea, direcția și viteza de deplasare. 
	myDisplay.displayScroll("Urmeaza statia TINERETULUI, cu peronul pe partea stanga                ", PA_CENTER, PA_SCROLL_LEFT, 40);
}

  // Rularea ciclică a programului și a comenzilor de mai sus, până la oprirea alimentării cu energie.
void loop() {
	if (myDisplay.displayAnimate()) { // Funcția derulează textul și returnează „true” (1) când se termină.
		myDisplay.displayReset(); // Când derularea s-a terminat (s-a intrat in if), funcția displayReset() resetează afișajul, rezultând o derulare continuă.
	}
}
