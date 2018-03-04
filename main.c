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

    Initialisation_filtre(&filtre);
    //montage_choisi(filtre);
    /*filtre.ordre=1;
    filtre.type_filtre=PASSE_BAS;
    filtre.compo_exact.R_exact=19300;
    filtre.compo_exact.C_exact=33*pow(10, -9);
    filtre.compo_exact.L_exact=0;

    frequence_coupure(&filtre);

    printf("\n");*/

    filtre.fc=250;
    filtre.ordre=1;
    filtre.Ele_prio=AUCUN;
    filtre.type_filtre=PASSE_BAS;
    filtre.compo_exact.R_exact=900;
    filtre.compo_exact.C_exact=0;
    filtre.compo_exact.L_exact=0;

    calcul_composant_standard(&filtre);

    montage_determine_exact(filtre);

    Liberer_filtre(&filtre);

    return 0;
}
