#ifndef TASKS_H
#define TASKS_H

#define MAX_DESC_LEN 300
#define MAX_CAT_LEN 100
#define MAX_TASKS 100
#define FILENAME "tasks.bin"

typedef struct {
    int priority;
    char description[MAX_DESC_LEN];
    char category[MAX_CAT_LEN];
} Task;

void cadastrarTarefa(Task tarefas[], int *numTarefas);
void listarTarefas(Task tarefas[], int numTarefas);
void deletarTarefa(Task tarefas[], int *numTarefas);
void salvarTarefas(Task tarefas[], int numTarefas);
void carregarTarefas(Task tarefas[], int *numTarefas);

#endif  // TASKS_H
