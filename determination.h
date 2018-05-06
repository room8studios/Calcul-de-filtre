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
* @brief Calcul des composants standard (avec des decades) en fonciton des composants exacts
*
* @param filtre pointeur sur filtre
*/
void calcul_composant_standard(filtre *filtre);

#endif // DETERMINATION_H_INCLUDED
