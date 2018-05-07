#include "Interface.h"

void saisie_filtre_souhaite(filtre *filtre)
{
    printf("==========Choix d'un filtre==============");
    printf("Voulez souhaitez un filtre d'ordre ? \n");
    scanf("%i", &filtre->ordre);
    printf("Voulez souhaitez quel type de filtre ? \n");
    printf("PASSE_BAS=0 \n PASSE_HAUT=1 \n PASEE_BANDE=2 \n");
    scanf("%i", &filtre->type_filtre);

}

resistance saisie_resistances(int i)
{
    resistance R=0;
    Booleen booleen=FAUX;

    do{
        printf("Saisir la resistance numero R%i \n", i);
        scanf("%f", &R);

        if(R>5)
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur de la resistance invalide ou trop faible \n");
        }
    }while(booleen==VRAI);

    return R;
}

capacite saisie_condensateur(int i)
{
    capacite C=0;
    Booleen booleen=FAUX;

    do{
        printf("Saisir le condensateur numero C%i \n", i);
        scanf("%f", &C);

        if(C>5)
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur du condensateur invalide ou trop faible \n");
        }
    }while(booleen==VRAI);

    return C;
}

inductance saisie_inductance(int i)
{
    inductance L=0;
    Booleen booleen=FAUX;

    do{
        printf("Saisir le condensateur numero C%i \n", i);
        scanf("%f", &L);

        if(L>5)
        {
            booleen=VRAI;
        }
        else
        {
            printf("Valeur du condensateur invalide ou trop faible \n");
        }
    }while(booleen==VRAI);

    return L;
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
                printf("               ---------------- \n");
                printf("---------------|   R=%f Ohms  |--------------------------------- \n", filtre.compo_exact.R_exact);
                printf("|              ----------------             |                  | \n");
                printf("|                                           |                  | \n");
                printf("|                                           |                  | \n");
                printf("|                                   ------------------         | \n");
                printf("|                                   |                |         | \n");
                printf("Ve                                  | C=%f*10pui%i F |         Vs \n", filtre.compo_exact.C_exact*pow(10, -filtre.compo_exact.C_exact_pui), filtre.compo_exact.C_exact_pui);
                printf("|                                   |                |         | \n");
                printf("|                                   ------------------         | \n");
                printf("|                                           |                  | \n");
                printf("|                                           |                  | \n");
                printf("|                                           |                  | \n");
                printf("---------------------------------------------------------------- \n");

                break;
            }
            case PASSE_HAUT :
            {
                printf("               -------------\n");
                printf("---------------|   C=%f F  |----------------------------------- \n", filtre.compo_exact.C_exact);
                printf("|              -------------                |                 | \n");
                printf("|                                           |                 | \n");
                printf("|                                           |                 | \n");
                printf("|                                       -------------         | \n");
                printf("Ve                                      | R=%f Ohms |         Vs \n", filtre.compo_exact.R_exact);
                printf("|                                       -------------         | \n");
                printf("|                                           |                 | \n");
                printf("|                                           |                 | \n");
                printf("|                                           |                 | \n");
                printf("--------------------------------------------------------------- \n");

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
                printf("                                       <------Vs-------- \n");
                printf("               --------------            -------------- \n");
                printf("---------------|   L=%f H   |------------|   C=%f F   |---------- \n", filtre.compo_exact.L_exact, filtre.compo_exact.C_exact);
                printf("|              --------------            --------------         | \n");
                printf("|                                                               | \n");
                printf("|                                                               | \n");
                printf("|                                                         ------------- \n");
                printf("Ve                                                        | R=%f Ohms | \n", filtre.compo_exact.R_exact);
                printf("|                                                         ------------- \n");
                printf("|                                                               | \n");
                printf("|                                                               | \n");
                printf("|                                                               | \n");
                printf("----------------------------------------------------------------- \n");

                break;
            }
            case PASSE_HAUT :
            {
                printf("             <----Vs---------- \n");
                printf("               --------------            -------------- \n");
                printf("---------------|   L=%f H   |------------|   C=%f F   |---------- \n", filtre.compo_exact.L_exact, filtre.compo_exact.C_exact);
                printf("|              --------------            --------------         | \n");
                printf("|                                                               | \n");
                printf("|                                                               | \n");
                printf("|                                                         ------------- \n");
                printf("Ve                                                        | R=%f Ohms | \n", filtre.compo_exact.R_exact);
                printf("|                                                         ------------- \n");
                printf("|                                                               | \n");
                printf("|                                                               | \n");
                printf("|                                                               | \n");
                printf("----------------------------------------------------------------- \n");

                break;
            }
            case PASSE_BANDE :
            {
                printf("               --------------            -------------- \n");
                printf("---------------|   L=%f H   |------------|   C=%f F   |--------------------------- \n", filtre.compo_exact.L_exact, filtre.compo_exact.C_exact);
                printf("|              --------------            --------------       |                  | \n");
                printf("|                                                             |                  | \n");
                printf("|                                                             |                  | \n");
                printf("|                                                       -------------            | \n");
                printf("Ve                                                      | R=%f Ohms |            Vs \n", filtre.compo_exact.R_exact);
                printf("|                                                       -------------            | \n");
                printf("|                                                             |                  | \n");
                printf("|                                                             |                  | \n");
                printf("|                                                             |                  | \n");
                printf("---------------------------------------------------------------------------------- \n");

                break;
            }
            case COUPE_BANDE :
            {
                printf("             <-------------------Vs--------------------- \n");
                printf("               --------------            -------------- \n");
                printf("---------------|   L=%f H   |------------|   C=%f F   |---------- \n", filtre.compo_exact.L_exact, filtre.compo_exact.C_exact);
                printf("|              --------------            --------------         | \n");
                printf("|                                                               | \n");
                printf("|                                                               | \n");
                printf("|                                                         ------------- \n");
                printf("Ve                                                        | R=%f Ohms | \n", filtre.compo_exact.R_exact);
                printf("|                                                         ------------- \n");
                printf("|                                                               | \n");
                printf("|                                                               | \n");
                printf("|                                                               | \n");
                printf("----------------------------------------------------------------- \n");

                break;
            }
        }
    }
}












