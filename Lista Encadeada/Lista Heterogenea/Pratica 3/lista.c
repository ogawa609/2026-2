#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "professor.h"
#include "aluno.h"

typedef struct Cel tCel;

struct Cel
{
    void* pessoa;
    tCel* proximo;
    tCel* anterior;
    char id;
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

    void LiberaCel(tCel* c)
    {
        if(id == 'A')
            LiberaAluno((tAluno*)c->pessoa);
        else
            LiberaProfessor((tProfessor*)c->pessoa);
    
        free(c);
            
    }

    void LiberaLista(tLista* l)
    {
        tCel* atual = l->primeiro;

        while(1)
        {
            if(atual == NULL)
                break;

            tCel* temp = atual->proximo;
            LiberaCel(atual);
            atual = temp;

        }

        free(l);
    }
    tCel* CriaCel(void* nfo, char id)
    {
        tCel* c = malloc(sizeof(tCel));
        c->pessoa  = nfo;
        c->proximo = NULL
        c->id = id;

        return c;
    }

    void InsereLista(tLista* l, void* sujeito, char id)
    {

        tCel* cel = CriaCel(sujeito,id);

        if(l->primeiro==NULL)
        {
            l->primeiro = cel;
            l->ultimo = cel;
        }

        l->ulrimo->proximo = cel;
        cel->anterior = l->ultimo;
        l->ultimo = cel;
        
    }
    void ImprimeRelatorio(tLista* l)
    {
        
    }