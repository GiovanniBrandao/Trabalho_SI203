#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct 
{
    char NomeQuadra[TAM];
    int dia, mes;
} reserva;

reserva *r1p;
int numdereserv = 0;       // número de reservas

void reservado (int *reservas)
{

char *nomequadra;
int dia, mes;
FILE *arquivo;

arquivo = fopen("reservas.txt", "a+");

if(arquivo == NULL)
{
    printf("Nao foi possivel abrir o arquivo");
    exit(1);
}

nomequadra = malloc(30 * sizeof(char));

    printf("-----------------\n");
    printf("Digite qual quadra deseja reservar\n");
    fgets(nomequadra, 30, stdin);
    printf("-----------------\n");
    printf("Para quando deseja reservar? (digite dia e mes em numeros com um espaco entre eles)\n");
    printf("-----------------\n");
    scanf("%d %d", &dia, &mes);
    getchar();
    (*reservas++);

    fprintf(arquivo, "Nome da quadra: %s", nomequadra);
    fprintf(arquivo, "Dia: %d %d\n", dia, mes);

free(nomequadra);
}

/*
void reserva1(struct reserva **r1, int *reservas)
{

    *r1 = (struct reserva *)realloc(*r1, ((*reservas + 1) * sizeof(struct reserva))); // aloca mais memória para mais reservas
    if (*r1 == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    printf("-----------------\n");
    printf("Digite qual quadra deseja reservar\n");
    printf("-----------------\n");
    fgets((*r1)[*reservas].NomeQuadra, TAM, stdin);
    printf("-----------------\n");
    printf("Para quando deseja reservar? (digite dia e mes em numeros com um espaco entre eles)\n");
    printf("-----------------\n");
    scanf("%d %d", &(*r1)[*reservas].dia, &(*r1)[*reservas].mes);
    getchar();
    (*reservas)++; // incremento no número de reservas feitas
}
*/
void excluir()
{
}

void reagendar()
{
}

void consultar(reserva *r1, int *a)
{
    char nome[TAM];
    printf("-----------------\n");
    printf("Digite o nome da quadra reservada\n");
    printf("-----------------\n");
    fgets(nome, TAM, stdin);

    for (int i = 0; i < *a; i++)
    {
        if (strcmp(nome, r1[i].NomeQuadra) == 0)
        {
            printf("-----------------\n");
            printf("%s agendada para o dia %d do mes %d\n", r1[i].NomeQuadra, r1[i].dia, r1[i].mes);
        }
    }
}

int main()
{
    int opcao;

    printf("-----------------\n");
    printf("Bem-vindo ao sistema de agendamento de quadra\n");
    printf("-----------------\n");
    printf("Digite o que deseja fazer\n");
    printf("[1] - Reservar quadra\n");
    printf("[2] - Excluir agendamento\n");
    printf("[3] - Reagendar reserva\n");
    printf("[4] - Consultar reservas\n");
    printf("[5] - Sair do programa\n");
    printf("-----------------\n");

    while (1)
    {
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1)
        {
            reservado(&numdereserv);
            //reserva(&r1p, &numdereserv);
        }
        else if (opcao == 2)
        {
            excluir();
        }
        else if (opcao == 3)
        {
            reagendar();
        }
        else if (opcao == 4)
        {
            consultar(r1p, &numdereserv);
        }
        else if (opcao == 5)
        {
            printf("Fechando e saindo do sistema...\n");
            break;
        }
        else
        {

            printf("Opcao invalida, tente novamente\n");
        }

        printf("-----------------\n");
        printf("Digite o que deseja fazer\n");
        printf("[1] - Reservar quadra\n");
        printf("[2] - Excluir agendamento\n");
        printf("[3] - Reagendar reserva\n");
        printf("[4] - Consultar reservas\n");
        printf("[5] - Sair do programa\n");
        printf("-----------------\n");

    }

    free(r1p);

    return 0;
}
