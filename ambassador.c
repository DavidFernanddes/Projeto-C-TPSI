#include <stdio.h>
#include <string.h>
#include "ambassador.h"

#define CSV_FILE_E "embaixadores.csv"

void carregarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores) {
    FILE *file = fopen(CSV_FILE_E, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo '%s' para leitura.\n", CSV_FILE_E);
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), file);

    while (fgets(linha, sizeof(linha), file) && *totalEmbaixadores < MAX_EMBAIXADORES) {
        Estudante novoEmbaixador;

        sscanf(linha, "%d,%49[^,],%49[^,],%8s", 
               &novoEmbaixador.numeroEstudante, novoEmbaixador.escola, novoEmbaixador.nomeCompleto, novoEmbaixador.nif);

        embaixadores[*totalEmbaixadores] = novoEmbaixador;
        (*totalEmbaixadores)++;
    }

    fclose(file);
}


void salvarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores) {
    FILE *file = fopen(CSV_FILE_E, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < *totalEmbaixadores; i++) {
        fprintf(file, "%d,%s,%s,%s\n",
                embaixadores[i].numeroEstudante,
                embaixadores[i].nomeCompleto,
                embaixadores[i].escola,
                embaixadores[i].nif);
    }

    fclose(file);
}

void listarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores) {
    if (*totalEmbaixadores == 0) {
        printf("Nenhum embaixador registrado.\n");
        return;
    }

    printf("Listagem de Embaixadores:\n");
    for (int i = 0; i < *totalEmbaixadores; i++) {
        printf("Número: %d\nEscola: %s\nNome: %s\nNIF: %s\n",
               embaixadores[i].numeroEstudante, embaixadores[i].escola, embaixadores[i].nomeCompleto, embaixadores[i].nif);
    }
}

void consultarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores) {
    if (*totalEmbaixadores == 0) {
        printf("Nenhum embaixador registrado.\n");
        return;
    }

    int numeroConsulta;
    printf("Digite o número do embaixador para consultar: ");
    scanf("%d", &numeroConsulta);

    for (int i = 0; i < *totalEmbaixadores; i++) {
        if (embaixadores[i].numeroEstudante == numeroConsulta) {
            printf("Detalhes do Embaixador:\n");
            printf("Número: %d\nEscola: %s\nNome: %s\nNIF: %s\n",
                   embaixadores[i].numeroEstudante, embaixadores[i].escola, embaixadores[i].nomeCompleto, embaixadores[i].nif);
            return;
        }
    }
    printf("Embaixador com número %d não encontrado.\n", numeroConsulta);
}

void adicionarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores) {
    if (*totalEmbaixadores >= MAX_EMBAIXADORES) {
        printf("Limite de embaixadores atingido.\n");
        return;
    }

    Estudante novoEmbaixador;
    printf("Digite o número do embaixador: ");
    scanf("%d", &novoEmbaixador.numeroEstudante);
    printf("Digite a escola: ");
    scanf("%s", novoEmbaixador.escola);
    printf("Digite o nome completo: ");
    scanf(" %[^\n]", novoEmbaixador.nomeCompleto);
    printf("Digite o NIF: ");
    scanf("%s", novoEmbaixador.nif);

    embaixadores[*totalEmbaixadores] = novoEmbaixador;
    (*totalEmbaixadores)++;

    salvarEmbaixadores(embaixadores, totalEmbaixadores);
    printf("Embaixador adicionado com sucesso!\n");
}