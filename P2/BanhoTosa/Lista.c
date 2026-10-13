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