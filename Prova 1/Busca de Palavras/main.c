#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


int main()
{
    FILE* f = fopen("entrada","r");
    int linha = 0;
    int coluna = 0;
    fscanf(f,"%d",&linha);
    fscanf(f,"%d",&coluna);

    tMatriz* mat = CriaMatriz(linha,coluna);

    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
        {
            char nome[150];
            fscanf(f,"%s",nome);
            InserirMatriz(mat,i,j,nome);
        }
    }

    fclose(f);

    ImprimeMatriz(mat);

    printf("Digite 1 para sair do programa ou 2 para buscar uma palavra\n");
    int op;
    scanf("%d",&op);
    if(op==1)
    {
        printf("Program ended with exit code: 0\n");
        LiberaMatriz(mat);
        return 0;
    }
    else
    {
        while(1)
        {
            int flag = BuscaPalavra(mat);

            if(!flag)
                break;
        }
    }

    LiberaMatriz(mat);
    return 0;
}
