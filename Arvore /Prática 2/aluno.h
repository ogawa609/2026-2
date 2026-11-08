#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;
Aluno* CriaAluno(char* nome, int mat);
void LiberaAluno(Aluno* a);
char* GetNomeAluno(Aluno* a);
int GetMatriculaAluno(Aluno* a);
void ImprimirAluno(Aluno* a);
int ComparaNome(Aluno* a1, Aluno* a2);

#endif