/*
We need to sum big numbers and we require your help.
Write a function that returns the sum of two numbers. The input numbers are strings and the function must return a string.

Example:
add("123", "321"); -> "444"
add("11", "99");   -> "110"

Notes:
- The input numbers are big.
- The input is a string of only digits
- The numbers are positives

LINK: https://www.codewars.com/kata/525f4206b73515bffb000b21/cpp
*/
#include <iostream>
#include <string>
using namespace std;

string add(const string& a, const string& b) {
    // typedef unsigned long long ull;
    // ull result = strtoll(a.c_str(), nullptr, 10) + strtoll(b.c_str(), nullptr, 10);
    // return to_string(result);
    string res = "";

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int digitA = (i >= 0) ? a[i] - '0' : 0;
        int digitB = (j >= 0) ? b[j] - '0' : 0;

        int sum = digitA + digitB + carry;
        carry = sum / 10;
        res.push_back((sum % 10) + '0');

        i--;
        j--;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a = "9999";
    string b = "1111";
    cout << add(a, b) << endl;

    return 0;
}