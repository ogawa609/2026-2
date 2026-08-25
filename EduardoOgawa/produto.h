#ifndef PRODUTO_H_
#define PRODUTO_H_


typedef struct Produto tProduto;

tProduto* criaProduto(char* nome,int id, float preco,int estoque);
int getIdProduto(tProduto* p);
float getPrecoProduto(tProduto* p);
char* getNomeProduto(tProduto* p);
int getEstoqueProduto(tProduto* p);
void liberaProduto(tProduto* p);
void incrementarEstoqueProduto(tProduto* p, int qnt);

#endif