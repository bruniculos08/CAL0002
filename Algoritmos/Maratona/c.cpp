#include <iostream>
#include <math.h>

using namespace std;

int solve(int N){
    int combinations = 0;
    if(N%2 != 0) combinations++;
    for(int i = N/2 + 1; i > 0; i--){
        if((N-i)%2 != 0) combinations += solve(i);
    }
    return combinations;
}

int main(){
    int N;
    cin >> N;
    cout << solve(N) << endl;
}