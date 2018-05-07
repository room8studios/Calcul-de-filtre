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
    liste_composants_aproxi C_aproxi;
    liste_composants_aproxi L_aproxi;
}composants_aproxi;

/******Structure composants exacts******/
typedef struct
{
    resistance R_exact;
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

}filtre;

typedef int Element; ///Il sert vraiment ?


/*struct deca_R
{
    int deca_E3[]={100,220,470}; //Decade E3 �20%
    int deca_E6[]={600,470,330,220,150,100}; //Decade E6 �10%
    int deca_E12[]={100,120,150,180,220,270,330,390,470,560,680,820}; //Decade E12 �10%
    int deca_E24[]={100,110,120,130,150,160,180,200,220,240,270,300,330,360,390,430,470,510,560,620,680,750,820,910}; //Decade E24 �5%
};*/



#endif // STRUCTURES_INCLUDED
