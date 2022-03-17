/*-------------------------------------------*/
/* Cours d'Informatique Industrielle I2      */
/* (c) B Caron 2012-2013                     */
/* TempoNB bas�e sur la fonction millis()    */
/*-------------------------------------------*/

#include "TempoNonBloquante.h"
//
void Tempo_RW(bool bRead,unsigned long &Debut,unsigned long &Duree){
	static unsigned long DebutMem=0,DureeMem=0 ; 	//m�morisation 
	if (true==bRead) {
		Debut=DebutMem;
		Duree=DureeMem;
	} 
	else {
		DebutMem=Debut;
		DureeMem=Duree;
	}
	
}
bool TestTempoNB(void){

	bool bFin=false;
	unsigned long Fin,Debut,Duree;
	//
	Tempo_RW(true,Debut,Duree);		// pour �viter une variable globale
	Fin = millis() - Debut;			//calcul de l��cart
	if(Fin >= Duree){				//pr�cision 1ms
		bFin=true;
	}
	return bFin;
}
void DemTempoNB(unsigned long Duree){
	//
	unsigned long Debut;
	Debut = millis();		//lecture d�but 
	Tempo_RW(false,Debut,Duree);  // pour �viter une variable globale
}