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
    struct aluno *ProximoRegistro, *RegistroAnterior;
};

struct aluno *NovoRegistro, *RegistroAtual, *primeiro, *ultimo, *pos;

void *AlocarMemoria(void)
{
    NovoRegistro = (struct aluno *)malloc(sizeof(struct aluno));
    if (NovoRegistro == NULL)
    {
        printf("Memoria insuficiente!");
        exit(1);
    }

    NovoRegistro->RegistroAnterior = RegistroAtual;
    NovoRegistro->ProximoRegistro = NULL;
    return (NovoRegistro);
}

void Listar()
{
    printf("\nL i s t a g e m \n\n");
    pos = primeiro;
    while (pos <= ultimo)
    {
        float media = (pos->nota1 + pos->nota2 + pos->nota3) / 3;
        printf("Nome do aluno: %s \n", pos->nome);
        printf("Idade: %d \n", pos->idade);
        printf("Nota 1: %.2f\n", pos->nota1);
        printf("Nota 2: %.2f\n", pos->nota2);
        printf("Nota 3: %.2f\n", pos->nota3);
        printf("Média: %.2f\n", media);
        printf("\n");
        pos = pos->ProximoRegistro;
    }
    RegistroAtual = pos;
}

void Inicio()
{
    printf("Primeiro Registro:\n");
    pos = primeiro;
    printf("Nome do aluno: %s \n", pos->nome);
    printf("Idade: %d \n", pos->idade);
    printf("Nota 1: %.2f\n", pos->nota1);
    printf("Nota 2: %.2f\n", pos->nota2);
    printf("Nota 3: %.2f\n", pos->nota3);
    RegistroAtual = pos;
}

void Ultimo()
{
    printf("Ultimo Registro:\n");
    pos = ultimo;
    printf("Nome do aluno: %s \n", pos->nome);
    printf("Idade: %d \n", pos->idade);
    printf("Nota 1: %.2f\n", pos->nota1);
    printf("Nota 2: %.2f\n", pos->nota2);
    printf("Nota 3: %.2f\n", pos->nota3);
    RegistroAtual = pos;
}

struct aluno *insere(struct aluno *pt, char NomeAluno[30], int IdadeAluno, float nota1, float nota2, float nota3)
{
    strcpy(pt->nome, NomeAluno);
    pt->idade = IdadeAluno;
    pt->nota1 = nota1;
    pt->nota2 = nota2;
    pt->nota3 = nota3;

    pt->ProximoRegistro = AlocarMemoria();
    ultimo = pt->ProximoRegistro->RegistroAnterior;
    return (pt->ProximoRegistro);
}

void Liberar()
{
    printf("Memoria Liberada!");
    free(NovoRegistro);
}

void Proximo()
{
    printf("Proximo Registro:\n");
    pos = RegistroAtual->ProximoRegistro;
    if (RegistroAtual->ProximoRegistro != NULL && RegistroAtual != ultimo)
    {
        printf("Nome do aluno: %s \n", pos->nome);
        printf("Idade: %d \n", pos->idade);
        printf("Nota 1: %.2f\n", pos->nota1);
        printf("Nota 2: %.2f\n", pos->nota2);
        printf("Nota 3: %.2f\n", pos->nota3);
        RegistroAtual = pos;
    }
}

void Anterior()
{
    printf("Registro Anterior:\n");
    pos = RegistroAtual->RegistroAnterior;
    if (RegistroAtual->RegistroAnterior != NULL)
    {
        printf("Nome do aluno: %s \n", pos->nome);
        printf("Idade: %d \n", pos->idade);
        printf("Nota 1: %.2f\n", pos->nota1);
        printf("Nota 2: %.2f\n", pos->nota2);
        printf("Nota 3: %.2f\n", pos->nota3);
        RegistroAtual = pos;
    }
}

main()
{
    char NomeAluno[30];
    int IdadeAluno;
    float nota1, nota2, nota3;
    int op = 1;
    int sentinela = 1;
    while (op <= 8)
    {
        printf("\n\n");
        printf("***Menu de Opcoes***\n");
        printf("1 - Cadastrar \n");
        printf("2 - Inicio \n");
        printf("3 - Ultimo \n");
        printf("4 - Proximo \n");
        printf("5 - Anterior \n");
        printf("6 - Listar \n");
        printf("7 - Limpar \n");
        printf("8 - Fim \n\n");
        printf("Escolha uma das opcoes: ");
        scanf("%d", &op);
        if (sentinela == 1)
        {
            primeiro = AlocarMemoria();
            RegistroAtual = primeiro;
            sentinela = 0;
        }
        printf("\n\n");
        if (op == 1)
        {
            getchar();
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
            RegistroAtual = insere(RegistroAtual, NomeAluno, IdadeAluno, nota1, nota2, nota3);
        }
        if (op == 2)
            Inicio();
        if (op == 3)
            Ultimo();
        if (op == 4)
            Proximo();
        if (op == 5)
            Anterior();
        if (op == 6)
            Listar();
        if (op == 7)
            Liberar();
        if (op == 8)
        {
            printf("Fim.");
            op = 9;
        }
    }

    return 0;
}