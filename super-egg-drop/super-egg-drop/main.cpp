/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:
Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

Example 2:
Input: k = 2, n = 6
Output: 3

Example 3:
Input: k = 3, n = 14
Output: 4

LINK: https://leetcode.com/problems/super-egg-drop/description/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    int dp(int k, int n) {
        if (n == 0 || n == 1) return n; // -> si el numero de pisos es 0 devolver 0, si es 1 devolver 1
        if (k == 1) return n; // -> si solo hay un huevo, retornar el numero del piso
        if (memo[k][n] != -1) return memo[k][n]; // -> si el resultado para k huevos y n pisos ya esta calculado, entonces devolverlo directo

        int low = 1, high = n; // -> limites (menor piso 1, mas alto es n)
        int res = n; // -> probamos primero con n

        while (low <= high) {
            int mid = (low + high) / 2; // -> piso intermedio donde se lanza el huevo
            int broken = dp(k - 1, mid - 1); // -> nro de lanzamientos necesarios si el huevo se rompe en mid, (k-1 y mid-1)
            int notBroken = dp(k, n - mid); // -> en cambio si no se rompe, quedan k huevos y n-mid pisos para probar
            int worst = max(broken, notBroken) + 1; // -> el peor caso entre broken y notBroken, mas 1 que es el lanzamiento actual

            res = min(res, worst); // -> guarda el minimo nro de lanzamientos encontrados

            if (broken > notBroken) { // -> si los intentos para que se rompa son mayores...
                high = mid - 1; // -> el peor caso esta en los pisos inferiores
            } else { // -> sino...
                low = mid + 1; // -> el peor caso esta en los pisos superiores
            }
        }

        return memo[k][n] = res; // -> asignamos el mejor resultado obtenido
    }

    int superEggDrop(int k, int n) {
        memo = vector<vector<int>>(k + 1, vector<int>(n + 1, -1)); // -> tabla de memorizacion para guardar resultados ya calculados
        // Empieza en una matriz de k+1 y n+1, todo inicializado con -1, ningun caluclo se ha hecho aun
        return dp(k, n); // -> Calculamos los lanzamientos necesarios (k huevos, n pisos) 90
    }
};

int main(){
    int k;
    cin >> k;
    
    int n;
    cin >> n;
    
    auto dp = new Solution();
    cout << dp->superEggDrop(k, n) << endl;
    
    return 0;
}
