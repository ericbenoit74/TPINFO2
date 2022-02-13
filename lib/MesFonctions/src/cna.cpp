#include <cna.h>

// méthode à montrer aux étudiants en avance
#define ADMUX_ADSC_ON 0x01
#define ADMUX_REF_AVCC 0x40
#define ADMUX_ADLAR_ON 0x20
#define ADCSRB_MUX5_ON 0x08
#define ADCSRA_ADEN 0x80
#define ADCSRA_ADPS_16 0x04

/**
 * @brief Initialisation de la conversion A/N 8 bits
 * Entrée A9 non différentielle
 * Vref = VCC, clck/16, 
 * ADATE = 0, ADIF = 0, ADIE = 0, ADLAR = 1
 */
void InitCan8(void) {
	// pour tous
	ADMUX = 0x61; // 01100001b: REF1:0=01, ADLAR=1, ADSC=1
	// pour étudiants en avance:
	// ADMUX = ADMUX_ADSC_ON | ADMUX_REF_AVCC | ADMUX_ADLAR_ON

	ADCSRB = 0x08; // 00001000b: MUX5 = 1
	// ADCSRB = ADCSRB_MUX5_ON

	ADCSRA = 0x84; // 10000100b: ADEN = 1, ADPS2:0 = 100b ;
	// ADCSRA = ADCSRA_ADEN | ADCSRA_ADPS_16
}

/**
 * @brief Initialisation de la conversion A/N 10 bits
 * Entrée A9 non différentielle
 * Vref = VCC, clck/16, 
 * ADATE = 0, ADIF = 0, ADIE = 0, ADLAR = 0
 */
void InitCan10(void) {
	ADMUX = 0x41; // 01100001b: REF1:0=01, ADLAR=0, ADSC=1
	// ADMUX = ADMUX_ADSC_ON | ADMUX_REF_AVCC

	ADCSRB = 0x08; // 00001000b: MUX5 = 1
	// ADCSRB = ADCSRB_MUX5_ON
	
	ADCSRA = 0x84; // 10000100b: ADEN = 1, ADPS2:0 = 100b ;
	// ADCSRA = ADCSRA_ADEN | ADCSRA_ADPS_16}
}

/**
 * @brief Conversion A/N sur 8 bits
 * entrée A9
 * doit être initilisé avec InitCan8()
 * 
 * @return uint8_t résultat de la conversion
 * @see InitCan8
 */
uint8_t ConvAN8(void) {
	uint8_t l_uint8_valConv = 0;
	bool l_bool_fin;
#ifdef DEBUG1
	unsigned long l_ulong_time = 0;
	l_ulong_time = micros();
#endif
	ADCSRA = ADCSRA | MSK_ADSC; 	//start CV
	do {
		l_bool_fin = (MSK_ADSC == (ADCSRA & MSK_ADSC));  //fin CV ?
#ifdef DEBUG2
		Serial.println(ADCSRA);
#endif
	} while (l_bool_fin != false);
#ifdef DEBUG1
	l_ulong_time = micros() - l_ulong_time;
	Serial.println(l_ulong_time);
#endif
	l_uint8_valConv = ADCH;		//poids forts uniquement
	return l_uint8_valConv;
}


uint16_t ConvAN10(void) {
	bool l_bool_fin;
	uint16_t l_uint16_val, l_uint16_valH, l_uint16_valL;

	ADCSRA = ADCSRA | MSK_ADSC; 	// start CV
	do {
		l_bool_fin = (MSK_ADSC == (ADCSRA & MSK_ADSC));  //fin Conversion ?
	} while (l_bool_fin != false);    //attente ici de 20us
								// lecture de la donn�e justification D
	l_uint16_valL = ADCL;  	//ATTENTION ADCL lu en premier !!!
	l_uint16_valH = ADCH;
	l_uint16_valH = l_uint16_valH << 8;
	l_uint16_val = l_uint16_valH + l_uint16_valL;
	return l_uint16_val;
}


void CConvAN8::Init(void) {
	ADMUX = ADMUX_ADLAR_ON | ADMUX_ADSC_ON | ADMUX_REF_AVCC;
	ADCSRB = ADCSRB_MUX5_ON;
	ADCSRA = ADCSRA_ADEN | ADCSRA_ADPS_16;
}

uint8_t CConvAN8::Conv(void) {
	uint8_t l_uint8_valConv = 0;
	bool l_bool_fin;

	ADCSRA = ADCSRA | MSK_ADSC; 	//start CV
	do {
		l_bool_fin = (MSK_ADSC == (ADCSRA & MSK_ADSC));  //fin CV ?
	} while (l_bool_fin != false);
	l_uint8_valConv = ADCH;		//poids forts uniquement
	return l_uint8_valConv;
}
