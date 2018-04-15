#include "determination.h"
#include "Liste_chainee.h"

void calcul_composant_exact(filtre *filtre)
{
    capacite C_defaut=33*pow(10,-9);

    if(filtre->Ele_prio==AUCUN)
    {
        filtre->compo_exact.C_exact=C_defaut;
        /*On regarde l'ordre du filtre*/
        if(filtre->ordre==1)
        {   /*On regarde le type de filtre*/
            switch(filtre->type_filtre)
            {
                case PASSE_BAS :
                {
                    filtre->compo_exact.R_exact=1/(2*M_PI*(filtre->fc)*(filtre->compo_exact.C_exact));
                    if(filtre->compo_exact.R_exact<=1)
                    {
                        filtre->compo_exact.R_exact=5;
                        filtre->compo_exact.C_exact=1/(2*M_PI*(filtre->fc)*(filtre->compo_exact.R_exact));
                    }

                    break;
                }
                case PASSE_HAUT :
                {
                    filtre->compo_exact.R_exact=1/(2*M_PI*(filtre->fc)*(filtre->compo_exact.C_exact));
                    if(filtre->compo_exact.R_exact<=1)
                    {
                        filtre->compo_exact.R_exact=5;
                        filtre->compo_exact.C_exact=1/(2*M_PI*(filtre->fc)*(filtre->compo_exact.R_exact));
                    }

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

                    break;
                }
                case PASSE_HAUT :
                {


                    break;
                }
                case PASSE_BANDE :
                {


                    break;
                }
                case COUPE_BANDE :
                {

                    break;
                }
            }

        }
        else
        {
            printf("Pour bientot !");
        }
    }
};

void calcul_composant_standard(filtre *filtre)
{
    int tab_deca[]={600,470,330,220,150,100}, i=0, a=0, tmp_R=0, quotient=0, num_decade; //tab_deca => Décade E6 ±10%

    ///Trouver une structure pour les décades
    num_decade=6;

    //On calcul les composants exacts
    calcul_composant_exact(filtre);

    //On récupère la valeur du composant exact dans une variable temporaire
    tmp_R=filtre->compo_exact.R_exact;

    while((tmp_R!=0) && (i!=num_decade))
    {
        quotient=tmp_R/tab_deca[i]; //On récupère le quotient de la fraction pour savoir combien de résistance on mets pour la valeur de tab[i]

        tmp_R=tmp_R%tab_deca[i]; //On récupère le reste de la fraction pour savoir combien d'ohms il nous reste

        if(quotient!=0)
        {
            for(a=0 ; a<quotient ; a++)
            {
                //On rajoute le nombre de résistance nécessaires dans la liste
                ajouteEnTete(&filtre->compo_aproxi.R_aproxi, tab_deca[i]);
            }
        }
        i++;
    }

    //On affiche la liste de résistances
    afficheListe_R(filtre->compo_aproxi.R_aproxi);

    detruireListe(&filtre->compo_aproxi.R_aproxi);
};


















