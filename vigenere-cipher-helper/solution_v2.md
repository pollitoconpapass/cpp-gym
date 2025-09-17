## DISCLAIMER ‼️
To solve this challenge I had to use a little help from AI...
Most of all for the complexity thing and the unicode tests (for the different alphabets and special characters)

The code I used to pass all the test is this one:

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class VigenèreCipher {
public:
    string key;
    string alphabet;

    // Extract individual characters from UTF-8 string
    vector<string> extractChars(const string& str) {
        vector<string> chars;
        for (size_t i = 0; i < str.length(); ) {
            size_t charLen = 1;
            // Check if it's a multi-byte UTF-8 character
            unsigned char byte = str[i];
            if ((byte & 0x80) != 0) { // Non-ASCII character
                if ((byte & 0xE0) == 0xC0) charLen = 2;      // 110xxxxx
                else if ((byte & 0xF0) == 0xE0) charLen = 3; // 1110xxxx  
                else if ((byte & 0xF8) == 0xF0) charLen = 4; // 11110xxx
            }
            
            if (i + charLen <= str.length()) {
                chars.push_back(str.substr(i, charLen));
                i += charLen;
            } else {
                chars.push_back(str.substr(i, 1)); // Fallback
                i++;
            }
        }
        return chars;
    }

    // Find the index of a character in the alphabet
    int findIndexNumber(const string& c, const vector<string>& alphabetChars) {
        for (size_t i = 0; i < alphabetChars.size(); i++) {
            if (alphabetChars[i] == c) {
                return static_cast<int>(i);
            }
        }
        return -1; // Return -1 if not found
    }

    string encode(const string& str) {
        // Extract characters from current alphabet and key
        vector<string> alphabetChars = extractChars(alphabet);
        vector<string> keyChars = extractChars(key);
        vector<string> inputChars = extractChars(str);
        
        string result;
        
        int keyLen = keyChars.size();
        int alphabetLen = alphabetChars.size();
        
        // Handle empty key or alphabet
        if (keyLen == 0 || alphabetLen == 0) {
            return str; // Return original string if key or alphabet is empty
        }
        
        for (int i = 0; i < static_cast<int>(inputChars.size()); i++) {
            string currentChar = inputChars[i];
            int charIndex = findIndexNumber(currentChar, alphabetChars);
            
            if (charIndex != -1) { // Character is in alphabet
                // Get the corresponding key character (repeating key)
                string keyChar = keyChars[i % keyLen];
                int keyIndex = findIndexNumber(keyChar, alphabetChars);
                
                if (keyIndex != -1) { // Key character is valid
                    // Apply Caesar shift with modular arithmetic
                    int shiftedIndex = (charIndex + keyIndex) % alphabetLen;
                    result += alphabetChars[shiftedIndex];
                } else {
                    // Key character not in alphabet, keep original character
                    result += currentChar;
                }
            } else {
                // Character not in alphabet, keep as is
                result += currentChar;
            }
        }
        
        return result;
    }

    string decode(const string& str) {
        // Extract characters from current alphabet and key
        vector<string> alphabetChars = extractChars(alphabet);
        vector<string> keyChars = extractChars(key);
        vector<string> inputChars = extractChars(str);
        
        string result;
        
        int keyLen = keyChars.size();
        int alphabetLen = alphabetChars.size();
        
        // Handle empty key or alphabet
        if (keyLen == 0 || alphabetLen == 0) {
            return str; // Return original string if key or alphabet is empty
        }
        
        for (int i = 0; i < static_cast<int>(inputChars.size()); i++) {
            string currentChar = inputChars[i];
            int charIndex = findIndexNumber(currentChar, alphabetChars);
            
            if (charIndex != -1) { // Character is in alphabet
                // Get the corresponding key character (repeating key)
                string keyChar = keyChars[i % keyLen];
                int keyIndex = findIndexNumber(keyChar, alphabetChars);
                
                if (keyIndex != -1) { // Key character is valid
                    // Reverse Caesar shift with modular arithmetic
                    int shiftedIndex = (charIndex - keyIndex + alphabetLen) % alphabetLen;
                    result += alphabetChars[shiftedIndex];
                } else {
                    // Key character not in alphabet, keep original character
                    result += currentChar;
                }
            } else {
                // Character not in alphabet, keep as is
                result += currentChar;
            }
        }
        
        return result;
    }
};
```