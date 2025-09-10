#include <iostream>
#include <vector>
using namespace std;

bool isOpposite(string a, string b) {
    return (a == "NORTH" && b == "SOUTH") ||
           (a == "SOUTH" && b == "NORTH") ||
           (a == "EAST" && b == "WEST")  ||
           (a == "WEST" && b == "EAST");
}

vector<string> dirReduc(vector<string>&arr) {
    vector<string> res;

    for (const string& dir : arr) {
        if (!res.empty() && isOpposite(res.back(), dir)) {
            res.pop_back();
        } else {
            res.push_back(dir);
        }
    }
    return res;
}

int main() {
    vector<string> arr= {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH"};
    vector<string> dir = dirReduc(arr);
    for (int i = 0; i < dir.size(); i++) {
        cout << dir[i] << endl;
    }

    return 0;
}