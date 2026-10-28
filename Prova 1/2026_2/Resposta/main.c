#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{
    FILE* f = fopen("entrada.txt","r");

    int linha,coluna;
    linha = coluna = 0;

    fscanf(f,"%d %d",&linha,&coluna);
    tMatriz* mat = CriaMatriz(linha,coluna);

    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
        {
            char elemento[151];
            fscanf(f,"%s",elemento);
            InsereElemento(mat,i,j,elemento);
        }
    }

    int li,lf,ci,cf;
    li=lf=ci=cf=0;

    fscanf(f,"%d %d %d %d",&li,&lf,&ci,&cf);

    fclose(f);

    FILE* s = fopen("saida.txt","w");

    fprintf(s,"Matriz Original:\n");
    ImprimeMatriz(mat,s);

    fprintf(s,"\nVisão Submatriz %d-%d %d-%d:\n",li,lf,ci,cf);
    tMatriz* sub = CriaVisao(mat,li,lf,ci,cf);
    ImprimeMatriz(sub,s);
    
    ImprimeQuadrados(mat,s);

    fclose(s);

    LiberaSub(sub);
    LiberaMatriz(mat);

    return 0;
}

