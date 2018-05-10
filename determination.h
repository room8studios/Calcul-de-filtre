#ifndef DETERMINATION_H_INCLUDED
#define DETERMINATION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Structures.h"
#include "Liste_chainee.h"

/**
* @brief Calcul des composants exacts du filtre en fonciton des paramètres du filtre
*
* @param filtre pointeur sur filtre
*/
void calcul_composant_exact(filtre *filtre);

/**
* @brief Calcul des composants standards (avec des decades) en fonciton des composants exacts
*
* @param filtre pointeur sur filtre
*/
void calcul_composant_standard(filtre *filtre);

/**
* @brief Calcul des resistances standards (avec des decades) en fonciton des resistances exacts
*
* @param filtre pointeur sur filtre
*/
void calcul_R_standard(filtre *filtre);

/**
* @brief Calcul des condensateurs standards (avec des decades) en fonciton des condensateurs exacts
*
* @param filtre pointeur sur filtre
*/
void calcul_C_standard(filtre *filtre);

/**
* @brief Calcul des inductances standards (avec des decades) en fonciton des inductances exacts
*
* @param filtre pointeur sur filtre
*/
void calcul_L_standard(filtre *filtre);

/**
* @brief Calcul des erreurs commises entre les composants standards et les composants exacts
*
* @param filtre pointeur sur filtre
*/
void erreur_commise(filtre *filtre);

/**
* @brief Calcul des puissances pour les composants exacts
*
* @param filtre pointeur sur filtre
*/
void calcul_pui_composant(filtre *filtre);

#endif // DETERMINATION_H_INCLUDED
