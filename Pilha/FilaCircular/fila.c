#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "amostra.h"
#define MAX 1000
struct Fila
{
	int indice;
	int nElem;
	Amostra amostras[MAX];
};
	tFila* CriaFila();
	void LiberaFila(tFila* f);
	void ImprimeFila(tFila* f);
	void PushFila(tFila* f, Amostra* a);
	int GetNumElem(tFila* f);
