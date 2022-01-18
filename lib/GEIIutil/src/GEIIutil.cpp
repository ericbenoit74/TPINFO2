/*-------------------------------------------*/
/* Cours d'Informatique Embarqu�e Info2      */
/* (c) JN Martin 01-2014                     */
/* fichier source Fonctions.cpp              */
/*-------------------------------------------*/
#include "GEIIutil.h"

/*-- Initialisation conforme � la carte ARDUINO-IUT --*/
// Cette fonction doit �tre appel�e en premier dans setup()
void InitPort(void){
  DDRA = INIT_A;
  DDRB = INIT_B;
  DDRC = INIT_C;
  DDRD = INIT_D;
  DDRE = INIT_E;
  DDRF = INIT_F;
  DDRG = INIT_G;
  DDRH = INIT_H;
  DDRJ = INIT_J;
  DDRK = INIT_K;
  DDRL = INIT_L;
}



/*-- test du bouton poussoir BP0 = PC4 = 33 --*/
// antirebond de 2 ms et retourne 1 si appui
// appui=0V pas d'appui=5V car Rpu connect�e
bool TestAppuiBP0(void){
  bool bAppui=false;
  PORTC = PORTC | BIT4;    //pull up connect�e sur PC4 avant lecture
  if ((PINC & BIT4) != BIT4) {
      delay(2);
    bAppui = true;
  }
  return bAppui;
}

/*****************************
TestBP1
test du bouton poussoir BP1 = PC5 avec antirebond de 2ms
BP1 <-> PC5
Param�tres : aucun
Retourne bool�en (true/false) si touche enfonc�e ou pas
*******************************/
bool TestAppuiBP1(void) {
	bool bAppui = false;
	PORTC = PORTC | BIT5;
	if ((PINC & BIT5) != BIT5) {
		delay(2);
		bAppui = true;
	}
	return bAppui;
}

/*-- test de l'interrupteur SW1 = PC7 --*/
// antirebond de 2 ms et retourne 1 si appui
// appui=0V pas d'appui=5V car Rpu connect�e
bool TestInterSW1(void){
	bool bAppui = false;
	PORTC = PORTC | BIT7;
	if ((PINC & BIT7) != BIT7) {
		delay(2);
		bAppui = true;
	}
	return bAppui;
}

/*-- test de l'interrupteur SW0 = PC6 --*/
// antirebond de 2 ms et retourne 1 si appui
// appui=0V pas d'appui=5V car Rpu connect�e
bool TestInterSW0(void){
	bool bAppui = false;
	PORTC = PORTC | BIT6;
	if ((PINC & BIT6) != BIT6) {
		delay(2);
		bAppui = true;
	}
	return bAppui;
}
/*----------------------------------------------*/
/* Cours d'Informatique Industrielle I2         */
/* (c) JN Martin 2012-2013                      */
/* Gestion de l'afficheur LCD Hitachi HD44780   */
/* Carte ARDUINO-IUT                            */
/* Fichier : AfficheurLCD.h                     */
/* Librairie Arduino <LiquidCrystal.h>          */
/*----------------------------------------------*/

//définition du nom et affectation des bornes de l'afficheur
LiquidCrystal lcd = LiquidCrystal(24, 25, 26, 27, 28, 29);

void InitLCD() {
  lcd.begin(16, 2);
  lcd.noBlink();
  lcd.home();
  lcd.clear();
  lcd.display();
  lcd.setCursor(0, 0);
}