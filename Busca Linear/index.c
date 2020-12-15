#include <stdio.h>
#include <string.h>

int buscar(int array[], int valor, int tamanhoArray){

    int i = 0;

    if(valor > array[tamanhoArray-1] || valor < array[0] ){
        return -1;
    }

    while (array[i] < valor){
        i++;
    }

    if(array[i] == valor){
        return i;
    }

    return -1;

}

int main() {

    int numeros[] = {1,2,3,4,5,6}, tamanhoArray = 6, valorBuscar;

    printf("Informe o valor a ser buscado:");
    scanf("%d", &valorBuscar);

    int busca = buscar(numeros, valorBuscar, tamanhoArray);

    printf("%d", busca);

    return 0;
}