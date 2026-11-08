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
char* GetNomeAluno(Aluno* a)
{
    return a->nome;
}
int GetMatriculaAluno(Aluno* a)
{
    return a->matricula;
}
void ImprimirAluno(Aluno* a)
{
    printf("NOME: %s\nMATRICULA: %d\n\n",a->nome,a->matricula);

}

int ComparaNome(Aluno* a1, Aluno* a2)
{
    return strcmp(a1->nome,a2->nome) == 0;
}
