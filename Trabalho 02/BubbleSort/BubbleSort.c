#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int countSteps = 0;

void bubble_sort(int *array, int array_size){
    int aux;
    for(int i=array_size-1; i>=0; i--){
        for(int j=0; j<i; j++){
            countSteps++;
            if(array[j] > array[j+1]){
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }

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
        bubble_sort(array, pow(2, i+1));
        printSteps(filePointer);
        free(array);
    }
    fprintf(filePointer, "\n");
}

int main(){
    testCase();
}