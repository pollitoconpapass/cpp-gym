#include <iostream>
using namespace std;

int is_prime(int n) {
    if(n==1) return 0;

    float limite = sqrt(n);

    for(int i=2; i<=limite; i++){
        if(n%i==0) return 0;
    }

    return 1;
}

int prime_number_10001() {
    int cont = 0;
    int NUM_MAX = 1000000;

    for(int i = 2; i <= NUM_MAX; i++) {
        if(is_prime(i)) {
            cont++;

            if (cont == 10001) {
                return i;
            }
        }
    }

}

int main() {
    int n;

    n = prime_number_10001();
    cout << n << endl;
    return 0;
}