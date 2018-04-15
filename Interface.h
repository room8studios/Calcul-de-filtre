#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include "Structures.h"

void saisie_filtre_souhaite(filtre *filtre);

resistance saisie_resistances(int i);

capacite saisie_condensateur(int i);

inductance saisie_inductance(int i);

void montage_choisi(filtre filtre);

void montage_determine_exact(filtre filtre);



#endif // INTERFACE_H_INCLUDED
