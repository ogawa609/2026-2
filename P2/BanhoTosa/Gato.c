#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gato.h"
#include "Cachorro.h"

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

    char* getNomeGato(Gato* g)
    {
        return g->nome;
    }

    void ImprimirGato(Gato* g)
    {
        printf("GATO -> %s\n",g->nome);
    }

    void atribuiNivelAgressividadeGato(Gato* g, Tipo t)
    {
        g->personalidade = t;
    }