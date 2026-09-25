#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eduardo_ogawa.h"

#define PI 3.14

void calc_esfera (float r, float* area, float* volume)
{
    *area = 4.0*PI*r*r;
    *volume = (4*PI*r*r*r)/3.0;
}

int raizes (float a, float b, float c, float* x1, float* x2)
{

    float delta = (b*b)-4*a*c;

    if(delta<0)
        return 0;

    *x1 = ((-1*b) + sqrt(delta))/(2*a);
    *x2 = ((-1*b) - sqrt(delta))/(2*a);

    return 1;
}

int pares (int n, int* vet)
{
    int cont = 0;
    for(int i=0;i<n;i++)
    {
        if(vet[i]%2==0)
            cont++;
    }

    return cont;
}


void inverte (int n, int* vet)
{
    int temp;
    int f = n/2;
    for(int i=0;i<f;i++)
    {
         temp = vet[n-1];
        vet[n-1] = vet[i];
        vet[i] = temp;

        n--;
    }

    
}
double avalia (double* poli, int grau, double x)
{
    double valor = 0;

    for(int i=0;i<=grau+1;i++)
    {
        valor += poli[i] * pow(x,i);
    }

    return valor;
}

int** inverte2 (int n, int* vet)
{
    int**inv = malloc(n*sizeof(int*));

    for(int i=0;i<n;i++)
        inv[i] = malloc(sizeof(int));

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(vet[i]>vet[j])
            {
                int temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }

    for(int i=0;i<n;i++)
        *inv[i] = vet[i];

    return inv;
}