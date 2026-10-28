#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

struct aluno 
{
    char* nome;
    int matricula;
};

Aluno* CriaAluno(char* nome, int matricula)
{
    Aluno* a = malloc(sizeof(Aluno));
    a->matricula = matricula;
    a->nome = strdup(nome);

    return a;
}

void LiberaAluno(Aluno* a)
{
    free(a->nome);
    free(a);
}
char* GetNomeAluno(Aluno* a)
{
    return a->nome;
}
int GetMatriculaAluno(Aluno* a)
{
    return a->matricula;
}

void ImprimeAluno(Aluno* a)
{
    printf("=> Aluno: %s; Matricula: %d\n",a->nome,a->matricula);
}