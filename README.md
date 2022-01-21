# GEIItpINFO2

## Présentation

Ce projet sert de base pour une série de travaux pratiques d'informatique embaquée a réaliser sur le kit de dévelopement de l'IUT GEII d'Annecy.

## Procédure de codage d'une fonction

Nous prendrons comme exemple la première fonction à coder du TP1, la fonction qui défini l'état d'une LED du kit et dont le prototype est:

> `void GereLedsPortC(int8_t x_int8_numLed, bool x_bool_etat);`

###1. Codage de la fonctionnalité

Dans la fonction `setup()` écrivez les lignes qui allument la première LED.  
Ajoutez au dessus une ligne de commentaire qui explique la fonctionnalité:

> `// allumage de la LED 0`

###2. Test de la fonctionnalité

Compilez pour chargez le programme dans le kit pour vérifier le bon fonctionnement de la fonctionalité : la première LED doit s'allumer.

Mettez les lignes en commentaire et refaite l'opération pour une autre fonctionnalité.

### 3. Création d'une fonction

Codez la fonction dans le fichier main.cpp. Si necessaire, créez une fonction pour l'initialisation.

### 4. Test de la fonction

Testez la fonction avec un jeu de données représentatif dans un environnement simple.

Pour des TPs ultérieurs uniquement: Créez et exécutez les tests unitaires.

Retournez au point 3 si necessaire.

### 5. Création d'une bibliothèque:

Dans le dossier **lib** du projet, créez la bibliothèque **MesFonctions** (**MesFonctions.h** et **MesFonctions.cpp**) en suivant les indications de **lib\README**.  

Pour éviter les erreurs en cas d'inclusion multiples, ajoutez au début du fichier **MesFonctions.h**:  

> `#ifndef __MesFonctions_h_`
> `#define __MesFonctions_h_` 

et ajoutez en fin de fichier:

> `#endif`

Puis transférez la définition de la fonction **GereLedsPortC** dans **MesFonctions.cpp** et son prototype dans **MesFonctions.h**. 

### 6. Documentation

#### 6.1 Documentation dans le code

Dans le fichier **MesFonctions.h** ajoutez un bloc commentaire juste avant chaque prototype:

Pour créer un commentaire, tapez `/**` puis 'entrée' juste au-dessus de la ligne  
`void GereLedsPortC(int8_t x_int8_numLed, bool x_bool_etat);`
Le bloc suivant doit apparaître automatiquement:

> `/**`
> ` * @brief` 
> ` *` 
> `* @param x_int8_numLed `
> `* @param x_bool_etat `
> `*/`

Vous pouvez alors compléter les lignes:
après `@brief`, donnez une description rapide de la fonction.  
Dans une ligne avec ` @param`, indiquez la signification des paramètres attendus et toute information utile sur leurs valeurs (valeur max, type, ...).
Entre `@brief` et ` @param`, Donnez une description détaillée et personalisée de la fonction.  
D'autre tags peuvent apparaître ou être ajoutés:  
`@return` pour indiquer ce que retourne la fonction le cas échéant.  
`@author` noms des auteurs de la fonction.

La création automatique de documentation à partir de ce bloc sera abordée plus tard.

#### 6.2 Documentation externe

Créez le fichier lib\MesFonctions\README.md dans lequel vous indiquerez pour chaque fonction:

* le fonctionnement de la fonction
* les conditions d'utilisation de la fonction
* les jutifications de vos choix techniques

Créez des exemples d'utilsation des fonctions dans lib\MesFonctions\examples
