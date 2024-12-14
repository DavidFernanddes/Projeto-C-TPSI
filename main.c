#include <stdio.h>
#include <stdlib.h>
#include "ambassador.h"
#include "visit.h"

int main()
{
    carregarVisitas();
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

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            listarVisitas();
            break;
        case 2:

            break;
        case 3:
            consultarVisitas();
            break;
        case 4:

            break;
        case 5:
            adicionarVisitas();
            break;
        case 6:

            break;
        case 7:
            autorizarVisitas();
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