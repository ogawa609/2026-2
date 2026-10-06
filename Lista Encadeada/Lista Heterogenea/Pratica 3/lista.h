#ifndef _LISTA_H
#define _LISTA_H

    typedef struct Lista tLista;
    tLista* CriaLista();
    void LiberaLista(tLista* l);
    void InsereLista(tLista* l, void* sujeito, char id);
    void ImprimeRelatorio(tLista* l);
#endif 