/*
 
 Write a program that will calculate the number of trailing zeros in a factorial of a given number.

 N! = 1 * 2 * 3 *  ... * N

 Be careful 1000! has 2568 digits...

 For more info, see: http://mathworld.wolfram.com/Factorial.html

 Examples
 N    Product    N factorial    Trailing zeros
 6    1*2*3*4*5*6    720    1
 12    1*2*3*4*5*6*7*8*9*10*11*12    479001600    2

 LINK: https://www.codewars.com/kata/52f787eb172a8b4ae1000a34/cpp
 */
#include <iostream>
using namespace std;

long zeros(long n){
    long count = 0;
    while (n>=5){
        n /= 5;
        count += n;
    }
    
    return count;
}

int main() {
    cout << zeros(1000) << endl;
    return 0;
}
