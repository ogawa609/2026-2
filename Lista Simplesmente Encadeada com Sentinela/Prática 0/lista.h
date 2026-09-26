#ifndef _LISTA_
#define _LISTA_
#include "aluno.h"

typedef struct Lista tLista;
typedef struct Celula tCelula;
tLista* CriaLista();
void InsereAluno(tLista* lista, tAluno* aluno );
void LiberaLista(tLista* lista);
void RetiraAluno(int matricula,tLista* lista);
tCelula* CriaCelula(tAluno* aluno);
void LiberaCelula(tCelula* cel);
void ImprimeLista(tLista* lista);


#endif