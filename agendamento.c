#include <stdio.h>


struct pessoa
{
    char nome;
    int telefone;
    int RG;
};

struct pessoa p1;

struct reserva
{
    char NomeQuadra;
    int dia;
};

struct reserva r1;


void reserva()
{
    
}

void excluir()
{
}

void reagendar()
{
}

void consultar()
{
}

int main()
{

    int opcao;

    printf("Bem vindo ao sistema de agendamento de quadra\n");
    printf("Digite o que deseja fazer\n");
    printf("[1] - Reservar quadra\n");
    printf("[2] - Excluir agendamento\n");
    printf("[3] - Reagendar reserva\n");
    printf("[4] - Consultar reservas\n");
    scanf("%d", &opcao);

    while (1)
    {

        scanf("%d", &opcao);

        if (opcao == 1)
        {
            reserva();
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
            consultar();
        }

        else
        {
            printf("Fechando e saindo do sistema...");
            break;
        }
    }

    return 0;
}