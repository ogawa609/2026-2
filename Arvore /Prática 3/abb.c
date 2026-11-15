#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

struct abb 
{
    char* dado;
    Abb* esquerda;
    Abb* direito;
};
Abb* CriaArvVazia()
{
    return NULL;
}
Abb* CriaArvore(char* dado, Abb* esq, Abb* dir)
{
    Abb* arv = malloc(sizeof(Abb));
    arv->dado = strdup(dado);
    arv->direito = dir;
    arv->esquerda = esq;

    return arv;
}
void LiberaArv(Abb* arv)
{
    if(arv == NULL)
        return;
    
    LiberaArv(arv->direito);
    LiberaArv(arv->esquerda);

    free(arv->dado);
    free(arv);
}

//strcmp > 0 str1 vem depois da str2 na ordem alfabetica
Abb* Insere(Abb* arv, char* dado)
{
    if(arv == NULL)
        arv = CriaArvore(dado,CriaArvVazia(),CriaArvVazia());
    else
    {
        if(strcmp(dado,arv->dado)>0)
            arv->direito = Insere(arv->direito,dado);

        else
           arv->esquerda = Insere(arv->esquerda,dado);
    
    }

    return arv; 
}

int Existe(Abb* arv, char* chave)
{
    if(arv == NULL)
        return 0;

    
        if(strcmp(arv->dado,chave)>0)
            return Existe(arv->esquerda,chave);

        else if(strcmp(arv->dado,chave)<0)
            return Existe(arv->direito,chave);
    
        else
            return 1;
}

Abb* Retira(Abb* arv, char* chave)
{
    if(arv == NULL)
        return NULL;

    if(strcmp(arv->dado,chave)>0)
        arv->esquerda = Retira(arv->esquerda,chave);

    else if(strcmp(arv->dado,chave)<0)
        arv->direito = Retira(arv->direito,chave);
    else
    {
        if(arv->direito == NULL && arv->esquerda == NULL)
        {
            free(arv->dado);
            free(arv);
            arv = NULL;
        }

        else if(arv->direito == NULL)
        {
            Abb* temp = arv;
            arv = arv->esquerda;

            free(temp->dado);
            free(temp);

        }
        else if(arv->esquerda == NULL)
        {
            Abb* temp = arv;
            arv = arv->direito;

            free(temp->dado);
            free(temp);
        }

        else
        {
            Abb* temp = arv->direito;

            while(temp->esquerda != NULL)
                temp = temp->esquerda;

            free(arv->dado);
            arv->dado = strdup(temp->dado);

            arv->direito = Retira(arv->direito, temp->dado);
        }
    }
    
    return arv;
}
void Imprime(Abb* arv)
{
    if(arv != NULL)
    {
        printf("%s\n",arv->dado);
        Imprime(arv->esquerda);
        Imprime(arv->direito);
    }
}
int Altura(Abb* arv)
{
    if(arv == NULL)
        return 0;
    
    int he = Altura(arv->esquerda);
    int hd = Altura(arv->direito);

    if(he > hd)
        return 1 + he;

    return 1 + hd;
}