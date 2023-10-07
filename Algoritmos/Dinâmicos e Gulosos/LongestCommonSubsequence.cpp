#include <bits/stdc++.h>

using namespace std;

int LongestCommonSubsequence(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    int dp[m+1][n+1];

    // A tática de programação dinâmica para resolver este problema é a seguinte:
    // Temos uma matrizes em que a i-ésima linha representa o índice do i-ésimo caracter da string x (s1) e...
    // .... em que a j-ésima coluna representa o índice do j-ésimo caracter da string y (s2), assim cada subproblema é...
    // ... dado por dp[i][j] onde na string x temos a opção de manter ou não o caracter x[i] e na string y temos...
    // ... a opção de manter ou não o caracter y[j], assim note que:
    //
    // i) se x[i] == y[j] a solução ótima implica em manter tais caracteres portanto o tamanho da subsequência é dado...
    //    ...por 1 + dp[i+1][j+1], isto é, 1 + a solução do problema para as strings x[i+1 até m] e y[j+1 até n];
    // 
    // ii) se x[i] != y[j] a solução ótima é então igual a melhor solução entre os seguintes subproblemas:
    //      
    //      (a) dp[i+1][j], isto é, a solução do problema para as strings x[i+1 até m] e y[j até n], ou seja, removendo...
    //          ...o caracter x[i] da string x e mantendo o caracter y[j] na string y;
    // 
    //      (b) dp[i][j+1], isto é, a solução do problema para as strings x[i até m] e y[j+1 até n], ou seja, removendo...
    //          ...o caracter y[j] da string y e mantendo o caracter X[i] na string x;
    //
    // Para a solução considere a existência de um caracter nulo no final das strings (apenas para propósito de organização)...
    // ... da matriz.

    dp[m][0] = 0;
    for(int i = 0; i < m; i++){
        if(s1[i] == s2[0]) dp[i][0] = 1;
    }

    dp[0][n] = 0;
    for(int j = 0; j < n; j++){
        if(s2[j] == s1[0]) dp[0][j] = 1;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(s1[i] == s2[j]){
                dp[i+1][j+1] = 1 + dp[i][j];
            }
            else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }            
        }
    }
    return dp[m][n];
}

int main(void){

}