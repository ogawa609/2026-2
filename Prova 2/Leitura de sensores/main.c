#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pessoa.h"

int main()
{
    FILE* f = fopen("entrada.txt","r");
    tLista* pessoas = CriaLista();

    char nome[151];
    int latitude;
    int longitude;
    float temperatura;

    while(fscanf(f,"%s %d %d %f",nome,&latitude,&longitude,&temperatura) != EOF)
    {
        tPessoa* pes = CriaPessoa(latitude,longitude,temperatura);
        InsereLista(pessoas,pes,nome);

    }

    ImprimeLista(pessoas);

    fclose(f);

    printf("==== sem os outliers ====\n\n");

    OrganizaLista(pessoas);

    ImprimeLista(pessoas);

    
    LiberaLista(pessoas);
    return 0;
}