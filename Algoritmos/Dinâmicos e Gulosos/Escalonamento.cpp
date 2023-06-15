#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

struct tarefa{
    string nome;
    int inicio, final;
};

bool compare_initial(tarefa t1, tarefa t2){
    return (t1.inicio < t2.inicio);
}

bool compare_final(tarefa t1, tarefa t2){
    return (t1.final < t2.final);
}

/* Sendo m o número de tarefas a função custo é dada por:
    T(m) = T(m-1) + m-1
    T(1) = 1

    para esta recursão pode-se provar por indução que 
    T(m) = T(1) + [sum_i=1_(m-2) i] 
    T(m) = T(1) + (m-2)(m-1)/2 
    T(m) = 1 + (m^2 -3m + 2)/2 
    T(m) = (m^2 -3m + 4)/2 
    
    Caso base:
    T(1) = (1^2 - 3.1 + 4)/2
    1 = (1 - 3 + 4)/2
    1 = 2/2
    1 = 1

    Hipótese:
    T(k) = (k^2 -3k + 4)/2 

    Passo:
    T(k+1) = ((k+1)^2 -3(k+1) + 4)/2
    T(k+1) = ((k+1)^2 -3(k+1) + 4)/2
    (usando a definição recursiva)
    T(k) + (k+1)-1 = ((k+1)^2 -3(k+1) + 4)/2
    T(k) + k = (k^2 + 2k + 1 - 3k - 3 + 4)/2
    T(k) + k = (k^2 + - 3k + 2 + 2k)/2
    T(k) + k = (k^2 + - 3k + 4)/2 + (2k)/2
    (usando a hipótese)
    T(k) + k = T(k) + (2k)/2
    T(k) + k = T(k) + K   
    Qed.

    Portanto T(m) ∈ O(m^2)
*/
vector<tarefa> escalonamentoRecursivo(vector<tarefa> &T){
    if(T.size() <= 1) return T;
    sort(T.begin(),T.end(),compare_initial);

    vector<tarefa> T_new, S;

    for(size_t i = 1; i < T.size(); i++){
        if(T[i].inicio >= T[0].final){
            T_new.push_back(T[i]);
       }
    }
    S = escalonamentoRecursivo(T_new);
    S.push_back(T[0]);
    return S;
}

/* Sendo m o número de tarefas a função é dada por:
    f(m) = m.(log m) + m
    logo
    f(m) ∈ O(m.(log m))
*/
vector<tarefa> escalonamento(vector<tarefa> &T){
    sort(T.begin(), T.end(), compare_final);
    vector<tarefa> S;
    S.push_back(T[0]);
    int last_added = 0;
    for(int i = 1; i < T.size(); i++){
        if(T[i].inicio >= T[last_added].final){
            S.push_back(T[i]);
            last_added = i;
        }
    }
    return S;
}

int main(void){
    vector<tarefa> agenda;
    vector<tarefa> resultado;
    
    tarefa t1;
    tarefa t2;
    tarefa t3;
    
    t1.inicio = 0; t1.final = 5; t1.nome = "t1";
    t2.inicio = 2; t2.final = 7; t2.nome = "t2";
    t3.inicio = 7; t3.final = 8; t3.nome = "t3";
    
    agenda.push_back(t1);
    agenda.push_back(t2);
    agenda.push_back(t3);

    // resultado = escalonamentoRecursivo(agenda); 
    resultado = escalonamento(agenda);

    for(tarefa x : resultado){
        cout << x.nome << endl;
    }
}
