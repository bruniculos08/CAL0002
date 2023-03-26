#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

struct timeval tv_ini, tv_fim;
unsigned long time_diff, sec_diff, usec_diff, msec_diff;

int linearSearch(int *array, int array_size, int target){
    for (int i = 0; i < array_size; i++) if(array[i] == target) return i;
    return -1;
}

void printArray(int *array, int n){
    for(int i = 0; i < n; i++) printf("%i ", array[i]);
    printf("\n");
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
        for(int j = 0; j < i; j++) array[j] = j;
        gettimeofday(&tv_ini, NULL);
        linearSearch(array, i, i-1);
        gettimeofday(&tv_fim, NULL);
        time_diff = (1000000L*tv_fim.tv_sec + tv_fim.tv_usec) - (1000000L*tv_ini.tv_sec + tv_ini.tv_usec);
        printTime(filePointer);
        free(array);
    }
    fprintf(filePointer, "\n");
}

int main(){
    testCase();
}