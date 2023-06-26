#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        sort(coins.begin(), coins.end());
        int V[coins.size()][amount+1];
        for(int i = 0; i < (int) coins.size(); i++) V[i][0] = 1;

        for(int i = coins.size()-1; i >= 0; i--){
            int coin = coins[i];
            for(int j = 1; j <= amount; j++){
                V[i][j] = 0;
                if(coin <= j) V[i][j] += V[i][j-coin];
                if(i+1 < coins.size()) V[i][j] += V[i+1][j];
            }
        }
    return V[0][amount];
 }

 int main(void){
    vector<int> coins;
    coins.push_back(5);
    coins.push_back(2);
    coins.push_back(1);
    cout << change(5, coins) << endl;
}