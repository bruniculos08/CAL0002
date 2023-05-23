#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int Maximize(vector<int> *values, int size);

int main(){
    int size, pieces_num;
    cin >> size >> pieces_num;

    vector<int> values;
    for(int i = 0; i < pieces_num; i++){
        cin >> values[i];
    }

    cout << "Max(" << size << ") = " << Maximize(&values, size) << endl;
}
