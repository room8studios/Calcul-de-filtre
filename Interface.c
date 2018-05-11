#include "Interface.h"

void saisie_filtre_souhaite(filtre *filtre)
{
    saisie_mode(filtre);
    if(filtre->mode_resoulution==1)
    {
        //Determination d'un montage
        printf("==========Mode 1==============\n");
        printf("==========Saisie des donnees==============\n\n");
        saisie_ordre(filtre);
        printf("\n");
        saisie_type_filtre(filtre);
        printf("\n");
        saisie_compo_prio(filtre);
        printf("\n");
        saisie_freq_filtre(filtre);
        printf("\n");
        saisie_decade_R_dispo(filtre);
        printf("\n");
        saisie_pui_10_R_dispo(filtre);

    }
    else
    {
        //Determination des frequences
        printf("==========Mode 2==============\n");
        printf("==========Saisie des donnees==============\n\n");
        saisie_ordre(filtre);
        printf("\n");
        saisie_type_filtre(filtre);
        printf("\n");
        saisie_compo_prio(filtre);
        printf("\n");
        saisie_resistances(filtre);
        printf("\n");
        saisie_condensateur(filtre);
        printf("\n");
        saisie_inductance(filtre);
    }
}

void strategie_resolution(filtre *filtre)
{
    if(filtre->mode_resoulution==1)
    {
        //On calcul les composants exacts
        calcul_composant_exact(filtre);
        calcul_composant_standard(filtre);
        montage_determine_exact(*filtre);

    }
    else
    {
        frequences_particulieres(filtre);
        montage_choisi(*filtre);
    }
}

void saisie_resistances(filtre *filtre)
{
    Booleen booleen=FAUX;

    do{
        printf("Saisir la resistance equivalente R (doit etre >5 Ohms)\n");
        printf("Maniere de saisie de la resistance : \n");
        printf("Etape 1 : Valeur de la resistance (sans la puissance) \n Etape 2 : Puissance de la resistance (>0) \n");
        printf("R : ");
        scanf("%f", &filtre->compo_exact.R_exact);
        printf("Puissance de R : ");
        scanf("%i", &filtre->compo_exact.R_exact_pui);

        if((filtre->compo_exact.R_exact>5) && (filtre->compo_exact.R_exact_pui>=0))
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur ou puissance de la resistance invalide ou trop faible \n");
        }
    }while(booleen==FAUX);
}

void saisie_condensateur(filtre *filtre)
{
    Booleen booleen=FAUX;

    do{
        printf("Saisir le condensateur equivalent C (doit etre >5 Ohms)\n");
        printf("Maniere de saisie du condensateur : \n");
        printf("Etape 1 : Valeur du condensateur (sans la puissance) \n Etape 2 : Puissance du condensateur (<0 en general) \n");
        printf("C :");
        scanf("%f", &filtre->compo_exact.C_exact);
        printf("Puissance de C : ");
        scanf("%i", &filtre->compo_exact.C_exact_pui);

        if(filtre->compo_exact.C_exact>5)
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur du condensateur invalide ou trop faible \n");
        }
    }while(booleen==FAUX);
}

void saisie_inductance(filtre *filtre)
{
    Booleen booleen=FAUX;

    do{
        printf("Saisir l'inductance equivalente L (doit etre >5 Ohms)\n");
        printf("Maniere de saisie de l'inductance : \n");
        printf("Etape 1 : Valeur de l'inductance (sans la puissance) \n Etape 2 : Puissance de l'inductance (<0 en general) \n");
        printf("L :");
        scanf("%f", &filtre->compo_exact.L_exact);
        printf("Puissance de L : ");
        scanf("%i", &filtre->compo_exact.L_exact_pui);

        if(filtre->compo_exact.L_exact>5)
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur de l'inductance invalide ou trop faible \n");
        }
    }while(booleen==FAUX);
}

void saisie_mode(filtre *filtre)
{
    Booleen booleen=FAUX;

    do{
        printf("Mode (1)=1 => Determination d'un montage a partir de l'ordre, du type et des frequences particulieres du filtre souhaite \n");
        printf("Mode (2)=2 => Determination des frequences particulieres du filtre a partir de l'ordre, du type et des composants exacts \
           souhaites (somme de chaque type de composant) du filtre souhaite \n");
        printf("Mode : ");
        scanf("%i", &filtre->mode_resoulution);

        if((filtre->mode_resoulution==1) || (filtre->mode_resoulution==2))
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur du mode non valide \n");
        }
    }while(booleen==FAUX);
}

