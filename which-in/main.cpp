#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Method to use:
/*
 .find()
string sentence = "The quick brown fox jumps over the lazy dog.";
string wordToFind = "fox";

size_t foundFox = sentence.find(wordToFind);

 */

vector<string> inArray(vector<string> &array1, vector<string> &array2) {
    vector<string> result;

    for (int i = 0; i < array1.size(); i++) {
        for (int j = 1; j < array2.size(); j++) {
            string item2find = array1[i];
            string sentenceInArray2 = array2[j];

            size_t isIn = sentenceInArray2.find(item2find);

            if (isIn != string::npos) {
                auto it = find(result.begin(), result.end(), item2find);
                if (it == result.end()) {
                    result.push_back(item2find);
                }
                break;
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<string> array1 = {"arp", "live", "strong"};
    vector<string> array2 = {"lively", "alive", "harp", "sharp", "armstrong"};

    vector<string> solution = inArray(array1, array2);

    for (int i = 0; i < solution.size(); i++) {
        cout << solution[i] << " ";
    }

    return 0;
}