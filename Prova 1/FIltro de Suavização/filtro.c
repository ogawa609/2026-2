#include <stdio.h>
#include <stdlib.h>
#include "filtro.h"

struct Matriz
{
    int linha;
    int coluna;
    int **matriz;
};
    tMatriz* CriaMatriz(int linha, int coluna)
    {
        tMatriz* m = malloc(sizeof(tMatriz));

        if(m == NULL)
        {
            exit(1);
        }

        m->coluna = coluna;
        m->linha = linha;

        m->matriz = malloc(linha*sizeof(int*));
        for(int i=0;i<linha;i++)
            m->matriz[i] = calloc(coluna,sizeof(int));

        return m;
    }


    void ImprimeMatriz(tMatriz* mat,FILE* arq)
    {
        for(int i=0;i<mat->linha;i++)
        {
            for(int j=0;j<mat->coluna;j++)
            {
                fprintf(arq,"%d ",mat->matriz[i][j]);
            }

            fprintf(arq,"\n");
        }
    }
    void LiberaMatriz(tMatriz* mat)
    {

        if(mat != NULL)
        {
            for(int i=0;i<mat->linha;i++)
                free(mat->matriz[i]);
        
            free(mat->matriz);
            free(mat);
        }
    }

    tMatriz* SuavizaMatriz(tMatriz* mat)
    {
        tMatriz* suavizada = CriaMatriz(mat->linha,mat->coluna);

        for(int i=0;i<mat->linha;i++)
        {
            for(int j=0;j<mat->coluna;j++)
            {
                if(!(i==0||i==mat->linha-1||j==0||j==mat->coluna-1))
                {
                    int soma = 0;
                    int cont = 0;

                    for(int k=i-1;k<=i+1;k++)
                    {
                        for(int l=j-1;l<=j+1;l++)
                        {
                            soma += mat->matriz[k][l];
                            cont++;
                        }
                    }

                    suavizada->matriz[i][j] = soma/cont;
                }
                else
                    suavizada->matriz[i][j] = mat->matriz[i][j];
            }
        }

        return suavizada;
    }

    void Inserir(tMatriz* m, int linha,int coluna,int elemento)
    {
        
        m->matriz[linha][coluna] = elemento;
    }