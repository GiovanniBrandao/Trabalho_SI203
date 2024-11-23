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
    int numeroQuadra, id;
    Data data;
} Reserva;

int id = 0;