#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Empleado {
    int numero;
    string nombre;
    string telefono;
    string direccion;
    string departamento;
    double salario;
    string puesto;
};

void registrarEmpleado() {
    ofstream archivo("cochiloco", ios::app);
    if (!archivo.is_open()) {
        cerr << "No mms we o no hay archivo o ya lo jodiste." << endl;
        return;
    }

    Empleado emp;
    cout << "Número de empleado: ";
    cin >> emp.numero;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, emp.nombre);
    cout << "Teléfono: ";
    getline(cin, emp.telefono);
    cout << "Dirección: ";
    getline(cin, emp.direccion);
    cout << "Departamento: ";
    getline(cin, emp.departamento);
    cout << "Salario mensual: ";
    cin >> emp.salario;
    cin.ignore();
    cout << "Puesto: ";
    getline(cin, emp.puesto);

    archivo << emp.numero << "\n"
            << emp.nombre << "\n"
            << emp.telefono << "\n"
            << emp.direccion << "\n"
            << emp.departamento << "\n"
            << emp.salario << "\n"
            << emp.puesto << "\n";
    archivo.close();

    cout << "Empleado registrado exitosamente." << endl;
}

void revisarRegistros() {
    ifstream archivo("cochiloco");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para leer." << endl;
        return;
    }

    Empleado emp;
    while (archivo >> emp.numero) {
        archivo.ignore();
        getline(archivo, emp.nombre);
        getline(archivo, emp.telefono);
        getline(archivo, emp.direccion);
        getline(archivo, emp.departamento);
        archivo >> emp.salario;
        archivo.ignore();
        getline(archivo, emp.puesto);

        cout << "Número de esclavo: " << emp.numero << endl;
        cout << "Nombre: " << emp.nombre << endl;
        cout << "Teléfono: " << emp.telefono << endl;
        cout << "Dirección: " << emp.direccion << endl;
        cout << "Departamento: " << emp.departamento << endl;
        cout << "Salario miserable: " << emp.salario << endl;
        cout << "Puesto: " << emp.puesto << endl;
        cout << "--------------------------------------" << endl;
    }
    archivo.close();
}

int main() {
    int opcion;
    do {
        cout << "Programa creado por Claire_Rupika ;3\n";
        cout << "Menú:\n";
        cout << "1. Registrar empleado\n";
        cout << "2. Revisar registros\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEmpleado();
                break;
            case 2:
                revisarRegistros();
                break;
            case 3:
                cout << "Muriendo..." << endl;
                break;
            default:
                cout << "Opción más invalida que tus sueños, intenta de nuevo." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}