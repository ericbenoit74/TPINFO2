/*-------------------------------------------*/
/* Cours d'Informatique Embarqu�e Info2      */
/* (c) JN Martin - B Caron 01-2018           */
/* fichier d'ent�te Fonctions.h              */
/*-------------------------------------------*/
#ifndef __GEIIutil_h_
#define __GEIIutil_h_
#include <Arduino.h>
#include "LiquidCrystal.h"

#define BIT0 (1<<0)
#define BIT1 (1<<1)
#define BIT2 (1<<2)
#define BIT3 (1<<3)
#define BIT4 (1<<4)
#define BIT5 (1<<5)
#define BIT6 (1<<6)
#define BIT7 (1<<7)

/** connexion MCU-LCD
 * LCD RS pin to digital pin 24
 * LCD Enable pin to digital pin 25
 * LCD D4 pin to digital pin 26
 * LCD D5 pin to digital pin 27
 * LCD D6 pin to digital pin 28
 * LCD D7 pin to digital pin 29
 * LCD R/W pin to ground 
 * Lignes n�0 et n�1
 * Colonnes n�0 � n�15
 * Initialisation avec les n� des bornes du kit IUT
 * LiquidCrystal lcd(rs, enable, d4, d5, d6, d7) 
 */
extern LiquidCrystal lcd;

/**
 * @brief Initialisation de l'écran LCD du kit
 * Cette fonction doit être appelée avant toute utilisation du LCD
 */
void InitLCD();

/*-----------------------------------------------
Initialisations conformes � la carte ARDUINO-IUT
Entr�e = IN = 0, Sortie = OUT = 1, NU = 0 
-------------------------------------------------
PA7  29 Afficheur LCD 2x16 ligne D7  Sortie 1
PA6 28 Afficheur LCD 2x16 ligne D6  Sortie 1
PA5 27 Afficheur LCD 2x16 ligne D5  Sortie 1
PA4 26 Afficheur LCD 2x16 ligne D4  Sortie 1
PA3 25 Afficheur LCD 2x16 ligne EN  Sortie 1
PA2 24 Afficheur LCD 2x16 ligne RS  Sortie 1
PA1 23 NU 0
PA0 22 Afficheur uOLED Reset    Sortie 1
-------------------------------------------------
PB7 PWM13 NU 0  
PB6 PWM12 NU 0
PB5 PWM11 NU 0
PB4 PWM10 Ethernet SSTCP  Sortie 1
PB3 50 Ethernet MISO    Entree 0
PB2 51 Ethernet MOSI    Sortie 1
PB1 52 Ethernet SCK     Sortie 1
PB0 53 Ethernet SSHard    Sortie 1
-------------------------------------------------
PC7 30 Inter1 Entree 0  
PC6 31 Inter0 Entree 0  
PC5 32 BP1    Entree 0  
PC4 33 BP0    Entree 0
PC3 34 LED3   Sortie 1
PC2 35 LED2   Sortie 1    
PC1 36 LED1   Sortie 1
PC0 37 LED0   Sortie 1
-------------------------------------------------
PD7 38 Inter1 Entree 0  
PD6 NC 0  
PD5 NC 0  
PD4 NC 0
PD3 18 Tx1 BNC4 Sortie 1
PD2 19 Rx1 IRQ clavier I2C Entree 0   
PD1 20 SDA I2C  Sortie 1
PD0 21 SCL I2C  Sortie 1
-------------------------------------------------
PE7 NC 0  
PE6 NC 0  
PE5 PWM3 INT5 BNC1 Entree 0 
PE4 PWM2 INT4 BNC2 Entree 0
PE3 PWM5 BUZZER    Sortie 1
PE2 NC 0    
PE1 1 Tx0 USB PROG  Sortie 1
PE0 0 Rx0 USB PROG  Entree 0
-------------------------------------------------
PF7 A7 LED7B Sortie 1 
PF6 A6 LED6B Sortie 1 
PF5 A5 LED5B Sortie 1
PF4 A4 LED4B Sortie 1
PF3 A3 LED7 Sortie 1
PF2 A2 LED6 Sortie 1
PF1 A1 LED5 Sortie 1
PF0 A0 LED4 Sortie 1
-------------------------------------------------
PG7 - 
PG6 - 
PG5 PWM4 carte SD SSSD  Sortie 1
PG4 NC 0
PG3 NC 0
PG2 carte BusCAN SS   Sortie 1
PG1 40 Entree 0
PG0 41 Entree 0
-------------------------------------------------
PH7 NC 0  
PH6 PWM9 LED3B Sortie 1
PH5 PWM8 LED2B Sortie 1
PH4 PWM7 LED1B Sortie 1
PH3 PWM6 LED0B Sortie 1
PH2 NC 0
PH1 16 Tx2 Afficheur uOLED RX Sortie 1
PH0 17 Rx2 Afficheur uOLED TX Entree 0
-------------------------------------------------
PJ7 � PJ2 NC 0  
PJ1 14 Tx3 BNC3 PCINT10 Sortie 1
PJ0 15 Rx3 Entree 0
-------------------------------------------------
PK7 A15 Entree 0  
PK6 A14 Entree 0
PK5 A13 Entree 0
PK4 A12 Capteur de lumi�re LUX Entree 0
PK3 A11 Capteur de temp�rature Entree 0
PK2 A10 Potentiom�tre2 Entree 0
PK1 A9  Potentiom�tre1 Entree 0
PK0 A8 BNC5 Entree 0
-------------------------------------------------
PL7 42 Entree 0 
PL6 43 Entree 0
PL5 44 Entree 0
PL4 45 Entree 0
PL3 46 Entree 0
PL2 47 Entree 0
PL1 48 Entree 0
PL0 49 BNC6 IC4 Entree 0
-----------------------------------------------*/

#define INIT_A B11111101    // initialisation DDRA
#define INIT_B B00010111    // initialisation DDRB
#define INIT_C B00001111    // initialisation DDRC
#define INIT_D B00001011    // initialisation DDRD
#define INIT_E B00001010    // initialisation DDRE
#define INIT_F B11111111    // initialisation DDRF
#define INIT_G B11100100    // initialisation DDRG
#define INIT_H B01111010    // initialisation DDRH
#define INIT_J B00000010    // initialisation DDRJ
#define INIT_K B00000000    // initialisation DDRK
#define INIT_L B00000000    // initialisation DDRL

//proto
/**
 * @brief Initialisation des ports du kit
 *        Doit être appelée dans la fonction setup()
 * 
 */
void InitPort(void);

/**
 * @brief Teste l'appui sur bouton poussoir BP1 du kit
 * 
 * @return true si le bouton est enfoncé
 * @return false si le bouton n'est pas enfoncé
 */
bool TestAppuiBP1(void);

/**
 * @brief Teste l'appui sur bouton poussoir BP0 du kit
 * 
 * @return true si le bouton est enfoncé
 * @return false si le bouton n'est pas enfoncé
 */
bool TestAppuiBP0(void);

/**
 * @brief Test de l'interrupteur SW1 du kit
 * 
 * @return true 
 * @return false 
 */
bool TestInterSW1(void);

/**
 * @brief Test de l'interrupteur SW0 du kit
 * 
 * @return true 
 * @return false 
 */
bool TestInterSW0(void);

#endif