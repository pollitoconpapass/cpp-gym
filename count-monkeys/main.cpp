/*
Task: Given a number, return a vector with all the numbers from 1 to n
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> MonkeyCount(int n) {
    vector<int> monkeys;
    for (int i = 1; i <= n; i++) {
        monkeys.push_back(i);
    }

    return monkeys;
}

int main() {
    int n = 10;
    vector<int> monkeys = MonkeyCount(n);
    for (int i = 0; i < n; i++) {
        cout << monkeys[i] << endl;
    }
    return 0;
}