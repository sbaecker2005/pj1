#ifndef PJ_H
#define PJ_H

#include <stdio.h>
#include <string.h>


#define FILENAME "tasks.txt"


typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
    char status[13];
} Task;

void cadastrar(Task tarefas[], int *numTarefas);
void listar(Task tarefas[], int numTarefas);
void alterar(Task tarefas[], int numTarefas);
void filtrar_Por_Prioridade(Task tarefas[], int numTarefas);
void filtrar_Por_Estado(Task tarefas[], int numTarefas);
void filtrar_Por_Categoria_Ordenado(Task tarefas[], int numTarefas);
void filtrar_Por_Prioridade_E_Categoria(Task tarefas[], int numTarefas);
void exportar_Por_Prioridade(Task tarefas[], int numTarefas);
void exportar_Por_Categoria_Ordenado(Task tarefas[], int numTarefas);
void exportar_Por_Prioridade_E_Categoria(Task tarefas[], int numTarefas);
void deletar(Task tarefas[], int *numTarefas);
void salvar(Task tarefas[], int numTarefas);
void carregar(Task tarefas[], int *numTarefas);
void exibir(Task tarefa);


#endif
