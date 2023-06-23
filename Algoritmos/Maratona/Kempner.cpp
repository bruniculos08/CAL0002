#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void calc(int n){

    int max = sqrt(sqrt( double(n) ));
    int a, b, c, d, resto_d, resto_c, resto_b, resto_a;

    vector<vector<int>> set_list;

    for(d = 0; d <= max; d++){
        resto_d = n - d*d*d*d;
        if(resto_d < 0){
            d = max+1;
            continue;
        }

        for(c = 0; c <= d; c++){
            resto_c = resto_d - c*c*c*c;
            if(resto_c < 0){
                c = d+1;
                continue;
            }

            for(b = 0; b <= c; b++){
                resto_b = resto_c - b*b*b*b;
                if(resto_b < 0){
                    b = c+1;
                    continue;
                }

                for(a = 0; a <= b; a++){
                    if(resto_a < 0){
                        a = b+1;
                        continue;
                    }
                    
                    resto_a = resto_b - a*a*a*a;

                    if(resto_a == 0){
                        vector<int> set;
                        set.push_back(a);
                        set.push_back(b);
                        set.push_back(c);
                        set.push_back(d);
                        set_list.push_back(set);
                    }
                }
            }
        }
    }

    cout << set_list.size() << endl;

    for(int i = 0; i < set_list.size(); i++){
        for(int j = 0; j < 4; j++){
            cout << set_list[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    int q, n;
    cin >> q;
    
    for(int i = 0; i < q; i++){
        cin >> n;
        calc(n);
    }
}
