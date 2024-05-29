#include <iostream>
using namespace std;

int main() {
    int i;
    int NumEnt[10];
    int suma = 0;
    double promedio;

    // Valores iniciales del vector
    NumEnt[0] = 7;
    NumEnt[1] = 64;
    NumEnt[2] = 77;
    NumEnt[3] = 89;
    NumEnt[4] = 69;
    NumEnt[5] = 666;
    NumEnt[6] = 754;
    NumEnt[7] = 99;
    NumEnt[8] = 1998;
    NumEnt[9] = 2084;

    cout << "Ingrese los valores al vector" << endl;
    for (i = 0; i < 10; i++) {
        cout << "Ingresa el valor de la posición " << i << ": ";
        cin >> NumEnt[i];
    }

    cout << "Los valores del vector son: " << endl;
    for (i = 0; i < 10; i++) {
        cout << "La posición " << i << ": " << NumEnt[i] << endl;
    }

    for (i = 0; i < 10; i++) {
        suma += NumEnt[i];
    }

    promedio = static_cast<double>(suma) / 10;

    cout << "La suma de los valores del vector es: " << suma << endl;
    cout << "El promedio de los valores del vector es: " << promedio << endl;

    return 0;
}

