#ifndef DETERMINATION_H_INCLUDED
#define DETERMINATION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "composants.h"
#include "Structures.h"


void calcul_composant_exact(filtre filtre, capacite*C, resistance*R, inductance*L);
void calcul_composant_standard();

#endif // DETERMINATION_H_INCLUDED
