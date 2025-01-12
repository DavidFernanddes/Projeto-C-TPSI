#include <stdio.h>
#include "util.h"
#include "visit.h"
#include "ambassador.h"

void gravarDados(Estudante embaixadores[], int *totalEmbaixadores, Visita visitas[], int *totalVisitas) {

    salvarEmbaixadores(embaixadores, totalEmbaixadores);
    
    salvarVisitas(visitas, totalVisitas);
    
    printf("Dados gravados com sucesso!\n");
}