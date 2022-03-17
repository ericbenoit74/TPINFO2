#include <Arduino.h>
#include <GEIIutil.h>
#include <GrapheEtat.h>

CGrapheEtat monGraphe;

void setup(){
	InitPort();
	Serial.begin(9600);		//pour visualisation sur Serial Monitor
	InitLCD();				//ordre des inits important
	lcd.print("TP4");
	Serial.println("TP4");
	monGraphe.Init();
}

//SANS FIN 

void loop() {
	monGraphe.Entrees();
	monGraphe.Evolue();
	monGraphe.Sorties();

}

