#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EDBooking.h"
#include "Lista.h"


/*Tipo opaco que define o sistema de reservas (EdBooking) de um hotel
 *Cada EdBooking deve ter os seguintes atributos:
 * * Nome do hotel
 * * Uma lista de reservas gerais
 * * Uma lista de reservas confirmadas
 * * Uma lista de reservas lixo
 * */
struct edbooking 
{
    char* nome;
    tLista* geral;
    tLista* confirmadas;
    tLista* lixo;

};

/* Cria uma instancia do EdBooking para um hotel, com as listas vazias
* inputs: nome do hotel (char*), que deve ser alocado dinamicamente
* output: EdBooking alocado e vazio, com listas de reservas vazias
* pre-condicao: string hotel não nula
* pos-condicao: estruturas alocadas, listas vazias */
EdBooking* criaEdBooking (char* hotel)
{
    EdBooking* e = malloc(sizeof(EdBooking));
    e->confirmadas = CriaLista();
    e->geral = CriaLista();
    e->lixo = CriaLista();
    e->nome = strdup(hotel);

    return e;
}


/* Insere uma reserva na lista de "reservas gerais" de um EdBooking
* inputs: o EdBooking e a reserva a ser inserida
* output: não tem
* pre-condicao: EdBooking e reserva alocados e não nulos
* pos-condicao: reserva inserida na lista de reservas gerais do EdBooking*/
void insereReserva (EdBooking* booking, Reserva* reserva)
{
    InsereLista(booking->geral,reserva);
}


/* Atualiza a situação da reserva dentro de um EdBooking
 * * se a reserva estiver confirmada, sai da lista de "reservas gerais" e vai para "lista de confirmadas"
 * * se a reserva não estiver confirmada, sai da lista de "reservas gerais" e vai para a "lista de lixo"
* inputs: o EdBooking e a reserva a ser atualizada
* output: não tem
* pre-condicao: EdBooking e reserva alocados e não nulos
* pos-condicao: situação da reserva corretamente atualizada nas listas de reservas*/
void atualizaReserva (EdBooking* booking, Reserva* reserva)
{
    RetiraLista(booking->geral,retornaId(reserva));

    if(ehConfirmada(reserva))
    {
        InsereLista(booking->confirmadas,reserva);
        return;
    }

     InsereLista(booking->lixo,reserva);
    
}

/* Imprime o EdBooking no formato:
 "===================
 Reservas do Hotel Hotel Aruan:
   Reservas Gerais:
       Reserva 2, Dono: Iris, Dia/hora: Tue Jun 24 13:37:28 2025
   Reservas Confirmadas:
       Reserva 1, Dono: Joao, Dia/hora: Tue Jun 24 13:37:28 2025
       Reserva 0, Dono: Patricia, Dia/hora: Tue Jun 24 13:37:28 2025
   Reservas Lixo:
       Reserva 3, Dono: Edu, Dia/hora: Tue Jun 24 13:37:28 2025
"
* inputs: o EdBooking
* output: não tem
* pre-condicao: EdBooking alocado e não nulo
* pos-condicao: estruturas de dados inalteradas */
void imprimeEdBooking (EdBooking* booking)
{
    printf("===================\n");
    printf("Reservas do Hotel %s:\n",booking->nome);
    printf("Reservas Gerais:\n");
    ImprimeLista(booking->geral);
    printf("Reservas Confirmadas:\n");
    ImprimeLista(booking->confirmadas);
    printf("Reservas Lixo:\n");
    ImprimeLista(booking->lixo);

}


/* Libera toda a memória alocada para o EdBooking (string e listas)
 * * Não libera as reservas em si
* inputs: o EdBooking
* output: não tem
* pre-condicao: EdBooking alocado e não nulo
* pos-condicao: toda a memória alocada (exceto reservas) */
void liberaEdBooking (EdBooking* booking)
{
    LiberaLista(booking->confirmadas);
    LiberaLista(booking->geral);
    LiberaLista(booking->lixo);
    free(booking->nome);
    free(booking);
}

