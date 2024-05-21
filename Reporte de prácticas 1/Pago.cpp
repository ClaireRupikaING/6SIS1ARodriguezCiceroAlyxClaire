#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Empleado {
    string nombre;
    double horasTrabajadas;
    double pagoPorHora;
};

double calcularPagoBruto(double horasTrabajadas, double pagoPorHora) {
    const int HORAS_LIMITE = 40;
    const double TARIFA_EXTRA = 1.5;
    double pagoBruto;

    if (horasTrabajadas <= HORAS_LIMITE) {
        pagoBruto = horasTrabajadas * pagoPorHora;
    } else {
        double horasExtras = horasTrabajadas - HORAS_LIMITE;
        pagoBruto = (HORAS_LIMITE * pagoPorHora) + (horasExtras * pagoPorHora * TARIFA_EXTRA);
    }

    return pagoBruto;
}

int main() {
    int numeroEmpleados;
    cout << "Programa creado por Claire <3 \n";
    cout << "Ingrese el número de empleados: ";
    cin >> numeroEmpleados;

    vector<Empleado> empleados(numeroEmpleados);

    // Solicitar la información de cada empleado
    for (int i = 0; i < numeroEmpleados; ++i) {
        cout << "Ingrese el nombre del empleado " << i + 1 << ": ";
        cin >> empleados[i].nombre;
        cout << "Ingrese las horas trabajadas por " << empleados[i].nombre << " la semana pasada: ";
        cin >> empleados[i].horasTrabajadas;
        cout << "Ingrese el pago por hora de " << empleados[i].nombre << ": ";
        cin >> empleados[i].pagoPorHora;
    }

    // Calcular y mostrar el pago bruto de cada empleado
    for (int i = 0; i < numeroEmpleados; ++i) {
        double pagoBruto = calcularPagoBruto(empleados[i].horasTrabajadas, empleados[i].pagoPorHora);
        cout << "El pago en bruto de " << empleados[i].nombre << " es: " << pagoBruto << endl;
    }

    return 0;
}
