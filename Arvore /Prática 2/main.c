#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "abb.h"


int main()
{
    FILE* entrada = fopen("entrada.txt","r");

    Abb* arvore = CriaArvoreVazia();
    int altura = 0;
    int n = 0;
    fscanf(entrada,"%d",&n);

    for(int i=0;i<n;i++)
    {
        char nome[151];
        int mat;

        fscanf(entrada,"%d %s",&mat,nome);

        Aluno* aluno = CriaAluno(nome,mat);
        arvore = InsereElementoArv(arvore,aluno);
    }

    printf("<<< LISTA ALUNOS: >>>\n");
    ImprimeArv(arvore);
    altura = AlturaArvore(arvore);
    printf("ALTURA = %d\n",altura);

    printf("EXCLUINDO:\n");
    char chave[151];
    while(fscanf(entrada,"%s",chave) != EOF)
    {
        Aluno* temp = BuscaAluno(arvore,chave);
        ImprimirAluno(temp);
        int c = GetMatriculaAluno(temp);
        arvore = RetiraArv(arvore,c);
    }

    printf("<<< LISTA NOVA: >>>\n");
    ImprimeArv(arvore);
    altura = AlturaArvore(arvore);
    printf("ALTURA = %d\n\n",altura);

    LiberaArv(arvore);
    fclose(entrada);
    return 0;
}