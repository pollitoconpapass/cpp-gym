/*
Given a string of words, you need to find the highest scoring word.
Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.

For example, the score of abad is 8 (1 + 2 + 1 + 4).

You need to return the highest scoring word as a string.
If two words score the same, return the word that appears earliest in the original string.

All letters will be lowercase and all inputs will be valid.

Examples:
"man i need a taxi up to ubud" -> "taxi"
"what time are we climbing up the volcano" -> "volcano"
"massage yes massage yes massage" -> "massage"

LINK: https://www.codewars.com/kata/57eb8fcdf670e99d9b000272/cpp
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> splitString(string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);

    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int findWordScore(string word) {
    int cont = 0;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (auto letter: word) {
        auto it = alphabet.find(letter);
        if (it != string::npos) {
            cont += (it+1);
        }
    }
    return cont;
}

string highestScoringWord(const string &str){
    string copy = str;
    vector<string> tokens = splitString(copy, ' ');

    unordered_map<string, int> words;

    for (string &t : tokens) {
        int score = findWordScore(t);
        words[t] = score;
    }

    auto maxIt = max_element(words.begin(), words.end(),
        [](const auto& p1, const auto &p2) {
        return p1.second <= p2.second;
    });

    return maxIt->first;
}

int main() {
    string sentence = "aa b";
    cout << highestScoringWord(sentence) << endl;
    return 0;
}