#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

/* Define o tipo TPedido (tipo opaco). Estrutura interna deste tipo eh definida na implementacao do TAD.
 * Trata-se da sentinela da lista e deve conter as seguintes informacoes:
 * Dono do pedido (char*) e os campos prim e ult da sentinela
 */

 typedef struct Cel tCel;

 struct Cel
 {
    TProduto* produto;
    tCel* proximo;
 };

 struct pedido 
 {
    char* dono;
    tCel* primeiro;
    tCel* ultimo;
 };

/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido* InicPedido (char* dono)
{
    TPedido* p = malloc(sizeof(TPedido));
    p->primeiro = NULL;
    p->ultimo = NULL;
    p->dono = strdup(dono);

    return p;
}

/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
void IncluiProdutoPedido (TPedido* pedido, TProduto* prod)
{
    tCel* cel = malloc(sizeof(tCel));
    cel->produto = prod;
    cel->proximo = NULL;

    if(pedido->primeiro == NULL)
    {
        pedido->primeiro = cel;
        pedido->ultimo = cel;
        return;
    }

    pedido->ultimo->proximo = cel;
    pedido->ultimo = cel;

}

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
void ImprimePedido (TPedido* pedido)
{
    if(pedido->primeiro==NULL)
    {
        printf("Nao ha produtos neste pedido!\n");
        return;
    }
    printf("\nDONO DO PEDIDO: %s\n",pedido->dono);

    tCel* atual = pedido->primeiro;

    while(atual != NULL)
    {
       
        ImprimeIngredientes(atual->produto);

        atual = atual->proximo;
    }

}

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso ele exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido (TPedido* pedido, char* prod)
{
    tCel* atual = pedido->primeiro;
    tCel* ant = NULL;

    while(atual != NULL)
    {
        tCel* prox = atual->proximo;
        if(strcmp(prod,RetornaNome(atual->produto))==0)
        {
            if(atual == pedido->primeiro && atual == pedido->ultimo)
            {
                pedido->primeiro = NULL;
                pedido->primeiro = NULL;
                free(atual);
                return;
            }
            if(atual == pedido->primeiro)
            {
                pedido->primeiro = atual->proximo;
                free(atual);
                return;
            }
            if(atual == pedido->ultimo)
            {
                pedido->ultimo = ant;
                ant->proximo = NULL;
                free(atual);
                return;
            }

            ant->proximo = atual->proximo;
            free(atual);
            return;
        }
        else
        {
            ant = atual;
            atual = prox;
        }

    }
}

//A função envia pedido verifica se há restrição calórica ou restrição alimentar
//Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
//Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: nPedido não Enviado! Restricao alimentar no produto: %s\n
* Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar)
{
    tCel* atual = pedido->primeiro;
    int cal = 0;

    while(atual != NULL)
    {
        cal += Calorias(atual->produto);
        atual = atual->proximo;

    }

    if(cal>restricao_calorica)
    {
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }

    atual = pedido->primeiro;

    while(atual != NULL)
    {
        if(VerificaIngrediente(atual->produto,restricao_alimentar))
        {
            printf("nPedido não Enviado! Restricao alimentar no produto: %s\n",RetornaNome(atual->produto));
            return 0;
        }

        atual = atual->proximo;
    }

    tCel* principal = pedido->primeiro;

    while(principal != NULL)
    {
        tCel* proximo = principal->proximo;

        free(principal);

        principal = proximo;
    }
    free(pedido->dono);
    free(pedido);
}
