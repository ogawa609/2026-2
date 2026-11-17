#ifndef ALUNO_H
#define ALUNO_H
typedef struct aluno Aluno;
Aluno* CriaAluno(char* nome);
void PresencaAluno(Aluno* aluno, char presenca);
void LiberaAluno(Aluno* aluno);
void ImprimeAluno(Aluno* aluno);
char* GetNomeAluno(Aluno* a);
#endif