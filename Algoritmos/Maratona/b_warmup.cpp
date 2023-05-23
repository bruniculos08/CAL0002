#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int fat(int n){
    if(n <= 1) return 1;
    int sum = 1;
    for(int i = n; i > 0; i--) sum *= i;
    return sum;
}

int minimumK(int N){
    int M = 1;
    int k = 0;
    vector<int> factorials;
    
    int f;
    do{
        f = fat(M);
        factorials.push_back(f);
        M++;
    } while(f <= N);


    int rest = N;
    while(rest > 0){
        while(factorials[M+1] <= rest){
            M++;
        }
        M--;
        k++;
        rest = rest - factorials[M+1];
        M = 1;
    }
    return k-1;
}

int main(){
    int N, k;
    cin >> N;
    k = minimumK(N);
    cout << k << endl;
}