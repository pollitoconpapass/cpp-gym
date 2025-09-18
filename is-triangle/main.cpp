#include <iostream>
using namespace std;

bool isTriangle(int a, int b, int c) {
    if ((a + b > c) && (a+c > b) && (b+c > a)) {
        return true;
    }
    return false;
}

int main() {
    int a =3 , b=2, c=1;
    cout << isTriangle(a, b, c);
    return 0;
}