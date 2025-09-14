/*
Task
In this simple Kata your task is to create a function that turns a string into a Mexican Wave. You will be passed a string and you must return an array of strings where an uppercase letter is a person standing up.

Rules
1.  The input string will always consist of lowercase letters and spaces, but may be empty, in which case you must return an empty array. 2.  If the character in the string is whitespace then pass over it as if it was an empty seat

Examples
"hello" => ["Hello", "hEllo", "heLlo", "helLo", "hellO"]
" s p a c e s " => [ " S p a c e s ", " s P a c e s ", " s p A c e s ", " s p a C e s ", " s p a c E s ", " s p a c e S "]


LINK: https://www.codewars.com/kata/58f5c63f1e26ecda7e000029
*/

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