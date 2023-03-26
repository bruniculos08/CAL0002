#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

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

struct timeval tv_ini, tv_fim;
unsigned long time_diff, sec_diff, usec_diff, msec_diff;

void printTime(FILE *filePointer){
    fprintf(filePointer, "%lu ", time_diff);
    time_diff = 0;    
}

void testCase(){
    FILE *filePointer;
    filePointer = fopen("PerformanceTestCase.txt", "w+");

    int n = 5000;
    for(int i = 0; i < n; i++){
        int *array = malloc(sizeof(int)*i);
        printf("array %i\n", i);
        for(int j = 0; j < i; j++) array[j] = i-j;
        gettimeofday(&tv_ini, NULL);
        bubble_sort(array, i);
        gettimeofday(&tv_fim, NULL);
        time_diff = (1000000L*tv_fim.tv_sec + tv_fim.tv_usec) - 
  	         (1000000L*tv_ini.tv_sec + tv_ini.tv_usec);
        printTime(filePointer);
        free(array);
    }
    fprintf(filePointer, "\n");
}

int main(){
    testCase();
}