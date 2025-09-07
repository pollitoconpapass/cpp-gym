#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int even_numbers_static() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int count = count_if(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
    return count;
}


int main() {
    int cant, num;

    cout << "Ingrese la cantidad de numeros: "; cin >> cant;

    vector<int> vec;
    for (int i = 0; i < cant; i++) {
       cout << "Ingrese el numero " << i+1 << ": "; cin >> num;
        vec.push_back(num);
    }

    int count = count_if(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
    cout << "Numeros pares encontrados: " << count << endl;

    return 0;
}