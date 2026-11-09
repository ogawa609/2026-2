#ifndef ABB_H
#define ABB_H
 
typedef struct abb Abb;
Abb* CriaArvoreVazia();
Abb* CriaArvore(int dado, Abb* e, Abb* d);
Abb* InsereArvore(int dado, Abb* arv);
void LiberaArv(Abb* argv);
int ArvVazia(Abb* arv);
int BuscaDado(Abb* arv, int dado);
Abb* RetiraArv(Abb* arv, int dado);
void Imprime(Abb* arv);
int Altura(Abb* arv);
int NumeroElementos(Abb* arv);
int NumeroFolhas(Abb* arv);
#endif 