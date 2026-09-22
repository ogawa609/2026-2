#include <stdio.h>
#include "lista.h"


int main()
{
    tLista* l = CriaLista();
   
    for(int i=0;i<6;i++)
    {
        char nome[51];
        int mat;
        float cr;

        scanf("%d %s %f",&mat,nome,&cr);

        tEstudante*est = CriaEstudante(nome,mat,cr);
        InsereEstudanteLista(l,est);
        
    }

    ImprimeLista(l);
    LiberaLista(l);

    return 0;

}