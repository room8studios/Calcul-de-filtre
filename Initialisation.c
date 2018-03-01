#include "Initialisation.h"

void Initialisation_filtre(filtre *filtre)
{
    filtre->ordre=0;
    filtre->type_filtre=PASSE_BAS;
    filtre->fc=0;
    filtre->fr=0;
    filtre->m=0;
    filtre->Ele_prio=CONDENSATEUR;
};
