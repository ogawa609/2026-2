#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"


int main()
{
    int qual;
    printf("Digite 1,2 ou 3 para a entrada desejada\n\n");
    scanf("%d",&qual);

    char caminho[50];
    if(qual==1)
        strcpy(caminho,"entrada1.txt");
    else if(qual==2)
        strcpy(caminho,"entrada2.txt");
    else if(qual==3)
        strcpy(caminho,"entrada3.txt");
    else
        printf("Invalido\n");

    FILE* arq = fopen(caminho,"r");

    int linha,coluna;
    fscanf(arq,"%d",&linha);
    fscanf(arq,"%d",&coluna);

    tMatriz* mat = CriaMatriz(linha,coluna);

    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
        {
            int elem;
            fscanf(arq,"%d",&elem);
            Inserir(mat,i,j,elem);
        }
    }

    int li,lf,ci,cf;
    fscanf(arq,"%d %d %d %d",&li,&lf,&ci,&cf);

    fclose(arq);
    FILE* arq2 = fopen("saidaProg.txt","w");

    ImprimeMatriz(mat,arq2);
    ImprimirVisaoSubmatriz(mat,li,lf,ci,cf,arq2);
    ImprimirQuadradas(mat,arq2);

    fclose(arq2);
    LiberaMatriz(mat);

    return 0;
}