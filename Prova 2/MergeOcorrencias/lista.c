#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/*TipoItem Aluno (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD. Devem ser definidos campos:
 - nome (string)
 - matricula (int) */
 struct aluno 
 {
    char* nome;
    int matricula;
 };

 typedef struct Cel tCel;

 struct Cel
 {
    TAluno* aluno;
    tCel* proximo;
 };
/*Tipo que define a lista (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD.
 Usar lista COM Sentinela */
 struct lista 
 {
    tCel* primeiro;
    tCel* ultimo;
 };

/*Inicializa o sentinela de uma lista
 * inputs: nenhum
 * output: Sentinela inicializado (lista vazia)
 * pre-condicao: nenhuma
 * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL */
TLista* CriaLista()
{
    TLista* l = malloc(sizeof(TLista));
    l->primeiro = NULL;
    l->ultimo = NULL;

    return l;
}

/*Inicializa um TipoItem aluno
 * inputs: o nome e a matricula do aluno
 * output: um ponteiro para o tipo TAluno criado
 * pre-condicao: nome e matricula validos
 * pos-condicao: tipo TAluno criado, com os campos nome e matricula COPIADOS */
TAluno* InicializaAluno(char* nome, int matricula)
{
    TAluno* a = malloc(sizeof(TAluno));
    a->matricula = matricula;
    a->nome = strdup(nome);

    return a;
}

/*Insere um aluno na primeira posicao da lista de alunos
 * inputs: aluno a ser inserido na lista (do tipo TAluno) e a lista
 * output: nenhum
 * pre-condicao: aluno n�o NULL e lista n�o NULL (mas, a lista pode estar vazia)
 * pos-condicao: lista contem o aluno inserido na primeira posicao */
void InsereAluno (TLista* lista, TAluno* aluno)
{
    tCel* nova = malloc(sizeof(tCel));
    nova->aluno = aluno;
    nova->proximo = NULL;

    if(lista->primeiro == NULL)
    {
        lista->primeiro = lista->ultimo = nova;
        return;
    }

    lista->ultimo->proximo = nova;
    lista->ultimo = nova;
        
}

/*Retira a primeira ocorrencia de um aluno de matricula mat da lista de alunos
 * inputs: a lista e a matricula do aluno a ser retirado da lista
 * output: o aluno (do tipo TAluno) retirado da lista ou NULL, se o aluno nao se encontrar na lista
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem a primeira ocorrencia do aluno de matricula mat */
TAluno* Retira (TLista* lista, int mat)
{
    tCel* atual = lista->primeiro;

    while(atual != NULL)
    {
        tCel* prox = atual->proximo;
        tCel* ant = NULL;
        TAluno* temp = atual->aluno;

        if(mat == atual->aluno->matricula)
        {
            if(atual == lista->primeiro && atual == lista->ultimo)
                lista->primeiro = lista->ultimo = NULL;
            else if(atual == lista->primeiro)
                lista->primeiro = atual->proximo;
            else if(atual == lista->ultimo)
            {
                lista->ultimo = ant;
                ant->proximo = NULL;
            }
            else
                ant->proximo = atual->proximo;

            free(atual);
            return temp;
        }

        ant = atual;
        atual = prox;
    }
}

/* Retira as repeticoes na lista. Ou seja, deixa apenas uma referencia para cada aluno na lista
 * inputs: a lista
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem repeticoes de alunos - APENAS UMA OCORRENCIA DE CADA ALUNO */
void RetiraRepetidos (TLista* lista)
{
    for(tCel* obj = lista->primeiro; obj != NULL; obj = obj->proximo)
    {
        int matricula = obj->aluno->matricula;

        tCel* atual = obj->proximo;
        tCel* ant = obj;

        while(atual != NULL)
        {
            tCel* prox = atual->proximo;

            if(atual->aluno->matricula == matricula)
            {
                
                if(atual == lista->ultimo)
                {
                    lista->ultimo = ant;
                    ant->proximo = NULL;
                }
                else
                    ant->proximo = atual->proximo;

                free(atual);
            }
            else
                ant = atual;

            
            atual = prox;

        }
    }
}


/* Intercala os alunos das turmas 1 e 2 em uma nova lista. Por exemplo, se a turma 1 tiver (a1->a2->a3) e a turma 2 tiver (b1->b2->b3->b4->b5), a funcao deve retornar uma nova lista formada pelos elementos (a1->b1->a2->b2->a3->b3->b4->b5). Se uma das  listas tiver mais elementos que a outra, os elementos excedentes s�o transferidos na mesma ordem para a nova lista. As listas originais devem ficar vazias (com sentila prim e ult apontando para NULL).
 * inputs: duas listas n�o nulas (por�m, podem estar vazias)
 * output: uma nova lista com os elementos intercalados
 * pre-condicao: listas turma1 e turma2 nao sao NULL (mas podem estar vazias)
 * pos-condicao: lista retornada contem os elementos intercalados. As listas de entrada vazias (apenas com sentinela). */
TLista* Merge (TLista* turma1, TLista* turma2)
{
    if(turma1->primeiro == NULL && turma2->primeiro == NULL)
    {
        return NULL;
    }

    TLista* merge = CriaLista();

    if(turma1->primeiro == NULL)
    {
        merge->primeiro = turma2->primeiro;
        merge->ultimo = turma2->ultimo;
        return merge;
    }

    tCel* a1 = turma1->primeiro;
    tCel* a2 = turma2->primeiro;

}

/* Libera a memoria alocada para o aluno
 * inputs: o aluno do tipo TAluno*
 * output: nenhum
 * pre-condicao: aluno n�o NULL
 * pos-condicao: toda a memoria alocada para o aluno foi liberada (inclusive para o nome) */
void LiberaAluno (TAluno* aluno)
{
    free(aluno->nome);
    free(aluno);
}

/*Imprime os dados de todos os alunos da lista
 * inputs: a lista de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas, pode estar vazia)
 * pos-condicao: dados dos alunos impressos na saida padrao */
void Imprime (TLista* lista);

/*Libera toda a memoria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
 * inputs: a lista encadeada de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: toda memoria alocada eh liberada (use valgrind!) */
void LiberaLista (TLista* lista)
{
    tCel* atual = lista->primeiro;

    while(atual != NULL)
    {
        tCel* prox = atual->proximo;
        LiberaAluno(atual->aluno);
        free(atual);

        atual = prox;
    }

    free(lista);
}