#include <iostream>
#include <vector>
using namespace std;


// Función para calcular el arreglo Z de una cadena S
vector<int> computeZ(const string& s) {
  int n = s.size();
  vector<int> Z(n, 0);

  int L = 0, R = 0;

  for (int i = 1; i < n; i++) {
    if (i <= R)
      Z[i] = min(R - i + 1, Z[i - L]);
      
    while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
      Z[i]++;
      
    if (i + Z[i] - 1 > R) {
      L = i;
      R = i + Z[i] - 1;
    }
  }
    
  return Z;
}

// Buscar patrón P en texto T usando el algoritmo Z
bool searchPattern(const string& text, const string& pattern) {
    bool wasFound = false;
    string combined = pattern + "$" + text;
    vector<int> Z = computeZ(combined);
    
    int pLen = pattern.size();
    
    for (int i = 0; i < (int)Z.size(); i++) {
        if (Z[i] == pLen) {
            wasFound = true;
            cout << "Patrón encontrado en índice " << i - pLen - 1 << endl;
        }
    }
    
    return wasFound;
}

int main() {
    string text = "abcx";
    string pattern = "cx";
    
    bool patternFound = searchPattern(text, pattern);
    if(!patternFound){
        cout << "No se encontro el patron" << endl;
    }
    
    return 0;
}
