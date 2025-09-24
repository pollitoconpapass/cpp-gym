/*
Given a string, you have to return a string in which each character (case-sensitive) is repeated once.

Examples (Input -> Output):
"String"      -> "SSttrriinngg"
"Hello World" -> "HHeelllloo  WWoorrlldd"
"1234!_ "     -> "11223344!!__  "
*/
#include <iostream>
using namespace std;

string double_char(const string& str){
    string aux = "";
    string res = "";
    for (char c : str) {
        aux = c;
        aux += c;
        res += aux;
    }
    return res;
}

string double_char_sol2(const string& str) {
    string s;
    for ( const char c : str ) s.append( 2, c );
    return s;
}

int main() {
    string input = "String";
    cout << double_char(input) << endl;
    return 0;
}