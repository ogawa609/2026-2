#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"
#include "Gato.h"
#include "Lista.h"

typedef struct Celula Celula;

struct Celula
{
    void* elemento;
    Celula* anterior;
    Celula* proximo;
    int id;
};

struct Lista 
{
    Celula* primeira;
    Celula* ultimo;
};

    Lista* CriaLista()
    {
        Lista* lista = malloc(sizeof(Lista));
        lista->primeira = NULL;
        lista->ultimo = NULL;

        return lista;
    }
    void InsereLista(Lista* lista, void* elemento,int id)
    {
        Celula* c = malloc(sizeof(Celula));
        c->id = id;
        c->elemento = elemento;
        c->proximo = NULL;
        c->anterior = NULL;

        if(lista->primeira == NULL)
        {
            lista->primeira = c;
            lista->ultimo = c;
        }

        lista->ultimo->proximo = c;
        c->anterior = lista->ultimo;
        lista->ultimo = c;
    }
    
    void LiberaLista(Lista* lista)
    {
        Celula* atual = lista->primeira;

        while(atual != NULL)
        {
            Celula* proxima = atual->proximo;
            free(atual);
            atual = proxima;
        }

        free(lista);
    }

    void RemoveLista(Lista* l,char* chave)
    {
        Celula* atual = l->primeira;

        while(atual != NULL)
        {
            Celula* prox = atual->proximo;
            char* nome = NULL;
            if(atual->id ==0)
                nome = getNomeCachorro((Cachorro*)atual->elemento);
            else
                nome = getNomeGato((Gato*)atual->elemento);

            if(strcmp(nome,chave)==0)
            {
                if(atual == l->primeira && atual == l->ultimo)
                {
                    l->primeira = NULL;
                    l->ultimo = NULL;
                    free(atual);
                    return;
                }

                if(atual == l->primeira)
                {
                    l->primeira = atual->proximo;
                    atual->proximo->anterior = NULL;
                    free(atual);
                    return;
                }

                if(atual == l->ultimo)
                {
                    atual->anterior->proximo = NULL;
                    l->ultimo = atual->anterior;
                    free(atual);
                    return;
                }

                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                free(atual);
                return;
            }
            else
            {
                atual = prox;
            }
        }
    }

     void ImprimeLista(Lista* l)
     {
        Celula* c = l->primeira;

        while(c != NULL)
        {
            if(c->id == 0)
                ImprimirCachorro((Cachorro*)c->elemento);
            else
                ImprimirGato((Gato*)c->elemento);
            
            c = c->proximo;

        }

     }

     int CalcularLista(Lista* l)
     {
        int valor = 0;
         Celula* c = l->primeira;

        while(c != NULL)
        {
            if(c->id == 0)
            {
                valor += 40;

                if(getTipoCachorro((Cachorro*)c->elemento) == BRAVO)
                    valor += 5;
            }
            else
            {
                valor += 30;

                if(getTipoGato((Gato*)c->elemento) == BRAVO)
                    valor += 5;
            }
            
            c = c->proximo;

        }

        return valor;
     }