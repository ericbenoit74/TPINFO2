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
  l_bool_appui = TestBP1();
  Serial.println(l_bool_appui);
}