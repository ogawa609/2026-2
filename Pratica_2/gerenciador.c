#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciador.h"
#include "produto.h"
#include "filial.h"
#include "supermercado.h"

void Ativar()
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


//IMPRIMIR

    printf("Nome do Supermercado: %s\n",getNomeSupermercado(mercado));

    for(int i=0;i<getQntFiliais(mercado);i++)
    {
        tFilial* filial = getFilialSupermercado(mercado,i);
        printf("Filial: %s\n",getNomeFIlial(filial));
        printf("Estoque: %.2f\n",getValorFilial(filial,lista,qnt));

        imprimiProdutosFIlial(filial,lista,qnt);
    }

//LIBERAR MEMÓRIA

    liberaSupermercado(mercado);
    for(int i=0;i<qnt;i++)
        liberaProduto(lista[i]);
    free(lista);
}