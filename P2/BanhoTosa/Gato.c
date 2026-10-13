#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gato.h"
#include "Cachorro.h"

enum Tipo
{
    BRAVO = 0,
    MANSO = 1
};

 struct Gato 
 {
    char* nome;
    Tipo personalidade;
 };

    Gato* inicGato(char* nome, Tipo pers)
    {
        Gato* g = malloc(sizeof(Gato));
        g->nome = strdup(nome);
        g->personalidade = pers;

        return g;
    }
    void liberaGato(Gato* pet)
    {
        free(pet->nome);
        
        free(pet);
    }

    Tipo getTipoGato(Gato* g)
    {
        return g->personalidade;
    }