#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filial.h"
#include "produto.h"

//Estrutura de dados com tecnicas em programação em C

struct Filial
{
    char* nome;
    int estoque;
    tProduto** listaProdutos;
    
};

tFilial* criaFilial(char* nome, int estoque)
{
    tFilial* f = malloc(sizeof(tFilial));
    f->nome = malloc((strlen(nome)+1)*sizeof(char));
    strcpy(f->nome,nome);
    f->estoque = estoque;
    f->listaProdutos = malloc(estoque*sizeof(tProduto*));

    for(int i=0;i<estoque;i++)
    {
        int id,qnt;
        scanf("%d %d",&id,&qnt);
        f->listaProdutos[i] = criaProduto(nome,id,0,qnt);
    }
        

    return f;
}

tFilial* leFilial()
{
    int estoque = 0;
    char nome[101];

    scanf("%s",nome);
    scanf("%d",&estoque);

    tFilial* f = criaFilial(nome,estoque);
    return f;
}

void liberaFilial(tFilial* f)
{
    free(f->nome);

    for(int i=0;i<f->estoque;i++)
        liberaProduto(f->listaProdutos[i]);

    free(f->listaProdutos);
    free(f);
}


char* getNomeFIlial(tFilial* f)
{
    return f->nome;
}

int getEstoqueFilial(tFilial* f)
{
    return f->estoque;
}

int getEstoqueProdutoFilial(int id,tFilial* f)
{
    for(int i=0;i<f->estoque;i++)
    {
        if(id==getIdProduto(f->listaProdutos[i]))
        {
            return getEstoqueProduto(f->listaProdutos[i]);
        }
    }
}

