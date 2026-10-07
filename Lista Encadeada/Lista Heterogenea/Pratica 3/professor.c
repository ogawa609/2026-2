#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct Professor 
{
    char* nome;
    int cpf;
    float salario;
};
    tProfessor* CriaProfessor(char* nome,int cpf,float salario)
    {
        tProfessor* p = malloc(sizeof(tProfessor));
        p->nome = strdup(nome);
        p->cpf = cpf;
        p->salario = salario;

        return p;
    }

    void LiberaProfessor(tProfessor* p)
    {
        free(p->nome);
        free(p);
    }

     void ImprimeProfesor(tProfessor* p)
     {
        printf("%s, CPF: %d e Salário: %.2f\n",p->nome,p->cpf,p->salario);
     }

     float GetSalarioProf(tProfessor* p)
     {
        return p->salario;
     }


