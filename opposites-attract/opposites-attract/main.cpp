/*
 Timmy & Sarah think they are in love, but around where they live, they will only know once they pick a flower each. If one of the flowers has an even number of petals and the other has an odd number of petals it means they are in love.

 Write a function that will take the number of petals of each flower and return true if they are in love and false if they aren't.
 
 LINK: https://www.codewars.com/kata/555086d53eac039a2a000083/cpp
 */

#include <iostream>
using namespace std;

bool lovefunc(int f1, int f2){
    if ((f1 % 2 == 0 && f2 % 2 == 0) || (f1 % 2 != 0 && f2 % 2 != 0)) {
        return false;
    }
    return true;
}

int main() {
    bool res = lovefunc(101, 101);
    
    if (res){
        cout << "True"  << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}
