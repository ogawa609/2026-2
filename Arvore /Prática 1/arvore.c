#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


struct arvore
{
    Aluno* aluno;
    Arv* esquerda;
    Arv* direita;
};

//Cria uma árvore vazia
Arv* arv_criavazia (void)
{
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e com subárvore esquerda e a subárvore direita
Arv* arv_cria (Aluno* c, Arv* e, Arv* d)
{
    Arv* a = malloc(sizeof(Arv));

    a->aluno = c;
    a->direita = d;
    a->esquerda = e;

    return a;
}

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a)
{
    if(a != NULL)
    {
        arv_libera(a->direita);
        arv_libera(a->esquerda);
        free(a);
    }

   return NULL;
}

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (Arv* a)
{
    return a == NULL;
}

//indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int arv_pertence (Arv* a, int mat)
{
   if(arv_vazia(a))
    return 0;

    if(GetMatriculaAluno(a->aluno) == mat)
        return 1;

    return arv_pertence(a->direita,mat) || arv_pertence(a->esquerda,mat);

}

//imprime as informações dos nós da árvore <raiz e d> e <> (árvore vazia)
void arv_imprime (Arv* a)
{

      if(a == NULL)
        return;

    ImprimeAluno(a->aluno);

    arv_imprime(a->esquerda);
    arv_imprime(a->direita);
}

//retorna a mãe/pai de um dado no que contém o aluno com a matrícula mat
Arv* arv_pai (Arv* a, int mat)
{
   
    if(a == NULL)
        return NULL;

    if(a->esquerda != NULL &&
       GetMatriculaAluno(a->esquerda->aluno) == mat)
        return a;

    if(a->direita != NULL &&
       GetMatriculaAluno(a->direita->aluno) == mat)
        return a;

    Arv* resultado = arv_pai(a->esquerda, mat);

    if(resultado != NULL)
        return resultado;

    return arv_pai(a->direita, mat);


}

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a)
{
    
      if(a == NULL)
        return 0;

    if(a->esquerda == NULL && a->direita == NULL)
        return 1;

    return folhas(a->esquerda) + folhas(a->direita);
}

//retorna o numero de ocorrencias de um dado aluno na árvore
int ocorrencias (Arv* a, int mat)
{
    if(arv_vazia(a))
        return 0;
    
    if(GetMatriculaAluno(a->aluno) == mat)
        return 1 + ocorrencias(a->direita,mat) + ocorrencias(a->esquerda,mat);

     return 0 + ocorrencias(a->direita,mat) + ocorrencias(a->esquerda,mat);   
}