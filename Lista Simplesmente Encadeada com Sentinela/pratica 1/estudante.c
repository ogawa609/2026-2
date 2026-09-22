#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudante.h"

struct estudante 
{
    char* nome;
    int matricula;
    float cr;
};

tEstudante* CriaEstudante(char* nome,int matricula,float cr)
{
    tEstudante* e = malloc(sizeof(tEstudante));
    e->cr = cr; 
    e->matricula = matricula;

    int tam = strlen(nome) + 1;
    e->nome = malloc(tam*sizeof(char));
    strcpy(e->nome,nome);

    return e;
}

float getCr(tEstudante* e)
{
    return e->cr;
}
int getMatricula(tEstudante* e)
{
    return e->matricula;
}
char* getNome(tEstudante* e)
{
    return e->nome;
}
void LiberaEstudante(tEstudante* e)
{
    free(e->nome);
    free(e);
}