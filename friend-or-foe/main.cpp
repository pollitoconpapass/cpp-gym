#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> friendOrFoe(const vector<string>&input) {
    vector<string> output;

    for (const string& input : input) {
        if (input.size() == 4) {
            output.push_back(input.substr(0, 4));
        }
    }

    return output;
}

int main() {
    vector<string> input = {"Peter", "Stephen", "Joe"};

    vector<string> output = friendOrFoe(input);
    for (const string& input : output) {
        cout << input << endl;
    }
    return 0;
}