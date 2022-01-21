#ifndef __MesFonctions_h_
#define __MesFonctions_h_

#include <Arduino.h>
#include "GEIIutil.h"

// PORTC b0 à b3 en sortie, b4 à b7 en entrée
#define DDRCINIT B00001111  

/**
 * @brief Affecte l'état d'une LED  
 * Le PORTC doit être préalablement initialisé avec DDRCINIT
 * 
 * @param x_int8_numLed numéro de la LED (0 à 3)
 * @param x_bool_etat etat (true=allumée, false=éteinte)
 */
void GereLedsPortC(int8_t x_int8_numLed, bool x_bool_etat);

/**
 * @brief Teste l'appui du bouton poussoir BP1
 * Cette fonction intègre un mécanisme d'anti-rebond de 2ms
 * 
 * @return true si le bouton est enfoncé
 * @return false si le bouton est relaché
 */
bool TestBP1(void);

#endif