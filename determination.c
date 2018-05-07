#include "determination.h"
#include "Liste_chainee.h"

void calcul_composant_exact(filtre *filtre)
{
    capacite C_defaut=33*pow(10,-9);
    float tmp_C;

    if(filtre->Ele_prio==AUCUN)
    {
        filtre->compo_exact.C_exact=C_defaut;
        filtre->compo_exact.C_exact_pui=-9;
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

                        //On regarde la puissance a mettre pour C
                        tmp_C=filtre->compo_exact.C_exact;
                        filtre->compo_exact.C_exact=0;
                        while(tmp_C<=1)
                        {
                            tmp_C=tmp_C*10;
                            filtre->compo_exact.C_exact--;
                        }
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
    int i=0, a=0, b=0, nb_tab /*Nombre de fois a mettre dans le tableau*/;
    int pui_tmp=0, pui_10=0, pui_delta=0, pui_max=filtre->compo_exact.C_exact_pui /*Puissance maximale necessaire*/, pui_mini=filtre->C_dispo.pui_de_10_max /*Puissance minimale disponible*/;
    float tmp_C=0 /*Valeur courante du composant exact*/, tmp_C_prece=0 /*Valeur precedente du composant exact*/;
    //On recupere la valeur du composant exact dans une variable temporaire
    /*pui_max=-12;
    tmp_C=600.3;*/
    tmp_C=filtre->compo_exact.C_exact*pow(10, -filtre->compo_exact.C_exact_pui);

    float deca_C[]={9.1,8.2,7.5,6.8,6.2,5.6,5.1,4.7,4.3,3.9,3.6,3.3,3,2.7,2.4,2.2,2,1.8,1.6,1.5,1.3,1.2,1.1,1}; //Condensateurs 5% et 10%
    pui_tmp=pui_max;
    //On regarde quelle est la puissance standard la plus proche et on converti
    if((pui_tmp==-1) || (pui_tmp==-2) || (pui_tmp==-3))
    {
        pui_tmp=-3;
    }
    else if((pui_tmp==-4) || (pui_tmp==-5) || (pui_tmp==-6))
    {
        pui_tmp=-6;
    }
    else if((pui_tmp==-7) || (pui_tmp==-8) || (pui_tmp==-9))
    {
        pui_tmp=-9;
    }
    else if((pui_tmp==-10) || (pui_tmp==-11) || (pui_tmp==-12))
    {
        pui_tmp=-12;
    }

    //On calcul le delta entre les 2 puissances pour convertir
    pui_delta=-pui_tmp+pui_max;
    //On remplace la puissance maximale par la nouvelle puissance
    pui_max=pui_tmp;

    //On converti les puissances
    tmp_C=tmp_C*pow(10, pui_delta);



    while((tmp_C!=0) && (pui_max>=pui_mini)) /*On a pui_max>=pui_mini car on prends que les valeurs entre puissances disponibles et celle necessaires*/
    {

        for(b=2; b>=0; b--) //On finit a 0 pour avoir les valeurs standards de la decades, on va du plus grand au plus petit
        {
            i=0; //On ne rentre plus dans la boucle apres avoir fait une puissnace de 10 pour la decade si on reinitialise pas la variable

            while(i!=filtre->C_dispo.decade)
            {
                nb_tab=0;
                while(tmp_C>=0)
                {
                    tmp_C_prece=tmp_C;
                    //On regarde si la valeur peut etre soustraite du composant exact
                    tmp_C=tmp_C-(deca_C[i]*pow(10, b));
                    if(tmp_C>=0)
                    {
                        //On ajoute si la valeur temporaire est superieure a 0 si oui on a pu retrancher donc on peut ajouter la valeur
                        nb_tab++;
                    }
                }
                for(a=0 ; a<nb_tab ; a++)
                {
                    //On rajoute le nombre de resistance necessaires dans la liste
                    ajouteEnTete(&filtre->compo_aproxi.C_aproxi, (deca_C[i]*pow(10, b)), pui_max);
                }
                //On reviens en arriere si on a pas pu retrancher
                tmp_C=tmp_C_prece;

                i++;
            }
        }
        pui_max=pui_max-3; //-3 pour avoir pico nano micro sans passer par les sous-multiples
    }


    /**************Calcul des inductances standards************/
    float deca_L[]={9.1,8.2,7.5,6.8,6.2,5.6,5.1,4.7,4.3,3.9,3.6,3.3,3,2.7,2.4,2.2,2,1.8,1.6,1.5,1.3,1.2,1.1,1}; //Inductances 5% et 10%
    pui_max=filtre->compo_exact.L_exact_pui; /*Puissance maximale necessaire*/
    pui_mini=filtre->L_dispo.pui_de_10_max; /*Puissance minimale disponible*/;
    float tmp_L=0 /*Valeur courante du composant exact*/, tmp_L_prece=0 /*Valeur precedente du composant exact*/;
    //On recupere la valeur du composant exact dans une variable temporaire
    /*pui_max=-12;
    tmp_L=600.3;*/
    tmp_L=filtre->compo_exact.L_exact*pow(10, -filtre->compo_exact.L_exact_pui);

    pui_tmp=pui_max;
    //On regarde quelle est la puissance standard la plus proche et on converti
    if((pui_tmp==-1) || (pui_tmp==-2) || (pui_tmp==-3))
    {
        pui_tmp=-3;
    }
    else if((pui_tmp==-4) || (pui_tmp==-5) || (pui_tmp==-6))
    {
        pui_tmp=-6;
    }
    else if((pui_tmp==-7) || (pui_tmp==-8) || (pui_tmp==-9))
    {
        pui_tmp=-9;
    }
    else if((pui_tmp==-10) || (pui_tmp==-11) || (pui_tmp==-12))
    {
        pui_tmp=-12;
    }

    //On calcul le delta entre les 2 puissances pour convertir
    pui_delta=-pui_tmp+pui_max;
    //On remplace la puissance maximale par la nouvelle puissance
    pui_max=pui_tmp;

    //On converti les puissances
    tmp_L=tmp_L*pow(10, pui_delta);

    while((tmp_L!=0) && (pui_max>=pui_mini)) /*On a pui_max>=pui_mini car on prends que les valeurs entre puissances disponibles et celle necessaires*/
    {
        for(b=2; b>=0; b--) //On finit a 0 pour avoir les valeurs standards de la decades, on va du plus grand au plus petit
        {
            i=0; //On ne rentre plus dans la boucle apres avoir fait une puissnace de 10 pour la decade si on reinitialise pas la variable

            while(i!=filtre->L_dispo.decade)
            {
                nb_tab=0;
                while(tmp_L>=0)
                {
                    tmp_L_prece=tmp_L;
                    //On regarde si la valeur peut etre soustraite du composant exact
                    tmp_L=tmp_L-(deca_L[i]*pow(10, b));
                    if(tmp_L>=0)
                    {
                        //On ajoute si la valeur temporaire est superieure a 0 si oui on a pu retrancher donc on peut ajouter la valeur
                        nb_tab++;
                    }
                }
                for(a=0 ; a<nb_tab ; a++)
                {
                    //On rajoute le nombre de resistance necessaires dans la liste
                    ajouteEnTete(&filtre->compo_aproxi.L_aproxi, (deca_L[i]*pow(10, b)), pui_max);
                }
                //On reviens en arriere si on a pas pu retrancher
                tmp_L=tmp_L_prece;

                i++;
            }
        }
        pui_max=pui_max-3; //-3 pour avoir pico nano micro sans passer par les sous-multiples
    }



    /**************Calcul des resistances standards************/
    int tmp_R=0, quotient=0 /*Pour resistances*/;

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
        case 3: /*******Decade E3 ±20%*******/
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
                            ajouteEnTete(&filtre->compo_aproxi.R_aproxi, (deca_E3[i]*pui_10), pui_max);
                        }
                    }
                    i++;
                }
                pui_max--;
            }
            break;
        }

        case 6: /********Decade E6 ±10%********/
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
                            ajouteEnTete(&filtre->compo_aproxi.R_aproxi, (deca_E6[i]*pui_10), pui_max);
                        }
                    }
                    i++;
                }
                pui_max--;
            }
            break;
        }

        case 12: /*********Decade E12 ±10%**********/
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
                            ajouteEnTete(&filtre->compo_aproxi.R_aproxi, (deca_E12[i]*pui_10), pui_max);
                        }
                    }
                    i++;
                }
                pui_max--;
            }
            break;
        }

        case 24: /**********Decade E24 ±5%**********/
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
                            ajouteEnTete(&filtre->compo_aproxi.R_aproxi, (deca_E24[i]*pui_10), pui_max);
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
    afficheListe_C(filtre->compo_aproxi.C_aproxi);
    afficheListe_L(filtre->compo_aproxi.L_aproxi);

    detruireListe(&filtre->compo_aproxi.R_aproxi);
    detruireListe(&filtre->compo_aproxi.C_aproxi);
    detruireListe(&filtre->compo_aproxi.L_aproxi);
}
