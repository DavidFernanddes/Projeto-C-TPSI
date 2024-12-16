#pragma once

#include "ambassador.h"

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


void carregarVisitas();
void salvarVisitas();

void listarVisitas(Visita visitas[], int *totalVisitas);
void consultarVisitas(Visita visitas[], int *totalVisitas);
void adicionarVisitas(Visita visitas[], int *totalVisitas, Estudante embaixadores[], int totalEmbaixadores);
void autorizarVisitas(Visita visitas[], int *totalVisitas, Estudante embaixadores[], int totalEmbaixadores);