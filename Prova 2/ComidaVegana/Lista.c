#   include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "ComidaNaoVegana.h"
#include "ComidaVegana.h"
typedef struct Celula tCelula;

struct Celula
{
    void* elemento;
    int id;
    tCelula* anterior;
    tCelula* proximo;
};

struct Lista 
{
    tCelula* primeiro;
    tCelula* ultimo;
    int itens;
};

tLista* CriaLista()
{
    tLista* l = malloc(sizeof(tLista));
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->itens = 0;

    return l;
}
void LiberaCelula(tCelula* c)
{
    free(c);
}
void LiberaLista(tLista* l)
{
    tCelula* atual = l->primeiro;

    while(atual != NULL)
    {
        tCelula* prox = atual->proximo;
        LiberaCelula(atual);
        atual = prox;
    }

    free(l);
}

void InsereLista(tLista* l, void* elem, int id)
{
    tCelula* c = malloc(sizeof(tCelula));
    c->anterior = NULL;
    c->proximo = NULL;
    c->elemento = elem;
    c->id = id;

    if(l->primeiro == NULL)
    {
        l->primeiro = c;
        l->ultimo = c;
        l->itens++;
        return;
    }

    c->anterior = l->ultimo;
    l->ultimo->proximo = c;
    l->ultimo = c;
    l->itens++;
}

int RetiraLista(tLista* l, char* nome)
{
    tCelula* atual = l->primeiro;

    while(atual != NULL)
    {
        tCelula* prox = atual->proximo;

        char* nomeBuscado = NULL;

        if(atual->id == 0)
            nomeBuscado = retornaNomeComidaNaoVegana((ComidaNaoVegana*)atual->elemento);
        else
            nomeBuscado = retornaNomeComidaVegana((ComidaVegana*)atual->elemento);
        
        if(strcmp(nome,nomeBuscado)==0)
        {
            //sendo unico elemento
            if(atual == l->primeiro && atual == l->ultimo)
            {
                l->primeiro = NULL;
                l->ultimo = NULL;
                LiberaCelula(atual);
                l->itens--;
                return 1;
            }
            //sendo primeiro elemento
            if(atual == l->primeiro)
            {
                prox->anterior = NULL;
                LiberaCelula(atual);
                l->primeiro = prox;
                l->itens--;
                return 1;
            }
            //sendo ultimo elemento
            if(atual == l->ultimo)
            {
                atual->anterior->proximo = NULL;
                l->ultimo = atual->anterior;
                LiberaCelula(atual);
                l->itens--;
                return 1;
            }
            //estando no meio
            atual->anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;
            LiberaCelula(atual);
            l->itens--;
            return 1;
        }
        else
        {
            atual = prox;
        }
    }

    return 0;
}

int GetQtdItens(tLista* l)
{
    return l->itens;
}

void ImprimeLista(tLista* l)
{
    tCelula* atual = l->primeiro;

    while(atual != NULL)
    {
        if(atual->id == 0)
            imprimeComidaNaoVegana((ComidaNaoVegana*)atual->elemento);
        else
            imprimeComidaVegana((ComidaVegana*)atual->elemento);
        
        atual = atual->proximo;
    }
}

float GetValorLista(tLista* l)
{
    tCelula* atual = l->primeiro;
    float valor = 0;
    while(atual != NULL)
    {
            if(atual->id == 0)
                valor += retornaValorComidaNaoVegana((ComidaNaoVegana*)atual->elemento);
            else
                valor+=30;
            
            atual = atual->proximo;
    }

    return valor;
}