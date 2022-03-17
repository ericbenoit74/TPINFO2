/*-------------------------------------------*/
/* Cours d'Informatique Industrielle I2      */
/* (c) JN Martin 2013-2014                   */
/* tempoNB bas�e sur la fonction millis()    */
/*-------------------------------------------*/

#ifndef _TempoNonBloquante_h
#define _TempoNonBloquante_h
#include <Arduino.h>
//
void Tempo_RW(bool bRead,unsigned long &Debut,unsigned long &Duree);

/**
 * @brief Test de la temporisation
 * 
 * @return true si la temporisation est ecoulée
 * @return false si la temporisation n'est pas terminée
 */
bool TestTempoNB(void);

/**
 * @brief Démarre une temporisation
 * 
 * @param Duree Durée de la temporisation (ms)
 */
void DemTempoNB(unsigned long Duree);

#endif
