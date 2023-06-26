#include <bits/stdc++.h>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    if(target == 0) return 1;
    int V[target+1];
    V[0] = 1;
    for(int i = 1; i <= target; i++){
        V[i] = -1;
        int ans = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] <= i){
                int x = i - nums[j];
                ans += V[x];
            }
            else break;
        }
        V[i] = ans;
    }
    return V[target];
}

int main(void){

}