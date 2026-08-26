#ifndef FILIAL_H_
#define FILIAL_H_

#include "filial.h"
#include "produto.h"
typedef struct Filial tFilial;

tFilial* criaFilial(char* nome, int estoque);
tFilial* leFilial();
void liberaFilial(tFilial* f);
char* getNomeFIlial(tFilial* f);
int getEstoqueFilial(tFilial* f);
float getValorFilial(tFilial* f,tProduto**c,int q);
tProduto* getProdutoFilial(tFilial* f,int i);
void imprimiProdutosFIlial(tFilial* f,tProduto** catalogo,int qnt);


#endif