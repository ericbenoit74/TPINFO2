/*-------------------------------------------*/
/* Cours d'Informatique Industrielle I2      */
/* (c) B Caron 2012-2013                     */
/* TempoNB basée sur la fonction millis()    */
/*-------------------------------------------*/

#include "TempoNonBloquante.h"
//
void Tempo_RW(bool bRead,unsigned long &Debut,unsigned long &Duree){
	static unsigned long DebutMem=0,DureeMem=0 ; 	//mémorisation 
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
	Tempo_RW(true,Debut,Duree);		// pour éviter une variable globale
	Fin = millis() - Debut;			//calcul de l’écart
	if(Fin >= Duree){				//précision 1ms
		bFin=true;
	}
	return bFin;
}
void DemTempoNB(unsigned long Duree){
	//
	unsigned long Debut;
	Debut = millis();		//lecture début 
	Tempo_RW(false,Debut,Duree);  // pour éviter une variable globale
}