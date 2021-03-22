#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila
{
    int topo, inicio;
    int capacidade_fila;
    char *pEstFila;
};

void criarfila(struct Fila *p, int capfila)
{
    p->topo = -1;
    p->inicio = -1;
    p->capacidade_fila = capfila;
    p->pEstFila = (char *)malloc(capfila * sizeof(char));
}

char inserir(struct Fila *p, char caractere)
{
    if (p->topo == p->capacidade_fila - 1)
    {
        printf("Fila cheia...");
        return 0;
    }
    else
    {
        char aux;
        p->topo++;
        aux = p->pEstFila[p->topo] = caractere;
        return aux;
    }
}

int remover(struct Fila *p)
{
    if (p->inicio == p->capacidade_fila - 1)
    {
        printf("Fila vazia...");
        p->topo = -1;
        p->inicio = -1;
        return 0;
    }
    else
    {
        char aux;
        p->inicio++;
        aux = p->pEstFila[p->inicio];
        return aux;
    }
}

void Listar_fila(struct Fila *p)
{
    int i;

    printf("\n ----------Listagem---------- \n");

    for (i = p->inicio + 1; i <= p->topo; i++)
    {
        printf("%c \n", p->pEstFila[i]);
    }

    printf("\n");
}

void Liberar_Fila(struct Fila *p)
{
    free(p->pEstFila);
}

main()
{
    struct
        Fila minhafila;
    int capacidade, op = 0;
    char caractere;

    printf("Informe a capacidade da fila? ");
    scanf("%d", &capacidade);
    criarfila(&minhafila, capacidade);
    printf("\n\n");
    printf("----------OPÇÕES----------\n");
    while (op < 5)
    {
        printf("1- Inserir na fila \n");
        printf("2- Listar a fila\n");
        printf("3- Remover na fila\n");
        printf("4- Liberar fila\n");
        printf("5- Sair\n\n");
        printf("Escolha a opcao?\n");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("\nInforme o caracter: ");
            scanf("%s", &caractere);
            getchar();
            caractere = inserir(&minhafila, caractere);
            printf("\n ----------Inserido---------- \n");
            printf("\nO caracter %c foi INSERIDO!\n\n", caractere);
        }
        if (op == 2)
        {
            Listar_fila(&minhafila);
        }
        if (op == 3)
        {
            caractere = remover(&minhafila);
            printf("\n ----------Removido---------- \n");
            printf("\nO caracter %c foi REMOVIDO!\n\n", caractere);
        }
        if (op == 4)
        {
            Liberar_Fila(&minhafila);
        }
    }
}