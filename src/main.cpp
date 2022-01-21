#include <Arduino.h>
#include <GEIIutil.h>

void setup() {
  InitPort();
  Serial.begin(9600);
  InitLCD();
  lcd.print("INFO2 TP1");

}

void loop() {

}
