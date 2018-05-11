#include <stdio.h>
#include <stdlib.h>
#include "determination.h"
#include "Initialisation.h"
#include "Interface.h"
#include "Calcul_filtre.h"


int main()
{

    ///Faire super gaffe au éléments prioritaire
    filtre filtre;
    Booleen quitter=FAUX;

    Initialisation_filtre(&filtre);

    ///Pour les phases de developpement decommenter le bloc en dessous et tout commenter ce qu'y est en-dessous du bloc commente
    /*filtre.fc=250;
    filtre.ordre=1;
    filtre.Ele_prio=AUCUN;
    filtre.type_filtre=PASSE_BAS;
    filtre.compo_exact.R_exact=900;
    filtre.compo_exact.C_exact=0;
    filtre.compo_exact.L_exact=0;
    calcul_composant_standard(&filtre);

    montage_determine_exact(filtre);*/

    do{
        saisie_filtre_souhaite(&filtre);
        strategie_resolution(&filtre);

        do{
            printf("Souhaitez-vous \"resoudre un autre filtre \" ? \n");
            printf("NON=0 \nOUI=1\n");
            printf("Quitter : ");
            scanf("%i", &quitter);

            //On verifie si on a aucun des 2 cas
            if((quitter!=FAUX) && (quitter!=VRAI))
            {
                printf("********Valeur non valide******** \n");
            }
        }while((quitter!=FAUX) && (quitter!=VRAI));
    }while(quitter==VRAI);

    return 0;
}
