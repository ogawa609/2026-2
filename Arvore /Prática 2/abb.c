#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

struct abb 
{
    Aluno* aluno;
    Abb* esquerda;
    Abb* direira;
};

Abb* CriaArvoreVazia()
{
    return NULL;
}
Abb* CriaRamo(Aluno* aluno,Abb* e, Abb* d)
{
    Abb* arv = malloc(sizeof(Abb));
    arv->aluno = aluno;
    arv->direira = d;
    arv->esquerda = e;
    return arv;
}
Abb* InsereElementoArv(Abb* a, Aluno* al)
{

    if(a == NULL)
        a = CriaRamo(al,CriaArvoreVazia(),CriaArvoreVazia());
    else
    {

        if(GetMatriculaAluno(al)>GetMatriculaAluno(a->aluno))
        {
            a->direira = InsereElementoArv(a->direira,al);
        }
        else 
        {
            a->esquerda = InsereElementoArv(a->esquerda,al);
        }

    }

    return a;
}


int AlturaArvore(Abb* a)
{
    if(a == NULL)
       return 0;

    int he = AlturaArvore(a->esquerda);
    int hd = AlturaArvore(a->direira);


    if(he>hd)
        return 1 + he;
    
    return 1 + hd;

}
void LiberaArv(Abb* a)
{
    if(a == NULL)
        return;
    
    
        LiberaArv(a->direira);
        LiberaArv(a->esquerda);
    

    LiberaAluno(a->aluno);
    free(a);
    
}
Abb* RetiraArv(Abb* a, int mat)
{
    if(a == NULL)
        return NULL;

    else if(GetMatriculaAluno(a->aluno) > mat)
    {
       a->esquerda =  RetiraArv(a->esquerda,mat);
    }
    else if(GetMatriculaAluno(a->aluno) < mat)
       a->direira = RetiraArv(a->direira,mat);
    else
    {
        if(a->direira == NULL && a->esquerda == NULL)
        {
            LiberaAluno(a->aluno);
            free(a);
            a = NULL;
        }
        else if(a->direira == NULL)
        {
            Abb* r = a;
            a = a->esquerda;
            LiberaAluno(r->aluno);
            free(r);

        }
        else if(a->esquerda == NULL)
        {
            Abb* r = a;
            a = a->direira;
            LiberaAluno(r->aluno);
            free(r);
        }
        else
        {
            Abb* r = a->direira;

            while(r->esquerda != NULL)
                r = r->esquerda;

            Aluno* temp = a->aluno;
            a->aluno = r->aluno;
            r->aluno = temp;
            a->direira = RetiraArv(a->direira,GetMatriculaAluno(temp));
        }
    }

    return a;
}
Aluno* BuscaAluno(Abb* a, char* nome)
{
    if(a == NULL)
        return NULL;
    
    if(strcmp(GetNomeAluno(a->aluno),nome)==0)
        return a->aluno;
    
    Aluno* e = BuscaAluno(a->esquerda,nome);
    Aluno* d = BuscaAluno(a->direira,nome);

    if(e != NULL)
        return e;
    else
        return d;
}

void ImprimeArv(Abb* arv)
{
    if(arv !=NULL)
    {
        ImprimirAluno(arv->aluno);
        ImprimeArv(arv->direira);
        ImprimeArv(arv->esquerda);
    }
}