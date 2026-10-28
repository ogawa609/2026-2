#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matriz.h"

struct Matriz
{
    char ***matriz;
    int linha,coluna;
};

    tMatriz* CriaMatriz(int linha,int coluna)
    {
        tMatriz* m = malloc(sizeof(tMatriz));
        m->matriz = malloc(linha*sizeof(char*));

        for(int i=0;i<linha;i++)
        {
            m->matriz[i] = malloc(coluna*sizeof(char*));
        }
        for(int i=0;i<linha;i++)
        {
            for(int j=0;j<coluna;j++)
            {
                m->matriz[i][j] = calloc(101,sizeof(char));
            }
        }
        m->coluna = coluna;
        m->linha = linha;
        return m;
    }

    void LiberaMatriz(tMatriz* m)
    {
        for(int i=0;i<m->linha;i++)
        {
            for(int j=0;j<m->coluna;j++)
            {
                free(m->matriz[i][j]);
            }
        }
        for(int i=0;i<m->linha;i++)
            free(m->matriz[i]);
        free(m->matriz);
        free(m);
    }
    void OrdenaAlfabeticamente(tMatriz* m)
    {
        for(int i=0;i<m->linha;i++)
        {
            for(int j=0;j<m->coluna;j++)
            {
                for(int k=0;k<m->linha;k++)
                {
                    for(int l=0;l<m->coluna;l++)
                    {
                        if(strcmp(m->matriz[i][j],m->matriz[k][l])<0)
                        {
                            char nome[101];
                            strcpy(nome,m->matriz[i][j]);
                            strcpy(m->matriz[i][j],m->matriz[k][l]);
                            strcpy(m->matriz[k][l],nome);
                        }
                    }
                }
            }
        }
    }
    tMatriz* Transposta(tMatriz* m)
    {
        tMatriz* trp = CriaMatriz(m->coluna,m->linha);

        for(int i=0;i<m->linha;i++)
        {
            for(int j=0;j<m->coluna;j++)
            {
                strcpy(trp->matriz[j][i],m->matriz[i][j]);
            }
        }

        return trp;
    }

    void Imprime(tMatriz* m)
    {
        for(int i=0;i<m->linha;i++)
        {
            for(int j=0;j<m->coluna;j++)
            {
                printf("%s ",m->matriz[i][j]);
            }
            printf("\n");
        }
    }

     void Adiciona(tMatriz* m,int linha,int coluna,char*nome)
     {
        strcpy(m->matriz[linha][coluna],nome);
     }