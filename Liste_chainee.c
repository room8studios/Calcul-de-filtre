#include "Liste_chainee.h"

cellule_composants_aproxi* creerCellule(float valeur, int puis_10);

void Init_Liste(liste_composants_aproxi *L)
{
    L->pt_tete=NULL;
}

int estVideListe(liste_composants_aproxi *L)
{
    //Retourne 1 si verifie 0 sinon
    return L->pt_tete==NULL;
}

cellule_composants_aproxi* creerCellule(float valeur, int puis_10)
{
    //On cree la cellule
    cellule_composants_aproxi *cell;
    cell=(cellule_composants_aproxi*) malloc(sizeof(cellule_composants_aproxi));
    cell->X=valeur;
    cell->pui_10=puis_10;
    cell->suivant=NULL;
    return cell;
}


void ajouteEnTete(liste_composants_aproxi *L, float X, int puis_10)
{
    cellule_composants_aproxi *p=creerCellule(X, puis_10);

    //On vrifie si la liste est vide pour affecter les pointeurs
    if(estVideListe(L)==1)
    {
       p->suivant=NULL;
    }
    else
    {
        p->suivant=L->pt_tete;
    }

    p->precedent=NULL;
    L->pt_tete=p;
}

void detruireListe(liste_composants_aproxi *L)
{
    cellule_composants_aproxi* p;

    //On vrifie si la liste est vide pour ne pas causer d'erreurs
    if(estVideListe(L)==0)
    {
        while (L->pt_tete!=NULL)
        {
            p=L->pt_tete;
            L->pt_tete=L->pt_tete->suivant;
            free(p);
        }
    }

    Init_Liste(L);
}

///Deplacer la fonction dans l'interface ?
void afficheListe_R(liste_composants_aproxi L)
{
    int i=0;
    cellule_composants_aproxi *p=L.pt_tete;

    //On vrifie si la liste est vide pour afficher
    if(estVideListe(&L)==0)
    {
        printf("========Resistances standards========\n");
        printf("Pour obtenir la resistance equivalente il est necessaire de mettre les resistances en serie\n");
        while (p!=NULL)
        {
            printf("R%i=%lf*10 puissance %i\n", i+1, p->X*pow(10, -p->pui_10), p->pui_10);

            p=p->suivant;

            i++;
        }

        printf("\n");

    }
    else
    {
        printf("\n Aucune resistances (standards)\n\n");
    }
}

void afficheListe_L(liste_composants_aproxi L)
{
    int i=0;
    cellule_composants_aproxi *p=L.pt_tete;

    //On vrifie si la liste est vide pour afficher
    if(estVideListe(&L)==0)
    {
        printf("========Inductances standards========\n");
        printf("Pour obtenir l'inductance equivalente il est necessaire de mettre les inductances en serie\n");
        while (p!=NULL)
        {
            printf("L%i=%lf*10 puissance %i\n", i+1, p->X, p->pui_10);

            p=p->suivant;

            i++;
        }

        printf("\n");

    }
    else
    {
        printf("\n Aucune inductances (standards)\n\n");
    }
}

void afficheListe_C(liste_composants_aproxi L)
{
    int i=0;
    cellule_composants_aproxi *p=L.pt_tete;

    //On vrifie si la liste est vide pour afficher
    if(estVideListe(&L)==0)
    {
        printf("========Condensateurs standards========\n");
        printf("Pour obtenir le condensateur equivalent il est necessaire de mettre les condensateurs en parallele\n");
        while (p!=NULL)
        {

            printf("C%i=%lf*10 puissance %i\n", i+1, p->X, p->pui_10);

            p=p->suivant;

            i++;
        }

        printf("\n");

    }
    else
    {
        printf("\n Aucun condensateurs (standards)\n\n");
    }
}

float Somme_liste(liste_composants_aproxi L)
{
    int i=0;
    float somme=0;
    cellule_composants_aproxi *p=L.pt_tete;

    //On verifie si la liste est vide pour sommer
    if(estVideListe(&L)==0)
    {
        while (p!=NULL)
        {
            somme=somme+p->X;
            //printf("somme %lf", somme);
            p=p->suivant;

            i++;
        }

    }
    return somme;
}
