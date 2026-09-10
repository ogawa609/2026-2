#ifndef _MATRIZ_H
#define _MATRIZ_H

    typedef struct Matriz tMatriz;

    tMatriz* CriaMatriz(int linha,int coluna);
    void LiberaMatriz(tMatriz* m);
    void OrdenaAlfabeticamente(tMatriz* m);
    tMatriz* Transposta(tMatriz* m);
    void Imprime(tMatriz* m);
    void Adiciona(tMatriz* m,int linha,int coluna,char*nome);

#endif