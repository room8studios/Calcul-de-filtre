#include "Calcul_filtre.h"

void frequence_coupure(filtre *filtre, resistance R, capacite C, inductance L)
{
    ///Faire les cas ou R, C, L sont nuls
    float omega0=0, omegar=0;

    /*On regarde l'ordre du filtre*/
    if(filtre->ordre==1)
    {   /*On regarde le type de filtre*/
        switch(filtre->type_filtre)
        {
            case PASSE_BAS :
            {
                printf("On est en presence d'un filtre passe bas d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                //On regarde l'ŽlŽment prioritaire
                if(filtre->Ele_prio==CONDENSATEUR)
                {
                    omega0=1/(R*C);
                }
                else
                {
                    omega0=R/C;
                }

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupeure est %f Hz", filtre->fc);

                break;
            }
            case PASSE_HAUT :
            {
                printf("On est en presence d'un filtre passe haut d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                //On regarde l'ŽlŽment prioritaire
                if(filtre->Ele_prio==CONDENSATEUR)
                {
                    omega0=1/(R*C);
                }
                else
                {
                    omega0=R/C;
                }

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupeure est %f Hz", filtre->fc);

                break;
            }
            default :
            {
                printf("Cas non impossible pour un filtre d'ordre 1 (cas default)\n");
            }
        }
    }
    else if(filtre->ordre==2)
    {
        /*On regarde le type de filtre*/
        switch(filtre->type_filtre)
        {
            case PASSE_BAS :
            {
                printf("On est en presence d'un filtre passe haut d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                omega0=1/sqrt(L*C);

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupeure est %f Hz", filtre->fc);

                //Calcul de m
                filtre->m=(1/2)*R*sqrt(C/L);

                //Calcul de pulsation de rŽsonnance
                omegar=omega0*sqrt(1-2*pow(filtre->m, 2));

                //Calcul de la frŽquence de rŽsonnance
                filtre->fr=omegar/(2*M_PI);
                printf("La frequence de resonnance est %f Hz", filtre->fr);

                break;
            }
            case PASSE_HAUT :
            {
                printf("On est en presence d'un filtre passe haut d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                omega0=1/sqrt(L*C);

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupeure est %f Hz", filtre->fc);

                //Calcul de m
                filtre->m=(1/2)*R*sqrt(C/L);

                //Calcul de pulsation de rŽsonnance
                omegar=omega0/sqrt(1-2*pow(filtre->m, 2));

                //Calcul de la frŽquence de rŽsonnance
                filtre->fr=omegar/(2*M_PI);
                printf("La frequence de resonnance est %f Hz", filtre->fr);

                break;
            }
            case PASSE_BANDE :
            {
                printf("On est en presence d'un filtre passe haut d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                omega0=1/sqrt(L*C);

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupeure est %f Hz", filtre->fc);

                //Calcul de m
                filtre->m=(1/2)*R*sqrt(C/L);

                //Calcul de pulsation de rŽsonnance
                omegar=omega0/sqrt(1-2*pow(filtre->m, 2));

                //Calcul de la frŽquence de rŽsonnance
                filtre->fr=omegar/(2*M_PI);
                printf("La frequence de resonnance est %f Hz", filtre->fr);

                break;
            }
            case COUPE_BANDE :
            {
                printf("On est en presence d'un filtre passe haut d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                omega0=1/sqrt(L*C);

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupeure est %f Hz", filtre->fc);

                //Calcul de m
                filtre->m=(1/2)*R*sqrt(C/L);

                //Calcul de pulsation de rŽsonnance
                omegar=omega0/sqrt(1-2*pow(filtre->m, 2));

                //Calcul de la frŽquence de rŽsonnance
                filtre->fr=omegar/(2*M_PI);
                printf("La frequence de resonnance est %f Hz", filtre->fr);

                break;
            }
        }

    }
    else
    {
        printf("Pour bientot !");
    }
};

void resistance_equivalente(resistance R)
{

}
