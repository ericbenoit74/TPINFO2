#include <Arduino.h>
#include <GEIIutil.h>

// definitions pour le TP 1
/**
 * @brief Modifie une LED du kit
 * 
 * @param x_int8_numLed numéro de la LED à modifier (0 à 3)
 * @param x_bool_etat vrai: allumer, faux: etteindre
 */
void GereLedsPortC(int8_t x_int8_numLed, bool x_bool_etat);


void setup() {
  InitPort();
  Serial.begin(9600);
  InitLCD();
  lcd.print("INFO2 TP1");

}

void loop() {

}
