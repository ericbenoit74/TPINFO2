#ifndef __GrapheEtat_h
#define __GrapheEtat_h

/**
 * @brief Noms des états du graphe
 * 
 */
typedef enum { LEDSON, LEDSOFF, LEDS_ONC } TypeEtat;

/**
 * @brief Graphe d'état du TP 4
 * 
 */
class CGrapheEtat{
private:
    // Etat 
    TypeEtat  Etat, EtatOld;
    // variables de mémorisation des entrées
    bool bBP1 = false;
	bool bFinTempo = true;
public:	
    /**
     * @brief Initialisation du graphe
     * 
     */
	void Init(void);

    /**
     * @brief Lecture des entrées
     * 
     */
	void Entrees(void);

    /**
     * @brief Calcul de l'état suivant
     * 
     */
	void Evolue(void);

    /**
     * @brief Application des sorties
     * 
     */
	void Sorties(void);
};

#endif