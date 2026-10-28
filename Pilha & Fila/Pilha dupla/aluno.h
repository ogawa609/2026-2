#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;
Aluno* CriaAluno(char* nome, int matricula);
void LiberaAluno(Aluno* a);
char* GetNomeAluno(Aluno* a);
int GetMatriculaAluno(Aluno* a);
void ImprimeAluno(Aluno* a);

#endif