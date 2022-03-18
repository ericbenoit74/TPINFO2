#include <GrapheEtat.h>
#include <MesFonctions.h>
#include <TempoNonBloquante.h>

#define BLSB B00001111

void CGrapheEtat::Init(void) {
	m_Etat_courant = LEDSOFF;
	m_Etat_old = LEDSOFF;
}

void CGrapheEtat::Entrees(void) {
	m_bool_BP1 = TestBP1();
	m_bool_FinTempo = TestTempoNB();
}

void CGrapheEtat::Evolue(void) {				
    switch (m_Etat_courant){
    case LEDSOFF:
        if (true == m_bool_BP1){
            m_Etat_courant = LEDSON;
        }
        break;
    case LEDSON:
        if (false == m_bool_BP1){
            m_Etat_courant = LEDS_ONC;
        }
        break;
    case LEDS_ONC:
        if ((true == m_bool_FinTempo) && (false == m_bool_BP1)){
            m_Etat_courant = LEDSOFF;
        }
        else if ((false == m_bool_FinTempo) && (true == m_bool_BP1)){
            m_Etat_courant = LEDSON;
        }
        break;
    }
}

void CGrapheEtat::Sorties(void)
{
    // �criture sur les sorties
    if (m_Etat_courant != m_Etat_old){
        m_Etat_old = m_Etat_courant;
        switch (m_Etat_courant){
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
