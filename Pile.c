#include "Pile.h"
#include <stdlib.h>
#include <stdio.h>

int sommet_plus_un;

void initPile(Pile *p, int taille_voulue)
{
    (*p).taille=taille_voulue;
    (*p).sommet=0;
    (*p).tab=malloc(sizeof(Element)*taille_voulue);
}

void libererPile(Pile *p)
{
    free((*p).tab);
}

int estVidePile(Pile p)
{
    //Retourne 1 si la pile est vide 0 sinon
    return p.sommet==0;
}

int estPleinePile(Pile p)
{
    //Retourne 1 si la pile est pleine 0 sinon
    return p.sommet>=p.taille;
}

int empiler(Pile *pile, Element element)
{
    if(estPleinePile(*pile)==0)
    {
        (*pile).sommet=(*pile).sommet+1;
        (*pile).tab[(*pile).sommet-1]=element;
        //Retourne 1 si bien empilé
        return 1;
    }
    //Retourne 0 si mal empilé
    return 0;
}

int depiler(Pile *pile)
{
    (*pile).sommet=(*pile).sommet-1;
    return (*pile).tab[(*pile).sommet];
}
