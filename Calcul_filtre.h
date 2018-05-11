#ifndef CALCUL_FILTRE_H_INCLUDED
#define CALCUL_FILTRE_H_INCLUDED

#include <stdio.h>
#include "Structures.h"
#include <math.h>

/**
* @brief Calcul des fr�quences de coupures et de r�sonnance en fonction des param�tres du filtre
*
* @param filtre un pointeur sur filtre
*/
void frequences_particulieres(filtre *filtre);

#endif // CALCUL_FILTRE_H_INCLUDED
