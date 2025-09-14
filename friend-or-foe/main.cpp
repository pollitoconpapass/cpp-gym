/*
Make a program that filters a list of strings and returns a list with only your friends name in it.

If a name has exactly 4 letters in it, you can be sure that it has to be a friend of yours! Otherwise, you can be sure he's not...

Input = ["Ryan", "Kieran", "Jason", "Yous"]
Output = ["Ryan", "Yous"]

Input = ["Peter", "Stephen", "Joe"]
Output = []
Input strings will only contain letters.
Note: keep the original order of the names in the output.

LINK: https://www.codewars.com/kata/55b42574ff091733d900002f
*/

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