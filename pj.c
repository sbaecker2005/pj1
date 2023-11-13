
#include "pj.h"
#include <stdio.h>

void cadastrarTarefa(Task tarefas[], int *numTarefas) {
    if (*numTarefas >= MAX_TASKS) {
        printf("Limite de tarefas atingido.\n");
        return;
    }

    // Adicione a lógica para cadastrar uma tarefa aqui
    printf("Função cadastrarTarefa chamada.\n");
    // Exemplo: solicitar informações do usuário e armazenar na próxima posição disponível no vetor de tarefas
    printf("Digite a descrição da tarefa: ");
    scanf(" %[^\n]s", tarefas[*numTarefas].description);

    printf("Digite a categoria da tarefa: ");
    scanf(" %[^\n]s", tarefas[*numTarefas].category);

    printf("Digite a prioridade da tarefa (0 a 10): ");
    scanf("%d", &tarefas[*numTarefas].priority);

    (*numTarefas)++;
}

void listarTarefas(Task tarefas[], int numTarefas) {
    if (numTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    printf("=== Lista de Tarefas ===\n");
    for (int i = 0; i < numTarefas; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Descrição: %s\n", tarefas[i].description);
        printf("Categoria: %s\n", tarefas[i].category);
        printf("Prioridade: %d\n", tarefas[i].priority);
        printf("\n");
    }
}

void deletarTarefa(Task tarefas[], int *numTarefas) {
    if (*numTarefas == 0) {
        printf("Nenhuma tarefa para deletar.\n");
        return;
    }

    // Adicione a lógica para deletar uma tarefa aqui
    // Este é um exemplo que remove a última tarefa
    (*numTarefas)--;
    printf("Última tarefa removida.\n");
}

void salvarTarefas(Task tarefas[], int numTarefas) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(&numTarefas, sizeof(int), 1, file);  // Salva o número de tarefas primeiro


    fwrite(tarefas, sizeof(Task), numTarefas, file);

    fclose(file);
}

void carregarTarefas(Task tarefas[], int *numTarefas) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Arquivo de dados não encontrado. Criando um novo.\n");
        return;
    }

    fread(numTarefas, sizeof(int), 1, file);  // Lê o número de tarefas primeiro


    fread(tarefas, sizeof(Task), *numTarefas, file);

    fclose(file);
}
