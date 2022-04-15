#include <Arduino.h>
#include <GEIIutil.h>


void setup(){
	InitPort();
	InitLCD();				//ordre des inits important
	lcd.print("TP7");
	Serial.println("TP7");

	noInterrupts();      			// pas d�its pendant la phase d�init
	TCCR1A = 0;						// mode normal (timer avec d�bordement)
	TCCR1B = 1 << CS12; 			// 256 prescaler Tclk = 32us
	TIMSK1 = TIMSK1 | 1 << TOIE1;	// 
	interrupts();					// autorise toutes les its configur�es

}

//SANS FIN 

void loop() {

}

ISR(TIMER1_OVF_vect) {       	 // ISR = interrupt service routine
	TCNT1 = 3036;                // toutes les 1000ms
	PORTC = PORTC ^ (BIT1);  // OUEX: inverse b4 uniquement
}