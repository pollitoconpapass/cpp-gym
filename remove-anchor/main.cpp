#include <iostream>
#include <string>
using namespace std;

string replaceAll(string str) {
    char toRemove = '#';
    size_t index = str.find(toRemove);

    if (index != string::npos) {
        str.erase(index);
    }

    return str;
}

int main() {
    string input = "www.codewars.com#about";
    cout << replaceAll(input) << endl;
    return 0;
}