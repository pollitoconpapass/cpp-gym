/*
 Muhammadali has an integer array 𝑎1,…,𝑎𝑛.
 He can change (replace) any subset of positions; changing position 𝑖
  costs 𝑐𝑖 and replaces 𝑎𝑖 with any integer of his choice. The positions that he does not change must retain their original values.

 After all changes, we call an index 𝑖 (1≤𝑖<𝑛) a drop if the final value at position 𝑖 is strictly greater than the final value at position 𝑖+1.
 
 Muhammadali wants the final array to contain no drops.
 Find the minimum cost of changes required to ensure that there are no drops in the array.

 Input
 The first line contains an integer 𝑡 (1≤𝑡≤5000) — the number of test cases.

 Each test case consists of three lines:
 The first line contains a single integer 𝑛 (1≤𝑛≤8000) — the length of the arrays.
 The second line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109) — the elements of the array.
 The third line contains 𝑛 integers 𝑐1,𝑐2,…,𝑐𝑛 (1≤𝑐𝑖≤109) — the costs of changes.

 It is guaranteed that the sum of 𝑛 across all test cases does not exceed 8000

 Output
 For each test case, output a single integer — the minimum possible total cost required to eliminate all drops.
 
 Example:
 INPUT
 1
 10
 5
 
 4
 1 2 2 3
 5 6 7 8
 
 4
 4 3 2 1
 1 1 1 1
 
 3
 3 1 2
 100 1 1
 
 5
 5 5 5 5 5
 10 1 10 1 10
 
 5
 1 3 2 2 4
 100 1 1 1 100
 
 6
 10 9 8 7 6 5
 1 100 1 100 1 100
 
 5
 100 1 100 100 100
  1 100 1   1   1
 
 4
 2 1 2 1
 5 4 3 2
 
 7
 1  5  3  4  2  6  7
 10 1  10 1  10 1  10
 
 OUTPUT
 0
 
 0
 
 3
 
 2
 
 0
 
 1
 
 203
 
 1
 
 6
 
 11
 
 LINK: https://codeforces.com/problemset/problem/2167/G
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long smoothArray(int n, vector<int>& a, vector<int>& c){
    if (n == 1) return 0;
    
    // dp[i] = minimum cost to make array[0..i] non-decreasing
    // where we keep element i unchanged
    vector<long long> dp(n, LLONG_MAX);
    
    // We can always keep the first element
    dp[0] = 0;
    
    for (int i = 1; i < n; i++){
        // Option 1: Keep position i unchanged
        // We need to find the minimum cost among all previous positions j
        // where a[j] <= a[i]
        for (int j = 0; j < i; j++){
            if (a[j] <= a[i] && dp[j] != LLONG_MAX){
                // Cost = dp[j] + cost of changing all positions between j+1 and i-1
                long long cost = dp[j];
                for (int k = j + 1; k < i; k++){
                    cost += c[k];
                }
                dp[i] = min(dp[i], cost);
            }
        }
    }
    
    // Find minimum cost considering all possible last kept positions
    long long result = LLONG_MAX;
    for (int i = 0; i < n; i++){
        if (dp[i] != LLONG_MAX){
            // Cost = dp[i] + cost of changing all positions after i
            long long cost = dp[i];
            for (int j = i + 1; j < n; j++){
                cost += c[j];
            }
            result = min(result, cost);
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        vector<int> c(n);
        for(int i = 0; i < n; i++){
            cin >> c[i];
        }
        
        cout << smoothArray(n, a, c) << endl;
    }
    
    return 0;
}
