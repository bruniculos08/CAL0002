#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

struct timeval tv_ini, tv_fim;
unsigned long time_diff, sec_diff, usec_diff, msec_diff;

int partition(int *array, int low, int pivot){
    int last_bigger = low - 1, aux;
    for(int j = low; j < pivot; j++){
        if(array[j] < array[pivot]){
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
    if(low < pivot){
        int low_partition = partition(array, low, pivot);
        quickSort(array, low, low_partition-1);
        quickSort(array, low_partition+1, pivot);
    }
}

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
        quickSort(array, 0, i-1);
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