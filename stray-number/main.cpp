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