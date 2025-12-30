/*
 LINK: https://www.hackerrank.com/challenges/ctci-contacts/problem
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Inicializar con los hijos que son las letras del abecedario
struct TrieNode {
    TrieNode* children[26];
    int prefixCount;

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr; // -> se le asigna todos null
        prefixCount = 0;
    }
};

class ContactsTrie {
private:
    TrieNode* root;

public:
    // Trie de contactos
    ContactsTrie() {
        root = new TrieNode(); // -> nodo raiz
    }

    // Agregar nuevo nombre a la lista de contactos
    void add(const string& name) {
        TrieNode* node = root; // -> empezamos en raiz
        for (char c : name) { // por cada letra del nombre...
            int idx = c - 'a'; // -> calculamos el indice de la letra (a = 0, b = 1)
            if (!node->children[idx]) // -> si no existe se crea
                node->children[idx] = new TrieNode();
            node = node->children[idx]; // -> avanzamos al hijo para seguir recorriendo
            node->prefixCount++; // -> aumentamos la cuenta de letras
        }
    }
    
    // Encontrar un prefijo en la lista de contactos
    int find(const string& partial) {
        TrieNode* node = root; // -> empezamos en raiz
        for (char c : partial) { // -> iteramos en las letras del prefijo que nos dan...
            int idx = c - 'a'; // -> hallamos nuevamente los indices
            if (!node->children[idx]) // -> si no existe el hijo (no existe ningun count)
                return 0;
            node = node->children[idx]; // -> si si existe avanzamos en los hijos para ver las demas letras del prefijo
        }
        return node->prefixCount; // -> del nodo donde termino, indica cuantos contactos tienen ese prefijo.
    }
};

int main() {
    int n;
    cin >> n;

    ContactsTrie trie;
    vector<int> resultados;
    string command, value;

    for (int i = 0; i < n; ++i) {
        cin >> command >> value;
        if (command == "add") {
            trie.add(value);
        } else if (command == "find") {
            resultados.push_back(trie.find(value));
        }
    }

    for (int res : resultados) {
        cout << res << endl;
    }

    return 0;
}
