/*
Complete the method/function so that it converts dash/underscore delimited words into camel casing. The first word within the output should be capitalized only if the original word was capitalized (known as Upper Camel Case, also often referred to as Pascal case). The next words should be always capitalized.

Examples
"the-stealth-warrior" gets converted to "theStealthWarrior"
"The_Stealth_Warrior" gets converted to "TheStealthWarrior"
"The_Stealth-Warrior" gets converted to "TheStealthWarrior"

LINK: https://www.codewars.com/kata/517abf86da9663f1d2000003/cpp
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> splitStringByNonAlpha(const string& input) {
    std::vector<string> tokens;
    string currentToken;

    for (char c : input) {
        if (isalpha(c)) { // Check if the character is alphabetical
            currentToken += c;
        } else {
            if (!currentToken.empty()) { // If currentToken is not empty, add it to tokens
                tokens.push_back(currentToken);
                currentToken.clear(); // Clear currentToken for the next word
            }
        }
    }

    // Add the last token if the string doesn't end with a non-alphabetical character
    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }

    return tokens;
}

string to_camel_case(string text) {
    string camel = "";
    vector<string> tokens = splitStringByNonAlpha(text);

    for (int i = 0; i < int(tokens.size()); i++) {
        if (i == 0) {
            camel += tokens[i];
        } else {
            // Make the first capital one
            char firstLetter = tokens[i][0];
            firstLetter = toupper(firstLetter);

            // Replace it in the tokens[i] word
            // tokens[i].replace(0, 1, to_string(firstLetter));
            tokens[i].erase(0, 1);
            tokens[i].insert(0, 1, firstLetter);

            // Add to camel result
            camel += tokens[i];
        }
    }
    return camel;
}

int main() {
    string input = "the_cat-is_cute";
    cout << to_camel_case(input)<< endl;

    return 0;
}