#ifndef ABB_H
#define ABB_H

typedef struct abb Abb;
Abb* CriaArvVazia();
Abb* CriaArvore(char* dado, Abb* esq, Abb* dir);
void LiberaArv(Abb* arv);
Abb* Insere(Abb* arv, char* dado);
int Existe(Abb* arv, char* chave);
Abb* Retira(Abb* arv, char* chave);
void Imprime(Abb* arv);
int Altura(Abb* arv);


#endif