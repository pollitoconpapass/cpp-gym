/*
The Vigenère cipher is a classic cipher originally developed by Italian cryptographer Giovan Battista Bellaso and published in 1553.
It is named after a later French cryptographer Blaise de Vigenère, who had developed a stronger autokey cipher (a cipher that incorporates the message of the text into the key).
The cipher is easy to understand and implement, but survived three centuries of attempts to break it, earning it the nickname "le chiffre indéchiffrable" ("the unbreakable cipher")

Assume the key is repeated for the length of the text, character by character.
Note that some implementations repeat the key over characters only if they are part of the alphabet -- this is not the case here.

The shift is derived by applying a Caesar shift to a character with the corresponding index of the key in the alphabet.

Visual representation:
"my secret code i want to secure"  // message
"passwordpasswordpasswordpasswor"  // key

Write a class that, when given a key and an alphabet, can be used to encode and decode from the cipher.

Examples
alphabet = "abcdefghijklmnopqrstuvwxyz"
key      = "password"

"codewars" --> encode -->  "rovwsoiv"
"laxxhsj"  --> decode -->  "waffles"

Note: any character not in the alphabet must be left alone. For example in the above case:
"CODEWARS"  --> encode -->  "CODEWARS"

LINK: https://www.codewars.com/kata/52d1bd3694d26f8d6e0000d3/cpp
 */

#include <iostream>
#include <vector>
using namespace std;

class VigenereCipher {
public:
    string key;
    string alphabet;

    int findIndexNumber(char c) {
        auto found = alphabet.find(c);
        if (found != string::npos) {
            return found;
        }
        return 0;
    }

    string encode(string str) {
        vector<int> indexes;
        string result;

        if (str.length() > key.length()) {
            int diff = str.length() - key.length();
            for (int i = 0; i < diff; i++) {
                key += key;
            }
        }

        for (auto c: key) {
            int index = findIndexNumber(c);
            indexes.push_back(index);
        }

        for (int i=0; i < str.length(); i++) {
            if (alphabet.find(str[i]) != string::npos) {
                cout << "Character of the string: " << str[i] << " " << endl;
                cout << "Indexes to sum: " << indexes[i] << endl;
                cout << "New word is: " <<  alphabet[alphabet.find(str[i]) + indexes[i]] << endl;
                cout << "---------" << endl;

                if (indexes[i] >= 10) {
                    alphabet += alphabet;
                }
                result += alphabet[alphabet.find(str[i]) + indexes[i]];
            } else {
                result += str[i];
            }
        }

        return result;
    }

    string decode(string str) {
        vector<int> indexes;
        string result;

        if (str.length() > key.length()) {
            int diff = str.length() - key.length();
            for (int i = 0; i < diff; i++) {
                key += key;
            }
        }

        for (auto c: key) {
            int index = findIndexNumber(c);
            indexes.push_back(index);
        }

        for (int i=0; i < str.length(); i++) {
            if (alphabet.find(str[i]) != string::npos) {
                cout << "Character of the string: " << str[i] << " " << endl;
                cout << "Indexes to take away: " << indexes[i] << endl;
                cout << "New word is: " <<  alphabet[alphabet.find(str[i]) + (26 - indexes[i])] << endl;

                result += alphabet[alphabet.find(str[i]) + (26 - indexes[i])];
            } else {
                result += str[i];
            }
        }

        return result;
    }
};

int main() {
    string key = "password";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    auto vc = new VigenereCipher(key, alphabet);

    cout << "============== Encoding ==============" << endl;
    string encoded = vc->encode("data science");
    cout << encoded << endl;

    cout << "======================================" << endl;

    cout << "============== Decoding ==============" << endl;
    string decoded = vc->decode(encoded); // -> decode the encripted result (should be the original word)
    cout << decoded << endl;

    return 0;
}