#include <GrapheEtat.h>
#include <MesFonctions.h>
#include <TempoNonBloquante.h>

#define BLSB B00001111

void CGrapheEtat::Init(void) {
	Etat = LEDSOFF;
	EtatOld = LEDSOFF;
}

void CGrapheEtat::Entrees(void) {
	bBP1 = TestBP1();
	bFinTempo = TestTempoNB();
}

void CGrapheEtat::Evolue(void) {							// machine d'�tats
    switch (Etat){
    case LEDSOFF:
        if (true == bBP1){
            Etat = LEDSON;
        }
        break;
    case LEDSON:
        if (false == bBP1){
            Etat = LEDS_ONC;
        }
        break;
    case LEDS_ONC:
        if ((true == bFinTempo) && (false == bBP1)){
            Etat = LEDSOFF;
        }
        else if ((false == bFinTempo) && (true == bBP1)){
            Etat = LEDSON;
        }
        break;
    }
}

void CGrapheEtat::Sorties(void)
{
    // �criture sur les sorties
    if (Etat != EtatOld){
        EtatOld = Etat;
        switch (Etat){
        case LEDSOFF:
            PORTC = PORTC & ~BLSB;
            break;
        case LEDSON:
            PORTC = PORTC | BLSB;
            break;
        case LEDS_ONC:
            PORTC = PORTC | BLSB;
            DemTempoNB(5000);
            break;
        }
    }
}
