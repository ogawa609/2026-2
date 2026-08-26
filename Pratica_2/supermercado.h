#ifndef SUPERMERCADO_H_
#define SUPERMERCADO_H_

#include "filial.h"

typedef struct Supermercado tSupermercado;

tSupermercado* criaSupermercado(char*nome,int qntFiliais);
tSupermercado* leSupermercado();
void liberaSupermercado(tSupermercado* s);
int getQntFiliais(tSupermercado* s);
tFilial* getFilialSupermercado(tSupermercado* s, int i);
char* getNomeSupermercado(tSupermercado* s);

#endif