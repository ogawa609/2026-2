#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct Produto
{
    char* nome;
    int estoque;
    int id;
    float preco;
};

tProduto* criaProduto(char* nome,int id, float preco,int estoque)
{
    tProduto* p = malloc(sizeof(tProduto));
    p->id = id;
    p->estoque = estoque;
    p->preco = preco;

    p->nome = malloc((strlen(nome)+1)*sizeof(char));
    strcpy(p->nome,nome);

    return p;
}

int getIdProduto(tProduto* p)
{
    return p->id;
}

float getPrecoProduto(tProduto* p)
{
    return p->preco;
}

char* getNomeProduto(tProduto* p)
{
    return p->nome;
}

int getEstoqueProduto(tProduto* p)
{
    return p->estoque;
}

void incrementarEstoqueProduto(tProduto* p, int qnt)
{
    p->estoque += qnt;
}

void liberaProduto(tProduto* p)
{
    free(p->nome);
    free(p);
}