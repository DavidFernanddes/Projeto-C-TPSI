#include <stdio.h>
#include <string.h>
#include "visit.h"

#define MAX_VISITAS 1000
#define CSV_FILE "visitas.csv"

Visit visitas[MAX_VISITAS];
int totalVisitas = 0;

void carregarVisitas() {
    FILE *file = fopen(CSV_FILE, "r");
    if (!file) {
        printf("Ficheiro não encontrado ou não pode ser aberto.\n");
        return;
    }

    while (fscanf(file, "%d,%[^,],%[^,],%s\n", 
                   &visitas[totalVisitas].idVisita, 
                   visitas[totalVisitas].local, 
                   visitas[totalVisitas].data, 
                   visitas[totalVisitas].estado) == 4) {
        totalVisitas++;
    }

    fclose(file);
}

void salvarVisitas() {
    FILE *file = fopen(CSV_FILE, "w");
    if (!file) {
        printf("Erro ao abrir o ficheiro para escrita.\n");
        return;
    }

    for (int i = 0; i < totalVisitas; i++) {
        fprintf(file, "%d,%s,%s,%s\n", visitas[i].idVisita, visitas[i].local, visitas[i].data, visitas[i].estado);
    }

    fclose(file);
}


void listarVisitas() {
    if (totalVisitas == 0) {
        printf("Nenhuma visita registrada.\n");
        return;
    }

    printf("Listagem de Visitas:\n");
    for (int i = 0; i < totalVisitas; i++) {
        printf("ID: %d\nLocal: %s\nData: %s\nEstado: %s\n",
               visitas[i].idVisita, visitas[i].local, visitas[i].data, visitas[i].estado);
    }
}

void consultarVisitas() {
    int idConsulta;
    printf("Digite o ID da visita para consultar: ");
    scanf("%d", &idConsulta);

    for (int i = 0; i < totalVisitas; i++) {
        if (visitas[i].idVisita == idConsulta) {
            printf("Detalhes da Visita:\n");
            printf("ID: %d\nLocal: %s\nData: %s\nEstado: %s\n",
                   visitas[i].idVisita, visitas[i].local, visitas[i].data, visitas[i].estado);
            return;
        }
    }
    printf("Visita com ID %d não encontrada.\n", idConsulta);
}

void adicionarVisitas() {
    
}

void autorizarVisitas() {
    
}