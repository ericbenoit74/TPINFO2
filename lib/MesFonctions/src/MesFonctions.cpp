#include "MesFonctions.h"

void GereLedsPortC(int8_t x_int8_numLed, bool x_bool_etat){
    // si allumage
    if(x_bool_etat == true){
        // mise à 1 du bit numero x_int8_numLed du PORTC
        PORTC = PORTC | (1 << x_int8_numLed);  
    }else{
        // mise à 0 du bit numero x_int8_numLed du PORTC
        PORTC = PORTC & ~(1 << x_int8_numLed);
    }
}

bool TestBP1(void) {
	bool l_bool_appui = false;
	PORTC = PORTC | BIT5;
	if ((PINC & BIT5) != BIT5) {
		delay(2);
		l_bool_appui = true;
	}
	return l_bool_appui;
}
