#include<bits/stdc++.h>

using namespace std;

int press(vector<bool> &teclado, int botao){
    if(botao == 1){
        // teclado[0] = ~teclado[0];
        teclado[1] = ~teclado[1];
        teclado[4] = ~teclado[4];
        return (int) teclado[1] + (int) teclado[4];
    }
    else if(botao == 2){
        teclado[0] = ~teclado[0];
        // teclado[1] = ~teclado[1];
        teclado[2] = ~teclado[2];
        teclado[4] = ~teclado[4];
        teclado[5] = ~teclado[5];
        return (int) teclado[2] + (int) teclado[4] + (int) teclado[0] + (int) teclado[5]; 
    }
    else if(botao == 3){
        teclado[1] = ~teclado[1];
        // teclado[2] = ~teclado[2];
        teclado[3] = ~teclado[3];
        teclado[5] = ~teclado[5];
        teclado[6] = ~teclado[6];
    }
    else if(botao == 4){
        // teclado[3] = ~teclado[3];
        teclado[2] = ~teclado[2];
        teclado[6] = ~teclado[6];
    }
    else if(botao == 5){
        // teclado[4] = ~teclado[4];
        teclado[1] = ~teclado[1];
        teclado[0] = ~teclado[0];
        teclado[5] = ~teclado[5];
        teclado[7] = ~teclado[7];
    }
    else if(botao == 6){
        teclado[4] = ~teclado[4];
        teclado[1] = ~teclado[1];
        teclado[2] = ~teclado[2];
        // teclado[5] = ~teclado[5];
        teclado[6] = ~teclado[6];
        teclado[7] = ~teclado[7];
        teclado[8] = ~teclado[8];
    }
    else if(botao == 7){
        teclado[2] = ~teclado[2];
        teclado[5] = ~teclado[5];
        // teclado[6] = ~teclado[6];
        teclado[3] = ~teclado[3];
        teclado[8] = ~teclado[8];
    }
    else if(botao == 8){
        teclado[4] = ~teclado[4];
        teclado[5] = ~teclado[5];
        // teclado[7] = ~teclado[7];
        teclado[8] = ~teclado[8];
        teclado[9] = ~teclado[9];
    }
    else if(botao == 9){
        teclado[5] = ~teclado[5];
        teclado[6] = ~teclado[6];
        teclado[7] = ~teclado[7];
        // teclado[8] = ~teclado[8];
        teclado[9] = ~teclado[9];
    }
    else if(botao == 10){
        teclado[7] = ~teclado[7];
        teclado[8] = ~teclado[8];
        // teclado[9] = ~teclado[9];
    }
}

int minPress(vector<bool> teclado, int count){
    count++;
    for(int i = 0; i < 10; i++){

    }

}

int main(void){

}

//