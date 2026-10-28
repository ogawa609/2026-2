#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciar.h"
#include "matriz.h"

void Ativar()
{
    FILE* f = fopen("entrada","r");
    int linha,coluna;
    fscanf(f,"%d",&linha);
    fscanf(f,"%d",&coluna);

    tMatriz* mat = CriaMatriz(linha,coluna);

    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
        {
            char nome[101];
            fscanf(f,"%s",nome);
            Adiciona(mat,i,j,nome);
        }
    }

    fclose(f);

    tMatriz* trp = Transposta(mat);
    OrdenaAlfabeticamente(mat);

    printf("== Primeiro experimento:\n");
    Imprime(trp);

    printf("\n\n");

    printf("== Segundo experimento:\n");
    Imprime(mat);

    LiberaMatriz(trp);
    LiberaMatriz(mat);
    
}