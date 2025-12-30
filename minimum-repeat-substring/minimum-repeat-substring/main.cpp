/*
Given two strings s1 and s2. Return a minimum number of times s1 has to be repeated such that s2 is a substring of it. If s2 can never be a substring then return -1.

Note: Both the strings contain only lowercase letters.

Examples:
Input: s1 = "ww", s2 = "www"
Output: 2
Explanation: Repeating s1 two times "wwww", s2 is a substring of it.

Input: s1 = "abac", s2 = "cabaca" 
Output: 3 
Explanation: Repeating s1 three times "abacabacabac", s2 is a substring of it. s2 is not a substring of s1 when it is repeated less than 3 times.

Input: s1 = "ab", s2 = "cab"
Output: -1
Explanation: No matter how many times we repeat s1, we can't get a string such that s2 is a substring of it.

LINK: https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1?page=1&category=Pattern%20Searching&difficulty=Medium,Hard&sortBy=submissions
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> computeZ(string str) {
        int n = str.length();
        vector<int> Z(n);
        int L = 0, R = 0;

        for (int i = 1; i < n; ++i) {
            if (i > R) {
                L = R = i;
                while (R < n && str[R - L] == str[R]) R++;
                Z[i] = R - L;
                R--;
            }
            else {
                int k = i - L;
                if (Z[k] < R - i + 1)
                    Z[i] = Z[k];
                else {
                    L = i;
                    while (R < n && str[R - L] == str[R]) R++;
                    Z[i] = R - L;
                    R--;
                }
            }
        }
        return Z;
    }

    int minRepeats(string s1, string s2) {
        string repeated = "";
        int count = 0;

        while (repeated.length() < s2.length()) {
            repeated += s1;
            count++;
        }

        repeated += s1;
        count++;

        string concat = s2 + "$" + repeated;
        vector<int> Z = computeZ(concat);
        int s2_len = s2.length();

        for (int i = 0; i < Z.size(); ++i) {
            if (Z[i] == s2_len) {
                int match_index = i - s2_len - 1;
                if (match_index + s2_len <= (count - 1) * s1.length()) {
                    return count - 1;
                }
                else {
                    return count;
                }
            }
        }

        return -1;
    }
};

int main() {
    string s1, s2;
    cout << "Ingrese s1: ";
    cin >> s1;
    cout << "Ingrese s2: ";
    cin >> s2;

    Solution sol;
    int result = sol.minRepeats(s1, s2);

    cout << "Mínimas repeticiones necesarias: " << result << endl;

    return 0;
}
