#ifndef LISTE_CHAINEE_H_INCLUDED
#define LISTE_CHAINEE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"

void Init_Liste(liste_composants_aproxi *L);

int estVideListe(liste_composants_aproxi *L);

cellule_composants_aproxi *creerCellule(int composantAP);

void ajouteEnTete(liste_composants_aproxi *L, int X);

void detruireListe(liste_composants_aproxi *L);

void afficheListe_R(liste_composants_aproxi L);

void afficheListe_L(liste_composants_aproxi L);

void afficheListe_C(liste_composants_aproxi L);

#endif // LISTE_CHAINEE_H_INCLUDED
