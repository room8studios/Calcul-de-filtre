#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include "Structures.h"

/**
* @brief Saisie du filtre du filtre avec ses paramètres
*
* @param filtre pointeur sur filtre
*/
void saisie_filtre_souhaite(filtre *filtre);

/**
* @brief Saisie des résistances
*
* @param i Entier
*/
resistance saisie_resistances(int i);

/**
* @brief Saisie des condensateurs
*
* @param i Entier
*/
capacite saisie_condensateur(int i);

/**
* @brief Saisie des inductances
*
* @param i Entier
*/
inductance saisie_inductance(int i);

/**
* @brief Affichage du montage choisi
*
* @param filtre Filtre
*/
void montage_choisi(filtre filtre);

/**
* @brief Affichage du montage determine avec les composants exacts
*
* @param filtre Filtre
*/
void montage_determine_exact(filtre filtre);



#endif // INTERFACE_H_INCLUDED
