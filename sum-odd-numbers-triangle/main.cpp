/*
Given the triangle of consecutive odd numbers:

             1
          3     5
       7     9    11
   13    15    17    19
21    23    25    27    29
...
Calculate the sum of the numbers in the nth row of this triangle (starting at index 1) e.g.: (Input --> Output)

1 -->  1
2 --> 3 + 5 = 8

LINK: https://www.codewars.com/kata/55fd2d567d94ac3bc9000064/cpp
*/

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