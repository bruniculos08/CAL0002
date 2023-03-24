#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heap(int *array, int array_size);
void build_max_heap(int *array, int array_size);
void max_heapfy(int *array, int array_size, int index);
int left_son(int i);
int right_son(int i);

int left_son(int i){
    return 2*i+1;
}

int right_son(int i){
    return 2*i+2;
}

void max_heapfy(int *array, int array_size, int index){
    int maior = index;
    int temp;
    // Como começamos da metade do vetor, note que, se o vetor tiver tamanho ímpar, o primeiro índice pai...
    // ... a ser verificado por esta função terá 2 filho (devido ao arredondamento da divisão) e caso o vetor...
    // ... tenha tamanho ímpar:
    if(right_son(index) <= array_size-1 && array[right_son(index)] >= array[left_son(index)] 
    && array[right_son(index)] > array[index]){
        maior = right_son(index);
        temp = array[index];
        array[index] = array[right_son(index)];
        array[right_son(index)] = temp;
    }
    else if(array[index] < array[left_son(index)]){
        maior = left_son(index);
        temp = array[index];
        array[index] = array[left_son(index)];
        array[left_son(index)] = temp;
    }
}

void build_max_heap(int *array, int array_size){
    // Na metade do vetor estarão os últimos vetores pais, por isso é a partir deles que se inicia a...
    // ... execução do max_heapfy:
    for(int i = (int) floor(array_size/2) - 1; i>=0; i--){
        max_heapfy(array, array_size, i);
    }
}

void heap(int *array, int array_size){
    int temp;
    for(int i = array_size; i > 0; i--){
        build_max_heap(array, i);
        temp = array[0];
        array[0] = array[i-1];
        array[i-1] = temp;
    }
    return array;
}

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++) printf("%i ", array[i]);
    printf("\n");
}

int main(){
    int array_size = 10;
    int *array = malloc(array_size*sizeof(int));
    for(int i = 10; i > 0; i--) array[10-i] = i;
    heap(array, array_size);
    print_array(array, array_size);
}