#include <Arduino.h>

/************************
InitLiaisonSerie
Initialise la liason s�rie USART 0
9600 bits/s  - 1bit = 104us(err=0,2%)
8bits, pas de parit�, 1stop
param�tres : aucun
retourne rien
**************************/
void InitLiaisonSerie(void) {
	UBRR0L = 103;
	UBRR0H = 0;
	UCSR0A = 0;
	UCSR0B = 1 << RXEN0 | 1 << TXEN0;
	UCSR0C = 1 << UCSZ01 | 1 << UCSZ00;
}
/************************
EcritCar
envoie un caract�re sur l'USART0
param�tres : Char � envoyer sur la liaison s�rie
retourne rien
**************************/
void EcritCar(char cCar) {
	// attente registre vide pour transmettre
	do {
		//} while ((UCSR0A & BIT5) != BIT5); //vide si b5=UDRE0=0
	} while ((UCSR0A &( 1 << UDRE0)) != (1 << UDRE0)); //vide si b5=UDRE0=0
	UDR0 = cCar;
}
/************************
LitCar
attend la r�ception d'un caract�re sur l'USART0
param�tres : aucun
retourne le caract�re lu
**************************/
char LitCar(void) {
	// attente arriv�e d'un caract�re
	do {
		//} while ((UCSR0A & BIT7) != BIT7); //vide si b7=RXC0=0
	} while ((UCSR0A & (1 << RXC0)) != (1 << RXC0)); //vide si b7=RXC0=0
	return UDR0;
}
/************************
LitCarNB
v�rifie qu'un caract�re est arriv� sur l'USART0
param�tres : aucun
retourne le caract�re arriv� ou 0
**************************/
char LitCarNB(void) {
	char l_char_Car = 0;
	if ((UCSR0A & (1 << RXC0)) == (1 << RXC0)) {
		l_char_Car = UDR0;
	}
	return l_char_Car;
}