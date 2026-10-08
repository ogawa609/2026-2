#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "questao.h"

#define NUM_PROVAS 2

int main()
{
    tLista* banco = CriaLista("Banco");

    int n = 0;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        char id[11];
        char enunciado[151];

        scanf("%s %[^\n]",id,enunciado);
        tQuestao* quest = CriaQuestao(id,enunciado);

        InsereLista(banco,quest);
    }

    tLista* provas[NUM_PROVAS];

    for(int i=0;i<NUM_PROVAS;i++)
    {
        char nome[151];
        scanf("%s",nome);
        provas[i] = CriaLista(nome);

        int numQuest=0;
        scanf("%d",&numQuest);

        for(int j=0;j<numQuest;j++)
        {
            char chave[11];
            scanf("%s",chave);

            tQuestao* buscada = BuscaQuestao(buscada,chave);
            InsereLista(provas[i],buscada);
        }
    }

    ImprimeProva(provas[0]);
    ImprimeProva(provas[1]);

    tLista* merge = CriaMerge(provas[0],provas[1]);

    ImprimeProva(merge);

    RetiraRepetido(merge);
    ImprimeProva(merge);
    

    LiberaListaParcial(merge);
    LiberaListaTotal(banco);
    return 0;
}