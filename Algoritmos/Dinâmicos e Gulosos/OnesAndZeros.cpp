#include <bits/stdc++.h>

using namespace std;

int count(char s, string &word){
    int n = 0;
    for(char &c : word){
        if(c == s) n++;
    }
    return n;
}

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<int> v0;
    vector<int> v1;
    for(string &word : strs){
        int n0 = count('0', word);
        int n1 = strs.size()-n0;
        v0.push_back(n0);
        v1.push_back(n1);
    }

    int V[strs.size()+1][m+1][n+1]; 
    
    for(int j = 0; j <= m; j++){
       for(int k = 0; k <= n; k++){
            V[0][j][k] = 0;           
       }
    }

    for(int i = 0; i < strs.size()+1; i++) V[i][0][0] = 0;
    
    // i representa a palavra a ser colocada e o número de palavras restantes (note que não era necessário que a matriz fosse...
    // ... 3D pois poderiamos usar auto &x : strs no loop abaixo como visto em uma solução de outro usuário)
    // j (m) representa o número de 0's de capacidade
    // k (n) representa o número de 1's de capacidade
    for(int i = 1; i < strs.size() + 1; i++){
       for(int j = 0; j <= m; j++){
           for(int k = 0; k <= n; k++){
                if(v0[i-1] <= j and v1[i-1] <= k)
                    V[i][j][k] = max(V[i-1][j - v0[i-1]][k - v1[i-1]] + 1, V[i-1][j][k]);
                else V[i][j][k] = V[i-1][j][k];
            }
        }
    }
    return V[strs.size()][m][n];
}

int main(void){
    vector<string> strs;
    strs.push_back("1001");
    strs.push_back("11");
    int m = 2;
    int n = 4;

    cout << findMaxForm(strs, m, n) << endl;
}