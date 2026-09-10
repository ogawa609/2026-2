#ifndef _MATRIZ_H
#define _MATRIZ_H


    typedef struct Matriz tMatriz;
    tMatriz* CriaMatriz(int linha,int coluna);
    void ImprimeMatriz(tMatriz* m);
    void InserirMatriz(tMatriz* m, int lin, int col, char* nome);
    void LiberaMatriz(tMatriz* m);
    void BuscaPalavra(tMatriz* m);
    
#endif