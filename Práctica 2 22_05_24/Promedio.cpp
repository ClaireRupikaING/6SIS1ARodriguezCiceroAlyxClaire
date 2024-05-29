#include <iostream>
#include <iomanip> // para mejorar el formato de la tabla
#include <cstdlib> // para comandos rand y srand en nuneros aleatorios
#include <ctime> // para usar time en numeros aleatorios

using namespace std;

int main() {
    const int numAlumnos = 5;
    const int numMaterias = 4; // Innovación, Metodologías Ágiles, Inglés, Sistemas Operativos, Estructura de datos
    string nombres[numAlumnos] = {"Silvestre Cruz", "Seraz Tebano", "Valeria Lino", "Naim Gonzales", "Samantha Nuñez"};
    float ED[numAlumnos], Inn[numAlumnos], MA[numAlumnos], Ing[numAlumnos], prom[numAlumnos];

    // Semillita para los números random
    srand(static_cast<unsigned int>(time(0)));

    // Asignar calificaciones aleatorias y calcular promedio
    for (int i = 0; i < numAlumnos; ++i) {
        ED[i] = rand() % 11; // Calificación random
        Inn[i] = rand() % 11;
        MA[i] = rand() % 11;
        Ing[i] = rand() % 11;
        prom[i] = (ED[i] + Inn[i] + MA[i] + Ing[i]) / numMaterias;
    }

    // Tabla completa
    auto mostrarTablaCompleta = [&]() {
        cout << left << setw(20) << "Nombre" << setw(10) << "ED" << setw(10) << "Inn" << setw(10) << "MA" << setw(10) << "Ing" << setw(10) << "Promedio" << endl;
        for (int i = 0; i < numAlumnos; ++i) {
            cout << left << setw(20) << nombres[i]
                 << setw(10) << ED[i]
                 << setw(10) << Inn[i]
                 << setw(10) << MA[i]
                 << setw(10) << Ing[i]
                 << setw(10) << prom[i];
            for (int j = 0; j < static_cast<int>(prom[i]); ++j) {
                cout << "*";
            }
            cout << endl;
        }
    };

    // Calificaciones individuales
    auto mostrarCalificacionesAlumno = [&](int index) {
        cout << "Las calificaciones de " << nombres[index] << " son:" << endl;
        cout << "Estructura de Datos: " << ED[index] << endl;
        cout << "Innovación: " << Inn[index] << endl;
        cout << "Metodologías Ágiles: " << MA[index] << endl;
        cout << "Inglés: " << Ing[index] << endl;
        cout << "Promedio: " << prom[index] << endl;
    };

    int opcion;
    do {
        cout << "Programa creado por Claire <3" << endl;
        cout << "Menu:" << endl;
        cout << "1. Ver tabla completa de calificaciones" << endl;
        cout << "2. Ver calificaciones de un alumno" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarTablaCompleta();
                break;
            case 2:
                int index;
                cout << "Seleccione el índice del alumno (0-4): ";
                cin >> index;
                if (index >= 0 && index < numAlumnos) {
                    mostrarCalificacionesAlumno(index);
                } else {
                    cout << "Índice tan inválido como tus sueños" << endl;
                }
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción más inválida que tus sueños" << endl;
        }
        cout << endl;
    } while (opcion != 3);

    return 0;
}

//Explicación del código:
//Declaramos los arreglos de calificaciones y nombres.
//Asignamos calificaciones aleatorias entre 0 y 10 usando rand() % 11.
//Calculamos el promedio de cada alumno.
//Definimos dos funciones lambda para mostrar la tabla completa y las calificaciones de un alumno específico.
//Implementamos un menú simple que permite al usuario elegir entre ver la tabla completa, ver las calificaciones de un alumno específico o salir del programa.