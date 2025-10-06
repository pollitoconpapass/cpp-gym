/*
Create a function that takes a positive integer and returns the next bigger number that can be formed by rearranging its digits.
For example:
* 12 ==> 21
* 513 ==> 531
* 2017 ==> 2071

If the digits can't be rearranged to form a bigger number, return -1:
* 9 ==> -1
* 111 ==> -1
* 531 ==> -1

LINK: https://www.codewars.com/kata/55983863da40caa2c900004e/cpp
*/

#include <iostream>
using namespace std;

long nextBigger(long n) {
    string str = to_string(n);

    int i = str.size()- 1;
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }

    if (i < 0) return -1;

    int j = str.size() - 1;
    while (str[j] <= str[i]) {
        j--;
    }

    swap(str[i], str[j]);

    reverse(str.begin() + i + 1, str.end());

    return stol(str);
}

int main() {
    long input = 2017;
    cout << nextBigger(input) << endl;
    return 0;
}