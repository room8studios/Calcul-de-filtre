#ifndef CALCUL_FILTRE_H_INCLUDED
#define CALCUL_FILTRE_H_INCLUDED

#include <stdio.h>
#include "Structures.h"
#include <math.h>

/**
* @brief Calcul des fréquences de coupures et de résonnance en fonction des paramètres du filtre
*
* @param filtre un pointeur sur filtre
*/
void frequences_particulieres(filtre *filtre);

#endif // CALCUL_FILTRE_H_INCLUDED
