#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "questao.h"

typedef struct Celula tCel;

struct Celula
{
    tCel* proxima;
    tQuestao* questao;
};

struct Lista 
{
    tCel* primeira;
    tCel* ultima;

    char* nome;
};

    tLista* CriaLista(char* nome)
    {
        tLista* l = mallloc(sizeof(tLista));
        l->primeira = NULL;
        l->ultima = NULL;

        l->nome = strdup(nome);

        return l;
    }

    void InsereLista(tLista* l, tQuestao* q)
    {

        tCel* c = malloc(sizeof(tCel));
        c->questao = q;
        c->proxima = NULL;


        if(l->primeira==NULL)
        {
            l->primeira = c;
            l->ultima = c;
            return;
        }

        l->ultima->proxima = c;
        l->ultima = c;
    }

    tQuestao* BuscaQuestao(tLista* l, char* id)
    {
        tCel* atual = l->primeira;
        if(atual==NULL)
            return;
        
        while(1)
        {
            if(atual==NULL)
                break;
            if(strcmp(GetIdQuest(atual->questao),id)==0)
                return atual->questao;

            atual = atual->proxima;
        }

        return NULL;
    }
    
    void LiberaListaTotal(tLista*l);
    void ImprimeProva(tLista* l);
    tLista* CriaMerge(tLista* l1, tLista* l2);
    void RetiraRepetido(tLista* l);
    void LiberaListaParcial(tLista* l);