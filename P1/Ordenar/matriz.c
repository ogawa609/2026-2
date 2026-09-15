#include <string.h>
#include "matriz.h"




struct Matriz
{
    int row;
    int clm;
    char*** mat;
};

/*
* @brief Cria uma matriz alocando memória para seus atributos
* @param row O número de linhas da matriz
* @param clm O número de colunas da matriz
* @return Retorna estrutura alocada na memória
*/
tMatriz* Create(int row, int clm)
{
    tMatriz* mat = malloc(sizeof(tMatriz));
    mat->clm = clm;
    mat->row = row;
    mat->mat = malloc(sizeof(char*)*row);

    for(int i=0;i<row;i++)
        mat->mat[i] = malloc(clm*sizeof(char*));

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<clm;j++)
            mat->mat[i][j] = calloc(151,sizeof(char));
    }

    return mat;
}

/*
* @brief Libera a memória alocada para a matriz
* @param mat Matriz que será liberada
*/
void FreeUp(tMatriz* mat)
{
    for(int i=0;i<mat->row;i++)
    {
        for(int j=0;j<mat->clm;j++)
        {
            free(mat->mat[i][j]);
        }
        free(mat->mat[i]);
            
    }

    free(mat->mat);
    free(mat);
}

/*
* @brief Adiciona um elemento na posição indicada da matriz
* @param mat Matriz na qual o elemento será adicionado
* @param row Linha na qual o elemento será inserido
* @param clm Coluna na qual o elemento será inserido
* @param name String que será adicionada à matriz
*/
void Add(tMatriz* mat, int row, int clm, char* name)
{
    strcpy(mat->mat[row][clm],name);

}

/*
* @brief Imprime os elementos da matriz
* @param mat Matriz que será impressa
*/
void PrintFunction(tMatriz* mat)
{
    for(int i=0;i<mat->row;i++)
    {
        for(int j=0;j<mat->clm;j++)
        {
            printf("%s ",mat->mat[i][j]);
        }

        printf("\n");
    }
}

/*
* @brief Ordena os elementos da matriz em ordem alfabética
* @param mat Matriz que será ordenada
*/
void GetInOrder(tMatriz* mat)
{
    for(int i=0;i<mat->row;i++)
    {
        for(int j=0;j<mat->clm;j++)
        {
            for(int k=i;k<mat->row;k++)
            {
                for(int l=0;l<mat->clm;l++)
                {
                    if (k == i && l <= j)
                    continue;

                    if(strcmp(mat->mat[i][j],mat->mat[k][l])>0)
                    {
                        char temp[151];
                        strcpy(temp,mat->mat[i][j]);
                        strcpy(mat->mat[i][j],mat->mat[k][l]);
                        strcpy(mat->mat[k][l],temp);
                    }
                }
            }
        }
    }
}

