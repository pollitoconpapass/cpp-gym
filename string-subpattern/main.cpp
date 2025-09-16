/*
You need to operate with shuffled strings to identify if they are composed repeating a subpattern

Since there is no deterministic way to tell which pattern was really the original one among all the possible permutations of a fitting subpattern, return a subpattern with sorted characters, otherwise return the base string with sorted characters (you might consider this case as an edge case, with the subpattern being repeated only once and thus equalling the original input string).

For example:

"a" ==> "a"; // no repeated pattern, just one character
"aaaa" ==> "a"; // just one character repeated
"abcd" ==> "abcd"; // base pattern equals the string itself, no repetitions
"babababababababa" ==> "ab"; // remember to return the base string sorted
"bbabbaaabbaaaabb" ==> "ab"; // same as above, just shuffled

LINK: https://www.codewars.com/kata/5a4a2973d8e14586c700000a/train/cpp
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string hasSubpattern(const string& str) {
    unordered_map<char, bool>seen_before;
    string result = "";

    for (char c: str) {
        if (seen_before.find(c) == seen_before.end()) {
            result += c;
            seen_before[c] = true;
        }
    }

    sort(result.begin(), result.end());
    return result;
}

int gcd_func(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

string hasSubpattern2(const string& str) {
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char c : str) {
        freq[c]++;
    }

    // Find GCD of all frequencies to determine how many times the pattern repeats
    int gcd_freq = 0;
    for (auto& p : freq) {
        gcd_freq = gcd_func(gcd_freq, p.second);
    }

    string result = "";
    vector<pair<char, int>> char_counts;

    for (auto& p : freq) {
        int count_in_pattern = p.second / gcd_freq;
        char_counts.push_back({p.first, count_in_pattern});
    }

    sort(char_counts.begin(), char_counts.end());

    for (auto& p : char_counts) {
        for (int i = 0; i < p.second; i++) {
            result += p.first;
        }
    }

    return result;
}

int main() {
    string str = "aaaa";
    cout << hasSubpattern2(str) << endl;
    return 0;
}