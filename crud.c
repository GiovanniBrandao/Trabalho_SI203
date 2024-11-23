#include "utils.c"

void criarReserva() {
    Reserva reserva;

    reserva.nomePessoa = malloc(TAM * sizeof(char));
    if(reserva.nomePessoa == NULL) {
        printf("Erro de memoria\n");
        exit(EXIT_FAILURE);
    }

    printf("Nome do reservante: ");
    fgets(reserva.nomePessoa, TAM, stdin);
    reserva.nomePessoa[strcspn(reserva.nomePessoa, "\n")] = '\0';

    printf("CPF: ");
    scanf("%li", &reserva.cpfPessoa);
    getchar();

    printf("Digite a data da reserva (dd/mm): ");
    scanf("%d/%d", &reserva.data.dia, &reserva.data.mes);
    
    printf("Digite o numero da quadra reservada: ");
    scanf("%d", &reserva.numeroQuadra);
    getchar();

    getId();
    reserva.id = id;
  
    printf("\nReserva realizada com sucesso! Id da reserva: %d\n", reserva.id);

    salvaArquivo(reserva);
    free(reserva.nomePessoa);
}

void excluirReserva() {
    FILE *arquivoprinci = fopen("reservas.txt", "r"), *arquivotemp = fopen("reservasTemp.txt", "w");
    char linha[TAM];
    int idReserva, idReserva_excluir, achou = 0;

    if (arquivoprinci == NULL || arquivotemp == NULL) {
        printf("Erro ao abrir o arquivo!\nVoce precisa ter reservas criadas para excluir alguma!\n");
        return;
    }

    printf("Digite o id da reserva que deseja excluir: ");
    scanf("%d", &idReserva_excluir);
    getchar();

    while (fgets(linha, sizeof(linha), arquivoprinci) != NULL) {
        if (sscanf(linha, "ID: %d", &idReserva) == 1) {
            if (idReserva != idReserva_excluir) {
                fprintf(arquivotemp, "%s", linha);
            } else {
                achou = 1;
                printf("\nReserva excluida com sucesso\n");
            }
        } else {
            fprintf(arquivotemp, "%s", linha);
        }
    }

    if(achou == 0) {
        printf("Reserva nao encontrada\n");
    }

    fclose(arquivoprinci);
    fclose(arquivotemp);
    remove("reservas.txt");
    rename("reservasTemp.txt", "reservas.txt");
}

void reagendarReserva() {
    FILE *arquivoprinci = fopen("reservas.txt", "r"), *arquivotemp = fopen("reservasTemp.txt", "w");
    Reserva reserva;
    Data novaData;
    char linha[TAM];
    int idReserva_reagendar, achou = 0;

    if (arquivoprinci == NULL || arquivotemp == NULL) {
        printf("Erro ao abrir o arquivo!\nVoce precisa ter reservas criadas para reagendar alguma!\n");
        return;
    }

    reserva.nomePessoa = malloc(TAM * sizeof(char));

    if(reserva.nomePessoa == NULL) {
        printf("Erro de memoria\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite o id da reserva que deseja reagendar: ");
    scanf("%d", &idReserva_reagendar);
    printf("Digite a nova data: ");
    scanf("%d/%d", &novaData.dia, &novaData.mes);
    getchar();

    while (fgets(linha, sizeof(linha), arquivoprinci) != NULL) {
        sscanf(linha, "ID: %d\t Numero da quadra: %d\t Nome do reservante: %s\t CPF: %li\t Data: %02d/%02d\n", &reserva.id, &reserva.numeroQuadra, reserva.nomePessoa, &reserva.cpfPessoa, &reserva.data.dia, &reserva.data.mes);
            
        if (reserva.id == idReserva_reagendar) {
            fprintf(arquivotemp, "ID: %d\t Numero da quadra: %d\t Nome do reservante: %s\t CPF: %li\t Data: %02d/%02d\n", reserva.id, reserva.numeroQuadra, reserva.nomePessoa, reserva.cpfPessoa, novaData.dia, novaData.mes);
            achou = 1;
        } else {
            fprintf(arquivotemp, "%s", linha);
        }
        
    }

    if(achou == 0) {
        printf("Reserva nao encontrada\n");
    }

    fclose(arquivoprinci);
    fclose(arquivotemp);
    remove("reservas.txt");
    rename("reservasTemp.txt", "reservas.txt");
    
    free(reserva.nomePessoa);
}

void consultarReserva() {
    FILE *arquivo = fopen("reservas.txt", "r");
    char linha[TAM];
    int id_consultar, idReserva, achou = 0;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\nVoce precisa ter reservas criadas para consultar alguma!\n");
        return;
    }

    printf("Digite o id da reserva que deseja consultar: ");
    scanf("%d", &id_consultar);
    getchar();

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "ID: %d", &idReserva);

        if (idReserva == id_consultar) {
            printf("Reserva encontrada:\n%s", linha);
            achou = 1;
            break;
        }
    }

    if(achou == 0) {
        printf("Reserva nao encontrada\n");
    }

    fclose(arquivo);
}

void listarTodasReservas() {
    FILE *arquivo = fopen("reservas.txt", "r");
    char linha[TAM];

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\nVoce precisa ter reservas criadas para listagem!\n");
        return;
    }

    printf("Reservas\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
}