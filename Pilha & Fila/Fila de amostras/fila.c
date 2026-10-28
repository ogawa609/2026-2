#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "amostra.h"

typedef struct cel Cel;

struct cel
{
	Amostra* amostra;
	Cel* proximo;
	int prioridade;
};
struct Fila
{
	Cel* primeiro;
	Cel* ultimo;
	int qnt;
};
	tFila* CriaFila()
	{
		tFila* f = malloc(sizeof(tFila));
		f->primeiro = NULL;
		f->ultimo = NULL;
		f->qnt = 0;

		return f;
	}

	void LiberaFila(tFila* f)
	{
		Cel* t = f->primeiro;

		while(t != NULL)
		{
			Cel* prox = t->proximo;
			liberaAmostra(t->amostra);
			free(t);

			t = prox;
		}

		free(f);
	}

	void ImprimeFila(tFila* f)
	{
		Cel* t = f->primeiro;
		int i =1;
		while(t != NULL)
		{
			printf("%d°) ",i);
			i++;
			imprimeAmostra(t->amostra);

			t = t->proximo;
		}
	}
	void PushFila(tFila* f, Amostra* a)
	{
		Cel* cel = malloc(sizeof(Cel));
		cel->amostra = a;
		cel->proximo = NULL;

		f->qnt++;

		if(retornaIdade(a)>=60)
			cel->prioridade = 1;
		else
			cel->prioridade = 0;
		
		if(f->primeiro == NULL)
		{
			f->primeiro = cel;
			f->ultimo = cel;
			return;
		}

		Cel* atual = f->primeiro;
		Cel* ant = NULL;

		while(atual != NULL)
		{
			Cel* prox = atual->proximo;

			if(cel->prioridade > atual->prioridade)
			{
				if(ant==NULL)
				{
					f->primeiro = cel;
					cel->proximo = atual;
					return;
				}
				
				ant->proximo = cel;
				cel->proximo = atual;
				return;
			}

			ant = atual;
			atual = prox;

		}

		f->ultimo->proximo = cel;
		f->ultimo = cel;
	}

	Amostra* PopFila(tFila* f)
	{
		Cel* pri = f->primeiro;
		f->primeiro = pri->proximo;

		f->qnt--;

		Amostra* amostra = pri->amostra;
		free(pri);
		return amostra;
	}

	int GetQntFila(tFila* f)
	{
		return f->qnt;
	}
