#ifndef _MATRIZ_H
#define _MATRIZ_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz tMatriz;

tMatriz* CriaMatriz(int linha, int coluna);
void LiberaMatriz(tMatriz* mat);
void ImprimeMatriz(tMatriz* mat, FILE* a);
void ImprimirVisaoSubmatriz(tMatriz* mat, int linIni, int linFin, int colIni, int colFin,FILE* a);
void ImprimirQuadradas(tMatriz* mat, FILE* a);
void Inserir(tMatriz* mat,int l, int c, int e);
#endif
