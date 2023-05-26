#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int BackPackRecursive(vector<int> *values, vector<int> *weights, int max_weight, int i){
    if(max_weight == 0 || i < 0) return 0;
    int max_value, into, not_into;

    if((*weights)[i] > max_weight) return BackPackRecursive(values, weights, max_weight, i-1);

    into = BackPackRecursive(values, weights, max_weight - (*weights)[i], i-1) + (*values)[i];
    not_into = BackPackRecursive(values, weights, max_weight, i-1);

    return max(into, not_into);
}

int initBackPackRecursive(vector<int> *values, vector<int> *weights, int max_weight){
    return BackPackRecursive(values, weights, max_weight, (*values).size());
}

int BackPackBottomUp(vector<int> values, vector<int> weights, int max_weight){
    int n = values.size();
    int V[max_weight+1][n+1];

    // (1) Quando a capacidade da mochila é 0 não se coloca item na mochila, isto é, quando...
    // ... X = 0, qualquer instância do problema V(j, X) retornará valor máximo 0:  
    for(int j = 0; j <= n; j++) 
        V[0][j] = 0;

    // (2) Quando a quantidade de itens restantes a serem colocados na mochila é 0, isto é, quando...
    // ... j = 0, qualquer instância do probrela V(j, X) retornará valor máximo 0:
    for(int X = 0; X <= max_weight; X++) 
        V[X][0] = 0;
    
    // (3) Vamos verificar o valor máximo para cada capacidade X a melhor solução considerando...
    // ... o j-ésimo item e portanto um quantidade j de itens: 
    for(int X = 1; X <= max_weight; X++){
        for(int j = 1; j <= n; j++){

            // (3.1) A possibilidade de não colocar o item j na mochila com capacidade X indica que...
            // ...  o valor máximo obtido será o valor máximo da intância V(j-1, X), isto é, o valor...
            // ... máximo na instância com o item j-1 e capacidade X:
            int without_j = V[X][j-1];

            // (3.2) Se a capacidade X é menor que o peso do item j então o item j não pode ser...
            // ... colocado na mochila, logo a solução da instância V(j, X) é a mesma solução da...
            // ... instância V(j-1, X) dado que o item j não pode ser colocado na mochila:
            if(weights[j-1] > X) 
                V[X][j] = without_j;

            // (3.3) Se é possível colocar o item j na mochila, note que a instância V(j, X) tem...
            // ... duas possíveis soluções:
            //
            //     (a) se colocarmos o item j teremos: V(j, X) = v_j + V(j-1, X - w_j) ; perceba que...
            //     ... a instância para o item j-1 nesse caso terá capacidade X - w_j, pois o item...
            //     ... j tem peso w_j.
            //
            //     (b) se não colocarmos o item j teremos: V(j, X) = V(j-1, X) ; perceba que a instância...
            //     ... para o item j-1 nesse caso terá capacidade X, pois o item j não ocupou capacida da...
            //     ... da mochila.
            //
            // O valor (solução) V(j, X) deve portanto ser o maior destas duas possibilidades, isto é, o...
            // maior entre v_j + V(j-1, X - w_j) e V(j-1, X);
            else{
                int with_j = V[X-weights[j-1]][j-1] + values[j-1];

                if(with_j >= without_j)
                    V[X][j] = with_j;
                else 
                    V[X][j] = without_j;
            }

        }
    }

    // (4) Se retorna a instância V(n, W):
    return V[max_weight][n];
}

int main(void){
    vector<int> values = {10, 7, 25, 24};
    vector<int> weights = {2, 1, 6, 5};
    int max_weight = 7;

    cout << "result = " << initBackPackRecursive(&values, &weights, max_weight) << endl;
    cout << "result = " << BackPackBottomUp(values, weights, max_weight) << endl;
}