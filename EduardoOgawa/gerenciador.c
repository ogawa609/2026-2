#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciador.h"
#include "produto.h"

void Leitura()
{
    
    int qnt = 0;
    scanf("%d",&qnt);

//LE CATALOGO DE PRODUTOS

    tProduto** lista = malloc(qnt*sizeof(tProduto*));

    for(int i=0;i<qnt;i++)
    {
        int id;
        float preco;
        char nome[101];

        scanf("%d %s %f",&id,nome,&preco);
        lista[i]  = criaProduto(nome,id,preco,0);
    }
//LE INFOS SUPERMERCADO E SUAS FILIAIS JUNTO COM PRODUTOS

    tSupermercado* mercado = leSupermercado();


//VINCULAR PRODUTOS FILIAIS COM CATALOGO

    for(int i=0;i<qnt;i++)
    {
        int idBuscado = getIdProduto(lista[i]);
        int estoque = getEstoqueTotal(mercado,idBuscado);
        incrementarEstoqueProduto(lista[i],estoque);
    }

//LIBERAR MEMÓRIA

    liberaSupermercado(mercado);
    for(int i=0;i<qnt;i++)
        liberaProduto(lista[i]);
    free(lista);
}