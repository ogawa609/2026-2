#ifndef _ESTUDANTE_H
#define _ESTUDANTE_H

typedef struct estudante tEstudante;

tEstudante* CriaEstudante(char* nome,int matricula,float cr);
float getCr(tEstudante* e);
int getMatricula(tEstudante* e);
char* getNome(tEstudante* e);
void LiberaEstudante(tEstudante* e);


#endif