#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "visit.h"
#include "ambassador.h"

#define CSV_FILE_V "visitas.csv"

void salvarVisitas(Visita visitas[], int *totalVisitas) {
    FILE *file = fopen(CSV_FILE_V, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(file, "idVisita,local,data,estado,embaixadores\n");

    for (int i = 0; i < *totalVisitas; i++) {
        fprintf(file, "%d,%s,%s,%s,\"%s\"\n",
                visitas[i].idVisita,
                visitas[i].local,
                visitas[i].data,
                visitas[i].estado,
                visitas[i].embaixadores);
    }

    fclose(file);
}

void carregarVisitas(Visita visitas[], int *totalVisitas) {
    FILE *file = fopen(CSV_FILE_V, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo '%s' para leitura.\n", CSV_FILE_V);
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), file);

    while (fgets(linha, sizeof(linha), file) && *totalVisitas < MAX_VISITAS) {
        Visita novaVisita;
        char embaixadores[MAX_NUM_EMBAIXADORES]; 

        sscanf(linha, "%d,%49[^,],%10[^,],%19[^,],\"%[^\"]\"",
               &novaVisita.idVisita, novaVisita.local, novaVisita.data, novaVisita.estado, embaixadores);

        strncpy(novaVisita.embaixadores, embaixadores, MAX_NUM_EMBAIXADORES - 1);
        novaVisita.embaixadores[MAX_NUM_EMBAIXADORES - 1] = '\0'; 

        visitas[*totalVisitas] = novaVisita;
        (*totalVisitas)++;
    }

    fclose(file);
}



void listarVisitas(Visita visitas[], int *totalVisitas) {
    if (*totalVisitas == 0) {
        printf("Nenhuma visita registrada.\n");
        return;
    }

    printf("Listagem de Visitas:\n");
    for (int i = 0; i < *totalVisitas; i++) {
        printf("ID: %d\nLocal: %s\nData: %s\nEstado: %s\nEmbaixadores: %s\n",
               visitas[i].idVisita, visitas[i].local, visitas[i].data, visitas[i].estado, visitas[i].embaixadores);
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

    novaVisita.embaixadores[0] = '\0';

    int numEmbaixadores;
    printf("Quantos embaixadores deseja associar a esta visita? (máximo de %d): ", MAX_NUM_EMBAIXADORES);
    scanf("%d", &numEmbaixadores);

    if (totalEmbaixadores == 0) {
        printf("Não há embaixadores disponíveis. Não é possível adicionar visitas.\n");
        return;
    } else if (numEmbaixadores < 2) {
        printf("AVISO: A visita precisa de pelo menos 2 embaixadores para ser autorizada.\n");
    }
    
        for (int i = 0; i < numEmbaixadores && i < totalEmbaixadores; i++) {
            int numeroEstudante;
            printf("Digite o número do estudante para o embaixador %d: ", i + 1);
            scanf("%d", &numeroEstudante);

            int encontrado = 0;
            for (int j = 0; j < totalEmbaixadores; j++) {
                if (embaixadores[j].numeroEstudante == numeroEstudante) {
                    if (i > 0) strcat(novaVisita.embaixadores, " | ");
                    char numeroStr[10];
                    sprintf(numeroStr, "%d", numeroEstudante);
                    strcat(novaVisita.embaixadores, numeroStr);
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

        salvarVisitas(visitas, totalVisitas);

        printf("Visita adicionada com sucesso!\n");
    
}

void autorizarVisitas(Visita visitas[], int *totalVisitas) {
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
            char embaixadoresCopy[MAX_NUM_EMBAIXADORES];
            strcpy(embaixadoresCopy, visitas[i].embaixadores); 

            char *token = strtok(embaixadoresCopy, "|");
            printf("Embaixadores associados: ");
            while (token != NULL) {
                numEmbaixadoresAssociados++;
                if (numEmbaixadoresAssociados > 1) {
                    printf("|");
                }
                printf("%s", token);
                token = strtok(NULL, "|");
            }
            printf("\n");

            if (numEmbaixadoresAssociados >= 2) {
                strcpy(visitas[i].estado, "autorizada");
                printf("A visita com ID %d foi autorizada com sucesso!\n", idVisita);
                salvarVisitas(visitas, totalVisitas);
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
