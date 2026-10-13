#ifndef CACHORRO_H
#define CACHORRO_H

    typedef struct Cachorro Cachorro;
    typedef enum Tipo Tipo;
    Cachorro* inicCachorro(char* nome,Tipo pers);
    void liberaCachorro(Cachorro* pet);
    Tipo getTipoCachorro(Cachorro* c);
#endif