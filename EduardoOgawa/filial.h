#ifndef FILIAL_H_
#define FILIAL_H_

typedef struct Filial tFilial;

tFilial* criaFilial(char* nome, int estoque);
tFilial* leFilial();
void liberaFilial(tFilial* f);
char* getNomeFIlial(tFilial* f);
int getEstoqueFilial(tFilial* f);
int getEstoqueProdutoFilial(int id,tFilial* f);


#endif