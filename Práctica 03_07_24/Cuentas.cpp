#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Cuenta {
    int id;
    std::string nombre;
    double saldo;
};

void mostrarMenu() {
    std::cout << "1. Leer Cuenta\n";
    std::cout << "2. Actualizar Cuenta\n";
    std::cout << "3. Agregar Cuenta Nueva\n";
    std::cout << "4. Eliminar Cuenta\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void leerCuentas() {
    std::ifstream archivo("cuentas.dat", std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de cuentas.\n";
        return;
    }
    Cuenta cuenta;
    while (archivo.read(reinterpret_cast<char*>(&cuenta), sizeof(Cuenta))) {
        std::cout << "ID: " << cuenta.id << ", Nombre: " << cuenta.nombre << ", Saldo: " << cuenta.saldo << '\n';
    }
    archivo.close();
}

void actualizarCuenta() {
    int id;
    std::cout << "Ingrese el ID de la cuenta a actualizar: ";
    std::cin >> id;

    std::fstream archivo("cuentas.dat", std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de cuentas.\n";
        return;
    }

    Cuenta cuenta;
    bool encontrado = false;
    while (archivo.read(reinterpret_cast<char*>(&cuenta), sizeof(Cuenta))) {
        if (cuenta.id == id) {
            std::cout << "Ingrese el nuevo nombre: ";
            std::cin >> cuenta.nombre;
            std::cout << "Ingrese el nuevo saldo: ";
            std::cin >> cuenta.saldo;

            archivo.seekp(-static_cast<int>(sizeof(Cuenta)), std::ios::cur);
            archivo.write(reinterpret_cast<char*>(&cuenta), sizeof(Cuenta));
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cerr << "No se encontró una cuenta con el ID proporcionado.\n";
    }

    archivo.close();
}

void agregarCuenta() {
    Cuenta nuevaCuenta;
    std::cout << "Ingrese el ID de la nueva cuenta: ";
    std::cin >> nuevaCuenta.id;
    std::cout << "Ingrese el nombre: ";
    std::cin >> nuevaCuenta.nombre;
    std::cout << "Ingrese el saldo: ";
    std::cin >> nuevaCuenta.saldo;

    std::ofstream archivo("cuentas.dat", std::ios::binary | std::ios::app);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de cuentas.\n";
        return;
    }
    archivo.write(reinterpret_cast<char*>(&nuevaCuenta), sizeof(Cuenta));
    archivo.close();
}

void eliminarCuenta() {
    int id;
    std::cout << "Ingrese el ID de la cuenta a eliminar: ";
    std::cin >> id;

    std::ifstream archivo("cuentas.dat", std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo de cuentas.\n";
        return;
    }

    std::vector<Cuenta> cuentas;
    Cuenta cuenta;
    while (archivo.read(reinterpret_cast<char*>(&cuenta), sizeof(Cuenta))) {
        if (cuenta.id != id) {
            cuentas.push_back(cuenta);
        }
    }
    archivo.close();

    std::ofstream archivoNuevo("cuentas.dat", std::ios::binary | std::ios::trunc);
    if (!archivoNuevo) {
        std::cerr << "No se pudo abrir el archivo de las cuentas, ni modo.\n";
        return;
    }

    for (const auto& c : cuentas) {
        archivoNuevo.write(reinterpret_cast<char*>(&c), sizeof(Cuenta));
    }
    archivoNuevo.close();
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                leerCuentas();
                break;
            case 2:
                actualizarCuenta();
                break;
            case 3:
                agregarCuenta();
                break;
            case 4:
                eliminarCuenta();
                break;
            case 5:
                std::cout << "Confirmando que no hay Metroids...\n";
                break;
            default:
                std::cout << "Opción tan inválida como tus sueños. Intenta otra vez.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}
