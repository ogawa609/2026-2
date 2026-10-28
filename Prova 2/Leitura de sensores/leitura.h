#ifndef LEITURA_H
#define LEITURA_H

#include "pessoa.h"
typedef struct Leituras tLeituras;
tLeituras* CriaLeitura(char* nome);
void LiberaLeitura(tLeituras* l);
void InsereLeitura(tLeituras* l, tPessoa* p);
char* GetNomeLeitura(tLeituras* l);
void ImprimeLeituras(tLeituras* l);
void RetiraOutiliers(tLeituras* l);
#endif