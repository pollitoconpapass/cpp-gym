/*
Task: Find whether a number is prime or not
Also, return the prime numbers from 0 to n
*/

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int test_primalidad_1(int n){
    if(n==1) return 0;
    for(int i=2; i<n; i++){
        if (n%i == 0) return 0; // -> no cumple como numero primo
    }

    return 1;
}

int test_primalidad_2(int n){
    if(n==1) return 0;
    if (n==2) return 1;

    float limite = sqrt(n);

    for(int i=2; i<=limite; i++){
        if(n%i==0) return 0;
    }

    return 1;
}

void criba(int n) { // -> numero primos desde 0 hasta n
    vector <bool> c;
    c.assign(n+1, true); // se marcan todos como primos...
    for (int i=2; i<=n; i++) { // -> recorren todos los numeros
        if (c[i]) {
            cout << i << endl; // -> al principio siempre se mostrara, esta bien ya que 2 siempre es primo
            for (int j = 2; i*j<=n; j++) {
                c[i*j] = false; // -> se colocan a todos los multiplos del numero actual (i) como falso
            }
        }
    }
}

int main()
{
    int n, valor;
    cout << "Ingresar numero: ";
    cin >> n;

    criba(n);

    // valor = test_primalidad_2(n);
    // cout << "Resultado: " << valor << endl;
    return 0;
}