#include <stdio.h>
#include <string.h>

void inverterVetor(int *vetor, int tamanho){
    int i, temp;

    for(i = 0; i < tamanho/2; i++){
        temp = vetor[i];
        vetor[i] = vetor[tamanho - i -1];
        vetor[tamanho - i -1] = temp;
    }
}

int main() {

    int i,x,tamanho;
    int matriz[3][5] = {{4,6,7,3,1},{8,9,0,2,2},{2,1,4,7,9}};

    for (i = 0; i < 3; i++){
        tamanho = sizeof(matriz[i])/sizeof(int);
        inverterVetor(matriz[i], tamanho);
    }

    for (i = 0; i < 3; i++){
        for(x=0; x < 5; x++){
            printf("%d", matriz[i][x]);
        }

        printf("\n");
    }

    return 0;
}