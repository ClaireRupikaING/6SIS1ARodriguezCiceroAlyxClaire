#include <iostream>
#include <vector>
using namespace std;

struct Prestamo {
    double monto;
    double tasa;
    int dias;
};

double calcularInteresSimple(double monto, double tasa, int dias) {
    return (monto * tasa * dias) / 365;
}

int main() {
    int numeroPrestamos;
    cout << "Programa creado por Claire <3 \n";
    cout << "Ingresa el número de préstamos: ";
    cin >> numeroPrestamos;

    vector<Prestamo> prestamos(numeroPrestamos);

    // Solicitar la información de cada préstamo
    for (int i = 0; i < numeroPrestamos; ++i) {
        cout << "Ingrese el monto del préstamo " << i + 1 << ": ";
        cin >> prestamos[i].monto;
        cout << "Ingrese la tasa de interés anual (como un decimal) del préstamo " << i + 1 << ": ";
        cin >> prestamos[i].tasa;
        cout << "Ingrese el número de días del préstamo " << i + 1 << ": ";
        cin >> prestamos[i].dias;
    }

    // Calcular y mostrar el interés simple de cada préstamo
    for (int i = 0; i < numeroPrestamos; ++i) {
        double interes = calcularInteresSimple(prestamos[i].monto, prestamos[i].tasa, prestamos[i].dias);
        cout << "El interés simple del préstamo " << i + 1 << " es: " << interes << endl;
    }

    return 0;
}
