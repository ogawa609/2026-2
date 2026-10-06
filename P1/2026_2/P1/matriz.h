#ifndef _MATRIZ_H
#define _MATRIZ_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz tMatriz;

tMatriz* CriaMatriz(int linha, int coluna);
void LiberaMatriz(tMatriz* mat);
void InsereElemento(tMatriz* mat, int linha, int coluna, char* elem);
void ImprimeMatriz(tMatriz* mat, FILE* arq);
tMatriz* CriaVisao(tMatriz* mat, int li,int lf, int ci, int cf);
void ImprimeQuadrados(tMatriz* mat, FILE* s);
void LiberaSub(tMatriz* sub);

#endif