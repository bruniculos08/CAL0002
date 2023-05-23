#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int fibRecall(int n, vector<int> *aux){
    if((*aux).at(n) != -1) return (*aux).at(n);
    else {
        (*aux)[n] = fibRecall(n-1, aux) + fibRecall(n-2, aux);
        return (*aux)[n];
    }
}

int fibTopDown(int n){
    vector<int> aux;
    aux.push_back(1);
    aux.push_back(1);
    for(int i = 2; i <= n; i++) aux.push_back(-1);
    return fibRecall(n, &aux);
}

int fibBottomUp(int n){
    vector<int> aux;
    aux.push_back(1);
    aux.push_back(1);
    for(int i = 2; i <= n; i++){
        aux[i] = aux[i-1] + aux[i-2];
    }
    return aux[n];
}

int main(){
    int n;
    cin >> n;
    cout << "Método TopDown -> F(" << n << ") = " << fibTopDown(n) << endl;
    cout << "Método BottomUp -> F(" << n << ") = " << fibBottomUp(n) << endl;
}
