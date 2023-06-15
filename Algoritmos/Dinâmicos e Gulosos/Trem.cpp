#include <bits/stdc++.h>

using namespace std;

struct time_stamp{
    int hour, min;
};

struct train{
    int platform;
    struct time_stamp arrive, exit;
};

bool compareExit(train t1, train t2){
    if(t1.exit.hour != t2.exit.hour) return (t1.exit.hour < t2.exit.hour);
    else return (t1.exit.min < t2.exit.min);
}

bool compareTime(time_stamp t1, time_stamp t2){
    if(t1.hour != t2.hour) return (t1.hour >= t2.hour);
    else return (t1.min >= t2.min);
}

/* Sendo m o número de trens a complexidade da seguinte função é dada por:
    f(m) = m.(log m) + m
    logo
    f(m) ∈ O(m.(log m))
*/
int escalonamento(vector<train> &T){
    sort(T.begin(), T.end(), compareExit);

    int S = 1;
    size_t last_added = 0;
    for(size_t i = 1; i < T.size(); i++){
        if(compareTime(T[i].arrive, T[last_added].exit)){
            S++;
            last_added = i;
        }
    }
    return S;
}

/* Sendo n o número de plataformas e m o número de trens a complexidade da seguinte função é dada por:
    g(n, m) = [sum_i=1_m 2.O(log n)] + [sum_i=1_n m.(log m) + m]
    g(n, m) = 2.m.O(log n) + n.m.(log m) + n.m
    logo
    g(n, m) ∈ O(n.m.(log m))
*/
int auxEscalonamento(vector<train> &T){
    // (1) Criando um map com chave sendo o número da plataforma e o conteúdo sendo um vector de train para...
    // ... separar os trem por estação:
    map<int, vector<train>> train_per_station;
    // Para um map a complexidade de operações de acesso, remoção e inserção é de O(log n);
    // Para um vector a inserção ao final e acesso possuem complexidade O(1);

    // (2) Iterando sobre o vetor de trains:
    for(train x : T){
        // (2.1) Se a plataforma do train ainda não está no map:
        if(train_per_station.find(x.platform) == train_per_station.end()){
            vector<train> new_vector;
            train_per_station[x.platform] = new_vector;
            train_per_station[x.platform].push_back(x);
        }
        // (2.2) Se a plataforma do train já está no map:
        else {
            train_per_station[x.platform].push_back(x);
        }
    }

    // (3) Para cada estação verifica quantos trens irão parar por meio do algoritmo...
    // ... de escalonamento de tarefas:
    int maximum_stopped = 0;
    for(pair<int, vector<train>> p : train_per_station){
        maximum_stopped += escalonamento(p.second);
    }
    train_per_station.clear();
    return maximum_stopped;
}

int main(void){
    vector<train> T;
    train ti;

    // Adicionando t1:
    ti.platform = 1;
    ti.arrive.hour = 11;
    ti.arrive.min = 0;
    ti.exit.hour = 11;
    ti.exit.min = 30;
    T.push_back(ti);

    // Adicionando t2:
    ti.platform = 1;
    ti.arrive.hour = 10;
    ti.arrive.min = 10;
    ti.exit.hour = 10;
    ti.exit.min = 30;
    T.push_back(ti);

    // Adicionando t3:
    ti.platform = 2;
    ti.arrive.hour = 10;
    ti.arrive.min = 0;
    ti.exit.hour = 10;
    ti.exit.min = 20;
    T.push_back(ti);

    // Adicionando t4:
    ti.platform = 2;
    ti.arrive.hour = 10;
    ti.arrive.min = 30;
    ti.exit.hour = 12;
    ti.exit.min = 30;
    T.push_back(ti);

    // Adicionando t5:
    ti.platform = 3;
    ti.arrive.hour = 12;
    ti.arrive.min = 0;
    ti.exit.hour = 12;
    ti.exit.min = 30;
    T.push_back(ti);

    // Adicionando t6:
    ti.platform = 1;
    ti.arrive.hour = 9;
    ti.arrive.min = 0;
    ti.exit.hour = 10;
    ti.exit.min = 5;
    T.push_back(ti);

    int maximum_stopped = auxEscalonamento(T);
    cout << "Maximum Stopped Trains = " << maximum_stopped << endl;

    T.clear();
    return 0;
}