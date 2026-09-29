#ifndef _LISTA_H
#define _LISTA_H

#include "questao.h"

    typedef struct Lista tLista;
    tLista* CriaLista(char* nome);
    void InsereLista(tLista* lista, tQuestao* questao);
    void LiberaLista(tLista* lista);
    void RetiraLista(tLista* lista, char* id);
    void ImprimeLista(tLista* lista);
    tLista* CriarMerge(tLista* l1, tLista* l2);


#endif