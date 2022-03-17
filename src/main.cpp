#include <Arduino.h>
#include <GEIIutil.h>
#include <Timer3.h>

CTimer3PE3 g_MonTimer;

void setup(){
	InitPort();
	Serial.begin(9600);		//pour visualisation sur Serial Monitor
	InitLCD();				//ordre des inits important
	lcd.print("TP3");
	Serial.println("TP3");
	g_MonTimer.InitTimer3PE3();

	// dans la fonction setup pour tester rapidement
	g_MonTimer.FreqTimer3PE3(g_MonTimer.dodeka[0]);
	g_MonTimer.DemTimer3PE3();
	delay(500);
	g_MonTimer.StopTimer3PE3();	
	delay(500);
	g_MonTimer.FreqTimer3PE3(g_MonTimer.dodeka[1]);
	g_MonTimer.DemTimer3PE3();
	delay(500);
	g_MonTimer.StopTimer3PE3();
}

//SANS FIN 

void loop() {
	

}

