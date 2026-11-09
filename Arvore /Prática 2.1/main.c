#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main()
{
    Abb* arv = CriaArvoreVazia();

    int elem = 0;
    while(1)
    {
        scanf("%d",&elem);

        if(elem == -1)
            break;
        
        arv = InsereArvore(elem,arv);
    }

    int op = 0;

    while(1)
    {
        printf("Digite a operacao:\n1)Insere\n2)Existe\n3)Retira\n4)Imprime\n5)Altura\n6)Num Elem\n7)Num Folhas\n\n");

        scanf("%d",&op);

        if(op==-1)
            break;

        else if(op == 1)
        {
            printf("Digite novo numero\n");
            int novo =0;
            scanf("%d",&novo);
            InsereArvore(novo,arv);
            printf("INSERIDO\n\n");
        }
        else if(op==2)
        {
            printf("Digite dado a ser buscado\n");
            int k;
            scanf("%d", &k);
            if(BuscaDado(arv,k))
                printf("EXISTE NA ÁRVORE!\n\n");
            else
                printf("NAO EXISTE\n\n");
        }
        else if(op == 3)
        {
            printf("Digite info a ser retirada\n");
            int k;
            scanf("%d",&k);
            arv = RetiraArv(arv,k);
            printf("RETIRADO\n\n");
        }
        else if(op == 4)
        {
            printf("========= ARVORE ============\n\n");
            Imprime(arv);
            printf("\n\n=============================\n\n");
        }
        else if(op == 5)
        {
            printf("A ALTURA EH: %d\n\n", Altura(arv));
        }
        else if(op== 6)
        {
            printf("ESSA ARVORE TEM %d ELEMENTOS\n\n",NumeroElementos(arv));
        }
        else if(op == 7)
        {
            printf("ESSA ARVORE TEM %d FOLHAS\n\n",NumeroFolhas(arv));
        }
    }

    LiberaArv(arv);
    return 0;
}