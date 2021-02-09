#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (100)
#define QTD_CARROS (5)

struct CARRO
{
    char nome[MAX];
    int mes1;
    int mes2;
    int mes3;
    float media;
};

typedef struct CARRO carro_t;

void carro_preencher(carro_t *c, char *nome, int mes1, int mes2, int mes3)
{
    strncpy(c->nome, nome, MAX);
    c->mes1 = mes1;
    c->mes2 = mes2;
    c->mes3 = mes3;
    c->media = (mes1 + mes2 + mes3) / 3;
}

int main()
{
    /* Declarando variaveis */

    char modelo[MAX];
    int mes1, mes2, mes3;

    /* Cria array de carros */

    carro_t *carros = malloc(QTD_CARROS * sizeof(carro_t));

    if (carros == NULL)
    {
        printf("Houve um problema, tente novamente!");
        exit(1);
    }
    /* Preenche os dados de cada Carro na array */

    for (size_t i = 0; i < QTD_CARROS; i++)
    {
        printf("Informe o modelo do carro:");
        gets(modelo);
        printf("Informe o número de vendas do primeiro mês:");
        scanf("%d", &mes1);
        printf("Informe o número de vendas do segundo mês:");
        scanf("%d", &mes2);
        printf("Informe o número de vendas do terceiro mês:");
        scanf("%d", &mes3);
        printf("---------------------------------------------------- \n");
        getchar();

        carro_preencher(&carros[i], modelo, mes1, mes2, mes3);
    }

    for (size_t i = 0; i < QTD_CARROS; i++)
    {
        printf("Nome: %s \n", carros[i].nome);
        printf("Mês 1: %d \n", carros[i].mes1);
        printf("Mês 2: %d \n", carros[i].mes2);
        printf("Mês 3: %d \n", carros[i].mes3);
        printf("Mêdia trimestral: %.2f \n", carros[i].media);
        printf("================================= \n");
    }

    /* Libera array de carros */

    free(carros);

    return 0;
}