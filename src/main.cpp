#include <Arduino.h>
#include <GEIIutil.h>


void setup(){
	InitPort();
	InitLCD();				//ordre des inits important
	lcd.print("TP7");
	Serial.println("TP7");

	noInterrupts();      			// pas d�its pendant la phase d�init
	TCCR1A = 0;						// mode normal (timer avec d�bordement)
	TCCR1B = 1 << CS12; 			// 256 prescaler 
	TIMSK1 = TIMSK1 | 1 << TOIE1;	// interruption overflow

	TCCR4A = 0;						// mode normal (timer avec d�bordement)
	TCCR4B = 1 << CS41; 			// 8 prescaler 
	TIMSK4 = TIMSK4 | 1 << TOIE4;	// interruption overflow
	interrupts();					// autorise toutes les its configur�es

	DDRL = 0x01;                    // ICP4 = PL0 configuré en sortie
}

//SANS FIN 

void loop() {

}

ISR(TIMER1_OVF_vect) {       	 // ISR = interrupt service routine
	TCNT1 = 3036;                // toutes les 1000ms
	PORTC = PORTC ^ (BIT1);  // OUEX: inverse b4 uniquement
}

ISR(TIMER4_OVF_vect) {       	 // ISR = interrupt service routine
	TCNT4 = 63536;                // toutes les 1 ms
	PORTL = PORTL ^ (BIT0);  // OUEX: inverse b4 uniquement
}