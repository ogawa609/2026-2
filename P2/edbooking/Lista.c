#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct Cel tCel;

struct Cel
{
    Reserva* reserva;
    tCel* proxima;
    tCel* anterior;
};

struct Lista
{
    tCel* primeira;
    tCel* ultima;
};

    tLista* CriaLista()
    {
        tLista* l = malloc(sizeof(tLista));
        l->primeira = NULL;
        l->ultima = NULL;
        return l;
    }

    void LiberaLista(tLista* l)
    {
        tCel* atual = l->primeira;

        while(atual != NULL)
        {
            tCel* prox = atual->proxima;
            free(atual);
            atual = prox;
        }
        
        free(l);
    }

    void InsereLista(tLista* l,Reserva* r)
    {
        tCel* cel = malloc(sizeof(tCel));
        cel->anterior = NULL;
        cel->proxima = NULL;
        cel->reserva = r;

        if(l->primeira == NULL)
        {
            l->primeira = cel;
            l->ultima = cel;
            return;
        }

        l->ultima->proxima = cel;
        cel->anterior = l->ultima;
        l->ultima = cel;
    }
    void ImprimeLista(tLista* l)
    {
        tCel* atual = l->primeira;

        while(atual != NULL)
        {
            imprimeReserva(atual->reserva);
            atual = atual->proxima;
        }
    }

     void RetiraLista(tLista* l, int id)
     {
        tCel* atual = l->primeira;

        while(atual != NULL)
        {
            tCel* prox = atual->proxima;

            if(retornaId(atual->reserva) == id)
            {
                if(atual == l->primeira && atual == l->ultima)
                {
                    l->primeira = NULL;
                    l->ultima = NULL;
                    free(atual);
                    return;
                }

                if(atual == l->primeira)
                {
                    l->primeira = atual->proxima;
                    atual->proxima->anterior = NULL;
                    free(atual);
                    return;
                }
                if(atual == l->ultima)
                {
                    l->ultima = atual->anterior;
                    atual->anterior->proxima = NULL;
                    free(atual);
                    return;
                }

                atual->anterior->proxima = atual->proxima;
                atual->proxima->anterior = atual->anterior;
                free(atual);
                return;
            }

            
                atual = prox;
        }
     }