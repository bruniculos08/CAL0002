#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void printArray(int *array, int n);
void insertionSort(int *array, int n);

int countSteps = 0;

void insertionSort(int *array, int n){
    int j, key, keyIndex;
    for(int i = 1; i < n; i++){
        // (1) Navegando pelo vetor pega-se:
        // a. o valor do elemento atual:
        key = array[i];
        // b. o index do elemento atual:
        keyIndex = i;
        // c. o index do valor antecessor ao atual:
        j = i-1;
        // (2) Verificando os elementos antecessores do elemento atual (enquanto forem maiores que o atual):
        while(j >= 0 && array[j] > key){
            countSteps++;
            // (2.1) Se o valor de algum elemento anterior é maior que o valor do elemento atual...
            // ... estes elementos trocam de posição (note que se o elemento antecessor do antecessor...
            // ... é maior que o elemento atual isso implica que o antecessor também será, logo o elemento atual...
            // ... já terá trocado de lugar com este antecessor, e trocará em seguida de lugar com o antecessor...
            // ... do seu antecessor inicial):
            if(key < array[j]){
                // (2.2) Elemento atual recebe o valor do elemento antecessor:
                array[keyIndex] = array[j];
                // (2.3) Elemento antecessor recebe o valr do elemento atual;
                array[j] = key;
                // (2.4) Elemento com o valor do atual inicial muda de index: 
                keyIndex = j;
            }
            // (2.5) Avança para o próximo elemento à esquerda:
            j--;
        }
    }
}

void printArray(int *array, int n){
    for(int i = 0; i < n; i++) printf("%i ", array[i]);
    printf("\n");
}

void printSteps(FILE *filePointer){
    fprintf(filePointer, "%i ", countSteps);
    countSteps = 0;    
}

void testCase(){
    FILE *filePointer;
    filePointer = fopen("PerformanceTestCase.txt", "w+");

    for(int i = 0; i < 15; i++){
        int *array = malloc(sizeof(int)*pow(2, i+1));
        printf("array %i\n", i);
        for(int j = 0; j < pow(2, i+1); j++) array[j] = pow(2, i+1)-j;
        insertionSort(array, pow(2, i+1));
        printSteps(filePointer);
        free(array);
    }
    fprintf(filePointer, "\n");
}

int main(){
    testCase();
}