#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/* A complexidade da versão do algoritmo de Fibonacci Top-Down é dada pela função custo (onde n é o indica...
   ... o número de fibonacci a ser calculado):
    T(n) = T(n-1) + T(n-2)
    
    porém como a chamada fibRecall(n-1, aux) irá calcular todos os números de fibonacci anteriores, a chamada
    fibRecall(n-2, aux) téra complexidade O(1), logo:

    T(n) = T(n-1) + O(1)

    Pelo método da substituição vamos provar que T(n) <= n sendo que T(1) = 1:

    Caso base:
    T(1) <= 1;
    1 <= 1

    Hipótese:
    T(k) <= k
    
    Passo:
    T(k+1) <= k+1

    usando a definição:
    T(k) + 1 <= k + 1
    T(k) <= k
    o que vale pela hipótese de indução.
    Qed.
*/
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


/* A complexidade da versão do algoritmo de Fibonacci Bottom-Up é dada pela função custo (onde n é o indica...
   ... o número de fibonacci a ser calculado):
    f(n) = 1 + [sum_i=2_n 1]
    f(n) = 1 + n-1
    f(n) = n
    logo 
    f(n) ∈ O(n)
*/
int fibBottomUp(int n){
    vector<int> aux;
    aux.push_back(1);
    aux.push_back(1);
    for(int i = 2; i <= n; i++){
        aux[i] = aux[i-1] + aux[i-2];
    }
    return aux[n];
}

// Ambas os algoritmos para o cálculo dos números de fibonacci possuem complexidade temporal O(n) e complexidade espacial...
// ... também O(n) porém a versão recursiva tende a consumir um pouco mais memória;

int main(){
    int n;
    cin >> n;
    cout << "Método TopDown -> F(" << n << ") = " << fibTopDown(n) << endl;
    cout << "Método BottomUp -> F(" << n << ") = " << fibBottomUp(n) << endl;
}
