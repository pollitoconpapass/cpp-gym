#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int factorial_array_fijo() {
    int arr[] = {1, 2, 3, 4, 5};

    auto factorial = [](int i, int j){ return i * j;};
    auto res = accumulate(arr, arr + 5, 1, factorial);
    return res;
}

int factorial_dinamico() {
    int arr[20];
    int n;

    cout << "Ingresar numero: ";
    cin >> n;

    for (int i = 0; i < n; i++) arr[i] = i+1;

    auto factorial = [](int i, int j){ return i*j; };
    auto res = accumulate(arr, arr+n, 1, factorial);

    return res;
}

int factorial_vector() {
    vector <int> v{1, 2, 3, 4, 5};

    auto factorial = [](int i, int j) { return i*j; }; // ponemos la multiplicacion de cada uno...
    auto res = accumulate(v.begin(), v.end(), 1, factorial);
    // accumulate los suma los valores desde el inicio hasta el final teniendo en cuenta la multiplicacion anterior...

    return res;
}

int factorial_multiplier() {
    vector <int> v{1, 2, 3, 4, 5};
    int multi = accumulate(v.begin(), v.end(), 1, multiplies<int>());
    // multiplies toma 2 numeros y multiplica todos los numeros en medio

    return multi;
}

int main() {




    return 0;
}