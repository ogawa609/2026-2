#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

 struct Celula 
{
    tCelula* proximo;
    tAluno* aluno;

};


struct Lista 
{
    tCelula* prim;
    tCelula* ult;

};


tLista* CriaLista()
{
    tLista* lista = malloc(sizeof(tLista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void InsereAluno(tLista* lista, tAluno* aluno )
{

    tCelula* cel = CriaCelula(aluno);
    if(lista->prim==NULL)
    {
        lista->prim = cel;
        lista->ult = cel;
        return;
    }

    lista->ult->proximo = cel;
    lista->ult = cel;

}
void LiberaLista(tLista* lista)
{
    if(lista->prim!=NULL)
    {
        tCelula* atual = lista->prim;
        tCelula* temp = atual->proximo;

        while(1)
        {
            LiberaCelula(atual);
            atual = temp;

            if(atual==NULL)
                break;
            temp = atual->proximo;
            
        }
    }
    free(lista);
}

void RetiraAluno(int matricula,tLista* lista)
{
    tCelula* atual = lista->prim;
    tCelula* anterior = NULL;

    while(atual != NULL)
    {
        if(getMatricula(atual->aluno)==matricula)
        {
            //Caso 1: cel unica
            if(atual==lista->prim && atual==lista->ult)
            {
                lista->prim = NULL;
                lista->ult = NULL;
                LiberaCelula(atual);
                return;
            }
            //Caso 2: primeira cel
            else if(atual==lista->prim)
            {
                tCelula* temp = atual->proximo;
                LiberaCelula(atual);
                lista->prim = temp;
                return;
            }
            //caso 3: ultima cel
            else if(atual==lista->ult)
            {
                LiberaCelula(atual);
                lista->ult = anterior;
                anterior->proximo = NULL;
                return;
            }
            //Caso 4: Meio
            else
            {
                tCelula* temp = atual->proximo;
                LiberaCelula(atual);
                anterior->proximo = temp;
                return;
            }
        }

        anterior = atual;
        atual = atual->proximo;

        if(atual==NULL)
            break;
    }
}

tCelula* CriaCelula(tAluno* aluno)
{
     tCelula* cel = malloc(sizeof(tCelula));
     cel->aluno = aluno;
     cel->proximo = NULL;

     return cel;

}

void LiberaCelula(tCelula* cel)
{
    LiberaAluno(cel->aluno);
    free(cel);
}

void ImprimeLista(tLista* lista)
{
    tCelula* atual = lista->prim;
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
    while(1)
    {
        ImprimeAluno(atual->aluno);
        atual = atual->proximo;

        if(atual==NULL)
            break;
    }

        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
}