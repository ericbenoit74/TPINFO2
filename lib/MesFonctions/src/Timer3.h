#ifndef __Timer3_h_
#define __Timer3_h_
#include <Arduino.h>
#include <GEIIutil.h>


void InitTimer3PE3(void);
void DemTimer3PE3(void);
void StopTimer3PE3(void);
void FreqTimer3PE3(unsigned long ulFrequence);

class CTimer3PE3 {
public:

  //Configuration du coupleur
  //  Utilisation du timer3
  //  WGM3 3:0 = 4  OCR3A(pour piloter la broche OC3A et donc PE3) utilis� en mode CTC
  //  WGM3 3:0 = 4  OCR3A(pour piloter la broche OC3A et donc PE3) utilis� en mode CTC
  //  COM3A1  COM3A0 COM3B1 COM3B0 COM3C1 COM3C0 = 010000 OC3A en mode toggle, cad que OC3A(PE3) va changer d��tat � chaque fois que le compteur TCNT3 sera �gal �  OCR3A
  //  Pas de signal externe. On met quand m�me ICNC3 = 0 pas de filtre et ICES3 = 1 capture front montant
  //  Pas de capture donc FOC3A / B / C = 0
  //  Fr�quence de 1 kHz, le changement d��tat de la sortie se fera � 2 kHz soit 0,5 ms
  //  2kHz = 16MHz / 8 / 1000
  //  CS32 CS31 CS30 = 010, clock interne et division par 8 soit 2 MHz
  //  OCR3A = 1000 
  //  DDRE bit3  � 1
  //  Au final :
  //  TCCR3A
  //    COM3A1 COM3A0 COM3B1 COM3B0 COM3C1 COM3C0 WGM31 WGM30 = b0100 0000
  //  TCCR3B
  //    ICNC3 ICES3 � WGM33 WGM32 CS32 CS31 CS30 = b0000 1010
  //  TCCR3C = 0
  //  OCR3A = 1000
  //  PORTE = bxxxx1xxx

  /**
   * @brief Configure timer3 pour générer un signal carré de 1KHz sur PE3
   * 
   */
  void InitTimer3PE3(void);

 /**
  * @brief Démarre la génération du signal sur PE3
  * 
  * Utiliser InitTimer3PE3() au préalable
  * 
  * @see CTimer3PE3::InitTimer3PE3
  * 
  */
  void DemTimer3PE3(void);
 
 /**
  * @brief Stoppe la génération du signal sur PE3
  * 
  * Utiliser InitTimer3PE3() au préalable
  * 
  * @see CTimer3PE3::InitTimer3PE3
  */
  void StopTimer3PE3(void);

 /**
  * @brief Modifie la fréquence du signal produit sur PE3 via le timer3
  * 
  * Utiliser InitTimer3PE3() au préalable
  * 
  * @param ulFrequence fréquence de 15Hz à 1MHz par pas de 15.25Hz
  * @see CTimer3PE3::InitTimer3PE3
  */
  void FreqTimer3PE3(unsigned long ulFrequence);
};
#endif