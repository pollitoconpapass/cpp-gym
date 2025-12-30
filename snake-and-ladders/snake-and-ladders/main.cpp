/*
LINK: https://www.hackerrank.com/challenges/the-quickest-way-up/problem
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int quickestWayUp(const vector<pair<int, int>>& ladders, const vector<pair<int, int>>& snakes) {
    vector<int> board(101); // -> tablero
    for (int i = 1; i <= 100; ++i)
        board[i] = i; // -> inicializa las coordenadas

    for (const auto& ladder : ladders)
        board[ladder.first] = ladder.second; // -> escaleras: board[base] = destino

    for (const auto& snake : snakes)
        board[snake.first] = snake.second; // -> serpiente: board[cabeza] = cola

    vector<bool> visited(101, false); // -> Marca los casilleros visitados para evitar ciclos.
    queue<pair<int, int>> q; // -> Cola para BFS. (casillero actual, numero de tiradas)
    q.push({1, 0}); // -> empieza casillero 1, 0 tiradas
    visited[1] = true; // -> ya inicializamos el casilleto 1 asi que, true

    while (!q.empty()) {
        int pos = q.front().first; // -> el primer elemento de la cola
        int moves = q.front().second; // -> junto con sus nros de tiradas
        q.pop(); // -> los extrae

        if (pos == 100) // -> si la posicion es 100, ya llego al final.
            return moves; // -> devuelve el nro de tiradas

        for (int dice = 1; dice <= 6; ++dice) { // -> para cada posible cara del dado (1 a 6)
            int next = pos + dice; // -> calcula el siguiente casillero
            if (next <= 100 && !visited[board[next]]) { // -> si aun no es el ultimo lugar del tablero y no ha sido visitado...
                visited[board[next]] = true; // -> lo marcamos como visitado
                q.push({board[next], moves + 1}); // -> lo agregamos a la cola
            }
        }
    }

    return -1; // -> si no llegamos al ultimo lugar del tablero devuelve -1
}

int main() {
    int t;
    cin >> t;
    vector<int> resultados;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> ladders(n);
        for (int i = 0; i < n; ++i)
            cin >> ladders[i].first >> ladders[i].second;

        int m;
        cin >> m;
        vector<pair<int, int>> snakes(m);
        for (int i = 0; i < m; ++i)
            cin >> snakes[i].first >> snakes[i].second;

        resultados.push_back(quickestWayUp(ladders, snakes));
    }

    for (int res : resultados)
        cout << res << endl;

    return 0;
}
