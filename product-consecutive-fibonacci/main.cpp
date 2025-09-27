/*
The Fibonacci numbers are the numbers in the following integer sequence (Fn):
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...

such that:
F(0)=0
F(1)=1
F(n)=F(n−1)+F(n−2)

Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying:
F(n)∗F(n+1)=prod

-------------
Your function takes an integer (prod) and returns an array/tuple (check the function signature/sample tests for the return type in your language):
if F(n) * F(n+1) = prod :
(F(n), F(n+1), true)

If you do not find two consecutive F(n) verifying F(n) * F(n+1) = prod :
(F(n), F(n+1), false)
where F(n) is the smallest one such as F(n) * F(n+1) > prod.

Examples:
714 ---> (21, 34, true)
--> since F(8) = 21, F(9) = 34 and 714 = 21 * 34

800 --->  (34, 55, false)
--> since F(8) = 21, F(9) = 34, F(10) = 55 and 21 * 34 < 800 < 34 * 55

LINK: https://www.codewars.com/kata/5541f58a944b85ce6d00006a
*/
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

class ProdFib {
public:
    static ull fibonacci(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    static vector<ull> productFib(ull prod) {
        vector<ull> res;
        for (ull i = 1; i < prod; i++) {
            if (fibonacci(i) * fibonacci(i+1) == prod) {
                res.push_back(fibonacci(i));
                res.push_back(fibonacci(i+1));
                res.push_back(true);
                return res;
            } else if (fibonacci(i) * fibonacci(i+1) > prod) {
                res.push_back(fibonacci(i));
                res.push_back(fibonacci(i+1));
                res.push_back(false);
                return res;
            }
        }
    }
};

int main() {
    auto prodFib = ProdFib();
    vector<ull> vec = prodFib.productFib(5895);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

    return 0;
}