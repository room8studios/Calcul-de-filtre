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
}

void calcul_composant_standard(filtre *filtre)
{
    //On calcul les composants exacts
    calcul_composant_exact(filtre);

    /**************Calcul des condensateurs standards************/
    int i=0, a=0, quotient=0, pui_10=0, pui_max=filtre->C_dispo.pui_de_10_max;
    /*float tmp_C=0;
    //On recupere la valeur du composant exact dans une variable temporaire
    tmp_C=filtre->compo_exact.C_exact;
    ////Rajouter pour les puissances de 10 des resistances des puissance moins quelquechose pour avoir des resistances en dessous de 100 ohms
    float tmp_C1, deca_C[]={9.1,8.2,7.5,6.8,6.2,5.6,5.1,4.7,4.3,3.9,3.6,3.3,3,2.7,2.4,2.2,2,1.8,1.6,1.5,1.3,1.2,1.1,1}; //Condensateurs 5% et 10%
    ///Probleme avec le modulo comme on a des float du coup il faut utiliser fmod dans la lib standards
    printf("tmp c %i", tmp_C);
    while((tmp_C!=0) && (pui_max>=0)) //On a >=0 car on fait 10 puissance quelque chose donc pour avec les chiffres standards de la decade il faut 10 puissance 0
    {
        //On calcul la puissance de 10 correspondante
        pui_10=pow(10, pui_max);
        i=0; ///On ne rentre plus dans la boucle apres avoir fait une puissnace de 10 pour la decade si on reinitialise pas la variable
        while((tmp_C!=0) && (i!=filtre->R_dispo.decade))
        {

            quotient=tmp_C/(deca_C[i]*pui_10); //On recupere le quotient de la fraction pour savoir combien de re«sistance on mets pour la valeur de tab[i]
            tmp_C1=tmp_C;
            tmp_C=fmod(tmp_C1,(deca_C[i]*pui_10)); //On recupere le reste de la fraction pour savoir combien d'ohms il nous reste
            //printf("tmp c %lf", tmp_C1);
            if(quotient!=0)
            {

                for(a=0 ; a<quotient ; a++)
                {
                    //On rajoute le nombre de resistance necessaires dans la liste
                    ajouteEnTete(&filtre->compo_aproxi.C_aproxi, (deca_C[i]*pui_10));
                }
            }
            i++;
        }
        pui_max--;
    }*/


    /**************Calcul des inductances standards************/
    float deca_L[]={9.1,8.2,7.5,6.8,6.2,5.6,5.1,4.7,4.3,3.9,3.6,3.3,3,2.7,2.4,2.2,2,1.8,1.6,1.5,1.3,1.2,1.1,1}; //Inductances 5% et 10%



    /**************Calcul des resistances standards************/
    int tmp_R=0;

    pui_max=filtre->R_dispo.pui_de_10_max;

    ///Attention a mettre les decades dans l'ordre decroissant pour avoir les plus grandes valeurs choisis en 1er
    int deca_E3[]={470,220,100}; //Decade E3 ±20%
    int deca_E6[]={600,470,330,220,150,100}; //Decade E6 ±10%
    int deca_E12[]={820,680,560,470,390,330,270,220,180,150,120,100}; //Decade E12 ±10%
    int deca_E24[]={910,820,750,680,620,560,510,470,430,390,360,330,300,270,240,220,200,180,160,150,130,120,110,100}; //Decade E24 ±5%
    ///Trouver une structure pour les decades



    //On recupere la valeur du composant exact dans une variable temporaire
    tmp_R=filtre->compo_exact.R_exact;

    switch (filtre->R_dispo.decade)
    {
        case 3: //Decade E3 ±20%
        {
            while((tmp_R!=0) && (pui_max>=0)) //On a >=0 car on fait 10 puissance quelque chose donc pour avec les chiffres standards de la decade il faut 10 puissance 0
            {
                //On calcul la puissance de 10 correspondante
                pui_10=pow(10, pui_max);
                i=0; ///On ne rentre plus dans la boucle apres avoir fait une puissnace de 10 pour la decade si on reinitialise pas la variable
                while((tmp_R!=0) && (i!=filtre->R_dispo.decade))
                {
                    quotient=tmp_R/(deca_E3[i]*pui_10); //On recupere le quotient de la fraction pour savoir combien de re«sistance on mets pour la valeur de tab[i]

                    tmp_R=tmp_R%(deca_E3[i]*pui_10); //On recupere le reste de la fraction pour savoir combien d'ohms il nous reste

                    if(quotient!=0)
                    {
                        for(a=0 ; a<quotient ; a++)
                        {
                            //On rajoute le nombre de resistance necessaires dans la liste
                            ajouteEnTete(&filtre->compo_aproxi.R_aproxi, (deca_E3[i]*pui_10));
                        }
                    }
                    i++;
                }
                pui_max--;
            }
            break;
        }

        case 6: //Decade E6 ±10%
        {

            while((tmp_R!=0) && (pui_max>=0)) //On a >=0 car on fait 10 puissance quelque chose donc pour avec les chiffres standards de la decade il faut 10 puissance 0
            {
                //On calcul la puissance de 10 correspondante
                pui_10=pow(10, pui_max);
                i=0; ///On ne rentre plus dans la boucle apres avoir fait une puissnace de 10 pour la decade si on reinitialise pas la variable
                while((tmp_R!=0) && (i!=filtre->R_dispo.decade))
                {
                    quotient=tmp_R/(deca_E6[i]*pui_10); //On recupere le quotient de la fraction pour savoir combien de re«sistance on mets pour la valeur de tab[i]

                    tmp_R=tmp_R%(deca_E6[i]*pui_10); //On recupere le reste de la fraction pour savoir combien d'ohms il nous reste

                    if(quotient!=0)
                    {
                        for(a=0 ; a<quotient ; a++)
                        {
                            //On rajoute le nombre de resistance necessaires dans la liste
                            ajouteEnTete(&filtre->compo_aproxi.R_aproxi, (deca_E6[i]*pui_10));
                        }
                    }
                    i++;
                }
                pui_max--;
            }
            break;
        }

        case 12: //Decade E12 ±10%
        {
            while((tmp_R!=0) && (pui_max>=0)) //On a >=0 car on fait 10 puissance quelque chose donc pour avec les chiffres standards de la decade il faut 10 puissance 0
            {
                //On calcul la puissance de 10 correspondante
                pui_10=pow(10, pui_max);
                i=0; ///On ne rentre plus dans la boucle apres avoir fait une puissnace de 10 pour la decade si on reinitialise pas la variable
                while((tmp_R!=0) && (i!=filtre->R_dispo.decade))
                {
                    quotient=tmp_R/(deca_E12[i]*pui_10); //On recupere le quotient de la fraction pour savoir combien de re«sistance on mets pour la valeur de tab[i]

                    tmp_R=tmp_R%(deca_E12[i]*pui_10); //On recupere le reste de la fraction pour savoir combien d'ohms il nous reste

                    if(quotient!=0)
                    {
                        for(a=0 ; a<quotient ; a++)
                        {
                            //On rajoute le nombre de resistance necessaires dans la liste
                            ajouteEnTete(&filtre->compo_aproxi.R_aproxi, (deca_E12[i]*pui_10));
                        }
                    }
                    i++;
                }
                pui_max--;
            }
            break;
        }

        case 24: //Decade E24 ±5%
        {
            while((tmp_R!=0) && (pui_max>=0)) //On a >=0 car on fait 10 puissance quelque chose donc pour avec les chiffres standards de la decade il faut 10 puissance 0
            {
                //On calcul la puissance de 10 correspondante
                pui_10=pow(10, pui_max);
                i=0; ///On ne rentre plus dans la boucle apres avoir fait une puissnace de 10 pour la decade si on reinitialise pas la variable
                while((tmp_R!=0) && (i!=filtre->R_dispo.decade))
                {
                    quotient=tmp_R/(deca_E24[i]*pui_10); //On recupere le quotient de la fraction pour savoir combien de re«sistance on mets pour la valeur de tab[i]

                    tmp_R=tmp_R%(deca_E24[i]*pui_10); //On recupere le reste de la fraction pour savoir combien d'ohms il nous reste

                    if(quotient!=0)
                    {
                        for(a=0 ; a<quotient ; a++)
                        {
                            //On rajoute le nombre de resistance necessaires dans la liste
                            ajouteEnTete(&filtre->compo_aproxi.R_aproxi, (deca_E24[i]*pui_10));
                        }
                    }
                    i++;
                }
                pui_max--;
            }
            break;
        }

        default:
        {
            printf("Decade non adequate");

            break;
        }
    }


    //On affiche la liste de resistances
    ///Attention a l'affichage final qui est inversÈ par rapport l'ajout dans la liste -> entrÈe dans la liste ordre decroissant -> affichage ordre croissant
    afficheListe_R(filtre->compo_aproxi.R_aproxi);

    detruireListe(&filtre->compo_aproxi.R_aproxi);
}
