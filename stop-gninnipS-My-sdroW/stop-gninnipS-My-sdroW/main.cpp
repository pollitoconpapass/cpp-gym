/*
 Write a function that takes in a string of one or more words, and returns the same string, but with all words that have five or more letters reversed (just like the name of this kata). Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.
 
 Examples:
 "Hey fellow warriors"  --> "Hey wollef sroirraw"
 "This is a test        --> "This is a test"
 "This is another test" --> "This is rehtona test"
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> splitString(string word, char del){
    vector<string> tokens;
    string token;
    stringstream ss(word);
    
    while(getline(ss, token, del)){
        tokens.push_back(token);
    }
    return tokens;
}

string spinWords(const string &str){
    vector<string> words = splitString(str, ' ');
    string result = "";
    
    int i = 0;
    for(string word: words){
        if(word.size() >=5){
            reverse(word.begin(), word.end());
        }
        i++;
        result += word;
        
        if (i != int(words.size())){
            result += " ";
        }
    }
        
    return result;
}

int main() {
    string input = "Pizza is the best vegetable";
    string output = spinWords(input);
    cout << output << endl;
    return 0;
}
