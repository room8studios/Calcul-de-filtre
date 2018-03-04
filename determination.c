#include "determination.h"

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
    Pile p;
    ///Faire attention si pile est pleine faire une condition ?
    ///Faire ultra gaffe à la taille de la pile vérifier si on peut pas faire une pile avec allocation dynamique =>liste chainée ?

    initPile(&p, 130);

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
                //On rajoute le nombre de résistance nécessaires dans la pile
                empiler(&p, tab_deca[i]);
                //On incrémente la taille du tableau pour plus tard
                filtre->compo_aproxi.taille_R_aproxi++;

            }
        }
        i++;
    }

    //On alloue le tableau dynamique
    filtre->compo_aproxi.R_aproxi=malloc(filtre->compo_aproxi.taille_R_aproxi*sizeof(int));

    //On copie toutes les valeurs de la pile dans le tableau
    for(i=0; i < filtre->compo_aproxi.taille_R_aproxi; i++)
    {
        filtre->compo_aproxi.R_aproxi[i]=p.tab[i];
    }

    //On affiche le tableau de résistances
    ///Déplacer l'affichage des résistances dans l'interface ?
    printf("======Affichage tableau de resistance====== \n");

    for(i=0; i < filtre->compo_aproxi.taille_R_aproxi; i++)
    {
        printf("R%i=%i\n", i+1, filtre->compo_aproxi.R_aproxi[i]);
    }

    libererPile(&p);
};


















