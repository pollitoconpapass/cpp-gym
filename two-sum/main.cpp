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