#ifndef LISTE_CHAINEE_H_INCLUDED
#define LISTE_CHAINEE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
* @return Entier
*/
int estVideListe(liste_composants_aproxi *L);

/**
* @brief Creation cellule de la liste
*
* @param valeur Float
* @param puis_10 Entier
*/
cellule_composants_aproxi *creerCellule(float valeur, int puis_10);

/**
* @brief Ajout d'une cellule en tete de liste
*
* @param L Pointeur sur liste composants aproximatifs
* @param X Float
* @param puis_10 Entier
*/
void ajouteEnTete(liste_composants_aproxi *L, float X, int puis_10);

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

/**
* @brief Somme les elements de la liste
*
* @param L Liste composants aproximatifs
* @return Float
*/
float Somme_liste(liste_composants_aproxi L);

#endif // LISTE_CHAINEE_H_INCLUDED
