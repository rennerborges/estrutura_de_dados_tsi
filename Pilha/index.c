#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aqui vamos criar a estrutura aluno que ficará dentro da pilha;
struct Aluno
{
    char nome[50]; // Esse [50] indica quantos caracteres essa string poderá ter;
    char status[50];
    float nota1;
    float nota2;
    float nota3;
    float media;
};

// Aqui estou criando a tipagem aluno_t;
typedef struct Aluno aluno_t;

// Nessa etapa estamos criando a pilha;
struct Pilha
{
    int topo;             // Topo da pilha;
    int capacidade_pilha; //Capacidade da pilha;
    aluno_t *aluno;       //Estrutura que remete ao aluno;
};

// Nesse procedimento iremos criar a pilha e alocar o espaço dos dados na memoria;
void criarpilha(struct Pilha *p, int capacidade_pilha)
{
    p->topo = -1;                                                     //Inicio o topo com -1 para dizer que estamos no inicio;
    p->capacidade_pilha = capacidade_pilha;                           //Será o valor de itens dentro dela, ele vem por parâmetro;
    p->aluno = (aluno_t *)malloc(capacidade_pilha * sizeof(aluno_t)); //Aqui estamos alocando na mémoria o espaço correspondente de aluno_t para a capacidade escolhida;
}

// Nessa função definimos que ela ira retornar um valor seguindo a tipagem aluno_t e nela é onde vamos empilhar;
aluno_t empilhar(struct Pilha *p, char nome[50], float nota1, float nota2, float nota3)
{
    // Precisamos de uma condição para verificar se a pilha está cheia;
    if (p->topo == p->capacidade_pilha - 1)
    {
        printf("Pilha cheia...");
        return;
    }
    else
    {
        // Entraremos aqui caso tenha espaço para empilhar;
        // Primeiro vamos declarar algumas váriaveis para prosseguirmos;
        aluno_t aluno; //Ela tem a tipagem do aluno_t;
        float media;
        char *status[50]; //Essa váriavel é um ponteiro;

        p->topo++;                 //Incrementamos um para o topo da nossa pilha;
        aluno = p->aluno[p->topo]; //Aqui pegamos a refêrencia do aluno na posição topo que até o momento está com tudo indefinido;

        // Aqui iremos calcular a média;
        media = (nota1 + nota2 + nota3) / 3;

        // Aqui estamos usando um IF ternario para atribuir um valor ao ponteiro status;
        *status = media >= 6 ? "Aprovado" : "Reprovado"; //Vale-se atentar que ele é um ponteiro;

        // Aqui é o pedaço que iremos atribuir os valores para aquela posição do aluno que até então não tinha valores;
        strncpy(aluno.nome, nome, 50); //Aqui estámos copiando os valores e substituindo;
        strncpy(aluno.status, *status, 50);
        aluno.nota1 = nota1;
        aluno.nota2 = nota2;
        aluno.nota3 = nota3;
        aluno.media = media;
        return aluno; //Optei por retornar o aluno para facilitar a exibição dos dados onde foi solicitada a função;
    }
}

// Nessa função definimos que ela ira retornar um valor seguindo a tipagem aluno_t e nela é onde vamos desempilhar;
aluno_t desempilhar(struct Pilha *p)
{
    // Temos uma validação para ver se a pilha está vazia;
    if (p->topo == -1)
    {
        printf("Pilha vazia...");
        return;
    }
    else
    {
        // Caso a pilha tenha dados iremos cair aqui;

        aluno_t aluno; //Estamos criando uma variavel aluno com a tipagem aluno_t;

        aluno = p->aluno[p->topo]; //Estamos obtendo os dados do aluno da última posição;
        p->topo == NULL;           //Aqui verificamos se o topo é NULL;
        p->topo--;                 //Enquanto aqui tiramos um valor do topo;
        return aluno;              //Retornamos aqui a antiga estrutura;
    }
}

void liberar_memoria(struct Pilha *p)
{
    free(p->aluno);
}

int main()
{
    // Aqui temos as declarações das variaveis;
    struct Pilha minhapilha; //Aqui estou declarando minhaPilha seguindo a estrutura Pilha;
    int capacidade, op = 3;
    char nome[50], status[50];
    float nota1, nota2, nota3, media;
    aluno_t aluno; //Aqui estou declarando aluno seguindo a tipagem aluno_t;

    printf("Capacidade da pilha? ");
    scanf("%d", &capacidade);            //Estamos pegando aqui  a capacidade da pilha;
    criarpilha(&minhapilha, capacidade); //Chamamos o procedimento criarpilha informando os parametros que ele precisa;
    printf("\n\n");
    printf("Opções \n\n");

    // Aqui temos um ciclo de repetição para fazermos o menu poderia ser um do while, mas optei por deixar o while mesmo;
    while (op < 4)
    {
        // Aqui temos a listagem das opções;
        printf("1- Empilhar \n");
        printf("2- Desempilhar \n");
        printf("3- Liberar mémoria \n");
        printf("4- Sair\n\n");
        printf("Escolha uma opção? ");
        scanf("%d", &op); // Aqui lemos a escolha do usuário;
        if (op == 1)      //Verifica se o usuário quer Empilhar;
        {

            getchar(); //Limpamos o cachê;

            // Aqui estamos obtendo as informações;
            printf("\nInforme o nome do aluno: ");
            gets(nome); //gets é uma função que pega string/char;

            printf("Informe a primeira nota: ");
            scanf("%f", &nota1);

            printf("Informe a segunda nota: ");
            scanf("%f", &nota2);

            printf("Informe a terceira nota: ");
            scanf("%f", &nota3);

            // Após pegar os dados envio eles para a função empilhar que me retornará o aluno para eu exibir;
            aluno = empilhar(&minhapilha, nome, nota1, nota2, nota3);

            // Assim que a função me retornar o aluno eu irei exibir os dados;
            printf("\n ---EMPILHADO--- \n");
            printf("Nome: %s\n", aluno.nome);
            printf("Nota 1: %.2f\n", aluno.nota1);
            printf("Nota 2: %.2f\n", aluno.nota2);
            printf("Nota 3: %.2f\n", aluno.nota3);
            printf("Média: %.2f\n", aluno.media);
            printf("Situação: %s\n\n", aluno.status);
        }
        if (op == 2) //Verifica se o usuário quer Desempilhar;
        {
            // Aqui chamaremos a função desempilhar para a mesma cumprir sua funcionalidade
            // Uma observação é que nessa implementação estou utilizando ela como procedimento
            desempilhar(&minhapilha);
            printf("\n ---DESEMPILHADO--- \n");
        }
        if (op == 3) //Verifica se o usuário quer Liberar a memoria;
        {
            liberar_memoria(&minhapilha);
        }
    }
}