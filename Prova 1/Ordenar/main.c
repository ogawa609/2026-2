#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int main()
{
    FILE* arq = fopen("entrada","r");

    int linha,coluna;

    fscanf(arq,"%d",&linha);
    fscanf(arq,"%d",&coluna);

    tMatriz* mat = Create(linha,coluna);

    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
        {
            char nome[151];
            fscanf(arq,"%s",nome);
            Add(mat,i,j,nome);
        }
    }

    fclose(arq);

    PrintFunction(mat);
    printf("==================================\n");
    GetInOrder(mat);
    PrintFunction(mat);
    printf("\n");
    FreeUp(mat);

    return 0;
}