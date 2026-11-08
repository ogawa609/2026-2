#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;
Aluno* CriaAluno(char* nome, int mat);
void LiberaAluno(Aluno* a);
void ImprimeAluno(Aluno* a);
int GetMatriculaAluno(Aluno* a);

#endif