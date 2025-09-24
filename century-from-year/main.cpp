/*
The first century spans from the year 1 up to and including the year 100, the second century
- from the year 101 up to and including the year 200, etc.

Task
Given a year, return the century it is in.

Examples:
1705 --> 18
1900 --> 19
1601 --> 17
2000 --> 20
2742 --> 28

LINK: https://www.codewars.com/kata/5a3fe3dde1ce0e8ed6000097/cpp
*/

#include <iostream>
using namespace std;

int centuryFromYear(int year) {
    if (year % 100 == 0)
        return year / 100;

    return (year / 100) + 1;
}

int main() {
    int year = 1601;
    cout << centuryFromYear(year) << endl;
    return 0;
}