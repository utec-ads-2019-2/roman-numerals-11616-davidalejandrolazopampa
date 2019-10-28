//
// Created by David Lazo on 23/10/2019.
//
#include <iostream>
#include <map>
using namespace std;
char letrar[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L","XL", "X", "IX", "V", "IV", "I"},in[50], *tip2;
int numeror[13] = {1000, 900, 500, 400, 100, 90, 50,40, 10, 9, 5, 4, 1},n;
map<string, int> numero;map<int, string> letra;
char* roma(int valor) {
    char *davlp = new char[30], cnt = 0;
    for(int i = 0; i < 13; i++) {
        while(valor >= numeror[i]) {
            valor = valor - numeror[i];
            davlp[cnt++] = letrar[i][0];
            if(letrar[i][1]){davlp[cnt++] = letrar[i][1];}
            davlp[cnt] = '\0';
        }
    }
    return davlp;
}
int main() {
    for(n = 1; n <= 3999; n++) {
        tip2 = roma(n);
        numero[tip2] = n;
        letra[n] = tip2;
    }
    while(scanf("%s", in) == 1) {
        if(in[0] >= '0' && in[0] <= '9') {
            sscanf(in, "%d", &n);
            cout << letra[n] << endl;
        } else
            cout << numero[in] << endl;
    }
    return 0;
}