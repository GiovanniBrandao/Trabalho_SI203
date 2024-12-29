# Sistema de Agendamento de Quadras
Este é um sistema simples em C para realizar o agendamento, exclusão, e consulta de reservas de quadras esportivas. O sistema permite que os usuários façam reservas, excluam reservas existentes, consultem detalhes de reservas, e reprogramem reservas para novas datas.

## Informações do Trabalho

Disciplina: **Algoritmos de Programação II - SI203**

Professora: **Lívia Couto Ruback**


Grupo formado por:

**Giovanni da Silva Virginio Brandão. RA: 288839**

**Izabella Julia dos Santos. RA: 169048**

**Thomaz Henrique Pedro Miranda. RA: 281456**

## Funcionalidades

- Reservar Quadra: Permite que o usuário faça uma reserva, informando o nome da quadra e a data desejada.

- Excluir Reserva: Permite excluir uma reserva existente.

- Reagendar Reserva: Permite que o usuário altere a data de agendamento

- Consultar Reserva: Permite que o usuário consulte os detalhes de uma reserva, como o nome da quadra e a data da reserva.

## Como Usar

Compilação: Compile o código com o comando:

```c
gcc -o agendamento agendamento.c
```
Execução: Execute o programa com:

```c
./agendamento
```

O sistema exibirá um menu interativo onde o usuário poderá escolher as operações desejadas.

Arquivos de Dados: O sistema utiliza o arquivo reservas.txt para armazenar as informações das reservas. Cada reserva inclui o nome da quadra e a data da reserva (dia e mês).

Menu de Opções: O menu oferece as seguintes opções:

- [1] - Reservar quadra: Permite reservar uma quadra.
- [2] - Excluir agendamento: Permite excluir uma reserva existente.
- [3] - Reagendar reserva: Permite alterar a data de uma reserva.
- [4] - Consultar reservas: Permite consultar reservas existentes.
- [5] - Sair do programa: Encerra o sistema.

## Estrutura do Código

Função reservado(): Responsável por fazer uma reserva de quadra, gravando as informações no arquivo reservas.txt.
Função excluir(): Exclui uma reserva existente, removendo-a do arquivo e gerando um arquivo temporário.
Função reagendar(): É responsável por modificar a data de uma reserva, no mesmo dia/mês.
Função consultar(): Permite que o usuário consulte a reserva de uma quadra informando seu nome.

## Dependências

O programa foi desenvolvido em C e usa funções da biblioteca padrão, como stdio.h e stdlib.h.

Utiliza arquivos de texto para persistir dados de reservas.
