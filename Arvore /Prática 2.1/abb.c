#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

struct abb
{
    int dado;

    Abb* esquerda;
    Abb* direita;
};

Abb* CriaArvoreVazia()
{
    return NULL;
}

Abb* CriaArvore(int dado, Abb* e, Abb* d)
{
    Abb* arv = malloc(sizeof(Abb));
    arv->dado = dado;
    arv->direita = d;
    arv->esquerda = e;

    return arv;
}

Abb* InsereArvore(int dado, Abb* arv)
{
    if(arv == NULL)
        arv = CriaArvore(dado,CriaArvoreVazia(),CriaArvoreVazia());
    else if(dado > arv->dado)
        arv->direita = InsereArvore(dado,arv->direita);
    else
        arv->esquerda = InsereArvore(dado,arv->esquerda);

    return arv;
}

void LiberaArv(Abb* arv)
{
    if(arv == NULL)
        return;
    
    LiberaArv(arv->direita);
    LiberaArv(arv->esquerda);

    free(arv);
}

int ArvVazia(Abb* arv)
{
    return arv == NULL;
}

int BuscaDado(Abb* arv, int dado)
{
    if(arv == NULL)
        return 0;

    if(arv->dado > dado)
        return BuscaDado(arv->esquerda,dado);

    else if(arv->dado < dado)
        return BuscaDado(arv->direita,dado);
    else
     return 1;
}
Abb* RetiraArv(Abb* arv, int dado)
{
    if(arv ==  NULL)
        return NULL;
    else if(arv->dado > dado)
        arv->esquerda = RetiraArv(arv->esquerda,dado);
    else if(arv->dado < dado)
        arv->direita = RetiraArv(arv->direita,dado);

    else
    {
        if(arv->direita == NULL && arv->esquerda == NULL)
        {
            free(arv);
            arv = NULL;
        }

        else if(arv->direita == NULL)
        {
            Abb* temp = arv;
            arv = arv->esquerda;
            free(temp);
        }

        else if(arv->esquerda == NULL)
        {
            Abb* temp = arv;
            arv = arv->direita;
            free(temp);
        }

        else
        {
            Abb* temp = arv->direita;

            while(temp->esquerda != NULL)
                temp = temp->esquerda;

            arv->dado = temp->dado;
            arv->direita = RetiraArv(arv->direita,temp->dado);
        }
    }

    return arv;
}

void Imprime(Abb* arv)
{
    

    if(arv != NULL)
    {
        Imprime(arv->esquerda);
        Imprime(arv->direita);

        printf("%d - ",arv->dado);
    }

   
}

int Altura(Abb* arv)
{
    if(arv == NULL)
        return 0;
    
    int he = Altura(arv->esquerda);
    int hd = Altura(arv->direita);

    if(he>hd)
        return he +1;
    return hd + 1;
}

int NumeroElementos(Abb* arv)
{
    if(arv == NULL)
        return 0;
    
    return 1+ NumeroElementos(arv->direita) + NumeroElementos(arv->esquerda);
}
int NumeroFolhas(Abb* arv)
{
    if(arv == NULL)
        return 0;
    else if(arv->direita == NULL && arv->esquerda == NULL)
    {
        return 1; 
    }

    return NumeroFolhas(arv->direita) + NumeroFolhas(arv->esquerda);
}