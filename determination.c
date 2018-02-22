#include "determination.h"

void calcul_composant_exact(frequence f, ordre ordre, type_filtre type_filtre, capacite *C, resistance *R, inductance *L, Element_prioritaire Ele_prio)
{
    if(Ele_prio==AUCUN)
    {
        if((type_filtre==PASSE_HAUT) && (ordre==1))
        {
            *C=33*pow(10,-9);
            *R=1/(2*f*(*C));
            if(*R<=1)
            {
                *R=5;
                *C=1/(2*f*(*R));
            }
        }
        if((type_filtre==PASSE_HAUT) && (ordre==1))
        {

        }
    }
}

void calcul_composant_standard()
{

};
