/*
Your job is to write a function which increments a string, to create a new string.

If the string already ends with a number, the number should be incremented by 1.
If the string does not end with a number. the number 1 should be appended to the new string.
Examples:

foo -> foo1

foobar23 -> foobar24

foo0042 -> foo0043

foo9 -> foo10

foo099 -> foo100

Attention: If the number has leading zeros the amount of digits should be considered.

LINK: https://www.codewars.com/kata/54a91a4883a7de5d7800009c/cpp
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

bool isNumber(string str) {
    string numbers = "0123456789";

    if (numbers.find(str) != string::npos) {
        return true;
    } else {
        return false;
    }
}

string incrementByOneString(string str) {
    long double num = stold(str);
    num++;

    long double width = str.size();

    ostringstream oss;

    oss << setw(width) << setfill('0') << num;
    return oss.str();
}

string convertBigNumber(string num) { // -> it was most of all to handle the test case of the number: 18446744073709551615
    long double newNum = stold(num);
    newNum++;
    long double truncatedNum = truncl(newNum);
    return to_string(truncatedNum);
}

string incrementString(const string &str) {
    string newStr = str;
    if (newStr.length() == 0) return "1";

    if (str.size() >= 19) {
        cout << "The size is too big..." << endl;
        return convertBigNumber(newStr);
    }

    // Extract the last item of the string
    string lastItem = newStr.substr(newStr.length() - 1, 1);

    // If it's a number, then keep searching until it's not.
    if (isNumber(lastItem)) {
        cout << "Its a number..." << endl;
        int cont = 1;
        string numberNumber = "";

        do {
            lastItem = newStr.substr(newStr.length() - cont, 1);
            cout << "lastItem: " << lastItem << endl;

            if (!isNumber(lastItem)) {
                cout << "Is not a number" << endl;
                break;
            }

            numberNumber += lastItem;
            cout << "Number Number: " << numberNumber << endl;
            cont++;
        } while (isNumber(lastItem) != false);

        reverse(numberNumber.begin(), numberNumber.end());
        cout << "Numero pa convertir: " << numberNumber << endl;

        // Algun proceso pa guardar los ceros...
        string newNum = incrementByOneString(numberNumber);
        newStr = newStr.replace((str.length() - cont) + 1, cont, newNum);
    } else {
        // If its a string then just add a 1 to the end
        cout << "It's not a number" << endl;
        newStr += "1";
    }

    return newStr;
}

int main() {
    string input = "foo1";
    cout << incrementString(input) << endl;

    return 0;
}