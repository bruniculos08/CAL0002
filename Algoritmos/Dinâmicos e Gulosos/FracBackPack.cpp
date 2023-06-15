#include <bits/stdc++.h>

using namespace std;

struct item{
    double value, weight, reason;
};

bool compare(item i1, item i2){
    return (i1.reason <= i2.reason);
}

bool compareInverse(item i1, item i2){
    return (i1.reason >= i2.reason);
}

/* A complexidade do seguinte algoritmo, considerando a ordenação como parte do mesmo e sendo n o número de itens é dada por:
    f(n) = n + n.log(n) + n
    f(n) = 2.n + n.log(n)
    logo
    f(n) ∈ O(n.log(n))
    sem considerar a ordenação teríamos:
    f(n) = n
    logo
    f(n) ∈ O(n) 
*/
vector<double> fracBackPack(vector<item> &I, double W){
    for(size_t i = 0; i < I.size(); i++) I[i].reason = (I[i].value/I[i].weight);
    sort(I.begin(), I.end(), compareInverse);

    int i = 0;
    vector<double> f(I.size());
    double capacity = W;

    // Enquanto os itens tiverem peso menor ou igual a capacidade da mochila estes devem ser inteiramente (100%)...
    // ... adicionados na mochila:
    while(i < I.size() and  capacity >= I[i].weight){
        f[i] = 1;
        capacity = capacity - I[i].weight;
        i++;
    }

    // Quando se chega em um item cujo peso é maior que o peso restante da mochila deve-se colocar apenas...
    // ... uma porcentagem do item que irá encher a mochila (capacidade/pesoDoItem):
    if(i < f.size()){
        f[i] = capacity/I[i].weight;
    }

    for(int j = i+1; j < f.size(); j++) f[j] = 0;
    return f;
}

/* A complexidade do seguinte algoritmo, considerando a ordenação como parte do mesmo e sendo n o número de itens é dada por:
    f(n) = n + n.log(n) + n
    f(n) = 2.n + n.log(n)
    logo
    f(n) ∈ O(n.log(n))
    sem considerar a ordenação teríamos:
    f(n) = n
    logo
    f(n) ∈ O(n) 
*/
vector<double> frackBackPackV2(vector<item> &I, double W){
    for(size_t i = 0; i < I.size(); i++) I[i].reason = (I[i].value/I[i].weight);
    sort(I.begin(), I.end(), compare);

    double capacity = W;
    vector<double> f(I.size());

    for(int j = I.size()-1; j >= 0; j--){
        if(capacity >= I[j].weight){
            f[j] = 1;
            capacity = capacity - I[j].weight;
        }
        else{
            if(capacity >= 0) f[j] = capacity/I[j].weight;
            capacity = 0;
        }
    }
    return f;
}

/* A complexidade do seguinte algoritmo, considerando a ordenação como parte do mesmo e sendo n o número de itens é dada por:
    f(n) = n
    logo
    f(n) ∈ O(n) 
*/
vector<double> frackBackPackV3(vector<item> &I, double W){

    double capacity = W;
    vector<double> f(I.size());

    for(int j = I.size()-1; j >= 0; j--){
        if(capacity >= I[j].weight){
            f[j] = 1;
            capacity = capacity - I[j].weight;
        }
        else{
            if(capacity >= 0) f[j] = capacity/I[j].weight;
            capacity = 0;
        }
    }
    return f;
}

int main(void){
    
    // Problema A:
    vector<item> I = vector<item> (5);
    
    I[0].weight = 40;
    I[0].value = 840;
    
    I[1].weight = 30;
    I[1].value = 600;
    
    I[2].weight = 20;
    I[2].value = 400;
    
    I[3].weight = 10;
    I[3].value = 100;
    
    I[4].weight = 20;
    I[4].value = 300;

    vector<double> f = frackBackPackV2(I, 50);
    cout << "Resposta do problema A: " << endl; 
    for(double x : f) cout << x << " ";
    cout << "\n";
    f.clear();
    I.clear();

    // Problema B:
    I = vector<item> (5);
    
    I[0].weight = 10;
    I[0].value = 100;
    I[0].reason = 10;
    
    I[1].weight = 20;
    I[1].value = 300;
    I[1].reason = 15;
    
    I[2].weight = 30;
    I[2].value = 600;
    I[2].reason = 20;
    
    I[3].weight = 20;
    I[3].value = 400;
    I[3].reason = 20;
    
    I[4].weight = 40;
    I[4].value = 840;
    I[4].reason = 21;

    f = frackBackPackV3(I, 50);
    cout << "Resposta do problema B: " << endl; 
    for(double x : f) cout << x << " ";
    cout << "\n";
    f.clear();
    I.clear();
}