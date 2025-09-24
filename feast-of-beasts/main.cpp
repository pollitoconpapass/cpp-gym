/*
All of the animals are having a feast! Each animal is bringing one dish.
There is just one rule: the dish must start and end with the same letters as the animal's name.
For example, the great blue heron is bringing garlic naan and the chickadee is bringing chocolate cake.

Write a function feast that takes the animal's name and dish as arguments and returns true or false to indicate whether the beast is allowed to bring the dish to the feast.

Assume that beast and dish are always lowercase strings, and that each has at least two letters.
beast and dish may contain hyphens and spaces, but these will not appear at the beginning or end of the string.
They will not contain numerals.

LINK: https://www.codewars.com/kata/5aa736a455f906981800360d/cpp
*/

#include <iostream>
#include <string>
using namespace std;

bool feast(string beast, string dish){
    char firstOfBeast = beast[0];
    char firstOfDish = dish[0];

    char lastOfBeast = beast[beast.size()-1];
    char lastOfDish = dish[dish.size()-1];

    if (firstOfBeast == firstOfDish && lastOfBeast == lastOfDish) {
        return true;
    }
    return false;
    // Other way to solve it: return beast.front()==dish.front() && beast.back()==dish.back()
}

int main() {
    string beast = "brown bear";
    string dish = "bear claw";

    cout << feast(beast, dish) << endl;
    return 0;
}