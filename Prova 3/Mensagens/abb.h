#ifndef ABB_H
#define ABB_H

#include "email.h"
typedef struct abb Abb;
Abb* Cria();
Abb* CriaArv(Email* e, Abb* d,Abb* es);
Abb* Insere(Email* e, Abb* arv);
int totalMensagens(Abb* arv);
int NumeroUsuarios(Abb* arv);
Email* maiorUsuario(Abb* arv);
void LibrarArv(Abb* arv);
void Imprimir(Abb* arv);


#endif