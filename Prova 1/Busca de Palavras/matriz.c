#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

struct Matriz
{
    int linha;
    int coluna;
    char ***palavras;
};

tMatriz* CriaMatriz(int linha,int coluna)
{
     tMatriz* m = malloc(sizeof(tMatriz));
     m->coluna = coluna;
     m->linha = linha;

     m->palavras = malloc(linha*sizeof(char*));
     for(int i=0;i<linha;i++)
        m->palavras[i] = malloc(coluna*sizeof(char*));

    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
            m->palavras[i][j] = calloc(150,sizeof(char));
        
    }

    return m;

}
    void ImprimeMatriz(tMatriz* m)
    {
        printf("=========================================================================\n\n");
        for(int i=0;i<m->linha;i++)
        {
            for(int j=0;j<m->coluna;j++)
            {
                printf("%s ",m->palavras[i][j]);
            }

            printf("\n");
        }

        printf("=========================================================================\n\n");
    }
    void InserirMatriz(tMatriz* m, int lin, int col, char* nome)
    {
        strcpy(m->palavras[lin][col],nome);
    }

    void LiberaMatriz(tMatriz* m)
    {
        for(int i=0;i<m->linha;i++)
        {
            for(int j=0;j<m->coluna;j++)
            {
                free(m->palavras[i][j]);
            }

            free(m->palavras[i]);
        }

        free(m->palavras);
        free(m);
    }
    int BuscaPalavra(tMatriz* m)
    {
        char palavra[150];
        printf("==> Digite a palavra para o caça-palavras ou 0, caso queira sair:\n\n");

        scanf("%s",palavra);

        if(strcmp(palavra,"0")==0)
        {
            printf("Program ended with exit code: 0\n");
            return 0;

        }

        int flag = 1;

        for(int i=0;i<m->linha;i++)
        {
            for(int j=0;j<m->coluna;j++)
            {
                if(strstr(m->palavras[i][j],palavra)!=NULL)
                {
                    printf("Palavra encontrada na posicao [%d][%d] :)!\n\n",i,j);
                    flag = 0;
                }
                
            }

        }

        if(flag)
             printf("Palavra não encontrada... :(\n");

        return 1;
    }
    