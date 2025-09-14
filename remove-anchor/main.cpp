/*
Complete the function/method so that it returns the url with anything after the anchor (#) removed.

Examples
"www.codewars.com#about" --> "www.codewars.com"
"www.codewars.com?page=1" -->"www.codewars.com?page=1"

LINK: https://www.codewars.com/kata/51f2b4448cadf20ed0000386/cpp
*/

#include <iostream>
#include <string>
using namespace std;

string replaceAll(string str) {
    char toRemove = '#';
    size_t index = str.find(toRemove);

    if (index != string::npos) {
        str.erase(index);
    }

    return str;
}

int main() {
    string input = "www.codewars.com#about";
    cout << replaceAll(input) << endl;
    return 0;
}