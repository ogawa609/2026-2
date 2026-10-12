#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "aluno.h"
#include "professor.h"

int main()
{
    FILE* f = fopen("entrada.txt","r");
    int qnt = 0;
    fscanf(f,"%d",&qnt);

    tLista* banco = CriaLista();

    for(int i=0;i<qnt;i++)
    {
        char tipo;
        char nome[151];
        int cpf = 0;
        float valor = 0;
        fscanf(f," %c %s %d %f",&tipo,nome,&cpf,&valor);

        if(tipo == 'A')
        {
            tAluno* aluno = CriaAluno(nome,cpf,valor);
            InsereLista(banco,aluno,tipo);
        }
        else
        {
            tProfessor* prof = CriaProfessor(nome,cpf,valor);
            InsereLista(banco,prof,tipo);
        }
    }


    ImprimeRelatorio(banco);
    fclose(f);
    LiberaLista(banco);
    return 0;
}
