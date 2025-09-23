/*
Write a function that accepts a non-negative integer n and a string s as parameters, and returns a string of s repeated exactly n times.

Examples (input -> output)
6, "I"     -> "IIIIII"
5, "Hello" -> "HelloHelloHelloHelloHello"

LINK: https://www.codewars.com/kata/57a0e5c372292dd76d000d7e/cpp
*/

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