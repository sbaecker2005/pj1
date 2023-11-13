
#include "pj.h"
#include <stdlib.h>

void cadastrar(Task tarefas[], int *numTarefas) {
  if (*numTarefas >= 100) {
    printf("Limite de tarefas atingido.\n");
    return;
  }

  printf("Digite a Prioridade o da tarefa: ");
  scanf(" %d", &tarefas[*numTarefas].prioridade);
  limparBuffer();

  printf("Digite a categoria da tarefa: ");
  scanf(" %[^\n]s", tarefas[*numTarefas].categoria);
  limparBuffer();

  printf("Digite o Estado da tarefa: ");
  scanf("%s", tarefas[*numTarefas].status);
  limparBuffer();

  printf("Digite a Descricao da tarefa: ");
  scanf("%s", tarefas[*numTarefas].descricao);
  limparBuffer();

  (*numTarefas)++;
}



void listar(Task tarefas[], int numTarefas) {
  if (numTarefas == 0) {
    printf("Nenhuma tarefa cadastrada.\n");
    return;
  }

  printf("=== Lista de Tarefas ===\n");
  for (int i = 0; i < numTarefas; i++) {
    printf("Tarefa %d:\n", i + 1);
    printf("Prioridade: %d\n", tarefas[i].prioridade);
    printf("Categoria: %s\n", tarefas[i].categoria);
    printf("Estado: %s\n", tarefas[i].status);
    printf("Descricao: %s\n", tarefas[i].descricao);
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
