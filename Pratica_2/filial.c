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

float getValorFilial(tFilial* f,tProduto**catalogo,int qnt)
{
    float total = 0;

    for(int i=0;i<f->estoque;i++)
    {

        int id = getIdProduto(f->listaProdutos[i]);
        float a = 0;

        for(int j=0;j<qnt;j++)
        {
            if(id==getIdProduto(catalogo[j]))
            {
                a = getPrecoProduto(catalogo[j]);
                break;
            }
        }
        int b = getEstoqueProduto(f->listaProdutos[i]);
        
       total +=(a*b);
    }

    return total;
}

tProduto* getProdutoFilial(tFilial* f,int i)
{
    return f->listaProdutos[i];
}

void imprimiProdutosFIlial(tFilial* f,tProduto** catalogo,int qnt)
{
    for(int i=0;i<f->estoque;i++)
    {
        tProduto* produto = f->listaProdutos[i];
        int estoque = getEstoqueProduto(produto);
        int id = getIdProduto(produto);
        int flag = 0;
        char* nome = NULL;
        float preco = 0;


        for(int j=0;j<qnt;j++)
        {
            if(id==getIdProduto(catalogo[j]))
            {
                flag = 1;
                nome = getNomeProduto(catalogo[j]);
                preco = getPrecoProduto(catalogo[j]);
                break;
            }
        }

        if(flag)
            printf("Item: %s, valor unitário: %.2f, quantidade: %d\n",nome,preco,estoque);
    }
}

