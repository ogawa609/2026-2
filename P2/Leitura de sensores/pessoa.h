#ifndef _PESSOA_H
#define _PESSOA_H

typedef struct Pessoa tPessoa;
tPessoa* CriaPessoa(int lat, int longi, float temp);
void LiberaPessoa(tPessoa* p);
char* GetNomePessoa(tPessoa* p);
float GetTempPessoa(tPessoa* p);
void ImprimePessoa(tPessoa* p);
int GetLatitude(tPessoa* p);
int GetLongitude(tPessoa* p);

#endif