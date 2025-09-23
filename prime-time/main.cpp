/*
We need prime numbers and we need them now!
Write a method that takes a maximum bound and returns all primes up to and including the maximum bound.

For example,
11 => [2, 3, 5, 7, 11]

LINK: https://www.codewars.com/kata/521ef596c106a935c0000519/cpp
*/

#include <iostream>
#include <vector>
using namespace std;

vector<unsigned> prime(unsigned n) {
    vector <bool> c;
    vector <unsigned> res;

    c.assign(n+1, true); // every number is set as prime
    for (int i=2; i<=n; i++) { // -> iter through all the numbers (starting from 2)
        if (c[i]) { // -> at the beginning its set as prime, it's fine because 2 is prime
            res.push_back(i);

            for (int j = 2; i*j<=n; j++) {
                c[i*j] = false; // -> all the multiples of i are set as false. (if i*some number is equal to n, then n it's NOT prime)
            }
        }
    }
    return res;
}

int main() {
    int n = 11;
    vector<unsigned> primes = prime(n);

    for (int i: primes) {
        cout << i << endl;
    }
    return 0;
}