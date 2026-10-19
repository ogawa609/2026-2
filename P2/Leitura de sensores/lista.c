#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct Cel tCel;

struct Cel
{
    tLeituras* pessoa;
    tCel* proximo;
    tCel* anterior;
};

struct Lista 
{
    tCel* primeiro;
    tCel* ultimo;
};

tLista* CriaLista()
{
    tLista* l = malloc(sizeof(tLista));
    l->primeiro = NULL;
    l->ultimo = NULL;

    return l;
}
void LiberaLista(tLista* l)
{
    tCel* atual = l->primeiro;

    while(atual != NULL)
    {
        tCel* prox = atual->proximo;
        LiberaLeitura(atual->pessoa);
        free(atual);
        atual = prox;
    }

    free(l);
}

void InsereLista(tLista* l,tPessoa* p,char* nome)
{
    //BUSCA SE PESSOA JA EXISTE
    tCel* atual = l->primeiro;

    while(atual != NULL)
    {
        if(strcmp(GetNomeLeitura(atual->pessoa),nome)==0)
        {
            InsereLeitura(atual->pessoa,p);
            return;
        }

        atual = atual->proximo;
    }

    tCel* cel = malloc(sizeof(tCel));
    cel->anterior = NULL;
    cel->proximo = NULL;
    cel->pessoa = CriaLeitura(nome);
    InsereLeitura(cel->pessoa,p);

    if(l->primeiro == NULL)
    {
        l->primeiro = cel;
        l->ultimo = cel;
        return;
    }

    l->ultimo->proximo = cel;
    cel->anterior = l->ultimo;
    l->ultimo = cel;
}

void ImprimeLista(tLista* l)
{
    tCel* atual = l->primeiro;

    while(atual != NULL)
    {
        ImprimeLeituras(atual->pessoa);
        atual = atual->proximo;
    }
}

void OrganizaLista(tLista* l)
{
    tCel* atual = l->primeiro;

    while(atual != NULL)
    {
        RetiraOutiliers(atual->pessoa);
        atual = atual->proximo;
    }
}