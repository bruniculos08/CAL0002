#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void printCuts(vector<int> &cuts){
    int i = cuts.size() - 1;
    while(i > 0){
        cout << "corte " << cuts[i] << " | ";
        i = i - cuts[i];
    }
    cout << "\n";
}

/* A função custo do seguinte algoritmo, considerando um tamannho n, é dada por:
    T(n) = [sum_i=1_n T(n-i) + 1]
    T(n) = [sum_i=1_n T(n-i)] + n

    quer-se um limitante superior, assim, utilizando o métoda da substituição vamos
    provar que T(n) <= 2^n + n, sabendo que T(0) = 1:

    Caso base:
    T(0) <= 2^0 + 0
    1 <= 1

    Hipótese:
    T(k) <= 2^k + k
    [sum_i=1_k T(k-i)] + k <= 2^k + k
    [sum_i=1_k T(k-i)] <= 2^k
    somando as linha 1 e 3 tem-se:
    [sum_j=1_i T(k-i)] + T(k) + k <= (2^k) + (2^k) + k

    Passo:
    T(k+1) <= 2^(k+1) + (k+1)
    T(k+1) <= 2.(2^k) + (k+1)
    [sum_i=1_(k+1) T((k+1)-i)] + (k+1) <= 2.(2^k) + (k+1)
    [sum_i=2_(k+1) T((k+1)-i)] + T(k) + (k+1) <= 2.(2^k) + (k+1)
    [sum_i=2_(k+1) T((k-(i-1))] + T(k) + (k+1) <= 2.(2^k) + (k+1)

    realizando a substituição j = i-1:
    [sum_j=1_k T(k-j)] + T(k) + (k+1) <= 2.(2^k) + (k+1)
    [sum_j=1_k T(k-j)] + T(k) + k <= 2.(2^k) + k
    [sum_j=1_k T(k-j)] + T(k) + k <= (2^k) + (2^k) + k
    o que vale pela hipótese de indução.
    Qed.

    Portanto como T(n) <= 2^n + n então T(n) ∈ O(2^n) 
*/
int BarCutRecursive(vector<int> *values, int size, vector<int> *cuts){

    int profit;
    int max_profit = 0;
    for(int i = 1; i <= size; i++){
        profit = (*values)[i-1] + BarCutRecursive(values, size-i, cuts);
        if(max_profit < profit){
            max_profit = profit;
            (*cuts)[size] = i;
        }
    }

    // Esse bloco para printar a resposta está sendo desconsiderado no cálculo de complexidade:
    for(int i = 0; i <= size && size+1 == (*cuts).size(); i++) 
        cout << "best cut when bar is with size " << i << " = " << (*cuts)[i] << endl;

    // Esse bloco para printar a resposta está sendo desconsiderado no cálculo de complexidade:
    if(size+1 == (*cuts).size()) printCuts(*cuts);

    return max_profit;
}

/* A função custo do seguinte algoritmo é dada por 
    T(n) = [sum_i=1_n T(n-i)]
    porém note que apenas a primeira chamada T(n-1) terá custo diferente de O(1) pois os subproblemas das...
    ... próximas chamadas já estarão resolvidos, assim, o correto é:
    T(n) = T(n-1) + [sum_i=2_n 1]
    T(n) = T(n-1) + (n-1)
    e
    T(0) = 0
    
    abrindo a fórmula temos
    T(n) = T(n-2) + (n-2) + (n-1)
    T(n) = T(n-3) + (n-3) + (n-2) + (n-1)
        ...
    T(n) = T(n-i) + [sum_j=1_i (n-j)]

    provando que esta fórmula recursiva é válida temos:

    Caso base (i=1):
    T(n) = T(n-1) + [sum_j=1_1 (n-1)]
    T(n-1) + (n-1) = T(n-1) + [sum_j=1_1 (n-1)]
    T(n-1) + (n-1) = T(n-1) + (n-1)

    Hipótese:
    T(n) = T(n-k) + [sum_j=1_k (n-j)]

    Passo:
    T(n) = T(n-(k+1)) + [sum_j=1_(k+1) (n-j)]
    T(n-1) + (n-1) = T(n-k-1) + [sum_j=1_(k+1) (n-j)]

    usando a hipótese
    T(n-k) + [sum_j=1_k (n-j)] = T(n-k-1) + [sum_j=1_(k+1) (n-j)]

    usando a definição
    T(n-k-1) + n-k-1 + [sum_j=1_k (n-j)] = T(n-k-1) + [sum_j=1_(k+1) (n-j)]
    T(n-k-1) + n-k-1 + [sum_j=1_k (n-j)] = T(n-k-1) + [sum_j=1_k (n-j)] + n-(k+1)
    T(n-k-1) + n-k-1 + [sum_j=1_k (n-j)] = T(n-k-1) + [sum_j=1_k (n-j)] + n-k-1
    T(n-k-1) + [sum_j=1_k (n-j)] = T(n-k-1) + [sum_j=1_k (n-j)]
    portanto se tem uma igualdade válida.
    Qed.

    Note que usando a fórmula de recursão que acabamos de provar tem-se para i = n-1:
    T(n) = T(n - (n-1)) + [sum_j=1_(n-1) (n-j)]
    T(n) = T(1) + (n-1).(n/2)
    T(n) = 1 + (n^2 -n)/2
    T(n) = (n^2 - n + 2)/2

    Portanto T(n) ∈ O(n^2) 
*/
int BarCutRecursiveTopDown(vector<int> &values, int size, vector<int> &max_profit, vector<int> &cuts){
    if(size == 0) return 0;

    if(max_profit[size] == -1){
        int profit = -1;
        int value;
        for(int i = 1; i <= size; i++){
            value = values[i-1] + BarCutRecursiveTopDown(values, size-i, max_profit, cuts);
            if(value > profit){
                profit = value;
                cuts[size] = i;
            }
        }
        max_profit[size] = profit;
    }

    // Esse bloco para printar a resposta está sendo desconsiderado no cálculo de complexidade:
    for(int i = 0; i <= size && size+1 == cuts.size(); i++) 
        cout << "best cut when bar is with size " << i << " = " << cuts[i] << endl;

    // Esse bloco para printar a resposta está sendo desconsiderado no cálculo de complexidade:
    if(size+1 == cuts.size()) printCuts(cuts);

    return max_profit[size];
}

