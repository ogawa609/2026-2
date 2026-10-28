#include <stdio.h>
#include "pilha.h"
#include "aluno.h"


int main()
{
    Pilha* pilhas = CriaPilha();

    Aluno* a1 = CriaAluno("Ana",000);
    Aluno* a2 = CriaAluno("Ber",001);
    Aluno* a3 = CriaAluno("Cia",002);
    Aluno* a4 = CriaAluno("Du",003);
    Aluno* a5 = CriaAluno("Edi",004);
    Aluno* a6 = CriaAluno("Fi",005);
    Aluno* a7 = CriaAluno("Gi",006);

    PushPilha1(pilhas,a1);
    PushPilha1(pilhas,a2);
    PushPilha1(pilhas,a3);
    PushPilha1(pilhas,a4);

    PushPilha2(pilhas,a5);
    PushPilha2(pilhas,a6);
    PushPilha2(pilhas,a7);

    ImprimePilha(pilhas);

   Aluno* t1 =  PopPilha1(pilhas);
   Aluno* t2 =  PopPilha2(pilhas);

    ImprimePilha(pilhas);

    LiberaPilha(pilhas);
    LiberaAluno(a1);
    LiberaAluno(a2);
    LiberaAluno(a3);
    LiberaAluno(a4);
    LiberaAluno(a5);
    LiberaAluno(a6);
    LiberaAluno(a7);

    return 0;
}