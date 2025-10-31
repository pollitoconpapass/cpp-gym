/*
 Write a function that accepts a string, and returns the same string with all even indexed characters in each word upper cased, and all odd indexed characters in each word lower cased. The indexing just explained is zero based, so the zero-ith index is even, therefore that character should be upper cased and you need to start over for each word.

 The passed in string will only consist of alphabetical characters and spaces(' '). Spaces will only be present if there are multiple words. Words will be separated by a single space(' ').

 Examples:
 "String" => "StRiNg"
 "Weird string case" => "WeIrD StRiNg CaSe"
 
 LINK: https://www.codewars.com/kata/52b757663a95b11b3d00062d/cpp
 */

#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

string to_weird_case(string_view str){
    string result = "";
    
    for(int i=0; i< str.size(); i++){
        char charac = str[i];
        if(i==0){
            charac = toupper(str[i]);
        } else {
            if (isupper(result[i-1])){
                charac = tolower(str[i]);
            } else {
                charac = toupper(str[i]);
            }
        }
        
        result += charac;
    }
    return result;
}

int main() {
    string input = "This is a test";
    string output = to_weird_case(input);
    cout << output << endl;
    
    return 0;
}
