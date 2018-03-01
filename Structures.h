#ifndef STRUCTURES_INCLUDED
#define STRUCTURES_INCLUDED

#include "composants.h"

typedef enum{AUCUN, RESISTANCE, CONDENSATEUR, BOBINE}Element_prioritaire;
typedef enum{FAUX, VRAI}Booleen;

typedef struct
{
    resistance R_aproxi[13];
    capacite C_aproxi[13];
    inductance L_aproxi[13];
}composants_aproxi;

typedef struct
{
    resistance R_exact;
    capacite C_exact;
    inductance L_exact;
}composants_exacts;

typedef struct
{
    int ordre;
    type_filtre type_filtre;
    frequence fc;
    frequence fr;
    Element_prioritaire Ele_prio;
    float m;
    composants_aproxi compo_aproxi;
    composants_exacts compo_exact;
}filtre;



#endif // STRUCTURES_INCLUDED
