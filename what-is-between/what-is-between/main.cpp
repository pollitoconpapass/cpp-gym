/*
 Complete the function that takes two integers (a, b, where a < b) and return an array of all integers between the input parameters, including them.
 
 For example:
 a = 1
 b = 4
 --> [1, 2, 3, 4]

 LINK: https://www.codewars.com/kata/55ecd718f46fba02e5000029/cpp
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> between(int start, int end){
    vector<int> res;
    for (int i = start; i <= end; i++)
        res.push_back(i);
    
    return res;
}

int main(){
    int a = -2;
    int b = 2;
    
    vector<int> sol = between(a, b);
    
    for (auto x: sol){
        cout << x << endl;
    }
    
    
    return 0;
}
