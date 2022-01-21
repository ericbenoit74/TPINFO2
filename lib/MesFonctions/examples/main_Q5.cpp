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
  // pour chaque LED
	for (l_int_numLed = 0; l_int_numLed < 4; l_int_numLed++) {

    // Affichage sur le moniteur série
		Serial.println(l_int_numLed);

    // allumage
		GereLedsPortC(l_int_numLed,true);

		delay(200);
    // extinction
		GereLedsPortC(l_int_numLed,false);

		delay(200);
	}
}