void saisie_ordre(filtre *filtre)
{
    Booleen booleen=FAUX;
    do{
        printf("Voulez souhaitez un filtre d'ordre ? \n");
        printf("Ordre : ");
        scanf("%i", &filtre->ordre);

        if(filtre->ordre>0)
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur de l'ordre du filtre invalide (<0) \n");
        }

    }while(booleen==FAUX);
}

void saisie_type_filtre(filtre *filtre)
{
    Booleen booleen=FAUX;
    do{
        printf("Voulez souhaitez quel type de filtre ? \n");
        if(filtre->ordre==1)
        {
            printf("PASSE BAS=0 \n PASSE HAUT=1 \n");
            printf("Type : ");
            scanf("%i", &filtre->type_filtre);

            if((filtre->type_filtre==0) || (filtre->type_filtre==0))
            {
                booleen=VRAI;
            }
            else
            {
                printf("Valeur de l'ordre du filtre invalide (<0) \n");
            }
        }
        else
        {
            printf("PASSE BAS=0 \n PASSE HAUT=1 \n PASEE BANDE=2 \n PASEE COUPE=3 \n");
            printf("Type : ");
            scanf("%i", &filtre->type_filtre);

            if((filtre->type_filtre==0) || (filtre->type_filtre==1) || (filtre->type_filtre==2) || (filtre->type_filtre==3))
            {
                booleen=VRAI;
            }
            else
            {
                printf("Valeur de l'ordre du filtre invalide (<0) \n");
            }
        }


    }while(booleen==FAUX);
}

void saisie_freq_filtre(filtre *filtre)
{
    Booleen booleen=FAUX;
    if(filtre->ordre==1)
    {
        do{
            printf("Saisir la frequence de coupure (fc) du filtre \n");
            printf("Frequence de coupure (fc) en Hz : ");
            scanf("%f", &filtre->fc);

            if(filtre->fc>0)
            {
                booleen=VRAI;
            }
            else
            {
                printf("Valeur de la frequence de coupure (fc) invalide (<0) \n");
            }
        }while(booleen==FAUX);
    }
    else
    {
        //Saisie frequence de coupure
        do{
            printf("Saisir la frequence de coupure (fc) du filtre \n");
            printf("Frequence de coupure (fc) en Hz : ");
            scanf("%f", &filtre->fc);

            if(filtre->fc>0)
            {
                booleen=VRAI;
            }
            else
            {
                printf("Valeur de la frequence de coupure (fc) invalide (<0) \n");
            }
        }while(booleen==FAUX);

        //Saisie frequence de resonnance
        do{
            printf("Saisir la frequence de resonnance (fr) du filtre \n");
            printf("Frequence de resonnance (fr) en Hz : ");
            scanf("%f", &filtre->fr);

            if(filtre->fr>0)
            {
                booleen=VRAI;
            }
            else
            {
                printf("Valeur de la frequence de resonnance (fr) invalide (<0) \n");
            }
        }while(booleen==FAUX);

    }

}

void saisie_compo_prio(filtre *filtre)
{
    Booleen booleen=FAUX;

    do{
        printf("Choissisez l'element prioritaire \n");
        printf("AUCUN=0 \n RESISTANCE=1\n CONDENSATEUR=2\n BOBINE=3\n");
        printf("Element prioritaire : ");
        scanf("%i", &filtre->Ele_prio);

        if((filtre->Ele_prio==0) || (filtre->Ele_prio==1) || (filtre->Ele_prio==2) || (filtre->Ele_prio==3))
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur du mode non valide \n");
        }
    }while(booleen==FAUX);
}

void saisie_decade_R_dispo(filtre *filtre)
{
    Booleen booleen=FAUX;

    do{
        printf("Choissisez la decade de resistance en stock \n");
        printf("Decade E3=3 \n Decade E6=6\n Decade E12=12\n Decade E24=24\n");
        printf("Decade de resistance : ");
        scanf("%i", &filtre->R_dispo.decade);

        if((filtre->R_dispo.decade==3) || (filtre->R_dispo.decade==6) || (filtre->R_dispo.decade==12) || (filtre->R_dispo.decade==24))
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur de la decade non valide \n");
        }
    }while(booleen==FAUX);
}

