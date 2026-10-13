# ifndef FILA_H
#define FILA_H

	typedef struct Fila tFila;
	tFila* CriaFila();
	void LiberaFila(tFila* f);
	void ImprimeFila(tFila* f);
	void PushFila(tFila* f, Amostra* a);
	void PushPriorFila(tFila* f, Amastra* a);
	int GetNumElem(tFila* f);
#endif
