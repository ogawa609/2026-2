#ifndef CACHORRO_H
#define CACHORRO_H

    typedef struct Cachorro Cachorro;

    typedef enum tipo 
    {
        BRAVO = 0,
        MANSO = 1

    }Tipo;

    Cachorro* inicCachorro(char* nome,Tipo pers);
    void liberaCachorro(Cachorro* pet);
    Tipo getTipoCachorro(Cachorro* c);
    char* getNomeCachorro(Cachorro* c);
    void ImprimirCachorro(Cachorro* c);
    void atribuiNivelAgressividadeCachorro(Cachorro* g, Tipo t);
#endif