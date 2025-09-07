#include <iostream>
using namespace std;

long long rowSumOddNumbers(unsigned n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long sum = 0;

    int ini = (n* (n-1)) + 1;
    int fin = ini + ((n*2) - 1);


    for (int i = ini; i <= fin; i++) {
        if (i%2 != 0) sum += i;
    }

    return sum;

}

long long rowSumOddNumbers2(unsigned n) {
    return n*n*n;
}

int main() {
    unsigned n = 42;
    cout << rowSumOddNumbers(n) << endl;
    return 0;
}