#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "questao.h"

typedef struct Celula tCel;

struct Celula
{
    tCel* proxima;
    tQuestao* questao;
};

struct Lista 
{
    tCel* primeira;
    tCel* ultima;

    char* nome;
};

    tLista* CriaLista(char* nome)
    {
        tLista* l = malloc(sizeof(tLista));
        l->primeira = NULL;
        l->ultima = NULL;

        l->nome = strdup(nome);

        return l;
    }

    void InsereLista(tLista* l, tQuestao* q)
    {

        tCel* c = malloc(sizeof(tCel));
        c->questao = q;
        c->proxima = NULL;


        if(l->primeira==NULL)
        {
            l->primeira = c;
            l->ultima = c;
            return;
        }

        c->proxima = l->primeira;
        l->primeira = c;
    }

    tQuestao* BuscaQuestao(tLista* l, char* id)
    {
        tCel* atual = l->primeira;
        if(atual==NULL)
            return NULL;
        
        while(1)
        {
            if(atual==NULL)
                break;
            if(strcmp(GetIdQuest(atual->questao),id)==0)
                return atual->questao;

            atual = atual->proxima;
        }

        return NULL;
    }
    
    void LiberaCel(tCel* c)
    {
        LiberaQuestao(c->questao);
        free(c);
    }
    void LiberaListaTotal(tLista*l)
    {
        tCel* atual = l->primeira;

        while(1)
        {
            if(atual==NULL)
                break;
            
            tCel* prox = atual->proxima;

            LiberaCel(atual);
            atual = prox;
        }

        free(l->nome);
        free(l);
    }
    void ImprimeProva(tLista* l)
    {


        printf("Prova: %s\n",l->nome);

        tCel* atual = l->primeira;

        while(1)
        {
            if(atual==NULL)
                break;

            ImprimeQuestao(atual->questao);
            atual = atual->proxima;
        }
    }

    void LiberaStruct(tLista* l)
    {
        free(l->nome);
        free(l);
    }

    tLista* CriaMerge(tLista* l1, tLista* l2)
    {
        //SE 2 LISTAS VAZIA
        if(l1->primeira==NULL && l2->primeira==NULL)
            return NULL;

        //CRIA LISTA MERGE
        tLista* merge = CriaLista("merge");

        //SE L1 ESTIVER VAZIA -> MERGE = L2
        if(l1->primeira==NULL)
        {
            merge->primeira = l2->primeira;
            merge->ultima = l2->ultima;
            LiberaStruct(l1);
            LiberaStruct(l2);
            return merge;
        }
        //SE L2 ESTIVER VAZIA -> MERGE = L1
        else if(l2->primeira == NULL)
        {
            merge->primeira = l1->primeira;
            merge->ultima = l1->ultima;
             LiberaStruct(l1);
            LiberaStruct(l2);
            return merge;
        }

        //ATUAL1 E ATUAL2 RECEBEM PRIMEIRA CELULA DA LISTA

        tCel* atual1 = l1->primeira;
        tCel* atual2 = l2->primeira;

        //CRIA PONTEIROS PARA A PROXIMA CELULA
        tCel* prox1 = NULL;
        tCel* prox2 = NULL;

        //FLAG DE CONTROLE
        int i = 0;

        //CASO DAS DUAS LISTAS TEREM ELEMENTOS
        while(1)
        {
            //SE AS DUAS LISTAS CHEGAREM AO FIM
            if(atual1==NULL && atual2==NULL)
            {
                LiberaStruct(l1);
                LiberaStruct(l2);
                merge->ultima->proxima = NULL;
                 return merge;
            }
               
            //SE L1 TERMINAR
            if(atual1==NULL)
            {
                prox2 = atual2->proxima; 

                merge->ultima->proxima = atual2;
                merge->ultima = atual2;
                atual2 = atual2->proxima;
                continue;
            }
            //SE L2 TERMINAR
            else if(atual2==NULL)
            {
                prox1 = atual1->proxima;

                merge->ultima->proxima = atual1;
                merge->ultima = atual1;
                atual1 = atual1->proxima;
                continue;
            }

        
            if(i%2==0)
            {
                prox1 = atual1->proxima;

                if(merge->primeira == NULL)
                {
                     merge->primeira = atual1;
                     merge->ultima = atual1;

                     atual1 = prox1;
                }
                else
                {
                    merge->ultima->proxima = atual1;
                    merge->ultima = atual1;
                    atual1 = prox1;
                }
                
                
            }
            else
            {
                prox2 = atual2->proxima;

                merge->ultima->proxima = atual2;
                merge->ultima = atual2;
                atual2 = prox2;
            }

            i++;
        }
    }

    void LiberaCelula(tCel* c)
    {
        free(c);
    }
    void RetiraRepetido(tLista* l)
{
    if(l == NULL)
        return;

    tCel* anterior = NULL;
    tCel* atualI = l->primeira;

    while(atualI != NULL)
    {
        tCel* atualJ = atualI->proxima;
        int repetido = 0;

        while(atualJ != NULL)
        {
            if(atualI->questao == atualJ->questao)
            {
                repetido = 1;
                break;
            }

            atualJ = atualJ->proxima;
        }

        if(repetido)
        {
            tCel* temp = atualI;

            if(anterior == NULL)
                l->primeira = atualI->proxima;
            else
                anterior->proxima = atualI->proxima;

            if(atualI == l->ultima)
                l->ultima = anterior;

            atualI = atualI->proxima;

            free(temp);
        }
        else
        {
            anterior = atualI;
            atualI = atualI->proxima;
        }
    }

    if(l->primeira == NULL)
        l->ultima = NULL;
}
    void LiberaListaParcial(tLista* l)
    {
        tCel* t = l->primeira;

        while(1)
        {
            if(t==NULL)
                break;

            tCel* prox = t->proxima;

            free(t);

            t = prox;
        }

        free(l->nome);
        free(l);
    }