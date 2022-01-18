#include <Arduino.h>
#include <GEIIutil.h>

void InitTP1();
void LoopTP1();

void setup() {
  InitPort();
  Serial.begin(9600);
  InitLCD();
  lcd.print("INFO2 TP1");
  InitTP1();
}

void loop() {
  LoopTP1();
}

void InitTP1(){

}

void LoopTP1(){

}