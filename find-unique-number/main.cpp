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