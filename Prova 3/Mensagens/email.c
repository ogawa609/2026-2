#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "email.h"

 struct email 
 {
    char* usuario;
    char* mensagem;
 };
Email* CriaEmail(char* email,char* mensagem)
{
    Email* e = malloc(sizeof(Email));
    e->usuario = strdup(email);
    e->mensagem = strdup(mensagem);

    return e;
}
void LiberaEmail(Email* e)
{
    free(e->mensagem);
    free(e->usuario);
    free(e);
}
char* getPessoa(Email* e)
{
    return e->usuario;
}
void ImprimirEmail(Email* e)
{
    printf("%s %s\n",e->usuario,e->mensagem);
}