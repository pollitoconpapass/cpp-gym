/*
Deoxyribonucleic acid, DNA is the primary information storage molecule in biological systems.
It is composed of four nucleic acid bases Guanine ('G'), Cytosine ('C'), Adenine ('A'), and Thymine ('T').

Ribonucleic acid, RNA, is the primary messenger molecule in cells. RNA differs slightly from DNA its chemical structure and contains no Thymine.
In RNA Thymine is replaced by another nucleic acid Uracil ('U').

Create a function which translates a given DNA string into RNA.

For example:
"GCAT"  =>  "GCAU"
The input string can be of arbitrary length - in particular, it may be empty. All input is guaranteed to be valid, i.e. each input string will only ever consist of 'G', 'C', 'A' and/or 'T'.

LINK: https://www.codewars.com/kata/5556282156230d0e5e000089/cpp
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string DNAtoRNA(string dna) {
    unordered_map<char, char> dnaMap  {
        {'T', 'U'},
        {'U', 'T'}
    };

    string solution = "";
    for (auto c : dna) {
        if (c == 'T' || c == 'U') {
            solution += dnaMap[c];
        } else {
            solution += c;
        }
    }

    return solution;
}

string DNAtoRNAwithReplaceMethod(string dna) {
    replace(dna.begin(), dna.end(), 'T', 'U');
    return dna;
}

int main() {
    string dna = "GCAT";
    cout << DNAtoRNA(dna) << endl;
    cout << DNAtoRNAwithReplaceMethod(dna) << endl;
    return 0;
}