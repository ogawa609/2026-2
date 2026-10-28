#ifndef _MATRIZ_H
#define _MATRIZ_H

#include <stdio.h>
#include <stdlib.h>

/*
* @file Matriz.h
* @brief Implementa funções de manipulações de matrizes com strings
*/

typedef struct Matriz tMatriz;

/*
* @brief Cria uma matriz alocando memória para seus atributos
* @param row O número de linhas da matriz
* @param clm O número de colunas da matriz
* @return Retorna estrutura alocada na memória
*/
tMatriz* Create(int row, int clm);

/*
* @brief Libera a memória alocada para a matriz
* @param mat Matriz que será liberada
*/
void FreeUp(tMatriz* mat);

/*
* @brief Adiciona um elemento na posição indicada da matriz
* @param mat Matriz na qual o elemento será adicionado
* @param row Linha na qual o elemento será inserido
* @param clm Coluna na qual o elemento será inserido
* @param name String que será adicionada à matriz
*/
void Add(tMatriz* mat, int row, int clm, char* name);

/*
* @brief Imprime os elementos da matriz
* @param mat Matriz que será impressa
*/
void PrintFunction(tMatriz* mat);

/*
* @brief Ordena os elementos da matriz em ordem alfabética
* @param mat Matriz que será ordenada
*/
void GetInOrder(tMatriz* mat);

#endif