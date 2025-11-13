/*
LeetCode 648. Replace Words
https://leetcode.com/problems/replace-words/description/
*/

#include <iostream>
#include <sstream>
using namespace std;

struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;

    TrieNode() : isEnd(false) {}
};

class Solution {
public:
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }

    string findRoot(TrieNode* root, const string& word) {
        TrieNode* node = root;
        string prefix;
        for (char c : word) {
            if (!node->children.count(c)) break;
            prefix += c;
            node = node->children[c];
            if (node->isEnd) return prefix;
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();

        for (auto& word : dictionary)
            insert(root, word);

        stringstream ss(sentence);
        string word;
        vector<string> result;

        while (ss >> word)
            result.push_back(findRoot(root, word));

        string replaced = "";
        for (int i = 0; i < result.size(); ++i) {
            if (i) replaced += " ";
            replaced += result[i];
        }

        return replaced;
    }
};


int main() {
    Solution s;
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";

    cout << s.replaceWords(dictionary, sentence) << endl;
    return 0;
}

