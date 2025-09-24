/*
ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet.
ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13.
If there are numbers or special characters included in the string, they should be returned as they are.
Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".

LINK: https://www.codewars.com/kata/530e15517bc88ac656000716/cpp
*/

#include <iostream>
#include <string>
using namespace std;

string rot13(string msg) {
    string alphabetLower = "abcdefghijklmnopqrstuvwxyz";
    string alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res = "";

    for (char c : msg) {
        auto indexLower = alphabetLower.find(c);
        auto indexUpper = alphabetUpper.find(c);

        if (indexLower != string::npos) {
            res += alphabetLower[(indexLower + 13) % 26];
        }
        else if (indexUpper != string::npos) {
            res += alphabetUpper[(indexUpper + 13) % 26];
        }
        else {
            res += c;
        }
    }

    return res;
}

int main() {
    string input = "Test";
    cout << rot13(input) << endl;

    return 0;
}