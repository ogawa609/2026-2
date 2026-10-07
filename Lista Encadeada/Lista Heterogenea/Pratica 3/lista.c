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
        if(c->id == 'A')
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
        c->proximo = NULL;
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

        l->ultimo->proximo = cel;
        cel->anterior = l->ultimo;
        l->ultimo = cel;
        
    }
    void ImprimeRelatorio(tLista* l)
    {
        printf("PROFESSORES\n");

        int nProf = 0;
        float salario = 0;

        tCel* temp = l->primeiro;

        while(1)
        {
            if(temp == NULL)
                break;

            if(temp->id == 'P')
            {
                ImprimeProfesor((tProfessor*)temp->pessoa);
                nProf++;
                salario += GetSalarioProf((tProfessor*)temp->pessoa);
            }

            temp = temp->proximo;

        }
        printf("\n");
        if(nProf>0)
            salario /= nProf;
        else
            salario = 0;


        printf("Média de salário dos %d professores: %,2f\n\n",nProf,salario);

        temp = l->primeiro;


    }