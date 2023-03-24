#include <stdio.h>
#include <stdlib.h>

int partition(int *array, int low, int pivot){
    int last_bigger = low - 1, aux;
    for(int j = low; j < pivot; j++){
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

int main(){
    int array_size = 10;
    int *array = malloc(array_size*sizeof(int));
    for(int i = 10; i > 0; i--) array[10-i] = i;
    quickSort(array, 0, array_size-1);
    print_array(array, array_size);
}