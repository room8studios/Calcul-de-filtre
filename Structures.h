#ifndef STRUCTURES_INCLUDED
#define STRUCTURES_INCLUDED

/******Liste Chainee*******/
struct cellule_composants_aproxi
{
   float X;
   int pui_10;
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

/******Structure composants approximatifs******/
typedef struct
{
    liste_composants_aproxi R_aproxi;
    float R_pourc_erreur;
    liste_composants_aproxi C_aproxi;
    float C_pourc_erreur;
    liste_composants_aproxi L_aproxi;
    float L_pourc_erreur;
}composants_aproxi;

/******Structure composants exacts******/
typedef struct
{
    resistance R_exact;
    int R_exact_pui;
    capacite C_exact;
    int C_exact_pui;
    inductance L_exact;
    int L_exact_pui;
}composants_exacts;

/******Structure composants disponible*****/
typedef struct
{
    int decade;
    int pui_de_10_max;
}composants_dispo;

/******Structure filtre******/
typedef struct
{
    int ordre;
    type_filtre type_filtre;
    frequence fc;
    frequence fr;
    Element_prioritaire Ele_prio;
    float m;
    composants_dispo R_dispo;
    composants_dispo C_dispo;
    composants_dispo L_dispo;
    composants_aproxi compo_aproxi;
    composants_exacts compo_exact;
    int mode_resoulution;

}filtre;

typedef int Element; ///Il sert vraiment ?




#endif // STRUCTURES_INCLUDED
