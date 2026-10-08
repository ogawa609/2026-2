#ifndef _QUESTAO_H
#define _QUESTAO_H

    typedef struct Questao tQuestao;
    tQuestao* CriaQuestao(char* id, char* enunciado);
    char* GetIdQuest(tQuestao* q);
#endif