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