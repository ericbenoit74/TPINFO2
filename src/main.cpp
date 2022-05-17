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
	g_Conv8.Init();
}

//SANS FIN 

void loop() {
	int8_t l_int8_ValCan;
#ifdef DEBUG3
	uint32_t l_uint32_time = 0;
	l_uint32_time = micros();
#endif
	l_int8_ValCan = g_Conv8.Conv();
	
#ifdef DEBUG3
	l_uint32_time = micros() - l_uint32_time;
	Serial.println(l_uint32_time);
#endif
	Serial.print("CAN = ");
	Serial.println(l_int8_ValCan);
	delay(100);
}

