#include "header.h"

void limparTela() {
    system("cls"); 
}

void pausarTela() {
    printf("\nPressione enter para voltar ao menu...\n");
    getchar();
}

void getId() {
    FILE *arquivo;

    arquivo = fopen("id.txt", "r+");

    if (arquivo == NULL) {
        arquivo = fopen("id.txt", "w+");
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo\n");
            exit(EXIT_FAILURE);
        }
        id = 0;
    } else {
        fscanf(arquivo, "%d", &id);
        id++;
        rewind(arquivo); 
    }

    fprintf(arquivo, "%d", id);
    printf("%d\n", id); 

    fclose(arquivo);
}

void salvaArquivo(Reserva reserva) {
    FILE *arquivo = fopen("reservas.txt", "a+");

    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    fprintf(arquivo, "ID: %d\t Numero da quadra: %d\t Nome do reservante: %s\t CPF: %li\t Data: %02d/%02d\n", reserva.id, reserva.numeroQuadra, reserva.nomePessoa, reserva.cpfPessoa, reserva.data.dia, reserva.data.mes);
    fclose(arquivo);
}