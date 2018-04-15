#include "Liste_chainee.h"

cellule_composants_aproxi* creerCellule(int composantAP);

void Init_Liste(liste_composants_aproxi *L)
{
    L->pt_tete=NULL;
}

int estVideListe(liste_composants_aproxi *L)
{
    //Retourne 1 si vŽrifie 0 sinon
    return L->pt_tete==NULL;
}

cellule_composants_aproxi* creerCellule(int composantAP)
{
    //On crŽe la cellule
    cellule_composants_aproxi *cell;
    cell=(cellule_composants_aproxi*) malloc(sizeof(cellule_composants_aproxi));
    cell->X=composantAP;
    cell->suivant=NULL;
    return cell;
}


void ajouteEnTete(liste_composants_aproxi *L, int X)
{
    cellule_composants_aproxi *p=creerCellule(X);

    //On vŽrifie si la liste est vide pour affecter les pointeurs
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

    //On vŽrifie si la liste est vide pour ne pas causer d'erreurs
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

    //On vŽrifie si la liste est vide pour afficher
    if(estVideListe(&L)==0)
    {
        while (p!=NULL)
        {
            printf("R%i=%i\n", i+1, p->X);

            p=p->suivant;

            i++;
        }

        printf("\n");

    }
    else
    {
        printf("\n pas de composant\n");
    }
}

void afficheListe_L(liste_composants_aproxi L)
{
    int i=0;
    cellule_composants_aproxi *p=L.pt_tete;

    //On vŽrifie si la liste est vide pour afficher
    if(estVideListe(&L)==0)
    {
        while (p!=NULL)
        {
            printf("L%i=%i\n", i+1, p->X);

            p=p->suivant;

            i++;
        }

        printf("\n");

    }
    else
    {
        printf("\n pas de composant\n");
    }
}

void afficheListe_C(liste_composants_aproxi L)
{
    int i=0;
    cellule_composants_aproxi *p=L.pt_tete;

    //On vŽrifie si la liste est vide pour afficher
    if(estVideListe(&L)==0)
    {
        while (p!=NULL)
        {
            printf("C%i=%i\n", i+1, p->X);

            p=p->suivant;

            i++;
        }

        printf("\n");

    }
    else
    {
        printf("\n pas de composant\n");
    }
}
