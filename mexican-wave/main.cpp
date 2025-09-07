#include <iostream>
#include <vector>
using namespace std;

string makeUpperCaseAt(string str, size_t index) {
    if (index >= str.length()) {
        cerr << "Index " << index << " out of bounds!" << endl;
        return str;
    }

    char& c = str[index];
    if (islower(c)) {
        c = toupper(c);
    }

    return str;
}

vector<string> wave(string y) {
    vector<string> res;

    if (y.empty()) {
        return res;
    }

    int n = y.length();

    for (int i = 0; i < n; i++) {
        if (!isspace(y[i])) {
            string x = makeUpperCaseAt(y, i);
            res.push_back(x);
        }
    }

    return res;
}

int main() {
    string word = "hello world";
    vector<string> res = wave(word);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}