void saisie_pui_10_R_dispo(filtre *filtre)
{
    Booleen booleen=FAUX;

    do{
        printf("Choissisez la puissance maximale de la decade en stock \n");
        printf("Puissance >=0\n");
        printf("Puissance de la decade : ");
        scanf("%i", &filtre->R_dispo.pui_de_10_max);

        if(filtre->R_dispo.pui_de_10_max>=0)
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur de la puissance maximale non valide \n");
        }
    }while(booleen==FAUX);
}

void montage_choisi(filtre filtre)
{

    if(filtre.ordre==1)
    {
        switch (filtre.type_filtre) //Filtres du 1er ordre
        {
            case PASSE_BAS :
            {
                printf("               --------- \n");
                printf("---------------|   R   |------------------------ \n");
                printf("|              ---------        |              | \n");
                printf("|                               |              | \n");
                printf("|                               |              | \n");
                printf("|                             -----            | \n");
                printf("|                             |   |            | \n");
                printf("Ve                            | C |            Vs \n");
                printf("|                             |   |            | \n");
                printf("|                             -----            | \n");
                printf("|                               |              | \n");
                printf("|                               |              | \n");
                printf("|                               |              | \n");
                printf("------------------------------------------------ \n");

                break;
            }
            case PASSE_HAUT :
            {
                printf("               --------- \n");
                printf("---------------|   C   |------------------------ \n");
                printf("|              ---------        |              | \n");
                printf("|                               |              | \n");
                printf("|                               |              | \n");
                printf("|                             -----            | \n");
                printf("|                             |   |            | \n");
                printf("Ve                            | R |            Vs \n");
                printf("|                             |   |            | \n");
                printf("|                             -----            | \n");
                printf("|                               |              | \n");
                printf("|                               |              | \n");
                printf("|                               |              | \n");
                printf("------------------------------------------------ \n");

                break;
            }
            case PASSE_BANDE :
            {
                printf("Impossible pour un filtre du premier ordre passif");
                break;
            }
            case COUPE_BANDE :
            {
                printf("Impossible pour un filtre du premier ordre passif");
                break;
            }
        }
    }
    else if(filtre.ordre==2) //Filtres du Second ordre
    {
        switch (filtre.type_filtre)
        {
            case PASSE_BAS :
            {
                printf("                                  <----Vs----- \n");
                printf("               ---------            --------- \n");
                printf("---------------|   L   |------------|   C   |-------- \n");
                printf("|              ---------            ---------       | \n");
                printf("|                                                   | \n");
                printf("|                                                   | \n");
                printf("|                                                 ----- \n");
                printf("|                                                 |   | \n");
                printf("Ve                                                | R | \n");
                printf("|                                                 |   | \n");
                printf("|                                                 ----- \n");
                printf("|                                                   | \n");
                printf("|                                                   | \n");
                printf("|                                                   | \n");
                printf("----------------------------------------------------- \n");

                break;
            }
            case PASSE_HAUT :
            {
                printf("             <----Vs----- \n");
                printf("               ---------            --------- \n");
                printf("---------------|   L   |------------|   C   |-------- \n");
                printf("|              ---------            ---------       | \n");
                printf("|                                                   | \n");
                printf("|                                                   | \n");
                printf("|                                                 ----- \n");
                printf("|                                                 |   | \n");
                printf("Ve                                                | R | \n");
                printf("|                                                 |   | \n");
                printf("|                                                 ----- \n");
                printf("|                                                   | \n");
                printf("|                                                   | \n");
                printf("|                                                   | \n");
                printf("----------------------------------------------------- \n");

                break;
            }
            case PASSE_BANDE :
            {
                printf("               ---------            --------- \n");
                printf("---------------|   L   |------------|   C   |------------------ \n");
                printf("|              ---------            ---------       |              | \n");
                printf("|                                                   |              | \n");
                printf("|                                                   |              | \n");
                printf("|                                                 -----            | \n");
                printf("|                                                 |   |            | \n");
                printf("Ve                                                | R |            Vs \n");
                printf("|                                                 |   |            | \n");
                printf("|                                                 -----            | \n");
                printf("|                                                   |              | \n");
                printf("|                                                   |              | \n");
                printf("|                                                   |              | \n");
                printf("-------------------------------------------------------------------- \n");

                break;
            }
            case COUPE_BANDE :
            {
                printf("            <----------------Vs---------------- \n");
                printf("               ---------            --------- \n");
                printf("---------------|   L   |------------|   C   |-------- \n");
                printf("|              ---------            ---------       | \n");
                printf("|                                                   | \n");
                printf("|                                                   | \n");
                printf("|                                                 ----- \n");
                printf("|                                                 |   | \n");
                printf("Ve                                                | R | \n");
                printf("|                                                 |   | \n");
                printf("|                                                 ----- \n");
                printf("|                                                   | \n");
                printf("|                                                   | \n");
                printf("|                                                   | \n");
                printf("----------------------------------------------------- \n");

                break;
            }
        }
    }
}

