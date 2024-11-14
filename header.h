#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 200

typedef struct {
    int dia, mes;
} Data;

typedef struct {
    char *nomePessoa;
    long int cpfPessoa;
    int numeroQuadra;
    Data data;
} Reserva;

//Assinaturas das funcoes
void limpaTela();
void pausarTela();
void criarReserva(int *idReserva);
void excluirReserva();
void reagendaReserva();
void consultaReserva();

int menu();
