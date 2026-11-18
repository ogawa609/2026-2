#ifndef EMAIL_H
#define EMAIL_H
typedef struct email Email;
Email* CriaEmail(char* email,char* mensagem);
void LiberaEmail(Email* e);
char* getPessoa(Email* e);
void ImprimirEmail(Email* e);
#endif