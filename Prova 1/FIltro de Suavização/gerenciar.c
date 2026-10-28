#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filtro.h"
#include "gerenciar.h"


 void ATIVAR()
 {
    FILE* f = fopen("entrada","r");
    

    int linha = 0;
    int coluna = 0;

    fscanf(f,"%d",&linha);
    fscanf(f,"%d",&coluna);

    tMatriz* mat = CriaMatriz(linha,coluna);

    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
        {
            int elem;
            fscanf(f,"%d",&elem);
            Inserir(mat,i,j,elem);
        }
    }

    fclose(f);

    tMatriz* suav = SuavizaMatriz(mat);

    FILE* arq = fopen("saida","w");
    ImprimeMatriz(mat,arq);
    
    fprintf(arq,"\n\nA matriz com filtro de suavização eh:\n");

    ImprimeMatriz(suav,arq);

    fclose(arq);

    LiberaMatriz(mat);
    LiberaMatriz(suav);

 }