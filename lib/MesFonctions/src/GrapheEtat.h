#ifndef __GrapheEtat_h
#define __GrapheEtat_h

typedef enum { LEDSON, LEDSOFF, LEDS_ONC } TypeEtat;

class CGrapheEtat{
private:
    TypeEtat  Etat, EtatOld;
    bool bBP1 = false;
	bool bFinTempo = true;
public:	
	void Init(void);
	void Entrees(void);
	void Evolue(void);
	void Sorties(void);
};

#endif