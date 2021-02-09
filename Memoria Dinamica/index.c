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
    /* Cria array de carros */
    carro_t *carros = malloc(QTD_CARROS * sizeof(carro_t));

    /* Preenche os dados de cada Carro na array */
    carro_preencher(&carros[0], "Chevrolet Onix", 17463, 17662, 12007);
    carro_preencher(&carros[1], "Chevrolet Onix Plus", 8722, 9123, 6670);
    carro_preencher(&carros[2], "Hyundai HB20", 6555, 8420, 7042);
    carro_preencher(&carros[3], "Volkswagen Gol", 6030, 5944, 5681);
    carro_preencher(&carros[4], "Fiat Strada", 5419, 5190, 4799);

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