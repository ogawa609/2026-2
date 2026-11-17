#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

 struct abb 
 {
    Aluno* aluno;
    Abb* esquerda;
    Abb* direita;
 };

Abb* Cria()
{
    return NULL;
}
Abb* CriaArv(Aluno* a, Abb* d, Abb* e)
{
    Abb* arv = malloc(sizeof(Abb));
    arv->aluno = a;
    arv->direita = d;
    arv->esquerda = e;

    return arv;
}

Abb* Inserir(Abb* arv, Aluno* a)
{
    if(arv == NULL)
        arv = CriaArv(a,Cria(),Cria());

    else if(strcmp(GetNomeAluno(arv->aluno),GetNomeAluno(a)) > 0)
        arv->esquerda = Inserir(arv->esquerda,a);
    else
        arv->direita = Inserir(arv->direita,a);

    return arv;
    
}
void Liberar(Abb* arv)
{
    if(arv == NULL)
        return;
    
    Liberar(arv->direita);
    Liberar(arv->esquerda);

    LiberaAluno(arv->aluno);
    free(arv);
}

Aluno* Buscar(Abb* arv, char* nome)
{
    if(arv == NULL)
        return NULL;
    
    if(strcmp(GetNomeAluno(arv->aluno),nome)>0)
        return Buscar(arv->direita,nome);

    else if(strcmp(GetNomeAluno(arv->aluno),nome)<0)
        return Buscar(arv->esquerda,nome);
    
    else
        return arv->aluno;
}

void Imprimir(Abb* arv)
{
    ImprimeAluno(arv->aluno);

    Imprimir(arv->direita);
    Imprimir(arv->esquerda);
}