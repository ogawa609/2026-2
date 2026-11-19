#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "email.h"
#include "abb.h"

struct abb 
{
    Email* email;
    Abb* esquerda;
    Abb* direita;
};

Abb* Cria()
{
    return NULL;
}
Abb* CriaArv(Email* e, Abb* d,Abb* es)
{
    Abb* a = malloc(sizeof(Abb));
    a->direita = d;
    a->esquerda = es;
    a->email = e;

    return a;
}
Abb* Insere(Email* e, Abb* arv)
{
    if(arv == NULL)
        arv = CriaArv(e,Cria(),Cria());

    else if(strcmp(getPessoa(e),getPessoa(arv->email)) > 0)
        arv->esquerda = Insere(e,arv->esquerda);
    
    else 
        arv->direita = Insere(e,arv->direita);

    return arv;
}

int totalMensagens(Abb* arv)
{
    if(arv == NULL)
        return 0;
    
    return gerQnt(arv->email) + totalMensagens(arv->direita) + totalMensagens(arv->esquerda);
}

int Existe(Abb* arv, char* chave)
{
    if(arv == NULL)
        return 0;

    if(strcmp(getPessoa(arv->email),chave) > 0)
        return Existe(arv->direita,chave);

    else if(strcmp(getPessoa(arv->email),chave) < 0)
        return Existe(arv->esquerda ,chave);

    else
        return 1;
}

int NumeroUsuarios(Abb* arv)
{
    if(arv == NULL)
        return 0;


    return 1 + NumeroUsuarios(arv->direita) + NumeroUsuarios(arv->esquerda);
}



Email* maiorUsuario(Abb* raiz, Abb* atual)
{
    if(atual == NULL)
        return NULL;
    
    if(atual->direita == NULL && atual->esquerda == NULL)
        return atual->email;

    Email* pe = maiorUsuario(raiz,atual->esquerda);
    Email* pd = maiorUsuario(raiz,atual->direita);

    int cd =0;
    
    if(pd != NULL)
        cd = gerQnt(pd);

    int ce = 0;
    
    if(pe!=NULL)
        ce = gerQnt(pe);

    int ca = gerQnt(atual->email);

    if(cd>ce)
    {
        if(cd>ca)
            return pd;
        else
            return atual->email;
    }
    else
    {
        if(ce>ca)
            return pe;
        else
            return atual->email;
    }
    
}
void LibrarArv(Abb* arv)
{
    if(arv == NULL)
        return;
    
    LibrarArv(arv->direita);
    LibrarArv(arv->esquerda);

    LiberaEmail(arv->email);
    free(arv);
}

void Imprimir(Abb* arv)
{

    if(arv == NULL)
        return;

    ImprimirEmail(arv->email);
    printf("\n");

    Imprimir(arv->direita);
    Imprimir(arv->esquerda);
}

Email* Busca(Abb* arv, char* chave)
{
    if(arv == NULL)
        return NULL;

    if(strcmp(getPessoa(arv->email),chave) > 0)
        return Busca(arv->direita,chave);

    else if(strcmp(getPessoa(arv->email),chave) < 0)
        return Busca(arv->esquerda,chave);

    return arv->email;
}

int Transfere(Abb* arv, Email** vet, int i)
{
    if(arv == NULL)
        return i;

    vet[i] = arv->email;
    i++;

    i = Transfere(arv->direita, vet, i);
    i = Transfere(arv->esquerda, vet, i);

    return i;
}