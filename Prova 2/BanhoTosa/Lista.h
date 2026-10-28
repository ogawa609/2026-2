#ifndef LISTA_H
#define LISTA_H

    typedef struct Lista Lista;
    Lista* CriaLista();
    void InsereLista(Lista* lista, void* elemento,int id);
    void LiberaLista(Lista* lista);
    void RemoveLista(Lista* l, char* chave);
    void ImprimeLista(Lista* l);
    int CalcularLista(Lista* l);

#endif
