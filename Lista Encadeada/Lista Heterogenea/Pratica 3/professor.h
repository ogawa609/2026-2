#ifndef _PROFESSOR_H
#define _PROFESSOR_H

    typedef struct Professor tProfessor;
    tProfessor* CriaProfessor(char* nome, int cpf, float salario);
    void LiberaProfessor(tProfessor* p);
    void ImprimeProfesor(tProfessor* p);
    float GetSalarioProf(tProfessor* p);

#endif