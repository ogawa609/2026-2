#ifndef ABB_H
#define ABB_H

#include "email.h"
typedef struct abb Abb;
Abb* Cria();
Abb* CriaArv(Email* e, Abb* d,Abb* es);
Abb* Insere(Email* e, Abb* arv);
int totalMensagens(Abb* arv);
int NumeroUsuarios(Abb* arv);
Email* maiorUsuario(Abb* raiz, Abb* atual);
void LibrarArv(Abb* arv);
void Imprimir(Abb* arv);
int Existe(Abb* arv, char* chave);
Email* Busca(Abb* arv, char* chave);
int Transfere(Abb* arv, Email** vet, int i);


#endif