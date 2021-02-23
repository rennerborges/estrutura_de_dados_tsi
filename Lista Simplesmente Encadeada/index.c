#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char nome[30];
    int idade;
    float nota1;
    float nota2;
    float nota3;
    struct aluno *proximo;
};

struct aluno *inicio, *novo, *atual, *fim;

void AlocarMemoria(void)
{
    novo = (struct aluno *)malloc(sizeof(struct aluno));
    if (novo == NULL)
    {
        printf("Memoria insuficiente!");
        exit(1);
    }
}

void inserir(char NomeAluno[30], int IdadeAluno, float nota1, float nota2, float nota3)
{
    strcpy(novo->nome, NomeAluno);
    novo->idade = IdadeAluno;
    novo->nota1 = nota1;
    novo->nota2 = nota2;
    novo->nota3 = nota3;

    if (atual == NULL)
    {
        novo->proximo = NULL; // nulo
        inicio = novo;
        atual = novo;
        fim = atual; // inicio e atual recebe o mesmo endereço alocado. Ex.56021
    }
    else
    {
        novo->proximo = NULL; // nulo
        atual->proximo = novo;
        atual = novo;
        fim = atual; // nó anterior aponta para o próximo nó. Ex.56021
    }
}

void listar(void)
{
    printf("\nL i s t a g e m \n\n");
    atual = inicio;
    while (atual != NULL)
    {
        float media = (atual->nota1 + atual->nota2 + atual->nota3) / 3;
        printf("Nome: %s \n", atual->nome);
        printf("Idade: %d \n", atual->idade);
        printf("Nota 1: %.2f \n", atual->nota1);
        printf("Nota 2: %.2f \n", atual->nota2);
        printf("Nota 3: %.2f \n", atual->nota3);
        printf("Média: %.2f \n", media);
        printf("\n");

        atual = atual->proximo;
    }
    atual = fim;
    printf("\n");
}

int main()
{
    int op = 1;
    char NomeAluno[30];
    int IdadeAluno;
    float nota1, nota2, nota3;

    while (op < 3)
    {
        printf("+++ Menu de opcoes +++ \n");
        printf("1-Inserir \n");
        printf("2-Listar \n");
        printf("3-Sair \n");
        printf("Escolha a opcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            AlocarMemoria();

            getchar();
            printf("\nC a d a s t r o \n\n");
            printf("Nome: ");
            gets(NomeAluno);
            printf("Idade: ");
            scanf("%d", &IdadeAluno);
            printf("Nota 1:");
            scanf("%f", &nota1);
            printf("Nota 2:");
            scanf("%f", &nota2);
            printf("Nota 3:");
            scanf("%f", &nota3);
            printf("\n");

            inserir(NomeAluno, IdadeAluno, nota1, nota2, nota3);
        }

        if (op == 2)
        {
            listar();
        }

        if (op == 3)
        {
            free(novo);
        }
    }
    return 0;
}