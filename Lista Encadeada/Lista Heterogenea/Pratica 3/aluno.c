#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    void ImprimeAluno(tAluno* a)
    {
        printf("%s, CPF: %d e CR: %.2f\n",a->nome,a->cpf,a->cr);

    }

    float GetCrAluno(tAluno* a)
    {
        return a->cr;
    }