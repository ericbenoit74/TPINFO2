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
	bool l_bool_appui = false;
	PORTC = PORTC | BIT5;
	if ((PINC & BIT5) != BIT5) {
		delay(2);
		l_bool_appui = true;
    Serial.println("OK");
	}
	else
		Serial.println("KO");
}