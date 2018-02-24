#include "Interface.h"

void saisie_utili(int nummero)
{
    int i=0;
    printf("Voulez vous saisir un autre composant ?");
    printf("Saisir le composant numero %i", i);

};

resistance saisie_resistances(int i)
{
    resistance R=0;
    Booleen booleen=FAUX;

    do{
        printf("Saisir la resistance numero R%i", i);
        scanf("%f", &R);

        if(R>5)
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur de la resistance est invalide ou trop faible");
        }
    }while(booleen==VRAI);

    return R;
};

capacite saisie_condensateur(int i)
{
    capacite C=0;
    Booleen booleen=FAUX;

    do{
        printf("Saisir le condensateur numero C%i", i);
        scanf("%f", &C);

        if(C>5)
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur du condensateur est invalide ou trop faible");
        }
    }while(booleen==VRAI);

    return C;
};

inductance saisie_inductance(int i)
{
    inductance L=0;
    Booleen booleen=FAUX;

    do{
        printf("Saisir le condensateur numero C%i", i);
        scanf("%f", &L);

        if(L>5)
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur du condensateur est invalide ou trop faible");
        }
    }while(booleen==VRAI);

    return L;
};
