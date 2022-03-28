#include <Arduino.h>
#include <GEIIutil.h>
#include <MySerial.h>


void setup(){
	InitPort();
	InitLiaisonSerie();
	InitLCD();				//ordre des inits important
	lcd.print("TP4");
	Serial.println("TP4");
}

//SANS FIN 

void loop() {
	// EcritCar('A');
	// delay(2);

	char l_char_C = LitCarNB();
    if(l_char_C != 0){
		EcritCar(':');
		EcritCar(l_char_C);
	}
}

