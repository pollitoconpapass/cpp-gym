#include <iostream>
#include <string>
using namespace std;

string repeat_str(size_t repeat, const string &str) {
    string result = "";

    for (int i = 0; i < repeat; i++) {
        result += str;
    }

    return result;
}

int main() {
    int repeat = 3;
    string input = "";
    cout << repeat_str(repeat, input) << endl;

    return 0;
}