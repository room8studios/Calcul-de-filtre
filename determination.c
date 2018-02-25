#include "determination.h"

void calcul_composant_exact(filtre filtre, capacite *C, resistance *R, inductance *L)
{
    if(filtre.Ele_prio==AUCUN)
    {
        if((filtre.type_filtre==PASSE_HAUT) && (filtre.ordre==1))
        {
            *C=33*pow(10,-9);
            *R=1/(2*(filtre.fc)*(*C));
            if(*R<=1)
            {
                *R=5;
                *C=1/(2*(filtre.fc)*(*R));
            }
        }
        else if((filtre.type_filtre==PASSE_BAS) && (filtre.ordre==1))
        {

        }
    }
}

void calcul_composant_standard()
{

};
