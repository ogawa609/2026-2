#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

struct abb 
{
    char* palavra;
    int frequenca;
    Abb* esquerda;
    Abb* direita;
};

Abb* CriaVazia()
{
    return NULL;
}
Abb* CriaArv(char* palavra, int freq, Abb* esquerda, Abb* direito)
{
    Abb* arv = malloc(sizeof(Abb));
    arv->direita = direito;
    arv->esquerda = esquerda;
    arv->frequenca = freq;
    arv->palavra = strdup(palavra);

    return arv;
}
Abb* Insere(Abb* arv, char* palavra, int frq)
{
    if(arv == NULL)
        arv = CriaArv(palavra,frq,CriaVazia(),CriaVazia());

    else
    {
        if(strcmp(arv->palavra,palavra)>0)
            arv->direita = Insere(arv->direita,palavra,frq);
         else
            arv->esquerda = Insere(arv->esquerda,palavra,frq);

    }
        return arv;
    
}

int TotalPalavras(Abb* arv)
{
    if(arv == NULL)
        return 0;

    return arv->frequenca + TotalPalavras(arv->direita) + TotalPalavras(arv->esquerda);
}

int Busca(Abb* arv, char* palavra)
{
    if(arv == NULL)
        return 0;

    if(strcmp(arv->palavra, palavra)>0)
        return Busca(arv->esquerda,palavra);

    else if(strcmp(arv->palavra, palavra)<0)
        return Busca(arv->direita,palavra);

    return 1;
}

int PalavrasUnicas(Abb* arv)
{
    if(arv == NULL)
        return 0;
    
    if(Busca(arv->esquerda,arv->palavra))
        return 0 + PalavrasUnicas(arv->direita) + PalavrasUnicas(arv->esquerda);
    else
        return 1 + PalavrasUnicas(arv->direita) + PalavrasUnicas(arv->esquerda);
}

void Libera(Abb* arv)
{
    if(arv != NULL)
    {
        Libera(arv->direita);
        Libera(arv->esquerda);

        free(arv->palavra);
        free(arv);
    }
}
void Imprime(Abb* arv)
{

    if(arv == NULL)
        return;

    printf("%s %d\n",arv->palavra, arv->frequenca);

    
    Imprime(arv->esquerda);
    Imprime(arv->direita);
}

int Maior(Abb* arv)
{
    if(arv == NULL)
        return 0;

    if(arv->direita == NULL && arv->esquerda == NULL)
        return arv->frequenca;

    int maiorE = Maior(arv->esquerda);
    int maiorD = Maior(arv->direita);

    if(maiorD > maiorE)
    {
        if(maiorD > arv->frequenca)
            return maiorD;
        else
            return arv->frequenca;
    }

    if(maiorE > arv->frequenca)
            return maiorE;
        else
            return arv->frequenca;


}
