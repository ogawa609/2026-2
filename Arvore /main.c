#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "arvore.h"

int main()
{
    Aluno* a1 = CriaAluno("ana",004);
    Aluno* a2 = CriaAluno("bea",002);
    Aluno* a3 = CriaAluno("ceci",003);
    Aluno* a4 = CriaAluno("di",004);
    Aluno* a5 = CriaAluno("edi",005);


    Arv* v1 = arv_cria(a1, arv_cria(a2,arv_cria(a4,arv_criavazia(),arv_criavazia()),arv_cria(a5,arv_criavazia(),
    arv_criavazia())),arv_cria(a3,arv_criavazia(),arv_criavazia()));


    arv_imprime(v1);

    printf("FOLHAS = %d\n\n",folhas(v1));

    printf("OCORRENCIAS = %d\n",ocorrencias(v1,004));

    LiberaAluno(a1);
    LiberaAluno(a2);
    LiberaAluno(a3);
    LiberaAluno(a4);
    LiberaAluno(a5);

    arv_libera(v1);

    return 0;
}