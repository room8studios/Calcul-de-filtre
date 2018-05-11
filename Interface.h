#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include "Structures.h"
#include "Calcul_filtre.h"
#include "determination.h"

/**
* @brief Saisie du filtre du filtre avec ses paramètres
*
* @param filtre pointeur sur filtre
*/
void saisie_filtre_souhaite(filtre *filtre);

/**
* @brief Resolution du filtre en fonction du cas
*
* @param filtre pointeur sur filtre
*/
void strategie_resolution(filtre *filtre);

/**
* @brief Saisie des résistances
*
* @param filtre pointeur sur filtre
*/
void saisie_resistances(filtre *filtre);

/**
* @brief Saisie des condensateurs
*
* @param filtre pointeur sur filtre
*/
void saisie_condensateur(filtre *filtre);

/**
* @brief Saisie des inductances
*
* @param filtre pointeur sur filtre
*/
void saisie_inductance(filtre *filtre);

/**
* @brief Saisie du mode de "resolution"
*
* @param filtre pointeur sur filtre
*/
void saisie_mode(filtre *filtre);

/**
* @brief Saisie de l'ordre du filtre
*
* @param filtre pointeur sur filtre
*/
void saisie_ordre(filtre *filtre);

/**
* @brief Saisie du type de filtre
*
* @param filtre pointeur sur filtre
*/
void saisie_type_filtre(filtre *filtre);

/**
* @brief Saisie des frequences particulieres du filtre
*
* @param filtre pointeur sur filtre
*/
void saisie_freq_filtre(filtre *filtre);

/**
* @brief Saisie de l'element prioritaire du filtre
*
* @param filtre pointeur sur filtre
*/
void saisie_compo_prio(filtre *filtre);

/**
* @brief Saisie de la decade de resistance disponible en stock
*
* @param filtre pointeur sur filtre
*/
void saisie_decade_R_dispo(filtre *filtre);

/**
* @brief Saisie de la puissance de 10 maximale de la decade disponible en stock
*
* @param filtre pointeur sur filtre
*/
void saisie_pui_10_R_dispo(filtre *filtre);

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
