/*
The first line of the input contains an integer N.The next line contains N space separated integers(1-based index).The third line contains a single integer r denoting the position of an element that should be removed from the vector.The fourth line contains two integers a and b denoting the range that should be erased from the vector inclusive of a and exclusive of b.
Constraints
1 ≤ N ≤ 10^5
1 ≤ X ≤ N
1 ≤ a < b ≤ N

Output Format
Print the size of the vector in the first line and the elements of the vector after the two erase operations in the second line separated by space

Sample Input
6
1 4 6 2 8 9
2
2
4

Sample Output
3
1 8 9

Explanation:
The first query is to erase the 2nd element in the vector, which is 4.
Then, modifed vector is {1 6 2 8 9}, we want to remove the range of 2-4, which means the 2nd and 3rd elements should be removed.
Then 6 and 2 in the modified vector are removed and we finally get {1 8 9}
*/


#include <iostream>
#include <vector>
using namespace std;

vector<int>inputFormat(int N, vector<int> A, int x, int rango1, int rango2) {
    if (A.size() > N) {
        cout << "El tamaño del arreglo debe ser igual a " << N << endl;
        return {};
    }

    A.erase(A.begin() + (x-1));
    A.erase(A.begin() + (rango1 - 1 ), A.begin() + (rango2 - 1));

    cout << A.size() << endl;
    return A;
}

int main() {
    vector<int> A = {1, 4, 6, 2, 8, 9};
    vector<int> result = inputFormat(6, A, 2, 2, 4);

    for (int i = 0; i < result.size(); i++) {
        cout << result [i] << " ";
    }
    return 0;
}