/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:
- Trie() Initializes the trie object.
- void insert(String word) Inserts the string word into the trie.
- boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
- boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Example 1:
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

Constraints:
- 1 <= word.length, prefix.length <= 2000
- word and prefix consist only of lowercase English letters.
- At most 3 * 10^4 calls in total will be made to insert, search, and startsWith

LINK: https://leetcode.com/problems/implement-trie-prefix-tree/description/
*/

#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false; // -> indica si una palabra termino
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode(); // -> inicializar raiz
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(!node->children[index]) // -> si el nodo hijo no existe...
                node->children[index] = new TrieNode(); // -> lo va a crear
            node = node->children[index]; // -> iterar hasta la otra linea
        }
        node->isEndOfWord = true; // -> al terminar, marca como true que una palabra termino
    }

    // Busca una palabra completa
    bool search(string word) {
        TrieNode* node = root; // -> empezamos en la raiz
        for(char c : word) {
            int index = c - 'a'; // -> calcular indice
            if(!node->children[index]) // -> si no existe el nodo hijo, entonces la palabra como tal no esta en el trie
                return false; // -> devuelve false (pq no esta en el trie)
            node = node->children[index]; // -> recorre toda la palabra
        }
        return node->isEndOfWord; // -> si es que si llega al final, entonces isEndWord esta en True, devuelve True.
    }

    bool startsWith(string prefix) {
        TrieNode* node = root; // -> empieza en la raiz
        for(char c : prefix) {
            int index = c - 'a'; // -> calcula el indice de cada char
            if(!node->children[index]) // -> si el hijo no existe entonces
                return false; // -> el prefijo no existe
            node = node->children[index]; // -> avanza al hijo del hijo...
        }
        return true; // -> si pasa todo, entonces si existe. Devuelve true
    }
};


int main(){
    auto trie = Trie();
    
    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;
    
    return 0;
}
