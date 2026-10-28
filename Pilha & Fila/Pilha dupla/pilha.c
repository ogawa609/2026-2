#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define MaxTam 150

typedef int TipoItem;

typedef struct
{
    int Topo, Base;

}IndicePilha;

struct pilha
{
    Aluno* Item[MaxTam];
    IndicePilha Pilha1, Pilha2;
};

Pilha* CriaPilha()
{
    Pilha* p = malloc(sizeof(Pilha));
   p->Pilha1.Base = 0;
   p->Pilha1.Topo = -1;

   p->Pilha2.Base = MaxTam - 1;
   p->Pilha2.Topo = MaxTam;

   return p;
}
void LiberaPilha(Pilha* p)
{
free(p);

}
void PushPilha1(Pilha* p, Aluno* a)
{
    if(p->Pilha1.Topo != p->Pilha2.Topo)
    {
        p->Item[p->Pilha1.Topo+1] = a;
        p->Pilha1.Topo++;
        
    }

    return;
}

void PushPilha2(Pilha* p, Aluno* a)
{
    if(p->Pilha1.Topo != p->Pilha2.Topo)
    {
        p->Item[p->Pilha2.Topo-1] = a;
        p->Pilha2.Topo--;
        
    }

    return;
}

Aluno* PopPilha1(Pilha* p)
{
     Aluno* temp; 

    if(p != NULL && p->Pilha1.Topo>0)
    {
        temp = p->Item[p->Pilha1.Topo];
        p->Pilha1.Topo--;

        return temp;
    }

    return NULL;

}
Aluno* PopPilha2(Pilha* p)
{
     Aluno* temp; 

    if(p != NULL && p->Pilha2.Topo<MaxTam)
    {
        temp = p->Item[p->Pilha2.Topo];
        p->Pilha2.Topo++;

        return temp;
    }

    return NULL;
}

int PilhaCheia(Pilha* p)
{
    if(p != NULL || p->Pilha1.Topo == p->Pilha2.Topo+1)
        return 1;
    return 0;
}
void ImprimePilha(Pilha* p)
{

    printf("Alunos 1:\n\n");

    for(int i = p->Pilha1.Topo; i>=p->Pilha1.Base; i--)
    {
        ImprimeAluno(p->Item[i]);
    }

     printf("\nAlunos 2:\n\n");

     for(int i = p->Pilha2.Topo; i<=p->Pilha2.Base; i++)
        ImprimeAluno(p->Item[i]);
}
