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
  // mise à 1 du bit 1
  PORTC = PORTC | BIT1;
	delay(200);
  //mise à 0 du bit 1
	PORTC = PORTC & ~BIT1;
	delay(200);
}