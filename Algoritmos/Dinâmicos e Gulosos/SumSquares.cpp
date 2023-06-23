#include "math.h"
#include "vector"
#include "iostream"

using namespace std;

int numSquares(int n) {
        if(n == 0) return 1;

        // Cada instância V(x) tem como resposta o número de quadrados para x: 
        int V[n + 1];
        V[0] = 0;
        V[1] = 1;
        //int quadrados = new int[floor(sqrt(n)) + 1];
        
        for(int i = 2; i <= n; i++){
            V[i] = -1;
        }

        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i && j <= floor(sqrt(n)); j++){
                int x = i - (j*j);
                if(x >= 0 and (V[x] < V[i] || V[i] == -1)){
                    V[i] = V[x] + 1;
                    // cout << " i = " << i << " V[i] = " << V[i] << " x = " << x << " j = " << j << endl;
                } 
            }
        }

    return V[n];
}

int numSquaresBackPack(int n){
    if(n == 0) return 1;

    vector<int> weights;
    vector<int> values;
    int W = n;
    weights.push_back(0);
    values.push_back(0);
    for(int i = 1; i <= sqrt(n); i++){
        // 
        int num_itens = floor(n/(i*i));
        // int num_itens = 1;
        for(int j = weights.size(); j < num_itens; j++){
            weights.push_back(i*i);
            values.push_back(-1);
        } 
        // Como para cada quadrado perfeito se adiciona 1 ao número de quadrados perfeitos e queremos minimizar este...
        // ... número sabendo que mochila é um problema de maximização, basta invertermos os sinais para obter as resposta...
        // ... negativa da minimização;
    }

    int V[W+1][weights.size()+1];

    for(int i = 0; i < weights.size(); i++) {
        V[0][i] = 0;
    }
    for(int i = 1; i < W; i++){
        V[i][0] = -i;
        V[i][i] = 0;
    }


    for(int X = 1; X <= W; X++){
        for(int j = 1; j <= weights.size(); j++){
            if(X < weights[j]) V[X][j] = V[X][j-1];
            else{
                int pick = V[X-weights[j]][j] + values[j];
                int not_pick = V[X][j-1];
                V[X][j] = max(pick, not_pick);
            }
        }
    }

    return V[W][weights.size()];
}

int main(void){
    int n = 12;
    cout << numSquares(n) << endl;
    cout << numSquaresBackPack(n) << endl;
}