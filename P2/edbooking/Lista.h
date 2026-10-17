#ifndef _LISTA_H
#define _LISTA_H

#include "Reserva.h"
    typedef struct Lista tLista;
    tLista* CriaLista();
    void LiberaLista(tLista* l);
    void InsereLista(tLista* l,Reserva* r);
    void ImprimeLista(tLista* l);
    void RetiraLista(tLista* l, int id);

#endif
