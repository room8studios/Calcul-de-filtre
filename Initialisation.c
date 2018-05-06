#include "Initialisation.h"

void Initialisation_filtre(filtre *filtre)
{
    filtre->ordre=0;
    filtre->type_filtre=PASSE_BAS;
    filtre->fc=0;
    filtre->fr=0;
    filtre->m=0;
    filtre->Ele_prio=CONDENSATEUR;
    filtre->compo_exact.R_exact=0;
    filtre->compo_exact.C_exact=0;
    filtre->compo_exact.L_exact=0;
    Init_Liste(&filtre->compo_aproxi.R_aproxi);
    filtre->R_dispo.decade=6;
    filtre->R_dispo.pui_de_10_max=6;
    filtre->C_dispo.decade=1; //Inutile dans la structure mais juste pour initialiser
    filtre->C_dispo.pui_de_10_max=6;
}

