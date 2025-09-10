#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split_string(const string &s, char delimiter) {
    vector<std::string> tokens;
    string token;
    stringstream ss(s);

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string pig_it(string str) {
    string result = "";
    vector <string> tokens = split_string(str, ' ');

    for (int i = 0; i < int(tokens.size()); i++) {
        string prev_str = tokens[i];

        if (prev_str == "!" || prev_str == "," || prev_str == "." || prev_str == "?") {
            result += prev_str;
        } else {
            string new_str = prev_str + prev_str[0] + "ay";
            result += new_str.erase(0, 1); // + " "
        }

        if (i < int(tokens.size()) - 1) {
            result += " ";
        }

    }

    return result; // result.erase(result.size() - 1, 1);
}

int main() {
    string input = "Hello world !";
    cout << pig_it(input);

    /*
    pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
    pigIt('Hello world !');     // elloHay orldway !
    */

    return 0;
}