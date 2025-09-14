/*
Task: Find the opposite of a given number

LINK: https://www.codewars.com/kata/56dec885c54a926dcd001095
*/

#include <iostream>

int opposite(int number) {
    return number*-1;
}

int main() {
    int num = 0;
    std::cout << opposite(num) << std::endl;
    return 0;
}