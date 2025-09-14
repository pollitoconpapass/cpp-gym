/*
Complete the function that accepts a string parameter, and reverses each word in the string. All spaces in the string should be retained.

Examples
"This is an example!" ==> "sihT si na !elpmaxe"
"double  spaces"      ==> "elbuod  secaps"

LINK: https://www.codewars.com/kata/5259b20d6021e9e14c0010d4
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string reverseWords(const string &s) {
    vector<string> words;
    stringstream ss(s);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    // Build result string with words in reverse order
    string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i > 0) {
            result += " ";  // Add space between words (except after last word)
        }
    }

    return result;
}

string reverseWordsCompletely(const string &s) {
    int n = s.length();
    string res = "";

    for (int i=n-1; i>=0; --i) {
        res += s[i];
    }

    return res;
}

int main() {
    string s = reverseWords("hello world!");
    cout << s << endl;

    return 0;
}