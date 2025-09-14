/*
In this kata you have to write a simple Morse code decoder. While the Morse code is now mostly superseded by voice and digital data communication channels, it still has its use in some applications around the world.
The Morse code encodes every character as a sequence of "dots" and "dashes". For example, the letter A is coded as ·−, letter Q is coded as −−·−, and digit 1 is coded as ·−−−−. The Morse code is case-insensitive, traditionally capital letters are used. When the message is written in Morse code, a single space is used to separate the character codes and 3 spaces are used to separate words. For example, the message HEY JUDE in Morse code is ···· · −·−−   ·−−− ··− −·· ·.

NOTE: Extra spaces before or after the code have no meaning and should be ignored.

In addition to letters, digits and some punctuation, there are some special service codes, the most notorious of those is the international distress signal SOS (that was first issued by Titanic), that is coded as ···−−−···. These special codes are treated as single special characters, and usually are transmitted as separate words.

Your task is to implement a function that would take the morse code as input and return a decoded human-readable string.

For example:

decode_morse('.... . -.--   .--- ..- -.. .')
#should return "HEY JUDE"

NOTE: For coding purposes you have to use ASCII characters . and -, not Unicode characters.

LINK: https://www.codewars.com/kata/54b724efac3d5402db00065e/cpp
*/


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> MORSE_CODE{
    // Letters
    {".-", "A"},
    {"-...", "B"},
    {"-.-.", "C"},
    {"-..", "D"},
    {".", "E"},
    {"..-.", "F"},
    {"--.", "G"},
    {"....", "H"},
    {"..", "I"},
    {".---", "J"},
    {"-.-", "K"},
    {".-..", "L"},
    {"--", "M"},
    {"-.", "N"},
    {"---", "O"},
    {".--.", "P"},
    {"--.-", "Q"},
    {".-.", "R"},
    {"...", "S"},
    {"-", "T"},
    {"..-", "U"},
    {"...-", "V"},
    {".--", "W"},
    {"-..-", "X"},
    {"-.--", "Y"},
    {"--..", "Z"},

    // Digits
    {".----", "1"},
    {"..---", "2"},
    {"...--", "3"},
    {"....-", "4"},
    {".....", "5"},
    {"-....", "6"},
    {"--...", "7"},
    {"---..", "8"},
    {"----.", "9"},
    {"-----", "0"},
};

string decodeMorse(const string& morseCode) {
    string trimmed = morseCode;
    size_t start = trimmed.find_first_not_of(' ');

    if (start == string::npos) return "";
    size_t end = trimmed.find_last_not_of(' ');
    trimmed = trimmed.substr(start, end - start + 1);

    string result = "";
    string currentCode = "";
    int spaceCount = 0;

    for (size_t i = 0; i < trimmed.length(); i++) {
        if (trimmed[i] == ' ') {
            if (!currentCode.empty()) {
                if (MORSE_CODE.find(currentCode) != MORSE_CODE.end()) {
                    result += MORSE_CODE[currentCode];
                }
                currentCode.clear();
            }

            spaceCount = 1;
            while (i + 1 < trimmed.length() && trimmed[i + 1] == ' ') {
                spaceCount++;
                i++;
            }

            if (spaceCount >= 3) {
                result += " ";
            }
        } else {
            currentCode += trimmed[i];
        }
    }

    if (!currentCode.empty()) {
        if (MORSE_CODE.find(currentCode) != MORSE_CODE.end()) {
            result += MORSE_CODE[currentCode];
        }
    }

    return result;
}

int main() {
    string input = ".... . -.--   .--- ..- -.. .";
    string decodedInput = decodeMorse(input);
    cout << decodedInput << endl;

    return 0;
}