/*
LINK: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/move-minimization-8a9d3991/
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 7005; // -> tamaño maximo del Fenwick Tree
vector<int> fw(MAX); // -> el vector fw representa el Fenwick Tree


int getSum(int i) { // Calcula la suma acumulada desde 1 hasta i en el Fenwick Tree
    // Cuentos numeros menores que i ya han sido procesados
    int res = 0;
    while (i > 0) {
        res += fw[i]; // -> subir en el arbol y sumar los valores necesarios
        i -= i & -i; // -> calcula el bit menos significativo
    }
    return res;
}


void updateFW(int i, int val) { // Suma el parametro val al elemento en posicion i y propaga el cambio a los nodos afectados
    while (i < MAX) {
        fw[i] += val; // -> suma val al elemento en posicion i
        i += i & -i; // -> propaga el cambio a los demas nodos
    }
}

/* EJ:
 Para a = [1, 4, 2, 3, 5]
 - Procesa 5: i -1 = 4 -> getSum(4) Cuantos numeros menores que 4 ya han sido procesados = 0 -> inv = 0
 Ahora en el Fenwick Tree esta 5
 
 - Procesa 3: i-1 = 2 -> getSum(2) Cuantos numeros menores que 2 ya han sido procesados = 0 -> inv = 0
 Ahora en el Fenwick Tree esta 5, 3
 
 - Procesa 2: i-1 = 1 getSum(1) Cuantos numeros menores a 1 ya han sido procesados = 0  -> inv = 0
 Ahora en el Fenwick Tree esta 5, 3, 2
 
 - Procesa 4: i-1 = 3 -> getSum(3) Cuantos numeros menores a 3 ya han sido procesados = 1 (por el 2) -> inv = 1
 Ahora en el Fenwick Tree estan 5, 3, 2, 4
 
 - Procesa 1: i-1 = 0 -> getSum(0) Cuantos numeros menores a 0 ya han sido procesados = 0 (siempre es 0)
 */
int countInversions(const vector<int>& a) { // Cuenta el nro de inversiones (steps) en la permutación a
    int n = a.size();
    fill(fw.begin(), fw.end(), 0); // -> inicializa el Fenwick tree con puro ceros
    int inv = 0; // -> cont. de inversiones
    for (int i = n - 1; i >= 0; --i) {
        inv += getSum(a[i] - 1); // -> cuantos elementos menores que a[i] han sido procesados, suma ese valor al cont. de inversiones
        updateFW(a[i], 1); // -> actualiza el Fenwick Tree con el valor de esa posicion a 1
    }
    return inv; // -> retorna la inversion
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int minBeauty = countInversions(a);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(a[i], a[j]);
            int inv = countInversions(a);
            minBeauty = min(minBeauty, inv);
            swap(a[i], a[j]);
        }
    }

    cout << minBeauty << '\n';
    return 0;
}
