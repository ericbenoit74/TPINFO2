#include <Arduino.h>
#include <GEIIutil.h>
#include <cna.h>
#define DEBUG3
CConvAN8 g_Conv8;

void setup(){
	InitPort();
	Serial.begin(9600);		//pour visualisation sur Serial Monitor
	InitLCD();				//ordre des inits important
	lcd.print("TP2");
	Serial.println("TP2");
	//InitCan8();
	//InitCan10();
	g_Conv8.Init();
}

//SANS FIN 

void loop() {
	byte byValCan;
	word wValCan;
#ifdef DEBUG3
	unsigned long ulTime = 0;
	ulTime = micros();
#endif
	//byValCan = ConvAN8();
	byValCan = g_Conv8.Conv();
	//wValCan = ConvAN10();
	//wValCan = Conv8.ConvAN8();
	
#ifdef DEBUG3
	ulTime = micros() - ulTime;
	Serial.println(ulTime);
#endif
	Serial.print("CAN = ");
	Serial.println(byValCan);
	//Serial.println(wValCan);
	delay(1000);
}

