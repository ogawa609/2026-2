#ifndef _FILTRO_H
#define _FILTRO_H
#include <stdlib.h>
#include <stdio.h>

    typedef struct Matriz tMatriz;

    tMatriz* CriaMatriz(int linha, int coluna);
    void ImprimeMatriz(tMatriz* mat,FILE* f);
    void LiberaMatriz(tMatriz* mat);
    tMatriz* SuavizaMatriz(tMatriz* mat);
    void Inserir(tMatriz* m, int linha,int coluna,int elemento);
#endif