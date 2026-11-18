#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "abb.h"


int main()
{
    FILE* conf = fopen("configuracao.txt","r");
    Abb* arv = Cria();

    if(!conf)
    {
        printf("failed");
        exit(1);
    }

    int n = 0;
    fscanf(conf,"%d",&n);

    char nome[151];

    while(fscanf(conf,"%s",nome)!=EOF)
    {
        Aluno* aluno = CriaAluno(nome);
        arv = Inserir(arv,aluno);

    }
        
    fclose(conf);
    char arq[9];
    for(int i = 0; i < n; i++)
    {
        strcpy(arq,"entrada");
        arq[7] = (char) (i+1+'0');
        arq[8] = '\0';

        FILE* arquivo = fopen(arq,"r");
        char busca[151];
        char freq;
        while(fscanf(arquivo,"%s %c",busca, &freq)!=EOF)
        {

            Aluno* buscado = Buscar(arv,busca);

            if(buscado != NULL)
                PresencaAluno(buscado,freq);
        }

        fclose(arquivo);
    }

    Imprimir(arv);
    Liberar(arv);

    return 0;
}