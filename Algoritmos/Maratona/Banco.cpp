#include <bits/stdc++.h>

using namespace std;

int main(void){
    long long a, b, c;
    cin >> a >> b >> c;
    char type;
    cin >> type;

    long long total;
    if(type == 'A'){
        total = a + (long long) ((double) b*3/2 + (double) c*5/2);
    }
    if(type == 'B'){
        total = b + (long long) ((double) a * 2/3 + (double) c * 5/3);
    }
    if(type == 'C'){
        total = c + (long long) ((double) a * 2/5 + (double) b* 5/2);
    }

    cout << total << endl;

}