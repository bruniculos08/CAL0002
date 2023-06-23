#include <iostream>
#include <string>

using namespace std;

int count_sub(string &str, string &sub){
    int pos = 0, count = 0;
    do{
        pos = str.find(sub, pos) + 1;
        // cout << "pos = " << pos << endl;
        if(pos != 0) count++;

        if(pos + sub.size() > str.size()) break;
    } while(pos != 0);
    return count;
}

int main(void){
    long long size_dna, size_p;
    string dna, prot, sub_dna, sub_prot;
    int q;

    cin >> size_dna >> size_p;
    cin >> dna;
    cin >> prot;
    cin >> q;

    int start, end, idx0, idxn, count;
    for(int i = 0; i < q; i++){
        cin >> start >> end;
        count = 0;
        sub_prot = prot.substr(start-1, end-start+1);
        count = count_sub(dna, sub_prot);
        cout << count << endl;
    }

}