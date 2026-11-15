#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abb.h"

int main(int argc, char* argv[])
{
    Abb* arv = CriaArvVazia();

    char comando[151];

    while(1)
    {
        scanf("%s",comando);

        if(strcmp(comando,"STOP")==0)
            break;

        arv = Insere(arv,comando);
    }

    printf("\n===============ARVORE====================\n");
    Imprime(arv);
    printf("==========================================\n");

    printf("\nA ALTURA DA ARVORE EH: %d\n",Altura(arv));

    

    printf("\nRETIREM 1 PALAVRA POR VEZ\n");

    int flag = 0;
    int j=0;
    char busca[151];
    while(1)
    {

        char jogador[15];

        if(j%2==0)
            strcpy(jogador,"JOGADOR 1");
        else 
            strcpy(jogador,"JOGADOR 2");
        
        printf("\n-------------------------------------| %s |--------------------------------------\n",jogador);
        printf("\n VC TEM 3 TENTATIVAS PARA RETIRAR A PALAVRA\n");


        int fail = 1;
        for(int i=0; i<3;i++)
        {
            
            printf("\nTENTATIVA %d:\n",i+1);

           
                scanf("%s",busca);

                if(Existe(arv,busca)==0)
                    printf("\nESSA PALVRA NAO ESTA NA ARVORE! TENTE NOVAMENTE!\n");
                    
                
                else
                {
                    fail = 0;
                    break;
                }
        }
        


            if(fail)
            {
                
                flag = 1;
                break;
            }

           arv = Retira(arv,busca);

            printf("\n===============ARVORE====================\n");
            Imprime(arv);
            printf("==========================================\n");

    printf("\nA ALTURA DA ARVORE EH: %d\n",Altura(arv));

        printf("\n----------------------------------------------------------------------------\n");
        j++;
    }

    if(flag)
        printf("\nGAME OVER\n");


    printf("\n===============ARVORE====================\n");
    Imprime(arv);
    printf("==========================================\n");

    LiberaArv(arv);
    return 0;

}