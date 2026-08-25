#ifndef SUPERMERCADO_H_
#define SUPERMERCADO_H_

typedef struct Supermercado tSupermercado;

tSupermercado* criaSupermercado(char*nome,int qntFiliais);
tSupermercado* leSupermercado();
void liberaSupermercado(tSupermercado* s);
int getEstoqueTotal(tSupermercado* s,int id);

#endif