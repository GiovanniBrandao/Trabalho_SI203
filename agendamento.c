#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

struct reserva
{
    char NomeQuadra[TAM];
    int dia, mes;
};

struct reserva *r1 = NULL; // Inicializar como NULL para n dar problemas futuros
int numdereserv = 0;       // número de reservas

void reserva(struct reserva **r1, int *a)
{

    *r1 = (struct reserva *)realloc(*r1, ((*a + 1) * sizeof(struct reserva))); // aloca mais memória para mais reservas
    if (*r1 == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    printf("-----------------\n");
    printf("Digite qual quadra deseja reservar\n");
    printf("-----------------\n");
    fgets((*r1)[*a].NomeQuadra, TAM, stdin);
    printf("-----------------\n");
    printf("Para quando deseja reservar? (digite dia e mes em numeros com um espaco entre eles)\n");
    printf("-----------------\n");
    scanf("%d %d", &(*r1)[*a].dia, &(*r1)[*a].mes);
    getchar();
    (*a)++; // incremento no número de reservas feitas
}

void excluir()
{
}

void reagendar()
{
}

void consultar(struct reserva *r1, int *a)
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
            reserva(&r1, &numdereserv);
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
            consultar(r1, &numdereserv);
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
    }

    free(r1);

    return 0;
}
