#ifndef __MySerial_h_
#define __MySerial_h_

#include <Arduino.h>

/**
 * @brief Envoie un caractère sur la liaison série
 * 
 * @param cCar caractère à envoyer
 */
void EcritCar(char cCar);

/**
 * @brief Initialise la laison série
 * 
 * 9600 bauds, 8 bits sans parité
 * 
 */
void InitLiaisonSerie(void);

/**
 * @brief Attend un caractère sur la laison série
 * 
 * @return char caractère reçu
 */
char LitCar(void);

/**
 * @brief Lit le dernier caractère reçu
 * 
 * @return char caractère reçu ou 0 si pas de nouveau caractère
 */
char LitCarNB(void);

#endif