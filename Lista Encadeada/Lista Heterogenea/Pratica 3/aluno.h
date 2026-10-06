#ifndef _ALUNO_H
#define _ALUNO_H

    typedef struct Aluno tAluno;
    tAluno* CriaAluno(char* nome, int cpf, float cr);
    void LiberaAluno(tAluno* a);
#endif