#include <stdio.h>
#include <stdlib.h>
#include "determination.h"
#include "Initialisation.h"
#include "Interface.h"

int main()
{
    filtre filtre;

    Initialisation_filtre(&filtre);
    montage_choisi(filtre);



    return 0;
}
