/*
Given an array A[] of N integers and an integer M. The task is to count the number of subarrays which have median M.
Median of an array is defined as below:

1. If N is odd, the median value is the number that is in the middle after sorting the array.
2. if N is even, the median value is the left of the two middle numbers after sorting the array. 

Example 1:
Input:
N = 5, M = 2
A[] = {2, 1, 3, 5, 4}
Output: 
3
Explanation: 
The subarrays which has median equal to M
are [2], [2,1,3] and [2,1,3,5]

Example 2:
Input:
N = 1, M = 1
A[] = {1}
Output: 
1
Explanation: 
The subarrays which has median equal to M
is [1].

Your Task: 
You don't need to read input or print anything. Complete the function countSubarray( ) which takes the integer N , the array A[], and the integer M as input parameters and returns the number of subarays. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

LINK: https://www.geeksforgeeks.org/problems/median-of-the-subarrays--170647/1?page=1&category=Map&difficulty=Hard&sortBy=submissions
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countSubarray(int N, vector<int> A, int M) {
        int pos = -1;
        for (int i = 0; i < N; ++i) {
            if (A[i] == M) {
                pos = i;
                break;
            }
        }

        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            if (A[i] > M) B[i] = 1;
            else if (A[i] < M) B[i] = -1;
            else B[i] = 0;
        }
        unordered_map<int, int> balanceCount;
        int balance = 0;
        balanceCount[0] = 1;

        for (int i = pos + 1; i < N; ++i) {
            balance += B[i];
            balanceCount[balance]++;
        }

        long long ans = 0;
        balance = 0;
        for (int i = pos; i >= 0; --i) {
            balance += B[i];
            ans += balanceCount[-balance] + balanceCount[-balance + 1];
        }

        return ans;
    }
};

int main() {
    int N, M;
    cout << "Ingrese N (tamaño del arreglo): ";
    cin >> N;

    vector<int> A(N);
    cout << "Ingrese el arreglo A[] de tamaño " << N << ":\n";
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << "Ingrese M (valor de la mediana): ";
    cin >> M;

    Solution obj;
    long long result = obj.countSubarray(N, A, M);

    cout << "\nCantidad de subarreglos con mediana " << M << ": " << result << endl;

    return 0;
}
