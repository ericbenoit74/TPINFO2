#include <Arduino.h>
#include <GEIIutil.h>
#include <MesFonctions.h>

void setup() {
  InitPort();
  Serial.begin(9600);
  InitLCD();
  lcd.print("INFO2 TP1");

  // initialisation du PORTC
  PORTC = DDRCINIT;
  
}

void loop() {
	int l_int_numLed = 0;
	uint8_t l_uint8_Masque = 0;
  // pour chaque LED
	for (l_int_numLed = 0; l_int_numLed < 4; l_int_numLed++) {

    // Affichage sur le moniteur série
		Serial.println(l_int_numLed);

    // creation du masque
		l_uint8_Masque = 1 << l_int_numLed;

    // allumage
		PORTC = PORTC | l_uint8_Masque;

		delay(200);
    // extinction
		PORTC = PORTC & ~l_uint8_Masque;
		delay(200);
	}
}