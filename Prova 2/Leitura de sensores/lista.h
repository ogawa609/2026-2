#ifndef LISTA_H
#define LISTA_H

#include "pessoa.h"
#include "leitura.h"

typedef struct Lista tLista;
tLista* CriaLista();
void LiberaLista(tLista* l);
void InsereLista(tLista* l,tPessoa* p, char* nome);
void ImprimeLista(tLista* l);
void OrganizaLista(tLista* l);


#endif