#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"
#include "email.h"


int main()
{
    Abb* arv= Cria();

    FILE* entrada = fopen("entrada.txt","r");

    char usuario[151];
    char mensagem[501];

    while(fscanf(entrada,"%s %[^\n]",usuario,mensagem) != EOF)
    {
        if(Existe(arv,usuario))
        {
            Email* existente = Busca(arv,usuario);

            InserirMensagem(existente,mensagem);
        }
        else
        {
            Email* novo = CriaEmail(usuario,mensagem);
            arv = Insere(novo,arv);
        }
            

    }

    Imprimir(arv);

    printf("------------------------------------------------------\n\n");
    printf("Número total de usuários: %d\n",NumeroUsuarios(arv));
    printf("Número total de mensagens: %d\n",totalMensagens(arv));

    Email* user = maiorUsuario(arv,arv);
    printf("Usuário com maior número de mensagens: %s\n",getPessoa(user));

    fclose(entrada);

    int tam = NumeroUsuarios(arv);
    Email** pessoas = malloc(tam*sizeof(Email*));

    Transfere(arv,pessoas,0);
    qsort(pessoas,tam,sizeof(Email*),compara);

    for(int i=0;i<tam;i++)
    {
        ImprimirEmail(pessoas[i]);
    }
    LibrarArv(arv);
    free(pessoas);

    return 0;
}