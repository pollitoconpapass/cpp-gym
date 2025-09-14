/*
Introduction
Mr. Safety loves numeric locks and his Nokia 3310. He locked almost everything in his house.
He is so smart and he doesn't need to remember the combinations.
He has an algorithm to generate new passcodes on his Nokia cell phone.

Task
Can you crack his numeric locks? Mr. Safety's treasures wait for you. Write an algorithm to open his numeric locks. Can you do it without his Nokia 3310?

Input
The str or message (Python) input string consists of lowercase and upercase characters. It's a real object that you want to unlock.

Output
Return a string that only consists of digits.
Example
``` unlock("Nokia") // => 66542 unlock("Valut") // => 82588 unlock("toilet") // => 864538 ```

LINK: https://www.codewars.com/kata/592c1dfb912f22055b000099/cpp
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, string> dicc = {
    // Key 2
    {'a', "2"},
    {'b', "2"},
    {'c', "2"},
    // Key 3
    {'d', "3"},
    {'e', "3"},
    {'f', "3"},
    // Key 4
    {'g', "4"},
    {'h', "4"},
    {'i', "4"},
    // Key 5
    {'j', "5"},
    {'k', "5"},
    {'l', "5"},
    // Key 6
    {'m', "6"},
    {'n', "6"},
    {'o', "6"},
    // Key 7
    {'p', "7"},
    {'q', "7"},
    {'r', "7"},
    {'s', "7"},
    // Key 8
    {'t', "8"},
    {'u', "8"},
    {'v', "8"},
    // Key 9
    {'w', "9"},
    {'x', "9"},
    {'y', "9"},
    {'z', "9"}
};

string unlock(string str) {
    string result = "";
    vector<char> letters(str.begin(), str.end());


    for (int i = 0; i < int(letters.size()); i++) {
        char letter = tolower(letters[i]);
        result += dicc[letter];
    }
    return result;
}

string unlock_v2 (string str)
{
    string key = "abcdefghijklmnopqrstuvwxyz22233344455566677778889999";
    for(auto& i: str)
        i =key[key.find(tolower(i)) +26];
    return str;
}

int main() {
    string input = "Nokia";
    cout << unlock(input) << endl;

    return 0;
}