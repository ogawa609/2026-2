#include <stdio.h>
#include <stdlib.h>
#include "eduardo_ogawa.h"


int main()
{

    float* area = (float*) malloc(sizeof(float));
    float* volume = (float*) malloc(sizeof(float));
    float* x1 = (float*) malloc(sizeof(float));
    float* x2 = (float*) malloc(sizeof(float));

    int op;

    while(1)
    {

        printf("Escolha 1,2,3,4,5 ou 6 para selecionar a função e 0 para sair:\n");
        scanf("%d",&op);

        if(op==0)
            break;

        else if(op==1)
        {
            float raio = 0;
            printf("Digite um raio:\n");
            scanf("%f",&raio);
    
            calc_esfera(raio,area,volume);
            printf("Para raio %.2f a esfera tem Área = %.2f e Volume = %.2f\n",raio,*area,*volume);
        }
        else if(op==2)
        {
            float a,b,c;
            printf("Digite valores para a,b,c e obtenha suas raízes:\n");
            scanf("%f %f %f",&a,&b,&c);
            int flag = raizes(a,b,c,x1,x2);

            if(!flag)
                printf("Não existe raiz real\n");
            else
                printf("As raízes x1 e x2 obtidas são respectivamente: %.2f %.2f\n",*x1,*x2);
        }
        else if(op==3)
        {
            int a,b;
            printf("Digite o inicio e final do seu intervalo:\n");
            scanf("%d %d",&a,&b);

            if(a>b)
                printf("Intervalo invalido\n");
            else
            {
                int* vet = (int*) malloc(sizeof(int));
                int tam = 0;

                for(int i=a;i<b;i++)
                {
                    vet[tam] = i;
                    tam ++;
                    vet = (int*) realloc(vet,(tam+1)*sizeof(int));
                }

                int cont = pares(tam,vet);
                printf("A quantidade de pares do intervalo é: %d\n",cont);

                free(vet);
            }
        }
        else if(op==4)
        {
            int n;
            printf("Digite o tamanho do intervalo:\n");
            scanf("%d",&n);
            int* vet = (int*) malloc(n*sizeof(int));
            printf("Digite seu intervalo:\n");

            for(int i=0;i<n;i++)
                scanf("%d",&vet[i]);
            

            inverte(n,vet);

            printf("O vetor invertido é:\n");

            for(int i=0;i<n;i++)
                printf("%d ",vet[i]);
        
            printf("\n");

            free(vet);

        }
        else if(op==5)
        {
            printf("Digite o X o grau e os coeficientes (comecando pelo coeficiente do menor grau):\n");
            double x;
            int grau;
            scanf("%lf %d",&x,&grau);
            double* poli = (double*) malloc((grau+1)*sizeof(double));

            for(int i=0;i<=grau;i++)
                scanf("%lf",&poli[i]);
            

            double resultado = avalia(poli,grau,x);
            printf("O resultado é: %.2lf\n",resultado);

            free(poli);
        }

        else if(op==6)
        {
            int n;
            printf("DIgite o numero de elementos do vetor:\n");
            scanf("%d",&n);

            printf("Digite o vetor:\n");
            int vet[n];
            for(int i=0;i<n;i++)
                scanf("%d",&vet[i]);
        
            int** inv;
            inv = inverte2(n,vet);

            printf("O vetor é:\n");
            for(int i=0;i<n;i++)
                printf("%d ",*inv[i]);
            
            printf("\n");

            for(int i=0;i<n;i++)
                free(inv[i]);

            free(inv);
        }

    }

    free(area);
    free(volume);
    free(x1);
    free(x2);

    return 0;

}