/*
You are given an odd-length array of integers, in which all of them are the same, except for one single number.

Complete the method which accepts such an array, and returns that single different number.

The input array will always be valid! (odd-length >= 3)

Examples
[1, 1, 2] ==> 2
[17, 17, 3, 17, 17, 17, 17] ==> 3

LINK: https://www.codewars.com/kata/57f609022f4d534f05000024
*/

#include <iostream>
#include <vector>
using namespace std;

int stray(vector<int> v) {
    sort(v.begin(), v.end());

    if (v[0] == v[1]) {
        return v[(v.size() - 1)];
    } else {
        return v[0];
    }

}

int main() {
    vector<int> v = {3, 17, 17};
    cout << stray(v) << endl;
    return 0;
}