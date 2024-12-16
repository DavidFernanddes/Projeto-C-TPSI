#include <stdio.h>
#include <string.h>
#include "visit.h"
#include "ambassador.h"

void listarVisitas(Visita visitas[], int *totalVisitas) {
    if (*totalVisitas == 0) {
        printf("Nenhuma visita registrada.\n");
        return;
    }

    printf("Listagem de Visitas:\n");
    for (int i = 0; i < *totalVisitas; i++) {
        printf("ID: %d\nLocal: %s\nData: %s\nEstado: %s\n",
               visitas[i].idVisita, visitas[i].local, visitas[i].data, visitas[i].estado);
    }
}

void consultarVisitas(Visita visitas[], int *totalVisitas) {
    if (*totalVisitas == 0) {
        printf("Nenhuma visita registrada.\n");
        return;
    }

    int idConsulta;
    printf("Digite o ID da visita para consultar: ");
    scanf("%d", &idConsulta);

    for (int i = 0; i < *totalVisitas; i++) {
        if (visitas[i].idVisita == idConsulta) {
            printf("Detalhes da Visita:\n");
            printf("ID: %d\nLocal: %s\nData: %s\nEstado: %s\n",
                   visitas[i].idVisita, visitas[i].local, visitas[i].data, visitas[i].estado);
            return;
        }
    }
    printf("Visita com ID %d não encontrada.\n", idConsulta);
}

void adicionarVisitas(Visita visitas[], int *totalVisitas, Estudante embaixadores[], int totalEmbaixadores) {
    if (*totalVisitas >= MAX_VISITAS) {
        printf("Capacidade máxima de visitas atingida.\n");
        return;
    }

    Visita novaVisita;
    novaVisita.idVisita = *totalVisitas + 1;

    printf("Digite o local da visita: ");
    scanf(" %[^\n]", novaVisita.local);

    printf("Digite a data da visita (formato DD/MM/AAAA): ");
    scanf(" %[^\n]", novaVisita.data);

    strcpy(novaVisita.estado, "em planeamento");

    int numEmbaixadores;
    printf("Quantos embaixadores deseja associar a esta visita? (máximo de %d): ", MAX_NUM_EMBAIXADORES);
    scanf("%d", &numEmbaixadores);

    if (numEmbaixadores < 2) {
        printf("AVISO: A visita precisa de pelo menos 2 embaixadores para ser autorizada.\n");
    }
        for (int i = 0; i < numEmbaixadores; i++) {
            int numeroEstudante;
            printf("Digite o número do estudante para o embaixador %d: ", i + 1);
            scanf("%d", &numeroEstudante);

            int encontrado = 0;
            for (int j = 0; j < totalEmbaixadores; j++) {
                if (embaixadores[j].numeroEstudante == numeroEstudante) {
                    novaVisita.embaixadores[i] = numeroEstudante;
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                printf("Embaixador com número %d não encontrado. Tente novamente.\n", numeroEstudante);
                i--;
            }
        }

        visitas[*totalVisitas] = novaVisita;
        (*totalVisitas)++;

        printf("Visita adicionada com sucesso!\n");
    
}


void autorizarVisitas(Visita visitas[], int *totalVisitas, Estudante embaixadores[], int totalEmbaixadores) {
    if (*totalVisitas == 0) {
        printf("Nenhuma visita registrada.\n");
        return;
    }

    int idVisita;
    printf("Digite o ID da visita que deseja autorizar: ");
    scanf("%d", &idVisita);

    int encontrada = 0;
    for (int i = 0; i < *totalVisitas; i++) {
        if (visitas[i].idVisita == idVisita) {
            encontrada = 1;

            int numEmbaixadoresAssociados = 0;
            for (int j = 0; j < MAX_NUM_EMBAIXADORES; j++) {
                if (visitas[i].embaixadores[j] != 0) { 
                    numEmbaixadoresAssociados++;
                }
            }

            if (numEmbaixadoresAssociados >= 2) {
                strcpy(visitas[i].estado, "autorizada");
                printf("A visita com ID %d foi autorizada com sucesso!\n", idVisita);
            } else {
                printf("A visita precisa de pelo menos 2 embaixadores para ser autorizada.\n");
            }
            break;
        }
    }

    if (!encontrada) {
        printf("Visita com ID %d não encontrada.\n", idVisita);
    }
}
