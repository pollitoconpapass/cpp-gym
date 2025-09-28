/*
Complete the square sum function so that it squares each number passed into it and then sums the results together.
For example, for [1, 2, 2] it should return 9 because 1^2 + 2^2 + 2^2 = 9.

https://www.codewars.com/kata/515e271a311df0350d00000f/cpp
*/

#include <iostream>
#include <vector>
using namespace std;

int square_sum(const vector<int>& numbers) {
    int result = 0;

    for (int i : numbers) {
        result += i*i;
    }
    return result;
}

int main() {
    vector<int> numbers = {1, 2, 2};
    cout << square_sum(numbers);
    return 0;
}