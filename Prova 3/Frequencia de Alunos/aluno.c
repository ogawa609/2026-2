#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

struct aluno 
{
    char* nome;
    int presenca;
    int faltas;
};

Aluno* CriaAluno(char* nome)
{
    Aluno* a = malloc(sizeof(Aluno));
    a->faltas = 0;
    a->presenca = 0;
    a->nome = strdup(nome);

    return a;
}
void PresencaAluno(Aluno* aluno, char presenca)
{
    if(presenca == 'P')
        aluno->presenca++;
    else if(presenca == 'F')
        aluno->faltas++;
}
void LiberaAluno(Aluno* aluno)
{
    free(aluno->nome);
    free(aluno);

}
void ImprimeAluno(Aluno* aluno)
{
    printf("%s %dP %dF\n",aluno->nome,aluno->presenca, aluno->faltas);
}
char* GetNomeAluno(Aluno* a)
{
    return a->nome;
}