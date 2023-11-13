#include "pj.h"

int main() {
    Task tarefas[100];
    int numTarefas = 0;

    carregar(tarefas, &numTarefas);

    int opcao;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Cadastrar tarefas\n");
        printf("2. Listar tarefas\n");
        printf("3. Alterar tarefa\n");
        printf("4. Filtrar por prioridade\n");
        printf("5. Filtrar por estado\n");
        printf("6. Filtrar por categoria\n");
        printf("7. Filtrar por prioridade e categoria\n");
        printf("8. Exportar por prioridade\n");
        printf("9. Exportar por categoria\n");
        printf("10. Exportar por prioridade e categoria\n");
        printf("11. Deletar tarefas\n");
        printf("12. Salvar tarefas\n");
        printf("13. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar(tarefas, &numTarefas);
                break;
            case 2:
                listar(tarefas, numTarefas);
                break;
            case 3:
                alterar(tarefas, numTarefas);
                break;
            case 4:
                filtrar_Por_Prioridade(tarefas, numTarefas);
                break;
            case 5:
                filtrar_Por_Estado(tarefas, numTarefas);
                break;
            case 6:
                filtrar_Por_Categoria_Ordenado(tarefas, numTarefas);
                break;
            case 7:
                filtrar_Por_Prioridade_E_Categoria(tarefas, numTarefas);
                break;
            case 8:
                exportar_Por_Prioridade(tarefas, numTarefas);
                break;
            case 9:
                exportar_Por_Categoria_Ordenado(tarefas, numTarefas);
                break;
            case 10:
                exportar_Por_Prioridade_E_Categoria(tarefas, numTarefas);
                break;
            case 11:
                deletar(tarefas, &numTarefas);
                break;
            case 12:
                salvar(tarefas, numTarefas);
                break;
            case 13:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 13);

    return 0;
}
