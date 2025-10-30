#include <iostream>
using namespace std;

// Return sum from 0...i from array
int getSum(int fw[], int i)
{
    int sum = 0;
    // Fenwick's index start from 1
    i++;

    while (i > 0)
    {
        sum += fw[i];
        // i & (-i)  returns the decimal value of last set digit
        // eg: if i = 12 (1100) then  i & (-i) will 4 (100)
        i -= i & (-i);
    }
    return sum;
}

// newVal will be updated to Fenwick and all its ancestor
void updateFW(int fw[], int n, int i, int newVal)
{
    // Fenwick's index start from 1
    i++;
    while (i <= n)
    {
        fw[i] += newVal;
        i += i & (-i);
    }
}

// Build Fenwick's tree
int* constructFenwick(int a[], int n)
{
    int* fw = new int[n + 1];
    for (int i = 0; i <= n; i++)
        fw[i] = 0; //coloca a todos en cero

    for (int i = 0; i < n; i++)
        updateFW(fw, n, i, a[i]);

    return fw;
}


int main()
{
    int a[] = { 2, -1, 3, 4, 5, 6, 7 };
    
    int n = sizeof(a) / sizeof(a[0]);
    
    cout << "\nValores iniciales:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\n";

    int* fw = constructFenwick(a, n);
    int valor;
    cout << "\nIngresar valor indice para suma: ";
    do {
        cin >> valor;
    } while (valor<0 || valor>n);
    cout << getSum(fw, valor);

    a[3] += 7;
    updateFW(fw, n, 3, 7);
    cout << "\n\nValor modificado:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\n";
    cout << "\nActualizado ";
    cout << "\nIngresar valor indice para suma: ";
    do {
        cin >> valor;
    } while (valor<0 || valor>n);
    cout << getSum(fw, valor) << "\n";
    return 0;
}
