#ifndef CALCUL_FILTRE_H_INCLUDED
#define CALCUL_FILTRE_H_INCLUDED

#include <stdio.h>
#include "Structures.h"
#include "composants.h"
#include <math.h>

void frequence_coupure(filtre *filtre, resistance R, capacite C, inductance L);

#endif // CALCUL_FILTRE_H_INCLUDED
