#ifndef __cna_h_
#define __cna_h_
#include <Arduino.h>
#include <GEIIutil.h>


#define  MSK_ADSC BIT6
void InitCan8(void);
void InitCan10(void);
uint8_t ConvAN8(void);

/**
 * @brief Conversion A/N sur 8 bits
 * entrée A9
 * Doit être initilisé une fois avec InitCan10
 * 
 * @return word résultat de la conversion
 * @see InitCan10
 */word ConvAN10(void);


/**
 * @brief Convertisseur A/N 8 bits 
 * Entrée A9 non différentielle
 * 
 */
class CConvAN8 {
public:

	/**
	 * @brief Initialisation de la conversion
	 * Vref = VCC, clck/16,
	 * ADATE = 0, ADIF = 0, ADIE = 0, ADLAR = 1
	 */
	void Init(void);

	/**
	 * @brief réalisation de la conversion
	 * 
	 * @return byte résultat de la conversion
	 * @see CConvAN8::Init
	 */
	uint8_t Conv(void);
};

#endif