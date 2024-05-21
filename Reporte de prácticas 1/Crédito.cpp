#include <iostream>
using namespace std;

int main() {
    int numeroCuenta;
    double saldoInicioMes;
    double totalCargos;
    double totalCreditos;
    double limiteCredito;
    double nuevoSaldo;

    cout << "Programa creado por Claire <3 \n";
    cout << "Ingrese el número de cuenta: ";
    cin >> numeroCuenta;

    cout << "Ingrese el saldo al inicio del mes: ";
    cin >> saldoInicioMes;

    cout << "Ingrese el total de elementos cargados al cliente este mes: ";
    cin >> totalCargos;

    cout << "Ingrese el total de créditos aplicados a la cuenta del cliente durante el mes: ";
    cin >> totalCreditos;

    cout << "Ingrese el límite de crédito autorizado: ";
    cin >> limiteCredito;

    nuevoSaldo = saldoInicioMes + totalCargos - totalCreditos;

    cout << "Su nuevo saldo es: " << nuevoSaldo << endl;
    // Determinar si el cliente ha excedido el límite de crédito
    if (nuevoSaldo > limiteCredito) {
        cout << "El cliente con número de cuenta " << numeroCuenta << " excedio el límite de crédito, ni modo." << endl;
    } else {
        cout << "El cliente con número de cuenta " << numeroCuenta << " no ha excedido el límite de crédito, vayase a gastar." << endl;
    }

    return 0;
}