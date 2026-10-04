#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int main()
{
    tLista* banco = CriaLista("Banco");

    int n=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        char id[11];
        char enunciado[151];
        scanf("%s %[^\n]",id, enunciado);

        tQuestao* q = CriaQuestao(id, enunciado);

        InsereLista(banco,q);
    }

    tLista* provas[2];

    for(int i=0;i<2;i++)
    {
        char nome[151];
        scanf("%s",nome);

        provas[i] = CriaLista(nome);

        int nq = 0;
        scanf("%d",&nq);

        for(int j=0;j<nq;j++)
        {
            char chave[11];
            scanf("%s",chave);
            tQuestao* quest = BuscarQuestao(banco,chave);

            if(quest==NULL)
                continue;
            InsereLista(provas[i],quest);
        }
    }

    for(int i=0;i<2;i++)
    {
        ImprimeLista(provas[i]);
    }

    tLista* merge = CriarMerge(provas[1],provas[0]);
    ImprimeLista(merge);
    removeRepetido(merge);
    ImprimeLista(merge);

    LiberaProvas(merge);
    LiberaLista(banco);

    return 0;
}