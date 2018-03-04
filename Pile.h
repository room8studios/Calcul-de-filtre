#ifndef _PILEH_
#define _PILEH_

#include "Structures.h"

typedef struct Pile
{
    int taille;
    Element *tab;
    int sommet;
}Pile;

typedef struct Pile Pile;

void initPile(Pile*, int taille_voulue);
void libererPile(Pile *p);
int estVidePile(Pile p);
int estPleinePile(Pile p);
int empiler(Pile *pile,Element element);
int depiler(Pile *pile);

#endif
