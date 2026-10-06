#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

        if(atual!=NULL)
        {
            tCel* prox = lista->primeira->proxima;
            while(1)
            {
                LiberaCel(atual);
                atual = prox;

                if(atual==NULL)
                    break;

                prox = prox->proxima;
            }
        }
        free(lista->nome);
        free(lista);
    }

    void LiberaStructLIsta(tLista* l)
    {
        free(l->nome);
        free(l);
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
        tCel* cel1 = l1->primeira;
        tCel* cel2 = l2->primeira;

        if(cel1==NULL && cel2==NULL)
            return NULL;

        tLista* merge = CriaLista("Merge");

        if(cel1 == NULL)
        {
            merge->primeira = cel2;
            merge->ultima = l2->ultima;

             LiberaStructLIsta(l1);
             LiberaStructLIsta(l2);
            return merge;
        }
            
        else if(cel2 == NULL)
        {
             merge->primeira = cel1;
             merge->ultima = l1->ultima;
              LiberaStructLIsta(l1);
              LiberaStructLIsta(l2);
             return merge;
        }
           
        merge->primeira = cel1;
        merge->ultima = cel1;


        tCel* prox1 = cel1->proxima;
        tCel* prox2 = cel2->proxima;

        int i = 0;
        while(1)
        {
            if(cel1==NULL && cel2==NULL)
                break;

            if(cel1==NULL)
            {
                merge->ultima->proxima = cel2;
                merge->ultima = cel2;
                cel2 = prox2;

                if(prox2!=NULL)
                    prox2 = prox2->proxima;
                
                continue;
            }

            else if(cel2==NULL)
            {
                merge->ultima->proxima = cel1;
                merge->ultima = cel1;
                cel1 = prox1;

                if(prox1!=NULL)
                    prox1 = prox1->proxima;
                
                continue;
            }

            if(i%2==0)
            {
                merge->ultima->proxima = cel2;
                merge->ultima = cel2;
                cel2 = prox2;

                if(prox2!=NULL)
                    prox2 = prox2->proxima;
            }
            else
            {
                 merge->ultima->proxima = cel1;
                merge->ultima = cel1;
                cel1 = prox1;

                if(prox1!=NULL)
                    prox1 = prox1->proxima;
            }

            i++;
            
        }

        merge->ultima->proxima = NULL;
        LiberaStructLIsta(l1);
        LiberaStructLIsta(l2);
       return merge;
    }


    void removeRepetido(tLista* l)
    {
       if(l->primeira==NULL)
        return;

        tCel* atual = l->primeira;

        if(l->ultima==atual)
        return;

        while(1)
        {
            if(atual==NULL)
                break;

            tCel* comp = atual->proxima;
            tCel* ant = atual;

            while(1)
            {
                if(comp == NULL)
                    break;

                if(atual->questao==comp->questao)
                {
                    ant->proxima = comp->proxima;

                    if(comp == l->ultima)
                    {
                        l->ultima = ant;
                        ant->proxima=NULL;
                    }

                    free(comp);
                    comp = ant->proxima;
                }
                else
                {
                    ant = comp;
                    comp = comp->proxima;
                }
            }

            atual = atual->proxima;
        }
    }



    tQuestao* BuscarQuestao(tLista* l, char* id)
    {
        tCel* atual = l->primeira;

        while(1)
        {
            if(atual==NULL)
                break;
            
            if(strcmp(GetIdQuestao(atual->questao),id)==0)
                return atual->questao;
            
            atual = atual->proxima;
        }

        return NULL;
    }

     void LiberaProvas(tLista* l)
     {
         tCel* atual = l->primeira;

        while(atual != NULL)
        {
            tCel* prox = atual->proxima;

            free(atual);

            atual = prox;
        }

        free(l->nome);
        free(l);
     }