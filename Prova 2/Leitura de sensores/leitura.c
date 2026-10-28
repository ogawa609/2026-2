#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

typedef struct Leitura tLeitura;

struct Leitura
{
    tPessoa* dados;
    tLeitura* proximo;
    tLeitura* anterior;
};

struct Leituras 
{
    char* nome;
    int somaTemp;
    int cont;
    tLeitura* primeiro;
    tLeitura* ultimo;
};

tLeituras* CriaLeitura(char* nome)
{
    tLeituras* l = malloc(sizeof(tLeituras));
    l->nome = strdup(nome);
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->somaTemp = 0;
    l->cont = 0;


    return l;
}

void LiberaCelLeitura(tLeitura* l)
{
    LiberaPessoa(l->dados);
    free(l);
}

void LiberaLeitura(tLeituras* l)
{
    tLeitura* atual = l->primeiro;

    while(atual != NULL)
    {
        tLeitura* prox = atual->proximo;
        LiberaCelLeitura(atual);
        atual = prox;
    }

    free(l->nome);
    free(l);
}

void InsereLeitura(tLeituras* l, tPessoa* p)
{
    float temp = GetTempPessoa(p);

    tLeitura* cel = malloc(sizeof(tLeitura));
    cel->dados = p;
    cel->anterior = NULL;
    cel->proximo = NULL;

    l->somaTemp += (int)temp;
    l->cont++;

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

char* GetNomeLeitura(tLeituras* l) 
{
    return l->nome;
}

void ImprimeLeituras(tLeituras* l)
{
    printf("Pessoa: %s\n",l->nome);

    tLeitura* atual = l->primeiro;

    while(atual != NULL)
    {
        ImprimePessoa(atual->dados);
        atual = atual->proximo;
    }

    printf("\n");
}

void RetiraOutiliers(tLeituras* l)
{
    int media = 0;
    if(l->cont>0)
        media = l->somaTemp/l->cont +1;

    tLeitura* atual = l->primeiro;

    while(atual != NULL)
    {
        tLeitura* prox = atual->proximo;

        if(GetTempPessoa(atual->dados)>media)
        {
            if(atual == l->primeiro && atual == l->ultimo)
                l->ultimo = l->primeiro = NULL;
            else if(atual == l->primeiro)
            {
                l->primeiro = atual->proximo;
                atual->proximo->anterior = NULL;
            }
            else if(atual == l->ultimo)
            {
                l->ultimo = atual->anterior;
                atual->anterior->proximo = NULL;
            }
            else
            {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }

            LiberaCelLeitura(atual);
                
        }

        atual = prox;
    }
}