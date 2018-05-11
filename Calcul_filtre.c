#include "Calcul_filtre.h"

void frequences_particulieres(filtre *filtre)
{
    ///Faire les cas ou R, C, L sont nuls
    float omega0=0, omegar=0;
    float R_exact_calculee=filtre->compo_exact.R_exact*pow(10, filtre->compo_exact.R_exact_pui), C_exact_calculee=filtre->compo_exact.C_exact*pow(10, filtre->compo_exact.C_exact_pui);
    float L_exact_calculee=filtre->compo_exact.L_exact*pow(10, filtre->compo_exact.L_exact_pui);

    /*On regarde l'ordre du filtre*/
    if(filtre->ordre==1)
    {   /*On regarde le type de filtre*/
        switch(filtre->type_filtre)
        {
            case PASSE_BAS :
            {
                printf("On est en presence d'un filtre passe bas d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                //On regarde l'element prioritaire
                if((filtre->Ele_prio==CONDENSATEUR) || (filtre->Ele_prio==AUCUN))
                {
                    omega0=1/((R_exact_calculee)*(C_exact_calculee));
                }
                else
                {
                    omega0=R_exact_calculee/L_exact_calculee;
                }

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupure est %f Hz \n", filtre->fc);

                break;
            }
            case PASSE_HAUT :
            {
                printf("On est en presence d'un filtre passe haut d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                //On regarde l'element prioritaire
                if(filtre->Ele_prio==CONDENSATEUR)
                {
                    omega0=1/(R_exact_calculee)*(C_exact_calculee);
                }
                else
                {
                    omega0=R_exact_calculee/(C_exact_calculee);
                }

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupure est %f Hz \n", filtre->fc);

                break;
            }
            default :
            {
                printf("Cas impossible pour un filtre d'ordre 1 (cas default)\n");
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
                printf("On est en presence d'un filtre passe bas d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                omega0=1/sqrt(L_exact_calculee*C_exact_calculee);

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupure est %f Hz\n", filtre->fc);

                //Calcul de m
                filtre->m=(1/2)*R_exact_calculee*sqrt(C_exact_calculee/L_exact_calculee);

                //Calcul de pulsation de rŽsonnance
                omegar=omega0*sqrt(1-2*pow(filtre->m, 2));

                //Calcul de la frŽquence de rŽsonnance
                filtre->fr=omegar/(2*M_PI);
                printf("La frequence de resonnance est %f Hz \n", filtre->fr);

                break;
            }
            case PASSE_HAUT :
            {
                printf("On est en presence d'un filtre passe haut d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                omega0=1/sqrt(L_exact_calculee*C_exact_calculee);

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupure est %f Hz \n", filtre->fc);

                //Calcul de m
                filtre->m=(1/2)*R_exact_calculee*sqrt(C_exact_calculee/L_exact_calculee);

                //Calcul de pulsation de rŽsonnance
                omegar=omega0/sqrt(1-2*pow(filtre->m, 2));

                //Calcul de la frŽquence de rŽsonnance
                filtre->fr=omegar/(2*M_PI);
                printf("La frequence de resonnance est %f Hz \n", filtre->fr);

                break;
            }
            case PASSE_BANDE :
            {
                printf("On est en presence d'un filtre passe bande d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                omega0=1/sqrt(L_exact_calculee*C_exact_calculee);

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupure est %f Hz \n", filtre->fc);

                //Calcul de m
                filtre->m=(1/2)*R_exact_calculee*sqrt(C_exact_calculee/L_exact_calculee);

                //Calcul de pulsation de rŽsonnance
                omegar=omega0/sqrt(1-2*pow(filtre->m, 2));

                //Calcul de la frŽquence de rŽsonnance
                filtre->fr=omegar/(2*M_PI);
                printf("La frequence de resonnance est %f Hz \n", filtre->fr);

                break;
            }
            case COUPE_BANDE :
            {
                printf("On est en presence d'un filtre coupe bande d'ordre %i\n", filtre->ordre);

                //Calcul de la pulsation de coupure
                omega0=1/sqrt(L_exact_calculee*C_exact_calculee);

                //Calcul de la frŽquence de coupure
                filtre->fc=omega0/(2*M_PI);
                printf("La frequence de coupure est %f Hz \n", filtre->fc);

                //Calcul de m
                filtre->m=(1/2)*R_exact_calculee*sqrt(C_exact_calculee/L_exact_calculee);

                //Calcul de pulsation de rŽsonnance
                omegar=omega0/sqrt(1-2*pow(filtre->m, 2));

                //Calcul de la frŽquence de rŽsonnance
                filtre->fr=omegar/(2*M_PI);
                printf("La frequence de resonnance est %f Hz \n", filtre->fr);

                break;
            }
        }

    }
    else
    {
        printf("Pour bientot !");
    }
}

