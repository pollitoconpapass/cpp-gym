/*
LINK: https://www.hackerrank.com/contests/acm-042117/challenges/is-this-ternary-search/problem
*/
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* mid;
    Node* right;

    Node(int val) {
        key = val;
        left = nullptr;
        mid = nullptr;
        right = nullptr;
    }
};

int insert(Node* root, int key) {
    Node* current = root;
    while (true) {
        if (key < current->key) {
            if (current->left == nullptr) {
                current->left = new Node(key);
                return current->key;
            } else {
                current = current->left;
            }
        } else if (key > current->key) {
            if (current->right == nullptr) {
                current->right = new Node(key);
                return current->key;
            } else {
                current = current->right;
            }
        } else {
            if (current->mid == nullptr) {
                current->mid = new Node(key);
                return current->key;
            } else {
                current = current->mid;
            }
        }
    }
}

int main() {
    int N, X;
    cin >> N >> X;

    Node* root = new Node(X);

    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        cout << insert(root, val) << endl;
    }

    return 0;
}
