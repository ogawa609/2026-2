#ifndef _LISTA_H
#define _LISTA_H

#include "estudante.h"

typedef struct Lista tLista;

tLista* CriaLista();
void InsereEstudanteLista(tLista* lista,tEstudante* est);
void RetiraEstudanteLista(tLista* lista,int matricula);
void LiberaLista(tLista* lista);
void ImprimeLista(tLista* lista,FILE* f);
#endif