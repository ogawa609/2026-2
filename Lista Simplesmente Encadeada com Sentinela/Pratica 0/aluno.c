#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno
{
    char* nome;
    int matricula;
    char* curso;
};

tAluno* CriaAluno(char* nome, int matricula, char* curso)
{
    tAluno* a = malloc(sizeof(tAluno));
    int tam = strlen(nome) +1;
    a->nome = malloc(tam*sizeof(char));
    strcpy(a->nome,nome);
    tam = strlen(curso)+1;
    a->curso = malloc(tam*sizeof(char));
    strcpy(a->curso,curso);
    a->matricula = matricula;

    return a;
}

tAluno* LeAluno()
{
    char nome[151];
    char curso[151];
    int matricula;

    scanf("%d %s %s",&matricula,nome,curso);

    return CriaAluno(nome,matricula,curso);
}

void ImprimeAluno(tAluno* a)
{
    printf("Aluno: %s\nMatricula: %d\nCurso: %s\n==========================\n\n",a->nome,a->matricula,a->curso);

}
void LiberaAluno(tAluno* a)
{
    free(a->curso);
    free(a->nome);
    free(a);
}

int getMatricula(tAluno* a)
{
    return a->matricula;
}