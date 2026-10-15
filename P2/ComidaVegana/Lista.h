#ifndef _LISTA_H
#define _LISTA_H

typedef struct Lista tLista;
tLista* CriaLista();
void LiberaLista(tLista* l);
void InsereLista(tLista* l, void* elem,int id);
int RetiraLista(tLista* l, char* nome);

#endif