/* A função custo do seguinte algoritmo é dada por 
    T(n) = n + O(n^2)
    como n ∈ O(n^2) então
    T(n) ∈ O(n^2)
*/
int BarCutTopDown(vector<int> &values, int size){
    vector<int> max_profit(size+1);
    vector<int> cuts(size+1);

    max_profit[0] = 0;
    for(int &x : max_profit) x = -1;
    return BarCutRecursiveTopDown(values, size, max_profit, cuts);
    // Este return com a chamada de BarCutRecursiveTopDown tem complexidade O(n^2)
}

/* A função custo do seguinte algoritmo, considerando um tamannho n, é dada por:
    f(n) = [sum_i=1_n sum_j=1_i [ 1 ]] 
    f(n) = [sum_i=1_n i] 
    f(n) = n(n+1)/2 
    logo
    f(n) ∈ O(n^2) 
*/
int BarCutBottomUp(vector<int> *values, int size){
    vector<int> max_profits (size+1);
    vector<int> cuts (size+1);
    cuts[0] = 0;
    max_profits[0] = 0;

    int profit;
    for(int i = 1; i <= size; i++){
        max_profits[i] = -1;
        // (1) Para uma barra de tamanho i vericar qual o lucro máximo se retirando j onde j E [1,i]:
        for(int j = 1; j <= i; j++){
            // (2) Lucro igual ao lucro tirando um pedaço de tamanho j + lucro maximo com a barra...
            // ... de tamanho i-j:
            profit = (*values)[j-1] + max_profits[i-j];
            if(max_profits[i] < profit){
                max_profits[i] = profit;
                // (3) O corte que maximizou o lucro para barra de tamanho i é j:
                cuts[i] = j;
                // Obs.: note que se o "if" usa-se "<=" como condicional seriam contados cortes a mais...
                // ... pois se o corte j maximiza o lucro para barra de tamanho i o corte i-j também...
                // ... maximiza;
            }
        }
    }

    // Esse bloco para printar a resposta está sendo desconsiderado no cálculo de complexidade:
    for(int i = 0; i <= size; i++) 
        cout << "best cut when bar is with size " << i << " = " << cuts[i] << endl;

    // Esse bloco para printar a resposta está sendo desconsiderado no cálculo de complexidade:
    if(size+1 == cuts.size()) printCuts(cuts);
    
    return max_profits[size];
}

// Dentre as duas versões do algoritmo a que apresnta mais vantagens é a versão iterativa tenda a consumir menos memória...
// ... (pois as recursões precisam guardam endereços de retorno para função anterior) porém ambas possuem a mesma...
// ... complexidade temporal. 

int main(){
    vector<int> values;
    values = {1, 3 , 11, 16, 19, 10};
    int result;

    vector<int> cuts (values.size()+1);

    result = BarCutRecursive(&values, values.size(), &cuts);
    cout << "Max( p_" << values.size() << " ) = " << result << endl;
    
    result = BarCutTopDown(values, values.size());
    cout << "Max( p_" << values.size() << " ) = " << result << endl;

    result = BarCutBottomUp(&values, values.size());
    cout << "Max( p_" << values.size() << " ) = " << result << endl;
}
