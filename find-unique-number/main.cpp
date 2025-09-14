/*
There is an array with some numbers. All numbers are equal except for one. Try to find it!

find_uniq(std::vector<float>{1, 1, 1, 2, 1, 1});  // --> 2
find_uniq(std::vector<float>{0, 0, 0.55, 0, 0});  // --> 0.55
It’s guaranteed that array contains at least 3 numbers.

The tests contain some very huge arrays, so think about performance.

LINK: https://www.codewars.com/kata/585d7d5adb20cf33cb000235/cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

float find_uniq(const std::vector<float> &v) {
    vector<float> sorted_v(v);
    sort(sorted_v.begin(), sorted_v.end());

    if (sorted_v[0] == sorted_v[1]) {
        return sorted_v[sorted_v.size() - 1];
    } else {
        return sorted_v[0];
    }
}

float find_uniq_hashmap(const std::vector<float> &v) {
    unordered_map<float, int> count;

    for (float f: v) {
        count[f] ++;
    }

    for (const auto &pair : count) {
        if (pair.second == 1) {
            return pair.first;
        }
    }

    return -1;
}

int main() {
    vector<float> v = { 0, 0, 0.55, 0, 0 };
    cout << find_uniq_hashmap(v) << endl;

    return 0;
}