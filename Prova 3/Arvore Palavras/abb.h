#ifndef ABB_H
#define ABB_H

typedef struct abb Abb;
Abb* CriaVazia();
Abb* CriaArv(char* palavra, int freq, Abb* esquerda, Abb* direito);
Abb* Insere(Abb* arv, char* palavra, int frq);
int TotalPalavras(Abb* arv);
int PalavrasUnicas(Abb* arv);
void Libera(Abb* arv);
void Imprime(Abb* arv);
int Maior(Abb* arv);
#endif