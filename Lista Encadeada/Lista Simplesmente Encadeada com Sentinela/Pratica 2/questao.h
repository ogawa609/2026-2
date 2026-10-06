#ifndef _QUESTAO_H
#define _QUESTAO_H

    typedef struct Questao tQuestao;
    tQuestao* CriaQuestao(char* id, char* enunciado);
    void LiberaQuestao(tQuestao* q);
    char* GetIdQuestao(tQuestao* q);
    void ImprimeQuestao(tQuestao* q);
    

#endif