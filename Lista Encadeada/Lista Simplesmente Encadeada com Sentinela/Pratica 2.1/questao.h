#ifndef _QUESTAO_H
#define _QUESTAO_H

    typedef struct Questao tQuestao;
    tQuestao* CriaQuestao(char* id, char* enunciado);
    char* GetIdQuest(tQuestao* q);
    void LiberaQuestao(tQuestao* q);
    void ImprimeQuestao(tQuestao* q);
#endif