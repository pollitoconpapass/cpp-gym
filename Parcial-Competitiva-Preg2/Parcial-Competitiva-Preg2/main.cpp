#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> computeLPS(string pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMPSearch(string text, string pattern) {
    vector<int> positions;
    int n = text.length();
    int m = pattern.length();
    if (m == 0) return positions;

    vector<int> lps = computeLPS(pattern);
    int i = 0; // para el text
    int j = 0; // para el pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            positions.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return positions;
}

string generateRandomString(int n) {
    string chars = "ABCEP"; // A, B, C, P, E
    string result = "";
    for (int i = 0; i < n; i++) {
        result += chars[rand() % 5]; // solo 5 carc.
    }
    return result;
}

string removePattern(string text, string pattern) {
    string result = "";
    int n = text.length();
    int m = pattern.length();
    int i = 0;
    while (i <= n - m) {
        if (text.substr(i, m) == pattern) {
            i += m;
        } else {
            result += text[i];
            i++;
        }
    }
    while (i < n) {
        result += text[i];
        i++;
    }
    return result;
}

int main() {
    srand(time(0));

    int Q;
        cout << "Ingresar número de simulaciones:\n";
        while (true) {
            if (cin >> Q && Q > 0 && Q < 500) {
                break;
            } else {
                cout << "Error: Ingrese un número entero con 0 < Q < 500.\n";
            }
        }

        int maxCount = 0;
        int bestSim = -1;

        for (int sim = 1; sim <= Q; sim++) {
            int C;
            cout << "\nIngresar cantidad de elementos en la cadena:\n";
            while (true) {
                if (cin >> C && C >= 20 && C <= 10000) {
                    break;
                } else {
                    cout << "Error: Ingrese un número entero con 20 < C < 10000.\n";
                }
            }

        // generar cadena aleatoria
        string genome = generateRandomString(C);

        // generar patrón Sli de 5 caracteres
        string sli = generateRandomString(5);

        cout << "\nGen SLI: " << sli << "\n";
        cout << "Cadena: " << genome << "\n";

        // buscar matches con el algoritmo KMP
        vector<int> matches = KMPSearch(genome, sli);
        int count = matches.size();

        // mostrar los indices
        for (int idx : matches) {
            cout << "Indice: " << idx << "\n";
        }

        cout << "Cantidad de apariciones: " << count << "\n";

        // reemplazar cada aparicion con un "ZXZXZ"
        string modified = genome;

        for (auto it = matches.rbegin(); it != matches.rend(); ++it) {
            modified.replace(*it, 5, "ZXZXZ");
        }

        cout << "Cadena: " << modified << "\n";

        // si es q hay 4 apariciones o mas
        if (count >= 4) {
            cout << "\"Se encontraron varias veces... Genial\"\n"; // -> se imprime el Genial!
            string withoutPattern = removePattern(genome, sli);
            cout << "Cadena: " << withoutPattern << "\n";
        }

        cout << "************************************************************\n";

        // guarda simulacion con mas patrones
        if (count > maxCount) {
            maxCount = count;
            bestSim = sim;
        }
    }

    if (bestSim != -1 && maxCount > 0) {
        cout << "\nEn la simulacion " << bestSim << " se encontraron mas patrones.\n";
    }

    return 0;
}
