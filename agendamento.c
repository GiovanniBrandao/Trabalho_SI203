#include "crud.h"

void limparTela() {
    system("cls"); 
}

void pausarTela() {
    printf("\nPressione enter para voltar ao menu...\n");
    getchar();
}

int menu() {
    limparTela();
    int opcao = 0;
    
    printf("-----------------------------\n");
    printf("| Digite o que deseja fazer |\n");
    printf("| [1] - Reservar quadra     |\n");
    printf("| [2] - Excluir agendamento |\n");
    printf("| [3] - Reagendar reserva   |\n");
    printf("| [4] - Consultar reservas  |\n");
    printf("| [5] - Sair do programa    |\n");
    printf("-----------------------------\n");

    scanf("%d", &opcao);
    getchar();
    
    return opcao;
}

int main() {
    int escolha;
    int idReserva = 0;

    while (escolha != 5) {

        escolha = menu();
    
        switch(escolha) {
            case 1:
                limparTela();
                criarReserva(&idReserva);
                pausarTela();
                break;
            case 2: 
                limparTela();   
                excluirReserva();
                pausarTela();
                break;
            case 3:
                limparTela();
                reagendarReserva();
                pausarTela();
                break;
            case 4:
                limparTela();
                consultarReserva();
                pausarTela();
                break;
            case 5:
                printf("Fechando e saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida, tente novamente\n");
                pausarTela();
                break;
        }
    }
    
    return 0;
}
