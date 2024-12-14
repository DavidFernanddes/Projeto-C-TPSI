#pragma once

#define MAX_LOCAL_LENGTH 100
#define MAX_EMBAIXADORES 9
#define MAX_DATA_LENGTH 11
#define MAX_ESTADO_LENGTH 20

typedef struct visit{
    int idVisita;
    char embaixadores[MAX_EMBAIXADORES];
    char estado[MAX_ESTADO_LENGTH];
    char local[MAX_LOCAL_LENGTH];
    char data[MAX_DATA_LENGTH];
} Visit;


void carregarVisitas();
void salvarVisitas();

void listarVisitas();
void consultarVisitas();
void adicionarVisitas();
void autorizarVisitas();