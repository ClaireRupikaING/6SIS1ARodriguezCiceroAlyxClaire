#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const int NO_COLORES = 4;
const int NO_TARJETAS_COLOR = 9;
const int NO_JUGADORES = 2; // Para simplificar solo 2 jugadores

struct Tarjeta {
    string color;
    int numero;
};

struct Jugador {
    vector<Tarjeta> mano;
};

// Función para inicializar el mazo
vector<Tarjeta> inicializarMazo() {
    vector<Tarjeta> mazo;
    string colores[] = {"Rojo", "Azul", "Verde", "Amarillo"};
    
    for (int i = 0; i < NO_COLORES; ++i) {
        for (int j = 1; j <= NO_TARJETAS_COLOR; ++j) {
            Tarjeta tarjeta = {colores[i], j};
            mazo.push_back(tarjeta);
        }
    }
    return mazo;
}

// Función para mezclar el mazo
void mezclarMazo(vector<Tarjeta>& mazo) {
    srand(time(0));
    random_shuffle(mazo.begin(), mazo.end());
}

// Función para repartir las tarjetas a los jugadores
void repartirTarjetas(vector<Tarjeta>& mazo, vector<Jugador>& jugadores) {
    int numTarjetasPorJugador = mazo.size() / NO_JUGADORES;
    
    for (int i = 0; i < NO_JUGADORES; ++i) {
        for (int j = 0; j < numTarjetasPorJugador; ++j) {
            jugadores[i].mano.push_back(mazo.back());
            mazo.pop_back();
        }
    }
}

// Función para mostrar las tarjetas de un jugador
void mostrarMano(const Jugador& jugador) {
    for (const auto& tarjeta : jugador.mano) {
        cout << tarjeta.color << " " << tarjeta.numero << endl;
    }
}

// Función principal del juego
int main() {
    vector<Tarjeta> mazo = inicializarMazo();
    mezclarMazo(mazo);

    vector<Jugador> jugadores(NO_JUGADORES);
    repartirTarjetas(mazo, jugadores);

    // Mostrar las manos de los jugadores
    for (int i = 0; i < NO_JUGADORES; ++i) {
        cout << "Jugador " << i + 1 << ":\n";
        mostrarMano(jugadores[i]);
        cout << endl;
    }

    // Aquí puedes implementar la lógica del juego
    // Esto incluiría turnos, jugar una tarjeta, robar una tarjeta, verificar condiciones de victoria, etc.

    return 0;
}
