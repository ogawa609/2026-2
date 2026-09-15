#include "matriz.h"

struct Matriz 
{
    int linha;
    int coluna;
    int **matriz;
};

tMatriz* CriaMatriz(int linha, int coluna)
{
    tMatriz* m = malloc(sizeof(tMatriz));
    m->coluna = coluna;
    m->linha = linha;

    m->matriz = malloc(linha*sizeof(int*));
    for(int i=0;i<linha;i++)
        m->matriz[i] = calloc(coluna,sizeof(int));

    return m;
}
void LiberaMatriz(tMatriz* mat)
{
    for(int i=0;i<mat->linha;i++)
        free(mat->matriz[i]);
    
    free(mat->matriz);
    free(mat);
}

void ImprimeMatriz(tMatriz* mat, FILE* a)
{

    fprintf(a,"Matriz Original:\n");
    for(int i=0;i<mat->linha;i++)
    {
        for(int j=0;j<mat->coluna;j++ )
        {
            fprintf(a,"%d ",mat->matriz[i][j]);
        }
        fprintf(a,"\n");
    }

    fprintf(a,"\n");
}
void ImprimirVisaoSubmatriz(tMatriz* mat, int linIni, int linFin, int colIni, int colFin,FILE* a)
{
    fprintf(a,"Visão Submatriz %d-%d %d-%d:\n",linIni,linFin,colIni,colFin);
    for(int i=linIni;i<=linFin;i++)
    {
        for(int j=colIni;j<=colFin;j++)
        {
            fprintf(a,"%d ",mat->matriz[i][j]);
        }
        fprintf(a,"\n");
    }

    fprintf(a,"\n");
}

void ImprimirQuadradas(tMatriz* mat,FILE* a)
{

    int quadrado = 0;
    for(int i=0;i<mat->linha;i++)
    {
        for(int j=0;j<mat->coluna;j++)
        {
            quadrado = 0;
            while(1)
            {

                if((i+quadrado<mat->linha)&&(j+quadrado<mat->coluna))
                {

                    fprintf(a,"Submatriz quadrada %dx%d em (%d,%d):\n",quadrado,quadrado,i,j);
                    for(int k=i;k<=i+quadrado;k++)
                    {
                        for(int l=j;l<=j+quadrado;l++)
                        {
                            fprintf(a,"%d ",mat->matriz[k][l]);
                        }
                        fprintf(a,"\n");
                    }
                    fprintf(a,"\n");

                }
                else
                    break;

                quadrado++;

            }

        }
    }
}

void Inserir(tMatriz* mat,int l, int c, int e)
{
    mat->matriz[l][c] = e;
}