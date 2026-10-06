
#include "matriz.h"
#include <string.h>

struct Matriz
{
    int linha;
    int coluna;
    char ***matriz;
};

tMatriz* CriaMatriz(int linha, int coluna)
{
    tMatriz* m = malloc(sizeof(tMatriz));

    m->coluna = coluna;
    m->linha = linha;

    m->matriz = malloc(linha*sizeof(char*));

    for(int i=0;i<linha;i++)
        m->matriz[i] = calloc(coluna,(sizeof(char*)));

    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
        {
            m->matriz[i][j] = calloc(151,(sizeof(char)));
        }
    }

    return m;
}

void LiberaMatriz(tMatriz* mat)
{
    
    for(int i=0;i<mat->linha;i++)
    {
        for(int j=0;j<mat->coluna;j++)
        {
            free(mat->matriz[i][j]);

        }
        free(mat->matriz[i]);
    }
        
    free(mat->matriz);
    free(mat);

}

void InsereElemento(tMatriz* mat, int linha, int coluna, char* elem)
{
    strcpy(mat->matriz[linha][coluna],elem);
}

void ImprimeMatriz(tMatriz* mat, FILE* f)
{
    for(int i=0;i<mat->linha;i++)
    {
        for(int j=0;j<mat->coluna;j++)
        {
            fprintf(f,"%s ",mat->matriz[i][j]);
        }
        fprintf(f,"\n");
    }


}

tMatriz* CriaVisao(tMatriz* mat, int li,int lf, int ci, int cf)
{
    int linha = lf-li +1;
    int coluna = cf - ci +1;
    tMatriz* sub = malloc(sizeof(tMatriz));

    sub->coluna = coluna;
    sub->linha = linha;
    sub->matriz = malloc(linha*sizeof(char*));

    for(int i=0;i<linha;i++)
        sub->matriz[i] = calloc(coluna,sizeof(char*));

    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
        {
            sub->matriz[i][j]=mat->matriz[li+i][ci+j];
        }
    }

    return sub;
}

void ImprimeQuadrados(tMatriz* mat, FILE* s)
{
    for(int i=0;i<mat->linha;i++)
    {
        for(int j=0;j<mat->coluna;j++)
        {
            int quadrado = 0;

            while(1)
            {
                if((i+quadrado<mat->linha)&&(j+quadrado<mat->coluna))
                {
                    int li = i;
                    int lf = i + quadrado;
                    int ci= j;
                    int cf = j + quadrado;
                    tMatriz* sub = CriaVisao(mat,li,lf,ci,cf);
                    fprintf(s,"\nSubmatriz quadrada %dx%d em (%d,%d):\n",quadrado+1,quadrado+1,i,j);
                    ImprimeMatriz(sub,s);
                    LiberaSub(sub);
                }
                else
                    break;

                quadrado++;
            }
        }
    }
}

void LiberaSub(tMatriz* sub)
{
    for(int i=0;i<sub->linha;i++)
    {
        free(sub->matriz[i]);
    }

    free(sub->matriz);
    free(sub);
}


