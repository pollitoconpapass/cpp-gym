/*
The maximum sum subarray problem consists in finding the
maximum sum of a contiguous subsequence in an array or list of integers:
maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4});
//should be 6: {4, -1, 2, 1}

Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array.
If the list is made up of only negative numbers, return 0 instead.

Empty list is considered to have zero greatest sum. Note that the empty list or array is also a valid sublist/subarray.

LINK: https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c/cpp
*/

#include <iostream>
#include <vector>
using namespace std;

int maxSequence(const vector<int>& arr) {
    int maxSoFar = 0;   // maximum sum found so far
    int currentSum = 0; // current subarray sum

    for (int num : arr) {
        currentSum = max(0, currentSum + num);
        maxSoFar = max(maxSoFar, currentSum);
    }

    return maxSoFar;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSequence(arr) << endl;
    return 0;
}