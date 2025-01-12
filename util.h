#pragma once

#define MAX_VISITAS 1000
#define MAX_LOCAL_LENGTH 100
#define MAX_NUM_EMBAIXADORES 9
#define MAX_DATA_LENGTH 11
#define MAX_ESTADO_LENGTH 20

typedef struct visita{
    int idVisita;
    char embaixadores[MAX_NUM_EMBAIXADORES];
    char estado[MAX_ESTADO_LENGTH];
    char local[MAX_LOCAL_LENGTH];
    char data[MAX_DATA_LENGTH];
} Visita;


#define MAX_EMBAIXADORES 100
#define MAX_NAME_LENGTH 100
#define MAX_SCHOOL_LENGTH 4

typedef struct estudante {
    int numeroEstudante;
    char escola[MAX_SCHOOL_LENGTH];
    char nomeCompleto[MAX_NAME_LENGTH];
    char nif[9];
} Estudante;

void gravarDados(Estudante embaixadores[], int *totalEmbaixadores, Visita visitas[], int *totalVisitas);