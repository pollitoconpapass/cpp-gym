/*
Write a function that takes an array of numbers (integers for the tests) and a target number. It should find two different items in the array that, when added together, give the target value. The indexes of these items should then be returned in a tuple / list (depending on your language) like so: (index1, index2).

For the purposes of this kata, some tests may have multiple answers; any valid solutions will be accepted.

The input will always be valid (numbers will be an array of length 2 or greater, and all of the items will be numbers; target will always be the sum of two different items from that array).

LINK: https://www.codewars.com/kata/52c31f8e6605bcc646000082
*/

#include <iostream>
#include <vector>
using namespace std;

pair<size_t,size_t> two_sum(const vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            // cout << numbers[i] << " + " << numbers[j] << " = " << target << "??" << endl;
            if (numbers[i] + numbers[j] == target) {
                return {i, j};
            }
        }
    }

    return {0, 0};
}

int main() {
    pair<size_t,size_t> res = two_sum({2, 2, 3}, 4);
    cout << res.first << ' ' << res.second << endl;

    return 0;
}