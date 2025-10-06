/*
Desarrollar un ejercicio con texto y un patrón, implemente el algoritmo KMP para implementar lo siguiente:
- Ingresar un número entero T que indica el número de casos de prueba, el número debe ser mayor a 1 y menor a 10000.
- Para cada caso de prueba se debe ingresar o agregar los valores de manera aleatoria al patrón y al texto, el tamaño del patrón y el texto debe ser definido por el desarrollador.
- Encontrar todas las apariciones del patrón en el texto.
- Cuando se encuentre el patrón en el texto, debe remover los dígitos del patrón del texto, y mostrar la nueva cadena de texto.
- Si el patrón es encontrado por más de 3 veces debe mostrar un mensaje que diga: “El patrón es muy frecuente en el texto.
- Si no encuentra el patrón en el texto, mostrar un mensaje que diga “No se encontró patrón”.
*/

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
using namespace std;


vector<int> computeLPSArray(const string& pattern) { // -> algoritmo LPS (visto en clase)
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
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

vector<int> KMPSearch(const string& text, const string& pattern) { // -> algoritmo de KMP (visto en clase)
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPSArray(pattern);
    vector<int> matches;

    int i = 0; // índice para el texto
    int j = 0; // índice para el patrón

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return matches;
}

string generateRandomString(int length) { // -> generacion de strings aleatorios (uso de IA)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 25); // -> de la 'a' a la 'z'

    string s = "";
    for (int i = 0; i < length; ++i) {
        s += char('a' + dis(gen));
    }
    return s;
}

int main() {
    int T;
    cout << "Ingrese el numero de casos de prueba (2 - 9999): ";
    cin >> T;

    if (T < 2 || T > 9999) { // -> rango definido en el enunciado
        cout << "Nro de casos invalido." << endl;
        return 1;
    }

    // rango de tamaños (defnido por nosotros)
    int minTextSize = 10;
    int maxTextSize = 30;
    int minPatternSize = 2;
    int maxPatternSize = 6;

    for (int t = 0; t < T; ++t) {
        // generacion de tamaños aleatorios para el patron y para el texto (consultado con IA)
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> textDist(minTextSize, maxTextSize);
        uniform_int_distribution<> patternDist(minPatternSize, maxPatternSize);

        int textSize = textDist(gen);
        int patternSize = patternDist(gen);

        string text = generateRandomString(textSize);
        string pattern = generateRandomString(patternSize);

        cout << "\nCaso " << (t + 1) << ":" << endl;
        cout << "Texto: " << text << endl;
        cout << "Patron: " << pattern << endl;

        vector<int> positions = KMPSearch(text, pattern);

        if (positions.empty()) {
            cout << "No se encontro patron." << endl;
            continue;
        }

        int count = positions.size();

        if (count > 3) {
            cout << "El patron es muy frecuente en el texto." << endl;
        }

        string result = text;
        sort(positions.rbegin(), positions.rend());
        for (int pos : positions) {
            result.erase(pos, pattern.length()); // -> remover las apariciones del patrón en eltexto
        }

        cout << "Texto después de remover el patron: " << result << endl;
    }

    return 0;
}