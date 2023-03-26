#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printArray(int *array, int n);
int binarySearch(int *array, int target, int size);
int *mergeSort(int *array, int start, int end);
int *merge(int *array, int left, int right, int end);

int countSteps = 0;

int binarySearch(int *array, int target, int size){
    if(array == NULL) return -1;
    int left = 0;
    int right = size-1;
    int middle = (right + left)/2;
    do{
        if(array[middle] == target) return middle;
        else if(array[middle] > target) right = middle - 1;
        else left = middle + 1;
        middle = (left + right)/2;
    } while (left <= right);
    return -1;
}

int *mergeSort(int *array, int start, int end) {
    countSteps++;
    if(array == NULL || start >= end) return array;
    array = mergeSort(array, start, (end+start)/2);
    array = mergeSort(array, (end+start)/2 + 1, end);
    array = merge(array, start, (end+start)/2 + 1, end);
    return array;   
}

int *merge(int *array, int left, int right, int end) {
    if(array == NULL) return NULL;
    else if(right > end || left > right) return array;

    int *tempArray = malloc((1 + end-left)*sizeof(int));
    int l = left, r = right;
    for(int i = 0; i <= end-left; i++){
        countSteps++;

        if(l > right-1){
            tempArray[i] = array[r];
            r++;
        }
        else if(r > end){
            tempArray[i] = array[l];
            l++;
        }
        else if(array[l] <= array[r]){
            tempArray[i] = array[l];
            l++;
        }
        else{
            tempArray[i] = array[r];
            r++;
        }
    }
    for(int i = 0; i <= end-left; i++){
        array[i+left] = tempArray[i];    
    }
    return array;
}

void printArray(int *array, int n){
    for(int i = 0; i < n; i++) printf("%i ", array[i]);
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
        for(int j = 0; j < pow(2, i+1); j++) array[j] = pow(2, i+1)-j;
        array = mergeSort(array, 0, pow(2, i+1)-1);
        printSteps(filePointer);
        free(array);
    }
    fprintf(filePointer, "\n");
}


int main(){
    testCase();
}