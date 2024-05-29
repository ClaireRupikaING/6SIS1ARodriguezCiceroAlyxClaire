#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre, fechaNacimiento, telefono, direccion;
    int edad;
    //Variables para los datos
    
    string* ptrNombre = &nombre;
    string* ptrFechaNacimiento = &fechaNacimiento;
    string* ptrTelefono = &telefono;
    string* ptrDireccion = &direccion;
    int* ptrEdad = &edad;
    //Apuntador para cada variable
    
    cout << "Introduce tu nombre: ";
    getline(cin, *ptrNombre);
    
    cout << "Introduce tu edad: ";
    cin >> *ptrEdad;
    cin.ignore();
    
    cout << "Introduce tu fecha de nacimiento (DD/MM/AAAA): ";
    getline(cin, *ptrFechaNacimiento);
    
    cout << "Introduce tu número de teléfono: ";
    getline(cin, *ptrTelefono);
    
    cout << "Introduce tu dirección: ";
    getline(cin, *ptrDireccion);
    
    cout << "\nDatos introducidos:\n";
    cout << "Nombre: " << *ptrNombre << endl;
    cout << "Edad: " << *ptrEdad << endl;
    cout << "Fecha de nacimiento: " << *ptrFechaNacimiento << endl;
    cout << "Número de teléfono: " << *ptrTelefono << endl;
    cout << "Dirección: " << *ptrDireccion << endl;
    
    return 0;
}
