# ifndef FILA_H
#define FILA_H

#include "amostra.h"

	typedef struct Fila tFila;
	tFila* CriaFila();
	void LiberaFila(tFila* f);
	void ImprimeFila(tFila* f);
	void PushFila(tFila* f, Amostra* a);
	Amostra* PopFila(tFila* f);
	int GetQntFila(tFila* f);
#endif
