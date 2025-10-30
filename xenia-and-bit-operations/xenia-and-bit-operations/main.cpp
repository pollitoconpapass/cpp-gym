/*
 Xenia the beginner programmer has a sequence a, consisting of 2n non-negative integers: a1, a2, ..., a2n. Xenia is currently studying bit operations. To better understand how they work, Xenia decided to calculate some value v for a.

 Namely, it takes several iterations to calculate value v. At the first iteration, Xenia writes a new sequence a1 or a2, a3 or a4, ..., a2n - 1 or a2n, consisting of 2^n - 1 elements. In other words, she writes down the bit-wise OR of adjacent elements of sequence a. At the second iteration, Xenia writes the bitwise exclusive OR of adjacent elements of the sequence obtained after the first iteration. At the third iteration Xenia writes the bitwise OR of the adjacent elements of the sequence obtained after the second iteration. And so on; the operations of bitwise exclusive OR and bitwise OR alternate. In the end, she obtains a sequence consisting of one element, and that element is v.

 Let's consider an example. Suppose that sequence a = (1, 2, 3, 4). Then let's write down all the transformations (1, 2, 3, 4)  →  (1 or 2 = 3, 3 or 4 = 7)  →  (3 xor 7 = 4). The result is v = 4.

 You are given Xenia's initial sequence. But to calculate value v for a given sequence would be too easy, so you are given additional m queries. Each query is a pair of integers p, b. Query p, b means that you need to perform the assignment ap = b. After each query, you need to print the new value v for the new sequence a.

 Input
 The first line contains two integers n and m (1 ≤ n ≤ 17, 1 ≤ m ≤ 10^5). The next line contains 2^n integers a1, a2, ..., a2n (0 ≤ ai < 2^30). Each of the next m lines contains queries. The i-th line contains integers pi, bi (1 ≤ pi ≤ 2^n, 0 ≤ bi < 2^30) — the i-th query.

 Output
 Print m integers — the i-th integer denotes value v for sequence a after the i-th query.
 
 Examples
 input:
 2 4
 1 6 3 5
 1 4
 3 4
 1 2
 1 2

 output:
 1
 3
 3
 3
 
 LINK: https://codeforces.com/problemset/problem/339/D
 */

#include <iostream>
#include <vector>
 
using namespace std;
 
class SegmentTree {
private:
    vector<int> tree;
    int n;
    bool isOrOperation;
 
    void buildTree(const vector<int>& arr, int node, int start, int end, bool isOr) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node + 1, start, mid, !isOr);
            buildTree(arr, 2 * node + 2, mid + 1, end, !isOr);
            if (isOr) {
                tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
            } else {
                tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
            }
        }
    }
 
    void update(int node, int start, int end, int idx, int value, bool isOr) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, value, !isOr);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value, !isOr);
            }
            if (isOr) {
                tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
            } else {
                tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
            }
        }
    }
 
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        isOrOperation = (n & (n - 1)) == 0 && __builtin_popcount(n) % 2 == 0;
        buildTree(arr, 0, 0, n - 1, isOrOperation);
    }
 
    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value, isOrOperation);
    }
 
    int getResult() {
        return tree[0];
    }
};
 
int main() {
    int n, m;
    cin >> n >> m;
    int size = 1 << n;
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
 
    SegmentTree segTree(arr);
 
    for (int i = 0; i < m; ++i) {
        int p, b;
        cin >> p >> b;
        segTree.update(p - 1, b);
        cout << segTree.getResult() << endl;
    }
 
    return 0;
}
