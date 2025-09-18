/*
Given a list and a number, create a new list that contains each number of list at most N times, without reordering.
For example if the input number is 2, and the input list is [1,2,3,1,2,1,2,3], you take [1,2,3,1,2], drop the next [1,2] since this would lead to 1 and 2 being in the result 3 times, and then take 3, which leads to [1,2,3,1,2,3].
With list [20,37,20,21] and number 1, the result would be [20,37,21].
*/

#include <iostream>
#include <vector>
using namespace std;

// Count function
int checkCount(int n, vector<int> arr) {
    auto frequency = count(arr.begin(), arr.end(), n);
    return frequency;
}

vector<int> deleteNth(vector<int> arr, int n) {
    vector<int> res;

    // Go over all the vector
    for (int i = 0; i < arr.size(); i++) {
        // Check the count of that item in the res vector
        int frequency = checkCount(arr[i], res);
        if (frequency < n) {
            res.push_back(arr[i]);
        }
    }
    return res;
}


int main() {
    vector<int> arr = {1,2,3,1,2,1,2,3};
    int N = 2;

    vector<int> res = deleteNth(arr, N);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}