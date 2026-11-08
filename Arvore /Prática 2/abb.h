#ifndef ABB_H
#define ABB_H

#include "aluno.h"

typedef struct abb Abb;
Abb* CriaArvoreVazia();
Abb* CriaRamo(Aluno* a,Abb* e,Abb* d);
Abb* InsereElementoArv(Abb* a, Aluno* al);
int AlturaArvore(Abb* a);
void LiberaArv(Abb* a);
Abb* RetiraArv(Abb* a, int mat);
Aluno* BuscaAluno(Abb* a, char* nome);
void ImprimeArv(Abb* arv);

#endif