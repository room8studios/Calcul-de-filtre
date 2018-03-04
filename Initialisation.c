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
    filtre->compo_aproxi.taille_R_aproxi=0;
    filtre->compo_aproxi.taille_C_aproxi=0;
    filtre->compo_aproxi.taille_L_aproxi=0;
};

void Liberer_filtre(filtre *filtre)
{
    free(filtre->compo_aproxi.R_aproxi);
    free(filtre->compo_aproxi.C_aproxi);
    free(filtre->compo_aproxi.L_aproxi);
}
