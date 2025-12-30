/*
Given two strings, one is a text string txt and the other is a pattern string pat. 
The task is to return the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices.
Note: Return an empty list in case of no occurrences of pattern.

Examples:
Input: txt = "geeksforgeeks", pat = "geek"
Output: [0, 8]
Explanation: The pattern "geek" occurs at: Index 0 (characters 0–3) and Index 8 (characters 8–11)

Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.

Constraints:
1 <= |txt|, |pat| <= 10^5
1 ≤ pat.size() ≤ txt.size()
Both the strings consist of lowercase English alphabets.

LINK: https://www.geeksforgeeks.org/problems/search-pattern-z-algorithm--141631/1
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> search(string pat, string txt) {
        string concat = pat + "$" + txt;
        int n = concat.length();
        vector<int> Z(n);

        int L = 0, R = 0;
        for (int i = 1; i < n; ++i) {
            if (i > R) {
                L = R = i;
                while (R < n && concat[R - L] == concat[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
            else {
                int k = i - L;
                if (Z[k] < R - i + 1)
                    Z[i] = Z[k];
                else {
                    L = i;
                    while (R < n && concat[R - L] == concat[R])
                        R++;
                    Z[i] = R - L;
                    R--;
                }
            }
        }
        vector<int> result;
        int patLen = pat.length();
        for (int i = 0; i < n; ++i) {
            if (Z[i] == patLen) {
                result.push_back(i - patLen - 1 + 1);
            }
        }

        return result;
    }
};

int main() {
    string txt, pat;

    cout << "Ingrese el texto (S): ";
    getline(cin, txt);

    cout << "Ingrese el patrón (pat): ";
    getline(cin, pat);

    Solution sol;
    vector<int> result = sol.search(pat, txt);

    if (result.empty()) {
        cout << "-1\n";
    }
    else {
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
