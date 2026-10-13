#ifndef GATO_H
#define GATO_H



    typedef struct Gato Gato;
    typedef enum Tipo Tipo;
    Gato* inicGato(char* nome, Tipo pers);
    void liberaGato(Gato* pet);
    Tipo getTipoGato(Gato* g);
    
#endif