/*
You are given two interior angles (in degrees) of a triangle.

Write a function to return the 3rd.

Note: only positive integers will be tested.

LINK: https://www.codewars.com/kata/5a023c426975981341000014
*/

#include <iostream>
using namespace std;


int otherAngle(int a, int b) {
    int res = 180 - (a + b);
    return res;

}

int main() {
    int n = otherAngle(10, 20);
    cout << n << endl;
    return 0;
}