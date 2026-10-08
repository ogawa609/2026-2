#ifndef _LISTA_H
#define _LISTA_H
#include "questao.h"

    typedef struct Lista tLista;
    tLista* CriaLista(char* nome);
    void InsereLista(tLista* l, tQuestao* q);
    tQuestao* BuscaQuestao(tLista* l, char* id);
    void LiberaListaTotal(tLista*l);
    void ImprimeProva(tLista* l);
    tLista* CriaMerge(tLista* l1, tLista* l2);
    void RetiraRepetido(tLista* l);
    void LiberaListaParcial(tLista* l);
#endif