void montage_determine_exact(filtre filtre)
{

    if(filtre.ordre==1)
    {
        switch (filtre.type_filtre) //Filtres du 1er ordre
        {
            case PASSE_BAS :
            {
                printf("               ------------------------\n");
                printf("---------------|   R=%f*10pui%i Ohms  |--------------------------------- \n", filtre.compo_exact.R_exact*pow(10, -filtre.compo_exact.R_exact_pui), filtre.compo_exact.R_exact_pui);
                printf("|              ------------------------             |                  | \n");
                printf("|                                                   |                  | \n");
                printf("|                                                   |                  | \n");
                printf("|                                           ------------------         | \n");
                printf("|                                           |                |         | \n");
                printf("Ve                                          | C=%f*10pui%i F |         Vs \n", filtre.compo_exact.C_exact*pow(10, -filtre.compo_exact.C_exact_pui), filtre.compo_exact.C_exact_pui);
                printf("|                                           |                |         | \n");
                printf("|                                           ------------------         | \n");
                printf("|                                                   |                  | \n");
                printf("|                                                   |                  | \n");
                printf("|                                                   |                  | \n");
                printf("------------------------------------------------------------------------ \n");

                break;
            }
            case PASSE_HAUT :
            {
                printf("               ---------------------\n");
                printf("---------------|   C=%f*10pui%i F  |------------------------------------- \n", filtre.compo_exact.C_exact*pow(10, -filtre.compo_exact.C_exact_pui), filtre.compo_exact.C_exact_pui);
                printf("|              ---------------------                |                   | \n");
                printf("|                                                   |                   | \n");
                printf("|                                                   |                   | \n");
                printf("|                                         ---------------------         | \n");
                printf("Ve                                        | R=%f*10pui%i Ohms |         Vs \n", filtre.compo_exact.R_exact*pow(10, -filtre.compo_exact.R_exact_pui), filtre.compo_exact.R_exact_pui);
                printf("|                                         ---------------------         | \n");
                printf("|                                                   |                   | \n");
                printf("|                                                   |                   | \n");
                printf("|                                                   |                   | \n");
                printf("------------------------------------------------------------------------- \n");

                break;
            }
            case PASSE_BANDE :
            {
                printf("Impossible pour un filtre du premier ordre passif");
                break;
            }
            case COUPE_BANDE :
            {
                printf("Impossible pour un filtre du premier ordre passif");
                break;
            }
        }
    }
    else if(filtre.ordre==2) //Filtres du Second ordre
    {
        switch (filtre.type_filtre)
        {
            case PASSE_BAS :
            {
                printf("                                               <-----------Vs------------ \n");
                printf("               ----------------------            ---------------------- \n");
                printf("---------------|   L=%f*10pui%i H   |------------|   C=%f*10pui%i F   |---------- \n", filtre.compo_exact.L_exact*pow(10, -filtre.compo_exact.L_exact_pui), filtre.compo_exact.L_exact_pui, filtre.compo_exact.C_exact*pow(10, -filtre.compo_exact.C_exact_pui), filtre.compo_exact.C_exact_pui);
                printf("|              ----------------------            ----------------------         | \n");
                printf("|                                                                               | \n");
                printf("|                                                                               | \n");
                printf("|                                                                     --------------------- \n");
                printf("Ve                                                                    | R=%f*10pui%i Ohms | \n", filtre.compo_exact.R_exact*pow(10, -filtre.compo_exact.R_exact_pui), filtre.compo_exact.R_exact_pui);
                printf("|                                                                     --------------------- \n");
                printf("|                                                                               | \n");
                printf("|                                                                               | \n");
                printf("|                                                                               | \n");
                printf("--------------------------------------------------------------------------------- \n");

                break;
            }
            case PASSE_HAUT :
            {
                printf("             <-----------Vs----------- \n");
                printf("               ----------------------            ---------------------- \n");
                printf("---------------|   L=%f*10pui%i H   |------------|   C=%f*10pui%i F   |---------- \n", filtre.compo_exact.L_exact*pow(10, -filtre.compo_exact.L_exact_pui), filtre.compo_exact.L_exact_pui, filtre.compo_exact.C_exact*pow(10, -filtre.compo_exact.C_exact_pui), filtre.compo_exact.C_exact_pui);
                printf("|              ----------------------            ----------------------         | \n");
                printf("|                                                                               | \n");
                printf("|                                                                               | \n");
                printf("|                                                                     --------------------- \n");
                printf("Ve                                                                    | R=%f*10pui%i Ohms | \n", filtre.compo_exact.R_exact*pow(10, -filtre.compo_exact.R_exact_pui), filtre.compo_exact.R_exact_pui);
                printf("|                                                                     --------------------- \n");
                printf("|                                                                               | \n");
                printf("|                                                                               | \n");
                printf("|                                                                               | \n");
                printf("--------------------------------------------------------------------------------- \n");

                break;
            }
            case PASSE_BANDE :
            {
                printf("               ----------------------            ---------------------- \n");
                printf("---------------|   L=%f*10pui%i H   |------------|   C=%f*10pui%i F   |--------------------------- \n", filtre.compo_exact.L_exact*pow(10, -filtre.compo_exact.L_exact_pui), filtre.compo_exact.L_exact_pui, filtre.compo_exact.C_exact*pow(10, -filtre.compo_exact.C_exact_pui), filtre.compo_exact.C_exact_pui);
                printf("|              ----------------------            ----------------------       |                  | \n");
                printf("|                                                             |                                  | \n");
                printf("|                                                             |                                  | \n");
                printf("|                                                       ---------------------                    | \n");
                printf("Ve                                                      | R=%f*10pui%i Ohms |                    Vs \n", filtre.compo_exact.R_exact*pow(10, -filtre.compo_exact.R_exact_pui), filtre.compo_exact.R_exact_pui);
                printf("|                                                       ---------------------                    | \n");
                printf("|                                                             |                                  | \n");
                printf("|                                                             |                                  | \n");
                printf("|                                                             |                                  | \n");
                printf("-------------------------------------------------------------------------------------------------- \n");

                break;
            }
            case COUPE_BANDE :
            {
                printf("             <----------------------------Vs---------------------------- \n");
                printf("               ----------------------            ---------------------- \n");
                printf("---------------|   L=%f*10pui%i H   |------------|   C=%f*10pui%i F   |---------- \n", filtre.compo_exact.L_exact*pow(10, -filtre.compo_exact.L_exact_pui), filtre.compo_exact.L_exact_pui, filtre.compo_exact.C_exact*pow(10, -filtre.compo_exact.C_exact_pui), filtre.compo_exact.C_exact_pui);
                printf("|              ----------------------            ----------------------         | \n");
                printf("|                                                                               | \n");
                printf("|                                                                               | \n");
                printf("|                                                                       --------------------- \n");
                printf("Ve                                                                      | R=%f*10pui%i Ohms | \n", filtre.compo_exact.R_exact*pow(10, -filtre.compo_exact.R_exact_pui), filtre.compo_exact.R_exact_pui);
                printf("|                                                                       --------------------- \n");
                printf("|                                                                               | \n");
                printf("|                                                                               | \n");
                printf("|                                                                               | \n");
                printf("--------------------------------------------------------------------------------- \n");

                break;
            }
        }
    }
}












