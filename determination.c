#include"composants.h"
#include<stdio.h>
#include<stdlib.h>

void calcul_composant(frequence f, ordre a, type_filtre p, capacite*C, resistance*R, inductance*L, int x)//x=0->pas de composant particulier
{
    if(x==0)
    {
        if(p==0&&a==1)
        {
            C=&(33*pow(10,-9));
            R=(&1/(2*f*(*C)));
            if(*R<=1)
            {
                R=&5;
                C=&(1/(2*f*(*R)));
            }
        }
        if(p==1&&a==1)
        {

        }
    }

}
