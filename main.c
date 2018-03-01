#include <stdio.h>
#include <stdlib.h>
#include "determination.h"
#include "Initialisation.h"
#include "Interface.h"
#include "Calcul_filtre.h"


int main()
{
    filtre filtre;

    Initialisation_filtre(&filtre);
    montage_choisi(filtre);
    filtre.ordre=1;
    printf("ordre %i\n", filtre.ordre);
    filtre.type_filtre=PASSE_BAS;
    frequence_coupure(&filtre, 19300, 33*pow(10, -9), 0);



    return 0;
}
