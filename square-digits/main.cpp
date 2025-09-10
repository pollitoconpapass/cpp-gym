#include <iostream>
#include <string>
using namespace std;

int square_digits(int num) {
    // Unidades, Decimas, Centesimas, Milesimas
    int unidades =  num % 10;
    cout << unidades << endl;
    int decimas = ((num % 100) - unidades) / 10;
    cout << decimas << endl;
    int centesimas = ((num % 1000) - unidades) / 100 ;
    cout << centesimas << endl;
    int milesimas = ((num % 10000) - unidades) / 1000;
    cout << milesimas << endl;
    int dosmilesimas = ((num % 100000) - unidades) / 10000;
    cout << dosmilesimas << endl;

    // Sacar cuadrado de cada uno
    int unidades_cuadrado = unidades * unidades;
    int decimas_cuadrado = decimas * decimas;
    int centesimas_cuadrado = centesimas * centesimas;
    int milesimas_cuadrado = milesimas * milesimas;
    int dosmilesimas_cuadrado = dosmilesimas * dosmilesimas;

    string suma_strings = std::to_string(dosmilesimas_cuadrado) + std::to_string(milesimas_cuadrado) + std::to_string(centesimas_cuadrado) + std::to_string(decimas_cuadrado) + std::to_string(unidades_cuadrado);

    return stoi(suma_strings);
}

int square_digits_solution_2(int num) {
    std::string s = std::to_string(num);
    std::string ans;
    for(char c: s){
        int i = c - '0';
        ans += std::to_string(i * i);
    }
    return std::stoi(ans);
}

int main() {
    int num = 13579;
    int solution = square_digits(num);
    cout << solution << endl;
    return 0;
}