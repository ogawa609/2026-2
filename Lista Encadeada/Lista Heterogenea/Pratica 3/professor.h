#ifndef _PROFESSOR_H
#defime _PROFESSOR_H

    typedef struct Professor tProfessor;
    tProfessor* CriaProfessor(char* nome, int cpf, float salario);
    void LiberaProfessor(tProfessor* p);

#endif