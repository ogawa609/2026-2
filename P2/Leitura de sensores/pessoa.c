#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

 struct Pessoa 
 {
    
    int latitude;
    int longitude;
    float temperatura;
 };

tPessoa* CriaPessoa(int lat, int longi, float temp)
{
    tPessoa* p = malloc(sizeof(tPessoa));
    p->latitude = lat;
    p->longitude = longi;
    p->temperatura = temp;
    

    return p;
}

void LiberaPessoa(tPessoa* p)
{
    free(p);
}


float GetTempPessoa(tPessoa* p)
{
    return p->temperatura;
}
void ImprimePessoa(tPessoa* p)
{
    printf("%d %d %.2f\n",p->latitude,p->longitude,p->temperatura);
}
int GetLatitude(tPessoa* p)
{
    return p->latitude;
}
int GetLongitude(tPessoa* p)
{
    return p->longitude;
}