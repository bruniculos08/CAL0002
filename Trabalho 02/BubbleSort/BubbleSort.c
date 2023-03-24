#include <stdlib.h>
#include <stdio.h>

void bubble_sort(int *array, int array_size){
    int aux;
    for(int i=array_size-1; i>=0; i--){
        for(int j=0; j<i; j++){
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

int main(){
    int array_size = 10;
    int *array = malloc(array_size*sizeof(int));
    for(int i = 10; i > 0; i--) array[10-i] = i;
    bubble_sort(array, array_size);
    print_array(array, array_size);
}