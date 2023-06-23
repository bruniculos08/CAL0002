#include <iostream>
#include <vector>

using namespace std;

int getMaxDuplicate(int n, int x, int y){
    while(x > n || y > n){
        n *= 2;    
    }
    return n;
}

void solve(int n, int x, int y, int **matrix){
    int m = getMaxDuplicate(n, x, y);
    int m_previus;
    int value = 0;
    do{
        m_previus = m - n;
        if(x > m_previus && y <= m_previus){
            value += m_previus;
            x -= n;
        }
        else if(x <= m_previus && y > m_previus){
            value += m_previus;
            y -= n;
        }
        m_previus -= n;
        m -= n;
    } while(m_previus > n);
    value += matrix[x-1][y-1];
    cout << "Valor = " << value << endl;
}

int main(){
    int n, x, y;
    cin >> n;
    cin >> x >> y;
    cout << "x = " << x << " y = " << y << endl;
    int **matrix;
    matrix = (int**)malloc(n);

    for(int i = 0; i < n; i++){
        matrix[i] = (int*)malloc(n);
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    solve(n, x, y, matrix);
}