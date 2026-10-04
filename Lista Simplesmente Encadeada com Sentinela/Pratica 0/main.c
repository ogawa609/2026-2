#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "aluno.h"


int main()
{
    tLista* lista = CriaLista();
    printf("Insira o numero de alunos e a lista de alunos\n");

    int n=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        char nome[51];
        int matricula = 0;
        char curso[51];

        scanf("%s %d %s",nome,&matricula,curso);

        tAluno* aluno = CriaAluno(nome,matricula,curso);
        InsereAluno(lista,aluno);
    }

    printf("Digite as matriculas dos alunos que deseja retirar -> -1 encerra\n");

    while(1)
    {
        int retirada = 0;
        scanf("%d",&retirada);

        if(retirada<0)
            break;
        
        RetiraAluno(retirada,lista);
    }
    ImprimeLista(lista);
    LiberaLista(lista);

    return 0;
}