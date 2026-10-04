#ifndef _ALUNO_H
#define _ALUNO_H

typedef struct Aluno tAluno;
tAluno* CriaAluno(char* nome, int matricula, char* curso);
tAluno* LeAluno();
void ImprimeAluno(tAluno* a);
void LiberaAluno(tAluno* a);
int getMatricula(tAluno* a);

#endif