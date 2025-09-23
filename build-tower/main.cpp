/*
Build a pyramid-shaped tower, as an array/list of strings, given a positive integer number of floors.
A tower block is represented with "*" character.

For example, a tower with 3 floors looks like this:
[
  "  *  ",
  " *** ",
  "*****"
]

And a tower with 6 floors looks like this:
[
  "     *     ",
  "    ***    ",
  "   *****   ",
  "  *******  ",
  " ********* ",
  "***********"
]

LINK: https://www.codewars.com/kata/576757b1df89ecf5bd00073b/cpp
*/


#include <iostream>
#include <vector>
using namespace std;

vector<string> towerBuilder(unsigned nFloors) {
    vector<string> towerBuilder;
    string characters = "*";
    towerBuilder.push_back(characters);

    for (unsigned i = 0; i < nFloors-1; i++) {
        characters += "**";
        towerBuilder.push_back(characters);
    }
    return towerBuilder;
}

vector<string> towerBuilderSol2(unsigned nFloors) {
    vector<string> tower;
    int totalWidth = 2 * nFloors - 1;  // -> width of bottom floor

    for (unsigned i = 0; i < nFloors; i++) {
        int stars = 2 * i + 1;  // -> stars in this floor
        int spaces = (totalWidth - stars) / 2;  //-> spaces on each side

        string floor = "";

        // add leading spaces
        floor += string(spaces, ' ');

        // add stars
        floor += string(stars, '*');

        // add trailing spaces (it matches expected output :v)
        floor += string(spaces, ' ');

        tower.push_back(floor);
    }

    return tower;
}

int main() {
    vector<string> res = towerBuilder(6);
    for (string s: res) {
        cout << s << endl;
    }

    return 0;
}