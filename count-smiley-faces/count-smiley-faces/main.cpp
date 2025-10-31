/*
 Given an array (arr) as an argument complete the function countSmileys that should return the total number of smiling faces.
 
Rules for a smiling face:
    1. Each smiley face must contain a valid pair of eyes. Eyes can be marked as : or ;
    2. A smiley face can have a nose but it does not have to. Valid characters for a nose are - or ~
    3. Every smiling face must have a smiling mouth that should be marked with either ) or D
 
 No additional characters are allowed except for those mentioned.
 
 Valid smiley face examples: :) :D ;-D :~)
 Invalid smiley faces: ;( :> :} :]
 
 Example:
 countSmileys([':)', ';(', ';}', ':-D']);       // should return 2;
 countSmileys([';D', ':-(', ':-)', ';~)']);     // should return 3;
 countSmileys([';]', ':[', ';*', ':$', ';-D']); // should return 1;
 
 Note:
 In case of an empty array return 0. You will not be tested with invalid input (input will always be an array). Order of the face (eyes, nose, mouth) elements will always be the same.
 
 LINK: https://www.codewars.com/kata/583203e6eb35d7980400002a/cpp
 */

#include <iostream>
#include <vector>
#include <regex>
using namespace std;

int countSmileys(vector<string> arr){
    if (arr.size() == 0) return 0;
    int count = 0;
    string validEyes = ":;";
    string validNoses = "-~";
    string validSmiles = ")D";
    
    for (auto face : arr){
        if (face.size() == 2) {
            cout << "=== FACE " << face  <<  " ==="<< endl;
            cout << "Ojos: " << face[0] << endl;
            auto areEyesValid = validEyes.find(face[0]) != string::npos;
            
            cout << "Sonrisa: " << face[1]<< endl;
            auto isSmileValid = validSmiles.find(face[1]) != string::npos;
            
            if (areEyesValid == 1 && isSmileValid == 1){
                cout << "Is Valid!" << endl;
                count++;
            }

            cout << endl;
        }
        
        if (face.size() == 3) {
            cout << "=== FACE " << face  <<  " ==="<< endl;
            
            cout << "Ojos: " << face[0] << endl;
            auto areEyesValid = validEyes.find(face[0]) != string::npos;
            
            cout << "Nariz: " << face[1] << endl;
            auto isNoseValid = validNoses.find(face[1]) != string::npos;
            
            cout << "Sonrisa: " << face[2]<< endl;
            auto isSmileValid = validSmiles.find(face[2]) != string::npos;
            
            if (areEyesValid == 1 && isNoseValid == 1 && isSmileValid == 1){
                cout << "Is Valid!" << endl;
                count++;
            }
            cout << endl;
        }
        
    }
    
    return count;
}

int countSmileysV2(std::vector<std::string> arr){
    int count = 0;
    regex smiles_regex("[:|;](-|~)?[)|D]");
    
    for (auto &smile: arr){
        if (regex_match(smile, smiles_regex))
            count++;
    }
    return count;
}

int main() {
    int sol = countSmileys({":>", ";>", ":(", ":~)", ";~D", ":)"});
    cout << sol << endl;
        
    return 0;
}
