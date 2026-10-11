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
        q->enunciado = strdup(enunciado);
        q->id = strdup(id);

        return q;
    }

    char* GetIdQuest(tQuestao* q)
    {
        return q->id;
    }
    void LiberaQuestao(tQuestao* q)
    {
        free(q->enunciado);
        free(q->id);
        free(q);
    }

    void ImprimeQuestao(tQuestao* q)
    {
        printf("ID: %s, Enunciado: %s\n",q->id,q->enunciado);
    }