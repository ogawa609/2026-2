#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"

enum Tipo
{
    BRAVO = 0,
    MANSO = 1
};

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
