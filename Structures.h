#ifndef STRUCTURES_INCLUDED
#define STRUCTURES_INCLUDED

#include "composants.h"

typedef enum{AUCUN, RESISTANCE, CONDENSATEUR, BOBINE}Element_prioritaire;
typedef enum{FAUX, VRAI}Booleen;

typedef struct
{
    int *R_aproxi;
    int taille_R_aproxi;
    capacite *C_aproxi;
    int taille_C_aproxi;
    inductance *L_aproxi;
    int taille_L_aproxi;
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

typedef int Element;



#endif // STRUCTURES_INCLUDED
