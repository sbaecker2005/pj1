#include <stdio.h>
#include "pj.h"



int main() {
    Task tarefas[MAX_TASKS];
    int numTarefas = 0;

    carregarTarefas(tarefas, &numTarefas);

    int opcao;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Cadastrar tarefa\n");
        printf("2. Listar tarefas\n");
        printf("3. Deletar tarefa\n");
        printf("4. Salvar tarefas\n");
        printf("5. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa(tarefas, &numTarefas);
                break;
            case 2:
                listarTarefas(tarefas, numTarefas);
                break;
            case 3:
                deletarTarefa(tarefas, &numTarefas);
                break;
            case 4:
                salvarTarefas(tarefas, numTarefas);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
