#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

int left_son(int i);
int right_son(int i);
void heapSort(int *array, int array_size);
void build_max_heap(int *array, int array_size);
void max_heapfy(int *array, int array_size, int index);

struct timeval tv_ini, tv_fim;
unsigned long time_diff, sec_diff, usec_diff, msec_diff;

int left_son(int i){
    return 2*i+1;
}

int right_son(int i){
    return 2*i+2;
}

void max_heapfy(int *array, int array_size, int index){
    int maior = index;
    int temp;
    
    if(left_son(index) >= array_size) return;
    else if(right_son(index) < array_size && array[left_son(index)] <= array[right_son(index)]) maior = right_son(index);
    else maior = left_son(index);

    if(array[maior] > array[index]){
        temp = array[maior];
        array[maior] = array[index];
        array[index] = temp;
    }
    max_heapfy(array, array_size, maior);
}

void build_max_heap(int *array, int array_size){
    // Na metade do vetor estarão os últimos vetores pais, por isso é a partir deles que se inicia a...
    // ... execução do max_heapfy:
    for(int i = (int) floor(array_size/2) - 1; i>=0; i--){
        max_heapfy(array, array_size, i);
    }
}

void heapSort(int *array, int array_size){
    int temp;
    build_max_heap(array, array_size);
    for(int i = array_size; i > 0; i--){
        temp = array[0];
        array[0] = array[i-1];
        array[i-1] = temp;
        max_heapfy(array, i-1, 0);
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
        heapSort(array, i);
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
    // int array_size = 10;
    // int *array = malloc(sizeof(int)*array_size);
    // for(int i = 0; i < array_size; i++) array[i] = array_size-i;
    // print_array(array, array_size);
    // heapSort(array, array_size);
    // print_array(array, array_size);
}