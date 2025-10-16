#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

struct Equipo {
    string nombre;
    int puntos;
    int partidosGanados;
    int partidosJugados;
    int anotaciones;

    Equipo(string nombre) : nombre(nombre), puntos(0), partidosGanados(0), partidosJugados(0), anotaciones(0) {}
};

bool ordenarPorPuntos(const Equipo& e1, const Equipo& e2) {
    return e1.puntos > e2.puntos;
}

bool ordenarPorAnotaciones(const Equipo& e1, const Equipo& e2) {
    return e1.anotaciones > e2.anotaciones;
}

bool ordenarPorPartidosJugados(const Equipo& e1, const Equipo& e2) {
    return e1.partidosJugados < e2.partidosJugados;
}

int main() {
    string campeonato;
    int N, S;

    getline(cin, campeonato); // -> nombre del campeonato

    cin >> N; // cant de equipos
    cin.ignore();

    vector<Equipo> equipos;


    for (int i = 0; i < N; ++i) { // registar los equpos
        string nombreEquipo;
        getline(cin, nombreEquipo);
        equipos.push_back(Equipo(nombreEquipo));
    }

    // Nro de juegos
    cin >> S;
    cin.ignore();

    // Rresultados
    for (int i = 0; i < S; ++i) {
        string linea;
        getline(cin, linea);

        stringstream ss(linea);
        string equipo1, equipo2;
        int anotaciones1, anotaciones2;

        // obtener el resultado del partido
        getline(ss, equipo1, '-');
        ss >> anotaciones1; // -> guardar lo q esta despues del -
        ss.ignore();
        ss >> anotaciones2; // -> guardar lo q esta despues del #
        ss.ignore();
        getline(ss, equipo2);

        
        Equipo* e1 = nullptr; // buscar los equipos en el vector
        Equipo* e2 = nullptr;
        for (auto& equipo : equipos) {
            if (equipo.nombre == equipo1) e1 = &equipo;
            if (equipo.nombre == equipo2) e2 = &equipo;
        }

        // ir actualizando las anotaciones ypartidos
        e1->partidosJugados++;
        e1->anotaciones += anotaciones1;
        e2->partidosJugados++;
        e2->anotaciones += anotaciones2;

        // ir actualizando los puntos y partidos ganados
        if (anotaciones1 > anotaciones2) {
            e1->puntos += 3;
            e1->partidosGanados++;
        } else if (anotaciones2 > anotaciones1) {
            e2->puntos += 3;
            e2->partidosGanados++;
        } else {
            e1->puntos += 1;
            e2->puntos += 1;
        }
    }

    // === Mostrar todo ===
    cout << campeonato << endl;

    // más puntos
    sort(equipos.begin(), equipos.end(), ordenarPorPuntos);
    cout << "1. " << equipos.front().nombre << "," << equipos.front().puntos << " puntos (" << equipos.front().partidosGanados << " partidos ganados)" << endl;

    // menos puntos
    sort(equipos.begin(), equipos.end(), [](const Equipo& e1, const Equipo& e2) {
        return e1.puntos < e2.puntos;
    });
    cout << "2. " << equipos.front().nombre << "," << equipos.front().puntos << " puntos (" << equipos.front().partidosGanados << " partidos ganados)" << endl;

    // menos partidos jugados
    sort(equipos.begin(), equipos.end(), ordenarPorPartidosJugados);
    cout << "3. " << equipos.front().nombre << "," << equipos.front().partidosJugados << " partidos" << endl;

    // más anotaciones
    sort(equipos.begin(), equipos.end(), ordenarPorAnotaciones);
    cout << "4. " << equipos.front().nombre << "," << equipos.front().anotaciones << " anotaciones" << endl;

    // menos anotaciones
    sort(equipos.begin(), equipos.end(), [](const Equipo& e1, const Equipo& e2) {
        return e1.anotaciones < e2.anotaciones;
    });
    cout << "5. " << equipos.front().nombre << "," << equipos.front().anotaciones << " anotaciones" << endl;

    return 0;
}

