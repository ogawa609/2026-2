#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "email.h"

 struct email 
 {
    char* usuario;
    char* mensagens[10];
    int qnt;
 };
Email* CriaEmail(char* email,char* mens)
{
    Email* e = malloc(sizeof(Email));
    e->usuario = strdup(email);
    e->mensagens[0] = strdup(mens);
   e->qnt = 1;

    return e;
}
void LiberaEmail(Email* e)
{
    for(int i=0;i<e->qnt;i++)
        free(e->mensagens[i]);
    
    free(e->usuario);
    free(e);
}
char* getPessoa(Email* e)
{
    return e->usuario;
}
void ImprimirEmail(Email* e)
{
    printf("%s\n",e->usuario);
    for(int i=0;i<e->qnt;i++)
    {
        printf("    %s\n",e->mensagens[i]);
    }
}

int ComparaPessoas(Email* p1, Email* p2)
{
    return strcmp(p1->usuario,p2->usuario) == 0;
}
void InserirMensagem(Email* e, char* mensagem)
{
    if(e->qnt<10)
    {
        e->mensagens[e->qnt] = strdup(mensagem);
        e->qnt++;
    }
}
int gerQnt(Email* e)
{
    return e->qnt;
}

int compara(const void* a, const void* b)
{
    Email* aa = *(Email**)a;
    Email* bb = *(Email**)b;


    return (aa->qnt - bb->qnt);
}