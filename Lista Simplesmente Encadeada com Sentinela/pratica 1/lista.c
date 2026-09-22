#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct Celula tCelula;

 struct Celula
{
    tEstudante* estdante;
    tCelula* proxima;

};

struct Lista 
{
    tCelula* primeira;
    tCelula* ultima;
};

tLista* CriaLista()
{
    tLista* lista = malloc(sizeof(tLista));
    lista->primeira = NULL;
    lista->ultima = NULL;

    return lista;
}


void InsereEstudanteLista(tLista* lista,tEstudante* est)
{
    tCelula* cel = malloc(sizeof(tCelula));
    cel->estdante = est;
    cel->proxima = NULL;

    if(lista->primeira == NULL)
    {
        lista->primeira = cel;
        lista->ultima = cel;
        return;
    }
        

    lista->ultima->proxima = cel;
    lista->ultima = cel;
}

void LiberaCel(tCelula* cel)
{
    LiberaEstudante(cel->estdante);
    free(cel);
}

void RetiraEstudanteLista(tLista* lista,int matricula)
{
    tCelula* atual = lista->primeira;
    tCelula* anterior = NULL;

    while(1)
    {
        if(getMatricula(atual->estdante) == matricula)
        {
            //caso 1: ser o primeiro da lista

            if(atual == lista->primeira)
            {
                lista->primeira = atual->proxima;
                LiberaCel(atual);
                atual = lista->primeira;
                return;
            }
            
            //caso 2: ser o ultimo da lista

            else if(proxima == lista->ultima)
            {

            }
            //caso 3: meio da lista
        }
    }
}
    
void LiberaLista(tLista* lista)
{
    tCelula* atual = lista->primeira;
    tCelula* proxima = lista->primeira->proxima;

    while(1)
    {
        LiberaCel(atual);
        atual = proxima;

        if(atual==NULL)
            break;

        proxima = atual->proxima;

    }

    free(lista);


}
void ImprimeLista(tLista* lista)
{
    tCelula* atual = lista->primeira;

    printf("=======================LISTA==========================\n\n");

    while(1)
    {
        if(atual == NULL)
            break;
            #if !defined(MACRO)
            #define MACRO
            
            
            
            #endif // MACRO
        char* nome = getNome(atual->estdante);
        int matricula = getMatricula(atual->estdante);
        float cr = getCr(atual->estdante);

        printf("NOME: %s\nMATRICULA: %d\nCR: %.2f\n\n",nome,matricula,cr);

        atual = atual->proxima;

    }
}