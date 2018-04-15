#ifndef STRUCTURES_INCLUDED
#define STRUCTURES_INCLUDED

/******Liste Chainee*******/
struct cellule_composants_aproxi
{
   int X;
   struct cellule_composants_aproxi *suivant;
   struct cellule_composants_aproxi *precedent;
};

typedef struct cellule_composants_aproxi cellule_composants_aproxi;

typedef struct
{
    cellule_composants_aproxi* pt_tete;
}liste_composants_aproxi;

/*******Type de composants******/
typedef float resistance;
typedef resistance resistance;
typedef float capacite;
typedef capacite capacite;
typedef float inductance;
typedef inductance inductance;
typedef float frequence;
typedef frequence frequence;
typedef int ordre;
typedef ordre ordre;
typedef enum {PASSE_BAS, PASSE_HAUT, PASSE_BANDE, COUPE_BANDE}type_filtre; //passe_bas=0, passe_haut=1, passe_bande=2, coupe_bande=3


typedef enum{AUCUN, RESISTANCE, CONDENSATEUR, BOBINE}Element_prioritaire;
typedef enum{FAUX, VRAI}Booleen;

typedef struct
{
    liste_composants_aproxi R_aproxi;
    liste_composants_aproxi C_aproxi;
    liste_composants_aproxi L_aproxi;
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
