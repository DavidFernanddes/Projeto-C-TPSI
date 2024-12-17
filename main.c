#include <stdio.h>
#include <stdlib.h>
#include "ambassador.h"
#include "visit.h"

Estudante embaixadores[MAX_EMBAIXADORES];
int totalEmbaixadores = 0;

Visita visitas[MAX_VISITAS];
int totalVisitas = 0;

int main()
{
    carregarVisitas(visitas, &totalVisitas);
    carregarEmbaixadores(embaixadores, &totalEmbaixadores);
    int escolha;

    do
    {
        printf("\n==============================\n");
        printf("              MENU            \n");
        printf("==============================\n");
        printf("1. Listar visitas\n");
        printf("2. Listar embaixadores\n");
        printf("3. Consultar visita\n");
        printf("4. Consultar embaixador\n");
        printf("5. Adicionar visita\n");
        printf("6. Adicionar embaixador\n");
        printf("7. Autorizar visita\n");
        printf("8. Cancelar visita\n");
        printf("9. Confirmar realização da visita\n");
        printf("10. Alterar informação da visita\n");
        printf("11. Alterar informação do embaixador\n");
        printf("12. Eliminar visita\n");
        printf("13. Eliminar embaixador\n");
        printf("14. Gravar visitas\n");
        printf("15. Sair\n");
        printf("==============================\n");
        printf("Escolha uma das opções (1-15): ");

         if (scanf("%d", &escolha) != 1) {

            printf("Entrada inválida. Por favor, insira um número entre 1 e 15.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            continue;
        }

        switch (escolha)
        {
        case 1:
            listarVisitas(visitas, &totalVisitas);
            break;
        case 2:
			listarEmbaixadores(embaixadores, &totalEmbaixadores);
            break;
        case 3:
            consultarVisitas(visitas, &totalVisitas);
            break;
        case 4:
			consultarEmbaixadores(embaixadores, &totalEmbaixadores);
            break;
        case 5:
            adicionarVisitas(visitas, &totalVisitas, embaixadores, totalEmbaixadores);
            break;
        case 6:
			adicionarEmbaixadores(embaixadores, &totalEmbaixadores);
            break;
        case 7:
             autorizarVisitas(visitas, &totalVisitas);
            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;
        case 11:

            break;
        case 12:

            break;
        case 13:

            break;
        case 14:

            break;
        case 15:
            exit(0);
            break;
        default:
            printf("Escolha inválida, insira um numero de 1 a 15.\n");
        }

    } while (escolha != 15);

    return 0;
}