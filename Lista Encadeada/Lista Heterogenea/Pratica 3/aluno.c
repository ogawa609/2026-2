#include <stdio.h>
#include <stdlib.h>
#nclude <string.h>
#include "aluno.h"

struct Aluno 
{
    char* nome;
    int cpf;
    float cr;
};

    tAluno* CriaAluno(char* nome, int cpf, float cr)
    {
        tAluno* a = malloc(sizeof(tAluno));
        a->nome = strdup(nome);
        a->cpf = cpf;
        a->cr = cr;

        return a;
    }

    void LiberaAluno(tAluno* a)
    {
        free(a->nome);
        free(a);
    }