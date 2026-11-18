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
    Abb* a = mallorc(sizeof(Abb));
    a->direita = d;
    a->esquerda = es;
    a->email = e;

    return a;
}
Abb* Insere(Email* e, Abb* arv)
{
    if(arv == NULL)
        CriaArv(e,Cria(),Cria());

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
    
    return 1 + totalMensagens(arv->direita) + totalMensagens(arv->esquerda);
}

int Existe(Abb* arv, char* chave)
{
    if(arv == NULL)
        return 0;

    if(strcmp(getPessoa(arv->email),chave) > 0)
        return Existe(arv->esquerda,chave);

    else if(strcmp(getPessoa(arv->email),chave) < 0)
        return Existe(arv->direita,chave);

    return 1;
}

int NumeroUsuarios(Abb* arv)
{
    if(arv == NULL)
        return 0;

    if(Existe(arv->direita,getPessoa(arv->email)))
        return 0 + NumeroUsuarios(arv->direita) + NumeroUsuarios(arv->esquerda);

    return 1 + NumeroUsuarios(arv->direita) + NumeroUsuarios(arv->esquerda);
}

int Contar(Abb* arv, Email* pessoa)
{
    if(arv == NULL)
        return 0;

    if(ComparaPessoas(arv->email,pessoa))
        return 1 + Contar(arv->direita,pessoa) + Contar(arv->esquerda,pessoa);
        
    return 0 +  Contar(arv->direita,pessoa) + Contar(arv->esquerda, pessoa);
}

Email* maiorUsuario(Abb* arv)
{
    if(arv == NULL)
        return NULL;

    if(arv->direita == NULL && arv->esquerda == NULL)
        return arv->email;

    int qe = Contar(arv->esquerda,arv->email)


    
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

    Imprimir(arv->direita);
    Imprimir(arv->esquerda);
}