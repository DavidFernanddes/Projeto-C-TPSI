#pragma once

#include "util.h"

void carregarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores);
void salvarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores);

void listarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores);
void consultarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores);
void adicionarEmbaixadores(Estudante embaixadores[], int *totalEmbaixadores);
void eliminarEmbaixador(Estudante embaixadores[], int *totalEmbaixadores, Visita visitas[], int totalVisitas);