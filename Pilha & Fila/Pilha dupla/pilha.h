#ifndef PILHA_H
#define PILHA_H

#include "aluno.h"

typedef struct pilha Pilha;
Pilha* CriaPilha();
void LiberaPilha(Pilha* p);
void PushPilha1(Pilha* p, Aluno* a);
void PushPilha2(Pilha* p, Aluno* a);
Aluno* PopPilha1(Pilha* p);
Aluno* PopPilha2(Pilha* p);
int PilhaCheia(Pilha* p);
void ImprimePilha(Pilha* p);

#endif