#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct Celula tCel;

struct Celula
{
    tQuestao* questao;
    tCel* proxima;
};


struct Lista
{
    char* nome;

    tCel* primeira;
    tCel* ultima;
};

    tCel* CriaCelula(tQuestao* q)
    {
        tCel* c = malloc(sizeof(tCel));
        c->questao = q;
        c->proxima = NULL;
        return c;
    }

    void LiberaCel(tCel* cel)
    {
        LiberaQuestao(cel->questao);
        free(cel);
    }

    tLista* CriaLista(char* nome)
    {
        tLista* lista = malloc(sizeof(tLista));

        int tam = strlen(nome) + 1;
        lista->nome = calloc(tam,sizeof(char));
        strcpy(lista->nome,nome);


        lista->primeira = NULL;
        lista->ultima = NULL;

        return lista;
    }

    void InsereLista(tLista* lista, tQuestao* questao)
    {
        tCel* cel = CriaCelula(questao);

        if(lista->primeira==NULL)
        {
            lista->primeira = cel;
            lista->ultima = cel;
            return;
        }

        lista->ultima->proxima = cel;
        lista->ultima = cel;

    }

    void LiberaLista(tLista* lista)
    {
        tCel* atual = lista->primeira;
        tCel* prox = lista->primeira->proxima;
        while(1)
        {
            LiberaCel(atual);
            atual = prox;

            if(atual==NULL)
                break;

            prox = prox->proxima;
        }

        free(lista);
    }

    void RetiraLista(tLista* lista, char* id)
    {

        tCel* atual = lista->primeira;
        tCel* ant = NULL;

        while(1)
        {

            if(atual==NULL)
                break;

            if(strcmp(id,GetIdQuestao(atual->questao))==0)
            {
                if(atual==lista->primeira && atual==lista->ultima)
                {
                    lista->primeira = NULL;
                    lista->ultima = NULL;
                    LiberaCel(atual);
                    return;

                }

                else if(atual == lista->primeira)
                {
                    lista->primeira = atual->proxima;
                    LiberaCel(atual);
                    return;

                }

                else if(atual == lista->ultima)
                {
                    lista->ultima = ant;
                    ant->proxima = NULL;
                    LiberaCel(atual);
                    return;
                }

                else
                {
                    ant->proxima = atual->proxima;
                    LiberaCel(atual);
                    return;
                }
            }

            ant = atual;
            atual = atual->proxima;
        }
    }


    void ImprimeLista(tLista* lista)
    {
        printf("Prova: %s\n",lista->nome);
        tCel* atual = lista->primeira;

        while(1)
        {
            if(atual == NULL)
                break;

            ImprimeQuestao(atual->questao);

            atual = atual->proxima;
        }
    }

    tLista* CriarMerge(tLista* l1, tLista* l2)
    {
        tLista* merge = CriaLista("Merge");

        tCel* cel1 = l1->primeira;
        tCel* prox1 = cel1->proxima;
        tCel* cel2 = l2->primeira;
        
        merge->primeira = cel1;
       
        while(1)
        {
            if(cel1==NULL && cel2==NULL)
                break;

            

            
        }
    }