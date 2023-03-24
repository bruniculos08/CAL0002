#include <stdio.h>
#include <stdlib.h>

void quickSort(int *array, int low, int pivot){

}

int partition(int *array, int low, int pivot){
    int i = pivot-1, j = low, aux;
    while(i>=j+1){
        if(array[i] < pivot && array[j] >= pivot){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
        
        if(array[i] >= pivot) i--;
        if(array[j] < pivot) j++;
    }
}

int main(){

}