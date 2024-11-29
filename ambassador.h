#include <stdio.h>

#define MAX_NAME_LENGTH 100
#define MAX_SCHOOL_LENGTH 4

typedef struct estudante {
    int numeroEstudante;
    char escola[MAX_SCHOOL_LENGTH];
    char nomeCompleto[MAX_NAME_LENGTH];
    char nif[9];
} Estudante;

//listAmbassadors();
//consultAmbassadors();
//addAmbassador();