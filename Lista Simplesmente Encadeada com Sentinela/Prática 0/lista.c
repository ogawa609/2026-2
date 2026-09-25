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
    tCelula* prox;
    tCelula* ant;

};


tLista* CriaLista()
{
    tLista* lista = malloc(sizeof(tLista));
    lista->ant = NULL;
    lista->prox = NULL;

    return lista;
}

void InsereAluno(tLista* lista, tAluno* aluno )
{

    tCelula* cel = CriaCelula(aluno);
    if(lista->ant == NULL)
        lista->ant = cel;
    else
        lista->prox->proximo = cel;
    
    lista->prox = cel;
}
void LiberaLista(tLista* lista)
{
    if(lista->ant!=NULL)
    {
        tCelula* prox = lista->ant;
        tCelula* atual = prox;

        while(atual!=NULL)
        {
            atual = prox;
            prox = atual->proximo;
            LiberaCelula(atual);
            
        }
    }
    free(lista);
}

void RetiraAluno(int matricula,tLista* lista)
{
    tCelula* temp = NULL;
    tCelula* ant = NULL;

    for(temp = lista->ant;temp!=NULL;temp==temp->proximo)
    {
        if(getMatricula(temp->aluno)==matricula)
        {
            if(temp==lista->ant)
            {
                
            }
            else if()
        }
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