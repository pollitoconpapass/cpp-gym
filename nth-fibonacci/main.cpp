/*
Write a function that, when given a number n (n >= 1 ), returns the nth number in the Fibonacci Sequence.

For example:
nthFibo(4) == 2
Because 2 is the 4th number in the Fibonacci Sequence.

For reference, the first two numbers in the Fibonacci sequence are 0 and 1, and each subsequent number is the sum of the previous two.

LINK: https://www.codewars.com/kata/522551eee9abb932420004a0/cpp
*/

#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int nthFibo(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = fibonacci(i);
    }

    return v[n-1];
}

int main() {
    cout << nthFibo(40) << endl;
    return 0;
}