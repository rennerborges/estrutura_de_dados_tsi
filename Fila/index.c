#include <stdio.h>
#include <string.h>

char inf[5], xinf[1];
int f = 0, r = 0, tm = 4;

void insercao_fila(char valor)
{
    if (r <= tm)
    {
        inf[r] = valor;
        r = r + 1;
    }
    else
    {
        printf("overflow! \n");
    }
}

void listar_fila()
{
    printf("Será listado aqui a lista \n");
    for (size_t i = 0; i <= r; i++)
    {
        printf("%c ", inf[i]);
    }
    printf("\n");
}

void remocao_fila()
{
    if (f < r && f <= tm)
    {
        xinf[f] = inf[f];
        inf[f] = NULL;
        f = f + 1;
    }
    else
    {
        f = 0;
        r = 0;
        printf("underflow! \n");
    }
}

int main()
{
    char valor;
    int op;
    do
    {

        printf("====== Escolha uma das opções ======\n");
        printf("1 - Adicionar \n");
        printf("2 - Listar \n");
        printf("3 - Remover \n");
        printf("4 - Sair \n");
        printf("===================================\n");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("\nInforme o valor a ser inserido no vetor \n");
            getchar();
            scanf("%c", &valor);

            insercao_fila(valor);
        }

        if (op == 2)
        {
            listar_fila();
        }

        if (op == 3)
        {
            remocao_fila();
        }

    } while (op != 4);

    return 0;
}