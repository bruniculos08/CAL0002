#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int MaximizeRecursive(vector<int> *values, int size, int max_profit, vector<int> *cuts){

    int profit;
    max_profit = 0;
    for(int i = 1; i <= size; i++){
        profit = MaximizeRecursive(values, size-i, 0, cuts) + (*values)[i-1];
        if(max_profit < profit){
            max_profit = profit;
            (*cuts)[size] = i;
        }
    }

    for(int i = 0; i <= size && size+1 == (*cuts).size(); i++) 
        cout << "best cut when bar is with size " << i << " = " << (*cuts)[i] << endl;
    return max_profit;
}

int MaximizeDynamic(vector<int> *values, int size){
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

    for(int i = 0; i <= size; i++) 
        cout << "best cut when bar is with size " << i << " = " << cuts[i] << endl;
    return max_profits[size];
}

int main(){
    vector<int> values;
    values = {1, 3 , 11, 16, 19, 10, 2000};
    int result;

    vector<int> cuts (values.size()+1);

    result = MaximizeRecursive(&values, values.size(), values.size(), &cuts);
    cout << "Max( p_" << values.size() << " ) = " << result << endl;
    result = MaximizeDynamic(&values, values.size());
    cout << "Max( p_" << values.size() << " ) = " << result << endl;
}
