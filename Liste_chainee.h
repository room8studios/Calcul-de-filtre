#ifndef LISTE_CHAINEE_H_INCLUDED
#define LISTE_CHAINEE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"

/**
* @brief Initialisation de la liste chainee
*
* @param L Pointeur sur liste composants aproximatifs
*/
void Init_Liste(liste_composants_aproxi *L);

/**
* @brief Verification si la liste est vide
*
* @param L Pointeur sur liste composants aproximatifs
*/
int estVideListe(liste_composants_aproxi *L);

/**
* @brief Creation cellule de la liste
*
* @param composantAP Entier
*/
cellule_composants_aproxi *creerCellule(int composantAP);

/**
* @brief Ajout d'une cellule en tete de liste
*
* @param L Pointeur sur liste composants aproximatifs
* @param X Entier
*/
void ajouteEnTete(liste_composants_aproxi *L, int X);

/**
* @brief Destruction de la liste
*
* @param L Pointeur sur liste composants aproximatifs
*/
void detruireListe(liste_composants_aproxi *L);

/**
* @brief Affichage de la liste de resistances
*
* @param L Liste composants aproximatifs
*/
void afficheListe_R(liste_composants_aproxi L);

/**
* @brief Affichage de la liste d'inductances
*
* @param L Liste composants aproximatifs
*/
void afficheListe_L(liste_composants_aproxi L);

/**
* @brief Affichage de la liste de condensateurs
*
* @param L Liste composants aproximatifs
*/
void afficheListe_C(liste_composants_aproxi L);

#endif // LISTE_CHAINEE_H_INCLUDED
