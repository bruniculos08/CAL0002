#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countSteps = 0;

int partition(int *array, int low, int pivot){
    int last_bigger = low - 1, aux;
    for(int j = low; j < pivot; j++){
        countSteps++;
        if(array[j] <= array[pivot]){
            last_bigger++;
            aux = array[last_bigger];
            array[last_bigger] = array[j];
            array[j] = aux;
        }
    }
    aux = array[last_bigger+1];
    array[last_bigger+1] = array[pivot];
    array[pivot] = aux;
    return last_bigger+1;
}

void quickSort(int *array, int low, int pivot){
    countSteps++;
    if(low < pivot){
        int low_partition = partition(array, low, pivot);
        quickSort(array, low, low_partition-1);
        quickSort(array, low_partition+1, pivot);
    }
}

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++) printf("%i ", array[i]);
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
        quickSort(array, 0, pow(2, i+1));
        printSteps(filePointer);
        free(array);
    }
    fprintf(filePointer, "\n");
}

int main(){
    testCase();
}