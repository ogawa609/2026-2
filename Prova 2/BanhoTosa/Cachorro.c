#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"

struct Cachorro 
{
    char* nome;
    Tipo personalidade;
};
    Cachorro* inicCachorro(char* nome,Tipo pers)
    {
        Cachorro* c = malloc(sizeof(Cachorro));
        c->nome = strdup(nome);
        c->personalidade = pers;

        return c;
    }
    void liberaCachorro(Cachorro* pet)
    {
        free(pet->nome);
        free(pet);
    }

    Tipo getTipoCachorro(Cachorro* c)
    {
        return c->personalidade;
    }

     char* getNomeCachorro(Cachorro* c)
     {
        return c->nome;
     }

     void ImprimirCachorro(Cachorro* c)
     {
        printf("CACHORRO -> %s\n",c->nome);
     }

      void atribuiNivelAgressividadeCachorro(Cachorro* g, Tipo t)
      {
        g->personalidade = t;
      }
