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
  /************************
  InitTimer3PE3
  G�n�re un signal carr� � 1kHz sur PE3 � partir du timer3

  param�tres : aucun
  retourne rien
  **************************/
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
  void InitTimer3PE3(void);

  /************************
  DemTimer3PE3
  G�n�re un signal carr� � 1kHz sur PE3 � partir du timer3
  Utiliser InitTimer3PE3() au pr�alable
  param�tres : aucun
  retourne rien
  **************************/


  void DemTimer3PE3(void);

  /************************
  StopTimer3PE3
  Stoppe la g�n�ration d'un signal carr� � 1kHz sur PE3 � partir du timer3
  Utiliser InitTimer3PE3() au pr�alable
  param�tres : aucun
  retourne rien
  **************************/
 
  void StopTimer3PE3(void);
  /************************
  FreqTimer3PE3
  modifie la fr�quence de la g�n�ration d'un signal carr� sur PE3 � partir du timer3
  Utiliser InitTimer3PE3() au pr�alable
  param�tres :
  unsigned long fr�quence de 15Hz � 1000000Hz par pas de 15.25 Hz
  retourne rien
  **************************/

 /**
  * @brief Modifie la fréquence du signal produit via le timer3
  * 
  * Utiliser InitTimer3PE3() au préalable
  * 
  * @param ulFrequence fréquence de 15
  */
  void FreqTimer3PE3(unsigned long ulFrequence);
};
#endif