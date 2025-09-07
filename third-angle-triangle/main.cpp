#include <iostream>
using namespace std;


int otherAngle(int a, int b) {
    int res = 180 - (a + b);
    return res;

}

int main() {
    int n = otherAngle(10, 20);
    cout << n << endl;
    return 0;
}