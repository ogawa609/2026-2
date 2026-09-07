#include <stdio.h>
#include "matriz.h"



void AtivaPrograma()
{
    int linha,coluna;
    FILE* f = fopen("entrada","r");
    fscanf(f,"%d",&linha);
    fscanf(f,"%d",&coluna);
    Matriz* mat = inicializaMatriz(linha,coluna);

    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
        {
            int elem = 0;
            fscanf(f,"%d",&elem);
            modificaElemento(mat,i,j,elem);
        }
    }
    fclose(f);

    imprimeMatriz(mat);

    while(1)
    {

    
        int op;
        printf("Digite o numero da operacao que vc deseja:\n");
        printf("0)Sair\n1) Mudar elemento\n2)Imprimir Linha\n3)Matriz Transposta\n4)Multiplicar pela Transposta\n\n");
        scanf("%d",&op);

        if(op==0)
            break;

        else if(op==1)
        {
            int trocaElem,nlinha,ncoluna;
            printf("Digite a posicao (linha/coluna) que vc quer modificar e o elemento que será substituido:\n");
            scanf("%d %d %d",&nlinha,&ncoluna,&trocaElem);

            if(nlinha<0||nlinha>linha-1||ncoluna<0||ncoluna>coluna-1)
            {
                printf("\nEntrada linha ou coluna inválido\n\n");
            }
            else
            {
                modificaElemento(mat,nlinha,ncoluna,trocaElem);
                imprimeMatriz(mat);
            }
            
        }

        else if(op==2)
        {
            printf("\nDigite a linha que vc quer imprimir:\n\n");
            int pos;
            scanf("%d",&pos);

            if(pos<0||pos>linha-1)
            {
                printf("\nNumero da linha invalido\n\n");
            }
            else
                imprimeLinha(mat,pos);
        }

        else if(op==3||op==4)
        {

            Matriz* trsp = transposta(mat);
            if(op==3)
            {
                printf("A matriz transposta eh:\n");
                imprimeMatriz(trsp);
            }
            else
            {
                Matriz* mult = multiplicacao(mat,trsp);
                printf("A matriz multiplicacao eh:\n");
                imprimeMatriz(mult);
                destroiMatriz(mult);
            }

            destroiMatriz(trsp);
        }
    

    }

    destroiMatriz(mat);
    
}