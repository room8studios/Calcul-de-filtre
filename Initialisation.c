#include "Initialisation.h"

void Initialisation_filtre(filtre *filtre)
{
    filtre->ordre=0;
    filtre->type_filtre=PASSE_BAS;
    filtre->fc=0;
    filtre->fr=0;
};
