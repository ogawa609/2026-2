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

    while(atual != NULL)
    {
        if(getMatricula(atual->estdante) == matricula)
        {


            // caso 1: celula única
             if(atual== lista->primeira && atual==lista->ultima)
            {
                lista->primeira = NULL;
                lista->ultima = NULL;
                LiberaCel(atual);
            }
            //caso 2: ser o primeiro da lista

            else if(atual == lista->primeira)
            {
                lista->primeira = atual->proxima;
                LiberaCel(atual);
                return;
            }
            
            //caso 3: ser o ultimo da lista

            else if(atual == lista->ultima)
            {
                lista->ultima = anterior;
                anterior->proxima = NULL;
                LiberaCel(atual);
                return;
            }

            
            //caso 4: meio da lista

            else
            {
                anterior->proxima = atual->proxima;
                LiberaCel(atual);
                return;
            }
        }

        anterior = atual;
        atual = atual->proxima;

        if(atual==NULL)
            break;
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
void ImprimeLista(tLista* lista,FILE* f)
{
    tCelula* atual = lista->primeira;

    int cont = 0;
    float media = 0;

    while(1)
    {
        

        if(atual == NULL)
            break;
    
        char* nome = getNome(atual->estdante);
        int matricula = getMatricula(atual->estdante);
        float cr = getCr(atual->estdante);

        media += cr;
        cont++;

        fprintf(f,"%d %s %.1f\n",matricula,nome,cr);

        atual = atual->proxima;

    }
    if(cont>0)
        fprintf(f,"Média: %.2f\n",media/cont);
    
}