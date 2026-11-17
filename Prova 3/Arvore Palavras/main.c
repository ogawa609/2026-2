#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

int main(int argc, char* argv[])
{
    FILE* entrada = fopen("entrada.txt","r");
    Abb* arv = CriaVazia();

    char palavra[151];
    int freq = 0;

    while(fscanf(entrada,"%s %d",palavra,&freq) != EOF)
        arv = Insere(arv,palavra,freq);

    Imprime(arv);
    printf("------------------------\n");

    int pU = PalavrasUnicas(arv);
    int total = TotalPalavras(arv);
    int maior = Maior(arv);

    printf("%d palavras distintas encontradas\n",pU);
    printf("%d palavras no total\n",total);
    printf("de é a palavra de maior frequência (%d)\n",maior);


    fclose(entrada);
    Libera(arv);
    return 0;
    
}