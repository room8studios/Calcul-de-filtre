#ifndef DETERMINATION_H_INCLUDED
#define DETERMINATION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "composants.h"
#include "Structures.h"


void calcul_composant_exact(frequence f, ordre a, type_filtre p, capacite*C, resistance*R, inductance*L, Element_prioritaire Ele_prio);
void calcul_composant_standard();

#endif // DETERMINATION_H_INCLUDED
