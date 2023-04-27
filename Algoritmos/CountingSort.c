#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int get_max(int *A, int n);

int *countingSort(int *A, int n){
    int m = get_max(A, n);
    int *B;
    int *C;
    B = malloc(n*sizeof(int));
    C = malloc((m+1)*sizeof(int));
    
    for(int j = 0; j < m+1; j++){
        C[j] = 0;
    }

    for(int i = 0; i < n; i++){
        C[A[i]] ++;
    }

    int i = -1;
    for(int j = 0; j < m+1; j++){
        while(C[j] > 0){
            i++;
            B[i] = j;
            C[j]--;
        }
    }

    return B;

}

int get_max(int *A, int n){
    int max = A[0];
    for(int i = 0; i < n; i++){
        if(A[i] > max) max = A[i];
    }
    return max;
}


int main(){
    int n = 10;
    int *A;
    A = malloc(n*sizeof(int));

    srand(time(NULL));
    for(int i = 0; i < n; i++){
        A[i] = rand()%10;
        printf("%i ", A[i]);
    }
    printf("\n");

    A = countingSort(A, n);

    for(int i = 0; i < n; i++){
        printf("%i ", A[i]);
    }
    printf("\n");

}