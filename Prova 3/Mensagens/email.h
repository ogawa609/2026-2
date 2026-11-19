#ifndef EMAIL_H
#define EMAIL_H
typedef struct email Email;
Email* CriaEmail(char* email,char* mens);
void LiberaEmail(Email* e);
char* getPessoa(Email* e);
void ImprimirEmail(Email* e);
int ComparaPessoas(Email* p1, Email* p2);
void InserirMensagem(Email* e, char* mensagem);
int gerQnt(Email* e);
int compara(const void* a, const void* b);
#endif