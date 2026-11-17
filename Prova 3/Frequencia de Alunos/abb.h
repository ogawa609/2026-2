#ifndef ABB_H
#define ABB_H

#include "aluno.h"

typedef struct abb Abb;
Abb* Cria();
Abb* CriaArv(Aluno* a, Abb* d, Abb* e);
Abb* Inserir(Abb* arv, Aluno* a);
void Liberar(Abb* arv);
Aluno* Buscar(Abb* arv, char* nome);
void Imprimir(Abb* arv);
#endif