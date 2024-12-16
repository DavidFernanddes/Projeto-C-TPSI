#pragma once

#define MAX_EMBAIXADORES 100
#define MAX_NAME_LENGTH 100
#define MAX_SCHOOL_LENGTH 4

typedef struct estudante {
    int numeroEstudante;
    char escola[MAX_SCHOOL_LENGTH];
    char nomeCompleto[MAX_NAME_LENGTH];
    char nif[9];
} Estudante;

void carregarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores);
void salvarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores);

void listarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores);
void consultarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores);
void adicionarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores);