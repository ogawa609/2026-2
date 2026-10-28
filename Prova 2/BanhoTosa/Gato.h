#ifndef GATO_H
#define GATO_H
#include "Cachorro.h"
    typedef struct Gato Gato;
    Gato* inicGato(char* nome, Tipo pers);
    void liberaGato(Gato* pet);
    Tipo getTipoGato(Gato* g);
    char* getNomeGato(Gato* g);
    void ImprimirGato(Gato* g);
    void atribuiNivelAgressividadeGato(Gato* g, Tipo t);
    
#endif