#include <stdio.h>
#include "lista.h"


int main()
{
   FILE* arq = fopen("entrada.txt","r");
   FILE* ss = fopen("saida.txt","w");

   tLista* lista = CriaLista();

   int n = 0;
   fscanf(arq,"%d",&n);

   for(int i=0;i<n;i++)
   {
        char nome[51];
        float cr = 0.0;
        int matricula = 0;

        fscanf(arq,"%d %s %f",&matricula,nome,&cr);

        tEstudante* estudante = CriaEstudante(nome,matricula,cr);
        InsereEstudanteLista(lista,estudante);
   }

   ImprimeLista(lista,ss);

   int retirada = 0;

   while(fscanf(arq,"%d",&retirada)!=EOF)
   {
        RetiraEstudanteLista(lista,retirada);
        fprintf(ss,"================\n");
        ImprimeLista(lista,ss);
   }

   fclose(arq);
   fclose(ss);
   LiberaLista(lista);

    return 0;

}