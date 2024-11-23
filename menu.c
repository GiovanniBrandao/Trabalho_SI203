#include "crud.c"

void menu() {
    limparTela();
    int opcao = 0;
    
    printf("-------------------------------------\n");
    printf("| Digite o que deseja fazer         |\n");
    printf("| [1] - Reservar quadra             |\n");
    printf("| [2] - Excluir agendamento         |\n");
    printf("| [3] - Reagendar reserva           |\n");
    printf("| [4] - Consultar reserva           |\n");
    printf("| [5] - Listar todas as reservas    |\n");
    printf("| [6] - Sair do programa            |\n");
    printf("-------------------------------------\n");

    scanf("%d", &opcao);
    getchar();
    
    limparTela();

    switch(opcao) {
        case 1:
            criarReserva();
            break;
        case 2: 
            excluirReserva();
            break;
        case 3:
            reagendarReserva();
            break;
        case 4:
            consultarReserva();
            break;
        case 5:
            listarTodasReservas();
            break;
        case 6:
            printf("Fechando e saindo do sistema...\n");
            return;
        default:
            printf("Opcao invalida, tente novamente\n");
            break;
    }

    pausarTela();

    if (opcao == 6) {
        return;
    }

    menu();
}