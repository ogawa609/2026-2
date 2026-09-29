#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questao.h"


struct Questao 
{
    char* id;
    char* enunciado;
};

tQuestao* CriaQuestao(char* id, char* enunciado)
{
    tQuestao* q = malloc(sizeof(tQuestao));

    int tam = strlen(id) + 1;
    q->id = calloc(tam,sizeof(char));
    strcpy(q->id,id);

    tam = strlen(enunciado) + 1;
    q->enunciado = calloc(tam,sizeof(char));
    strcpy(q->enunciado,enunciado);

    return q;
}

void LiberaQuestao(tQuestao* q)
{
    free(q->enunciado);
    free(q->id);
}

char* GetIdQuestao(tQuestao* q)
{
    return q->id;
}

// ID: Q8, Enunciado: Enunciado da questão 8
void ImprimeQuestao(tQuestao* q)
{
    printf("ID: %s, Enunciado: %s\n",q->id,q->enunciado);
}