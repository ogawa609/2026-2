#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supermercado.h"
#include "filial.h"
#include "produto.h"

struct Supermercado 
{
    char* nome;
    int qntFiliais;
    tFilial** filiais;
    tProduto** produtos;
};

tSupermercado* criaSupermercado(char*nome,int qntFiliais)
{
    tSupermercado* s = malloc(sizeof(tSupermercado));

    s->nome = malloc((strlen(nome)+1)*sizeof(char));
    s->qntFiliais = qntFiliais;
    s->filiais = malloc(qntFiliais*sizeof(tFilial*));

    for(int i=0;i<qntFiliais;i++)
        s->filiais[i] = leFilial();
    
    return s;

}


tSupermercado* leSupermercado()
{
    char nome[101];
    int qntFiliais=0;

    scanf("%s",nome);
    scanf("%d",&qntFiliais);

    tSupermercado* s = criaSupermercado(nome,qntFiliais);

    return s;
}

int getEstoqueTotal(tSupermercado* s,int id)
{
    int total = 0;
    for(int i=0;i<s->qntFiliais;i++)
    {
        total += getEstoqueProdutoFilial(id,s->filiais[i]);
    }

    return total;
}

void liberaSupermercado(tSupermercado* s)
{
    free(s->nome);

    for(int i=0;i<s->qntFiliais;i++)
        liberaFilial(s->filiais[i]);
    
    free(s->filiais);
    free(s);
}