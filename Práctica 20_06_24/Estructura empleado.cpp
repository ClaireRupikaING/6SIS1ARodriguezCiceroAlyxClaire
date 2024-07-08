#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Empleado {
    string nombre;
    string direccion;
    string telefono;
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
    int edad;
    double pagoPorHora;
    int horasTrabajadas;
    double pagoSemanal;
    double salarioMensual;
};

int calcularEdad(int dia, int mes, int anio) {
    time_t t = time(0);
    struct tm * ahora = localtime(&t);
    int anioActual = ahora->tm_year + 1900;
    int mesActual = ahora->tm_mon + 1;
    int diaActual = ahora->tm_mday;

    int edad = anioActual - anio;
    if (mes > mesActual || (mes == mesActual && dia > diaActual)) {
        edad--;
    }
    return edad;
}

double calcularPagoSemanal(int horasTrabajadas, double pagoPorHora) {
    double pagoSemanal = 0.0;
    int horasRegulares = min(horasTrabajadas, 40);
    int horasExtras = max(horasTrabajadas - 40, 0);

    pagoSemanal += horasRegulares * pagoPorHora;
    pagoSemanal += horasExtras * pagoPorHora * 1.5;

    return pagoSemanal;
}

int main() {
    Empleado empleado;
    
    cout << "Ingrese el nombre del empleado: ";
    getline(cin, empleado.nombre);
    
    cout << "Ingrese la direccion del empleado: ";
    getline(cin, empleado.direccion);
    
    cout << "Ingrese el telefono del empleado: ";
    getline(cin, empleado.telefono);
    
    cout << "Ingrese el dia de nacimiento del empleado (DD): ";
    cin >> empleado.diaNacimiento;
    
    cout << "Ingrese el mes de nacimiento del empleado (MM): ";
    cin >> empleado.mesNacimiento;
    
    cout << "Ingrese el anio de nacimiento del empleado (YYYY): ";
    cin >> empleado.anioNacimiento;

    cout << "Ingrese las horas trabajadas por semana del empleado: ";
    cin >> empleado.horasTrabajadas;

    empleado.edad = calcularEdad(empleado.diaNacimiento, empleado.mesNacimiento, empleado.anioNacimiento);
    empleado.pagoPorHora = 150 / 40.0; // Pago por hora  40 horas trabajadas se pagan con 150
    empleado.pagoSemanal = calcularPagoSemanal(empleado.horasTrabajadas, empleado.pagoPorHora);
    empleado.salarioMensual = empleado.pagoSemanal * 4;

    cout << "El empleado " << empleado.nombre << " tiene " << empleado.edad << " años, gana $" << empleado.pagoSemanal 
         << " semanalmente, tiene registradas " << empleado.horasTrabajadas << " horas trabajadas y su salario mensual es $" 
         << empleado.salarioMensual << "." << endl;

    return 0;
}
