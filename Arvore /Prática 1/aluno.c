#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

struct aluno 
{
    char* nome;
    int matricula;
};

Aluno* CriaAluno(char* nome, int mat)
{
    Aluno* a = malloc(sizeof(Aluno));
    a->matricula = mat;
    a->nome = strdup(nome);

    return a;
    
}

void LiberaAluno(Aluno* a)
{
    free(a->nome);
    free(a);
}
void ImprimeAluno(Aluno* a)
{
    printf("NOME: %s; MATRICULA: %d\n",a->nome,a->matricula);
}

int GetMatriculaAluno(Aluno* a)
{
    return a->matricula;
}
